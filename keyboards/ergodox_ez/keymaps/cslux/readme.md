# ErgoDox EZ Default Configuration

## Changelog

qmk json2c ~/Downloads/ergodox_ez-base-davrok-qwerty-v35.json


``` bash
# wally https://github.com/zsa/wally/releases
# qmk pip install qmk
ae pyenv3

# clone to ./qmk_firmware
qmk clone

# setup qmk_firmware
qmk setup -H $(pwd)/qmk_firmware

# convert to keymap.c
qmk json2c keyboards/ergodox_ez/keymaps/cslux/cslux.json

# convert to json -- can be used to modify layouts via the website (https://config.qmk.fm)
qmk c2json -km cslux -kb ergodox_ez/base keyboards/ergodox_ez/keymaps/cslux/keymap.c --no-cpp > cslux.json

# compile and start flasher (wally)
qmk compile && wally
```
