#pragma once

#include "keymap.h"
#include QMK_KEYBOARD_H

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define LWR_SPC LT(_LOWER, KC_SPC)
#define RSE_SPC LT(_RAISE, KC_SPC)
#define RSE_ENT LT(_RAISE, KC_ENT)

// layers {{{
#if defined(COMMON_LAYERS)
enum LAYERS {
  _COLEMAK,
  _QWERTY,
  _DVORAK,
  _WORKMAN,
  #if defined(COMMON_ORTHO_LAYERS) // {{{
  _LOWER,
  _RAISE,
  _ADJUST,
  #endif // }}}
  _PLOVER,
  _ARROW,
};
#endif // }}}
// keycodes {{{
#ifdef COMMON_LAYERS
enum KEYCODES {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  WORKMAN,
  #if defined(COMMON_ORTHO_LAYERS) // {{{
  LOWER,
  RAISE,
  ADJUST,
  #endif // }}}
  ARROW,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  SARCASM,
};
#endif // }}}
