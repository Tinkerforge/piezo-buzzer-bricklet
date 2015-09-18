function octave_example_morse_code()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    pb = java_new("com.tinkerforge.BrickletPiezoBuzzer", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Morse SOS
    pb.morseCode("... --- ...");

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
