/* Copyright 2020 Steven Nguyen {{{
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// }}}
// includes {{{
#include QMK_KEYBOARD_H
// }}}
// Layers and keycodes {{{
enum framework_layers {
    _BASE,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROW,
};

enum framework_keycodes {
    BASE = SAFE_RANGE,
    QWERTY,
    LOWER,
    RAISE,
    ADJUST,
    ARROW,
    SARCASM
};
// }}}
// defines {{{
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
// }}}
// keymaps {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Colemak {{{
[_BASE] = framework_via(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_MEDIA_PLAY_PAUSE,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,       KC_G,    KC_J,   KC_L,       KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
    CTL_ESC,  KC_A,    KC_R,    KC_S,    KC_T,       KC_D,    KC_H,   KC_N,       KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_K,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    ARROW, KC_ALGR, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP
),
// }}}
// QWERTY{{{
[_QWERTY] = framework_via(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_MEDIA_PLAY_PAUSE,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    ARROW, KC_ALGR, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP
),
// }}}
// Lower {{{
[_LOWER] = framework_via(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,
    C(S(KC_TAB)), C(KC_TAB)
),
// }}}
// Raise {{{
[_RAISE] = framework_via(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,
    C(KC_LEFT), C(KC_RIGHT)
),
// }}}
// Adjust {{{
[_ADJUST] = framework_via(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, QWERTY, BASE, _______, _______, SARCASM,
    // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SARCASM,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EEP_RST, DEBUG,
    C(KC_Z), C(KC_Y)
),
// }}}
// ARROW {{{
[_ARROW] = framework_via(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_MS_WH_LEFT, KC_MS_WH_RIGHT
)
// }}}
};
// }}}
// tap dance {{{
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
    }
}
// }}}
// encoder {{{
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    if (index == 0) {
        if (clockwise) {
            tap_code16(dynamic_keymap_get_keycode(layer, 10, 1));
        } else {
            tap_code16(dynamic_keymap_get_keycode(layer, 10, 0));
        }
    }
    return true;
}
// }}}
// Layer switching {{{
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool sarcasm_flag = false;
  static bool caps_flag = false;

  if(sarcasm_flag) {
    if(record->event.pressed) {
      if(keycode != KC_SPC) {
        // if(rand() % 3 > 0){
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
        caps_flag = !caps_flag;
        // }
      }
    }
  }
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        layer_on(_ARROW);
      } else {
        layer_off(_ARROW);
      }
      return false;
      break;
    case SARCASM:
      if(record->event.pressed) {
        sarcasm_flag = !sarcasm_flag;
        if(caps_flag) {
          register_code(KC_CAPS);
          unregister_code(KC_CAPS);
        }
      }
    return false;
    break;
  }
  return true;
}; // }}}
