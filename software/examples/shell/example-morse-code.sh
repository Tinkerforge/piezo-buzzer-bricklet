#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# morse SOS
tinkerforge call piezo-buzzer-bricklet $uid morse-code "... --- ..."
