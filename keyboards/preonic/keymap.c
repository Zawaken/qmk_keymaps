// includes {{{
#include QMK_KEYBOARD_H
#include "muse.h"
#include "common.h"
// }}}
// keymaps {{{
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬──────┬──────┬──────┬───────┬─────┬──────┬───────┬──────┬──────┬────┬─────────┐
//    │    `    │  1   │  2   │  3   │   4   │  5  │  6   │   7   │  8   │  9   │ 0  │    \    │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │   tab   │  q   │  w   │  f   │   p   │  g  │  j   │   l   │  u   │  y   │ ;  │  bspc   │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │ CTL_ESC │  a   │  r   │  s   │   t   │  d  │  h   │   n   │  e   │  i   │ o  │    '    │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │  lsft   │  z   │  x   │  c   │   v   │  b  │  k   │   m   │  ,   │  .   │ /  │ SC_SENT │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │  ARROW  │ aLGR │ lalt │ lgui │ LOWER │ spc │ bspc │ RAISE │ left │ down │ up │  rght   │
//    └─────────┴──────┴──────┴──────┴───────┴─────┴──────┴───────┴──────┴──────┴────┴─────────┘
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4  , KC_5   , KC_6    , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSLS,
  KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P  , KC_G   , KC_J    , KC_L  , KC_U    , KC_Y    , KC_SCLN , KC_BSPC,
  CTL_ESC , KC_A    , KC_R    , KC_S    , KC_T  , KC_D   , KC_H    , KC_N  , KC_E    , KC_I    , KC_O    , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_K    , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , SC_SENT,
  ARROW   , KC_ALGR , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_BSPC , RAISE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

//    ┌─────────┬──────┬──────┬──────┬───────┬─────┬──────┬───────┬──────┬──────┬────┬─────────┐
//    │    `    │  1   │  2   │  3   │   4   │  5  │  6   │   7   │  8   │  9   │ 0  │    \    │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │   tab   │  q   │  w   │  e   │   r   │  t  │  y   │   u   │  i   │  o   │ p  │  bspc   │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │ CTL_ESC │  a   │  s   │  d   │   f   │  g  │  h   │   j   │  k   │  l   │ ;  │    '    │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │  lsft   │  z   │  x   │  c   │   v   │  b  │  n   │   m   │  ,   │  .   │ /  │ SC_SENT │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │  ARROW  │ aLGR │ lalt │ lgui │ LOWER │ spc │ bspc │ RAISE │ left │ down │ up │  rght   │
//    └─────────┴──────┴──────┴──────┴───────┴─────┴──────┴───────┴──────┴──────┴────┴─────────┘
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4  , KC_5   , KC_6    , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSLS,
  KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y    , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC,
  CTL_ESC , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H    , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N    , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , SC_SENT,
  ARROW   , KC_ALGR , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_BSPC , RAISE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

