using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletPiezoBuzzer pb = new BrickletPiezoBuzzer(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Make 2 second beep
		pb.Beep(2000);

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
	}
}
