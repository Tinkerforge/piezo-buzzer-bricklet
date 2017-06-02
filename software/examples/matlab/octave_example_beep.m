function octave_example_beep()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Piezo Buzzer Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    pb = javaObject("com.tinkerforge.BrickletPiezoBuzzer", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Make 2 second beep
    pb.beep(2000);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
