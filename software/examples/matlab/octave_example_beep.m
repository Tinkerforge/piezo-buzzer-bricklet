function octave_example_beep
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "mGW"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    pb = java_new("com.tinkerforge.BrickletPiezoBuzzer", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Make 2 second beep
    pb.beep(2000);

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end
