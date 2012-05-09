<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletPiezoBuzzer.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletPiezoBuzzer;

$host = 'localhost';
$port = 4223;
$uid = '6tU'; // Change to your UID

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$pb = new BrickletPiezoBuzzer($uid); // Create device object

$ipcon->addDevice($pb); // Add device to IP connection
// Don't use device before it is added to a connection

// Morse SOS
$pb->morseCode('... --- ...');

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->destroy();

?>
