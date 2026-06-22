/* Copyright 2023 Yiancar-Designs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keyboard_common.h"
#include "palettefx.h"
#include "print.h"
#include "via.h"
#include "socd_cleaner.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_tkl_ansi(
        QK_GESC, KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_MUTE, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_END,
        KC_CAPS, KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,            KC_PGUP,
        KC_LSFT,          KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,    KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                             KC_RALT, MO(2),            KC_LEFT, KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT_tkl_ansi(
        QK_GESC, KC_BRID, KC_BRIU,    KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,   KC_MUTE, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_END,
        KC_CAPS, KC_A,    KC_S,       KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,            KC_PGUP,
        KC_LSFT,          KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,    KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                      KC_SPC,                             KC_RGUI, MO(3),            KC_LEFT, KC_DOWN,  KC_RGHT
    ),
    [2] = LAYOUT_tkl_ansi(
        QK_GESC, KC_MYCM, LGUI(KC_E), KC_CALC, KC_MAIL, KC_MSEL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_INS,   KC_MUTE, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  RM_TOGG,  KC_HOME,
        KC_TAB,  MD_BLE1, MD_BLE2,    MD_BLE3, MD_24G,  MD_USB,  KC_Y,    KC_U,    KC_PSCR, KC_SCRL, KC_PAUS, KC_NO,   KC_NO,   RM_NEXT,  KC_END,
        KC_CAPS, KC_W,   MW_CH,      QMK_SLEEP_CYCLE, QMK_BRIGHTNESS_UNLOCK,    KC_NO,   KC_NO,   KC_J,    KC_K,    KC_L,    KC_NO,   KC_NO,   QK_BAT,            RM_HUEU,
        KC_LSFT,          KC_Z,       QMK_SOCD_TOG, KC_NO,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, RM_VALU,  RM_HUED,
        TEST_CL, QK_WLO,  KC_LALT,                      EE_CLR,                             KC_RALT, KC_NO,            RM_SPDD, RM_VALD,  RM_SPDU
    ),
    [3] = LAYOUT_tkl_ansi(
        QK_GESC, KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,   KC_MUTE, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  RM_TOGG,  KC_HOME,
        KC_TAB,  MD_BLE1, MD_BLE2,    MD_BLE3, MD_24G,  MD_USB,  KC_Y,    KC_U,    KC_PSCR, KC_SCRL, KC_PAUS, KC_NO,   KC_NO,   RM_NEXT,  KC_END,
        KC_CAPS, KC_W,   MW_CH,      QMK_SLEEP_CYCLE, QMK_BRIGHTNESS_UNLOCK,    KC_NO,   KC_NO,   KC_J,    KC_K,    KC_L,    KC_NO,   KC_NO,   QK_BAT,            RM_HUEU,
        KC_LSFT,          KC_Z,       QMK_SOCD_TOG, KC_NO,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, RM_VALU,  RM_HUED,
        TEST_CL, KC_LALT, KC_LGUI,                      EE_CLR,                             KC_RGUI, KC_NO,            RM_SPDD, RM_VALD,  RM_SPDU
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [1] = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [2] = { ENCODER_CCW_CW(KC_NO, KC_NO) },
    [3] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
};

#endif

// SOCD
socd_cleaner_t socd_opposing_pairs[] = {
  {{KC_W, KC_S}, SOCD_CLEANER_LAST},
  {{KC_A, KC_D}, SOCD_CLEANER_LAST},
};

#ifndef CORE75_DISABLE_CUSTOM_DIRECT_RGB
uint8_t color_buffer[RGB_MATRIX_LED_COUNT * 2] = {0};
uint8_t brightness_buffer[RGB_MATRIX_LED_COUNT] = {[0 ... RGB_MATRIX_LED_COUNT - 1] = 255};

void save_custom_rgb(void) {
    eeprom_write_block_user(color_buffer, (void*)0, sizeof(color_buffer));
    eeprom_write_block_user(brightness_buffer, (void*)164, sizeof(brightness_buffer));
}

bool is_buffer_empty(uint8_t *buf, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
        if (buf[i] != 0) return false;
    }
    return true;
}

void load_custom_rgb(void) {
    eeprom_read_block_user(color_buffer, (void*)0, sizeof(color_buffer));
    eeprom_read_block_user(brightness_buffer, (void*)164, sizeof(brightness_buffer));

    if (is_buffer_empty(brightness_buffer, sizeof(brightness_buffer))) {
        memset(brightness_buffer, 255, sizeof(brightness_buffer));
    }
}
#endif

#ifdef VIA_ENABLE
void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    uint8_t  channel_id = data[1];
    uint8_t *command_id = &(data[0]);

    if (channel_id != id_custom_channel) return;

    uint8_t value_id  = data[2];
#ifndef CORE75_DISABLE_CUSTOM_DIRECT_RGB
    uint8_t led_index = data[3];
    uint8_t led_count = data[4];
#endif

    switch (*command_id)
    {
        case id_custom_set_value:
        {
#ifndef CORE75_DISABLE_CUSTOM_DIRECT_RGB
            if (value_id == 1) {
                memcpy(color_buffer + led_index * 2, data + 5, led_count * 2);
            } else if (value_id == 2) {
                memcpy(brightness_buffer + led_index, data + 5, led_count);
            } else if (value_id == 5) {
                save_custom_rgb();
            } else
#endif
            if (value_id == 3) {
                 // Palette Selection
                 uint8_t palette_index = data[3];
                 rgb_matrix_sethsv_noeeprom(palette_index * RGB_MATRIX_HUE_STEP, 255, 255);
            } else if (value_id == 4) {
                // Sleep Timer Selection
                uint8_t timer_option = data[3];
                uint32_t sleep_times[] = {60, 180, 600, 1800}; // 1min, 3min, 10min, 30min
                if (timer_option < 4) {
                    Keyboard_Info.User_Sleep_Time = sleep_times[timer_option];
                    User_Sleep_Time_Send = true;  // Trigger sync to RF module
                    Save_Flash_Set();             // Persist to EEPROM
                }
            } else if (value_id == 6) {
                // SOCD Toggle
                socd_cleaner_enabled = data[3] ? true : false;
            } else if (value_id == 7) {
                // Battery level is read-only, no-op on set
            } else if (value_id == 8) {
                // Wireless Brightness Unlock Toggle
                Keyboard_Info.Wireless_Brightness_Unlock = data[3] ? 1 : 0;
                Save_Flash_Set(); // Persist to EEPROM
            }
            break;
        }
        case id_custom_get_value:
        {
#ifndef CORE75_DISABLE_CUSTOM_DIRECT_RGB
            if (value_id == 1) {
                memcpy(data + 5, color_buffer + led_index * 2, led_count * 2);
            } else if (value_id == 2) {
                memcpy(data + 5, brightness_buffer + led_index, led_count);
            } else
#endif
            if (value_id == 3) {
                // Palette Selection
                data[3] = (rgb_matrix_get_hue() / RGB_MATRIX_HUE_STEP) % palettefx_num_palettes();
            } else if (value_id == 4) {
                // Return current sleep timer index based on the RF value
                extern uint32_t Rf_Reported_Sleep_Time;
                uint8_t index = 1;  // default to 3 min
                if (Rf_Reported_Sleep_Time <= 60) index = 0;
                else if (Rf_Reported_Sleep_Time <= 180) index = 1;
                else if (Rf_Reported_Sleep_Time <= 600) index = 2;
                else index = 3;
                data[3] = index;
            } else if (value_id == 6) {
                // Return SOCD state
                data[3] = socd_cleaner_enabled ? 1 : 0;
            } else if (value_id == 7) {
                // Return battery percentage (0-100)
                data[3] = Keyboard_Info.Batt_Number;
            } else if (value_id == 8) {
                // Return wireless brightness unlock state
                data[3] = Keyboard_Info.Wireless_Brightness_Unlock;
            }
            break;
        }
        case id_custom_save:
            break;
        default:
        {
            *command_id = id_unhandled;
            break;
        }
    }
}
#endif // VIA_ENABLE
