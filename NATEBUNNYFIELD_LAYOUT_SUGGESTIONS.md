# natebunnyfield layout suggestions

Date: 2026-10-30. Commit surveyed: `84c8968527`, plus the uncommitted working-copy edits
to the Planck, Preonic and PocketType keymaps (today's bottom-row click change and the
PocketType TR-key rotation). Suggestions only; nothing here has been applied or compiled.

Line numbers below are into the working copy. Only `keymap.c` is compiled; the
`keymap_default.c` files and the commented-out blocks (Preonic 57-91, PocketType 20-78)
are old reference and are not counted as live.

Boards read:

- `keyboards/planck/keymaps/natebunnyfield/keymap.c` (planck/rev6_drop, `LAYOUT_planck_2x2u`)
- `keyboards/preonic/keymaps/natebunnyfield/keymap.c` (preonic/rev3, `LAYOUT_preonic_2x2u`)
- `keyboards/abacus/keymaps/natebunnyfield/keymap.c` (3x12 + 2.75u thumbs, `LAYOUT`)
- `keyboards/evyd13/pockettype/keymaps/natebunnyfield/keymap.c` (`LAYOUT_ortho_4x12`)
- `keyboards/milk_crate/keymaps/natebunnyfield/keymap.c` (1x2)

Physical facts that drive the ergonomics claims (from the `keyboard.json` geometry):

- Planck/Preonic bottom row is 10 keys: cols 0-3 are 1u, then a 2u at cols 4-5 (Space),
  a 2u at cols 6-7 (Backspace), then 1u at cols 8-11. Both layer keys `LT(1,KC_LEFT)` /
  `LT(2,KC_RGHT)` sit at cols 8 and 9 (planck:28, preonic:99), i.e. directly right of the
  right 2u. Both layers are therefore held by the RIGHT thumb; every layer action is
  "right thumb + some finger".
- Abacus bottom row is 9 keys: cols 0-2 1u, two 2.75u thumbs, then four 1u. There is no
  "position 2" spare key, so the new unlayered left click does not exist there (abacus:28).

## Top 5

### 1. Preonic layers 4-11 and PocketType layers 1-11 are unreachable: wire them or delete them

Evidence: the only layer-switching keycodes in the live keymaps are `LT(1,…)`, `LT(2,…)`,
`DF(3)` and `DF(0)` (planck:28,38,43; preonic:99,111,117,123,129; abacus:28,38,43).
PocketType's live keymap (pockettype:118-191) has zero layer keys. So:

- Preonic layer 4 "MIDI guitar" (preonic:118-123) and layer 5 "chromatic alt"
  (preonic:124-129) can never be entered. Their `DF(0)` keys only matter if you got there.
- Preonic layers 6-11 (preonic:130-165) are all-transparent and unreachable: 6 x 62 x 2 =
  744 bytes of PROGMEM on an ATmega32U4 doing nothing.
- PocketType layers 1-11 (pockettype:125-190) are unreachable. They are per-key voicings,
  which is exactly what the `TR_*` keys now do at runtime by setting
  `midi_config.transpose`/`octave` (pockettype:102-113). The transposition approach made
  them redundant. The overview `NATEBUNNYFIELD_KEYMAPS.md` describes them as if live.

Suggestion, Preonic, if you want layers 4 and 5 back: give them switches on layer 2's
top row, which is currently transparent and falls through to `KC_VOLD`/`KC_VOLU` at
cols 4-5 (preonic:95) - volume that layer 2 already has at row 2 cols 5-6 (preonic:109).

```
// preonic layer 2, row 0 (top), before (preonic:107)
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// after
        _______, _______, _______, _______, DF(4),   DF(5),   _______, _______, _______, _______, _______, _______,
```

Suggestion, if you do not want them: delete Preonic 118-165 and PocketType 125-190
(git keeps the voicings). Either way the overview doc should stop listing them as live.

Argued against: "maybe they are kept for later." They cost flash and mislead the doc;
git history preserves them for free. Survives. Choose wire-or-delete, not keep-as-is.

### 2. Bring play/prev/next back on layer 2's right home row, identical on Planck, Preonic, Abacus

Today's change replaced `KC_MPLY`/`KC_MPRV`/`KC_MNXT` with `MS_BTN1/2/3` at bottom col 1
(planck:28,33,38; preonic:99,105,111). Volume survived on layer 2 (planck:36 cols 5-6;
preonic:109; abacus:36). Layer 2 has five empty transparent slots right next to volume:
row 1 cols 7-11 (planck:36, preonic:109, abacus:36). Putting media there keeps "sound
stuff" in one row and lands at the same matrix position on all three boards.

