/* Copyright 2023 Finalkey
 * Copyright 2023 LiWenLiu <https://github.com/Linger7857>
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

#include "keyboard_common.h"

#ifndef CORE75_DISABLE_CUSTOM_DIRECT_RGB
extern void load_custom_rgb(void);
#endif

// ===========================================================================
// Keyboard-specific data
// ===========================================================================

// Battery indicator LED indices (num row 1-10 )
const uint8_t Led_Batt_Index_Tab[BATTERY_LED_COUNT] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

// ===========================================================================
// LED Matrix Configuration (keyboard-specific)
// ===========================================================================


led_config_t g_led_config = { {
    { 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , NO_LED   , 81       , NO_LED   },
	{ 14       , 15       , 16       , 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , NO_LED   , NO_LED   },
	{ 29       , 30       , 31       , 32       , 33       , 34       , 35       , 36       , 37       , 38       , 39       , 40       , 41       , 42       , 13       , 28       },
	{ 44       , 45       , 46       , 47       , 48       , 49       , 50       , 51       , 52       , 53       , 54       , 55       , NO_LED   , 56       , 43       , 57       },
	{ 58       , NO_LED   , 59       , 60       , 61       , 62       , 63       , 64       , 65       , 66       , 67       , 68       , NO_LED   , 69       , 70       , 71       },
	{ 72       , 73       , 74       , NO_LED   , NO_LED   , 75       , NO_LED   , NO_LED   , NO_LED   , 76       , 77       , NO_LED   , NO_LED   , 78       , 79       , 80       }
}, {
    { 0,  10},  { 17, 10}, { 32, 10}, { 47, 10}, { 62, 10}, { 79, 10}, { 94, 10}, {109, 10}, {124, 10}, { 141, 10}, { 156, 10}, { 171, 10}, { 186, 10}, { 206, 10},
    { 0,  20},  { 15, 20}, { 30, 20}, { 45, 20}, { 60, 20}, { 75, 20}, { 90, 20}, {105, 20}, {120, 20}, { 135, 20}, { 150, 20}, { 165, 20}, { 180, 20}, { 200, 20},             { 224, 20},
    { 4,  30},  { 20, 30}, { 35, 30}, { 50, 30}, { 65, 30}, { 80, 30}, { 95, 30}, {110, 30}, {125, 30}, { 140, 30}, { 155, 30}, { 170, 30}, { 185, 30},             { 204, 30}, { 224, 30},
    { 6,  40},  { 24, 40}, { 39, 40}, { 54, 40}, { 69, 40}, { 84, 40}, { 99, 40}, {114, 40}, {129, 40}, { 144, 40}, { 159, 40}, { 174, 40},             { 199, 40},             { 224, 40},
    { 8,  50},             { 28, 50}, { 43, 50}, { 58, 50}, { 73, 50}, { 88, 50}, {103, 50}, {118, 50}, { 133, 50}, { 148, 50}, { 163, 50},             { 183, 50}, { 203, 50}, { 224, 50},
    { 0,  60},  { 20, 60}, { 40, 60},                       { 90, 60},                                  { 145, 60}, { 165, 60},                         { 188, 60}, { 203, 60}, { 224, 60},  { 224, 10}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,      1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1,
    1,  1,  1,          1,              1,  1,          1,  1,  1,  1
} };

// ===========================================================================
// QMK Callback Functions - Delegate to common implementations
// ===========================================================================


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
#ifndef CORE75_DISABLE_CUSTOM_DIRECT_RGB
    // Turn off the knob LED  in per key RGB mode 
    // since the encoder can't be colored from VIA's color-palette
    if (rgb_matrix_get_mode() == RGB_MATRIX_CUSTOM_DIRECT) {
        rgb_matrix_set_color(81, 0, 0, 0);
    }
#endif
    return kb_rgb_matrix_indicators_common(led_min, led_max);
}

void notify_usb_device_state_change_user(struct usb_device_state usb_device_state) {
    kb_notify_usb_device_state_change(usb_device_state);
}

bool led_update_user(led_t led_state) {
    return kb_led_update(led_state);
}

void housekeeping_task_user(void) {
    kb_housekeeping_task();
}

void board_init(void) {
    kb_board_init();
}

void keyboard_post_init_user(void) {
    kb_keyboard_post_init();
#ifndef CORE75_DISABLE_CUSTOM_DIRECT_RGB
    load_custom_rgb();
#endif
}

void matrix_scan_user(void) {
#ifdef RGB_MATRIX_ENABLE
    static uint8_t saved_brightness = 0;
    static bool was_clamped = false;

    // Wireless Battery Saving: Clamp maximum brightness to 170 over 2.4G/BLE unless unlocked via VIA
    if (Keyboard_Info.Key_Mode != QMK_USB_MODE && !Keyboard_Info.Wireless_Brightness_Unlock) {
        if (rgb_matrix_config.hsv.v > 170) {
            if (!was_clamped) {
                saved_brightness = rgb_matrix_config.hsv.v; // Store user's original preferred brightness
                was_clamped = true;
            }
            rgb_matrix_sethsv_noeeprom(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, 170);
        }
    } else {
        // Restoring brightness if we just connected to USB or unlocked wireless brightness
        if (was_clamped) {
            rgb_matrix_sethsv_noeeprom(rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, saved_brightness);
            was_clamped = false;
        }
    }
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return kb_process_record_common(keycode, record);
}


