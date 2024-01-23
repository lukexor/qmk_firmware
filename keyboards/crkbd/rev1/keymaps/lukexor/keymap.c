/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define XXX KC_NO   // No-op key
#define UUU KC_NO   // Unused key
#define ___ KC_TRNS // Transparent key

#define _BASE 0
#define _GAME 1
#define _SYM 2
#define _NAV 3
#define _NUM 4
#define _MOUSE 5
#define _MEDIA 6
#define _FN 7

// Sticky key
#define SK(mod) OSM(mod)

// Layer Toggles
#define _TB TO(_BASE)
#define _TG TO(_GAME)

// Home-row Mods
#define HLA(key) LALT_T(key)
#define HLG(key) LGUI_T(key)
#define HRG(key) RGUI_T(key)
#define HLC(key) LCTL_T(key)
#define HRC(key) RCTL_T(key)
#define HLS(key) LSFT_T(key)
#define HRS(key) RSFT_T(key)

// Mod-taps
#define MEHT(key) MEH_T(key)
#define HYPT(key) HYPR_T(key)

// Layer Taps
#define _M(key) LT(_MEDIA, key)
#define _NV(key) LT(_NAV, key)
#define _MS(key) LT(_MOUSE, key)
#define _S(key) LT(_SYM, key)
#define _N(key) LT(_NUM, key)
#define _F(key) LT(_FN, key)

/* clang-format off */
/* Layer template
// ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
// │      │             │             │             │             │             │  │            │             │             │             │             │      │
     UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             XXX,         XXX,          XXX,          XXX,          XXX,          UUU,
// ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
// │      │             │             │             │             │             │  │            │             │             │             │             │      │
     UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             XXX,         XXX,          XXX,          XXX,          XXX,          UUU,
// ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
// │      │             │             │             │             │             │  │            │             │             │             │             │      │
     UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             XXX,         XXX,          XXX,          XXX,          XXX,          UUU,
// └──────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┘
//                                    │             │             │             │  │            │             │             │
                                        XXX,          XXX,          XXX,             XXX,         XXX,          XXX
//                                    └─────────────┴─────────────┴─────────────┘  └────────────┴─────────────┴─────────────┘
*/
/* clang-format on */

static void oled_render_layer_state(void) {
    if (is_caps_word_on()) {
        oled_write_ln_P(PSTR("Caps Word"), false);
        return;
    }
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        default:
            break;
    }
}

