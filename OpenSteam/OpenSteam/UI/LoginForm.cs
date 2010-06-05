using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Steam4NET;
using System.Threading;

namespace OpenSteam
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
        }

        bool IsInputValid()
        {
            if ( String.IsNullOrEmpty( userTextBox.Text ) )
            {
                MessageBox.Show( this, "Please enter a username." );
                return false;
            }

            if ( String.IsNullOrEmpty( passTextBox.Text ) )
            {
                MessageBox.Show( this, "Please enter a password." );
                return false;
            }

            return true;
        }

        private void okButton_Click( object sender, EventArgs e )
        {
            if ( !IsInputValid() )
                return;

            Steam3.ReadyLogin( userTextBox.Text, passTextBox.Text );

            try
            {
                int loginHandle = Steam2.Login( userTextBox.Text, passTextBox.Text );

                ProgressForm pf = new ProgressForm( loginHandle );
                pf.SetProgress( "Logging in..." );
                pf.ShowDialog( this );
                if ( pf.DialogResult == DialogResult.Cancel )
                {
                    string errorMsg = string.Format( "Unable to login!\n\n{0}", Utils.GetDisplayError( pf.ErrorInfo ) );
                    MessageBox.Show( this, errorMsg );

                    return;
                }

                TSteamGlobalUserID userId = Steam2.GetUser();
                string email = Steam2.GetEmailAddress();

                // SetFromSteam2
                CSteamID steamId = new CSteamID( 0 );
                steamId.AccountID = ( userId.Low32Bits * 2 ) + userId.High32Bits;
                steamId.AccountUniverse = Steam3.GetUniverse();
                steamId.AccountType = EAccountType.k_EAccountTypeIndividual;
                steamId.AccountInstance = 1;

                if ( !Steam3.SetEmail( email ) )
                {
                    string errorMsg = string.Format( "Unable to login!\n\nUnable to set email address." );
                    MessageBox.Show( this, errorMsg );

                    return;
                }

                Steam3.LogOn( steamId );

                while ( Steam3.GetLogonState() == ELogonState.k_ELogonStateLoggingOn )
                {
                    Application.DoEvents();
                    Thread.Sleep( 1 );
                }
            }
            catch ( SteamException ex )
            {
                string errorMsg = string.Format( "Unable to login!\n\n{0}", Utils.GetDisplayError( ex.ErrorInfo ) );
                MessageBox.Show( this, errorMsg );

                DialogResult = DialogResult.Cancel;
                this.Close();
                return;
            }

            DialogResult = DialogResult.OK;
            this.Close();
        }

        private void cancelButton_Click( object sender, EventArgs e )
        {
            DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}