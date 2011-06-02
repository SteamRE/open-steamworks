namespace ChatLog
{
    partial class SettingsForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager( typeof( SettingsForm ) );
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.browseBox = new ChatLog.BrowseTextBox();
            this.logFormatBox = new ChatLog.PreviewTextBox();
            this.emoteFormatBox = new ChatLog.PreviewTextBox();
            this.filenameBox = new ChatLog.PreviewTextBox();
            this.editLinkIdsBox = new System.Windows.Forms.Button();
            this.trackSessions = new System.Windows.Forms.CheckBox();
            this.sessionMinutes = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.enableGroupChats = new System.Windows.Forms.CheckBox();
            this.statusLabel = new System.Windows.Forms.Label();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.label4 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.invalidCharBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.dateFormatBox = new ChatLog.PreviewTextBox();
            this.timeFormatBox = new ChatLog.PreviewTextBox();
            this.linkLabel4 = new System.Windows.Forms.LinkLabel();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.helpBox = new System.Windows.Forms.RichTextBox();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.linkLabel3 = new System.Windows.Forms.LinkLabel();
            this.label14 = new System.Windows.Forms.Label();
            this.linkLabel2 = new System.Windows.Forms.LinkLabel();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.toolTip = new System.Windows.Forms.ToolTip( this.components );
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point( 3, 0 );
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size( 99, 29 );
            this.label1.TabIndex = 0;
            this.label1.Text = "Log Directory:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.toolTip.SetToolTip( this.label1, "The directory that log files will be stored in. You can use several variables des" +
                    "cribed in the Help & Formatting tab." );
            // 
            // label2
            // 
            this.label2.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point( 3, 29 );
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size( 99, 44 );
            this.label2.TabIndex = 3;
            this.label2.Text = "Filename:\r\n\r\n";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.toolTip.SetToolTip( this.label2, "The filename to store a specific log message in. You can use file variables descr" +
                    "ibed in Help & Formatting." );
            // 
            // label8
            // 
            this.label8.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point( 3, 119 );
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size( 99, 46 );
            this.label8.TabIndex = 7;
            this.label8.Text = "Emote Format:\r\n\r\n";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.toolTip.SetToolTip( this.label8, "This is the emotion log format. These are messages that are sent with the \"/me\" c" +
                    "ommand. Variables are described in Help & Formatting." );
            // 
            // label5
            // 
            this.label5.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point( 3, 73 );
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size( 99, 46 );
            this.label5.TabIndex = 5;
            this.label5.Text = "Message Format:\r\n\r\n";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.toolTip.SetToolTip( this.label5, "This is the format to write log messages to. Many variables are described in Help" +
                    " & Formatting" );
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add( this.tabPage1 );
            this.tabControl1.Controls.Add( this.tabPage2 );
            this.tabControl1.Controls.Add( this.tabPage3 );
            this.tabControl1.Controls.Add( this.tabPage4 );
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point( 0, 0 );
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size( 469, 427 );
            this.tabControl1.TabIndex = 11;
            this.tabControl1.Selecting += new System.Windows.Forms.TabControlCancelEventHandler( this.tabControl1_Selecting );
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add( this.tableLayoutPanel1 );
            this.tabPage1.Location = new System.Drawing.Point( 4, 22 );
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding( 3 );
            this.tabPage1.Size = new System.Drawing.Size( 461, 401 );
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Logging";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle() );
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 66.66666F ) );
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 33.33333F ) );
            this.tableLayoutPanel1.Controls.Add( this.label1, 0, 0 );
            this.tableLayoutPanel1.Controls.Add( this.label8, 0, 3 );
            this.tableLayoutPanel1.Controls.Add( this.label2, 0, 1 );
            this.tableLayoutPanel1.Controls.Add( this.label5, 0, 2 );
            this.tableLayoutPanel1.Controls.Add( this.browseBox, 1, 0 );
            this.tableLayoutPanel1.Controls.Add( this.logFormatBox, 1, 2 );
            this.tableLayoutPanel1.Controls.Add( this.emoteFormatBox, 1, 3 );
            this.tableLayoutPanel1.Controls.Add( this.filenameBox, 1, 1 );
            this.tableLayoutPanel1.Controls.Add( this.editLinkIdsBox, 0, 4 );
            this.tableLayoutPanel1.Controls.Add( this.trackSessions, 0, 5 );
            this.tableLayoutPanel1.Controls.Add( this.sessionMinutes, 1, 5 );
            this.tableLayoutPanel1.Controls.Add( this.label15, 2, 5 );
            this.tableLayoutPanel1.Controls.Add( this.enableGroupChats, 2, 6 );
            this.tableLayoutPanel1.Controls.Add( this.statusLabel, 0, 6 );
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point( 3, 3 );
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 7;
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Absolute, 20F ) );
            this.tableLayoutPanel1.Size = new System.Drawing.Size( 455, 395 );
            this.tableLayoutPanel1.TabIndex = 9;
            // 
            // browseBox
            // 
            this.tableLayoutPanel1.SetColumnSpan( this.browseBox, 2 );
            this.browseBox.Location = new System.Drawing.Point( 105, 0 );
            this.browseBox.Margin = new System.Windows.Forms.Padding( 0 );
            this.browseBox.Name = "browseBox";
            this.browseBox.Size = new System.Drawing.Size( 350, 29 );
            this.browseBox.TabIndex = 9;
            this.toolTip.SetToolTip( this.browseBox, "The directory that log files will be stored in. You can use several variables des" +
                    "cribed in the Help & Formatting tab." );
            // 
            // logFormatBox
            // 
            this.logFormatBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.tableLayoutPanel1.SetColumnSpan( this.logFormatBox, 2 );
            this.logFormatBox.Location = new System.Drawing.Point( 105, 73 );
            this.logFormatBox.Margin = new System.Windows.Forms.Padding( 0 );
            this.logFormatBox.Name = "logFormatBox";
            this.logFormatBox.Size = new System.Drawing.Size( 350, 46 );
            this.logFormatBox.TabIndex = 10;
            this.toolTip.SetToolTip( this.logFormatBox, "This is the format to write log messages to. Many variables are described in Help" +
                    " & Formatting" );
            // 
            // emoteFormatBox
            // 
            this.emoteFormatBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.tableLayoutPanel1.SetColumnSpan( this.emoteFormatBox, 2 );
            this.emoteFormatBox.Location = new System.Drawing.Point( 105, 119 );
            this.emoteFormatBox.Margin = new System.Windows.Forms.Padding( 0 );
            this.emoteFormatBox.Name = "emoteFormatBox";
            this.emoteFormatBox.Size = new System.Drawing.Size( 350, 46 );
            this.emoteFormatBox.TabIndex = 11;
            this.toolTip.SetToolTip( this.emoteFormatBox, "This is the emotion log format. These are messages that are sent with the \"/me\" c" +
                    "ommand. Variables are described in Help & Formatting." );
            // 
            // filenameBox
            // 
            this.filenameBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.tableLayoutPanel1.SetColumnSpan( this.filenameBox, 2 );
            this.filenameBox.Location = new System.Drawing.Point( 105, 29 );
            this.filenameBox.Margin = new System.Windows.Forms.Padding( 0 );
            this.filenameBox.Name = "filenameBox";
            this.filenameBox.Size = new System.Drawing.Size( 350, 44 );
            this.filenameBox.TabIndex = 12;
            this.toolTip.SetToolTip( this.filenameBox, "The filename to store a specific log message in. You can use file variables descr" +
                    "ibed in Help & Formatting." );
            // 
            // editLinkIdsBox
            // 
            this.tableLayoutPanel1.SetColumnSpan( this.editLinkIdsBox, 2 );
            this.editLinkIdsBox.Location = new System.Drawing.Point( 3, 168 );
            this.editLinkIdsBox.Name = "editLinkIdsBox";
            this.editLinkIdsBox.Size = new System.Drawing.Size( 206, 23 );
            this.editLinkIdsBox.TabIndex = 13;
            this.editLinkIdsBox.Text = "Edit LinkIDs";
            this.editLinkIdsBox.UseVisualStyleBackColor = true;
            this.editLinkIdsBox.Click += new System.EventHandler( this.editLinkIdsBox_Click );
            // 
            // trackSessions
            // 
            this.trackSessions.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.trackSessions.AutoSize = true;
            this.trackSessions.Location = new System.Drawing.Point( 3, 197 );
            this.trackSessions.Name = "trackSessions";
            this.trackSessions.Size = new System.Drawing.Size( 99, 20 );
            this.trackSessions.TabIndex = 14;
            this.trackSessions.Text = "Track Sessions";
            this.trackSessions.UseVisualStyleBackColor = true;
            // 
            // sessionMinutes
            // 
            this.sessionMinutes.Dock = System.Windows.Forms.DockStyle.Fill;
            this.sessionMinutes.Location = new System.Drawing.Point( 108, 197 );
            this.sessionMinutes.Name = "sessionMinutes";
            this.sessionMinutes.Size = new System.Drawing.Size( 227, 20 );
            this.sessionMinutes.TabIndex = 15;
            // 
            // label15
            // 
            this.label15.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point( 341, 194 );
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size( 111, 26 );
            this.label15.TabIndex = 16;
            this.label15.Text = "Minutes between sessions";
            this.label15.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // enableGroupChats
            // 
            this.enableGroupChats.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan( this.enableGroupChats, 2 );
            this.enableGroupChats.Location = new System.Drawing.Point( 3, 236 );
            this.enableGroupChats.Name = "enableGroupChats";
            this.enableGroupChats.Size = new System.Drawing.Size( 226, 17 );
            this.enableGroupChats.TabIndex = 17;
            this.enableGroupChats.Text = "Enable Group Chat Logging (Experimental)";
            this.enableGroupChats.UseVisualStyleBackColor = true;
            // 
            // statusLabel
            // 
            this.statusLabel.AutoSize = true;
            this.tableLayoutPanel1.SetColumnSpan( this.statusLabel, 2 );
            this.statusLabel.Location = new System.Drawing.Point( 3, 220 );
            this.statusLabel.Name = "statusLabel";
            this.statusLabel.Size = new System.Drawing.Size( 138, 13 );
            this.statusLabel.TabIndex = 18;
            this.statusLabel.Text = "Group Chat Logging Status:";
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add( this.tableLayoutPanel2 );
            this.tabPage2.Location = new System.Drawing.Point( 4, 22 );
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding( 3 );
            this.tabPage2.Size = new System.Drawing.Size( 461, 401 );
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Miscellaneous";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle() );
            this.tableLayoutPanel2.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 100F ) );
            this.tableLayoutPanel2.Controls.Add( this.label4, 0, 2 );
            this.tableLayoutPanel2.Controls.Add( this.label9, 0, 0 );
            this.tableLayoutPanel2.Controls.Add( this.invalidCharBox, 1, 0 );
            this.tableLayoutPanel2.Controls.Add( this.label3, 0, 1 );
            this.tableLayoutPanel2.Controls.Add( this.dateFormatBox, 1, 1 );
            this.tableLayoutPanel2.Controls.Add( this.timeFormatBox, 1, 2 );
            this.tableLayoutPanel2.Controls.Add( this.linkLabel4, 0, 3 );
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point( 3, 3 );
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 4;
            this.tableLayoutPanel2.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel2.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel2.RowStyles.Add( new System.Windows.Forms.RowStyle() );
            this.tableLayoutPanel2.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Absolute, 20F ) );
            this.tableLayoutPanel2.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Absolute, 20F ) );
            this.tableLayoutPanel2.Size = new System.Drawing.Size( 455, 395 );
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // label4
            // 
            this.label4.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point( 3, 72 );
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size( 132, 46 );
            this.label4.TabIndex = 4;
            this.label4.Text = "Time Format:\r\n\r\n";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.toolTip.SetToolTip( this.label4, "This is the time format to use with the {Time} variable. Check the link below for" +
                    " documentation details." );
            // 
            // label9
            // 
            this.label9.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point( 3, 0 );
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size( 132, 26 );
            this.label9.TabIndex = 0;
            this.label9.Text = "Invalid Char Replacement:";
            this.label9.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.toolTip.SetToolTip( this.label9, "All invalid file system characters will be replaced with this string." );
            // 
            // invalidCharBox
            // 
            this.invalidCharBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.invalidCharBox.Location = new System.Drawing.Point( 141, 3 );
            this.invalidCharBox.Name = "invalidCharBox";
            this.invalidCharBox.Size = new System.Drawing.Size( 311, 20 );
            this.invalidCharBox.TabIndex = 1;
            this.toolTip.SetToolTip( this.invalidCharBox, "All invalid file system characters will be replaced with this string." );
            // 
            // label3
            // 
            this.label3.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point( 3, 26 );
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size( 132, 46 );
            this.label3.TabIndex = 2;
            this.label3.Text = "Date Format:\r\n\r\n";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.toolTip.SetToolTip( this.label3, "This is the date format to use with the {Date} variable. Check the below link for" +
                    " documentation details." );
            // 
            // dateFormatBox
            // 
            this.dateFormatBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.dateFormatBox.Location = new System.Drawing.Point( 138, 26 );
            this.dateFormatBox.Margin = new System.Windows.Forms.Padding( 0 );
            this.dateFormatBox.Name = "dateFormatBox";
            this.dateFormatBox.Size = new System.Drawing.Size( 317, 46 );
            this.dateFormatBox.TabIndex = 5;
            this.toolTip.SetToolTip( this.dateFormatBox, "This is the date format to use with the {Date} variable. Check the below link for" +
                    " documentation details." );
            // 
            // timeFormatBox
            // 
            this.timeFormatBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.timeFormatBox.Location = new System.Drawing.Point( 138, 72 );
            this.timeFormatBox.Margin = new System.Windows.Forms.Padding( 0 );
            this.timeFormatBox.Name = "timeFormatBox";
            this.timeFormatBox.Size = new System.Drawing.Size( 317, 46 );
            this.timeFormatBox.TabIndex = 6;
            this.toolTip.SetToolTip( this.timeFormatBox, "This is the time format to use with the {Time} variable. Check the link below for" +
                    " documentation details." );
            // 
            // linkLabel4
            // 
            this.linkLabel4.AutoSize = true;
            this.tableLayoutPanel2.SetColumnSpan( this.linkLabel4, 2 );
            this.linkLabel4.Location = new System.Drawing.Point( 3, 118 );
            this.linkLabel4.Name = "linkLabel4";
            this.linkLabel4.Size = new System.Drawing.Size( 180, 13 );
            this.linkLabel4.TabIndex = 7;
            this.linkLabel4.TabStop = true;
            this.linkLabel4.Text = "DateTime Formatting Documentation";
            this.linkLabel4.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler( this.linkLabel4_LinkClicked );
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add( this.helpBox );
            this.tabPage3.Location = new System.Drawing.Point( 4, 22 );
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding( 3 );
            this.tabPage3.Size = new System.Drawing.Size( 461, 401 );
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Help & Formatting";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // helpBox
            // 
            this.helpBox.BackColor = System.Drawing.SystemColors.Window;
            this.helpBox.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.helpBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.helpBox.Location = new System.Drawing.Point( 3, 3 );
            this.helpBox.Name = "helpBox";
            this.helpBox.ReadOnly = true;
            this.helpBox.Size = new System.Drawing.Size( 455, 395 );
            this.helpBox.TabIndex = 14;
            this.helpBox.Text = resources.GetString( "helpBox.Text" );
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add( this.linkLabel3 );
            this.tabPage4.Controls.Add( this.label14 );
            this.tabPage4.Controls.Add( this.linkLabel2 );
            this.tabPage4.Controls.Add( this.linkLabel1 );
            this.tabPage4.Controls.Add( this.label13 );
            this.tabPage4.Controls.Add( this.label12 );
            this.tabPage4.Controls.Add( this.label11 );
            this.tabPage4.Controls.Add( this.label10 );
            this.tabPage4.Controls.Add( this.label7 );
            this.tabPage4.Controls.Add( this.label6 );
            this.tabPage4.Location = new System.Drawing.Point( 4, 22 );
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding( 3 );
            this.tabPage4.Size = new System.Drawing.Size( 461, 401 );
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "About";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // linkLabel3
            // 
            this.linkLabel3.AutoSize = true;
            this.linkLabel3.Location = new System.Drawing.Point( 8, 238 );
            this.linkLabel3.Name = "linkLabel3";
            this.linkLabel3.Size = new System.Drawing.Size( 192, 13 );
            this.linkLabel3.TabIndex = 9;
            this.linkLabel3.TabStop = true;
            this.linkLabel3.Text = "Steam Chat Logger Facepunch Thread\r\n";
            this.linkLabel3.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler( this.linkLabel3_LinkClicked );
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point( 8, 212 );
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size( 399, 26 );
            this.label14.TabIndex = 8;
            this.label14.Text = "\r\nBe sure to check the official facepunch release thread for updates and more det" +
                "ails\r\n";
            // 
            // linkLabel2
            // 
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Location = new System.Drawing.Point( 8, 199 );
            this.linkLabel2.Name = "linkLabel2";
            this.linkLabel2.Size = new System.Drawing.Size( 188, 13 );
            this.linkLabel2.TabIndex = 7;
            this.linkLabel2.TabStop = true;
            this.linkLabel2.Text = "Open Steamworks Facepunch Thread\r\n";
            this.linkLabel2.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler( this.linkLabel2_LinkClicked );
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point( 8, 186 );
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size( 171, 13 );
            this.linkLabel1.TabIndex = 6;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Open Steamworks Official Website";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler( this.linkLabel1_LinkClicked );
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point( 8, 173 );
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size( 257, 13 );
            this.label13.TabIndex = 5;
            this.label13.Text = "This program runs on the Open Steamworks platform.";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font( "Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.label12.Location = new System.Drawing.Point( 8, 160 );
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size( 71, 13 );
            this.label12.TabIndex = 4;
            this.label12.Text = "Final Notes";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point( 8, 86 );
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size( 212, 52 );
            this.label11.TabIndex = 3;
            this.label11.Text = "The best way to contact me is through IRC.\r\n\r\nirc: irc.gamesurge.net / #opensteam" +
                "works\r\nemail: voidedweasel (at) gmail (dot) com";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font( "Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.label10.Location = new System.Drawing.Point( 8, 73 );
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size( 51, 13 );
            this.label10.TabIndex = 2;
            this.label10.Text = "Contact\r\n";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point( 8, 16 );
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size( 385, 39 );
            this.label7.TabIndex = 1;
            this.label7.Text = "Author: VoiDeD\r\n\r\nThis project is licensed under the MIT License. Check license.t" +
                "xt for more details";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font( "Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.label6.Location = new System.Drawing.Point( 8, 3 );
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size( 200, 13 );
            this.label6.TabIndex = 0;
            this.label6.Text = "About Steam Chat Logger (beta 4)";
            // 
            // SettingsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 469, 427 );
            this.Controls.Add( this.tabControl1 );
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SettingsForm";
            this.Text = "Steam Chat Logger - Settings";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler( this.SettingsForm_FormClosing );
            this.tabControl1.ResumeLayout( false );
            this.tabPage1.ResumeLayout( false );
            this.tableLayoutPanel1.ResumeLayout( false );
            this.tableLayoutPanel1.PerformLayout();
            this.tabPage2.ResumeLayout( false );
            this.tableLayoutPanel2.ResumeLayout( false );
            this.tableLayoutPanel2.PerformLayout();
            this.tabPage3.ResumeLayout( false );
            this.tabPage4.ResumeLayout( false );
            this.tabPage4.PerformLayout();
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox invalidCharBox;
        private System.Windows.Forms.RichTextBox helpBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private PreviewTextBox dateFormatBox;
        private PreviewTextBox timeFormatBox;
        private BrowseTextBox browseBox;
        private PreviewTextBox logFormatBox;
        private PreviewTextBox emoteFormatBox;
        private PreviewTextBox filenameBox;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.LinkLabel linkLabel2;
        private System.Windows.Forms.LinkLabel linkLabel3;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.LinkLabel linkLabel4;
        private System.Windows.Forms.ToolTip toolTip;
        private System.Windows.Forms.Button editLinkIdsBox;
        private System.Windows.Forms.CheckBox trackSessions;
        private System.Windows.Forms.TextBox sessionMinutes;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.CheckBox enableGroupChats;
        private System.Windows.Forms.Label statusLabel;
    }
}