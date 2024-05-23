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

void keyboard_post_init_user(void) {
    process_midi(MI_OC1, 0);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        KC_TAB,     KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,       KC_Y,       KC_F,       KC_G,       KC_C,           KC_R,           KC_L,       KC_SLSH,
        KC_LCTL,    KC_A,       KC_O,       KC_E,       KC_U,       KC_I,       KC_D,       KC_H,       KC_T,           KC_N,           KC_S,       KC_MINS,
        KC_LSFT,    KC_SCLN,    KC_Q,       KC_J,       KC_K,       KC_X,       KC_B,       KC_M,       KC_W,           KC_V,           KC_Z,       KC_ENT,
        KC_ESC,     KC_LALT,    KC_LGUI,    KC_SPC,                 KC_BSPC,                            LT(1,KC_LEFT),  LT(2,KC_RGHT),  KC_UP,      KC_DOWN),
	[1] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,           KC_9,           KC_0,       KC_BSLS,
        DT_UP,      DT_DOWN,    DT_PRNT,    KC_LT,      KC_GT,      KC_LPRN,    KC_RPRN,    KC_LBRC,    KC_RBRC,        KC_LCBR,        KC_RCBR,    KC_EQL,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
        _______,    _______,    _______,    _______,                KC_DEL,                             KC_NO,          KC_END,         KC_PGUP,    KC_PGDN),
	[2] = LAYOUT(
        TD(TD_R),   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,          KC_F9,          KC_F10,     _______,
        _______,    KC_MS_L,    KC_MS_R,    KC_MS_U,    KC_MS_D,    KC_VOLD,    KC_VOLU,    _______,    _______,        _______,        _______,    _______,
        _______,    KC_F11,     KC_F12,     _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,    _______,
        DF(3),      _______,    _______,    KC_BTN1,                KC_BTN2,                            KC_BTN3,        KC_NO,          KC_WH_D,    KC_WH_U),
    [3] = LAYOUT(
        MI_D1,      MI_Ds1,     MI_E1,      MI_F1,      MI_Fs1,     MI_G1,      MI_Gs1,     MI_A1,      MI_As1,         MI_B1,          MI_C2,      MI_Cs2,
        MI_G,       MI_Gs,      MI_A,       MI_As,      MI_B,       MI_C1,      MI_Cs1,     MI_D1,      MI_Ds1,         MI_E1,          MI_F1,      MI_Fs1,
        MI_C,       MI_Cs,      MI_D,       MI_Ds,      MI_E,       MI_F,       MI_Fs,      MI_G,       MI_Gs,          MI_A,           MI_As,      MI_B,
        DF(0),      MI_VELD,    MI_VELU,    MI_SUST,                MI_AOFF,                            MI_TRSD,        MI_TRSU,        MI_OCTD,    MI_OCTU)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_WH_D);
    } else {
        tap_code(KC_WH_U);
    }
    return false;
};
