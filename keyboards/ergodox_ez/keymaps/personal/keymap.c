#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           |  ESC |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | LGUI   |   Q  |   W  |   E  |   R  |   T  |  [ { |           |  } ] |   Y  |   U  |   I  |   O  |   P  | RGUI   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab   |   A   |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|  \ | |           | / ?  |------+------+------+------+------+--------|
 * | Del  |    Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | UP   | Backspc|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LAlt | ` ~  | SYMB |  (   |                                       |  )  | Mouse | LEFT | DOWN | RIGHT  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Insert| Home |      | PgUp | Ptr scr|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End |        | PgDn |        |      |
 *                                 | Space|LShift|------|       |------| RShift |Enter |
 *                                 |      |      | Caps  |      | Caps |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,       KC_3,       KC_4,       KC_5,       KC_ESC,
        KC_LGUI,        KC_Q,         KC_W,       KC_E,       KC_R,       KC_T,       KC_LBRC,
        KC_TAB,         KC_A,         KC_S,       KC_D,       KC_F,       KC_G,
        KC_DELT,        KC_Z,         KC_X,       KC_C,       KC_V,       KC_B,       KC_BSLS,
        KC_LCTL,        KC_LALT,      KC_GRV,     KC_FN1,     KC_LPRN,
                                                                          KC_INS,     KC_HOME,
                                                                                      KC_END,
                                                              KC_SPC,     KC_LSFT,    KC_CAPS,
        // right hand
             KC_ESC,      KC_6,     KC_7,       KC_8,       KC_9,       KC_0,             KC_MINS,
             KC_RBRC,     KC_Y,     KC_U,       KC_I,       KC_O,       KC_P,             KC_RGUI,
                          KC_H,     KC_J,       KC_K,       KC_L,       KC_SCLN,          KC_QUOT,
             KC_SLSH,     KC_N,     KC_M,       KC_COMM,    KC_DOT,     KC_UP,            KC_BSPC,
                                    KC_RPRN,    TG(MDIA),   KC_LEFT,    KC_DOWN,          KC_RGHT,
             KC_PGUP,     KC_PSCR,
             KC_PGDN,
             KC_CAPS,    KC_RSFT,  KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   º    |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   ~    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |   é  |      |      |      |           |      |      |   ú  |   í  |   ó  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   á  |      |      |      |      |------|           |------| left | down |  up  | right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  ñ   |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |LShift|------|       |------|LShift|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       LALT(LCTL(KC_EQL)),    KC_F1,                KC_F2,    KC_F3,                  KC_F4,        KC_F5,    KC_F11,
       KC_TRNS,             KC_NO,                KC_NO,    LALT(LCTL(KC_E)),       KC_NO,        KC_NO,    KC_NO,
       KC_TRNS,             LALT(LCTL(KC_A)),     KC_NO,    KC_NO,                  KC_NO,        KC_NO,
       KC_NO,               KC_NO,                KC_NO,    KC_NO,                  KC_NO,        KC_NO,    KC_NO,
       KC_TRNS,             KC_TRNS,              KC_NO,    KC_TRNS,                  KC_NO,
                                                                        KC_NO,      KC_NO,
                                                                                    KC_NO,
                                                              KC_NO,    KC_LSFT,    KC_NO,
       // right hand
       KC_F12,  KC_F6,              KC_F7,                KC_F8,                KC_F9,                KC_F10,   KC_TILD,
       KC_NO,   KC_NO,              LALT(LCTL(KC_U)),     LALT(LCTL(KC_I)),     LALT(LCTL(KC_O)),     KC_NO,    KC_TRNS,
                KC_LEFT,            KC_DOWN,              KC_UP,                KC_RGHT,              KC_NO,    KC_NO,
       KC_NO,   LALT(LCTL(KC_N)),   KC_NO,                KC_NO,                KC_NO,                KC_NO,    KC_NO,
                                    KC_NO,                KC_TRNS,              KC_NO,                KC_NO,    KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_RSFT,            KC_NO
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | BTN1 | BTN2 |------|       |------|SCL_U | SCL_D|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,
                                                            KC_NO,    KC_NO,
                                                                      KC_NO,
                                                  KC_BTN1,  KC_BTN2,  KC_NO,
    // right hand
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
                  KC_MS_L,  KC_MS_D,  KC_MS_U,    KC_MS_R,  KC_NO,    KC_NO,
       KC_NO,     KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,
                            KC_NO,    KC_TRNS,    KC_NO,    KC_NO,    KC_NO,
       KC_NO,     KC_NO,
       KC_NO,
       KC_NO,     KC_WH_U,  KC_WH_D
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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
      }
    return MACRO_NONE;
};

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
            ergodox_right_led_2_on();
            break;
        case 2:
            ergodox_right_led_3_on();
            break;
        default:
            // don't do anything
            break;
    }

    // capslock
    if (host_keyboard_leds() & (3<<USB_LED_CAPS_LOCK)) {
      ergodox_right_led_1_on();
    }
  };
