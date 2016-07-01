Imports System
Imports Tinkerforge

Module ExampleMorseCode
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Piezo Buzzer Bricklet

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim pb As New BrickletPiezoBuzzer(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Morse SOS
        pb.MorseCode("... --- ...")

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
