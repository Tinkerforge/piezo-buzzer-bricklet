/* piezo-buzzer-bricklet
 * Copyright (C) 2011 Olaf Lüke <olaf@tinkerforge.com>
 *
 * piezo-buzzer.h: Implementation of Piezo Buzzer Bricklet messages
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

#ifndef PIEZO_BUZZER_H
#define PIEZO_BUZZER_H

#include <stdint.h>

#define TYPE_BEEP 1
#define TYPE_MORSE_CODE 2
#define TYPE_BEEP_FINISHED 3
#define TYPE_MORSE_CODE_FINISHED 4

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} __attribute__((__packed__)) StandardMessage;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t duration;
} __attribute__((__packed__)) Beep;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char morse[60];
} __attribute__((__packed__)) MorseCode;

void beep(uint8_t com, Beep *data);
void morse_code(uint8_t com, MorseCode *data);

void invocation(uint8_t com, uint8_t *data);
void constructor(void);
void destructor(void);
void tick(void);

#endif
