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
#define CHORDAL_HOLD

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
