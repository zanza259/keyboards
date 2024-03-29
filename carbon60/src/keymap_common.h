/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


/* GH60 keymap definition macro
 * K2C, K31 and  K3C are extra keys for ISO
 */
#define KEYMAP( \
    K00,	  K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K110, K111, K112, K113, K114, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K210, K211, K212, K213, K214, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, 	 K3D, 				  K311, K312, K313,       \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A,           K4D,      K4F,       K411, K412, K413, K414, \
	K50, K51, K52,           K55, 				 K59, K5A,      K5C, K5D, K5E, K5F, K510, K511,       K513        \
) { \
    { KC_##K00, KC_NO,    KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_##K0E, KC_##K0F, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO},\
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F, KC_##K110, KC_##K111, KC_##K112, KC_##K113, KC_##K114},\
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F, KC_##K210, KC_##K211, KC_##K212, KC_##K213, KC_##K214},\
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_NO,    KC_##K3D, KC_NO,    KC_NO,    KC_NO,     KC_##K311, KC_##K312, KC_##K313, KC_NO },\
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47, KC_##K48, KC_##K49, KC_##K4A, KC_NO,    KC_NO,    KC_##K4D, KC_NO,    KC_##K4F, KC_NO,     KC_##K411, KC_##K412, KC_##K413, KC_##K414},\
	{ KC_##K50, KC_##K51, KC_##K52, KC_NO,    KC_NO,    KC_##K55, KC_NO,    KC_NO,    KC_NO,    KC_##K59, KC_##K5A, KC_NO,    KC_##K5C, KC_##K5D, KC_##K5E, KC_##K5F, KC_##K510, KC_##K511, KC_NO,     KC_##K513, KC_NO}  \
}


#endif
