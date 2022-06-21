#include "common.h"

#include "quantum.h"

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   static bool sarcasm_flag = false;
//   static bool caps_flag = false;
//
//   if(sarcasm_flag) {
//     if(record->event.pressed) {
//       if(keycode != KC_SPC) {
//         register_code(KC_CAPS);
//         unregister_code(KC_CAPS);
//         caps_flag = !caps_flag;
//       }
//     }
//   }
//
//   switch(keycode) {
//     case SARCASM:
//       if(record->event.pressed) {
//         sarcasm_flag = !sarcasm_flag;
//         if(caps_flag) {
//           register_code(KC_CAPS);
//           unregister_code(KC_CAPS);
//         }
//       }
//       return false;
//       break;
//   }
//   return true;
// };
