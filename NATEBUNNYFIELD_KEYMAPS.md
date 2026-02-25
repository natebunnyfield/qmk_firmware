# natebunnyfield Keymaps

Personal keyboard firmware across 5 keyboards. All typing layers use **Dvorak**. MIDI layers use **advanced MIDI** with chromatic and harmonic layouts.

---

## Keyboards

### evyd13/pockettype — PocketType
**MCU:** ATmega32U4 · **Layout:** ortho 4×12 (48 keys) · **MIDI:** Advanced

The most musically focused keyboard. The left 3 columns of every layer are **circle-of-fifths transposition keys** — pressing one instantly shifts octave and transpose so the right 9 columns play in that key.

| Layer | Description |
|-------|-------------|
| 0 | **Circle-of-fifths instrument.** Left 3 cols: TR keys (C G D A E B / Gb Db Ab Eb Bb F). Right 9 cols: harmonic voicing in 4ths, spanning 5 octaves (F1–F5). |
| 1–11 | **Harmonic voicings** tuned for each step of the circle of fifths. Each layer shifts the right 9 columns to match the selected key. |

**Transposition keys (left 3 cols):**
Sets `midi_config.octave` and `midi_config.transpose` on press so the right-side notes always reflect the current key.

| Key | Octave | Transpose | Key of |
|-----|--------|-----------|--------|
| TR_C | OC0 | 0 | C |
| TR_G | OC0 | -5 | G |
| TR_D | OC0 | +2 | D |
| TR_A | OC0 | -3 | A |
| TR_E | OC0 | +4 | E |
| TR_B | OC0 | -1 | B |
| TR_Gb | OCN1 | +6 | Gb |
| TR_Db | OC0 | +1 | Db |
| TR_Ab | OC0 | -4 | Ab |
| TR_Eb | OC0 | +3 | Eb |
| TR_Bb | OC0 | -2 | Bb |
| TR_F | OCN1 | +5 | F |

---

### preonic — Drop Preonic
**MCU:** ATmega32U4 · **Layout:** preonic\_2x2u 5×12 (62 keys) · **MIDI:** Advanced

General-purpose typing + MIDI. Default layer is Dvorak. Switch to MIDI with `DF(3)`.

| Layer | Description |
|-------|-------------|
| 0 | **Dvorak.** Top row: mouse buttons + volume + mouse movement. Bottom row: `LT(1,←)` / `LT(2,→)` for layers. |
| 1 | **Symbols/Numbers.** Backtick, digits, brackets, braces. Tap-tempo controls `DT_UP/DOWN/PRNT`. |
| 2 | **Functions/Mouse/System.** F1–F12, mouse movement, scroll, brightness, media. `TD(TD_R)` = triple-tap for safe reset. `DF(3)` switches base to MIDI. |
| 3 | **MIDI Chromatic** (48 notes, C to Gs2). Bottom row: `DF(0)` back to Dvorak, velocity, sustain, soft, all-notes-off, transpose ±, octave ±. |
| 4 | **MIDI Guitar tuning** (notes in 4ths across rows: C E G B). |
| 5 | **MIDI Chromatic alt** (same as layer 3, slightly different bottom row). |
| 6–11 | Empty (reserved). |

**Safe reset:** `TD(TD_R)` on layer 2 — triple-tap to enter bootloader.

---

### abacus — Abacus (nickolaij)
**MCU:** ATmega32U4 · **Layout:** 3×12 (36 keys, no number row) · **MIDI:** Advanced · **Encoder:** yes

Compact 36-key board. Same Dvorak/MIDI pattern as Planck but no top row. Encoder scrolls up/down.

| Layer | Description |
|-------|-------------|
| 0 | **Dvorak.** `LT(1,←)` / `LT(2,→)` hold for layers. |
| 1 | **Symbols/Numbers.** Digits, brackets, tap-tempo. |
| 2 | **Functions/Mouse.** F1–F12, mouse, scroll, media. `TD(TD_R)` safe reset. `DF(3)` to MIDI. |
| 3 | **MIDI Chromatic** (36 notes, C to Cs2). Bottom row: `DF(0)`, velocity, sustain, all-notes-off, transpose ±, octave ±. |

---

### planck — Planck
**MCU:** ATmega32U4 · **Layout:** planck\_2x2u 4×12 (47 keys) · **MIDI:** Advanced

One row shorter than the Preonic. Identical layer structure to the Abacus but with the Planck 2×2U bottom row.

| Layer | Description |
|-------|-------------|
| 0 | **Dvorak.** Media play, `LT(1,←)` / `LT(2,→)`. |
| 1 | **Symbols/Numbers.** Digits, brackets, tap-tempo, media prev. |
| 2 | **Functions/Mouse.** F1–F12, mouse, brightness, media. `TD(TD_R)` safe reset. `DF(3)` to MIDI. |
| 3 | **MIDI Chromatic** (36 notes, C to Cs2). Bottom row: `DF(0)`, velocity, soft, sustain, all-notes-off, transpose ±, octave ±. |

---

### milk_crate — Milk Crate
**MCU:** ATmega32U4 · **Layout:** ortho 1×2 (2 keys) · **MIDI:** No

Minimal 2-key macropad by Nate Bunnyfield.

| Key | Action |
|-----|--------|
| Key 1 | `PHRASE` — types `hello world` |
| Key 2 | `Enter` |

---

### milk_crate_original
**Layout:** 1×2 (2 keys)

Predecessor to milk_crate. Bare keymap.

| Key | Action |
|-----|--------|
| Key 1 | `0` |
| Key 2 | `1` |

---

## Common Patterns

**Dvorak base** — all typing keyboards use Dvorak layout on layer 0.

**Safe reset** — `TD(TD_R)` requires triple-tap to enter bootloader, preventing accidental resets.

**MIDI switching** — `DF(3)` on the function layer switches the default layer to MIDI; `DF(0)` on the MIDI layer returns to Dvorak.

**MIDI chromatic layout** — consistent across Preonic/Abacus/Planck:
```
Row 0 (top):    D1  Ds1  E1  F1  Fs1  G1  Gs1  A1  As1  B1   C2  Cs2
Row 1 (mid):    G   Gs   A   As  B    C1  Cs1  D1  Ds1  E1   F1  Fs1
Row 2 (low):    C   Cs   D   Ds  E    F   Fs   G   Gs   A    As  B
```
Three octaves of chromatic notes with natural/sharp interleaved by row.

**Build commands:**
```
qmk flash -kb evyd13/pockettype -km natebunnyfield
qmk flash -kb preonic/rev3 -km natebunnyfield
qmk flash -kb planck/rev6_drop -km natebunnyfield
qmk flash -kb abacus -km natebunnyfield
qmk flash -kb milk_crate -km natebunnyfield
```
