using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletPiezoBuzzer pb = new BrickletPiezoBuzzer(UID); // Create device object
		ipcon.AddDevice(pb); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Morse SOS
		pb.MorseCode("... --- ...");

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
		ipcon.Destroy();
	}
}
