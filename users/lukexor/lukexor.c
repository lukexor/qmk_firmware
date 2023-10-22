#include "lukexor.h"
#include "os_detection.h"

bool macos_key(uint8_t mods, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_mods(mods);
        register_code(keycode);
    } else {
        clear_mods();
        unregister_code(keycode);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    os_variant_t os       = detected_host_os();
    bool         is_macos = os == OS_MACOS || os == OS_IOS;

    if (is_macos) {
        switch (keycode) {
            case U_RDO:
                return macos_key(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT), KC_Z, record);
            case U_PST:
                return macos_key(MOD_BIT(KC_LGUI), KC_V, record);
            case U_CPY:
                return macos_key(MOD_BIT(KC_LGUI), KC_C, record);
            case U_CUT:
                return macos_key(MOD_BIT(KC_LGUI), KC_X, record);
            case U_UND:
                return macos_key(MOD_BIT(KC_LGUI), KC_Z, record);
        }
        uint8_t mods = get_mods();
        if (record->event.pressed && mods & MOD_MASK_CTRL) {
            switch (keycode) {
                case GUI_A: // select all
                case KC_F:  // find
                case SFT_F:
                case KC_O:  // open
                case KC_P:  // print
                case CTL_S: // save
                case ALT_S:
                case SFT_T_: // new tab
                case KC_W:   // close
                    set_mods(MOD_BIT(KC_LGUI));
                    register_code(keycode);
                    del_mods(MOD_BIT(KC_LGUI));
                    return false;
            }
        }
    }

    return true;
}

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
