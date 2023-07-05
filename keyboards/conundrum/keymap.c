#include QMK_KEYBOARD_H

#include "quantum.h"
#include "common.h"

enum layers {
  _COLEMAK,
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ARROW
};

enum keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  DVORAK,
  ARROW
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

// keymaps {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty {{{
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | LCtrl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SFTENT|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ARROW| AltGr| Alt  | GUI  |Lower |Space | Space|Raise | Left | Down | Up   |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_grid(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
      CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
      ARROW,   KC_ALGR, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
    // }}}
    /* Colemak {{{
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_grid(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_J,    KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
      CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_H,    KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_K,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      ARROW,   KC_ALGR, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
    // }}}
    /* Dvorak {{{
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_grid(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,    KC_G,  KC_C,    KC_R,    KC_L,  KC_BSPC,
      KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,    KC_H,  KC_T,    KC_N,    KC_S,  KC_SLSH,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,    KC_M,  KC_W,    KC_V,    KC_Z,  KC_ENT,
      ARROW,   KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_BSPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    // }}}
    /* Arrow layout {{{
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      | DEL  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      | Left | Down |  Up  | Right|      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ARROW] = LAYOUT_grid(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    // }}}
    /* Lower {{{
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Play | Vol- | Vol+ | Next |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_grid(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,   KC_LPRN, KC_RPRN, KC_DEL,
      KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,   KC_LCBR, KC_RCBR, KC_PIPE,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS),KC_HOME, KC_END,  _______,
      _______, _______, _______, _______, _______, _______, KC_DEL,  _______,    KC_MPLY,   KC_VOLD, KC_VOLU, KC_MNXT),
    // }}}
    /* Raise {{{
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Play | Vol- | Vol+ | Next |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_grid(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
      _______, _______, _______, _______, _______, _______, KC_DEL, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT),
    // }}}
    /* Adjust (Lower + Raise) {{{
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_grid(
      _______, RESET, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
      _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______,  _______,
      _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
    // }}}

}; // }}}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