//    ┌─────────┬──────┬──────┬──────┬───────┬─────┬──────┬───────┬──────┬──────┬────┬─────────┐
//    │    `    │  1   │  2   │  3   │   4   │  5  │  6   │   7   │  8   │  9   │ 0  │    \    │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │   tab   │  q   │  d   │  r   │   w   │  b  │  j   │   f   │  u   │  p   │ ;  │  bspc   │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │ CTL_ESC │  a   │  s   │  h   │   t   │  g  │  y   │   n   │  e   │  o   │ i  │    '    │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │  lsft   │  z   │  x   │  m   │   c   │  v  │  k   │   l   │  ,   │  .   │ /  │ SC_SENT │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼──────┼───────┼──────┼──────┼────┼─────────┤
//    │  ARROW  │ aLGR │ lalt │ lgui │ LOWER │ spc │ bspc │ RAISE │ left │ down │ up │  rght   │
//    └─────────┴──────┴──────┴──────┴───────┴─────┴──────┴───────┴──────┴──────┴────┴─────────┘
[_WORKMAN] = LAYOUT_preonic_grid(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4  , KC_5   , KC_6    , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSLS,
  KC_TAB  , KC_Q    , KC_D    , KC_R    , KC_W  , KC_B   , KC_J    , KC_F  , KC_U    , KC_P    , KC_SCLN , KC_BSPC,
  CTL_ESC , KC_A    , KC_S    , KC_H    , KC_T  , KC_G   , KC_Y    , KC_N  , KC_E    , KC_O    , KC_I    , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_M    , KC_C  , KC_V   , KC_K    , KC_L  , KC_COMM , KC_DOT  , KC_SLSH , SC_SENT,
  ARROW   , KC_ALGR , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_BSPC , RAISE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬──────────┬──────┬──────┬──────┬────────┬──────┐
//    │     │     │     │     │     │     │   nUM    │ kp_7 │ kp_8 │ kp_9 │  kp_-  │ sCRL │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼──────────┼──────┼──────┼──────┼────────┼──────┤
//    │     │     │     │     │     │     │          │ kp_4 │ kp_5 │ kp_6 │  kp_+  │ del  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼──────────┼──────┼──────┼──────┼────────┼──────┤
//    │     │     │     │     │     │     │          │ kp_1 │ kp_2 │ kp_3 │ kp_ent │      │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼──────────┼──────┼──────┼──────┼────────┼──────┤
//    │     │     │     │     │     │     │ kro_auto │ kp_0 │ kp_0 │ kp_, │ kp_ent │      │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼──────────┼──────┼──────┼──────┼────────┼──────┤
//    │     │     │     │     │     │     │          │      │      │      │        │      │
//    └─────┴─────┴─────┴─────┴─────┴─────┴──────────┴──────┴──────┴──────┴────────┴──────┘
[_ARROW] = LAYOUT_preonic_grid(
  _______ , _______ , _______ , _______ , _______ , _______ , KC_NUM            , KC_P7   , KC_P8   , KC_P9   , KC_PMNS , KC_SCRL,
  _______ , _______ , _______ , _______ , _______ , _______ , _______           , KC_P4   , KC_P5   , KC_P6   , KC_PPLS , KC_DEL ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______           , KC_P1   , KC_P2   , KC_P3   , KC_PENT , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , MAGIC_TOGGLE_NKRO , KC_P0   , KC_P0   , KC_PCMM , KC_PENT , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────────┬─────────┬──────┬──────┬──────┐
//    │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │    &     │    *    │  (   │  )   │ bspc │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │    &     │    *    │  (   │  )   │ del  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │ del │ f1  │ f2  │ f3  │ f4  │ f5  │ f6  │    _     │    +    │  {   │  }   │  |   │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │     │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │ S(iso--) │ S(iso\) │ home │ end  │      │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │     │     │     │     │     │     │     │          │  mply   │ vold │ volu │ mnxt │
//    └─────┴─────┴─────┴─────┴─────┴─────┴─────┴──────────┴─────────┴──────┴──────┴──────┘
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR    , KC_ASTR    , KC_LPRN , KC_RPRN , KC_BSPC,
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR    , KC_ASTR    , KC_LPRN , KC_RPRN , KC_DEL ,
  KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_UNDS    , KC_PLUS    , KC_LCBR , KC_RCBR , KC_PIPE,
  _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , S(KC_NUHS) , S(KC_NUBS) , KC_HOME , KC_END  , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    , KC_MPLY    , KC_VOLD , KC_VOLU , KC_MNXT
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┬──────┬──────┬──────┬──────┐
//    │  `  │  1  │  2  │  3  │  4  │  5  │  6  │   7   │  8   │  9   │  0   │ bspc │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │  `  │  1  │  2  │  3  │  4  │  5  │  6  │   7   │  8   │  9   │  0   │ del  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │ del │ f1  │ f2  │ f3  │ f4  │ f5  │ f6  │   -   │  =   │  [   │  ]   │  \   │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │     │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │ iso-- │ iso\ │ pgup │ pgdn │      │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │     │     │     │     │     │     │     │       │ mply │ vold │ volu │ mnxt │
//    └─────┴─────┴─────┴─────┴─────┴─────┴─────┴───────┴──────┴──────┴──────┴──────┘
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL ,
  KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
  _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NUHS , KC_NUBS , KC_PGUP , KC_PGDN , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MPLY , KC_VOLD , KC_VOLU , KC_MNXT
),

//    ┌─────┬─────────┬─────────┬───────┬────────┬─────────┬─────────┬────────┬─────────┬─────────┬─────┬─────────┐
//    │ f1  │   f2    │   f3    │  f4   │   f5   │   f6    │   f7    │   f8   │   f9    │   f10   │ f11 │   f12   │
//    ├─────┼─────────┼─────────┼───────┼────────┼─────────┼─────────┼────────┼─────────┼─────────┼─────┼─────────┤
//    │     │ QK_BOOT │ DB_TOGG │       │        │         │         │        │         │         │     │   del   │
//    ├─────┼─────────┼─────────┼───────┼────────┼─────────┼─────────┼────────┼─────────┼─────────┼─────┼─────────┤
//    │     │   ins   │         │ AU_ON │ AU_OFF │ AG_NORM │ AG_SWAP │ QWERTY │ COLEMAK │ WORKMAN │     │ SARCASM │
//    ├─────┼─────────┼─────────┼───────┼────────┼─────────┼─────────┼────────┼─────────┼─────────┼─────┼─────────┤
//    │     │         │         │ MU_ON │ MU_OFF │  MI_ON  │ MI_OFF  │        │         │         │     │         │
//    ├─────┼─────────┼─────────┼───────┼────────┼─────────┼─────────┼────────┼─────────┼─────────┼─────┼─────────┤
//    │     │         │         │       │        │         │         │        │         │         │     │         │
//    └─────┴─────────┴─────────┴───────┴────────┴─────────┴─────────┴────────┴─────────┴─────────┴─────┴─────────┘
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  _______ , QK_BOOT , DB_TOGG , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_DEL ,
  _______ , KC_INS  , _______ , AU_ON   , AU_OFF  , AG_NORM , AG_SWAP , QWERTY  , COLEMAK , WORKMAN , _______ , SARCASM,
  _______ , _______ , _______ , MU_ON   , MU_OFF  , MI_ON   , MI_OFF  , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
)
};
// }}}
// }}}
// variables {{{
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
// }}}
