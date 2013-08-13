#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# make 2 second beep
tinkerforge call piezo-buzzer-bricklet $uid beep 2000
