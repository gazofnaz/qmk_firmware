#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Forked/inspired by: https://github.dev/mattstenback/qmk_firmware (not inspired, copy pasted.)

#include QMK_KEYBOARD_H

#include "g/keymap_combo.h"
#include "oneshot.h"
#include "swapper.h"

// Keymap helpers
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define xxxxxxx KC_NO

// MacOS macros
#define SPOTL LGUI(KC_SPC)
#define ONEPW LGUI(KC_BSLS)
#define SC_SHOT SGUI(KC_4)

// Browser navigation
#define TAB_R LAG(KC_RIGHT)
#define TAB_L LAG(KC_LEFT)
#define BR_BACK LGUI(KC_LEFT)
#define BR_FORW LGUI(KC_RGHT)

// VIM window navigation
#define VIM_BUFL RCTL(KC_H)
#define VIM_BUFR RCTL(KC_L)

enum layers {
    BASE,
    SYM,
    NAV,
    NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window (cmd-tab)
};


//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    [0] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LSFT_T(KC_A), LT(5,KC_S), LT(1,KC_D), LT(3,KC_F), KC_G, KC_H, LT(4,KC_J), LT(2,KC_K), LT(6,KC_L), LSFT_T(KC_SCLN), KC_Z, LCTL_T(KC_X), LALT_T(KC_C), KC_V, KC_B, KC_N, KC_M, LALT_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH, KC_DEL, LT(7,KC_SPC), LT(7,KC_SPC), KC_BSPC),
//    [1] = LAYOUT(RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_BTN1, KC_WH_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_BTN2, KC_NO, KC_BTN1, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_WH_L, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//    [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LGUI, KC_NO, LCTL(KC_LALT), LCA(KC_LSFT), KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//    [3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_QUOT, KC_TRNS, KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, KC_TRNS, KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_BSLS, KC_GRV, KC_TRNS, RGB_RMOD, KC_TRNS, KC_TRNS, RGB_MOD),
//    [4] = LAYOUT(KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC, KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_VOLU),
//    [5] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//    [6] = LAYOUT(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//    [7] = LAYOUT(KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, DF(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT, KC_TRNS, KC_TAB, KC_NO, KC_TRNS)
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,      KC_U,    KC_I,    KC_O,    KC_QUOT,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,      KC_J,    KC_K,    KC_L,    KC_P,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_UNDS,
                                   LA_NAV,  KC_SPC,   KC_LSFT,   LA_SYM
    ),

    [SYM] = LAYOUT(
        KC_GRV,  KC_LPRN, KC_LCBR, KC_LBRC, KC_LT,   KC_GT,   KC_RBRC, KC_RCBR, KC_RPRN, KC_TILD,
        KC_PIPE, KC_SCLN, KC_EQL,  KC_MINS, KC_EXLM, KC_HASH, OS_CMD,  OS_CTRL, OS_ALT,  OS_SHFT,
        KC_AT,   KC_AMPR, KC_PLUS, KC_PERC, KC_QUES, KC_SLSH, KC_DLR,  KC_ASTR, KC_BSLS, KC_CIRC,
                                    _______, _______, _______, _______
    ),

    [NAV] = LAYOUT(
        SW_WIN,  SPOTL,   TAB_L,   TAB_R,   KC_VOLU, VIM_BUFL, KC_WH_D, KC_WH_U, VIM_BUFR, KC_DEL,
        OS_SHFT, OS_ALT,  OS_CTRL, OS_CMD,  KC_VOLD, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,  KC_BSPC,
        ONEPW,   SC_SHOT, BR_BACK, BR_FORW, KC_MPLY, KC_HOME,  KC_PGDN, KC_PGUP, KC_END,   KC_ENT,
                                   _______, _______, _______, _______
    ),


    [NUM] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F11,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_F12,
                                   _______, _______, _______, _______
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}


//#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
//const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//
//};
//#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
//
//void keyboard_post_init_user(void) {
//    // Initialize RGB to static black
//    rgblight_enable_noeeprom();
//    rgblight_sethsv_noeeprom(HSV_BLACK);
//    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//}
//
//void housekeeping_task_user(void) {
//    switch (get_highest_layer(layer_state | default_layer_state)) {
//        case 0:
//            // Default layer
//            rgblight_setrgb_at(RGB_BLACK, 0);
//            rgblight_setrgb_at(RGB_BLACK, 1);
//            break;
//        case 1:
//            rgblight_setrgb_at(10, 0, 0, 0);
//            rgblight_setrgb_at(10, 0, 0, 1);
//            break;
//        case 2:
//            rgblight_setrgb_at(0, 10, 0, 0);
//            rgblight_setrgb_at(0, 10, 0, 1);
//            break;
//        case 3:
//            rgblight_setrgb_at(0, 0, 10, 0);
//            rgblight_setrgb_at(0, 0, 10, 1);
//            break;
//    }
//}
