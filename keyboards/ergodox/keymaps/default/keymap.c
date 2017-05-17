#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define OSX     0  // default layer (for OSX)
#define FN      1  // functions

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: OS X layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Kanji|           | ascii|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Tab  |           | LFn  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CTRL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  | K/Gui|   L  |   ;  |   '"   |
 * |--------+------+------+------+------+------| Meh  |           |Meh   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  `~  |      | Left | Right|                                       |  Up  | Down |   [  |   ]  |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | LAlt |       | LGui | Esc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Alt/  | Esc  |------|       |------| Enter  |Space |
 *                                 |   ESC|      | Del  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[OSX] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,        KC_3,      KC_4,   KC_5,   KC_FN2,
        KC_TAB,         KC_Q,         KC_W,        KC_E,      KC_R,   KC_T,   KC_TAB,
        KC_LCTL,        KC_A,         KC_S,        KC_D,      KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,        KC_C,      KC_V,   KC_B,   MEH_T(KC_NO),
        KC_NO,          KC_GRV,       KC_NO,       KC_LEFT,   KC_RGHT,
                                                               KC_LGUI,       KC_LALT,
                                                                              KC_HOME,
                                                              KC_SPC,KC_ESC,KC_DEL,
        // right hand
             KC_FN3,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             MO(FN),      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                  KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          KC_NO,
             KC_ESC,      KC_LGUI,
             KC_PGUP,
             KC_PGDN,KC_BSPC, KC_ENT
    ),

/* Keymap 1: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | M-Up |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |M-Left|M-BTN1|M-Rght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |M-Down|      |      |      |           |      |      |      |      |      |      | RESET  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Play | Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Kanji |Englsh|------|       |------| Vol- | Vol+ |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Fnctions
[FN] = KEYMAP(
       // left hand
       KC_TRNS,       KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_MS_L, KC_BTN1, KC_MS_R, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_MS_D, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_MOD,     RGB_VAD,    RGB_VAI, RGB_TOG, RGB_SLD,
                                                            KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                     RCTL(RSFT(KC_J)), RCTL(RSFT(KC_SCLN)), KC_TRNS,
       // right hand
       KC_F7,     KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, RESET,
                RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS,  KC_TRNS,
       KC_MPLY, KC_MUTE,
       KC_TRNS,
       KC_TRNS, KC_VOLD, KC_VOLU
    ),
};

enum macro_id {
  IME_ON=1,
  IME_OFF=2,
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(FN),                // FN1 - Momentary Layer 1 (functions)
  [2] = ACTION_MACRO(IME_ON),
  [3] = ACTION_MACRO(IME_OFF),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
