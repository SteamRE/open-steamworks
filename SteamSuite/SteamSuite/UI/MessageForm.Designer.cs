namespace SteamSuite
{
    partial class MessageForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager( typeof( MessageForm ) );
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.chatBox = new System.Windows.Forms.RichTextBox();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.splitContainer3 = new System.Windows.Forms.SplitContainer();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnSpam = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.txtDelay = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.checkBeeKeeper = new System.Windows.Forms.CheckBox();
            this.txtResponses = new System.Windows.Forms.RichTextBox();
            this.txtSpam = new System.Windows.Forms.RichTextBox();
            this.inputBox = new SteamSuite.ChatTextBox();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.splitContainer3.Panel1.SuspendLayout();
            this.splitContainer3.Panel2.SuspendLayout();
            this.splitContainer3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point( 0, 0 );
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add( this.chatBox );
            this.splitContainer1.Panel1.Padding = new System.Windows.Forms.Padding( 3 );
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add( this.inputBox );
            this.splitContainer1.Panel2.Padding = new System.Windows.Forms.Padding( 3 );
            this.splitContainer1.Size = new System.Drawing.Size( 293, 418 );
            this.splitContainer1.SplitterDistance = 234;
            this.splitContainer1.TabIndex = 0;
            // 
            // chatBox
            // 
            this.chatBox.BackColor = System.Drawing.SystemColors.Window;
            this.chatBox.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.chatBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.chatBox.Location = new System.Drawing.Point( 3, 3 );
            this.chatBox.Name = "chatBox";
            this.chatBox.ReadOnly = true;
            this.chatBox.Size = new System.Drawing.Size( 287, 228 );
            this.chatBox.TabIndex = 0;
            this.chatBox.Text = "";
            // 
            // splitContainer2
            // 
            this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer2.Location = new System.Drawing.Point( 0, 0 );
            this.splitContainer2.Name = "splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add( this.splitContainer1 );
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add( this.splitContainer3 );
            this.splitContainer2.Panel2.Padding = new System.Windows.Forms.Padding( 3 );
            this.splitContainer2.Size = new System.Drawing.Size( 456, 418 );
            this.splitContainer2.SplitterDistance = 293;
            this.splitContainer2.TabIndex = 1;
            // 
            // splitContainer3
            // 
            this.splitContainer3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer3.Location = new System.Drawing.Point( 3, 3 );
            this.splitContainer3.Name = "splitContainer3";
            this.splitContainer3.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer3.Panel1
            // 
            this.splitContainer3.Panel1.Controls.Add( this.groupBox1 );
            // 
            // splitContainer3.Panel2
            // 
            this.splitContainer3.Panel2.Controls.Add( this.groupBox2 );
            this.splitContainer3.Size = new System.Drawing.Size( 153, 412 );
            this.splitContainer3.SplitterDistance = 258;
            this.splitContainer3.TabIndex = 1;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add( this.txtSpam );
            this.groupBox1.Controls.Add( this.btnSpam );
            this.groupBox1.Controls.Add( this.label2 );
            this.groupBox1.Controls.Add( this.txtDelay );
            this.groupBox1.Controls.Add( this.label1 );
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Location = new System.Drawing.Point( 0, 0 );
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size( 153, 258 );
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Chat Spam";
            // 
            // btnSpam
            // 
            this.btnSpam.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.btnSpam.Location = new System.Drawing.Point( 6, 226 );
            this.btnSpam.Name = "btnSpam";
            this.btnSpam.Size = new System.Drawing.Size( 141, 23 );
            this.btnSpam.TabIndex = 4;
            this.btnSpam.Text = "Begin";
            this.btnSpam.UseVisualStyleBackColor = true;
            this.btnSpam.Click += new System.EventHandler( this.btnSpam_Click );
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point( 6, 55 );
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size( 28, 13 );
            this.label2.TabIndex = 2;
            this.label2.Text = "Text";
            // 
            // txtDelay
            // 
            this.txtDelay.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.txtDelay.Location = new System.Drawing.Point( 6, 32 );
            this.txtDelay.Name = "txtDelay";
            this.txtDelay.Size = new System.Drawing.Size( 141, 20 );
            this.txtDelay.TabIndex = 1;
            this.txtDelay.Text = "1000";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point( 6, 16 );
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size( 100, 13 );
            this.label1.TabIndex = 0;
            this.label1.Text = "Delay (Milliseconds)";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add( this.txtResponses );
            this.groupBox2.Controls.Add( this.checkBeeKeeper );
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox2.Location = new System.Drawing.Point( 0, 0 );
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size( 153, 150 );
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Bee Keeper";
            // 
            // checkBeeKeeper
            // 
            this.checkBeeKeeper.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left ) ) );
            this.checkBeeKeeper.AutoSize = true;
            this.checkBeeKeeper.Location = new System.Drawing.Point( 6, 124 );
            this.checkBeeKeeper.Name = "checkBeeKeeper";
            this.checkBeeKeeper.Size = new System.Drawing.Size( 59, 17 );
            this.checkBeeKeeper.TabIndex = 0;
            this.checkBeeKeeper.Text = "Enable";
            this.checkBeeKeeper.UseVisualStyleBackColor = true;
            // 
            // txtResponses
            // 
            this.txtResponses.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.txtResponses.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtResponses.Location = new System.Drawing.Point( 6, 19 );
            this.txtResponses.Name = "txtResponses";
            this.txtResponses.Size = new System.Drawing.Size( 138, 99 );
            this.txtResponses.TabIndex = 1;
            this.txtResponses.Text = "";
            // 
            // txtSpam
            // 
            this.txtSpam.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( ( ( System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom )
                        | System.Windows.Forms.AnchorStyles.Left )
                        | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.txtSpam.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.txtSpam.Location = new System.Drawing.Point( 6, 71 );
            this.txtSpam.Name = "txtSpam";
            this.txtSpam.Size = new System.Drawing.Size( 138, 149 );
            this.txtSpam.TabIndex = 5;
            this.txtSpam.Text = "";
            // 
            // inputBox
            // 
            this.inputBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.inputBox.Location = new System.Drawing.Point( 3, 3 );
            this.inputBox.Name = "inputBox";
            this.inputBox.Size = new System.Drawing.Size( 287, 174 );
            this.inputBox.TabIndex = 0;
            this.inputBox.Text = "";
            this.inputBox.EnterPressed += new System.EventHandler( this.inputBox_EnterPressed );
            // 
            // MessageForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 456, 418 );
            this.Controls.Add( this.splitContainer2 );
            this.Icon = ( ( System.Drawing.Icon )( resources.GetObject( "$this.Icon" ) ) );
            this.Name = "MessageForm";
            this.Text = "MessageForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler( this.MessageForm_FormClosing );
            this.splitContainer1.Panel1.ResumeLayout( false );
            this.splitContainer1.Panel2.ResumeLayout( false );
            this.splitContainer1.ResumeLayout( false );
            this.splitContainer2.Panel1.ResumeLayout( false );
            this.splitContainer2.Panel2.ResumeLayout( false );
            this.splitContainer2.ResumeLayout( false );
            this.splitContainer3.Panel1.ResumeLayout( false );
            this.splitContainer3.Panel2.ResumeLayout( false );
            this.splitContainer3.ResumeLayout( false );
            this.groupBox1.ResumeLayout( false );
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout( false );
            this.groupBox2.PerformLayout();
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.RichTextBox chatBox;
        private ChatTextBox inputBox;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtDelay;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnSpam;
        private System.Windows.Forms.SplitContainer splitContainer3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox checkBeeKeeper;
        private System.Windows.Forms.RichTextBox txtResponses;
        private System.Windows.Forms.RichTextBox txtSpam;

    }
}