void oled_render_logo(void) {
    // clang-format off
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    // clang-format on
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    } else {
        oled_render_logo();
    }
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            rgblight_sethsv_noeeprom(HSV_TEAL);
            break;
        case _GAME:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _SYM:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _NAV:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _MOUSE:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        case _MEDIA:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        case _FN:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
    }
    return state;
}

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │ Q           │ W           │ F           │ P           │ B           │  │ J           │ L           │ U           │ Y           │ ' "         │      │
             UUU,   KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,            KC_J,         KC_L,         KC_U,         KC_Y,         KC_QUOT,      UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ A 󰘳         │ R 󰘵         │ S 󰘴         │ T 󰘶         │ G           │  │ M           │ N 󰘶         │ E 󰘴         │ I 󰘵         │ O 󰘳         │      │
             UUU,   HLG(KC_A),    HLA(KC_R),    HLC(KC_S),    HLS(KC_T),    KC_G,            KC_M,         HRS(KC_N),    HRC(KC_E),    HLA(KC_I),    HRG(KC_O),    UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ Z 󰘴󰘶󰘵       │ X 󰘴󰘶󰘵󰘳      │ C           │ D           │ V           │  │ K           │ H           │ , <         │ . > 󰘴󰘶󰘵󰘳    │ / ? 󰘴󰘶󰘵     │      │
             UUU,   MEHT(KC_Z),   HYPT(KC_X),   KC_C,         KC_D,         KC_V,            KC_K,         KC_H,         KC_COMM,      HYPT(KC_DOT), MEHT(KC_SLSH), UUU,
        // └──────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │ Esc _SYM    │ 󱁐 _NAV      │  _NUM      │  │ ⏎ _MOUSE    │ 󰭜 _MEDIA    │ 󰹿 _FN       │
                                                _S(KC_ESC),   _NV(KC_SPC),  _N(KC_TAB),      _MS(KC_ENT),  _M(KC_BSPC),  _F(KC_DEL)
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_GAME] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │ Q           │ W           │ E           │ R           │ T           │  │ Y           │ U           │ I           │ O           │ P           │      │
             UUU,   KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,            KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ A           │ S           │ D           │ F           │ G           │  │ H           │ J           │ K           │ L           │ ' "         │      │
             UUU,   KC_A,         KC_S,         KC_D,         KC_F,         KC_G,            KC_H,         KC_J,         KC_K,         KC_L,         KC_QUOT,      UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ Z           │ X           │ C           │ V           │ B           │  │ N           │ M           │ , <         │ . >         │ / ?         │      │
             UUU,   KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,            KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      UUU,
        // └──────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │ Esc _SYM    │ 󱁐 _NAV      │  _NUM      │  │ ⏎ _MOUSE    │ 󰭜 _MEDIA    │ 󰹿 _FN       │
                                                ___,          ___,          ___,             ___,          ___,          ___
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_SYM] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │             │             │             │             │             │  │ {           │ &           │ *           │ (           │ }           │      │
             UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             KC_LCBR,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RCBR,      UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ 󰘳           │ 󰘵           │ 󰘴           │ 󰘶           │ AltGr       │  │ :           │ $           │ %           │ ^           │ +           │      │
             UUU,   SK(MOD_LGUI), SK(MOD_LALT), SK(MOD_LCTL), SK(MOD_LSFT), SK(MOD_RALT),    KC_COLN,      KC_DLR,       KC_PERC,      KC_CIRC,      KC_PLUS,      UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │             │             │             │             │             │  │ ~           │ !           │ @           │ #           │ |           │      │
             UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             KC_TILD,      KC_EXLM,      KC_AT,        KC_HASH,      KC_PIPE,      UUU,
        // └──────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │ *           │             │             │  │ _           │ (           │ )           │
                                                XXX,          XXX,          XXX,             KC_UNDS,      KC_LPRN,      KC_RPRN
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_NAV] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │             │             │             │             │             │  │             │ {           │ }           │ (           │ )           │      │
             UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             XXX,          KC_LCBR,      KC_RCBR,      KC_LPRN,      KC_RPRN,      UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ 󰘳           │ 󰘵           │ 󰘴           │ 󰘶           │ AltGr       │  │ Caps Toggle │ ←           │ ↓           │ ↑           │ →           │      │
             UUU,   SK(MOD_LGUI), SK(MOD_LALT), SK(MOD_LCTL), SK(MOD_LSFT), SK(MOD_RALT),    CW_TOGG,      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,     UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ ⇱           │ ⇟           │ ⇞           │ ⇲           │ 󰘳           │  │ Insert      │ [           │ ]           │ <           │ >           │      │
             UUU,   KC_HOME,      KC_PGDN,      KC_PGUP,      KC_END,       KC_LGUI,         KC_INS,       KC_LBRC,      KC_RBRC,      KC_LABK,      KC_RABK,      UUU,
        // └──────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │             │ *           │             │  │ ⏎           │ 󰹿           │ ⏎           │
                                                XXX,          XXX,          XXX,             KC_ENT,       KC_BSPC,      KC_DEL
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_NUM] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │             │             │             │             │             │  │ [ {         │ 7 &         │ 8 *         │ 9 (         │ ] }         │      │
             UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             KC_LBRC,      KC_7,         KC_8,         KC_9,         KC_RBRC,      UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ 󰘳           │ 󰘵           │ 󰘴           │ 󰘶           │ AltGr       │  │ ; :         │ 4 $         │ 5 %         │ 6 ^         │ = +         │      │
             UUU,   SK(MOD_LGUI), SK(MOD_LALT), SK(MOD_LCTL), SK(MOD_LSFT), SK(MOD_RALT),    KC_SCLN,      KC_4,         KC_5,         KC_6,         KC_EQL,       UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │             │             │             │             │             │  │ ` ~         │ 1 !         │ 2 @         │ 3 #         │ \ |         │      │
             UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             KC_GRV,       KC_1,         KC_2,         KC_3,         KC_BSLS,      UUU,
        // └────────────────────┼─────────────┼─────────────┼─────────────┴─────────────┤  ├───────────────────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │             │             │ *           │  │ - _         │ 0 )         │ . >         │
                                                XXX,          XXX,          XXX,             KC_MINS,      KC_0,         KC_DOT
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_MOUSE] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │             │             │             │             │             │  │             │             │             │             │             │      │
             UUU,   XXX,          XXX,          XXX,          XXX,          XXX,             XXX,          XXX,          XXX,          XXX,          XXX,          UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ ←           │ ↓           │ ↑           │ →           │             │  │ AltGr       │ 󰘶           │ 󰘴           │ 󰘵           │ 󰘳           │      │
             UUU,   KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,      XXX,             SK(MOD_RALT), SK(MOD_RSFT), SK(MOD_RCTL), SK(MOD_LALT), SK(MOD_LGUI), UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ ⇐           │ ⇓           │ ⇑           │ ⇒           │             │  │             │             │             │             │ 󰘳           │      │
             UUU,   KC_WH_L,      KC_WH_D,      KC_WH_U,      KC_WH_R,      XXX,             XXX,          XXX,          XXX,          XXX,          KC_LGUI,      UUU,
        // └──────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │ Middle Btn  │ Left Btn    │ Right Btn   │  │ *           │             │             │
                                                KC_BTN3,      KC_BTN1,      KC_BTN2,         XXX,          XXX,          XXX
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_MEDIA] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │ -Mode       │ +Mode       │ -Saturation │ +Saturation │             │  │ Sleep       │             │             │ Mission Ctl │ Launchpad   │      │
             UUU,   RGB_RMOD,     RGB_MOD,      RGB_SAD,      RGB_SAI,      XXX,             KC_SLEP,      XXX,          XXX,          KC_MCTL,      KC_LPAD,      UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ RGB Toggle  │ 󰒮           │            │            │ 󰒭           │  │ AltGr       │ 󰘶           │ 󰘴           │ 󰘵           │ 󰘳           │      │
             UUU,   RGB_TOG,      KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,         SK(MOD_RALT), SK(MOD_RSFT), SK(MOD_RCTL), SK(MOD_LALT), SK(MOD_LGUI), UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ -Brightness │ +Brightness │ 🔅          │ 🔆          │             │  │             │             │             │ -Hue        │ +Hue        │      │
             UUU,   RGB_VAD,      RGB_VAI,      KC_BRID,      KC_BRIU,      XXX,             XXX,          XXX,          XXX,          RGB_HUD,      RGB_HUI,      UUU,
        // └──────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │            │ 󰐎           │            │  │             │ *           │             │
                                                KC_MUTE,      KC_MPLY,      KC_MSTP,         XXX,          XXX,          XXX
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_FN] = LAYOUT_split_3x6_3(
        // ┌──────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬──────┐
        // │      │ F12         │ F7          │ F8          │ F9          │ _BASE       │  │             │             │             │             │             │      │
             UUU,   KC_F12,       KC_F7,        KC_F8,        KC_F9,        _TB,             XXX,          XXX,          XXX,          XXX,          XXX,          UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ F11         │ F4          │ F5          │ F6          │ _GAME       │  │ AltGr       │ 󰘶           │ 󰘴           │ 󰘵           │ 󰘳           │      │
             UUU,   KC_F11,       KC_F4,        KC_F5,        KC_F6,        _TG,             SK(MOD_RALT), SK(MOD_RSFT), SK(MOD_RCTL), SK(MOD_LALT), SK(MOD_LGUI), UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼──────┤
        // │      │ F10         │ F1          │ F2          │ F3          │             │  │             │             │             │             │             │      │
             UUU,   KC_F10,       KC_F1,        KC_F2,        KC_F3,        XXX,             XXX,          XXX,          XXX,          UUU,          UUU,          UUU,
        // ├──────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴──────┘
        //                                    │             │ 󱁐           │            │  │             │             │ *           │
                                                XXX,          KC_SPC,       KC_TAB,          XXX,          XXX,          XXX
        //                                    └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),
};
/* clang-format on */
