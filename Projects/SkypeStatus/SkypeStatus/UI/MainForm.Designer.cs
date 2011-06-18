namespace SkypeStatus
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose( bool disposing )
        {
            if ( disposing && ( components != null ) )
            {
                components.Dispose();
            }
            base.Dispose( disposing );
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager( typeof( MainForm ) );
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.btnSkypeAttach = new System.Windows.Forms.Button();
            this.lblSteam = new System.Windows.Forms.Label();
            this.lblSkype = new System.Windows.Forms.Label();
            this.btnSteamAttach = new System.Windows.Forms.Button();
            this.txtLog = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.notifyIcon = new System.Windows.Forms.NotifyIcon( this.components );
            this.notifyStrip = new System.Windows.Forms.ContextMenuStrip( this.components );
            this.showToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tableLayoutPanel1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.notifyStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 50F ) );
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 50F ) );
            this.tableLayoutPanel1.Controls.Add( this.btnSkypeAttach, 1, 1 );
            this.tableLayoutPanel1.Controls.Add( this.lblSteam, 0, 0 );
            this.tableLayoutPanel1.Controls.Add( this.lblSkype, 0, 1 );
            this.tableLayoutPanel1.Controls.Add( this.btnSteamAttach, 1, 0 );
            this.tableLayoutPanel1.Controls.Add( this.txtLog, 0, 2 );
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point( 3, 3 );
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 3;
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Percent, 25F ) );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Percent, 25F ) );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Percent, 50F ) );
            this.tableLayoutPanel1.Size = new System.Drawing.Size( 429, 275 );
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // btnSkypeAttach
            // 
            this.btnSkypeAttach.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.btnSkypeAttach.Location = new System.Drawing.Point( 218, 72 );
            this.btnSkypeAttach.Name = "btnSkypeAttach";
            this.btnSkypeAttach.Size = new System.Drawing.Size( 207, 61 );
            this.btnSkypeAttach.TabIndex = 3;
            this.btnSkypeAttach.Text = "Attach";
            this.btnSkypeAttach.UseVisualStyleBackColor = true;
            this.btnSkypeAttach.Click += new System.EventHandler( this.btnSkypeAttach_Click );
            // 
            // lblSteam
            // 
            this.lblSteam.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.lblSteam.AutoSize = true;
            this.lblSteam.Location = new System.Drawing.Point( 4, 1 );
            this.lblSteam.Name = "lblSteam";
            this.lblSteam.Size = new System.Drawing.Size( 207, 67 );
            this.lblSteam.TabIndex = 0;
            this.lblSteam.Text = "Steam Status: Unknown";
            this.lblSteam.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblSkype
            // 
            this.lblSkype.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.lblSkype.AutoSize = true;
            this.lblSkype.Location = new System.Drawing.Point( 4, 69 );
            this.lblSkype.Name = "lblSkype";
            this.lblSkype.Size = new System.Drawing.Size( 207, 67 );
            this.lblSkype.TabIndex = 1;
            this.lblSkype.Text = "Skype Status: Unknown";
            this.lblSkype.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // btnSteamAttach
            // 
            this.btnSteamAttach.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.btnSteamAttach.Location = new System.Drawing.Point( 218, 4 );
            this.btnSteamAttach.Name = "btnSteamAttach";
            this.btnSteamAttach.Size = new System.Drawing.Size( 207, 61 );
            this.btnSteamAttach.TabIndex = 2;
            this.btnSteamAttach.Text = "Attach";
            this.btnSteamAttach.UseVisualStyleBackColor = true;
            this.btnSteamAttach.Click += new System.EventHandler( this.btnSteamAttach_Click );
            // 
            // txtLog
            // 
            this.txtLog.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.tableLayoutPanel1.SetColumnSpan( this.txtLog, 2 );
            this.txtLog.Location = new System.Drawing.Point( 4, 140 );
            this.txtLog.Multiline = true;
            this.txtLog.Name = "txtLog";
            this.txtLog.Size = new System.Drawing.Size( 421, 131 );
            this.txtLog.TabIndex = 4;
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add( this.tableLayoutPanel1 );
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point( 0, 0 );
            this.panel1.Name = "panel1";
            this.panel1.Padding = new System.Windows.Forms.Padding( 3 );
            this.panel1.Size = new System.Drawing.Size( 437, 283 );
            this.panel1.TabIndex = 1;
            // 
            // notifyIcon
            // 
            this.notifyIcon.ContextMenuStrip = this.notifyStrip;
            this.notifyIcon.Icon = ( ( System.Drawing.Icon )( resources.GetObject( "notifyIcon.Icon" ) ) );
            this.notifyIcon.Text = "Skype Status";
            this.notifyIcon.Visible = true;
            this.notifyIcon.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler( this.notifyIcon_MouseDoubleClick );
            // 
            // notifyStrip
            // 
            this.notifyStrip.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.showToolStripMenuItem,
            this.toolStripMenuItem1,
            this.exitToolStripMenuItem} );
            this.notifyStrip.Name = "contextMenuStrip1";
            this.notifyStrip.Size = new System.Drawing.Size( 134, 54 );
            this.notifyStrip.Opening += new System.ComponentModel.CancelEventHandler( this.contextMenuStrip1_Opening );
            // 
            // showToolStripMenuItem
            // 
            this.showToolStripMenuItem.Name = "showToolStripMenuItem";
            this.showToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.showToolStripMenuItem.Text = "Show/Hide";
            this.showToolStripMenuItem.Click += new System.EventHandler( this.showToolStripMenuItem_Click );
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size( 149, 6 );
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Image = ( ( System.Drawing.Image )( resources.GetObject( "exitToolStripMenuItem.Image" ) ) );
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size( 133, 22 );
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler( this.exitToolStripMenuItem_Click );
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 437, 283 );
            this.Controls.Add( this.panel1 );
            this.Icon = ( ( System.Drawing.Icon )( resources.GetObject( "$this.Icon" ) ) );
            this.Name = "MainForm";
            this.Text = "Skype Status";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler( this.MainForm_FormClosing );
            this.tableLayoutPanel1.ResumeLayout( false );
            this.tableLayoutPanel1.PerformLayout();
            this.panel1.ResumeLayout( false );
            this.notifyStrip.ResumeLayout( false );
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btnSkypeAttach;
        private System.Windows.Forms.Label lblSteam;
        private System.Windows.Forms.Label lblSkype;
        private System.Windows.Forms.Button btnSteamAttach;
        private System.Windows.Forms.TextBox txtLog;
        private System.Windows.Forms.NotifyIcon notifyIcon;
        private System.Windows.Forms.ContextMenuStrip notifyStrip;
        private System.Windows.Forms.ToolStripMenuItem showToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
    }
}