```
// planck layer 2, row 1, before (planck:36)
        _______, MS_LEFT, MS_RGHT, MS_UP,   MS_DOWN, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,
// after
        _______, MS_LEFT, MS_RGHT, MS_UP,   MS_DOWN, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______,
```

Same row on Preonic (preonic:109, the LCTL row) and Abacus (abacus:36). Keycodes:
`KC_MPRV`, `KC_MPLY`, `KC_MNXT`, `KC_MUTE`.

Tradeoff: the layer is held by the right thumb at col 9 and H/T/N (cols 7-9) are the
right hand's home keys - a tight but normal chord. On the Preonic you could instead put
them unlayered on the top row (see smaller ideas) but that breaks cross-board parity.

Argued against: "he removed media on purpose today." He removed them because he wanted
that physical key for a click, not because media was unwanted (volume was kept). Spare
layer-2 slots cost nothing. macOS honors consumer-page MPLY/MPRV/MNXT from any HID
keyboard (Music, Spotify, browsers). Survives.

### 3. Layer 2 bottom row: the duplicate `MS_BTN3` at col 8 should become `KC_HOME`

After today's change, Planck/Preonic layer 2's bottom row has `MS_BTN3` twice: col 1 (the
new click column) and col 8 (planck:38, preonic:111). Col 8 is also the position of
`LT(1,KC_LEFT)`, right beside the thumb holding `LT(2)` at col 9, so it is awkward to hit
while in mouse mode anyway.

Separately, `KC_END` exists (layer 1 col 9: planck:33, preonic:105, abacus:33) but there
is no `KC_HOME` on any board (grep: zero hits in live keymaps). The mirror slot is free.
"Hold one layer key, tap the other" then gives HOME/END as a pair.

```
// planck layer 2, bottom row, before (planck:38)
        DF(3),   MS_BTN3, _______, _______, MS_BTN1, MS_BTN2, MS_BTN3,          KC_NO,            MS_WHLD, MS_WHLU),
// after
        DF(3),   MS_BTN3, _______, _______, MS_BTN1, MS_BTN2, KC_HOME,          KC_NO,            MS_WHLD, MS_WHLU),
```

Same for Preonic (preonic:111). NOT for Abacus: abacus:38 has no col-1 click, so its
`MS_BTN3` after the thumbs is the only middle click; leave it.

Tradeoff: none functional; `MS_BTN3` stays at col 1 on layer 2. If HOME is useless to you
on macOS, `KC_MPLY` is the other candidate for this slot.

Argued against: HOME/END are rare on macOS. True, but they do work in Terminal/tmux and
the key is otherwise a duplicate. Survives (low stakes).

### 4. Right Shift as `MT(MOD_RSFT, KC_ENT)`; do NOT add home-row mods at `TAPPING_TERM 115`

Current mods are left-only: `KC_LCTL` (caps position), `KC_LSFT`, `KC_LALT`, `KC_LGUI`
(planck:26-28, preonic:97-99, abacus:26-28). Every left-hand capital (A O E U I P Y Q J K X
in Dvorak) is a same-hand pinky chord. The right pinky key at the Shift row is `KC_ENT`
(planck:27 col 11), which is where a right Shift would live anyway.

```
// planck layer 0, row 2, before (planck:27)
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
// after
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    MT(MOD_RSFT, KC_ENT),
```

Same on Preonic (preonic:98) and Abacus (abacus:27). Layers 1-2 are transparent there
(planck:32,37) and layer 3 overrides it with `MI_B`, so MIDI is unaffected.

Tradeoff, and it is real: with `TAPPING_TERM 115` (planck config.h:55, preonic:54,
abacus:7), an Enter held longer than 115 ms and released with no other key sends NOTHING
(mod-tap hold with no key = bare Shift press/release). Firm Enter presses can exceed
115 ms. So this only works with a per-key term, e.g. in each keymap.c:

```c
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return keycode == MT(MOD_RSFT, KC_ENT) ? 200 : TAPPING_TERM;
}
```

(`DYNAMIC_TAPPING_TERM_ENABLE` is already on; `g_tapping_term` can replace `TAPPING_TERM`
there if you want DT_UP/DOWN to keep tuning the base.) Enter auto-repeat is lost; you
already accepted that for Left/Right on the LT keys.

Home-row mods: not worth it here. Typing dwell times are routinely 80-150 ms, so at 115 ms
HRMs would misfire as modifiers constantly; fixing that means raising the global term to
170-220 ms plus `PERMISSIVE_HOLD`, which changes the feel of the LT arrow keys you have
tuned with DT_UP/DT_DOWN. One MT on a key that is rarely rolled (Enter) is the safe subset.

