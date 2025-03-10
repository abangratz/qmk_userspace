/*
    Author: Anton 'tony' Bangratz

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#pragma once
#define TAPPING_TERM 120
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
/* #define TAPPING_TOGGLE 2 */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define ACHORDION_STREAK

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define RGB_DI_PIN D3

#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY 150
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 32
#define MOUSEKEY_TIME_TO_MAX 32
#define MOUSEKEY_FRICTION 24
#define MOUSEKEY_MOVE_DELTA 1

#ifdef RGB_MATRIX_ENABLE

#    define RGBLED_NUM 72
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_SPLIT {36, 36}
#    define SPLIT_TRANSPORT_MIRROR

#endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SPLIT
#    define RGBLED_NUM 72
#    define RGB_SPLIT {36, 36}
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_SLEEP /* If defined, the RGB lighting will be switched off when the host goes to sleep */
                           // /*== all animations enable ==*/
                           //   #define RGBLIGHT_ANIMATIONS
                           // /*== or choose animations ==*/
#    define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
#endif
