#!/bin/bash
# POSIX

show_help() {
echo '    -h     display this help and exit'
echo '    -d     dry mode - no build, no flashing'
echo '    -b     build only mode, no flashing'
echo '    -f     ignore git status and force firmware build'
echo '    -v     verbose mode'

echo 'Example: ${0##*/} -d -v -f planck_ez'
}

check_git='true'
verbose=0
dry='false'
build_only='false'

echo_verbose() {
    if [ $verbose -gt 0 ] ; then
        echo $1
    fi
}

eval LAST_ARG=\${$#}

if [ "$#" -lt 1 ] || ! [ -d "$LAST_ARG" ]; then
    show_help
    exit 1
fi

while :; do
    case $1 in
        -h|-\?|--help)
            show_help # usage synopsis
            exit
            ;;
        -b|--build-only)
            build_only=true
            ;;
        -d|--dry)
            dry=true
            ;;
        -v|--verbose)
            verbose=$((verbose + 1))  # each -v adds 1 to verbosity
            ;;
        -f|--force)
            check_git=false
            ;;
        --)
            shift
            break
            ;;
        -?*)
            printf 'WARN: Unknown option (ignored): %s\n' "$1" >&2
            ;;
        *)
            break
    esac
    shift
done

if [[ $verbose -gt 1 ]] ; then
    set -o xtrace
fi


if [[ -n $(git status --porcelain) ]] && $check_git; then
    echo "Repo is dirty, please make a commit"
    exit 1
fi

KEYSET_VERSION=$(git describe --abbrev=6 --dirty --always --tags)
KEYSET_DATETIME=$(git --no-pager show --date=short --format="%ad" --name-only | head -n1 | sed -e 's/\s.*$//')

QMK_FIRMWARE='qmk_firmware'
QMK_USER='zawaken'
TARGET_LAYOUT=${LAST_ARG%/} # last argument without last slash

if [ $TARGET_LAYOUT = planck* ] ; then
    TARGET_KEYBOARD='planck'
    MAKE_PREFIX='planck/rev6'
    IMAGE_EXTENSION='bin'
elif [ $TARGET_LAYOUT = preonic* ]; then
	TARGET_KEYBOARD='preonic'
	MAKE_PREFIX='preonic/rev3'
	IMAGE_EXTENSION='bin'
else
    TARGET_KEYBOARD=$TARGET_LAYOUT
    MAKE_PREFIX=$TARGET_LAYOUT
    IMAGE_EXTENSION='hex'
fi

BINARY_NAME="${TARGET_LAYOUT}_${QMK_USER}.${IMAGE_EXTENSION}"

echo "Using firmware folder '$QMK_FIRMWARE'"
echo "Layout: ${TARGET_LAYOUT}, version: ${KEYSET_VERSION}/${KEYSET_DATETIME}"
echo "Building binary '${BINARY_NAME}'"

if $dry; then
    echo "\nSkipped building and flashing because of dry mode, exiting"
    exit
fi

rsync -avh $1/{config.h,keymap.c,rules.mk} $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/${QMK_USER}/
rsync -avh --delete common/ $QMK_FIRMWARE/users/$QMK_USER/
cd $QMK_FIRMWARE
make git-submodule
rm -rf $QMK_FIRMWARE/${TARGET_LAYOUT}_${QMK_USER}.bin
echo "\nBuilding layout ${MAKE_PREFIX}:${QMK_USER}"
make ${MAKE_PREFIX}:${QMK_USER} KEYSET_VERSION=\"${KEYSET_VERSION}\" KEYSET_DATETIME=\"${KEYSET_DATETIME}\"
MAKE_RESULT=$?
cd ..

if [ ${MAKE_RESULT} -ne 0 ] ; then
  echo "Can't build binary, exiting"
  exit 1
fi

echo "Binary '${BINARY_NAME}' created"

if $build_only; then
    echo "\nSkipped flashing because of dry mode, exiting"
    exit
fi

echo "\nFlashing...\n"
