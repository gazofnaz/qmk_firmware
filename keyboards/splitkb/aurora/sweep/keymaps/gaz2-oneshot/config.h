#pragma once

#define SPLIT_LAYER_STATE_ENABLE

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

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 35
