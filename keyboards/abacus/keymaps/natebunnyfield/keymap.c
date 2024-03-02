#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        KC_TAB,     KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       KC_F,       KC_G,       KC_C,           KC_R,           KC_L,       KC_SLSH,
        KC_LCTL,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       KC_D,       KC_H,       KC_T,           KC_N,           KC_S,       KC_MINS,
        KC_LSFT,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_B,       KC_M,       KC_W,           KC_V,           KC_Z,       KC_ENT,
        KC_ESC,     KC_LALT,    KC_LGUI,    KC_SPC,                 KC_BSPC,                            LT(1,KC_LEFT),  LT(2,KC_RGHT),  KC_UP,      KC_DOWN),
	[1] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,           KC_9,           KC_0,       KC_BSLS,
        _______,    _______,    _______,    KC_LT,      KC_GT,      KC_LPRN,    KC_RPRN,    KC_LBRC,    KC_RBRC,        KC_LCBR,        KC_RCBR,    KC_EQL,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
        KC_MPLY,    _______,    _______,    _______,                KC_DEL,                             KC_NO,          KC_END,         KC_PGUP,    KC_PGDN),
	[2] = LAYOUT(
        QK_BOOT,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,          KC_F9,          KC_F10,     _______,
        _______,    KC_MS_L,    KC_MS_R,    KC_MS_U,    KC_MS_D,    KC_VOLD,    KC_VOLU,    _______,    _______,        _______,        _______,    _______,
        _______,    KC_F11,     KC_F12,     _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
        KC_MPLY,    _______,    _______,    KC_BTN5,                KC_BTN1,                            KC_BTN2,        KC_NO,          KC_BTN3,    KC_BTN4)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_WH_D);
    } else {
        tap_code(KC_WH_U);
    }
    return false;
};
