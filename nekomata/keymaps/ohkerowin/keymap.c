
#include "nekomata.h"



enum layer_names
{
  _QWERTY,
  _LOWER,
  _FLASH,
  _ART
};

enum custom_keycodes
{
	KEY_TEST = SAFE_RANGE

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
    KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,      KC_MPLY,     KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_ESC,
    KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   TG(_ART),       TG(_FLASH),  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P ,   KC_BSLS,
    KC_BSPC,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,LGUI(LSFT(KC_S)),    LGUI(LSFT(LALT(KC_C))),  KC_H,   KC_J,   KC_K,   KC_L,  KC_SCLN,   KC_MINS,
    KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                      KC_N,  KC_M,KC_COMM, KC_DOT, KC_SLSH,  KC_QUOT,
    KC_LCTL,  KC_LALT, KC_LGUI, MO(_LOWER),  KC_SPC,  KC_ENT,   KC_DEL, KC_ENT, KC_SPC, KC_LEFT,  KC_UP,  KC_DOWN,  KC_RGHT),\

	[_LOWER] = LAYOUT( \
		KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,        KC_TRNS,    KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11, KC_F12,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_TRNS),\



	[_FLASH] = LAYOUT( \
		KC_TRNS, LCTL(KC_EQL), LCTL(KC_MINS), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
		KC_TRNS, KC_N, KC_V, KC_F8, LSFT(LALT(KC_F12)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, LCTL(KC_Z), LCTL(KC_Y), LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_K, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),\

    [_ART] = LAYOUT( \
  		KC_TRNS, LCTL(KC_PPLS), LCTL(KC_PMNS), LCTL(KC_0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  		KC_P, KC_B, KC_H, LCTL(LSFT(KC_H)), KC_D, KC_C, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  		KC_TRNS, LCTL(KC_Z), LCTL(LSFT(KC_Z)), LSFT(KC_X), LCTL(LSFT(KC_N)), LCTL(LALT(KC_G)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  		KC_TRNS, KC_M, LSFT(KC_T), LGUI(LSFT(KC_T)), KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_LBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)\
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _FLASH:
            oled_write_P(PSTR("Flash\n"), false);
            break;
        case _ART:
            oled_write_P(PSTR("Art\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

void encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      /* This is where the actual magic happens: this bit of code taps on the
         Page Down key. You can do anything QMK allows you to do here.
         You'll want to replace these lines with the things you want your
         encoders to do. */
      tap_code(KC_DOT);
    } else {
      /* And likewise for the other direction, this time Page Down is pressed. */
      tap_code(KC_COMM);
    }



#endif
