<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletPiezoBuzzer.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletPiezoBuzzer;

const HOST = 'localhost';
const PORT = 4223;
const UID = '6tU'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$pb = new BrickletPiezoBuzzer(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Make 2 second beep
$pb->beep(2000);

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
