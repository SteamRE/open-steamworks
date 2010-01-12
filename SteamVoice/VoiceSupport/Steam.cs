using System;
using System.Collections.Generic;
using System.Text;
using dotnetworks;

namespace VoiceSupport
{
    public class Steam
    {
        static SteamClient008 steamClient;

        static SteamPipeHandle pipe;
        static SteamUserHandle user;

        static SteamUser012 steamUser;

        public static void Init()
        {
            int error;
            steamClient = (SteamClient008)Steamworks.CreateInterface( SteamClient008.InterfaceVersion, out error );

            pipe = steamClient.CreateSteamPipe();
            user = steamClient.ConnectToGlobalUser( pipe );

            steamUser = (SteamUser012)steamClient.GetISteamUser( user, pipe, SteamUser012.InterfaceVersion );
        }

        public static void StartRecording()
        {
            steamUser.StartVoiceRecording();
        }

        public static void StopRecording()
        {
            steamUser.StopVoiceRecording();
        }

        public static byte[] GetCompressedVoiceData()
        {
            uint buffSize = 1024 * 20; // start with 20kb
            byte[] voiceBuff = new byte[ buffSize ];
            uint written;
            VoiceResult result;

            while ( true )
            {
                result = steamUser.GetCompressedVoice( voiceBuff, buffSize, out written );

                if ( result == VoiceResult.DataCorrupted || result == VoiceResult.NoData || result == VoiceResult.NotInitialized )
                    return new byte[ 0 ];

                if ( result == VoiceResult.OK || result == VoiceResult.NotRecording )
                    break;

                if ( result == VoiceResult.BufferTooSmall )
                {
                    buffSize += ( 1024 * 10 ); // add another 10kb
                    voiceBuff = new byte[ buffSize ];
                    continue;
                }
            }

            byte[] returnData = new byte[ written ];
            Array.Copy( voiceBuff, 0, returnData, 0, written );

            return returnData;
        }

        public static byte[] DecompressVoice( byte[] input )
        {
            uint decompSize = (uint)( input.Length * 2 );
            byte[] decompressed = new byte[ decompSize ];
            VoiceResult result;
            uint written;

            while ( true )
            {
                result = steamUser.DecompressVoice( input, (uint)input.Length, decompressed, decompSize, out written );

                if ( result == VoiceResult.DataCorrupted || result == VoiceResult.NoData || result == VoiceResult.NotInitialized )
                    return new byte[ 0 ];

                if ( result == VoiceResult.OK )
                    break;

                if ( result == VoiceResult.BufferTooSmall )
                {
                    decompSize += ( 1024 * 10 );
                    decompressed = new byte[ decompSize ];
                    continue;
                }
            }

            byte[] returnData = new byte[ written ];
            Array.Copy( decompressed, 0, returnData, 0, written );

            return returnData;
        }
    }
}
