using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using Steam4NET;

namespace OpenSteam
{
    public partial class ProgressForm : Form
    {
        int callHandle;
        public TSteamError ErrorInfo { get; private set; }

        public ProgressForm( int callHandle )
        {
            this.callHandle = callHandle;

            InitializeComponent();

            ThreadPool.QueueUserWorkItem( ProgressFunc );
        }

        public void SetProgress( string text )
        {
            if ( this.InvokeRequired )
            {
                this.Invoke( ( MethodInvoker )delegate
                {
                    if ( label2.Text != text )
                        label2.Text = text;
                } );
            }
            else
            {
                if ( label2.Text != text )
                    label2.Text = text;
            }

        }

        void FinishError( TSteamError error )
        {
            ErrorInfo = error;

            this.Invoke( ( MethodInvoker )delegate
            {
                DialogResult = DialogResult.Cancel;
                this.Close();
            } );

        }
        void Finish()
        {
            this.Invoke( ( MethodInvoker )delegate
            {
                DialogResult = DialogResult.OK;
                this.Close();
            } );
        }

        void ProgressFunc( object state )
        {
            while ( !this.IsHandleCreated )
            {
                Thread.Sleep( 10 ); // spin until we have a handle
            }

            TSteamError error = new TSteamError();
            TSteamProgress progress = new TSteamProgress();

            while ( Steam2.SteamProcessCall( callHandle, ref progress, ref error ) == 0 )
            {
                SetProgress( progress.Progress );

                Thread.Sleep( 10 );
            }

            if ( error.eSteamError != ESteamError.eSteamErrorNone )
            {
                FinishError( error );
                return;
            }

            Finish();
        }
    }
}
