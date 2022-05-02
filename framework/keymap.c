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
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROW,
};

enum framework_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    ADJUST,
    ARROW,
};
// }}}
// defines {{{
#define CTL_ESC(MOD_LCTL, KC_ESC)
#define ARROW MO(_ARROW)
// }}}
// keymaps {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Colemak {{{
[_BASE] = framework_via(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_MEDIA_PLAY_PAUSE,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,       KC_G,    KC_J,   KC_L,       KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
    CTL_ESC,  KC_A,    KC_R,    KC_S,    KC_T,       KC_D,    KC_H,   KC_N,       KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_K,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    MO(_FN), KC_ALGR, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,  KC_BSPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP
),
// }}}
// Lower {{{
[_LOWER] = framework_via(
    _______, _______, _______, _______, _______, _______, _______, _______,   _______, KC_MINS, KC_EQL,  _______,
    KC_LEAD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______,   _______, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______,   _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,   _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    C(S(KC_TAB)), C(KC_TAB)
),
// }}}
// Raise {{{
[_RAISE] = framework_via(
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    C(KC_LEFT), C(KC_RIGHT)
),
// }}}
// Adjust {{{
[_ADJUST] = framework_via(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EEP_RST, DEBUG,
    C(KC_Z), C(KC_Y)
),
// }}}
// ARROW {{{
[_ARROW] = framework_via(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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
      if(ekycode != KC_SPC) {
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
        caps_flag = !caps_flag;
      }
    }
  }
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
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
