#!/usr/bin/env python3
"""Decode a Keyboardio Preonic `keymap.custom` dump (648 values) into a grid.

Usage: python3 decode_keymap.py keymap.custom.readback.txt [layer ...]
Encodings are from Kaleidoscope master (key_defs.h, keymaps.h, Ranges.h,
MouseKeyDefs.h), read 2026-10-30. Unknown values print as raw hex.
"""
import sys

ROWS, COLS = 6, 12
PER_LAYER = ROWS * COLS

HID = {0: '___', 0xFFFF: '...'}  # 0 = Key_NoKey, 0xFFFF = Key_Transparent
for i in range(26):
    HID[0x04 + i] = chr(ord('A') + i)
for i, d in enumerate('1234567890'):
    HID[0x1E + i] = d
HID.update({0x28: 'Enter', 0x29: 'Esc', 0x2A: 'Bksp', 0x2B: 'Tab', 0x2C: 'Space',
            0x2D: '-', 0x2E: '=', 0x2F: '[', 0x30: ']', 0x31: '\\', 0x33: ';',
            0x34: "'", 0x35: '`', 0x36: ',', 0x37: '.', 0x38: '/', 0x39: 'Caps',
            0x46: 'PrtSc', 0x47: 'ScrLk', 0x48: 'Pause', 0x49: 'Ins', 0x4A: 'Home',
            0x4B: 'PgUp', 0x4C: 'Del', 0x4D: 'End', 0x4E: 'PgDn', 0x4F: 'Right',
            0x50: 'Left', 0x51: 'Down', 0x52: 'Up', 0x65: 'Menu',
            0xE0: 'LCtrl', 0xE1: 'LShift', 0xE2: 'LAlt', 0xE3: 'LGui',
            0xE4: 'RCtrl', 0xE5: 'RShift', 0xE6: 'RAlt', 0xE7: 'RGui'})
for i in range(12):
    HID[0x3A + i] = f'F{i + 1}'
for i in range(12):
    HID[0x68 + i] = f'F{i + 13}'

MODS = ['LCtrl', 'LShift', 'LAlt', 'LGui', 'RCtrl', 'RShift', 'RAlt', 'RGui']
HELD = [(0x01, 'C'), (0x02, 'A'), (0x04, 'AltGr'), (0x08, 'S'), (0x10, 'G')]

CONSUMER = {0xCD: 'Play', 0xB5: 'Next', 0xB6: 'Prev', 0xB7: 'Stop', 0xE2: 'Mute',
            0xE9: 'Vol+', 0xEA: 'Vol-', 0x6F: 'Bri+', 0x70: 'Bri-'}
MOUSE_BTN = {0x41: 'Click L', 0x42: 'Click R', 0x44: 'Click M', 0x48: 'Click Back',
             0x50: 'Click Fwd'}
MOUSE_DIR = {1: 'Up', 2: 'Down', 4: 'Left', 8: 'Right'}

# Ranges.h, counted from FIRST = 0xC000
OSM_FIRST, OSL_FIRST = 0xC001, 0xC009
DUM_FIRST, DUL_FIRST = 0xC011, 0xC812
TD_FIRST = 0xD013
MACRO_FIRST = 0x6000


def name(v):
    if v in HID:
        return HID[v]
    hi, lo = v >> 8, v & 0xFF
    if hi & 0x40 == 0 and v < 0x2000:  # plain key with modifier flags
        mods = '+'.join(n for bit, n in HELD if hi & bit)
        return f'{mods}+{HID.get(lo, hex(lo))}'
    if hi == 0x48:
        return CONSUMER.get(lo, f'Cons {lo:#x}')
    if hi == 0x50:
        if lo & 0x40:
            return MOUSE_BTN.get(lo, f'Btn {lo:#x}')
        d = '/'.join(n for bit, n in MOUSE_DIR.items() if lo & bit)
        return ('Scroll ' if lo & 0x10 else 'Mouse ') + d
    if hi == 0x44:
        if lo < 42:
            return f'Lock L{lo}'
        if lo < 84:
            return f'Hold L{lo - 42}'
        return f'Move L{lo - 84}'
    if MACRO_FIRST <= v <= MACRO_FIRST + 255:
        return f'Macro {v - MACRO_FIRST}'
    if OSM_FIRST <= v < OSL_FIRST:
        return f'OS {MODS[v - OSM_FIRST]}'
    if OSL_FIRST <= v < DUM_FIRST:
        return f'OS L{v - OSL_FIRST}'
    if DUM_FIRST <= v < DUL_FIRST:
        m, k = divmod(v - DUM_FIRST, 256)
        return f'{HID.get(k, hex(k))}/{MODS[m]}'
    if DUL_FIRST <= v < TD_FIRST:
        layer, k = divmod(v - DUL_FIRST, 256)
        return f'{HID.get(k, hex(k))}/L{layer}'
    if TD_FIRST <= v < TD_FIRST + 16:
        return f'TapDance {v - TD_FIRST}'
    return f'{v:#06x}'


def main():
    vals = list(map(int, open(sys.argv[1]).read().split()))
    layers = [int(a) for a in sys.argv[2:]] or range(len(vals) // PER_LAYER)
    for L in layers:
        print(f'== layer {L}')
        for r in range(ROWS):
            row = vals[L * PER_LAYER + r * COLS:L * PER_LAYER + (r + 1) * COLS]
            print(' '.join(f'{name(v):>10}' for v in row))


if __name__ == '__main__':
    main()
