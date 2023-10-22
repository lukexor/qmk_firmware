/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "lukexor.h"

enum layers {
    _BASE,
    _GAME,
    _COL,
    _NAV,
    // _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,          DF(_GAME),
        KC_ESC,  GUI_A,   ALT_S,   CTL_D,   SFT_F,   MEH_G,   MEH_H,   SFT_J,   CTL_K,   ALT_L,   GUI_SCLN,KC_QUOT,           KC_ENT,           DF(_COL),
        KC_LSFT,          HYPR_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  HYPR_SLSH,         KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT, KC_LGUI,                            _NAV_SPC,                         _SYM_ENT, _NUM_BSPC, _FN_DEL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_GAME] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          DF(_BASE),
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,           _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______, _______, _______, _______
    ),


    [_COL] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC,  KC_RBRC, KC_BSLS,          DF(_BASE),
        KC_BSPC, GUI_A,   ALT_R,   CTL_S,   SFT_T_,  MEH_G,   MEH_M,   SFT_N,   CTL_E,   ALT_I,   GUI_O,   KC_QUOT,           KC_ENT,           MO(_MEDIA),
        KC_LSFT,          HYPR_Z,  KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  HYPR_SLSH,         KC_RSFT, KC_UP,
        _MEDIA_ESC, _NAV_SPC, KC_TAB,                         KC_SPC,                           _SYM_ENT, _NUM_BSPC, _FN_DEL, KC_LEFT, KC_DOWN, KC_RGHT
    ),


    [_NAV] = LAYOUT_ansi_67(
        KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_BSPC,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   XXXXXXX,  XXXXXXX, XXXXXXX,          KC_DEL,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX,           KC_ENT,           KC_HOME,
        KC_LSFT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,            KC_RSFT, XXXXXXX,
        KC_LCTL, KC_LOPT, KC_LGUI,                            XXXXXXX,                            KC_ENT,  KC_BSPC,  KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // [_MOUSE] = LAYOUT_ansi_67(
    //     KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_BSPC,          XXXXXXX,
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   XXXXXXX,  XXXXXXX, XXXXXXX,          KC_DEL,
    //     XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,           KC_ENT,           KC_HOME,
    //     KC_LSFT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,           KC_RSFT, XXXXXXX,
    //     KC_LCTL, KC_LOPT, KC_LGUI,                            XXXXXXX,                            KC_BTN2, KC_BTN1, KC_BTN3,  XXXXXXX, XXXXXXX, XXXXXXX
    // ),

    [_MEDIA] = LAYOUT_ansi_67(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,           XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            KC_MSTP, KC_MPLY, KC_MUTE,  XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_ansi_67(
        KC_ESC, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, XXXXXXX, DT_PRNT, DT_DOWN, DT_UP,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,           KC_ENT,           XXXXXXX,
        KC_LSFT,          KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_RSFT, XXXXXXX,
        KC_DOT,  KC_0,    KC_MINS,                            XXXXXXX,                            XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT_ansi_67(
        KC_ESC, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,           KC_ENT,           XXXXXXX,
        KC_LSFT,          KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_RSFT, XXXXXXX,
        KC_LPRN, KC_RPRN, KC_UNDS,                            XXXXXXX,                            XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_FN] = LAYOUT_ansi_67(
        KC_ESC, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,           KC_ENT,           XXXXXXX,
        KC_LSFT,          KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_RSFT, XXXXXXX,
        KC_APP,  KC_SPC,  KC_TAB,                             XXXXXXX,                            XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GAME]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_COL]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NAV]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    // [_MOUSE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MEDIA] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_NUM]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYM]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
// clang-format on

const key_override_t del_override       = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, LSFT(KC_GRV));
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV);

// clang-format off
const key_override_t** key_overrides = (const key_override_t*[]){
    &del_override,
    &tilde_esc_override,
    &grave_esc_override,
    NULL
};
// clang-format on
