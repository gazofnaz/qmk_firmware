#include QMK_KEYBOARD_H
#include "keymap_uk.h"

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
  [BASE] = LAYOUT_split_3x6_3(
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
        KC_LALT,  KC_Q,               KC_W,               KC_E,               KC_R,                 KC_T,                    KC_Y,             KC_U,                KC_I,              KC_O,              KC_P,             KC_GRV,
        KC_LSFT,  LGUI_T(KC_A),       LALT_T(KC_S),       LCTL_T(KC_D),       LSFT_T(KC_F),         KC_G,                    KC_H,             RSFT_T(KC_J),        RCTL_T(KC_K),      RALT_T(KC_L),      RGUI_T(KC_SCLN),  UK_DQUO,
        KC_LCTL,  KC_Z,               KC_X,               KC_C,               KC_V,                 KC_B,                    KC_N,             KC_M,                KC_COMM,           KC_DOT,            KC_SLASH,         UK_BSLS,
                                                          LT(MED, KC_ESC),    LT(NAV, KC_SPC),      LT(MOU, KC_TAB),         LT(FUN, KC_ENT),  LT(NUM, KC_BSPC),    KC_DEL
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
  ),

  [SYM] = LAYOUT_split_3x6_3(
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
        KC_TRNS,  KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,                     QK_LLCK,          KC_NO,               KC_NO,             KC_NO,             KC_NO,            KC_NO,
        KC_TRNS,  LGUI_T(KC_NO),      LALT_T(KC_NO),      LCTL_T(KC_NO),      LSFT_T(KC_NO),      KC_NO,                     KC_NO,            RSFT_T(KC_NO),       RCTL_T(KC_NO),     RALT_T(KC_NO),     RGUI_T(KC_NO),    KC_NO,
        KC_TRNS,  KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,                     KC_NO,            KC_NO,               KC_NO,             KC_NO,             KC_NO,            KC_NO,
                                                          KC_NO,              KC_NO,              KC_NO,                     KC_NO,            KC_NO,               KC_NO
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
  ),

  [NUM] = LAYOUT_split_3x6_3(
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
        KC_TRNS,  KC_LBRC,            KC_7,               KC_8,               KC_9,                 KC_RBRC,                 QK_LLCK,          KC_NO,               KC_NO,             KC_NO,             KC_NO,            KC_PSCR,
        KC_TRNS,  KC_LPRN,            LALT_T(KC_4),       LCTL_T(KC_5),       LSFT_T(KC_6),         KC_RPRN,                 KC_BSLS,          RSFT_T(KC_NO),       RCTL_T(UK_QUOT),   RALT_T(KC_MINS),   RGUI_T(KC_EQL),   KC_PSCR,
        KC_TRNS,  KC_0,               KC_1,               KC_2,               KC_3,                 KC_MINS,                 KC_NO,            KC_NO,               KC_TRNS,           KC_TRNS,           KC_TRNS,          KC_NO,
                                                          KC_ESC,             KC_SPC,               KC_DOT,                  KC_TRNS,          KC_TRNS,             KC_TRNS
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
  ),

  [FUN] = LAYOUT_split_3x6_3(
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
        KC_TRNS,  KC_F12,             KC_F7,              KC_F8,              KC_F9,                KC_PSCR,                 QK_LLCK,          KC_NO,               KC_NO,             KC_NO,             KC_NO,            KC_NO,
        KC_TRNS,  LGUI_T(KC_F11),     LALT_T(KC_F4),      LCTL_T(KC_F5),      LSFT_T(KC_F6),        KC_NO,                   KC_NO,            RSFT_T(KC_NO),       RCTL_T(KC_NO),     RALT_T(KC_NO),     RGUI_T(KC_NO),    KC_NO,
        KC_TRNS,  KC_F10,             KC_F1,              KC_F2,              KC_F3,                KC_NO,                   KC_NO,            KC_NO,               KC_NO,             KC_NO,             KC_NO,            KC_NO,
                                                          KC_NO,              KC_SPC,               KC_TAB,                  KC_NO,            KC_NO,               KC_NO
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
  ),

  [MOU] = LAYOUT_split_3x6_3(
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
        KC_TRNS,  KC_NO,              KC_NO,              KC_NO,              KC_NO,                QK_LLCK,                 KC_NO,            KC_NO,               MS_UP,             KC_NO,             KC_NO,            KC_NO,
        KC_TRNS,  KC_LGUI,            KC_LALT,            KC_LCTL,            KC_LSFT,              KC_NO,                   KC_NO,            MS_LEFT,             MS_DOWN,           MS_RGHT,           KC_CAPS,          KC_NO,
        KC_TRNS,  KC_NO,              KC_NO,              KC_NO,              KC_NO,                KC_NO,                   MS_WHLL,          MS_WHLD,             MS_WHLU,           MS_WHLR,           KC_NO,            KC_NO,
                                                          KC_NO,              KC_NO,                KC_NO,                   MS_BTN2,          MS_BTN1,             MS_BTN3
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
  ),

  [NAV] = LAYOUT_split_3x6_3(
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
        KC_TRNS,  KC_NO,              KC_NO,              KC_NO,              KC_NO,                QK_LLCK,                 KC_NO,            KC_NO,               KC_UP,             KC_NO,             KC_NO,            KC_NO,
        KC_TRNS,  KC_LGUI,            KC_LALT,            KC_LCTL,            KC_LSFT,              KC_NO,                   KC_HOME,          KC_LEFT,             KC_DOWN,           KC_RIGHT,          KC_CAPS,          KC_END,
        KC_TRNS,  KC_UNDO,            KC_CUT,             KC_COPY,            KC_PASTE,             KC_ENT,                  KC_NO,            KC_PGDN,             KC_PGUP,           KC_END,            KC_INS,           KC_NO,
                                                          KC_NO,              KC_NO,                KC_NO,                   KC_ENT,           KC_BSPC,             KC_DEL
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
  ),

  [MED] = LAYOUT_split_3x6_3(
//   |----LEFT------------------------------------------------------------------------------------------                   |----RIGHT----------------------------------------------------------------------------------------
        KC_TRNS,  KC_NO,              KC_NO,              KC_NO,              KC_NO,                QK_LLCK,                 UG_VALU,          KC_NO,             KC_PGUP,           KC_NO,             KC_NO,            KC_NO,
        KC_TRNS,  LGUI_T(KC_NO),      LALT_T(KC_NO),      LCTL_T(KC_NO),      LSFT_T(KC_NO),        KC_NO,                   UG_SATU,          KC_HOME,           KC_PGDN,           KC_END,            KC_CAPS,          KC_NO,
        KC_TRNS,  KC_NO,              KC_NO,              KC_NO,              KC_NO,                KC_NO,                   UG_HUEU,          KC_NO,             KC_NO,             KC_NO,             KC_INS,           KC_NO,
                                                          KC_NO,              KC_NO,                KC_NO,                   UG_TOGG,          UG_PREV,             UG_NEXT
//   |----LEFT------------------------------------------------------------------------------------------                   |--RIGHT----------------------------------------------------------------------------------------
  )
};


void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_RED);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

//void housekeeping_task_user(void) {
//    switch (get_highest_layer(layer_state | default_layer_state)) {
//        case BASE:
//            // non-rgb colours don't work at low levels since the individual leds are still visible, the colours don't merge
//            rgblight_sethsv_at(HSV_BLACK, 0); // Off
//            rgblight_sethsv_at(HSV_BLACK, 1);
//            break;
//        case NAV:
//            rgblight_sethsv_at(0, 255, 25, 0); // Red
//            break;
//        case MOU:
//            rgblight_sethsv_at(170, 255, 25, 0); // Blue
//            break;
//        case MED:
//            rgblight_sethsv_at(85, 255, 10, 0); // Green
//            break;
//        case NUM:
//            rgblight_sethsv_at(0, 255, 25, 1); // Red
//            break;
//        case FUN:
//            rgblight_sethsv_at(85, 255, 10, 1); // Green
//            break;
//    }
//}
