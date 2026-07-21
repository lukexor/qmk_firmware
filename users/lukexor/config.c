#include QMK_KEYBOARD_H

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    switch (get_highest_layer(state)) {
        case _BS:
            rgblight_mode_noeeprom(RGBLIGHT_DEFAULT_MODE);
            break;
        case _BN:
            rgblight_sethsv_noeeprom(HSV_ORANGE);
            break;
        case _GM:
            rgblight_sethsv_noeeprom(HSV_TEAL);
            break;
        case _MD:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case _NV:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case _MS:
            rgblight_sethsv_noeeprom(HSV_YELLOW);
            break;
        case _SY:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _NM:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _FN:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        default:
            break;
    }
    return state;
}
