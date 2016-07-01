#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Piezo Buzzer Bricklet

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_piezo_buzzer import BrickletPiezoBuzzer

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    pb = BrickletPiezoBuzzer(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Make 2 second beep
    pb.beep(2000)

    raw_input("Press key to exit\n") # Use input() in Python 3
    ipcon.disconnect()