Argued against: "Shift+Enter in Slack/Messages." Still works: hold left Shift, tap the MT
key; a tap under a held mod resolves to Enter. Survives, conditional on the per-key term.

### 5. MIDI layer: move `MI_AOFF` off the right 2u thumb

Planck/Preonic layer 3 bottom row (planck:43, preonic:117):
`DF(0), MI_VELD, MI_VELU, MI_SOFT, MI_SUST (2u), MI_AOFF (2u), MI_TRSD, MI_TRSU, MI_OCTD, MI_OCTU`.
Sustain on the left thumb is right; all-notes-off on the other prime thumb key means the
easiest key to hit while playing is the panic button, and the soft pedal is a 1u reach.

```
// planck layer 3, bottom row, before (planck:43)
        DF(0),   MI_VELD, MI_VELU, MI_SOFT, MI_SUST, MI_AOFF, MI_TRSD,          MI_TRSU,          MI_OCTD, MI_OCTU),
// after
        DF(0),   MI_VELD, MI_VELU, MI_AOFF, MI_SUST, MI_SOFT, MI_TRSD,          MI_TRSU,          MI_OCTD, MI_OCTU),
```

Two pedals under two thumbs, panic at col 3 (still one key, still reachable). Abacus
(abacus:43) has 9 keys and no `MI_SOFT`; its `MI_AOFF` on the right thumb could swap with
`MI_SUST` only if you want sustain on the right, so leave it unless you adopt this.

Tradeoff: muscle memory for the panic key. Argued against: "panic should be the biggest
key." Defensible; this one is a preference call, ranked last for that reason. Survives
only as an option.

## Smaller ideas

- **Preonic top row (preonic:95)** `MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, KC_VOLD, KC_VOLU,
  MS_LEFT, MS_RGHT, MS_UP, MS_DOWN, MS_WHLU, MS_WHLD`. Col 0 `MS_BTN1` is now an exact
  unlayered duplicate of bottom col 1 (preonic:99). Keep `MS_BTN2`/`MS_BTN3` up there:
  they are the only clicks that work while the RIGHT hand is on the top-row movement keys
  (cols 6-9), since the layered clicks need the right hand on `LT(1)`/`LT(2)`. Col 0 is
  the one free slot: `KC_MPLY` or `KC_MUTE` if you want one unlayered media key.
- **Abacus parity**: layer 2 row 2 cols 5-6 are `_______` (abacus:37) where Planck/Preonic
  have `KC_BRID, KC_BRIU` (planck:37, preonic:110). Add them so the function layer is the
  same shape on all three.
- **Left-thumb layer key** (the only way to make layers two-handed): swap `KC_LGUI` (col 3)
  with `LT(1,KC_LEFT)` (col 8) on planck:28/preonic:99/abacus:28. Cost: the bottom-right
  `LEFT RIGHT UP DOWN` cluster breaks and Cmd moves to the right hand, on three boards plus
  whatever the Geonix mirrors. Not ranked because the muscle-memory cost likely exceeds
  the gain; do NOT use `LT(1,KC_SPC)`: at 115 ms a held Space would be dropped.
- **Esc as `MT(MOD_LCTL, KC_ESC)`** at the Ctrl position (planck:26 col 0) would free
  bottom-left `KC_ESC` (planck:28 col 0) for another key. Same per-key-term caveat as
  suggestion 4; and `DF(3)`/`DF(0)` live at that bottom-left position on layers 2/3
  (planck:38,43), so it would need a new home. Low value; listed for completeness.
- **Doc nits** in `NATEBUNNYFIELD_KEYMAPS.md`: the chromatic layers are 36/48 KEYS but
  26/31 unique notes (rows are offset by a fifth, so each row repeats five notes of the
  one below: planck:40-42 row 1 cols 0-4 = row 2 cols 7-11). Call it the isomorphic
  fifths layout it is. Preonic/PocketType layer tables list unreachable layers as live.
- **Build-config portability**: Abacus and PocketType rely on edits to the KEYBOARD-level
  `rules.mk` (`keyboards/abacus/rules.mk:17-19` TAP_DANCE/DYNAMIC_TAPPING_TERM/MIDI,
  `keyboards/evyd13/pockettype/rules.mk:12` MIDI_ENABLE), not the keymap directory. A
  rebase onto upstream can silently drop them. Moving those lines into
  `keymaps/natebunnyfield/rules.mk` (as Planck/Preonic already do) is a one-line-each fix.
- **Geonix (VIA, not visible here)**: what carries over from this review is the layer-2
  media row (suggestion 2), HOME opposite END (3) and `MT(MOD_RSFT, KC_ENT)` (4) - VIA
  supports LT/MT/DF/mouse keys. The tap-dance safe reset and all MIDI do not exist in VIA,
  so those stay firmware-only.

