# Keyboardio Preonic: keymap backups and CLI recipe

The Preonic on this desk is the **Keyboardio** Preonic (USB `0x3496:0x00A1`,
vendor name "Keyboardio"), running Kaleidoscope `0.93.0+128`. It is NOT the
OLKB/Drop Preonic that `~/src/qmk_firmware/keyboards/preonic` builds for: QMK
resets (`TD(TD_R)`, bootmagic) and the `preonic_rev3` `.bin` do not apply to it.
Never flash the QMK bin onto it.

## CLI

`focus` / `focus-send` from keyboardio/kaleidoscope-focus.rs, release `latest`
(2022-10-23), macOS universal binary, installed 2026-10-30 at
`~/.local/opt/kaleidoscope-focus/`, symlinked into `~/.local/bin/`.

The tool predates this board, so auto-detect fails ("No supported devices
found"). Always pass the port:

```bash
focus-send -d /dev/cu.usbmodem11101 help
focus backup -d /dev/cu.usbmodem11101 -q > preonic-backup-YYYY-MM-DD.json
focus-send -d /dev/cu.usbmodem11101 keymap.custom              # read
focus-send -d /dev/cu.usbmodem11101 keymap.custom <648 values>  # write
```

The port name can change; find it with `ioreg -r -c IOUSBHostDevice -l -w0 -n Preonic | grep IOCalloutDevice`.

## Keymap layout

`keymap.custom` is 648 decimal values = 9 layers x 72 keys (matrix 6 rows x 12
cols, from `Preonic.h` `PreonicKeyScannerProps`). Index = layer*72 + row*12 + col.
Rows 1-5 line up with the 5 QMK rows; the bottom row is row 5.

## Key codes (from Kaleidoscope source, verified against values on the board)

| Key | Raw |
|---|---|
| Consumer key | `0x4800 | usage` (SYNTHETIC\|IS_CONSUMER) |
| Play/Pause | `0x48CD` |
| Next track | `0x48B5` |
| Previous track | `0x48B6` |
| Volume up / down | `0x48E9` / `0x48EA` |
| Mouse left / right / middle click | `0x5041` / `0x5042` / `0x5044` |
| Mouse move up/down/left/right | `0x5001` / `0x5002` / `0x5004` / `0x5008` |
| Scroll up / down | `0x5011` / `0x5012` |

## Changes

- 2026-10-30: layers 0/1/2, row 5 col 1: Play/Pause, Prev, Next -> left, right,
  middle click (matches the QMK Planck). Read back and verified. Before/after in
  `keymap.custom.before.txt` / `keymap.custom.readback.txt`; full config backup
  taken first in `preonic-backup-2026-10-30.json`. To undo:
  `focus-send -d <port> keymap.custom $(cat keymap.custom.before.txt)`.
