#include QMK_KEYBOARD_H

#define KC_LSHZ LSFT_T(KC_Z)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CTLA LCTL_T(KC_A)
#define KC_SFTR LSFT_T(KC_R)
#define KC_GUIS LGUI_T(KC_S)
#define KC_ALTT LALT_T(KC_T)
#define KC_RALX RALT_T(KC_X)

#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_ALTN LALT_T(KC_N)
#define KC_GUIE RGUI_T(KC_E)
#define KC_SFTI RSFT_T(KC_I)
#define KC_CTLO RCTL_T(KC_O)


#define KC_SPM1 LT(1, KC_SPC)
#define KC_ENM2 LT(2, KC_ENT)
#define KC_BSM3 LT(3, KC_BSPC)
#define KC_WM4  LT(4, KC_W)
#define KC_FM5  LT(5, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,    KC_WM4,  KC_FM5,  KC_P,    KC_G,            KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_CTLA, KC_SFTR, KC_GUIS, KC_ALTT, KC_D,            KC_H,    KC_ALTN, KC_GUIE, KC_SFTI, KC_CTLO,
    KC_LSHZ, KC_RALX, KC_C,    KC_V,    KC_B,            KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_RLSH,
                                    KC_GUTA, KC_SPM1, KC_ENM2, KC_BSM3
  ),

  [1] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    QK_GESC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN2,         MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_ENT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [2] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, QK_BOOT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [4] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [5] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         MS_BTN1, MS_WHLU, MS_BTN2, KC_TRNS, KC_TRNS,
    KC_TRNS,  MS_BTN1, KC_TRNS, MS_BTN2, KC_TRNS,         MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  // [6] = LAYOUT(
  //   KC_TRNS,  KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //   KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,         KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS,
  //   KC_TRNS,  KC_HOME, KC_PGDN, KC_END,  KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  // ),
};
