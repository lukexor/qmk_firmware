#include QMK_KEYBOARD_H

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SFT_T_ LSFT_T(KC_T)

// Qwerty Left-hand home row mods
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I RALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// Qwerty Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Shortcut mods
#define HYPR_Z HYPR_T(KC_Z)
#define HYPR_SLSH HYPR_T(KC_SLSH)
#define MEH_G MEH_T(KC_G)
#define MEH_M MEH_T(KC_M)

// Qwerty Shortcut mods
#define MEH_H MEH_T(KC_H)

// Thumb layers
#define _MEDIA_ESC LT(_MEDIA, KC_ESC)
#define _NAV_SPC LT(_NAV, KC_SPC)
#define _MOUSE_TAB LT(_MOUSE, KC_TAB)
#define _SYM_ENT LT(_SYM, KC_ENT)
#define _NUM_BSPC LT(_NUM, KC_BSPC)
#define _FN_DEL LT(_FN, KC_DEL)

// TODO: Add application shortcuts for MEH and HYPR keys
enum platform_keycodes { U_RDO = SAFE_RANGE, U_PST, U_CPY, U_CUT, U_UND };
