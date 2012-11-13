/* piezo-buzzer-bricklet
 * Copyright (C) 2011-2012 Olaf Lüke <olaf@tinkerforge.com>
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

#include "bricklib/com/com_common.h"

#define FID_BEEP 1
#define FID_MORSE_CODE 2
#define FID_BEEP_FINISHED 3
#define FID_MORSE_CODE_FINISHED 4

typedef struct {
	MessageHeader header;
} __attribute__((__packed__)) StandardMessage;

typedef struct {
	MessageHeader header;
	uint32_t duration;
} __attribute__((__packed__)) Beep;

typedef struct {
	MessageHeader header;
	char morse[60];
} __attribute__((__packed__)) MorseCode;

void beep(const ComType com, const Beep *data);
void morse_code(const ComType com, const MorseCode *data);

void invocation(const ComType com, const uint8_t *data);
void constructor(void);
void destructor(void);
void tick(const uint8_t tick_type);

#endif
