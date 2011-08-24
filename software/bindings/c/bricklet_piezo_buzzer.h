/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_PIEZO_BUZZER_H
#define BRICKLET_PIEZO_BUZZER_H

#include "ip_connection.h"

typedef Device PiezoBuzzer;

#define PIEZO_BUZZER_CALLBACK_BEEP_FINISHED 3
#define PIEZO_BUZZER_CALLBACK_MORSE_CODE_FINISHED 4

void piezo_buzzer_create(PiezoBuzzer *piezo_buzzer, const char *uid);

int piezo_buzzer_beep(PiezoBuzzer *piezo_buzzer, uint32_t duration);
int piezo_buzzer_morse_code(PiezoBuzzer *piezo_buzzer, char morse[60]);
int piezo_buzzer_beep_finished(PiezoBuzzer *piezo_buzzer);
int piezo_buzzer_morse_code_finished(PiezoBuzzer *piezo_buzzer);

void piezo_buzzer_register_callback(PiezoBuzzer *piezo_buzzer, uint8_t cb, void *func);

#endif