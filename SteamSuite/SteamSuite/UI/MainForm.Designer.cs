namespace SteamSuite
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager( typeof( MainForm ) );
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cmbState = new System.Windows.Forms.ComboBox();
            this.btnSetName = new System.Windows.Forms.Button();
            this.txtPersonaName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.friendsList = new SteamSuite.FriendList();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.chkNoEscape = new System.Windows.Forms.CheckBox();
            this.btnGoAway = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.awayMessageBox = new System.Windows.Forms.TextBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.btnAbout = new System.Windows.Forms.Button();
            this.txtCallbacks = new System.Windows.Forms.RichTextBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.txtNameChanger = new System.Windows.Forms.TextBox();
            this.btnEnable = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add( this.label2 );
            this.groupBox1.Controls.Add( this.cmbState );
            this.groupBox1.Controls.Add( this.btnSetName );
            this.groupBox1.Controls.Add( this.txtPersonaName );
            this.groupBox1.Controls.Add( this.label1 );
            this.groupBox1.Location = new System.Drawing.Point( 12, 12 );
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size( 223, 105 );
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Personal Control";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point( 6, 77 );
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size( 35, 13 );
            this.label2.TabIndex = 4;
            this.label2.Text = "State:";
            // 
            // cmbState
            // 
            this.cmbState.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbState.FormattingEnabled = true;
            this.cmbState.Location = new System.Drawing.Point( 47, 74 );
            this.cmbState.Name = "cmbState";
            this.cmbState.Size = new System.Drawing.Size( 170, 21 );
            this.cmbState.TabIndex = 3;
            this.cmbState.SelectedIndexChanged += new System.EventHandler( this.cmbState_SelectedIndexChanged );
            // 
            // btnSetName
            // 
            this.btnSetName.Location = new System.Drawing.Point( 6, 45 );
            this.btnSetName.Name = "btnSetName";
            this.btnSetName.Size = new System.Drawing.Size( 211, 23 );
            this.btnSetName.TabIndex = 2;
            this.btnSetName.Text = "Set";
            this.btnSetName.UseVisualStyleBackColor = true;
            this.btnSetName.Click += new System.EventHandler( this.btnSetName_Click );
            // 
            // txtPersonaName
            // 
            this.txtPersonaName.Location = new System.Drawing.Point( 50, 19 );
            this.txtPersonaName.Name = "txtPersonaName";
            this.txtPersonaName.Size = new System.Drawing.Size( 167, 20 );
            this.txtPersonaName.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point( 6, 22 );
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size( 38, 13 );
            this.label1.TabIndex = 0;
            this.label1.Text = "Name:";
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.groupBox2.Controls.Add( this.friendsList );
            this.groupBox2.Location = new System.Drawing.Point( 241, 12 );
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size( 235, 429 );
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Friends";
            // 
            // friendsList
            // 
            this.friendsList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.friendsList.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed;
            this.friendsList.IntegralHeight = false;
            this.friendsList.Location = new System.Drawing.Point( 3, 16 );
            this.friendsList.Name = "friendsList";
            this.friendsList.Size = new System.Drawing.Size( 229, 410 );
            this.friendsList.SteamContext = null;
            this.friendsList.TabIndex = 0;
            this.friendsList.DoubleClick += new System.EventHandler( this.friendsList_DoubleClick );
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add( this.chkNoEscape );
            this.groupBox3.Controls.Add( this.btnGoAway );
            this.groupBox3.Controls.Add( this.label3 );
            this.groupBox3.Controls.Add( this.awayMessageBox );
            this.groupBox3.Location = new System.Drawing.Point( 12, 123 );
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size( 223, 120 );
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Away Status";
            // 
            // chkNoEscape
            // 
            this.chkNoEscape.AutoSize = true;
            this.chkNoEscape.Location = new System.Drawing.Point( 96, 19 );
            this.chkNoEscape.Name = "chkNoEscape";
            this.chkNoEscape.Size = new System.Drawing.Size( 121, 17 );
            this.chkNoEscape.TabIndex = 3;
            this.chkNoEscape.Text = "There Is No Escape";
            this.chkNoEscape.UseVisualStyleBackColor = true;
            // 
            // btnGoAway
            // 
            this.btnGoAway.Location = new System.Drawing.Point( 6, 91 );
            this.btnGoAway.Name = "btnGoAway";
            this.btnGoAway.Size = new System.Drawing.Size( 211, 23 );
            this.btnGoAway.TabIndex = 2;
            this.btnGoAway.Text = "Go Away";
            this.btnGoAway.UseVisualStyleBackColor = true;
            this.btnGoAway.Click += new System.EventHandler( this.btnGoAway_Click );
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point( 6, 20 );
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size( 82, 13 );
            this.label3.TabIndex = 1;
            this.label3.Text = "Away Message:";
            // 
            // awayMessageBox
            // 
            this.awayMessageBox.Location = new System.Drawing.Point( 6, 42 );
            this.awayMessageBox.Multiline = true;
            this.awayMessageBox.Name = "awayMessageBox";
            this.awayMessageBox.Size = new System.Drawing.Size( 211, 43 );
            this.awayMessageBox.TabIndex = 0;
            // 
            // groupBox4
            // 
            this.groupBox4.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.groupBox4.Controls.Add( this.btnAbout );
            this.groupBox4.Controls.Add( this.txtCallbacks );
            this.groupBox4.Location = new System.Drawing.Point( 12, 447 );
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size( 464, 89 );
            this.groupBox4.TabIndex = 3;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Debug Callbacks";
            // 
            // btnAbout
            // 
            this.btnAbout.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.btnAbout.Location = new System.Drawing.Point( 389, 66 );
            this.btnAbout.Name = "btnAbout";
            this.btnAbout.Size = new System.Drawing.Size( 75, 23 );
            this.btnAbout.TabIndex = 1;
            this.btnAbout.Text = "About";
            this.btnAbout.UseVisualStyleBackColor = true;
            this.btnAbout.Click += new System.EventHandler( this.btnAbout_Click );
            // 
            // txtCallbacks
            // 
            this.txtCallbacks.BackColor = System.Drawing.SystemColors.Window;
            this.txtCallbacks.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.txtCallbacks.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtCallbacks.Location = new System.Drawing.Point( 3, 16 );
            this.txtCallbacks.Name = "txtCallbacks";
            this.txtCallbacks.ReadOnly = true;
            this.txtCallbacks.Size = new System.Drawing.Size( 458, 70 );
            this.txtCallbacks.TabIndex = 0;
            this.txtCallbacks.Text = "";
            // 
            // groupBox5
            // 
            this.groupBox5.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left ) ) );
            this.groupBox5.Controls.Add( this.txtNameChanger );
            this.groupBox5.Controls.Add( this.btnEnable );
            this.groupBox5.Location = new System.Drawing.Point( 12, 249 );
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size( 223, 192 );
            this.groupBox5.TabIndex = 4;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Name Changer";
            // 
            // txtNameChanger
            // 
            this.txtNameChanger.Location = new System.Drawing.Point( 6, 19 );
            this.txtNameChanger.Multiline = true;
            this.txtNameChanger.Name = "txtNameChanger";
            this.txtNameChanger.Size = new System.Drawing.Size( 211, 141 );
            this.txtNameChanger.TabIndex = 2;
            // 
            // btnEnable
            // 
            this.btnEnable.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnEnable.Location = new System.Drawing.Point( 3, 166 );
            this.btnEnable.Name = "btnEnable";
            this.btnEnable.Size = new System.Drawing.Size( 217, 23 );
            this.btnEnable.TabIndex = 1;
            this.btnEnable.Text = "Enable";
            this.btnEnable.UseVisualStyleBackColor = true;
            this.btnEnable.Click += new System.EventHandler( this.btnEnable_Click );
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 488, 548 );
            this.Controls.Add( this.groupBox5 );
            this.Controls.Add( this.groupBox4 );
            this.Controls.Add( this.groupBox3 );
            this.Controls.Add( this.groupBox2 );
            this.Controls.Add( this.groupBox1 );
            this.Icon = ( ( System.Drawing.Icon )( resources.GetObject( "$this.Icon" ) ) );
            this.Name = "MainForm";
            this.Text = "Steam Suite";
            this.Shown += new System.EventHandler( this.MainForm_Shown );
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler( this.MainForm_FormClosing );
            this.groupBox1.ResumeLayout( false );
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout( false );
            this.groupBox3.ResumeLayout( false );
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout( false );
            this.groupBox5.ResumeLayout( false );
            this.groupBox5.PerformLayout();
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnSetName;
        private System.Windows.Forms.TextBox txtPersonaName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cmbState;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox2;
        private FriendList friendsList;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox awayMessageBox;
        private System.Windows.Forms.Button btnGoAway;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox chkNoEscape;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.RichTextBox txtCallbacks;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button btnEnable;
        private System.Windows.Forms.TextBox txtNameChanger;
        private System.Windows.Forms.Button btnAbout;
    }
}