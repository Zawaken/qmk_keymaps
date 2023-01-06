#include "common.h"

#include "quantum.h"

#ifdef COMMON_PROCESS_RECORD
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool sarcasm_flag = false;
  static bool caps_flag = false;
  static int same_case = 0;

  if(sarcasm_flag && record->event.pressed) {
    if(keycode != KC_SPC) {
      if(rand() % 2 == 1 || same_case >= 1) {
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
        caps_flag = !caps_flag;
        same_case = 0;
      } else {
        same_case++;
      }
    }
  }
#ifdef COMMON_LAYERS
  switch(keycode) {
    //{{{Colemak, Qwerty etc
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case ARROW: // {{{
      if (record->event.pressed) {
        layer_on(_ARROW);
      } else {
        layer_off(_ARROW);
      }
      return false;
      break; // }}}
    case SARCASM: // {{{
      if(record->event.pressed) {
        sarcasm_flag = !sarcasm_flag;
        if(caps_flag) {
          register_code(KC_CAPS);
          unregister_code(KC_CAPS);
        }
      }
      return false;
      break; // }}}
    #endif
    // }}}

    #ifdef COMMON_ORTHO_LAYERS // {{{
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
    #endif // }}}

    #ifdef BACKLIT_ENABLED // {{{
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef __AVR__
        writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef __AVR__
        writePinHigh(E6);
        #endif
      }
      return false;
      break;
    #endif // }}}
    #ifdef PLOVER_ENABLED // {{{
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    #endif // }}}
  }
  return true;
};
#endif