## Checked and judged fine

- **Today's click scheme** (layer 0 -> BTN1, layer 1 -> BTN2, layer 2 -> BTN3 at bottom
  col 1; planck:28,33,38; preonic:99,105,111) is a clean mnemonic; I considered swapping
  layer 2's col 1 to BTN2 for mouse-mode convenience and rejected it as breaking the
  mnemonic for marginal gain.
- **`KC_NO` at planck:33 col 8 and planck:38 col 9** (and preonic:105/111, abacus:33/38)
  are each the held layer key's own slot; they are never looked up while the layer is
  held. Not wasted keys.
- **Layer-2 mouse mode** (right thumb holds col 9; A/O/E/U move; Space = BTN1; wheel at
  cols 10-11) is coherent. `KC_LALT`/`KC_LGUI`/`KC_LSFT` are transparent on layer 2
  (planck:36-38), so Cmd-click / Shift-click / Option-click all work in mouse mode. Keep
  them transparent.
- **Mouse-key tuning** (config.h: `MOUSEKEY_INERTIA`, `MOVE_DELTA 1`, `INTERVAL 12`,
  `MAX_SPEED 32`, `TIME_TO_MAX 32`, `FRICTION 30`) matches the inertia-mode defaults in
  `quantum/mousekey.h:40-44,67,74` apart from slightly higher friction; `MS_ACL*` keys are
  correctly absent since acceleration keys are ignored in inertia mode
  (`docs/features/mouse_keys.md:218`).
- **Arrow order** `LEFT RIGHT UP DOWN` (planck:28 cols 8-11) is unusual but matches the
  layer-2 mouse order `MS_LEFT MS_RGHT MS_UP MS_DOWN` (planck:36) and `PGUP PGDN` sit
  under `UP DOWN` on layer 1 (planck:33). Internally consistent; leave it.
- **LT on arrows at 115 ms**: short term means a fast roll of layer key + digit resolves
  correctly; the only cost is no auto-repeat on Left/Right, already accepted.
- **Safe reset**: `TD(TD_R)` triple-tap (planck:8-17, preonic:8-17, abacus:8-17) sits
  on layer 2 at the Tab position, so it needs right-thumb layer hold plus three taps within
  the tapping term. No bare `QK_BOOT` anywhere live. PocketType has no software reset at
  all; bootmagic is on (`pockettype/keyboard.json` features.bootmagic true) so holding
  (0,0) = `TR_F` at plug-in enters the bootloader. Adequate for a board with no spare key.
- **MIDI note-off safety with TR keys**: `process_midi.c:85-88` sends note-off using the
  note stored at press time, so changing `midi_config.transpose`/`octave` with a `TR_*`
  key while notes are held does not strand notes. PocketType ranges checked: highest key
  `MI_F5` at `MI_OC0` = MIDI 89, lowest `MI_C1` with `TR_G` (-5) = MIDI 31; all in 0-127.
- **PocketType TR grid** (pockettype:120-123, today's rotation): col 2 = C G D A, col 1 =
  E B Gb Db, col 0 = Ab Eb Bb F, bottom to top - the circle of fifths snakes outward from
  the note keys. Just rebuilt today; not touched.
- **Symbol layer** (planck:30-31): bracket pairs `< > ( ) [ ] { }` adjacent and ordered,
  `KC_BSLS`/`KC_EQL` at col 11, digits on the top row; tap-tempo `DT_UP/DT_DOWN/DT_PRNT`
  on left home keys. Fine.
- **Milk Crate** (`PHRASE` + `KC_ENT`): nothing to say.

## Method

```
git -C ~/src/qmk_firmware rev-parse --short HEAD      # 84c8968527
git -C ~/src/qmk_firmware status --short              # planck/preonic/pockettype keymaps modified
cat -n keyboards/{planck,preonic,abacus,evyd13/pockettype,milk_crate}/keymaps/natebunnyfield/*
python3: parse keyboard.json layouts for key x/w per row (2x2u geometry, abacus 2.75u)
grep 'DF(\|TO(\|MO(\|LT(' across live keymaps        # layer reachability
grep KC_HOME/KC_MPLY/KC_MUTE across live keymaps      # none live
sed -n 40,135p quantum/process_keycode/process_midi.c # note-off uses stored note
grep MOUSEKEY defaults in quantum/mousekey.h; inertia docs in docs/features/mouse_keys.md
```

Limits: no compile was run; ergonomics claims are from geometry plus the stated typing
habits, not from watching him type; the Geonix VIA layout was not visible.
