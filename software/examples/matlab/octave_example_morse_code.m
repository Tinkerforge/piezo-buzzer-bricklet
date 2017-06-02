function octave_example_morse_code()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Piezo Buzzer Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    pb = javaObject("com.tinkerforge.BrickletPiezoBuzzer", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Morse SOS
    pb.morseCode("... --- ...");

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
