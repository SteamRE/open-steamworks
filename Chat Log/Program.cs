/*
Copyright (c) 2009 Ryan Stecker

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

namespace ChatLog
{
    using System;
    using System.IO;
    using System.Threading;
    using System.Windows.Forms;
    using Steam4NET;

    static class Program
    {
        static Settings sets;

        static Notification notifyIcon;
        static LogManager logManager;

        static SettingsForm setsForm;

        static bool running = true;

        [STAThread]
        static void Main()
        {
            bool firstProcess;
            Mutex singleMutex = new Mutex
            (
                true,
                "SteamChatLogger_4d8g8hisih39", // this is hopefully a unique mutex string not present on the current system
                out firstProcess
            );

            if ( !firstProcess )
            {
                // process already exists, so we exit
                Util.ShowWarning( null, "Steam chat logger is already running. You may control it through context menus in the task bar icon." );
                return;
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault( false );

            // load our settings
            try
            {
                sets = Settings.Load( Settings.BackingFile );
            }
            catch ( FileNotFoundException )
            {
                // if the file isn't found, no biggie
                sets = new Settings();
                sets.Save();
            }
            catch ( Exception ex )
            {
                Util.ShowError( null, "Unable to load settings: " + ex.Message + "\n\nResetting to defaults." );
                sets = new Settings();
                sets.Save();
            }

            setsForm = new SettingsForm( sets );

            // initialize the notification icon context
            notifyIcon = new Notification();
            notifyIcon.Exit += new EventHandler( notifyIcon_Exit );
            notifyIcon.ShowSettings += new EventHandler( notifyIcon_ShowSettings );


            // initialize logging
            logManager = new LogManager( sets );
            logManager.LogFailure += new EventHandler<LogFailureEventArgs>( logManager_LogFailure );


            // gasp a label.. what could it be for?
        //SteamInit: // maybe someday this will come back (not likely)

            bool waited = false;

            if ( !logManager.GetSteamClient() )
            {
                Util.ShowFatalError( null, "Unable get SteamClient interface.\nThis indicates a major change in the steam client, please contact voidedweasel@gmail.com." );
                return;
            }

            if ( !logManager.GetPipe() )
            {
                notifyIcon.ShowError( "Steam is currently not running.. Waiting for it to startup." );
                waited = true;

                while ( !logManager.GetPipe() )
                {
                    Application.DoEvents();

                    Thread.Sleep( 2000 );
                }

                // get the pipe again just in case
                if ( !logManager.GetPipe() )
                {
                    Util.ShowFatalError( null, "Error getting steam pipe after steam startup!" );
                    return;
                }
            }

            while ( !logManager.GetUser() )
            {
                Application.DoEvents();

                Thread.Sleep( 2000 );
            }

            // wait for steam to full start itself
            if ( waited )
                Thread.Sleep( 10000 );

            // get the user again
            if ( !logManager.GetUser() )
            {
                Util.ShowFatalError( null, "Error getting steam user after steam startup!" );
                return;
            }


            if ( !logManager.GetInterface() )
            {
                Util.ShowFatalError( null, "Unable to get SteamFriends interface.\nThis indicates a major change in the steam client, please contact voidedweasel@gmail.com." );
                return;
            }


            if ( waited )
                notifyIcon.ShowInfo( "Steam is now running, logging enabled." );
           

            while ( running )
            {
                // CreateSteamPipe causes deadlocks, not using this for now
                /*if ( !logManager.GetPipe() )
                {
                    Util.ShowError( null, "Steam pipe error!\nAttempting to regain pipe..." );
                    goto SteamInit; // gasp! a goto!?
                }*/

                Application.DoEvents();

                Thread.Sleep( 10 );
            }

            logManager.Close();

            GC.KeepAlive( singleMutex );
        }

        static void logManager_LogFailure( object sender, LogFailureEventArgs e )
        {
            notifyIcon.ShowError( "Unable to log message: " + e.Reason + "\n\nPlease check settings." );
        }

        static void notifyIcon_ShowSettings( object sender, EventArgs e )
        {
            if ( setsForm == null )
                return;

            setsForm.Show();
            setsForm.SetGroupChatStatus( logManager.GetGroupChatStatus() );
        }

        static void notifyIcon_Exit( object sender, EventArgs e )
        {
            running = false;

            notifyIcon.Visible = false;
            setsForm.Close(); // this saves settings and hides the form
        }
    }
}
