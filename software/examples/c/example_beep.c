
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_piezo_buzzer.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

int main() {
	// Create IP connection to brickd
	IPConnection ipcon;
	if(ipcon_create(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not create connection\n");
		exit(1);
	}

	// Create device object
	PiezoBuzzer pb;
	piezo_buzzer_create(&pb, UID); 

	// Add device to IP connection
	if(ipcon_add_device(&ipcon, &pb) < 0) {
		fprintf(stderr, "Could not connect to Bricklet\n");
		exit(1);
	}
	// Don't use device before it is added to a connection

	// Make 2 second beep
	piezo_buzzer_beep(&pb, 2000);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
