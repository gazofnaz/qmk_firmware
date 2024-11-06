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
        KC_Q,          KC_W,          KC_E,             KC_R,             KC_T,       KC_Y,             KC_U,             KC_I,          KC_O,          KC_P,
        LGUI_T(KC_A),  LALT_T(KC_S),  LCTL_T(KC_D),     LSFT_T(KC_F),     KC_G,       KC_H,             RSFT_T(KC_J),     RCTL_T(KC_K),  RALT_T(KC_L),  RGUI_T(KC_SCLN),
        KC_Z,          KC_X,          KC_C,             KC_V,             KC_B,       KC_N,             KC_M,             KC_COMM,       KC_DOT,        KC_SLASH,
                                      LT(NAV, KC_SPC),  LT(MOU, KC_TAB),              LT(SYM, KC_ENT),  LT(NUM, KC_BSPC)
//   |----LEFT-------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------------------
  ),

  [SYM] = LAYOUT(
//   |----LEFT-------------------------------------------------------------------   |----RIGHT---------------------------------------------------------------
        KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,      KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,
        KC_COLN,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_PLUS,      KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,
        KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_PIPE,      KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,
                                                        KC_RPRN,        KC_UNDS,      KC_NO,         KC_NO
//   |----LEFT-------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------
  ),

  [NUM] = LAYOUT(
//   |----LEFT-------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------------
        KC_LBRC,          KC_7,          KC_8,          KC_9,          KC_RBRC,        KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,
        KC_SCLN,          KC_4,          KC_5,          KC_6,          KC_EQL,         KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,
        KC_GRV,           KC_1,          KC_2,          KC_3,          KC_NUBS,        KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,
                                                        KC_0,          KC_MINS,        KC_NO,         KC_NO
//   |----LEFT-------------------------------------------------------------------   |----RIGHT-----------------------------------------------------------------------
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
