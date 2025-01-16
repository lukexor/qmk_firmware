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

/* clang-format off */
/* Layer template
// ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
// │             │             │             │             │             │             │  │             │             │             │             │             │             │
     XXX,          XXX,          XXX,          XXX,          XXX,          XXX,             XXX,          XXX,          XXX,          XXX,          XXX,          XXX,
// ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
// │             │             │             │             │             │             │  │             │             │             │             │             │             │
     XXX,          XXX,          XXX,          XXX,          XXX,          XXX,             XXX,          XXX,          XXX,          XXX,          XXX,          XXX,
// ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
// │             │             │             │             │             │             │  │             │             │             │             │             │             │
     XXX,          XXX,          XXX,          XXX,          XXX,          XXX,             XXX,          XXX,          XXX,          XXX,          XXX,          XXX,
// └─────────────────────────────────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┘
//                                           │             │             │             │  │             │             │             │
                                               XXX,          XXX,          XXX,             XXX,          XXX,          XXX
//                                           └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
*/
/* clang-format on */

static void oled_render_layer_state(void) {
    if (is_caps_word_on()) {
        oled_write_ln_P(PSTR("Caps Word"), false);
        return;
    }
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COL:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _EXT:
            oled_write_ln_P(PSTR("Extend"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Number"), false);
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
    state = update_tri_layer_state(state, _EXT, _NUM, _FN);

    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    switch (get_highest_layer(state)) {
        case _COL:
            rgblight_mode_noeeprom(RGBLIGHT_DEFAULT_MODE);
            break;
        case _EXT:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(HSV_TEAL);
            break;
        case _FN:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
    }
    return state;
}

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COL] = LAYOUT_split_3x6_3(
        // ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
        // │ Esc         │ Q           │ W           │ F           │ P           │ B           │  │ J           │ L           │ U           │ Y           │ ' "         │ 󰹿           │
             KC_ESC,       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,            KC_J,         KC_L,         KC_U,         KC_Y,         KC_QUOT,      KC_DEL,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │ 󰘵           │ A           │ R           │ S           │ T           │ G           │  │ M           │ N           │ E           │ I           │ O           │ ; :         │
             KC_LALT,      KC_A,         KC_R,         KC_S,         KC_T,         KC_G,            KC_M,         KC_N,         KC_E,         KC_I,         KC_O,         KC_SCLN,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │ 󰘴           │ Z           │ X           │ C           │ D           │ V           │  │ K           │ H           │ , <         │ . >         │ / ?         │            │
             KC_LCTL,      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,            KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_LGUI,
        // └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────┘
        //                                           │ _EXT        │ 󱁐           │ 󰘶           │  │ ⏎           │ 󰭜           │ _NUM        │
                                                       MO(_EXT),     KC_SPC,       KC_LSFT,         KC_ENT,       KC_BSPC,      MO(_NUM)
        //                                           └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_NUM] = LAYOUT_split_3x6_3(
        // ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
        // │             │ Num Lock    │ 7 &         │ 8 *         │ 9 (         │ = +         │  │ (           │ ` ~         │ [ {         │ ] }         │ ' "         │             │
             ___,          KC_NUM,       KC_7,         KC_8,         KC_9,         KC_EQL,          KC_LPRN,      KC_GRV,       KC_LBRC,      KC_RBRC,      KC_QUOT,      ___,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │             │             │ 4 $         │ 5 %         │ 6 ^         │ - _         │  │ 󰘶           │ 󰘴           │ 󰘵           │            │ AltGr       │             │
             ___,                        KC_4,         KC_5,         KC_6,         KC_MINS,         KC_LSFT,      OLCTL,        OLALT,        OLGUI,        ORALT,        ___,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │             │ 0 )         │ 1 !         │ 2 @         │ 3 #         │ \ |         │  │ )           │ ; :         │ , <         │  . >        │ / ?         │             │
             ___,          KC_0,         KC_1,         KC_2,         KC_3,         KC_BSLS,         KC_RPRN,      KC_SCLN,      KC_COMM,      KC_DOT,       KC_SLSH,      ___,
        // └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────┘
        //                                           │             │ 󱁐           │ 󰘶           │  │             │             │ *           │
                                                       ___,          KC_SPC,       KC_LSFT,         XXX,          XXX,          ___
        //                                           └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_EXT] = LAYOUT_split_3x6_3(
        // ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
        // │             │             │            │             │ 󰘴󰘶C         │ 󰘴󰘶V         │  │ ⇧           │ ⇱           │            │             │             │             │
             ___,          XXX,          KC_LGUI,      XXX,          LCS(KC_C),    LCS(KC_V),       KC_PGUP,      KC_HOME,      KC_TAB,       XXX,          XXX,          ___,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │             │ AltGr       │            │ 󰘵           │ 󰘴           │ 󰘶           │  │ Esc         │ ←           │ ↓           │ ↑           │ →           │             │
             ___,          ORALT,        OLGUI,        OLALT,        OLCTL,        OLSFT,           KC_ESC,       KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,     ___,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │             │ 󰘴Z          │ 󰘴X          │ 󰘴C          │ ^D          │ 󰘴V          │  │ ⇩           │ ⇲           │ Caps Toggle │ Insert      │ Prt Scr     │             │
             ___,          LCTL(KC_Z),   LCTL(KC_X),   LCTL(KC_C),   LCTL(KC_D),   LCTL(KC_V),      KC_PGDN,      KC_END,       CW_TOGG,      KC_INS,       KC_PSCR,      ___,
        // └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────┘
        //                                           │ *           │             │             │  │ 󰘶           │ 󰹿           │             │
                                                       ___,          XXX,          XXX,             KC_LSFT,      KC_DEL,       ___
        //                                           └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),

    [_FN] = LAYOUT_split_3x6_3(
        // ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐  ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
        // │             │ Sleep       │ F7          │ F8          │ F9          │ F12         │  │ 🔆          │ 󰒮           │ 󰐎           │ 󰒭           │            │             │
             ___,          KC_SLEP,      KC_F7,        KC_F8,        KC_F9,        KC_F12,          KC_BRIU,      KC_MPRV,      KC_MPLY,      KC_MNXT,      KC_MSTP,      ___,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │             │             │ F4          │ F5          │ F6          │ F11         │  │ 󰘶           │ 󰘴           │ 󰘵           │            │ ALTGR       │             │
             ___,          XXX,          KC_F4,        KC_F5,        KC_F6,        KC_F11,          OLSFT,        OLCTL,        OLALT,        OLGUI,        ORALT,        ___,
        // ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        // │             │             │ F1          │ F2          │ F3          │ F10         │  │ 🔅          │            │            │            │             │             │
             ___,          XXX,          KC_F1,        KC_F2,        KC_F3,        KC_F10,          KC_BRID,      KC_VOLD,      KC_MUTE,      KC_VOLU,      XXX,          ___,
        // └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤  ├─────────────┼─────────────┼─────────────┼─────────────┴─────────────┴─────────────┘
        //                                           │ *           │             │             │  │             │             │ *           │
                                                       ___,          XXX,          XXX,             XXX,          XXX,          ___
        //                                           └─────────────┴─────────────┴─────────────┘  └─────────────┴─────────────┴─────────────┘
    ),
};
/* clang-format on */
