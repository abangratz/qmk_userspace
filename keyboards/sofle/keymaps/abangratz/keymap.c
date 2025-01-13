/*
    Author: Anton 'tony' Bangratz

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include QMK_KEYBOARD_H

#include "features/achordion.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _DESKTOP
};

enum custom_keycodes { KC_LSTRT = SAFE_RANGE, KC_LEND, KC_RARROW, KC_ELIXIRPIPE, KC_DOUBLEARROW, KC_LARROW, KC_HASHROCKET, KC_COLEMAK };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* COLEMAK
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | <-   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  /   |LT_A/A|LT_R/R|LT_L/S| LS/T |LT_D/G|-------.    ,-------|   M  | LS/N |LT_L/E|LT_R/I|LT_A/O|  '   |
     * |------+------+------+------+------+------| Mute  |    | DT Pri|------+------+------+------+------+------|
     * |  [   |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  | TT A |  ]   |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | TT L | TT R | LC_t |LG_t  | /LA_t   /       \ RA_t \  |RG_t  | RC_t |  TT A |  =   |
     *            |      |      | Tab  |Spc   |/  Esc  /         \Enter \ |Spc   | CAPS |       |      |
     *            `----------------------------------'           '------''-----------------------------'
     */

    [_COLEMAK] = LAYOUT(
        /* first line */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        /* second line */
        KC_GRV, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
        /* third line */
        KC_SLSH, LT(_ADJUST, KC_A), LT(_RAISE, KC_R), LT(_LOWER, KC_S), LSFT_T(KC_T), LT(_DESKTOP, KC_G), KC_M, RSFT_T(KC_N), LT(_LOWER, KC_E), LT(_RAISE, KC_I), LT(_ADJUST, KC_O), KC_QUOT,
        /* fourth line */
        KC_LBRC, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MUTE, DT_PRNT, KC_K, KC_H, KC_COMM, KC_DOT, KC_BSLS, KC_RBRC,
        /* thumb keys */
        TT(_LOWER), TT(_RAISE), LCTL_T(KC_TAB), LGUI_T(KC_SPC), LALT_T(KC_ESC), RALT_T(KC_ENT), RGUI_T(KC_SPC), RCTL_T(KC_CAPS), KC_MINS, KC_EQL),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |  !   |  @   |  /   |  \   | ~    |                    |      |   7  |   8  |   9  |  -   |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |  [   |  ]   |  (   | LS/) |  +   |-------.    ,-------|      | RS/4 |   5  |   6  |  +   |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |  _   |  *   |  -   |-------|    |-------|   0  |   1  |   2  |   3  |   .  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | TT 1 |      | LC_t |LG_t  | /LA_t   /       \ RA_t \  |RG_t  | RC_t |  -    |  =   |
     *            |      |      | Tab  |Spc   |/  Esc  /         \Enter \ |Spc   | CAPS |       |      |
     *            `----------------------------------'           '------''-----------------------------'
     */
    [_LOWER] = LAYOUT(
        /* first line */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        /* second line */
        XXXXXXX, KC_EXLM, KC_AT, KC_SLSH, KC_BSLS, KC_TILD, XXXXXXX, KC_7, KC_8, KC_9, KC_KP_MINUS, _______,
        /* third line */
        XXXXXXX, KC_LBRC, KC_RBRC, KC_LPRN, LSFT_T(KC_0), KC_PLUS, XXXXXXX, RSFT_T(KC_4), KC_5, KC_6, KC_KP_PLUS, XXXXXXX,
        /* fourth line */
        XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_ASTR, KC_MINUS, XXXXXXX, XXXXXXX, KC_0, KC_1, KC_2, KC_3, KC_DOT, XXXXXXX,
        /* thumb keys */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* RAISE
     * ,----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |PrtScr| Ins  | <=>  |  -   |  =   |      |                    | PgUp | Home |  Up  | End  |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |  |>  |  <-  |  ->  |  =>  |LShift|-------.    ,-------|RShift| Left | Down | Right|  Del |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------| PgDn |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | TT L | TT R | LC_t |LG_t  | /LA_t   /       \ RA_t \  |RG_t  | RC_t |  -    |  =   |
     *            |      |      | Tab  |Spc   |/  Esc  /         \Enter \ |Spc   | CAPS |       |      |
     *            `-----------------------------------'           '------''----------------------------'
     */
    [_RAISE] = LAYOUT(
        /* first line */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        /* second line */
        KC_PSCR, KC_INS, KC_HASHROCKET, KC_MINS, KC_EQL, XXXXXXX, KC_PGUP, KC_HOME, KC_UP, KC_END, XXXXXXX, KC_BSPC,
        /* third line */
        XXXXXXX, KC_ELIXIRPIPE, KC_LARROW, KC_RARROW, KC_DOUBLEARROW, KC_LSFT, KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, XXXXXXX,
        /* fourth line */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        /* thumb keys */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * ,-----------------------------------------.                    ,-------------------------------------------------------------.
     * |      |      |      |      |      |      |                    | COLEMAK |           |         |           |         |         |
     * |------+------+------+------+------+------|                    |---------+-----------+---------+-----------+---------+---------|
     * |RESET |      |      |      |      |      |                    | balance | deskt7    | deskt8  | deskt9    |         |         |
     * |------+------+------+------+------+------|                    |---------+-----------+---------+-----------+---------+---------|
     * |      |      |      |      |      |      |-------.    ,-------|   bsp   | deskt4    | deskt5  | deskt6    |         |         |
     * |------+------+------+------+------+------|  MUTE |    |       |---------+-----------+---------+-----------+---------+---------|
     * |      |      |      |      |      |      |-------|    |-------| deskt0  | deskt1    | deskt2  | deskt4    |         |         |
     * `-----------------------------------------/       /     \      \---------------------------------------------------------------'
     *            | TT L | TT R | LC_t |LG_t  | /LA_t   /       \ RA_t \  |RG_t  | RC_t |  -    |  =   |
     *            |      |      | Tab  |Spc   |/  Esc  /         \Enter \ |Spc   | CAPS |       |      |
     *            `-----------------------------------'           '------''----------------------------'
     */
    [_ADJUST] = LAYOUT(
        /* first line */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        /* second line */
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX, C(G(KC_0)), LAG(KC_7), LAG(KC_8), LAG(KC_9), XXXXXXX, XXXXXXX,
        /* third line */
        XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX, C(G(KC_1)), LAG(KC_4), LAG(KC_5), LAG(KC_6), XXXXXXX, XXXXXXX,
        /* fourth line */
        XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, LAG(KC_0), LAG(KC_1), LAG(KC_2), LAG(KC_3), XXXXXXX, XXXXXXX,
        /* thumb keys */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * ,-----------------------------------------.                    ,-------------------------------------------------------------.
     * |      |      |      |      |      |      |                    | COLEMAK |           |         |           |         |         |
     * |------+------+------+------+------+------|                    |---------+-----------+---------+-----------+---------+---------|
     * |RESET | F1   | F2   | F3   | F4   |      |                    | balance | ->deskt7  | ->deskt8| ->deskt9  |         |         |
     * |------+------+------+------+------+------|                    |---------+-----------+---------+-----------+---------+---------|
     * |      | F5   | F6   | F7   | F8   |      |-------.    ,-------|   bsp   | ->deskt4  | ->deskt5| ->deskt6  |         |         |
     * |------+------+------+------+------+------|  MUTE |    |       |---------+-----------+---------+-----------+---------+---------|
     * |      | F9   | F10  | F11  | F1   |      |-------|    |-------| ->deskt0| ->deskt1  | ->deskt2| ->deskt4  |         |         |
     * `-----------------------------------------/       /     \      \---------------------------------------------------------------'
     *            | TT L | TT R | LC_t |LG_t  | /LA_t   /       \ RA_t \  |RG_t  | RC_t |  -    |  =   |
     *            |      |      | Tab  |Spc   |/  Esc  /         \Enter \ |Spc   | CAPS |       |      |
     *            `-----------------------------------'           '------''----------------------------'
     */
    [_DESKTOP] = LAYOUT(
        /* first line */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        /* second line */
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX, C(G(KC_0)), RSG(KC_7), RSG(KC_8), RSG(KC_9), XXXXXXX, XXXXXXX,
        /* third line */
        XXXXXXX, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX, C(G(KC_1)), RSG(KC_4), RSG(KC_5), RSG(KC_6), XXXXXXX, XXXXXXX,
        /* fourth line */
        XXXXXXX, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, RSG(KC_0), RSG(KC_1), RSG(KC_2), RSG(KC_3), XXXXXXX, XXXXXXX,
        /* thumb keys */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        /* case _QWERTY: */
        /*     oled_write_ln_P(PSTR("Qwrt"), false); */
        /*     break; */
        case _COLEMAK:
            oled_write_ln_P(PSTR("Cole"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        /* case _QWERTY: */
        case _COLEMAK:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case KC_I:
            if (other_keycode == KC_E) {
                return true;
            }
            if (other_keycode == KC_N) {
                return true;
            }
            break;
        case KC_R:
            if (other_keycode == KC_S) {
                return true;
            }
            if (other_keycode == KC_T) {
                return true;
            }
            break;
    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    if (!process_caps_word(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_ELIXIRPIPE:
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            break;
        case KC_RARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case KC_LARROW:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;
        case KC_DOUBLEARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case KC_HASHROCKET:
            if (record->event.pressed) {
                SEND_STRING("<=>");
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
#    ifdef RGBLIGHT_ENABLE
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    bool    is_ctrl  = (temp_mod | temp_osm) & MOD_MASK_CTRL;
    bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;

    if (is_shift) {
        if (index == 0) { /* First encoder */
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
        } else if (index == 1) { /* Second encoder */
            if (clockwise) {
                rgblight_decrease_sat();
            } else {
                rgblight_increase_sat();
            }
        }
    } else if (is_ctrl) {
        if (index == 0) { /* First encoder */
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
        } else if (index == 1) { /* Second encoder */
            if (clockwise) {
                rgblight_increase_speed();
            } else {
                rgblight_decrease_speed();
            }
        }
    } else {
#    endif
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            if (clockwise) {
                g_tapping_term += 5;
            } else {
                g_tapping_term -= 5;
            }
        }
#    ifdef RGBLIGHT_ENABLE
    }
#    endif
    return true;
}

#endif
