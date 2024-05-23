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

enum custom_keycodes {
    TR_C = SAFE_RANGE,
    TR_G,
    TR_D,
    TR_A,
    TR_E,
    TR_B,
    TR_Gb,
    TR_Db,
    TR_Ab,
    TR_Eb,
    TR_Bb,
    TR_F
};

void keyboard_post_init_user(void) {
    process_midi(MI_OC1, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TR_C:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TR0, record);
        }
        break;
    case TR_G:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TRN5, record);
        }
        break;
    case TR_D:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TR2, record);
        }
        break;
    case TR_A:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TRN3, record);
        }
        break;
    case TR_E:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TR4, record);
        }
        break;
    case TR_B:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TRN1, record);
        }
        break;
    case TR_Gb:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TR6, record);
        }
        break;
    case TR_Db:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TR1, record);
        }
        break;
    case TR_Ab:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TRN4, record);
        }
        break;
    case TR_Eb:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TR3, record);
        }
        break;
    case TR_Bb:
        if (record->event.pressed) {
            process_midi(MI_OC1, record);
            process_midi(MI_TRN2, record);
        }
        break;
    case TR_F:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TR5, record);
        }
        break;
    }
    return true;
};

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_preonic_2x2u(MI_C, MI_D, MI_G, MI_A, MI_C1, MI_D1, MI_E1, MI_F1, MI_G1, MI_A1, MI_B1, MI_C2,
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
        KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
        KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT,
        KC_ESC, LCAG(KC_NO), KC_LALT, KC_LGUI, KC_SPC, KC_BSPC, LT(8,KC_LEFT), LT(9,KC_RGHT), KC_UP, KC_DOWN),
    [1] = LAYOUT_preonic_2x2u(MI_C1, MI_D1, MI_E1, MI_F1, MI_G1, MI_A1, MI_B1, MI_C2, MI_D2, MI_E2, MI_F2, MI_G2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
	[2] = LAYOUT_preonic_2x2u(MI_B, MI_C1, MI_D1, MI_E1, MI_F1, MI_G1, MI_Ab1, MI_A1, MI_B1, MI_C2, MI_D2, MI_E2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    [3] = LAYOUT_preonic_2x2u(MI_B, MI_C1, MI_D1, MI_Eb1, MI_F1, MI_G1, MI_Ab1, MI_Bb1, MI_B1, MI_C2, MI_D2, MI_Eb2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
	[8] = LAYOUT_preonic_2x2u(TR_C, TR_G, TR_D, TR_A, TR_E, TR_B, TR_Gb, TR_Db, TR_Ab, TR_Eb, TR_Bb, TR_F,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
        _______, KC_F11, KC_F12, KC_LT, KC_GT, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_EQL,
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        KC_MPLY, _______, _______, _______, _______, KC_DEL, KC_NO, KC_END, KC_PGUP, KC_PGDN),
	[9] = LAYOUT_preonic_2x2u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(3), TO(2), TO(1), TO(0),
        QK_BOOT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, TR_E, TR_B, TR_Gb, TR_Db,
        _______, KC_MS_L, KC_MS_R, KC_MS_U, KC_MS_D, KC_VOLD, KC_VOLU, LGUI(KC_LCBR), TR_Ab, TR_Eb, TR_Bb, TR_F,
        _______, KC_NO, KC_NO, KC_WH_U, KC_WH_D, LGUI(KC_W), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_ESC, _______, _______, _______, KC_BTN1, KC_BTN2, KC_HOME, KC_NO, KC_BTN3, KC_BTN1)
};

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_preonic_2x2u(
        KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_VOLD, KC_VOLU, KC_MS_L, KC_MS_R, KC_MS_U, KC_MS_D, KC_WH_D, KC_WH_U,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
        KC_ESC,  KC_MPLY, KC_LALT, KC_LGUI, KC_SPC,  KC_BSPC, LT(1,KC_LEFT),    LT(2,KC_RGHT),    KC_UP,   KC_DOWN),
    [1] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        DT_UP,   DT_DOWN, DT_PRNT, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_DEL,  KC_NO,            KC_END,           KC_PGUP, KC_PGDN),
    [2] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        TD(TD_R),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_MS_L, KC_MS_R, KC_MS_U, KC_MS_D, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        DF(3),   _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3,          KC_NO,            KC_WH_D, KC_WH_U),
	[3] = LAYOUT_preonic_2x2u(
        MI_A1,   MI_As1,  MI_B1,   MI_C2,   MI_Cs2,  MI_D2,   MI_Ds2,  MI_E2,   MI_F2,   MI_Fs2,  MI_G2,   MI_Gs2,
        MI_D1,   MI_Ds1,  MI_E1,   MI_F1,   MI_Fs1,  MI_G1,   MI_Gs1,  MI_A1,   MI_As1,  MI_B1,   MI_C2,   MI_Cs2,
        MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,    MI_C1,   MI_Cs1,  MI_D1,   MI_Ds1,  MI_E1,   MI_F1,   MI_Fs1,
        MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,
        DF(0),   MI_VELD, MI_VELU, MI_SOFT, MI_SUST, MI_AOFF, MI_TRSD,          MI_TRSU,          MI_OCTD, MI_OCTU),
    [4] = LAYOUT_preonic_2x2u(
        MI_A,    MI_B,    MI_C1,   MI_D1,   MI_E1,   MI_F1,   MI_G1,   MI_Gs1,  MI_A1,   MI_B1,   MI_C2,   MI_D2,
        MI_G,    MI_Gs,   MI_A,    MI_B,    MI_C1,   MI_D1,   MI_E1,   MI_F1,   MI_G1,   MI_Gs1,  MI_A1,   MI_B1,
        MI_E,    MI_F,    MI_G,    MI_Gs,   MI_A,    MI_B,    MI_C1,   MI_D1,   MI_E1,   MI_F1,   MI_G1,   MI_Gs1,
        MI_C,    MI_D,    MI_E,    MI_F,    MI_G,    MI_Gs,   MI_A,    MI_B,    MI_C1,   MI_D1,   MI_E1,   MI_F1,
        DF(0),   _______, _______, _______, _______, _______, _______,          _______,          _______, _______),
	[5] = LAYOUT_preonic_2x2u(
        MI_A1,   MI_As1,  MI_B1,   MI_C2,   MI_Cs2,  MI_D2,   MI_Ds2,  MI_E2,   MI_F2,   MI_Fs2,  MI_G2,   MI_Gs2,
        MI_D1,   MI_Ds1,  MI_E1,   MI_F1,   MI_Fs1,  MI_G1,   MI_Gs1,  MI_A1,   MI_As1,  MI_B1,   MI_C2,   MI_Cs2,
        MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,    MI_C1,   MI_Cs1,  MI_D1,   MI_Ds1,  MI_E1,   MI_F1,   MI_Fs1,
        MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,
        DF(0),   _______, _______, _______, MI_SUST, MI_SOFT, _______,          _______,          _______, _______),
    [6] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______),
	[7] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______),
    [8] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______),
	[9] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______),
	[10] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______),
    [11] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______)
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
