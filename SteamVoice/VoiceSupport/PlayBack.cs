using System;
using System.Collections.Generic;
using System.Text;
using FMOD;
using System.Runtime.InteropServices;

namespace VoiceSupport
{
    public class PlayBack
    {
        static FMOD.System system = null;

        public static void Init()
        {
            Factory.System_Create( ref system );

            system.init( 32, FMOD.INITFLAGS.NORMAL, IntPtr.Zero );
        }

        public static void PlayData( byte[] data )
        {
            CREATESOUNDEXINFO exInfo = new CREATESOUNDEXINFO();

            exInfo.cbsize = Marshal.SizeOf( exInfo );
            exInfo.length = (uint)data.Length;
            exInfo.defaultfrequency = 11025;
            exInfo.numchannels = 1;
            exInfo.format = SOUND_FORMAT.PCM16;

            Sound sound = null;
            system.createSound( data, MODE.HARDWARE | MODE.OPENMEMORY | MODE.OPENRAW, ref exInfo, ref sound );

            Channel chan = null;

            system.playSound( CHANNELINDEX.FREE, sound, false, ref chan );
        }
    }
}
