#!/usr/bin/env bash
# variables # {{{
build_only='false'
FW_FOLDER='qmk_firmware'
QMK_USER="${USER}"
eval LAST_ARG=\${$#}
TARGET_LAYOUT=${LAST_ARG%/}
verbose=0
RUNTIME="local"
# }}}
show_help() { # {{{
printf 'Usage:

    -h     display this menu and exit
    -b     build only mode, no flashing
    -v     verbose mode
    -p     build with podman
    -d     build with docker
    -l     build locally with qmk cli (default)

Example: ./flash.sh -p -v preonic

Keyboards:
  planck
  preonic
  m60-a
  viterbi
  nyquist
  vitamins_included
  framework
  lulu\n'
}
# }}}
# argument handling {{{
while true; do
  case $1 in
    -h|--help)
      show_help
      exit
      ;;
    -v|--verbose) verbose=1;;
    -u|--user) QMK_USER="${2}";;
    -b|--build_only) build_only=true;;
    -p|--podman) RUNTIME="podman";;
    -d|--docker) RUNTIME="docker";;
    -l|--local) RUNTIME="local";;
    -u|--user) QMK_USER="${2}";;
    -*)
      show_help
      printf "\nERR: Argument \"${1}\" does not exist\n"
      exit 1
      ;;
    *)
      break
      ;;
  esac
  shift
done
if test "${verbose}" -eq 1; then
  set -o xtrace
fi
# }}}
if test "${1}"; then # {{{
  case "${TARGET_LAYOUT}" in
    planck)
      TARGET_KEYBOARD='planck'
      MAKE_PREFIX='planck/rev6'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX='dfu-util'
      ;;
    preonic)
      TARGET_KEYBOARD='preonic'
      MAKE_PREFIX='preonic/rev3'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX="dfu-util"
      ;;
    m60-a)
      TARGET_KEYBOARD='rama_works_m60_a'
      MAKE_PREFIX='wilba_tech/rama_works_m60_a'
      IMAGE_EXTENSION='hex'
      ;;
    viterbi)
      TARGET_KEYBOARD='keebio/viterbi'
      MAKE_PREFIX='keebio/viterbi/rev2'
      IMAGE_EXTENSION='hex'
      MAKE_SUFFIX='dfu'
      ;;
    nyquist)
      TARGET_KEYBOARD='keebio/nyquist'
      MAKE_PREFIX='keebio/nyquist/rev3'
      IMAGE_EXTENSION='hex'
      MAKE_SUFFIX='dfu'
      ;;
    vitamins_included)
      TARGET_KEYBOARD='vitamins_included'
      MAKE_PREFIX='vitamins_included/rev2'
      IMAGE_EXTENSION='hex'
      MAKE_SUFFIX='dfu'
      ;;
    framework)
      TARGET_KEYBOARD='7c8/framework'
      MAKE_PREFIX='7c8/framework'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX='flash'
      ;;
    framework-via)
      TARGET_KEYBOARD='7c8/framework'
      MAKE_PREFIX='7c8/framework'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX='flash'
      ;;
    lulu)
      TARGET_KEYBOARD='boardsource/lulu'
      MAKE_PREFIX='boardsource/lulu/rp2040'
      IMAGE_EXTENSION='uf2'
      MAKE_SUFFIX='flash'
      ;;
    *)
      printf "Layout ${TARGET_LAYOUT} not found in the list, maybe you should add it?\nexiting\n"
      exit 1
      ;;
  esac
else
  show_help
  printf "\nERR: No arguments supplied.\n"
  exit
fi #}}}

get_make_command() {
  MAKE_COMMAND="${MAKE_PREFIX}:${QMK_USER}"
  if ! $build_only; then
    MAKE_COMMAND="${MAKE_COMMAND}:${MAKE_SUFFIX}"
  fi
}

fw_lock() { # {{{
  GIT_DIR="git --git-dir ${FW_FOLDER}/.git"
  if test ! -d ${FW_FOLDER}; then
    git clone https://github.com/qmk/qmk_firmware.git ${FW_FOLDER}
  fi
  git --git-dir ${FW_FOLDER}/.git config advice.detachedHead false
  if test -f keyboards/${TARGET_LAYOUT}/fw.lock; then
    FW_LOCK_HASH=$(cat keyboards/${TARGET_LAYOUT}/fw.lock)
    if $(printf '%s\n' "$(git --git-dir ${FW_FOLDER}/.git rev-parse HEAD)") -eq FW_LOCK_HASH; then
      git --git-dir ${FW_FOLDER} checkout "$FW_LOCK_HASH"
    fi
  else
    git checkout master
    git pull
    git rev-parse HEAD > keyboards/${TARGET_LAYOUT}/fw.lock
  fi
} # }}}

# preonic_zawaken.bin
BINARY_NAME="$(printf "${MAKE_PREFIX}" | sed -e 's/\//_/g')_${QMK_USER}.${IMAGE_EXTENSION}"
KEYMAP_DIR="keyboards/${TARGET_LAYOUT}"
FW_KEYMAPS_DIR="${FW_FOLDER}/keyboards/${TARGET_KEYBOARD}/keymaps"
FW_KEYMAP_DIR="${FW_KEYMAPS_DIR}/${QMK_USER}"
FW_COMMON_DIR="${FW_FOLDER}/users/${QMK_USER}"

get_make_command
printf "\n===================================================
KEYBOARD:         \"${TARGET_KEYBOARD}\"
LAYOUT:           \"${TARGET_LAYOUT}\"
BINARY:           \"${BINARY_NAME}\"
FW_FOLDER:        \"${FW_FOLDER}\"
FW_KEYMAP_DIR:    \"${FW_KEYMAP_DIR}\"
QMK_USER:         \"${QMK_USER}\"
RUNTIME:          \"${RUNTIME}\"
MAKE_COMMAND:     \"${MAKE_COMMAND}\"
===================================================\n"

main () { # {{{
make --directory="${FW_FOLDER}" git-submodule >/dev/null 2>&1 # Submodule initialization
rm -rf  "${FW_FOLDER}/.build" \
        "${FW_KEYMAP_DIR}" \
        "${FW_COMMON_DIR}"
mkdir -p "${FW_KEYMAPS_DIR}" # Create TARGET_KEYBOARD/keymaps/ folder
cp -r "${KEYMAP_DIR}" "${FW_KEYMAP_DIR}"
cp -r common "${FW_COMMON_DIR}"
# rsync -avh ${KEYMAP_DIR}/{config.h,keymap.c,rules.mk} "${FW_KEYMAP_DIR}" >/dev/null 2>&1
# rsync -avh --delete common/ ${FW_FOLDER}/users/${QMK_USER}/ >/dev/null 2>&1 # Copy everything in the common directory into users/QMK_USER
rm -rf "${FW_FOLDER}/${BINARY_NAME}"

# Build/flash
# cd "${FW_FOLDER}"
case $RUNTIME in
  # TODO: make the flash script work with util/docker_build.sh from qmk_firmware
  # podman|docker) RUNTIME="${RUNTIME}" ./util/docker_build.sh ${MAKE_COMMAND};;
  podman|docker) RUNTIME="${RUNTIME}" ./container_build.sh ${MAKE_COMMAND};;
  local) ;;
esac
} # }}}

main
