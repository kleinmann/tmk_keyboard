/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "keycode.h"
#include "action.h"
#include "action_util.h"
#include "action_code.h"
#include "action_macro.h"
#include "action_layer.h"
#include "bootloader.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "ergodox.h"


/* ErgoDox keymap definition macro */
#define KEYMAP(                                                 \
                                                                \
    /* left hand, spatial positions */                          \
    k00,k01,k02,k03,k04,k05,k06,                                \
    k10,k11,k12,k13,k14,k15,k16,                                \
    k20,k21,k22,k23,k24,k25,                                    \
    k30,k31,k32,k33,k34,k35,k36,                                \
    k40,k41,k42,k43,k44,                                        \
                            k55,k56,                            \
                                k54,                            \
                        k53,k52,k51,                            \
                                                                \
    /* right hand, spatial positions */                         \
        k07,k08,k09,k0A,k0B,k0C,k0D,                            \
        k17,k18,k19,k1A,k1B,k1C,k1D,                            \
            k28,k29,k2A,k2B,k2C,k2D,                            \
        k37,k38,k39,k3A,k3B,k3C,k3D,                            \
                k49,k4A,k4B,k4C,k4D,                            \
    k57,k58,                                                    \
    k59,                                                        \
    k5C,k5B,k5A )                                               \
                                                                \
   /* matrix positions */                                       \
   {                                                            \
    { KC_##k00,KC_##k10,KC_##k20,KC_##k30,KC_##k40,KC_NO   },   \
    { KC_##k01,KC_##k11,KC_##k21,KC_##k31,KC_##k41,KC_##k51},   \
    { KC_##k02,KC_##k12,KC_##k22,KC_##k32,KC_##k42,KC_##k52},   \
    { KC_##k03,KC_##k13,KC_##k23,KC_##k33,KC_##k43,KC_##k53},   \
    { KC_##k04,KC_##k14,KC_##k24,KC_##k34,KC_##k44,KC_##k54},   \
    { KC_##k05,KC_##k15,KC_##k25,KC_##k35,KC_NO,   KC_##k55},   \
    { KC_##k06,KC_##k16,KC_NO,   KC_##k36,KC_NO,   KC_##k56},   \
                                                                \
    { KC_##k07,KC_##k17,KC_NO,   KC_##k37,KC_NO,   KC_##k57},   \
    { KC_##k08,KC_##k18,KC_##k28,KC_##k38,KC_NO,   KC_##k58},   \
    { KC_##k09,KC_##k19,KC_##k29,KC_##k39,KC_##k49,KC_##k59},   \
    { KC_##k0A,KC_##k1A,KC_##k2A,KC_##k3A,KC_##k4A,KC_##k5A},   \
    { KC_##k0B,KC_##k1B,KC_##k2B,KC_##k3B,KC_##k4B,KC_##k5B},   \
    { KC_##k0C,KC_##k1C,KC_##k2C,KC_##k3C,KC_##k4C,KC_##k5C},   \
    { KC_##k0D,KC_##k1D,KC_##k2D,KC_##k3D,KC_##k4D,KC_NO   }    \
   }

#if defined(KEYMAP_DVORAK)
#include "keymap_dvorak.h"
#elif defined(KEYMAP_COLEMAK)
#include "keymap_colemak.h"
#elif defined(KEYMAP_WORKMAN)
#include "keymap_workman.h"
#elif defined(KEYMAP_MICRO)
#include "keymap_micro.h"
#elif defined(KEYMAP_CUB)
#include "keymap_cub.h"
#elif defined(KEYMAP_KLEINMANN)
#include "keymap_kleinmann.h"
#else

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

#endif


#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    if (layer < KEYMAPS_SIZE) {
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}

#if defined(KEYMAP_CUB)

// function keymap_fn_to_action will be defined in keymap_cub.h

#else
/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    action_t action;
    if (FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    } else {
        action.code = ACTION_NO;
    }
    return action;
}
#endif

