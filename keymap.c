#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"

#include "raw_hid.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

#define _ KC_TRANSPARENT

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  NAV_LAYER,
  LOCK
};

bool locked = false;
bool holding_layer = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    LOCK, LSFT(KC_QUOTE), KC_GRAVE, KC_F, KC_B, KC_QUES, MO(6), TO(7), KC_LABK, KC_K, KC_Q, KC_SLASH, KC_MINUS, KC_ASTR,
    KC_TAB, KC_QUOTE, KC_H, KC_D, KC_P, KC_COMMA, MO(5), MO(5), KC_LCBR, KC_L, KC_U, KC_Y, KC_EQUAL, KC_PLUS,
    LSFT_T(KC_ESCAPE),KC_A, KC_R, KC_S, KC_T, KC_DOT, KC_LPRN, KC_N, KC_E, KC_I, KC_O, KC_ENTER,
    MO(1), KC_Z, KC_W, KC_G, KC_C, KC_SCOLON, MO(2), MO(2), KC_LBRACKET, KC_M, KC_V, KC_J, KC_X, MO(1),
    KC_LCTRL, KC_LGUI, KC_LALT, KC_DELETE, KC_BSPACE, KC_BSPACE, KC_HYPR, KC_MEH, KC_DLR, KC_PSCREEN,
    DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,DYN_REC_STOP, MO(8),
    KC_MEDIA_PLAY_PAUSE,DYN_REC_START1,
    KC_SPACE, NAV_LAYER, KC_MEDIA_NEXT_TRACK,DYN_REC_START2, NAV_LAYER, KC_SPACE
  ),

  [1] = LAYOUT_ergodox_pretty(
    _, LSFT(KC_BSLASH),LSFT(KC_NONUS_BSLASH),LSFT(KC_F), LSFT(KC_B), KC_NONUS_HASH, _, _, KC_RABK, LSFT(KC_K), LSFT(KC_Q), KC_NONUS_BSLASH,KC_CIRC, KC_PERC,
    LSFT(KC_TAB), LSFT(KC_2), LSFT(KC_H), LSFT(KC_D), LSFT(KC_P), KC_AMPR, _, _, KC_RCBR, LSFT(KC_L), LSFT(KC_U), LSFT(KC_Y), KC_UNDS, _,
    _, LSFT(KC_A), LSFT(KC_R), LSFT(KC_S), LSFT(KC_T), KC_EXLM, KC_RPRN, LSFT(KC_N), LSFT(KC_E), LSFT(KC_I), LSFT(KC_O), LSFT(KC_ENTER),
    _, LSFT(KC_Z), LSFT(KC_W), LSFT(KC_G), LSFT(KC_C), KC_COLN, _, _, KC_RBRACKET, LSFT(KC_M), LSFT(KC_V), LSFT(KC_J), LSFT(KC_X), _,
    KC_PC_CUT, KC_PC_COPY, KC_PC_PASTE, LALT(LGUI(KC_0)),_, _, LALT(LGUI(KC_0)),_, LSFT(KC_3), KC_PAUSE,
    _, _, _, _,
    _, _,
    KC_ENTER, _, _, _, _, KC_ENTER
  ),

  [2] = LAYOUT_ergodox_pretty(
    _, KC_NO, KC_PERC, KC_9, KC_8, KC_RPRN, _, _, KC_RPRN, KC_8, KC_9, KC_PERC, KC_NO, KC_NO,
    _, KC_7, KC_6, KC_5, KC_4, KC_LPRN, _, _, KC_LPRN, KC_4, KC_5, KC_6, KC_7, KC_NO,
    _, KC_3, KC_2, KC_1, KC_0, KC_DOT, KC_DOT, KC_0, KC_1, KC_2, KC_3, _,
    KC_SLASH, KC_ASTR, KC_MINUS, KC_PLUS, KC_EQUAL, KC_COMMA, _, _, KC_COMMA, KC_EQUAL, KC_PLUS, KC_MINUS, KC_ASTR, KC_SLASH,
    _, _, _, _, KC_BSPACE, KC_BSPACE, KC_NO, KC_NO, KC_NO, KC_NO,
    _, _, _, _,
    _, _,
    _, _, _, _, _, _
  ),
  
  [3] = LAYOUT_ergodox_pretty(
    _, KC_PC_UNDO, KC_PC_CUT, KC_PC_COPY, KC_PC_PASTE, KC_NO, _, _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    _, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, _, _, KC_NO, KC_MS_WH_DOWN, KC_MS_UP, KC_MS_WH_UP, KC_NO, _,
    _, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_MS_WH_LEFT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_RIGHT, _,
    KC_LSFT, KC_NO, KC_V, KC_HOME, KC_END, KC_NO,_, _, KC_MS_BTN4, KC_MS_BTN5, KC_NO, KC_NO, KC_NO, KC_LSFT,
    _, _, _, _, _, KC_MS_BTN3, KC_NO, KC_NO, KC_NO, KC_RCTRL,
    _, _, _, _,
    _, _,
    KC_MS_BTN1, KC_MS_BTN2, TO(0), TO(0), KC_MS_BTN2, KC_MS_BTN1
  ),

  [4] = LAYOUT_ergodox_pretty(
    _, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TO(0), _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    _, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _, _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _,
    _, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_INSERT, KC_NUMLOCK, KC_SCROLLLOCK, KC_CAPSLOCK, KC_RALT, _,
    OSM(MOD_LSFT), KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, _, _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, OSM(MOD_LSFT),
    _, _, _, KC_F21, KC_F22, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    _, _, _, _,
    _, _,
    KC_NO, _, _, _, _, KC_NO
  ),
  
  [5] = LAYOUT_ergodox_pretty(
    _, _, _, LALT(LGUI(KC_F)),LALT(LGUI(KC_B)),_, _, _, _, LALT(LGUI(KC_K)),LALT(LGUI(KC_Q)),_, _, LALT(LGUI(KC_F9)),
    _, _, LALT(LGUI(KC_H)),LALT(LGUI(KC_D)),LALT(LGUI(KC_P)),LALT(LGUI(KC_F1)),_, _, LALT(LGUI(KC_F1)),LALT(LGUI(KC_L)),LALT(LGUI(KC_UP)),LALT(LGUI(KC_Y)),LALT(KC_F12), _,
    _, LALT(LGUI(KC_A)),LALT(LGUI(KC_R)),LALT(LGUI(KC_S)),LALT(LGUI(KC_T)),LALT(LGUI(KC_F5)), LALT(LGUI(KC_F5)),LALT(LGUI(KC_LEFT)),LALT(LGUI(KC_DOWN)),LALT(LGUI(KC_RIGHT)),LALT(LGUI(KC_O)),LALT(LGUI(KC_ENTER)),
    OSM(MOD_LSFT), LALT(LGUI(KC_Z)),LALT(LGUI(KC_W)),LALT(LGUI(KC_G)),LALT(LGUI(KC_C)),LALT(LGUI(KC_F2)),_, _, LALT(LGUI(KC_F2)),LALT(LGUI(KC_M)),LALT(LGUI(KC_V)),LALT(LGUI(KC_J)),LALT(LGUI(KC_X)),OSM(MOD_LSFT),
    _, _, _, LALT(LGUI(KC_SPACE)),LALT(LGUI(LSFT(KC_DELETE))), LALT(LGUI(LSFT(KC_DELETE))),_, _, _, _,
    _, _, _, _,
    _, _,
    LALT(LGUI(KC_F3)),_, _, _, _, LALT(LGUI(KC_F3))
  ),
  
  [6] = LAYOUT_ergodox_pretty(
    _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _, _, ST_MACRO_1, KC_NO, KC_NO, KC_NO, KC_NO, TO(0),
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _, _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_NO, KC_NO,
    _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _, _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, _, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO, _, KC_NO, KC_NO, _, KC_NO
  ),
  
  [7] = LAYOUT_ergodox_pretty(
    KC_F1, KC_F2, KC_F3, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, TO(0),
    _, _, _, _,
    _, _,
    _, _, _, _, _, TO(0)
  ),
  
  [8] = LAYOUT_ergodox_pretty(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, EEP_RST,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RESET, KC_NO, WEBUSB_PAIR, _,
    KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_ENTER))));
      }
      break;

    case ST_MACRO_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_0)) SS_DELAY(100) SS_TAP(X_F) SS_DELAY(100) SS_TAP(X_I) SS_DELAY(100) SS_TAP(X_R) SS_DELAY(100) SS_TAP(X_ENTER));
      }
      break;

    case NAV_LAYER:
      if (record->event.pressed) {
        holding_layer = true;
        layer_on(3);
      } else {
        holding_layer = false;
        if (locked) {
          locked = false;
        } else {
          layer_off(3);
        }
      }
      return false;
      break;

    case LOCK:
      if (record->event.pressed) {
        if (layer_state_is(0)) {
          SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_ENTER))));
        } else if (holding_layer) {
          locked = true;
        } else {
          layer_clear();
        }
      } else {
        if (!holding_layer) {
          locked = false;
        }
      }
      break;
  }
  return true;
}

uint8_t last_layer = 0;

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t msg[RAW_EPSIZE];
  sprintf((char *)msg, "LAYER:%u", layer);
  raw_hid_send(msg, RAW_EPSIZE);

  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;

    case 2:
      ergodox_right_led_2_on();
      break;
  
    case 3:
      ergodox_right_led_3_on();
      break;
  
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
      
    default:
      break;
  }

  last_layer = layer;
  return state;
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your code goes here. data is the packet received from host.
}