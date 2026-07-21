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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
        KC_MEH,      KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,           KC_J,        KC_L,        KC_U,        KC_Y,        KC_QUOT,     KC_HYPR,
        KC_LGUI,     GH(KC_A),    AH(KC_R),    CH(KC_S),    SH(KC_T),    MHH(KC_G),      MHH(KC_M),   SH(KC_N),    CH(KC_E),    AH(KC_I),    GH(KC_O),    KC_LSFT,
        KC_LCTL,     HYH(KC_Z),   KC_X,        KC_C,        KC_D,        KC_V,           KC_K,        KC_H,        KC_COMM,     KC_DOT,      HYH(KC_SLSH),KC_LALT,
        UUU,         UUU,         UUU,         AT(KC_ESC),  ST(KC_SPC),  LOT(KC_TAB),    RST(KC_ENT), GT(KC_BSPC), CT(KC_SCLN), UUU,         UUU,         UUU
    ),
    [_GAME] = LAYOUT_planck_grid(
        ___,         KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,           KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        ___,
        ___,         KC_A,        KC_S,        KC_D,        KC_F,        KC_G,           KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     ___,
        ___,         KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,           KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     ___,
        UUU,         UUU,         UUU,         ___,         ___,         ___,            ___,         ___,         ___,         UUU,         UUU,         UUU
    ),
    [_LO] = LAYOUT_planck_grid(
        ___,         XXX,         XXX,         XXX,         XXX,         CW_TOGG,        KC_NUM,      KC_PSCR,     KC_SCRL,     XXX,         XXX,         ___,
        ___,         OS_LGUI,     OS_LALT,     OS_LCTL,     OS_LSFT,     OS_MEH,         KC_INS,      KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,    ___,
        ___,         OS_HYPR,     XXX,         XXX,         XXX,         XXX,            KC_DEL,      KC_HOME,     KC_PGDN,     KC_PGUP,     KC_END,      ___,
        UUU,         UUU,         UUU,         ___,         ___,         ___,            ___,         ___,         ___,         UUU,         UUU,         UUU
    ),
    [_RS] = LAYOUT_planck_grid(
        ___,         KC_GRV,      KC_LABK,     KC_LCBR,     KC_RCBR,     KC_AMPR,        KC_ASTR,     KC_7,        KC_8,        KC_9,        KC_BSLS,     ___,
        ___,         KC_EXLM,     KC_RABK,     KC_LPRN,     KC_RPRN,     KC_EQL,         KC_MINS,     KC_4,        KC_5,        KC_6,        KC_DOT,      ___,
        ___,         KC_HASH,     KC_COLN,     KC_LBRC,     KC_RBRC,     KC_UNDS,        KC_0,        KC_1,        KC_2,        KC_3,        KC_PIPE,     ___,
        UUU,         UUU,         UUU,         ___,         ___,         ___,            ___,         ___,         ___,         UUU,         UUU,         UUU
    ),
    [_ADJ] = LAYOUT_planck_grid(
        ___,         TG(_GAME),   KC_MPRV,     KC_MPLY,     KC_MSTP,     KC_MNXT,        KC_F12,      KC_F7,       KC_F8,       KC_F9,       XXX,         ___,
        ___,         XXX,         KC_MUTE,     KC_VOLD,     KC_VOLU,     KC_APP,         KC_F11,      KC_F4,       KC_F5,       KC_F6,       XXX,         ___,
        ___,         XXX,         XXX,         KC_BRID,     KC_BRIU,     XXX,            KC_F10,      KC_F1,       KC_F2,       KC_F3,       XXX,         ___,
        UUU,         UUU,         UUU,         ___,         ___,         ___,            ___,         ___,         ___,         UUU,         UUU,         UUU
    ),
};
/* clang-format on */
