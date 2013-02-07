<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletPiezoBuzzer.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletPiezoBuzzer;

$host = 'localhost';
$port = 4223;
$uid = '6tU'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$pb = new BrickletPiezoBuzzer($uid, $ipcon); // Create device object

$ipcon->connect($host, $port); // Connect to brickd
// Don't use device before ipcon is connected

// Morse SOS
$pb->morseCode('... --- ...');

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
