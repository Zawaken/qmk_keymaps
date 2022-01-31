/* Copyright 2019 Ealdin
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
#include QMK_KEYBOARD_H

#define CTL_ESC MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x14(
    /* Base
      * ,-------------------------------------------------------------------------------------------------.
      * |   `  |   1  |   2  |   3  |   4  |   5  |   -  |   +  |   6  |   7  |   8  |   9  |   0  | Bksp |
      * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
      * | Tab  |   Q  |   W  |   F  |   P  |   G  |   [  |   ]  |   J  |   L  |   U  |   Y  |   ;  | Del  |
      * |------+------+------+------+------+-------------+------+------+------+------+------+------+------|
      * | Esc  |   A  |   R  |   S  |   T  |   D  | Home | PgUp |   H  |   N  |   E  |   I  |   O  |  "   |
      * |------+------+------+------+------+------|------+------+------+------+------+------+------+------|
      * | Shift|   Z  |   X  |   C  |   V  |   B  | End  | PgDn |   K  |   M  |   ,  |   .  |   /  | Enter|
      * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
      * | Ctrl |  GUI | CpsLk|  Alt |  Fn2 | Space| Space| Space| Space|  Fn1 | Left | Down |  Up  | Right|
      * `-------------------------------------------------------------------------------------------------'
      */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_DEL,
    KC_CTL_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_HOME, KC_PGUP, KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    KC_LGUI, KC_LCTL, KC_LALT, KC_CAPS, MO(2),   KC_BSPC, KC_BSPC, KC_SPC,  KC_SPC,  TG(1),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [1] = LAYOUT_ortho_5x14(
    /* Layer 1
      * ,-------------------------------------------------------------------------------------------------.
      * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |  F12 | PScr |
      * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
      * |      |      |      |      |      |      |      |      |      |      |      |      |      |  |   |
      * |------+------+------+------+------+-------------+------+------+------+------+------+------+------|
      * |      |      |      |      |      |      |      |      |      |      |      |      |      |Pause |
      * |------+------+------+------+------+------|------+------+------+------+------+------+------+------|
      * |      |      |      |      |      |      |      |      |      |      |      |      |      |Insert|
      * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
      * | Reset|      |      |      |      |      |      |      |      |      |      |      |      |ScrLk |
      * `-------------------------------------------------------------------------------------------------'
      */
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLCK
  ),

  [2] = LAYOUT_ortho_5x14(
  /* Layer 2
      * ,-------------------------------------------------------------------------------------------------.
      * |Toggle| Mode+| Mode-| Hue+ | Hue- | Sat+ | Sat- |Value+|Value-|      |      |      |      |      |
      * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
      * |Static|Breath| Rainb| Swirl| Snake|Knight| Xmas | Grad | Test |      |      |      |      |      |
      * |------+------+------+------+------+-------------+------+------+------+------+------+------+------|
      * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
      * |------+------+------+------+------+------|------+------+------+------+------+------+------+------|
      * |      |      |      |      |      |      |      |      |      |      |      |      |      | Mute |
      * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
      * |      |      |      |      |      |      | Stop | Play |      |      | Prev | Vol- | Vol+ | Next |
      * `-------------------------------------------------------------------------------------------------'
      */
    RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
    RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
    _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
  ),
};
