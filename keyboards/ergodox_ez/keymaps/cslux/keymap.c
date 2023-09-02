#include QMK_KEYBOARD_H
#include "version.h"


enum layers {
    BASE,  // default layer
    AUX,  // F1-F12, NUMPAD
    MOUSE,  // MOUSE
    QWERTY,  // QWERTY
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [BASE] = LAYOUT_ergodox_pretty(
          TG(1), KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC, KC_ESC, KC_6, KC_7, KC_8, KC_9, KC_0, TG(2), KC_GRV, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_LBRC, KC_RBRC, KC_F, KC_G, KC_C, KC_R, KC_L, KC_EQL, KC_TAB, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH, LSFT_T(KC_LCBR), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_LGUI, KC_LGUI, KC_B, KC_M, KC_W, KC_V, KC_Z, RSFT_T(KC_RCBR), LCTL(KC_C), LCTL(KC_X), LCTL(KC_V), LCTL(KC_SLSH), LT(1,KC_SPC), LT(2,KC_SPC), KC_MINS, KC_BSLS, KC_UNDS, KC_RALT, KC_HOME, KC_END, KC_LEFT, KC_RGHT, KC_PGUP, KC_UP, LCTL_T(KC_BSPC), LALT_T(KC_DEL), KC_PGDN, KC_DOWN, LALT_T(KC_SPC), LCTL_T(KC_ENT)
        ),
        [AUX] = LAYOUT_ergodox_pretty(KC_TRNS, KC_MPRV, KC_LEFT, KC_RGHT, KC_MNXT, KC_MPLY, KC_TRNS, KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSLS, QK_BOOT, KC_TRNS, KC_F12, KC_F11, KC_F10, KC_F9, KC_VOLU, KC_TRNS, KC_TRNS, KC_CIRC, KC_P7, KC_P8, KC_P9, KC_PAST, KC_PERC, KC_TRNS, KC_F8, KC_F7, KC_F6, KC_F5, KC_VOLD, KC_LPRN, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_RPRN, KC_TRNS, KC_F4, KC_F3, KC_F2, KC_F1, KC_MUTE, KC_MSTP, KC_TRNS, KC_QUES, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_PCMM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
        [MOUSE] = LAYOUT_ergodox_pretty(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_WH_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(3), KC_TRNS
        ),
        [QWERTY] = LAYOUT_ergodox_pretty(
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,
          KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_TRNS, KC_TRNS, KC_Z,
          KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;
};
