/* Copyright 2019 Evy Dekkers
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

// #include "process_midi.h"

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12(
  MI_A1, MI_As1, MI_B1, MI_C2, MI_Cs2, MI_D2, MI_Ds2, MI_E2, MI_F2, MI_Fs2, MI_G2, MI_Gs2,
  MI_D1, MI_Ds1, MI_E1, MI_F1, MI_Fs1, MI_G1, MI_Gs1, MI_A1, MI_As1, MI_B1, MI_C2, MI_Cs2,
  MI_G, MI_Gs, MI_A, MI_As, MI_B, MI_C1, MI_Cs1, MI_D1, MI_Ds1, MI_E1, MI_F1, MI_Fs1,
  MI_C, MI_Cs, MI_D, MI_Ds, MI_E, MI_F, MI_Fs, MI_G, MI_Gs, MI_A, MI_As, MI_B),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12(
  MI_E1, MI_F1, MI_G1, MI_A1, MI_B1, MI_C2, MI_D2, MI_E2, MI_F2, MI_G2, MI_A2, MI_B2,
  MI_Ds1, MI_E1, MI_Fs1, MI_Gs1, MI_As1, MI_B1, MI_Cs2, MI_Ds2, MI_E2, MI_Fs2, MI_Gs2, MI_As2,
  MI_A, MI_As, MI_C1, MI_D1, MI_E1, MI_F1, MI_G1, MI_A1, MI_As1, MI_C2, MI_D2, MI_E2,
  MI_Gs, MI_A, MI_B, MI_Cs1, MI_Ds1, MI_E1, MI_Fs1, MI_Gs1, MI_A1, MI_B1, MI_Cs2, MI_Ds2
  ),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12(
  MI_E1, MI_F1, MI_G1, MI_A1, MI_B1, MI_C2, MI_D2, MI_E2, MI_F2, MI_G2, MI_A2, MI_B2,
  MI_C1, MI_D1, MI_E1, MI_G1, MI_A1, MI_C2, MI_D2, MI_E2, MI_G2, MI_A2, MI_C3, MI_D3,
  ),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12(
  MI_F1, MI_G1,  MI_Gs1, MI_A1,  MI_B1,  MI_C2,  MI_Cs2, MI_D2,  MI_E2,  MI_F2,  MI_Fs2, MI_G2,
  MI_D1, MI_E1,  MI_F1,  MI_F1,  MI_G1,  MI_A1,  MI_As1, MI_B1,  MI_C2,  MI_D2,  MI_Ds2, MI_E2,
  MI_B,  MI_C1,  MI_D1,  MI_D1,  MI_E1,  MI_F1,  MI_G1,  MI_G1,  MI_A1,  MI_B1,  MI_C2,  MI_C2,
  MI_G,  MI_A,   MI_As,  MI_B,   MI_C1,  MI_D1,  MI_Ds1, MI_E1,  MI_F1,  MI_G1,  MI_Gs1, MI_A1
  ),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12(
  MI_B1,  MI_C2,  MI_Cs2, MI_D2,  MI_Ds2, MI_E2,  MI_F2,  MI_Fs2, MI_G2,  MI_Gs2, MI_A2,  MI_AOFF,
  MI_E1,  MI_F1,  MI_Fs1, MI_G1,  MI_Gs1, MI_A1,  MI_As1, MI_B1,  MI_C2,  MI_Cs2, MI_D2,  MI_OCTU,
  MI_A,   MI_As,  MI_B,   MI_C1,  MI_Cs1, MI_D1,  MI_Ds1, MI_E1,  MI_F1,  MI_Fs1, MI_G1,  MI_OCTD,
  MI_D,   MI_Ds,  MI_E,   MI_F,   MI_Fs,  MI_G,   MI_Gs,  MI_A,   MI_As,  MI_B,   MI_C1,  MI_SUST
  ),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12(
  MI_B1,  MI_C2,  MI_Cs2, MI_D2,  MI_Ds2, MI_E2,  MI_F2,  MI_Fs2, MI_G2,  MI_Gs2, MI_A2,  QK_COMBO_ON,
  MI_E1,  MI_F1,  MI_Fs1, MI_G1,  MI_Gs1, MI_A1,  MI_As1, MI_B1,  MI_C2,  MI_Cs2, MI_D2,  MI_OCTU,
  MI_A,   MI_As,  MI_B,   MI_C1,  MI_Cs1, MI_D1,  MI_Ds1, MI_E1,  MI_F1,  MI_Fs1, MI_G1,  MI_OCTD,
  KC_A,   KC_B,   MI_E,   MI_F,   MI_Fs,  MI_G,   MI_Gs,  MI_A,   MI_As,  MI_B,   MI_C1,  MI_SUST
  ),
};

const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};

combo_t key_combos[] = {
  COMBO(test_combo1, MI_C2),
};

*/

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
    process_midi(MI_OC0, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TR_C:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TR0, record);
        }
        break;
    case TR_G:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TRN5, record);
        }
        break;
    case TR_D:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TR2, record);
        }
        break;
    case TR_A:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TRN3, record);
        }
        break;
    case TR_E:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TR4, record);
        }
        break;
    case TR_B:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TRN1, record);
        }
        break;
    case TR_Gb:
        if (record->event.pressed) {
            process_midi(MI_OCN1, record);
            process_midi(MI_TR6, record);
        }
        break;
    case TR_Db:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TR1, record);
        }
        break;
    case TR_Ab:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TRN4, record);
        }
        break;
    case TR_Eb:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TR3, record);
        }
        break;
    case TR_Bb:
        if (record->event.pressed) {
            process_midi(MI_OC0, record);
            process_midi(MI_TRN2, record);
        }
        break;
    case TR_F:
        if (record->event.pressed) {
            process_midi(MI_OCN1, record);
            process_midi(MI_TR5, record);
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_4x12(
  TR_A,    TR_Db,   TR_F,    MI_F5,   MI_B4,   MI_F4,   MI_B3,   MI_F3,   MI_B2,   MI_F2,   MI_B1,   MI_F1,
  TR_D,    TR_Gb,   TR_Bb,   MI_E5,   MI_A4,   MI_E4,   MI_A3,   MI_E3,   MI_A2,   MI_E2,   MI_A1,   MI_E1,
  TR_G,    TR_B,    TR_Eb,   MI_D5,   MI_Gs4,  MI_D4,   MI_Gs3,  MI_D3,   MI_Gs2,  MI_D2,   MI_Gs1,  MI_D1,
  TR_C,    TR_E,    TR_Ab,   MI_C5,   MI_G4,   MI_C4,   MI_G3,   MI_C3,   MI_G2,   MI_C2,   MI_G1,   MI_C1
  ),
[1] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_F4,   MI_As3,  MI_Ds3,  MI_Gs2,  MI_Cs2,  MI_Fs1,
  _______, _______, _______, _______, _______, _______, MI_Ds4,  MI_Gs3,  MI_Cs3,  MI_Fs2,  MI_B1,   MI_F1,
  _______, _______, _______, _______, _______, _______, MI_Cs4,  MI_Fs3,  MI_B2,   MI_F2,   MI_As1,  MI_Ds1,
  _______, _______, _______, _______, _______, _______, MI_B3,   MI_F3,   MI_As2,  MI_Ds2,  MI_Gs1,  MI_Cs1
  ),
