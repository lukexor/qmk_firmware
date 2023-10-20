/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FN,
};

#define GT GUI_T
#define AT ALT_T
#define CT CTL_T
#define ST SFT_T
#define HT HYPR_T
#define ET MEH_T

// TODO: Add application shortcuts for MEH and HYPR keys
// TODO: Solve ctrl/gui mismatch between win/linux and mac
#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     GT(KC_A),AT(KC_R),CT(KC_S),ST(KC_T), HT(KC_G),                     ET(KC_M), ST(KC_N),CT(KC_E),AT(KC_I),GT(KC_O),
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      LT(_MEDIA,KC_ESC),LT(_NAV,KC_SPC), LT(_MOUSE,KC_TAB),   LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FN,KC_RSFT)
                             //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, XXXXXXX,    KC_ENT, KC_BSPC, KC_DEL
                            //`--------------------------'  `--------------------------'
    ),

    [_MOUSE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     XXXXXXX,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN2, KC_BTN1, KC_BTN3
                            //`--------------------------'  `--------------------------'
    ),

    [_MEDIA] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE
                            //`--------------------------'  `--------------------------'
    ),

    [_NUM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                      XXXXXXX,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_DOT, KC_0, KC_MINS,        XXXXXXX, XXXXXXX, XXXXXXX
                            //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                     XXXXXXX,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, XXXXXXX, XXXXXXX
                            //`--------------------------'  `--------------------------'
    ),

    [_FN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                     XXXXXXX,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_APP, KC_SPC, KC_TAB,       XXXXXXX, XXXXXXX, XXXXXXX
                            //`--------------------------'  `--------------------------'
    ),
};

const uint16_t PROGMEM vim_esc[] = { KC_J, KC_K, COMBO_END };
combo_t key_combos[1] = {
    COMBO(vim_esc, KC_ESC),
};

const key_override_t del_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);
const key_override_t** key_overrides = (const key_override_t*[]){
    &del_override,
    &capsword_key_override,
    NULL
};
