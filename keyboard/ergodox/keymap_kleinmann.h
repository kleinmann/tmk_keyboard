static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( // Layer 0
    // Left hand
    ESC, 1, 2, 3, 4, 5, EQL,
    TAB, Q, W, E, R, T, FN6,
    ESC, A, S, D, F, G,
    LSFT, Z, X, C, V, B, FN1,
    LCTL, GRV, NO, LALT, LGUI,

    INS, HOME, // top of thumb cluster
    END, SPC, DEL, LGUI, // right small, left large, right large, bottom small

    // Right hand
    BSPC, 6, 7, 8, 9, 0, MINS,
    FN6, Y, U, I, O, P, LBRC,
    H, J, K, L, SCLN, QUOT,
    FN1, N, M, COMM, DOT, SLSH, RSFT,
    RGUI, RALT, RBRC, NUHS, FN3,

    PGUP, DEL, // top of thumb cluster
    PGDN, RGUI, ENT, BSPC), // top small, bottom small, left large, right large
  KEYMAP( // Layer 1
    TRNS, F1, F2, F3, F4, F5, F6,
    TRNS, TRNS, TRNS, MPRV, MPLY, MNXT, TRNS,
    TRNS, TRNS, TRNS, VOLD, VOLU, MUTE,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    FN7, TRNS, TRNS, LALT, LGUI,

    TRNS, TRNS,
    TRNS, LCTL, LSFT, TRNS,

    // Right hand
    F7, F8, F9, F10, F11, F12, MINS,
    TRNS, TRNS, FN10, FN11, TRNS, TRNS, RBRC,
    FN12, FN8, FN9, FN13, TRNS, TRNS,
    TRNS, TRNS, FN15, FN16, TRNS, TRNS, TRNS,
    RGUI, RALT, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, RSFT, RCTL),
  KEYMAP( // Layer 2
    NO, NO, NO, NO, NO, NO, NO,
    NO, NO, NO, NO, NO, NO, TRNS,
    NO, NO, NO, NO, NO, NO,
    NO, NO, NO, NO, NO, NO, TRNS,
    TRNS, NO, NO, NO, NO,

    TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS,

    NO, NO, NO, NO, NO, NO, NO,
    TRNS, HOME, PGDN, PGUP, END, NO, NO,
    LEFT, DOWN, UP, RGHT, NO, NO,
    TRNS, NO, NO, NO, NO, NO, NO,
    NO, NO, NO, NO, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS),
  KEYMAP( // Layer 3
    TRNS, NO, NO, NO, NO, NO, NO,
    TRNS, F13, F14, F15, F16, NO, TRNS,
    TRNS, F17, F18, F19, F20, NO,
    TRNS, F21, F22, F23, F24, NO, TRNS,
    TRNS, TRNS, TRNS, LALT, LGUI,

    TRNS, TRNS,
    TRNS, LCTL, LSFT, TRNS,

    NO, NO, NO, NO, NO, NO, TRNS,
    TRNS, NO, BTN1, BTN2, F3, F4, TRNS,
    MS_L, MS_D, MS_U, MS_R, F8, TRNS,
    TRNS, WH_L, WH_D, WH_U, WH_R, F12, TRNS,
    RGUI, RALT, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, RSFT, RCTL),
  KEYMAP( // Layer 4
    TRNS, F1, F2, F3, F4, F5, F6,
    FN7, NO, PGUP, UP, PGDN, PGUP, TRNS,
    TRNS, NO, LEFT, DOWN, RGHT, PGDN,
    TRNS, NO, NO, END, HOME, NO, TRNS,
    FN5, TRNS, TRNS, LALT, LGUI,

    TRNS, TRNS,
    TRNS, LCTL, LSFT, TRNS,

    F7, F8, F9, F10, F11, F12, MINS,
    TRNS, PGUP, PGUP, UP, PGDN, NO, FN7,
    PGDN, LEFT, DOWN, RGHT, NO, TRNS,
    TRNS, NO, HOME, END, NO, NO, TRNS,
    RGUI, RALT, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, RSFT, RCTL),
  KEYMAP( // Layer 5
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, Q, D, R, W, B, TRNS,
    TRNS, A, S, H, T, G,
    TRNS, Z, X, M, C, V, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS,

    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, J, F, U, P, 4, TRNS,
    Y, N, E, O, I, TRNS,
    TRNS, K, L, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS)
};
enum function_id {
  TEENSY_KEY,

};


static const uint16_t PROGMEM fn_actions[] = {
  ACTION_DEFAULT_LAYER_SET(0),
  ACTION_LAYER_MOMENTARY(1),
  ACTION_DEFAULT_LAYER_SET(2),
  ACTION_LAYER_MOMENTARY(3),
  ACTION_LAYER_MOMENTARY(4),
  ACTION_DEFAULT_LAYER_SET(5),
  ACTION_LAYER_MOMENTARY(2),
  ACTION_FUNCTION(TEENSY_KEY),
  ACTION_MODS_KEY(MOD_RSFT, KC_8),
  ACTION_MODS_KEY(MOD_RSFT, KC_9),
  ACTION_MODS_KEY(MOD_RALT, KC_5),
  ACTION_MODS_KEY(MOD_RALT, KC_6),
  ACTION_MODS_KEY(MOD_RALT, KC_8),
  ACTION_MODS_KEY(MOD_RALT, KC_9),
  ACTION_MODS_KEY(MOD_RALT, KC_7),
  ACTION_MODS_KEY(MOD_RALT|MOD_RSFT, KC_7),
  ACTION_MODS_KEY(MOD_RSFT, KC_7),
};


void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
