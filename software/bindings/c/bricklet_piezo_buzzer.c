/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_piezo_buzzer.h"

#include <string.h>

#define TYPE_BEEP 1
#define TYPE_MORSE_CODE 2
#define TYPE_BEEP_FINISHED 3
#define TYPE_MORSE_CODE_FINISHED 4

typedef void (*beep_finished_func_t)();
typedef void (*morse_code_finished_func_t)();

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t duration;
} PACKED Beep;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char morse[60];
} PACKED MorseCode;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED BeepFinishedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED MorseCodeFinishedCallback;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int piezo_buzzer_beep(PiezoBuzzer *piezo_buzzer, uint32_t duration) {
	if(piezo_buzzer->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(piezo_buzzer);

	Beep b;
	b.stack_id = piezo_buzzer->stack_id;
	b.type = TYPE_BEEP;
	b.length = sizeof(Beep);
	b.duration = duration;

	ipcon_device_write(piezo_buzzer, (char *)&b, sizeof(Beep));

	ipcon_sem_post_write(piezo_buzzer);

	return E_OK;
}

int piezo_buzzer_morse_code(PiezoBuzzer *piezo_buzzer, char morse[60]) {
	if(piezo_buzzer->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(piezo_buzzer);

	MorseCode mc;
	mc.stack_id = piezo_buzzer->stack_id;
	mc.type = TYPE_MORSE_CODE;
	mc.length = sizeof(MorseCode);
	strcpy(mc.morse, morse);


	ipcon_device_write(piezo_buzzer, (char *)&mc, sizeof(MorseCode));

	ipcon_sem_post_write(piezo_buzzer);

	return E_OK;
}

int piezo_buzzer_callback_beep_finished(PiezoBuzzer *piezo_buzzer, const unsigned char *buffer) {
	BeepFinishedCallback *bfc = (BeepFinishedCallback *)buffer;
	((beep_finished_func_t)piezo_buzzer->callbacks[bfc->type])();
	return sizeof(BeepFinishedCallback);
}

int piezo_buzzer_callback_morse_code_finished(PiezoBuzzer *piezo_buzzer, const unsigned char *buffer) {
	MorseCodeFinishedCallback *mcfc = (MorseCodeFinishedCallback *)buffer;
	((morse_code_finished_func_t)piezo_buzzer->callbacks[mcfc->type])();
	return sizeof(MorseCodeFinishedCallback);
}

void piezo_buzzer_register_callback(PiezoBuzzer *piezo_buzzer, uint8_t cb, void *func) {
    piezo_buzzer->callbacks[cb] = func;
}

void piezo_buzzer_create(PiezoBuzzer *piezo_buzzer, const char *uid) {
	ipcon_device_create(piezo_buzzer, uid);

	piezo_buzzer->device_callbacks[TYPE_BEEP_FINISHED] = piezo_buzzer_callback_beep_finished;
	piezo_buzzer->device_callbacks[TYPE_MORSE_CODE_FINISHED] = piezo_buzzer_callback_morse_code_finished;
}