[2] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_F4,   MI_B3,   MI_E3,   MI_A2,   MI_D2,   MI_G1,
  _______, _______, _______, _______, _______, _______, MI_E4,   MI_A3,   MI_D3,   MI_G2,   MI_C2,   MI_F1,
  _______, _______, _______, _______, _______, _______, MI_D4,   MI_G3,   MI_C3,   MI_F2,   MI_B1,   MI_E1,
  _______, _______, _______, _______, _______, _______, MI_C4,   MI_F3,   MI_B2,   MI_E2,   MI_A1,   MI_D1
  ),
[3] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_G4,   MI_C4,   MI_F3,   MI_Bb2,  MI_Eb2,  MI_Ab1,
  _______, _______, _______, _______, _______, _______, MI_F4,   MI_Bb3,  MI_Eb3,  MI_Ab2,  MI_Db2,  MI_Gb1,
  _______, _______, _______, _______, _______, _______, MI_Eb4,  MI_Ab3,  MI_Db3,  MI_Gb2,  MI_C2,   MI_F1,
  _______, _______, _______, _______, _______, _______, MI_Db4,  MI_Gb3,  MI_C3,   MI_F2,   MI_Bb1,  MI_Eb1
  ),
[4] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_G4,   MI_C4,   MI_F3,   MI_B2,   MI_E2,   MI_A1,
  _______, _______, _______, _______, _______, _______, MI_F4,   MI_B3,   MI_E3,   MI_A2,   MI_D2,   MI_G1,
  _______, _______, _______, _______, _______, _______, MI_E4,   MI_A3,   MI_D3,   MI_G2,   MI_C2,   MI_F1,
  _______, _______, _______, _______, _______, _______, MI_D4,   MI_G3,   MI_C3,   MI_F2,   MI_B1,   MI_E1
  ),
