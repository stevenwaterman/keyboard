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
  LOCK,
  LAYER_1,
  LAYER_2,
  LAYER_3,
  LAYER_4,
  LAYER_5,
  LAYER_6,
  UNSHIFT_HASH,
  UNSHIFT_RABK,
  UNSHIFT_BSLASH,
  UNSHIFT_RCBR,
  UNSHIFT_RBRACKET,
  UNSHIFT_ENTER,
  UNSHIFT_CUT,
  UNSHIFT_COPY,
  UNSHIFT_PASTE,
  UNSHIFT_PROGRAMS
};

bool locked = false;
bool holding_layer = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    LOCK, LSFT(KC_QUOTE), KC_GRAVE, KC_F, KC_B, KC_QUES, LAYER_5, LAYER_5, KC_LABK, KC_K, KC_Q, KC_SLASH, KC_MINUS, KC_ASTR,
    KC_TAB, KC_QUOTE, KC_H, KC_D, KC_P, KC_COMMA, LAYER_4, LAYER_4, KC_LCBR, KC_L, KC_U, KC_Y, KC_EQUAL, KC_PLUS,
    KC_ESCAPE,KC_A, KC_R, KC_S, KC_T, KC_DOT, KC_LPRN, KC_N, KC_E, KC_I, KC_O, KC_ENTER,
    LAYER_1, KC_Z, KC_W, KC_G, KC_C, KC_SCOLON, LAYER_2, LAYER_2, KC_LBRACKET, KC_M, KC_V, KC_J, KC_X, LAYER_1,
    KC_LCTRL, KC_LGUI, KC_LALT, KC_DELETE, KC_BSPACE, KC_BSPACE, KC_HYPR, KC_MEH, KC_DLR, KC_PSCREEN,
    DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,DYN_REC_STOP, LAYER_6,
    KC_MEDIA_PLAY_PAUSE,DYN_REC_START1,
    KC_SPACE, LAYER_3, KC_MEDIA_NEXT_TRACK,DYN_REC_START2, LAYER_3, KC_SPACE
  ),

  // 
  [1] = LAYOUT_ergodox_pretty(
    _, KC_BSLASH, KC_NONUS_BSLASH,KC_F, KC_B, UNSHIFT_HASH, _, _, UNSHIFT_RABK, KC_K, KC_Q, UNSHIFT_BSLASH, KC_6, KC_5,
    KC_TAB, KC_2, KC_H, KC_D, KC_P, KC_7, _, _, UNSHIFT_RCBR, KC_L, KC_U, KC_Y, KC_MINUS, _,
    UNSHIFT_ENTER, KC_A, KC_R, KC_S, KC_T, KC_1, KC_0, KC_N, KC_E, KC_I, KC_O, KC_ENTER,
    KC_NO, KC_Z, KC_W, KC_G, KC_C, KC_SCOLON, _, _, UNSHIFT_RBRACKET, KC_M, KC_V, KC_J, KC_X, _,
    UNSHIFT_CUT, UNSHIFT_COPY, UNSHIFT_PASTE, UNSHIFT_PROGRAMS, _, _, UNSHIFT_PROGRAMS,_, KC_3, KC_PAUSE,
    _, _, _, _,
    _, _,
    _, _, _, _, _, _
  ),

  // Symbol layer
  [2] = LAYOUT_ergodox_pretty(
    _, KC_NO, KC_NO, KC_9, KC_8, KC_NO, _, _, KC_NO, KC_8, KC_9, KC_NO, KC_NO, KC_NO,
    _, KC_7, KC_6, KC_5, KC_4, KC_NO, _, _, KC_NO, KC_4, KC_5, KC_6, KC_7, KC_NO,
    _, KC_3, KC_2, KC_1, KC_0, KC_DOT, KC_DOT, KC_0, KC_1, KC_2, KC_3, _,
    _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _,
    _, _, _, _, _, _, _, KC_NO, KC_NO, _,
    _, _, _, _,
    _, _,
    _, _, _, _, _, _
  ),
  
  // Nav layer
  [3] = LAYOUT_ergodox_pretty(
    _,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,		_,		_, 		KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 			KC_NO,
    _,		KC_NO,		KC_NO, 		KC_UP, 		KC_NO, 		KC_NO,		_,		_, 		KC_NO, 			KC_MS_WH_DOWN, 		KC_MS_UP, 		KC_MS_WH_UP, 		KC_NO, 			_,
    _,  	KC_NO,		KC_LEFT, 	KC_DOWN, 	KC_RIGHT, 	KC_NO,						KC_MS_WH_LEFT, 		KC_MS_LEFT, 		KC_MS_DOWN, 		KC_MS_RIGHT, 		KC_MS_WH_RIGHT, 	_,
    KC_LSFT, 	KC_NO,		KC_HOME, 	KC_NO, 		KC_END, 	KC_NO,		_,		_, 		KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 			KC_LSFT,
    _,		_,		_,		_,		_,											KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_NO,
    										_, 		_, 		_, 		_,
    												_, 		_,
    								KC_MS_BTN1, 	KC_MS_BTN2, 	KC_MS_BTN3, 	KC_MS_BTN3, 	KC_MS_BTN2, 	KC_MS_BTN1
  ),

  // i3
  [4] = LAYOUT_ergodox_pretty(
    _, _, _, LALT(LGUI(KC_F)),LALT(LGUI(KC_B)),_, _, _, _, LALT(LGUI(KC_K)),LALT(LGUI(KC_Q)),_, _, LALT(LGUI(KC_F9)),
    _, _, LALT(LGUI(KC_H)),LALT(LGUI(KC_D)),LALT(LGUI(KC_P)),LALT(LGUI(KC_F1)),_, _, LALT(LGUI(KC_F1)),LALT(LGUI(KC_L)),LALT(LGUI(KC_UP)),LALT(LGUI(KC_Y)),LALT(KC_F12), _,
    _, LALT(LGUI(KC_A)),LALT(LGUI(KC_R)),LALT(LGUI(KC_S)),LALT(LGUI(KC_T)),LALT(LGUI(KC_F5)), LALT(LGUI(KC_F5)),LALT(LGUI(KC_LEFT)),LALT(LGUI(KC_DOWN)),LALT(LGUI(KC_RIGHT)),LALT(LGUI(KC_O)),LALT(LGUI(KC_ENTER)),
    OSM(MOD_LSFT), LALT(LGUI(KC_Z)),LALT(LGUI(KC_W)),LALT(LGUI(KC_G)),LALT(LGUI(KC_C)),LALT(LGUI(KC_F2)),_, _, LALT(LGUI(KC_F2)),LALT(LGUI(KC_M)),LALT(LGUI(KC_V)),LALT(LGUI(KC_J)),LALT(LGUI(KC_X)),OSM(MOD_LSFT),
    _, _, _, LALT(LGUI(KC_SPACE)),LALT(LGUI(LSFT(KC_DELETE))), LALT(LGUI(LSFT(KC_DELETE))),_, _, _, _,
    _, _, _, _,
    _, _,
    LALT(LGUI(KC_F3)),_, _, _, _, LALT(LGUI(KC_F3))
  ),

  // F keys
  [5] = LAYOUT_ergodox_pretty(
    _, KC_NO, KC_NO, KC_F9, KC_F8, KC_NO, _, _, KC_NO, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO,
    _, KC_F7, KC_F6, KC_F5, KC_F4, KC_NO, _, _, KC_NO, KC_F4, KC_F5, KC_F6, KC_F7, KC_NO,
    _, KC_F3, KC_F2, KC_F1, KC_F10, KC_NO, KC_NO, KC_10, KC_F1, KC_F2, KC_F3, _,
    MOD_LSFT, KC_NO, KC_F12, KC_F11, KC_NO, KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MOD_LSFT,
    _, _, _, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _,
    _, _, _, _,
    _, _,
    _, _, _, _, _, _
  ),
  
  [6] = LAYOUT_ergodox_pretty(
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

bool layer(keyrecord_t *record, uint8_t layer) {
  if (record->event.pressed) {
    holding_layer = true;
    layer_on(layer);
  } else {
    holding_layer = false;
    if (locked) {
      locked = false;
    } else {
      layer_off(layer);
    }
  }
  return false;
}

bool unshifted(keyrecord_t *record, uint16_t keycode) {
  if (record->event.pressed) {
    unregister_code(KC_LSFT);
    tap_code16(keycode);
    register_code(KC_LSFT);
  }
  return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAYER_1:
      return layer(record, 1);
    case LAYER_2:
      return layer(record, 2);
    case LAYER_3:
      return layer(record, 3);
    case LAYER_4:
      return layer(record, 4);
    case LAYER_5:
      return layer(record, 5);
    case LAYER_8:
      return layer(record, 8);

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

    case UNSHIFT_HASH:
      return unshifted(record, KC_NONUS_HASH);
    case UNSHIFT_RABK:
      return unshifted(record, KC_RABK);
    case UNSHIFT_BSLASH:
      return unshifted(record, KC_NONUS_BSLASH);
    case UNSHIFT_RCBR:
      return unshifted(record, KC_RCBR);
    case UNSHIFT_RBRACKET:
      return unshifted(record, KC_RBRACKET);
    case UNSHIFT_ENTER:
      return unshifted(record, KC_ENTER);
    case UNSHIFT_CUT:
      return unshifted(record, KC_PC_CUT);
    case UNSHIFT_COPY:
      return unshifted(record, KC_PC_COPY);
    case UNSHIFT_PASTE:
      return unshifted(record, KC_PC_PASTE);
    case UNSHIFT_PROGRAMS:
      return unshifted(record, LALT(LGUI(KC_0)));
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

  uint8_t msg[RAW_EPSIZE] = { 0 };
  sprintf((char *)msg, "LAYER:%u", layer);
  raw_hid_send(msg, RAW_EPSIZE);

  if (layer == 1) {
    register_code(KC_LSFT);
  } else {
    unregister_code(KC_LSFT);
  }

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