#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Piezo Buzzer Bricklet

# Morse SOS
tinkerforge call piezo-buzzer-bricklet $uid morse-code "... --- ..."
