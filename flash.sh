#!/usr/bin/env bash
# variables # {{{
__DIR="$( cd -- "$(dirname "${0}")" >/dev/null 2>&1 ; pwd -P )"
FW_FOLDER='qmk_firmware'
eval LAST_ARG=\${$#}
TARGET_LAYOUT=${LAST_ARG%/}
FW_REPO="https://github.com/qmk/qmk_firmware.git"
# }}}

# argument handling {{{
RUNTIME="podman" QMK_USER="${USER}" BUILD_SCRIPT="./util/docker_build.sh" BUILD_ONLY=false
while true; do
  case $1 in
    -v|--verbose) verbose=1;;
    -u|--user) QMK_USER="${2}";;
    -b|--build_only) BUILD_ONLY=true;;
    -p|--podman) RUNTIME="podman";;
    -d|--docker) RUNTIME="docker";;
    -l|--local) RUNTIME="local";;
    -*)
      printf "ERR: Argument \"%s\" does not exist\n" "${1}"
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
      TARGET_KBD='planck'
      MAKE_PREFIX='planck/rev6'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX='dfu-util'
      ;;
    preonic)
      TARGET_KBD='preonic'
      MAKE_PREFIX='preonic/rev3'
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX="dfu-util"
      ;;
    m60-a)
      TARGET_KBD='rama_works_m60_a'
      MAKE_PREFIX='wilba_tech/rama_works_m60_a'
      IMAGE_EXTENSION='hex'
      ;;
    viterbi)
      TARGET_KBD='keebio/viterbi'
      MAKE_PREFIX='keebio/viterbi/rev2'
      IMAGE_EXTENSION='hex'
      MAKE_SUFFIX='dfu'
      ;;
    nyquist)
      TARGET_KBD='keebio/nyquist'
      MAKE_PREFIX='keebio/nyquist/rev3'
      IMAGE_EXTENSION='hex'
      MAKE_SUFFIX='dfu'
      ;;
    lpvi)
      TARGET_KBD='vitamins_included'
      MAKE_PREFIX='vitamins_included/rev2'
      IMAGE_EXTENSION='hex'
      MAKE_SUFFIX='dfu'
      ;;
    framework)
      TARGET_KBD='7c8/framework'
      MAKE_PREFIX="$TARGET_KBD"
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX='flash'
      ;;
    framework-via)
      TARGET_KBD='7c8/framework'
      MAKE_PREFIX="$TARGET_KBD"
      IMAGE_EXTENSION='bin'
      MAKE_SUFFIX='flash'
      ;;
    lulu)
      TARGET_KBD='boardsource/lulu'
      MAKE_PREFIX="$TARGET_KBD/rp2040"
      IMAGE_EXTENSION='uf2'
      MAKE_SUFFIX='flash'
      ;;
    conundrum)
      TARGET_KBD='thock/conundrum'
      MAKE_PREFIX="$TARGET_KBD"
      IMAGE_EXTENSION='uf2'
      MAKE_SUFFIX='flash'
      ;;
    air40)
      TARGET_KBD='ymdk/ymd40/air40'
      MAKE_PREFIX="$TARGET_KBD"
      IMAGE_EXTENSION='hex'
      MAKE_SUFFIX='flash'
      ;;
    completion)
      echo "planck preonic m60-a viterbi nyquist lpvi framework framework-via lulu conundrum air40"
      exit 0
      ;;
    *)
      printf "Layout %s not found in the list, maybe you should add it?\nexiting\n" "${TARGET_LAYOUT}"
      exit 1
      ;;
  esac
else
  printf "\nERR: No arguments supplied.\n"
  exit
fi #}}}

get_make_command() { # {{{
  MAKE_COMMAND="${MAKE_PREFIX}:${QMK_USER}"
  if ! $BUILD_ONLY; then
    MAKE_COMMAND="${MAKE_COMMAND}:${MAKE_SUFFIX}"
  fi
} # }}}

fw_lock() { # {{{
  if test ! -d ${FW_FOLDER}; then
    git clone ${FW_REPO} ${FW_FOLDER}
  fi
  (
  FW_LOCK_DIR="$(pwd)/${KEYMAP_DIR}"
  cd ${FW_FOLDER} || exit
  git config advice.detachedHead false
  if test -f "${FW_LOCK_DIR}/fw.lock"; then
    FW_LOCK_HASH=$(cat "${FW_LOCK_DIR}/fw.lock")
    if [ "$(printf '%s\n' "$(git rev-parse HEAD)")" != "${FW_LOCK_HASH}" ]; then
      git checkout "${FW_LOCK_HASH}"
    fi
  else
    git checkout master
    git pull
    git rev-parse HEAD > "${FW_LOCK_DIR}/fw.lock"
  fi
  )
} # }}}

get_make_command

if [ "$TARGET_LAYOUT" == "conundrum" ]; then
  FW_REPO="https://github.com/zawaken/thockqmk.git"
  FW_FOLDER="thockqmk"
  BUILD_SCRIPT="./build-conundrum.sh"
  MAKE_COMMAND="${QMK_USER}:uf2"
  export keymap="${QMK_USER}:uf2"
  # conundrum_build
  # exit 0
fi # }}}

# preonic_zawaken.bin
BINARY_NAME="$(printf "%s" "${MAKE_PREFIX}" | sed -e 's/\//_/g')_${QMK_USER}.${IMAGE_EXTENSION}"
KEYMAP_DIR="keyboards/${TARGET_LAYOUT}"
FW_KEYMAPS_DIR="${FW_FOLDER}/keyboards/${TARGET_KBD}/keymaps"
FW_KEYMAP_DIR="${FW_KEYMAPS_DIR}/${QMK_USER}"
FW_COMMON_DIR="${FW_FOLDER}/users/${QMK_USER}"

printf "\n===================================================
KEYBOARD:         \"${TARGET_KBD}\"
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
  rm -rf  "${FW_FOLDER:?}/.build" \
          "${FW_KEYMAP_DIR:?}" \
          "${FW_COMMON_DIR:?}"
  mkdir -p "${FW_KEYMAPS_DIR}" # Create TARGET_KBD/keymaps/ folder
  mkdir -p "${FW_FOLDER}/.build"
  cp -r "${KEYMAP_DIR}" "${FW_KEYMAP_DIR}"
  cp -r common "${FW_COMMON_DIR}"
  # rsync -avh ${KEYMAP_DIR}/{config.h,keymap.c,rules.mk} "${FW_KEYMAP_DIR}" >/dev/null 2>&1
  # rsync -avh --delete common/ ${FW_FOLDER}/users/${QMK_USER}/ >/dev/null 2>&1 # Copy everything in the common directory into users/QMK_USER
  rm -rf "${FW_FOLDER:?}/${BINARY_NAME}"

  cd "${FW_FOLDER}" || exit
  # Build/flash
  # cd "${FW_FOLDER}"
  case $RUNTIME in
    podman|docker) RUNTIME="${RUNTIME}" "${BUILD_SCRIPT}" "${MAKE_COMMAND}";;
    local) ;;
  esac
} # }}}

fw_lock
main