[5] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_A4,   MI_D4,   MI_G3,   MI_C3,   MI_F2,   MI_B1,
  _______, _______, _______, _______, _______, _______, MI_G4,   MI_C4,   MI_F3,   MI_B2,   MI_E2,   MI_A1,
  _______, _______, _______, _______, _______, _______, MI_F4,   MI_B3,   MI_E3,   MI_A2,   MI_D2,   MI_G1,
  _______, _______, _______, _______, _______, _______, MI_E4,   MI_A3,   MI_D3,   MI_G2,   MI_C2,   MI_F1
  ),
[6] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_As4,  MI_Ds4,  MI_Gs3,  MI_Cs3,  MI_Fs2,  MI_B1,
  _______, _______, _______, _______, _______, _______, MI_Gs4,  MI_Cs4,  MI_Fs3,  MI_B2,   MI_E2,   MI_As1,
  _______, _______, _______, _______, _______, _______, MI_Fs4,  MI_B3,   MI_E3,   MI_As2,  MI_Ds2,  MI_Gs1,
  _______, _______, _______, _______, _______, _______, MI_E4,   MI_As3,  MI_Ds3,  MI_Gs2,  MI_Cs2,  MI_Fs1
  ),
[7] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_B3,   MI_E3,   MI_A2,   MI_D2,   MI_G1,   MI_C1,
  _______, _______, _______, _______, _______, _______, MI_A3,   MI_D3,   MI_G2,   MI_C2,   MI_F1,   MI_B,
  _______, _______, _______, _______, _______, _______, MI_G3,   MI_C3,   MI_F2,   MI_B1,   MI_E1,   MI_A,
  _______, _______, _______, _______, _______, _______, MI_F3,   MI_B2,   MI_E2,   MI_A1,   MI_D1,   MI_G
  ),
[8] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_C4,   MI_F3,   MI_Bb2,  MI_Eb2,  MI_Ab1,  MI_Db1,
  _______, _______, _______, _______, _______, _______, MI_Bb3,  MI_Eb3,  MI_Ab2,  MI_Db2,  MI_Gb1,  MI_C1,
  _______, _______, _______, _______, _______, _______, MI_Ab3,  MI_Db3,  MI_Gb2,  MI_C2,   MI_F1,   MI_Bb,
  _______, _______, _______, _______, _______, _______, MI_Gb3,  MI_C3,   MI_F2,   MI_Bb1,  MI_Eb1,  MI_Ab
  ),
[9] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_C4,   MI_F3,   MI_B2,   MI_E2,   MI_A1,   MI_D1,
  _______, _______, _______, _______, _______, _______, MI_B3,   MI_E3,   MI_A2,   MI_D2,   MI_G1,   MI_C1,
  _______, _______, _______, _______, _______, _______, MI_A3,   MI_D3,   MI_G2,   MI_C2,   MI_F1,   MI_B,
  _______, _______, _______, _______, _______, _______, MI_G3,   MI_C3,   MI_F2,   MI_B1,   MI_E1,   MI_A
  ),
[10] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_D4,   MI_G3,   MI_C3,   MI_F2,   MI_Bb1,  MI_Eb1,
  _______, _______, _______, _______, _______, _______, MI_C4,   MI_F3,   MI_Bb2,  MI_Eb2,  MI_Ab1,  MI_D1,
  _______, _______, _______, _______, _______, _______, MI_Bb3,  MI_Eb3,  MI_Ab2,  MI_D2,   MI_G1,   MI_C1,
  _______, _______, _______, _______, _______, _______, MI_A3,   MI_D3,   MI_G2,   MI_C2,   MI_F1,   MI_Bb
  ),
[11] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, MI_D4,   MI_G3,   MI_C3,   MI_F2,   MI_B1,   MI_E1,
  _______, _______, _______, _______, _______, _______, MI_C4,   MI_F3,   MI_B2,   MI_E2,   MI_A1,   MI_D1,
  _______, _______, _______, _______, _______, _______, MI_B3,   MI_E3,   MI_A2,   MI_D2,   MI_G1,   MI_C1,
  _______, _______, _______, _______, _______, _______, MI_A3,   MI_D3,   MI_G2,   MI_C2,   MI_F1,   MI_B
  ),
};
