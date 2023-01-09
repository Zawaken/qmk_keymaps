/* VIA specific defines to increase dynamic layer count */
// #define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 3
// #define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define COMMON_LAYERS
#define COMMON_ORTHO_LAYERS
#define COMMON_PROCESS_RECORD

/* defining an extra row for encoder assignment in VIA */
#undef MATRIX_ROWS
#define MATRIX_ROWS 11

#undef DEBOUNCE
#define DEBOUNCE 6
