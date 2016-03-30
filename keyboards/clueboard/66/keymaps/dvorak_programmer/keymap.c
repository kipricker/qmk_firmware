#include "66.h"

#ifdef ENABLE_RGBLIGHT
#include "rgblight.h"
#endif

// Used for SHIFT_ESC
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _DL 1
#define _FL 2
#define _RS 3
#define _ML 4
#define _NL 5

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


[_DL] = KEYMAP(
  F(8),    F(9),    F(10),   F(11),  F(12),  F(13),  F(14),  F(15),  F(16),  F(17),   F(18),    F(19),    F(20),    KC_BSPC,   KC_DEL,         KC_PGUP, \
  KC_TAB,  KC_SCLN, KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,    KC_L,     KC_SLSH,  F(21),    KC_BSLS,                   KC_PGDN, \
  KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,    KC_S,     KC_MINS,  KC_BSLS,  KC_ENT,                             \
  MO(_FL), KC_LSFT, KC_QUOT, KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,    KC_V,     KC_Z,     KC_RSFT,  MO(_FL),          KC_UP,            \
  KC_LCTL, KC_LALT, KC_LGUI, MO(_NL),        KC_LSFT,KC_SPC,                          MO(_ML),  KC_RGUI,  KC_RALT,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

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
   * |      | _BL|    |    |RESET|   |    |    |    |    |    |    |    |       |  |    |
   * |--------------------------------------------------------------------------|  `----'
   * |       |    | _RS| _DL|    |    |    |    |    |    |    |    |     |     |
   * |-----------------------------------------------------------------------------.
   * |     |    |    |    |    |    |    |    |    |    |    |    |     |     |    |
   * |------------------------------------------------------------------------|----|----.
   * |     |     |     |     |         |         |     |     |     |  _FL|    |    |    |
   * `----------------------------------------------------------------------------------'
   */
[_RS] = KEYMAP(
  KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, F(0),             F(6), \
  KC_TRNS, DF(_BL), KC_TRNS,KC_TRNS,RESET,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                   F(7), \
  KC_TRNS, KC_TRNS, MO(_RS),DF(_DL),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                         \
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

    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_10,
    KEY_11,
    KEY_12,
    KEY_13,
    KEY_14,
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

  [8]  = ACTION_FUNCTION(KEY_1),
  [9]  = ACTION_FUNCTION(KEY_2),
  [10] = ACTION_FUNCTION(KEY_3),
  [11] = ACTION_FUNCTION(KEY_4),
  [12] = ACTION_FUNCTION(KEY_5),
  [13] = ACTION_FUNCTION(KEY_6),
  [14] = ACTION_FUNCTION(KEY_7),
  [15] = ACTION_FUNCTION(KEY_8),
  [16] = ACTION_FUNCTION(KEY_9),
  [17] = ACTION_FUNCTION(KEY_10),
  [18] = ACTION_FUNCTION(KEY_11),
  [19] = ACTION_FUNCTION(KEY_12),
  [20] = ACTION_FUNCTION(KEY_13),
  [21] = ACTION_FUNCTION(KEY_14),

};

void key_remap_unshift(keyrecord_t *record, const uint16_t kc)
{
    const uint8_t isShifted = get_mods()&MODS_SHIFT_MASK;
    if (record->event.pressed) {
        del_mods(isShifted);
        add_key(kc);
        send_keyboard_report();
        add_mods(isShifted);
    } else {
        del_key(kc);
        send_keyboard_report();
    }
}

void key_remap_shift(keyrecord_t *record, const uint16_t kc)
{
    const uint8_t isShifted = get_mods()&MODS_SHIFT_MASK;
    if (record->event.pressed) {
        if (!isShifted) {
            add_mods(MODS_SHIFT_MASK);
        }

        add_key(kc);
        send_keyboard_report();

        if (!isShifted) {
            del_mods(MODS_SHIFT_MASK);
        }
    } else {
        del_key(kc);
        send_keyboard_report();
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {

  const uint8_t isShifted = get_mods()&MODS_SHIFT_MASK;

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


    case KEY_1:
        if (isShifted) {
            key_remap_shift(record, KC_GRV);
        } else {
            key_remap_shift(record, KC_4);
        }
        break;
    case KEY_2:
        if (isShifted) {
            key_remap_shift(record, KC_5);
        } else {
            key_remap_shift(record, KC_7);
        }
        break;
    case KEY_3:
        if (isShifted) {
           key_remap_unshift(record, KC_7);
        } else {
           key_remap_unshift(record, KC_LBRC);
        }
        break;
    case KEY_4:
        if (isShifted) {
           key_remap_unshift(record, KC_5);
        } else {
           key_remap_shift(record, KC_LBRC);
        }
        break;
    case KEY_5:
        if (isShifted) {
           key_remap_unshift(record, KC_3);
        } else {
           key_remap_shift(record, KC_RBRC);
        }
        break;
    case KEY_6:
        if (isShifted) {
           key_remap_unshift(record, KC_1);
        } else {
           key_remap_shift(record, KC_9);
        }
        break;
    case KEY_7:
        if (isShifted) {
           key_remap_unshift(record, KC_9);
        } else {
           key_remap_unshift(record, KC_EQL);
        }
        break;
    case KEY_8:
        if (isShifted) {
           key_remap_unshift(record, KC_0);
        } else {
           key_remap_shift(record, KC_8);
        }
        break;
    case KEY_9:
        if (isShifted) {
           key_remap_unshift(record, KC_2);
        } else {
           key_remap_shift(record, KC_0);
        }
        break;
    case KEY_10:
        if (isShifted) {
           key_remap_unshift(record, KC_4);
        } else {
           key_remap_shift(record, KC_EQL);
        }
        break;
    case KEY_11:
        if (isShifted) {
           key_remap_unshift(record, KC_6);
        } else {
           key_remap_unshift(record, KC_RBRC);
        }
        break;
    case KEY_12:
        if (isShifted) {
           key_remap_unshift(record, KC_8);
        } else {
           key_remap_shift(record, KC_1);
        }
        break;
    case KEY_13:
        if (isShifted) {
           key_remap_unshift(record, KC_GRV);
        } else {
           key_remap_shift(record, KC_3);
        }
        break;
    case KEY_14:
        if (isShifted) {
           key_remap_shift(record, KC_6);
        } else {
           key_remap_shift(record, KC_2);
        }
        break;
  }
}
