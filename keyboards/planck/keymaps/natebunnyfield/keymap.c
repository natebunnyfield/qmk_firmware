#include QMK_KEYBOARD_H

enum {
    TD_R = 0
};

void safe_reset(tap_dance_state_t *state, void *user_date) {
    if (state->count >= 3) {
        reset_keyboard();
        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_R] = ACTION_TAP_DANCE_FN(safe_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_2x2u(
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
        KC_ESC,  KC_MPLY, KC_LALT, KC_LGUI, KC_SPC,  KC_BSPC, LT(1,KC_LEFT),    LT(2,KC_RGHT),    KC_UP,   KC_DOWN),
	[1] = LAYOUT_planck_2x2u(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        DT_UP,   DT_DOWN, DT_PRNT, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_DEL,  KC_NO,            KC_END,           KC_PGUP, KC_PGDN),
	[2] = LAYOUT_planck_2x2u(
        TD(TD_R),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_MS_L, KC_MS_R, KC_MS_U, KC_MS_D, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3,          KC_NO,            KC_WH_D, KC_WH_U),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
