#!/usr/bin/env bash
show_help() {
printf '    -h     display this help and exit
    -b     build only mode, no flashing
    -v     verbose mode

Example: ./flash.sh -d -v -f planck_ez\n'
}

verbose=0
build_only='false'

eval LAST_ARG=\${$#}

while true; do
  case $1 in
    -h|--help)
      show_help
      exit
      ;;
    -v|--verbose)
      verbose=1
      ;;
    -b|--build_only)
      build_only=true
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

QMK_FIRMWARE='qmk_firmware'
QMK_USER='zawaken'
TARGET_LAYOUT=${LAST_ARG%/}

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
else
  TARGET_KEYBOARD=$TARGET_LAYOUT
  MAKE_PREFIX=$TARGET_LAYOUT
  IMAGE_EXTENSION='hex'
fi

BINARY_NAME="${TARGET_LAYOUT}_${QMK_USER}.${IMAGE_EXTENSION}"

printf "===================================================
Using firmware folder ${QMK_FIRMWARE}
Layout: ${TARGET_LAYOUT}
Building binary '${BINARY_NAME}'"

rm -rf $QMK_FIRMWARE/.build
printf "\n\nCopying keymap \"${MAKE_PREFIX}:${QMK_USER}\" \n\n"
mkdir -p $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}
rsync -avh $1/{config.h,keymap.c,rules.mk} $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}/ # >/dev/null 2>&1
printf "Copying ./common to \"./${QMK_FIRMWARE}/users/${QMK_USER}\"\n\n"
rsync -avh --delete common/ $QMK_FIRMWARE/users/$QMK_USER/ >/dev/null 2>&1
make --directory=qmk_firmware git-submodule >/dev/null 2>&1
rm -rf $QMK_FIRMWARE/${TARGET_LAYOUT}_${QMK_USER}.${IMAGE_EXTENSION}
cd $QMK_FIRMWARE
if $build_only; then
  printf 'build_only specified, skipping flash\n===================================================\n\n'
  ./util/docker_build.sh ${MAKE_PREFIX}:${QMK_USER}
  exit
else
  printf "building and flashing \"${MAKE_PREFIX}:${QMK_USER}\"\n===================================================\n\n"
  ./util/docker_build.sh ${MAKE_PREFIX}:${QMK_USER}${MAKE_SUFFIX}
fi
cd ..
