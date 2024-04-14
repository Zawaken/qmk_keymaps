# QMK Keyboard Layouts

#### These keyboard layouts are work in progress and will definitely be tweaked more when I find out I want to add features.
#### I will also add more keyboards to this repo whenever I get new ones.


Flash script shamelessly stolen and rewritten from [ai212983](https://github.com/ai212983)


## TODO:
* Lower/Raise on hold, space on tap, does not allow going to the ADJUST layer.


## Building/flashing zmk keyboards
```sh
nix develop # Takes a while, because Zephyr-sdk is huuge, when in the nix develop shell, continue
west init -l zmk-keymaps
west update
west zephyr-export
west build -p -s "$(pwd)/zmk/app" -b "lpgalaxy_blank_slate" -- -DZMK_CONFIG="$(pwd)/zmk-keymaps"
```
