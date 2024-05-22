#include QMK_KEYBOARD_H
#include "common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────┬──────┬──────┬──────┬───────┬─────┬─────┬───────┬──────┬──────┬────┬──────┐
//    │    `    │  1   │  2   │  3   │   4   │  5  │  6  │   7   │  8   │  9   │ 0  │ bspc │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │   tab   │  q   │  w   │  e   │   r   │  t  │  y  │   u   │  i   │  o   │ p  │ del  │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │ CTL_ESC │  a   │  s   │  d   │   f   │  g  │  h  │   j   │  k   │  l   │ ;  │  '   │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │  lsft   │  z   │  x   │  c   │   v   │  b  │  n  │   m   │  ,   │  .   │ /  │ ent  │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │ ADJUST  │ lctl │ lalt │ lgui │ LOWER │ spc │ spc │ RAISE │ left │ down │ up │ rght │
//    └─────────┴──────┴──────┴──────┴───────┴─────┴─────┴───────┴──────┴──────┴────┴──────┘
[_QWERTY] = LAYOUT_ortho_5x12(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4  , KC_5   , KC_6   , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_DEL ,
  CTL_ESC , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
  ADJUST  , KC_LCTL , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_SPC , RAISE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

//    ┌─────────┬──────┬──────┬──────┬───────┬─────┬─────┬───────┬──────┬──────┬────┬──────┐
//    │    `    │  1   │  2   │  3   │   4   │  5  │  6  │   7   │  8   │  9   │ 0  │ bspc │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │   tab   │  q   │  w   │  f   │   p   │  g  │  j  │   l   │  u   │  y   │ ;  │ del  │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │ CTL_ESC │  a   │  r   │  s   │   t   │  d  │  h  │   n   │  e   │  i   │ o  │  '   │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │  lsft   │  z   │  x   │  c   │   v   │  b  │  k  │   m   │  ,   │  .   │ /  │ ent  │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │ ADJUST  │ lctl │ lalt │ lgui │ LOWER │ spc │ spc │ RAISE │ left │ down │ up │ rght │
//    └─────────┴──────┴──────┴──────┴───────┴─────┴─────┴───────┴──────┴──────┴────┴──────┘
[_COLEMAK] = LAYOUT_ortho_5x12(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4  , KC_5   , KC_6   , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P  , KC_G   , KC_J   , KC_L  , KC_U    , KC_Y    , KC_SCLN , KC_DEL ,
  CTL_ESC , KC_A    , KC_R    , KC_S    , KC_T  , KC_D   , KC_H   , KC_N  , KC_E    , KC_I    , KC_O    , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_K   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
  ADJUST  , KC_LCTL , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_SPC , RAISE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

//    ┌─────────┬──────┬──────┬──────┬───────┬─────┬─────┬───────┬──────┬──────┬────┬──────┐
//    │    `    │  1   │  2   │  3   │   4   │  5  │  6  │   7   │  8   │  9   │ 0  │ bspc │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │   tab   │  '   │  ,   │  .   │   p   │  y  │  f  │   g   │  c   │  r   │ l  │ del  │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │ CTL_ESC │  a   │  o   │  e   │   u   │  i  │  d  │   h   │  t   │  n   │ s  │  /   │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │  lsft   │  ;   │  q   │  j   │   k   │  x  │  b  │   m   │  w   │  v   │ z  │ ent  │
//    ├─────────┼──────┼──────┼──────┼───────┼─────┼─────┼───────┼──────┼──────┼────┼──────┤
//    │ ADJUST  │ lctl │ lalt │ lgui │ LOWER │ spc │ spc │ RAISE │ left │ down │ up │ rght │
//    └─────────┴──────┴──────┴──────┴───────┴─────┴─────┴───────┴──────┴──────┴────┴──────┘
[_DVORAK] = LAYOUT_ortho_5x12(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4  , KC_5   , KC_6   , KC_7  , KC_8    , KC_9    , KC_0  , KC_BSPC,
  KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P  , KC_Y   , KC_F   , KC_G  , KC_C    , KC_R    , KC_L  , KC_DEL ,
  CTL_ESC , KC_A    , KC_O    , KC_E    , KC_U  , KC_I   , KC_D   , KC_H  , KC_T    , KC_N    , KC_S  , KC_SLSH,
  KC_LSFT , KC_SCLN , KC_Q    , KC_J    , KC_K  , KC_X   , KC_B   , KC_M  , KC_W    , KC_V    , KC_Z  , KC_ENT ,
  ADJUST  , KC_LCTL , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_SPC , RAISE , KC_LEFT , KC_DOWN , KC_UP , KC_RGHT
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────────┬─────────┬──────┬──────┬──────┐
//    │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │    &     │    *    │  (   │  )   │ bspc │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │    &     │    *    │  (   │  )   │ del  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │ del │ f1  │ f2  │ f3  │ f4  │ f5  │ f6  │    _     │    +    │  {   │  }   │  |   │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │     │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │ S(iso--) │ S(iso\) │      │      │      │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼──────────┼─────────┼──────┼──────┼──────┤
//    │     │     │     │     │     │     │     │          │  mnxt   │ vold │ volu │ mply │
//    └─────┴─────┴─────┴─────┴─────┴─────┴─────┴──────────┴─────────┴──────┴──────┴──────┘
[_LOWER] = LAYOUT_ortho_5x12(
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR    , KC_ASTR    , KC_LPRN , KC_RPRN , KC_BSPC,
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR    , KC_ASTR    , KC_LPRN , KC_RPRN , KC_DEL ,
  KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_UNDS    , KC_PLUS    , KC_LCBR , KC_RCBR , KC_PIPE,
  _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , S(KC_NUHS) , S(KC_NUBS) , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    , KC_MNXT    , KC_VOLD , KC_VOLU , KC_MPLY
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┬──────┬──────┬──────┬──────┐
//    │  `  │  1  │  2  │  3  │  4  │  5  │  6  │   7   │  8   │  9   │  0   │ bspc │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │  `  │  1  │  2  │  3  │  4  │  5  │  6  │   7   │  8   │  9   │  0   │ del  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │ del │ f1  │ f2  │ f3  │ f4  │ f5  │ f6  │   -   │  =   │  [   │  ]   │  \   │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │     │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │ iso-- │ iso\ │      │      │      │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────┼──────┼──────┼──────┼──────┤
//    │     │     │     │     │     │     │     │       │ mnxt │ vold │ volu │ mply │
//    └─────┴─────┴─────┴─────┴─────┴─────┴─────┴───────┴──────┴──────┴──────┴──────┘
[_RAISE] = LAYOUT_ortho_5x12(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL ,
  KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
  _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NUHS , KC_NUBS , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY
),

//    ┌─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────┐
//    │ f1  │   f2    │   f3    │   f4    │   f5    │   f6    │   f7    │   f8    │   f9    │   f10   │ f11 │ f12 │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┤
//    │     │ QK_BOOT │ RGB_TOG │ RGB_MOD │ RGB_HUD │ RGB_HUI │ RGB_SAD │ RGB_SAI │ RGB_VAD │ RGB_VAI │     │ del │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┤
//    │     │         │         │  AU_ON  │ AU_OFF  │ AG_NORM │ AG_SWAP │ QWERTY  │ COLEMAK │ DVORAK  │     │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┤
//    │     │         │         │         │         │         │         │         │         │         │     │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┤
//    │     │         │         │         │         │         │         │         │         │         │     │     │
//    └─────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────┴─────┘
[_ADJUST] = LAYOUT_ortho_5x12(
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  _______ , QK_BOOT , RGB_TOG , RGB_MOD , RGB_HUD , RGB_HUI , RGB_SAD , RGB_SAI , RGB_VAD , RGB_VAI , _______ , KC_DEL ,
  _______ , _______ , _______ , AU_ON   , AU_OFF  , AG_NORM , AG_SWAP , QWERTY  , COLEMAK , DVORAK  , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
)
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case QWERTY: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           PLAY_SONG(tone_qwerty); */
/*         #endif */
/*         persistent_default_layer_set(1UL<<_QWERTY); */
/*       } */
/*       return false; */
/*       break; */
/*     case COLEMAK: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           PLAY_SONG(tone_colemak); */
/*         #endif */
/*         persistent_default_layer_set(1UL<<_COLEMAK); */
/*       } */
/*       return false; */
/*       break; */
/*     case DVORAK: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           PLAY_SONG(tone_dvorak); */
/*         #endif */
/*         persistent_default_layer_set(1UL<<_DVORAK); */
/*       } */
/*       return false; */
/*       break; */
/*   } */
/*   return true; */
/* } */
