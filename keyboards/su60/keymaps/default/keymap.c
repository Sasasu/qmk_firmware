#include QMK_KEYBOARD_H

#define MO_TOFN MO(FN_LAYER)
#define MO_TOMO MO(MA_LAYER)

enum su60_layers {
    QW_LAYER,
    FN_LAYER,
    MA_LAYER,
};

enum su60_macros {
    MA_WHERE_AM_I = SAFE_RANGE,
    MA_CLR,
};

#define MA_WAMI MA_WHERE_AM_I

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QW_LAYER] = LAYOUT(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        MO_TOFN, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT ,
        KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX, KC_RSFT, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, KC_SPC , XXXXXXX, KC_RALT, MO_TOMO, XXXXXXX, KC_APP , KC_RCTL
    ),

    [FN_LAYER] = LAYOUT(
        KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL,
        _______, KC_BTN4, KC_UP  , KC_BTN5, _______, _______, _______, KC_WH_U, KC_WH_D, KC_PGUP, KC_PGDN, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______,
        _______, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, KC_PSCR, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [MA_LAYER] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, MA_WAMI, MA_CLR , _______, _______, _______, _______, _______, _______, _______, KC_PWR , _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MA_WHERE_AM_I:
            if (record->event.pressed) {
                SEND_STRING("ps -aux | grep -v -P \"\\[\" && w");
            }
            break;
        case MA_CLR:
            if (record->event.pressed) {
                SEND_STRING("clear && tmux clear-history");
            }
            break;
        default:
            break;
    }
    return true;
}
