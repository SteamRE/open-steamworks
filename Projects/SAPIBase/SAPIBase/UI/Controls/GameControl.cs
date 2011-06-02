using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.IO;
using System.Net;
using System.Diagnostics;

namespace SAPIBase
{
    public partial class GameControl : UserControl
    {
        public string GameName { get; set; }

        public uint AppID { get; set; }

        public string Icon { get; set; }

        public bool Selected { get; set; }


        private Image iconImage;

        static object lockObj = new object();

        static int downloaders = 0;
        static object dlLock = new object();


        public GameControl()
        {
            InitializeComponent();

            ResizeRedraw = true;

            iconImage = null;
        }

        protected override void OnDoubleClick( EventArgs e )
        {
            // display launch type dialog
        }

        protected override void OnMouseClick( MouseEventArgs e )
        {
            if ( !Selected )
            {
                GamePanel gamePanel = this.Parent as GamePanel;

                if ( gamePanel == null )
                {
                    DebugLog.AppendText( "GameControl::OnMouseClick() - Parent control is not GamePanel!!!" );
                    return;
                }

                gamePanel.SelectGame( this );
            }

            if ( e.Button == MouseButtons.Right )
            {
                MainForm mf = this.ParentForm as MainForm;

                if ( mf == null )
                {
                    DebugLog.AppendText( "GameControl::OnMouseClick() - Parent form is not MainForm!!!" );
                    return;
                }

                mf.ShowContextMenu( this, e.Location );
            }
        }

        protected override void OnPaint( PaintEventArgs e )
        {
            base.OnPaint( e );

            Graphics gfx = e.Graphics;

            if ( iconImage == null )
            {
                string appName = Steam.GetAppData( AppID, "name" );
                string displayText = string.Format( "{0}\n{1}\nAppID: {2}", GameName, appName, AppID );

                Font gameFont = new Font( "Tahoma", 8 );
                SizeF size = gfx.MeasureString( displayText, gameFont );

                gfx.DrawString( displayText, gameFont, Brushes.Black, new PointF( 5, ( this.Height / 2.0f ) - ( size.Height / 2.0f ) ) );
            }
            else
            {
                gfx.DrawImage( iconImage, 0, 0, this.Width, this.Height );
            }

            if ( Selected )
            {
                Brush br = new SolidBrush( Color.FromArgb( 127, 0, 200, 0 ) );
                Rectangle bounds = new Rectangle( 0, 0, this.Width, this.Height );

                gfx.FillRectangle( br, bounds );
            }

        }

        public void RequestIcon()
        {
            if ( string.IsNullOrEmpty( Icon ) )
                return; // nothing to request!

            try
            {
                ThreadPool.QueueUserWorkItem( RequestWork );
            }
            catch ( Exception ex )
            {
                DebugLog.AppendText( "GameControl::RequestIcon() Failed: {0}", ex.Message );
                NotifyFinished( false );
            }
        }


        void NotifyFinished( bool success )
        {
            this.Invalidate();
        }

        void RequestFinished( bool success )
        {
            try
            {
                this.Invoke( new MethodInvoker( () => { this.NotifyFinished( success ); } ) );
            }
            catch ( InvalidOperationException )
            {
            }
        }

        static void FinishDL()
        {
            Monitor.Enter( dlLock );

            downloaders--;

            Monitor.Exit( dlLock );
        }

        static void WaitToDL( int maxDownloaders )
        {
        wait:

            Monitor.Enter( dlLock );

            if ( downloaders > maxDownloaders )
            {
                Monitor.Exit( dlLock );

                Thread.Sleep( 10 );
                goto wait;
            }

            downloaders++;

            Monitor.Exit( dlLock );
        }

        //http://media.steampowered.com/steamcommunity/public/images/apps/440/6f6d22ab0c357d9f02a11f76ff35797e4ccdf19f.jpg
        void RequestWork( object state )
        {
            string localPath = Path.Combine( Application.StartupPath, "cache" );

            Monitor.Enter( lockObj );

            if ( !Directory.Exists( localPath ) )
            {
                try
                {
                    DebugLog.AppendText( "GameControl::RequestWork() - Creating cache directory..." );
                    Directory.CreateDirectory( localPath );
                }
                catch ( Exception ex )
                {
                    DebugLog.AppendText( "Failed: {0}", ex.Message );

                    RequestFinished( false );

                    Monitor.Exit( lockObj );
                    return;
                }
            }

            Monitor.Exit( lockObj );

            string localFile = Path.Combine( localPath, AppID + ".jpg" );

            // is it cached?
            if ( File.Exists( localFile ) )
            {
                try
                {
                    iconImage = Image.FromFile( localFile );

                    RequestFinished( true );
                    return;
                }
                catch ( Exception ex )
                {
                    DebugLog.AppendText( "GameControl::RequestWork() - Unable to load cached image: {0}", ex.Message );

                    // image is messed up, lets try to redownload it
                    try
                    {
                        DebugLog.AppendText( "GameControl::RequestWork() - Deleting corrupt image..." );
                        File.Delete( localFile );
                    }
                    catch ( Exception ex2 )
                    {
                        DebugLog.AppendText( "Unable to delete image: {0}", ex2.Message );

                        // can't delete the cached file? welp.
                        RequestFinished( false );
                        return;
                    }
                }
            }

            string uri = "http://media.steampowered.com/steamcommunity/public/images/apps/";

            uri += AppID + "/";
            uri += Icon + ".jpg";

            // 2 maximum downloaders
            WaitToDL( 2 );

            using ( WebClient client = new WebClient() )
            {
                try
                {
                    client.DownloadFile( uri, localFile );
                }
                catch
                {
                    RequestFinished( false );

                    FinishDL();
                    return;
                }
            }

            FinishDL();

            try
            {
                iconImage = Image.FromFile( localFile );

                RequestFinished( true );
            }
            catch ( Exception ex )
            {
                DebugLog.AppendText( "GameControl::RequestWork() - Unable to load image: {0}", ex.Message );

                RequestFinished( false );
            }

        }
    }
}
