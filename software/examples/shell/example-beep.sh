#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Piezo Buzzer Bricklet

# Make 2 second beep
tinkerforge call piezo-buzzer-bricklet $uid beep 2000
