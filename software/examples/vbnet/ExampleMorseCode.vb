Imports Tinkerforge

Module ExampleMorseCode
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "6tU" ' Change to your UID

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim pb As New BrickletPiezoBuzzer(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Morse SOS
        pb.MorseCode("... --- ...")

        System.Console.WriteLine("Press key to exit")
        System.Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
