// includes {{{
#include QMK_KEYBOARD_H
#include "common.h"
// #include "encoder.h"
// }}}
// keymaps {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Colemak {{{
[_COLEMAK] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_MPLY,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,       KC_G,    KC_J,   KC_L,       KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
    CTL_ESC,  KC_A,    KC_R,    KC_S,    KC_T,       KC_D,    KC_H,   KC_N,       KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_K,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    ARROW, KC_ALGR, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
// }}}
// QWERTY{{{
[_QWERTY] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,   KC_7,       KC_8,    KC_9,    KC_0,    KC_MPLY,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,    KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,       KC_G,    KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    ARROW, KC_ALGR, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
// }}}
// Lower {{{
[_LOWER] = LAYOUT_ortho_5x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
),
// }}}
// Raise {{{
[_RAISE] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
),
// }}}
// Adjust {{{
[_ADJUST] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, QWERTY, COLEMAK, _______, _______, SARCASM,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
// }}}
// ARROW {{{
[_ARROW] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______, KC_DEL,
    _______, _______, _______, KC_BTN1, KC_BTN2, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______
)
// }}}
};
// }}}
// tap dance, leader {{{
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
    }
}
// }}}
// encoder {{{
#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  [_COLEMAK]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_QWERTY]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
  [_LOWER]    = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
  [_RAISE]    = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
  [_ADJUST]   = { ENCODER_CCW_CW(_______, _______)  },
  [_ARROW]    = { ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)  }
};
#endif
// }}}
