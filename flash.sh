#!/usr/bin/env bash


show_help() {
printf '    -h     display this menu and exit
    -b     build only mode, no flashing
    -v     verbose mode
    -d     build with docker instead of podman

Example: ./flash.sh -p -v preonic\n'
}

verbose=0
PODMAN=1
build_only='false'
QMK_FIRMWARE='qmk_firmware'
QMK_USER='zawaken'
eval LAST_ARG=\${$#}
TARGET_LAYOUT=${LAST_ARG%/}

while true; do
  case $1 in
    -h|--help)
      show_help
      exit
      ;;
    -v|--verbose)
      verbose=1
      ;;
    -u|--user)
      QMK_USER="${2}"
      ;;
    -b|--build_only)
      build_only=true
      ;;
    -d|--docker)
      PODMAN=
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

if test "${TARGET_LAYOUT}" = "planck"; then
  TARGET_KEYBOARD='planck'
  MAKE_PREFIX='planck/rev6'
  IMAGE_EXTENSION='bin'
  MAKE_SUFFIX=':dfu-util-wait'
elif test "${TARGET_LAYOUT}" = "preonic"; then
  TARGET_KEYBOARD='preonic'
  MAKE_PREFIX='preonic/rev3'
  IMAGE_EXTENSION='bin'
  MAKE_SUFFIX=":dfu-util-wait"
elif test "${TARGET_LAYOUT}" = "m60-a"; then
  TARGET_KEYBOARD='rama_works_m60_a'
  MAKE_PREFIX='wilba_tech/rama_works_m60_a'
  IMAGE_EXTENSION='hex'
elif test "${TARGET_LAYOUT}" = "viterbi"; then
  TARGET_KEYBOARD='keebio/viterbi'
  MAKE_PREFIX='keebio/viterbi/rev2'
  IMAGE_EXTENSION='hex'
  MAKE_SUFFIX=':dfu'
elif test "${TARGET_LAYOUT}" = "nyquist"; then
  TARGET_KEYBOARD='keebio/nyquist'
  MAKE_PREFIX='keebio/nyquist/rev3'
  IMAGE_EXTENSION='hex'
  MAKE_SUFFIX=':dfu'
elif test "${TARGET_LAYOUT}" = "vitamins_included"; then
  TARGET_KEYBOARD='vitamins_included'
  MAKE_PREFIX='vitamins_included/rev2'
  IMAGE_EXTENSION='hex'
  MAKE_SUFFIX=':dfu'
else
  TARGET_KEYBOARD=$TARGET_LAYOUT
  MAKE_PREFIX=$TARGET_LAYOUT
  IMAGE_EXTENSION='hex'
fi

#if test -z "${TARGET_LAYOUT}"; then
#  case "${TARGET_LAYOUT}" in
#    planck)
#      TARGET_KEYBOARD='planck'
#      MAKE_PREFIX='planck/rev6'
#      IMAGE_EXTENSION='bin'
#      MAKE_SUFFIX=':dfu-util-wait'
#      ;;
#    preonic)
#      TARGET_KEYBOARD='preonic'
#      MAKE_PREFIX='preonic/rev3'
#      IMAGE_EXTENSION='bin'
#      MAKE_SUFFIX=":dfu-util-wait"
#      ;;
#    m60-a)
#      TARGET_KEYBOARD='rama_works_m60_a'
#      MAKE_PREFIX='wilba_tech/rama_works_m60_a'
#      IMAGE_EXTENSION='hex'
#      ;;
#    viterbi)
#      TARGET_KEYBOARD='keebio/viterbi'
#      MAKE_PREFIX='keebio/viterbi/rev2'
#      IMAGE_EXTENSION='hex'
#      MAKE_SUFFIX=':dfu'
#      ;;
#    nyquist)
#      TARGET_KEYBOARD='keebio/nyquist'
#      MAKE_PREFIX='keebio/nyquist/rev3'
#      IMAGE_EXTENSION='hex'
#      MAKE_SUFFIX=':dfu'
#      ;;
#    vitamins_included)
#      TARGET_KEYBOARD='vitamins_included'
#      MAKE_PREFIX='vitamins_included/rev2'
#      IMAGE_EXTENSION='hex'
#      MAKE_SUFFIX=':dfu'
#      ;;
#    *)
#      printf "${TARGET_LAYOUT} not found in the list, maybe you should add it?\nexiting"
#      exit 1
#      ;;
#  esac
#fi

BINARY_NAME="${TARGET_LAYOUT}_${QMK_USER}.${IMAGE_EXTENSION}"

printf "\n===================================================
Using firmware folder ${QMK_FIRMWARE}
Layout: ${TARGET_LAYOUT}
Building binary '${BINARY_NAME}'"

# Remove .build folder
rm -rf $QMK_FIRMWARE/.build

# Create TARGET_KEYBOARD/keymaps/QMK_USER folder
mkdir -p $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}

# Copy keymap files for the specified keymap
printf "\n\nCopying keymap \"${MAKE_PREFIX}:${QMK_USER}\" \n\n"
rsync -avh $1/{config.h,keymap.c,rules.mk} $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}/ # >/dev/null 2>&1

# Copy everything in the common directory into users/QMK_USER
printf "Copying ./common to \"./${QMK_FIRMWARE}/users/${QMK_USER}\"\n\n"
rsync -avh --delete common/ $QMK_FIRMWARE/users/$QMK_USER/ >/dev/null 2>&1

# Submodule initialization
make --directory=qmk_firmware git-submodule >/dev/null 2>&1

# Remove previous binary
rm -rf $QMK_FIRMWARE/${TARGET_LAYOUT}_${QMK_USER}.${IMAGE_EXTENSION}

# Build/flash
cd $QMK_FIRMWARE
if test ${PODMAN}; then
  rsync -avh --delete ../podman_build.sh ./util/
  if $build_only; then
    printf 'build_only specified, skipping flash\n===================================================\n\n'
    ./util/podman_build.sh ${MAKE_PREFIX}:${QMK_USER}
  else
    printf "building and flashing \"${MAKE_PREFIX}:${QMK_USER}\"\n===================================================\n\n"
    ./util/podman_build.sh ${MAKE_PREFIX}:${QMK_USER}${MAKE_SUFFIX}
  fi
else
  if $build_only; then
    printf 'build_only specified, skipping flash\n===================================================\n\n'
    ./util/docker_build.sh ${MAKE_PREFIX}:${QMK_USER}
    exit
  else
    printf "building and flashing \"${MAKE_PREFIX}:${QMK_USER}\"\n===================================================\n\n"
    ./util/docker_build.sh ${MAKE_PREFIX}:${QMK_USER}${MAKE_SUFFIX}
  fi
fi
