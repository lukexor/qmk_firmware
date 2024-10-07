#pragma once

#define XXX KC_NO   // No-op key
#define ___ KC_TRNS // Transparent key

// Layers
#define _COL 0
#define _EXT 1
#define _NUM 2
#define _FN 3

#define MG(key) LGUI_T(key)
#define MLA(key) LALT_T(key)
#define MRA(key) RALT_T(key)
#define MC(key) LCTL_T(key)
#define MS(key) LSFT_T(key)
#define MMEH(key) MEH_T(key)
#define MHYP(key) HYPR_T(key)

// Layer Toggles
#define _TC DF(_COL)

#define LCS(kc) LCTL(LSFT(kc))

// One shot mods
#define OLALT OSM(MOD_LALT)
#define OLGUI OSM(MOD_LGUI)
#define OLSFT OSM(MOD_LSFT)
#define OLCTL OSM(MOD_LCTL)
#define ORALT OSM(MOD_RALT)

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 1000
#define RGBLIGHT_LAYERS

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BAND_PINWHEEL_VAL
#define RGB_MATRIX_DEFAULT_HUE 213
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL 255
#define RGB_MATRIX_DEFAULT_SPD 20
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL + 3
#define RGBLIGHT_DEFAULT_HUE 128
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 128
#define RGBLIGHT_DEFAULT_SPD 20
#define RGBLIGHT_SLEEP

// Enabled RGB modes
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #undef ENABLE_RGB_MATRIX_BREATHING
// #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #undef ENABLE_RGB_MATRIX_MULTISPLASH
// #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL

// Reduces firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT // Limit to only 16 layers
