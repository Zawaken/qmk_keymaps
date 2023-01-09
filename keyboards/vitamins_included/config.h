#pragma once

/* Use I2C or Serial. Default is Serial */
// #define USE_I2C

/* Select hand configuration */
// Defaults:
// Rev1: EE_HANDS
// Rev2: SPLIT_HAND_PIN B4

// You can override the defaults (rev1 doesn't support SPLIT_HAND_PIN)
//#define EE_HANDS
//#define MASTER_LEFT
//#define MASTER_RIGHT


#ifdef AUDIO_ENABLE
  #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                SONG(DVORAK_SOUND), \
                                SONG(COLEMAK_SOUND) \
                              }
#endif
