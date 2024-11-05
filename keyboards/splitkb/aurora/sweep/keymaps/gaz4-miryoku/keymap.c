#include QMK_KEYBOARD_H

//#include "g/keymap_combo.h"

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    MOU,
    MED,
    FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
//   |----LEFT-------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------------------
        KC_Q,  KC_W,  KC_E,               KC_R,                                         KC_T,    KC_Y,           KC_U,   KC_I,     KC_O,    KC_P,
        LGUI_T(KC_A),  LALT_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),       KC_G,                                          KC_H,    RSFT_T(KC_J),   RCTL_T(KC_K),     RALT_T(KC_L),    RGUI_T(KC_SCLN),
        KC_Z,  KC_X,  KC_C,               KC_V,                    KC_B,                KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLASH,
                                          LT(NAV, KC_SPC),    LT(MOU, KC_TAB),                          LT(SYM, KC_ENT),  LT(NUM, KC_BSPC)
//   |----LEFT-------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------------------
  ),

  [SYM] = LAYOUT(
//   |----LEFT-------------------------------------------------------------------------   |----RIGHT---------------------------------------------------------------
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_NO,     KC_NO,              KC_NO,   KC_NO
//   |----LEFT-------------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------
  ),

  [NUM] = LAYOUT(
//   |----LEFT----------------------------------------------   |----RIGHT-------------------------------------
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              MO(FUN), KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_NO,     KC_NO,              KC_NO,   KC_NO
//   |----LEFT----------------------------------------------   |----RIGHT-------------------------------------
  ),

  [NAV] = LAYOUT(
//   |----LEFT---------------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     MO(MED),            KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_NO,     KC_NO,              KC_NO,   KC_NO
//   |----LEFT----------------------------------------------------------------------------   |---RIGHT------------------------------------------------------------------
  ),

  [MOU] = LAYOUT(
//   |----LEFT---------------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_NO,     KC_NO,              KC_NO,   KC_NO
//   |----LEFT----------------------------------------------------------------------------   |---RIGHT------------------------------------------------------------------
  ),

  [MED] = LAYOUT(
//   |----LEFT---------------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_NO,     KC_NO,              KC_NO,   KC_NO
//   |----LEFT----------------------------------------------------------------------------   |---RIGHT------------------------------------------------------------------
  ),

  [FUN] = LAYOUT(
//   |----LEFT---------------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,     KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_NO,     KC_NO,              KC_NO,   KC_NO
//   |----LEFT----------------------------------------------------------------------------   |---RIGHT------------------------------------------------------------------
  )
};


void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void housekeeping_task_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case BASE:
            // non-rgb colours don't work at low levels since the individual leds are still visible, the colours don't merge
            rgblight_sethsv_at(HSV_BLACK, 0); // Off
            rgblight_sethsv_at(HSV_BLACK, 1);
            break;
        case SYM:
            rgblight_sethsv_at(0, 255, 25, 0); // Red
            rgblight_sethsv_at(0, 255, 25, 1);
            break;
        case NUM:
            rgblight_sethsv_at(85, 255, 10, 0); // Green
            rgblight_sethsv_at(85, 255, 10, 1);
            break;
        case NAV:
            rgblight_sethsv_at(170, 255, 25, 0); // Blue
            rgblight_sethsv_at(170, 255, 25, 1);
            break;
        case MOU:
            rgblight_setrgb_at(2, 2, 0, 0); // RG
            rgblight_setrgb_at(2, 2, 0, 1);
            break;
        case MED:
            rgblight_setrgb_at(0, 2, 2, 0); // RG
            rgblight_setrgb_at(0, 2, 2, 1);
            break;
        case FUN:
            rgblight_setrgb_at(2, 0, 2, 0); // RG
            rgblight_setrgb_at(2, 0, 2, 1);
            break;
    }
}
