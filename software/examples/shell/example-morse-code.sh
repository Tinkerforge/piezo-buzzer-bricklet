#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change to your UID

# Morse SOS
tinkerforge call piezo-buzzer-bricklet $uid morse-code "... --- ..."
