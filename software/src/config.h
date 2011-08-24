/* piezo-buzzer-bricklet
 * Copyright (C) 2011 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config.h: Piezo Buzzer Bricklet specific configuration
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib/drivers/board/sam3s/SAM3S.h"

#include "piezo-buzzer.h"


#define BOARD_MCK 64000000
#define INVOCATION_IN_BRICKLET_CODE

#define PIN_PIEZO (BS->pin3_pwm)
#define MORSE_LENGTH 60

typedef struct {
	uint32_t beep_duration;
	uint32_t morse_duration;
	char morse[MORSE_LENGTH];
	bool morse_buzz;
	uint8_t morse_pos;
} BrickContext;

#endif
