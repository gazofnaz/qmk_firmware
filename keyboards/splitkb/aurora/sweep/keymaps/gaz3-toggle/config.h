#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE // syncs the capslock led value to each board

#undef WS2812_DI_PIN
#define WS2812_DI_PIN 25

#undef RGBLED_SPLIT
#define RGBLED_SPLIT {1, 1}
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 2
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 150

#define LED_CAPS_LOCK_PIN 24
#define LED_PIN_ON_STATE 0

#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 240
#define RETRO_TAPPING


#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1
#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED 1
#undef MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED 12
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 22
#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 35
