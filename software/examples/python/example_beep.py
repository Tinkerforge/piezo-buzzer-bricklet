#!/usr/bin/env python
# -*- coding: utf-8 -*-  

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_piezo_buzzer import PiezoBuzzer

if __name__ == "__main__":
    ipcon = IPConnection(HOST, PORT) # Create IP connection to brickd

    pb = PiezoBuzzer(UID) # Create device object
    ipcon.add_device(pb) # Add device to IP connection
    # Don't use device before it is added to a connection

    # Make 2 second beep
    pb.beep(2000)

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.destroy()
