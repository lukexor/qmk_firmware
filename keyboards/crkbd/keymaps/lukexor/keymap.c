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

static void oled_render_layer_state(void) {
    if (is_caps_word_on()) {
        oled_write_ln_P(PSTR("Caps Word"), false);
        return;
    }
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BS:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _BN:
            oled_write_ln_P(PSTR("Base (No Mods)"), false);
            break;
        case _GM:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _MD:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _NV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case _MS:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _SY:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NM:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("Functions"), false);
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

void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
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

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if 1
    [_BS] = LAYOUT_split_3x6_3(
        KC_MEH,      KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,           KC_J,        KC_L,        KC_U,        KC_Y,        KC_QUOT,     KC_HYPR,
        KC_LGUI,     GH(KC_A),    AH(KC_R),    CH(KC_S),    SH(KC_T),    MHH(KC_G),      MHH(KC_M),   SH(KC_N),    CH(KC_E),    AH(KC_I),    GH(KC_O),    KC_LSFT,
        KC_LCTL,     HYH(KC_Z),   AG(KC_X),    KC_C,        KC_D,        KC_V,           KC_K,        KC_H,        KC_COMM,     AG(KC_DOT),  HYH(KC_SLSH),KC_LALT,
                                               MDT(KC_ESC), NVT(KC_SPC), MST(KC_TAB),    SYT(KC_ENT), NMT(KC_BSPC),FNT(KC_SCLN)
    ),
    [_BN] = LAYOUT_split_3x6_3(
        _______,     KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,           KC_J,        KC_L,        KC_U,        KC_Y,        KC_QUOT,     TG(_BN),
        _______,     KC_A,        KC_R,        KC_S,        KC_T,        KC_G,           KC_M,        KC_N,        KC_E,        KC_I,        KC_O,        _______,
        _______,     KC_Z,        KC_X,        KC_C,        KC_D,        KC_V,           KC_K,        KC_H,        KC_COMM,     KC_DOT,      KC_SLSH,     _______,
                                               _______,     _______,     _______,        _______,     _______,     _______
    ),
    [_GM] = LAYOUT_split_3x6_3(
        _______,     KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,           KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        TG(_GM),
        _______,     KC_A,        KC_S,        KC_D,        KC_F,        KC_G,           KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     _______,
        _______,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,           KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     _______,
                                               KC_ESC,      KC_SPC,      KC_TAB,         KC_ENT,      KC_BSPC,     KC_DEL
    ),
    [_MD] = LAYOUT_split_3x6_3(
        _______,     XXXXXXX,     TG(_BN),     TG(_GM),     XXXXXXX,     XXXXXXX,        UG_TOGG,     UG_NEXT,     UG_HUEU,     UG_SATU,     UG_VALU,     _______,
        _______,     KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     KC_MEH,         XXXXXXX,     KC_MPRV,     KC_VOLD,     KC_VOLU,     KC_MNXT,     _______,
        _______,     KC_HYPR,     KC_ALGR,     QK_LLCK,     XXXXXXX,     XXXXXXX,        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,
                                               _______,     _______,     _______,        KC_MSTP,     KC_MPLY,     KC_MUTE
    ),
    [_NV] = LAYOUT_split_3x6_3(
        _______,     XXXXXXX,     TG(_BN),     TG(_GM),     XXXXXXX,     XXXXXXX,        U_RDO,       U_PST,       U_CPY,       U_CUT,       U_UND,       _______,
        _______,     KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     KC_MEH,         CW_TOGG,     KC_LEFT,     KC_DOWN,     KC_UP,       KC_RGHT,     _______,
        _______,     KC_HYPR,     KC_ALGR,     QK_LLCK,     XXXXXXX,     XXXXXXX,        KC_INS,      KC_HOME,     KC_PGDN,     KC_PGUP,     KC_END,      _______,
                                               _______,     _______,     _______,        KC_ENT,      KC_BSPC,     KC_SCLN
    ),
    [_MS] = LAYOUT_split_3x6_3(
        _______,     XXXXXXX,     TG(_BN),     TG(_GM),     XXXXXXX,     XXXXXXX,        U_RDO,       U_PST,       U_CPY,       U_CUT,       U_UND,       _______,
        _______,     KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     XXXXXXX,        XXXXXXX,     MS_LEFT,     MS_DOWN,     MS_UP,       MS_RGHT,     _______,
        _______,     XXXXXXX,     KC_ALGR,     QK_LLCK,     XXXXXXX,     XXXXXXX,        XXXXXXX,     MS_WHLL,     MS_WHLD,     MS_WHLU,     MS_WHLR,     _______,
                                               _______,     _______,     _______,        MS_BTN2,     MS_BTN1,     MS_BTN3
    ),
    [_SY] = LAYOUT_split_3x6_3(
        _______,     KC_LCBR,     KC_AMPR,     KC_ASTR,     KC_LPRN,     KC_RCBR,        XXXXXXX,     XXXXXXX,     TG(_GM),     TG(_BN),     XXXXXXX,     _______,
        _______,     KC_COLN,     KC_DLR,      KC_PERC,     KC_CIRC,     KC_PLUS,        KC_MEH,      KC_LSFT,     KC_LCTL,     KC_LALT,     KC_LGUI,     _______,
        _______,     KC_TILD,     KC_EXLM,     KC_AT,       KC_HASH,     KC_PIPE,        XXXXXXX,     XXXXXXX,     QK_LLCK,     KC_ALGR,     KC_HYPR,     _______,
                                               KC_LPRN,     KC_RPRN,     KC_UNDS,        _______,     _______,     _______
    ),
    [_NM] = LAYOUT_split_3x6_3(
        _______,     KC_LBRC,     KC_7,        KC_8,        KC_9,        KC_RBRC,        XXXXXXX,     XXXXXXX,     TG(_GM),     TG(_BN),     XXXXXXX,     _______,
        _______,     KC_SCLN,     KC_4,        KC_5,        KC_6,        KC_LGUI,        KC_MEH,      KC_LSFT,     KC_LCTL,     KC_LALT,     KC_LGUI,     _______,
        _______,     KC_GRV,      KC_1,        KC_2,        KC_3,        KC_BSLS,        XXXXXXX,     XXXXXXX,     QK_LLCK,     KC_ALGR,     KC_HYPR,     _______,
                                               KC_DOT,      KC_0,        KC_MINS,        _______,     _______,     _______
    ),
    [_FN] = LAYOUT_split_3x6_3(
        _______,     KC_F12,      KC_F7,       KC_F8,       KC_F9,       KC_PSCR,        XXXXXXX,     XXXXXXX,     TG(_GM),     TG(_BN),     XXXXXXX,     _______,
        _______,     KC_F11,      KC_F4,       KC_F5,       KC_F6,       KC_SCRL,        KC_MEH,      KC_LSFT,     KC_LCTL,     KC_LALT,     KC_LGUI,     _______,
        _______,     KC_F10,      KC_F1,       KC_F2,       KC_F3,       KC_PAUS,        XXXXXXX,     XXXXXXX,     QK_LLCK,     KC_ALGR,     KC_HYPR,     _______,
                                               KC_APP,      KC_SPC,      KC_TAB,         _______,     _______,     _______
    ),
