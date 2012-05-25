#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_piezo_buzzer'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = '6tU' # Change to your UID

ipcon = IPConnection.new HOST, PORT # Create IP connection to brickd
pb = BrickletPiezoBuzzer.new UID # Create device object
ipcon.add_device pb # Add device to IP connection
# Don't use device before it is added to a connection

# Morse SOS
pb.morse_code '... --- ...'

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
