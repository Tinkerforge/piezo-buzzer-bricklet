function matlab_example_beep()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletPiezoBuzzer;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Piezo Buzzer Bricklet

    ipcon = IPConnection(); % Create IP connection
    pb = handle(BrickletPiezoBuzzer(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Make 2 second beep
    pb.beep(2000);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
