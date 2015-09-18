#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change to your UID

# Make 2 second beep
tinkerforge call piezo-buzzer-bricklet $uid beep 2000
