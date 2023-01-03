#pragma once

#include "keymap.h"
#include QMK_KEYBOARD_H

#define CTL_ESC MT(MOD_LCTL, KC_ESC)

#if defined(COMMON_LAYERS)
enum LAYERS {
  _COLEMAK,
  _QWERTY,
  _DVORAK,
  _WORKMAN,
  #if defined(COMMON_ORTHO_LAYERS)
  _LOWER,
  _RAISE,
  _ADJUST,
  #endif
  _PLOVER,
  _ARROW,
};

enum KEYCODES {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  WORKMAN,
  #if defined(COMMON_ORTHO_LAYERS)
  LOWER,
  RAISE,
  ADJUST,
  #endif
  ARROW,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  SARCASM,
};
#endif
