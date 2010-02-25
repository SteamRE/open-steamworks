
namespace ChatLog
{
    using System;
    using System.ComponentModel;
    using System.Windows.Forms;

    class Notification : Component
    {
        private ContextMenuStrip contextMenuStrip1;
        private IContainer components;
        private ToolStripMenuItem showSettingsItem;
        private ToolStripSeparator toolStripSeparator1;
        private NotifyIcon notifyIcon1;
        private ToolStripMenuItem exitItem;


        public event EventHandler ShowSettings;
        public event EventHandler Exit;

        public bool Visible
        {
            get { return notifyIcon1.Visible; }
            set { notifyIcon1.Visible = value; }
        }


        public Notification()
        {
            InitializeComponent();

            notifyIcon1.Icon = Properties.Resources.logger;

            showSettingsItem.Click += new EventHandler( showSettingsItem_Click );
            exitItem.Click += new EventHandler( exitItem_Click );
        }

        public void ShowError( string message )
        {
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Error;
            notifyIcon1.ShowBalloonTip( 10 * 1000, "Error", message, ToolTipIcon.Error );
        }

        public void ShowInfo( string message )
        {
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Info;
            notifyIcon1.ShowBalloonTip( 10 * 1000, "Info", message, ToolTipIcon.Error );
        }

        void exitItem_Click( object sender, EventArgs e )
        {
            OnExit( e );
        }
        void showSettingsItem_Click( object sender, EventArgs e )
        {
            OnShowSettings( e );
        }

        protected virtual void OnShowSettings( EventArgs e )
        {
            if ( ShowSettings != null )
                ShowSettings( this, e );
        }
        protected virtual void OnExit( EventArgs e )
        {
            if ( Exit != null )
                Exit( this, e );
        }

        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip( this.components );
            this.showSettingsItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitItem = new System.Windows.Forms.ToolStripMenuItem();
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon( this.components );
            this.contextMenuStrip1.SuspendLayout();
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.showSettingsItem,
            this.toolStripSeparator1,
            this.exitItem} );
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size( 143, 54 );
            // 
            // showSettingsItem
            // 
            this.showSettingsItem.Name = "showSettingsItem";
            this.showSettingsItem.Size = new System.Drawing.Size( 142, 22 );
            this.showSettingsItem.Text = "Show Settings";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size( 139, 6 );
            // 
            // exitItem
            // 
            this.exitItem.Name = "exitItem";
            this.exitItem.Size = new System.Drawing.Size( 142, 22 );
            this.exitItem.Text = "Exit";
            // 
            // notifyIcon1
            // 
            this.notifyIcon1.BalloonTipIcon = System.Windows.Forms.ToolTipIcon.Info;
            this.notifyIcon1.ContextMenuStrip = this.contextMenuStrip1;
            this.notifyIcon1.Text = "Steam Chat Logger";
            this.notifyIcon1.Visible = true;
            this.notifyIcon1.BalloonTipClicked += new System.EventHandler( this.notifyIcon1_BalloonTipClicked );
            this.notifyIcon1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler( this.notifyIcon1_MouseDoubleClick );
            this.contextMenuStrip1.ResumeLayout( false );

        }

        private void notifyIcon1_BalloonTipClicked( object sender, EventArgs e )
        {
            OnShowSettings( e );
        }

        private void notifyIcon1_MouseDoubleClick( object sender, MouseEventArgs e )
        {
            OnShowSettings( EventArgs.Empty );
        }
    }
}
