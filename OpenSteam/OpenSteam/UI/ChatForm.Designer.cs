namespace OpenSteam
{
    partial class ChatForm
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
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.chatBox = new System.Windows.Forms.TextBox();
            this.chatTextBox1 = new OpenSteam.ChatTextBox();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
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
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add( this.chatTextBox1 );
            this.splitContainer1.Size = new System.Drawing.Size( 292, 270 );
            this.splitContainer1.SplitterDistance = 146;
            this.splitContainer1.TabIndex = 0;
            // 
            // chatBox
            // 
            this.chatBox.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.chatBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.chatBox.Location = new System.Drawing.Point( 0, 0 );
            this.chatBox.Multiline = true;
            this.chatBox.Name = "chatBox";
            this.chatBox.ReadOnly = true;
            this.chatBox.Size = new System.Drawing.Size( 292, 146 );
            this.chatBox.TabIndex = 0;
            // 
            // chatTextBox1
            // 
            this.chatTextBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.chatTextBox1.Location = new System.Drawing.Point( 0, 0 );
            this.chatTextBox1.Multiline = true;
            this.chatTextBox1.Name = "chatTextBox1";
            this.chatTextBox1.Size = new System.Drawing.Size( 292, 120 );
            this.chatTextBox1.TabIndex = 0;
            this.chatTextBox1.EnterPressed += new System.EventHandler( this.chatTextBox1_EnterPressed );
            // 
            // ChatForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 292, 270 );
            this.Controls.Add( this.splitContainer1 );
            this.Name = "ChatForm";
            this.Text = "OpenSteam - %name%";
            this.splitContainer1.Panel1.ResumeLayout( false );
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout( false );
            this.splitContainer1.Panel2.PerformLayout();
            this.splitContainer1.ResumeLayout( false );
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TextBox chatBox;
        private ChatTextBox chatTextBox1;
    }
}