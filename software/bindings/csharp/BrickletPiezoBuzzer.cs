/*************************************************************
 * This file was automatically generated on 2011-09-20.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

namespace Tinkerforge
{
	public class BrickletPiezoBuzzer : Device 
	{
		private static byte TYPE_BEEP = 1;
		private static byte TYPE_MORSE_CODE = 2;
		private static byte TYPE_BEEP_FINISHED = 3;
		private static byte TYPE_MORSE_CODE_FINISHED = 4;

		public delegate void BeepFinished();
		public delegate void MorseCodeFinished();

		public BrickletPiezoBuzzer(string uid) : base(uid) 
		{
			messageCallbacks[TYPE_BEEP_FINISHED] = new MessageCallback(CallbackBeepFinished);
			messageCallbacks[TYPE_MORSE_CODE_FINISHED] = new MessageCallback(CallbackMorseCodeFinished);
		}

		public void Beep(uint duration)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_BEEP, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(duration, 4, data);

			ipcon.Write(this, data, TYPE_BEEP, false);
		}

		public void MorseCode(string morse)
		{
			byte[] data = new byte[64];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_MORSE_CODE, 1, data);
			LEConverter.To((ushort)64, 2, data);
			LEConverter.To(morse, 4, data);

			ipcon.Write(this, data, TYPE_MORSE_CODE, false);
		}

		public int CallbackBeepFinished(byte[] data)
		{
			((BeepFinished)callbacks[TYPE_BEEP_FINISHED])();
			return 4;
		}

		public int CallbackMorseCodeFinished(byte[] data)
		{
			((MorseCodeFinished)callbacks[TYPE_MORSE_CODE_FINISHED])();
			return 4;
		}

		public void RegisterCallback(System.Delegate d)
		{
			if(d.GetType() == typeof(BeepFinished))
			{
				callbacks[TYPE_BEEP_FINISHED] = d;
			}
			else if(d.GetType() == typeof(MorseCodeFinished))
			{
				callbacks[TYPE_MORSE_CODE_FINISHED] = d;
			}
		}
	}
}
