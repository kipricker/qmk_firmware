#include "66.h"

#ifdef ENABLE_RGBLIGHT
#include "rgblight.h"
#endif

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _RS 2
#define _ML 3
#define _NL 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |    `|   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   =| BS| Del|  |PGUP|
   * |--------------------------------------------------------------------------|  |----|
   * |   Tab|   Q|   W|   E|   R|   T|   Y|   U|   I|   O|   P|   [|   ]|      \|  |PGDN|
   * |--------------------------------------------------------------------------|  `----'
   * |   Esc|   A|   S|   D|   F|   G|   H|   J|   K|   L|   ;|   '|   # |  Ent|
   * |-----------------------------------------------------------------------------.
   * |_FL| Shift|   Z|   X|   C|   V|   B|   N|   M|   ,|   .|   /|  Shift|_FL|  Up|
   * |------------------------------------------------------------------------|----|----.
   * | Ctrl|  Alt|  Gui|     |    Shift|    Space|     |  Gui|  Alt| Ctrl|Left|Down|Rght|
   * `----------------------------------------------------------------------------------'
   */
[_BL] = KEYMAP(
  KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,   KC_DEL,         KC_PGUP, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,                   KC_PGDN, \
  KC_ESC,  KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                             \
  MO(_FL), KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  MO(_FL),          KC_UP,            \
  KC_LCTL, KC_LALT, KC_LGUI,MO(_NL),        KC_LSFT,KC_SPC,                          MO(_ML),  KC_RGUI,  KC_RALT,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,--------------------------------------------------------------------------.  ,----.
   * | Esc|  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12|    | Del|  |BLIN|
   * |--------------------------------------------------------------------------|  |----|
   * |      |    |    |    |    |    |    |    |PScr|SLck|Paus|    |    |       |  |BLDE|
   * |--------------------------------------------------------------------------|  `----'
   * |Capslck|    | _RS|    |    |    |    |    |    |    |    |    |     |     |
   * |-----------------------------------------------------------------------------.
   * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |PGUP|
   * |------------------------------------------------------------------------|----|----.
   * |     |     |     |     |         |         |     |     |     |  _FL|HOME|PGDN| END|
   * `----------------------------------------------------------------------------------'
   */
[_FL] = KEYMAP(
  KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_TRNS, KC_BSPC,           BL_STEP, \
  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_SLCK, KC_PAUS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                   KC_TRNS, \
  KC_CAPS, KC_TRNS, MO(_RS),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                           \
  MO(_FL), KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(_FL),          KC_PGUP,         \
  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,        KC_TRNS,KC_TRNS,                         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_HOME, KC_PGDN, KC_END),

  /* Keymap _RS: Reset/Underlight layer
   * ,--------------------------------------------------------------------------.  ,----.
   * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  |    |
   * |--------------------------------------------------------------------------|  |----|
   * |      |    |    |    |RESET|   |    |    |    |    |    |    |    |       |  |    |
   * |--------------------------------------------------------------------------|  `----'
   * |       |    | _RS|    |    |    |    |    |    |    |    |    |     |     |
   * |-----------------------------------------------------------------------------.
   * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |    |
   * |------------------------------------------------------------------------|----|----.
   * |     |     |     |     |         |         |     |     |     |  _FL|    |    |    |
   * `----------------------------------------------------------------------------------'
   */
[_RS] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, F(0),             F(6), \
  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                   F(7), \
  KC_TRNS, KC_TRNS, MO(_RS),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                         \
  MO(_FL), KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(_FL),          F(4),          \
  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,        F(1),   F(1),                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, F(3),    F(5),    F(2)),


/* Keymap _ML: Media layer
 * ,--------------------------------------------------------------------------.  ,----.
 * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  |    |
 * |--------------------------------------------------------------------------|  |----|
 * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |  |    |
 * |--------------------------------------------------------------------------|  `----'
 * |       |    |    |    |    |    |    |    |    |    |    |    |     |     |
 * |-----------------------------------------------------------------------------.s
 * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |    |
 * |------------------------------------------------------------------------|----|----.
 * |     |     |     |     |         |         |     |     |     |     |    |    |    |
 * `----------------------------------------------------------------------------------'
 */
[_ML] = KEYMAP(
KC_TRNS, KC_SLCK, KC_PAUS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MPRV,KC_MPLY,KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS, KC_TRNS,          KC_POWER,  \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                   KC_TRNS,  \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                         \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,          \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,        KC_TRNS,KC_TRNS,                         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


/* Keymap _: NumPad layer
 * ,--------------------------------------------------------------------------.  ,----.
 * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  |    |
 * |--------------------------------------------------------------------------|  |----|
 * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |  |    |
 * |--------------------------------------------------------------------------|  `----'
 * |       |    |    |    |    |    |    |    |    |    |    |    |     |     |
 * |-----------------------------------------------------------------------------.s
 * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |    |
 * |------------------------------------------------------------------------|----|----.
 * |     |     |     |     |         |         |     |     |     |     |    |    |    |
 * `----------------------------------------------------------------------------------'
 */
[_NL] = KEYMAP(
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NLCK,KC_PSLS,KC_PAST, KC_PMNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_P7,  KC_P8,  KC_P9, KC_PPLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                   KC_TRNS, \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_P4,  KC_P5,  KC_P6, KC_PENT,  KC_TRNS,  KC_TRNS,  KC_TRNS,                         \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_P1,  KC_P2,  KC_P3, KC_PDOT,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,          \
KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,        KC_TRNS,KC_TRNS,                           KC_P0,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

/* Keymap _: Template layer
 * ,--------------------------------------------------------------------------.  ,----.
 * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |  |    |
 * |--------------------------------------------------------------------------|  |----|
 * |      |    |    |    |    |    |    |    |    |    |    |    |    |       |  |    |
 * |--------------------------------------------------------------------------|  `----'
 * |       |    |    |    |    |    |    |    |    |    |    |    |     |     |
 * |-----------------------------------------------------------------------------.s
 * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |    |
 * |------------------------------------------------------------------------|----|----.
 * |     |     |     |     |         |         |     |     |     |     |    |    |    |
 * `----------------------------------------------------------------------------------'
 */
// [_] = KEYMAP(
// KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, 
// KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                   KC_TRNS, 
// KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                         
// KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,          
// KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,        KC_TRNS,KC_TRNS,                         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

enum function_id {
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(RGBLED_TOGGLE),
  [1]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
  [2]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [3]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [4]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [5]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [6]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [7]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case RGBLED_TOGGLE:
      //led operations
      if (record->event.pressed) {
        rgblight_toggle();
      }

      break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
      }
      break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
      }
      break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
      }
      break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
      }
      break;
    case RGBLED_INCREASE_VAL:
      if (record->event.pressed) {
        rgblight_increase_val();
      }
      break;
    case RGBLED_DECREASE_VAL:
      if (record->event.pressed) {
        rgblight_decrease_val();
      }
      break;
    case RGBLED_STEP_MODE:
      if (record->event.pressed) {
        rgblight_step();
      }
      break;
  }
}
