// Inspiration from https://gist.github.com/ordnungswidrig/c0e67fa538fc6ec4881d

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( // Layer 0
    // Left hand
    NUBS, 1, 2, 3, 4, 5, EQL,
    TAB, Q, W, E, R, T, FN1,
    ESC, A, S, D, F, G,
    LSFT, Z, X, C, V, B, FN0,
    LCTL, GRV, NO, LALT, LGUI,

    INS, HOME, // top of thumb cluster
    END, SPC, LSFT, FN4, // right small, left large, right large, bottom small

    // Right hand
    BSPC, 6, 7, 8, 9, 0, MINS,
    FN6, Y, U, I, O, P, LBRC,
    H, J, K, L, SCLN, QUOT,
    FN0, N, M, COMM, DOT, SLSH, RSFT,
    RGUI, RALT, RBRC, NUHS, NUBS,

    LEFT, RGHT, // top of thumb cluster
    UP, DOWN, FN5, BSPC), // top small, bottom small, left large, right large
  KEYMAP( // Layer 1
    FN3, F1, F2, F3, F4, F5, F6,
    TRNS, TRNS, TRNS, MPRV, MPLY, MNXT, FN1,
    TRNS, TRNS, TRNS, VOLD, VOLU, MUTE,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    FN2, TRNS, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS,

    // Right hand
    F7, F8, F9, F10, F11, F12, TRNS,
    FN1, TRNS, TRNS, UP, TRNS, TRNS, TRNS,
    TRNS, LEFT, DOWN, RGHT, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, DEL, TRNS),
  KEYMAP( // Layer 2
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS,

    TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS,

    // Right hand
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    GRV, SCLN, QUOT, RBRC, NUHS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
    TRNS, TRNS, TRNS, TRNS, TRNS,

    TRNS, DEL,
    PGUP, PGDOWN, TRNS, TRNS),
  KEYMAP( // Layer 3, Colemak
    // Left hand
    NUBS, 1, 2, 3, 4, 5, EQL,
    TAB, Q, W, F, P, G, FN1,
    ESC, A, R, S, T, D,
    LSFT, Z, X, C, V, B, FN0,
    LCTL, GRV, NO, LALT, LGUI,

    INS, HOME, // top of thumb cluster
    END, SPC, LSFT, FN4, // right small, left large, right large, bottom small

    // Right hand
    BSPC, 6, 7, 8, 9, 0, MINS,
    FN6, J, L, U, Y, SCLN, LBRC,
    H, N, E, I, O, QUOT,
    FN0, K, M, COMM, DOT, SLSH, RSFT,
    RGUI, RALT, RBRC, NUHS, NUBS,

    LEFT, RGHT, // top of thumb cluster
    UP, DOWN, FN5, BSPC), // top small, bottom small, left large, right large
};
enum function_id {
  TEENSY_KEY,
};


static const uint16_t PROGMEM fn_actions[] = {
  ACTION_LAYER_MOMENTARY(1),
  ACTION_LAYER_TOGGLE(1),
  ACTION_FUNCTION(TEENSY_KEY),
  ACTION_LAYER_MOMENTARY(1),
  ACTION_LAYER_TOGGLE(2),
  ACTION_LAYER_TAP_KEY(2, KC_ENT),
  ACTION_LAYER_TOGGLE(3),
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