#else
    [_BASE] = LAYOUT_split_3x6_3(
        KC_MEH,      KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,           KC_J,        KC_L,        KC_U,        KC_Y,        KC_QUOT,     KC_HYPR,
        KC_LGUI,     GH(KC_A),    AH(KC_R),    CH(KC_S),    SH(KC_T),    MHH(KC_G),      MHH(KC_M),   SH(KC_N),    CH(KC_E),    AH(KC_I),    GH(KC_O),    KC_LSFT,
        KC_LCTL,     HYH(KC_Z),   KC_X,        KC_C,        KC_D,        KC_V,           KC_K,        KC_H,        KC_COMM,     KC_DOT,      HYH(KC_SLSH),KC_LALT,
                                               AT(KC_ESC),  ST(KC_SPC),  LOT(KC_TAB),    RST(KC_ENT), GT(KC_BSPC), CT(KC_SCLN)
    ),
    [_GAME] = LAYOUT_split_3x6_3(
        KC_LALT,     KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,           KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        _______,
        KC_LSFT,     KC_A,        KC_S,        KC_D,        KC_F,        KC_G,           KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     _______,
        _______,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,           KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     _______,
                                               KC_ESC,      KC_SPC,      _______,        _______,     KC_BSPC,     KC_SCLN
    ),
    [_LO] = LAYOUT_split_3x6_3(
        _______,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     CW_TOGG,        KC_NUM,      KC_PSCR,     KC_SCRL,     XXXXXXX,     XXXXXXX,     _______,
        _______,     OS_LGUI,     OS_LALT,     OS_LCTL,     OS_LSFT,     OS_MEH,         KC_INS,      KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,    _______,
        _______,     OS_HYPR,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,        KC_DEL,      KC_HOME,     KC_PGDN,     KC_PGUP,     KC_END,      _______,
                                               _______,     _______,     _______,        _______,     _______,     _______
    ),
    [_RS] = LAYOUT_split_3x6_3(
        _______,     KC_GRV,      KC_LABK,     KC_LCBR,     KC_RCBR,     KC_AMPR,        KC_ASTR,     KC_7,        KC_8,        KC_9,        KC_BSLS,     _______,
        _______,     KC_EXLM,     KC_RABK,     KC_LPRN,     KC_RPRN,     KC_EQL,         KC_MINS,     KC_4,        KC_5,        KC_6,        KC_DOT,      _______,
        _______,     KC_HASH,     KC_COLN,     KC_LBRC,     KC_RBRC,     KC_UNDS,        KC_0,        KC_1,        KC_2,        KC_3,        KC_PIPE,     _______,
                                               _______,     _______,     _______,        _______,     _______,     _______
    ),
    [_ADJ] = LAYOUT_split_3x6_3(
        _______,     TG(_GAME),   KC_MPRV,     KC_MPLY,     KC_MSTP,     KC_MNXT,        KC_F12,      KC_F7,       KC_F8,       KC_F9,       XXXXXXX,     _______,
        _______,     XXXXXXX,     KC_MUTE,     KC_VOLD,     KC_VOLU,     KC_APP,         KC_F11,      KC_F4,       KC_F5,       KC_F6,       XXXXXXX,     _______,
        _______,     XXXXXXX,     XXXXXXX,     KC_BRID,     KC_BRIU,     XXXXXXX,        KC_F10,      KC_F1,       KC_F2,       KC_F3,       XXXXXXX,     _______,
                                               _______,     _______,     _______,        _______,     _______,     _______
    ),
#endif
};
/* clang-format on */
