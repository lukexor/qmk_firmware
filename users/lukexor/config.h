#pragma once

#define UUUUUUU XXXXXXX // Unused key

// Mod-tap settings
#undef TAPPING_TERM
#define TAPPING_TERM 200

#define FLOW_TAP_TERM 150
#define QUICK_TAP_TERM 120
#define PERMISSIVE_HOLD

// Editing Shortcuts
#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

// Layers
// #define _BASE 0
// #define _GAME 1
// #define _LO 2  // Lower
// #define _RS 3  // Raise
// #define _ADJ 4 // Adjust
#define _BS 0 // Base
#define _BN 1 // Base (No Mods)
#define _GM 2 // Game
#define _MD 3 // Media
#define _NV 4 // Nav
#define _MS 5 // Mouse
#define _SY 6 // Symbol
#define _NM 7 // Number
#define _FN 8 // Function

// One shot mods
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)

// Homerow
#define SH(key) SFT_T(key)
#define CH(key) CTL_T(key)
#define AH(key) ALT_T(key)
#define AG(key) RALT_T(key)
#define GH(key) GUI_T(key)
#define MHH(key) MEH_T(key)
#define HYH(key) HYPR_T(key)

// Layer tap
// #define LOT(key) LT(_LO, key)
// #define RST(key) LT(_RS, key)
#define MDT(key) LT(_MD, key)
#define NVT(key) LT(_NV, key)
#define MST(key) LT(_MS, key)
#define SYT(key) LT(_SY, key)
#define NMT(key) LT(_NM, key)
#define FNT(key) LT(_FN, key)

// Mod tap keys
#define ST(key) SFT_T(key)
#define CT(key) CTL_T(key)
#define AT(key) ALT_T(key)
#define GT(key) GUI_T(key)
#define MHT(key) MEH_T(key)
#define HYT(key) HYPR_T(key)

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 1000

#define RGBLIGHT_LAYERS
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_HUE 128
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 128
#define RGBLIGHT_DEFAULT_SPD 20
#define RGBLIGHT_SLEEP

// Mouse key speed and acceleration.
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_WHEEL_DELAY 0

// Reduces firmware size
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT // Limit to only 16 layers
