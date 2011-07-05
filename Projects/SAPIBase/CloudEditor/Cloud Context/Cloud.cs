using System;
using System.Collections.Generic;
using System.Text;
using SAPIBase;
using System.IO;

namespace CloudEditor
{
    static class Cloud
    {
        public struct FileInfo
        {
            public string FileName { get; set; }
            public int Size { get; set; }
        }

        public static void Initialize( int appID )
        {
            Environment.SetEnvironmentVariable( "SteamAppId", appID.ToString() );

            CloudContext.Initialize();
        }

        public static bool IsEnabled()
        {
            int total = 0;
            int avail = 0;

            bool bRet = CloudContext.RemoteStorage.GetQuota( ref total, ref avail );

            return bRet;
        }

        public static FileInfo[] GetFiles()
        {
            int fileCount = CloudContext.RemoteStorage.GetFileCount();

            DebugLog.AppendText( "ISteamRemoteStorage::GetFileCount() = {0}", fileCount );

            FileInfo[] files = new FileInfo[ fileCount ];

            for ( int x = 0 ; x < fileCount ; ++x )
            {
                int fileSize = 0;
                string fileName = CloudContext.RemoteStorage.GetFileNameAndSize( x, ref fileSize );

                DebugLog.AppendText( "ISteamRemoteStorage::GetFileNameAndSize( {0} ) = \"{1}\", {2}", x, fileName, fileSize );

                files[ x ].FileName = fileName;
                files[ x ].Size = fileSize;
            }

            return files;

        }

        public static bool DeleteFile( string fileName )
        {
            bool bRet = CloudContext.RemoteStorageOld.FileDelete( fileName );

            DebugLog.AppendText( "ISteamRemoteStorage::FileDelete( \"{0}\" ) = {1}", fileName, bRet );

            return bRet;
        }

        public static byte[] ReadFile( string fileName )
        {
            int fileSize = CloudContext.RemoteStorage.GetFileSize( fileName );

            DebugLog.AppendText( "ISteamRemoteStorage::GetFileSize( \"{0}\" ) = {1}", fileName, fileSize );

            byte[] data = new byte[ fileSize ];

            int iRet = CloudContext.RemoteStorage.FileRead( fileName, data );

            DebugLog.AppendText( "ISteamRemoteStorage::FileRead( \"{0}\", {1} ) = {2}", fileName, fileSize, iRet );

            return data;
        }

        public static bool WriteFile( string fileName, byte[] data )
        {
            bool bRet = CloudContext.RemoteStorage.FileWrite( fileName, data );

            DebugLog.AppendText( "ISteamRemoteStorage::FileWrite( \"{0}\", {1} ) = {2}", fileName, data.Length, bRet );

            return bRet;
        }


        public static bool GetQuota( out int total, out int avail )
        {
            total = 0;
            avail = 0;

            bool bRet = CloudContext.RemoteStorage.GetQuota( ref total, ref avail );

            if ( bRet )
                DebugLog.AppendText( "ISteamRemoteStorage::GetQuota() = {0}, {1}", total, avail );
            else
                DebugLog.AppendText( "ISteamRemoteStorage::GetQuota() Failed!" );

            return bRet;
        }

        public static void Shutdown()
        {
            CloudContext.Shutdown();
        }
    }
}