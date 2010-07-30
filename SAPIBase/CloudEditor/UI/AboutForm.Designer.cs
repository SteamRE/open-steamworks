namespace CloudEditor
{
    partial class AboutForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.oswLink = new System.Windows.Forms.LinkLabel();
            this.silkLink = new System.Windows.Forms.LinkLabel();
            this.label3 = new System.Windows.Forms.Label();
            this.voidedLink = new System.Windows.Forms.LinkLabel();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font( "Tahoma", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.label1.Location = new System.Drawing.Point( 12, 9 );
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size( 140, 29 );
            this.label1.TabIndex = 0;
            this.label1.Text = "Cloud Editor";
            // 
            // oswLink
            // 
            this.oswLink.AutoSize = true;
            this.oswLink.Font = new System.Drawing.Font( "Tahoma", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.oswLink.Location = new System.Drawing.Point( 12, 141 );
            this.oswLink.Name = "oswLink";
            this.oswLink.Size = new System.Drawing.Size( 113, 16 );
            this.oswLink.TabIndex = 1;
            this.oswLink.TabStop = true;
            this.oswLink.Text = "Open Steamworks";
            this.oswLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler( this.oswLink_LinkClicked );
            // 
            // silkLink
            // 
            this.silkLink.AutoSize = true;
            this.silkLink.Font = new System.Drawing.Font( "Tahoma", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.silkLink.Location = new System.Drawing.Point( 12, 157 );
            this.silkLink.Name = "silkLink";
            this.silkLink.Size = new System.Drawing.Size( 62, 16 );
            this.silkLink.TabIndex = 3;
            this.silkLink.TabStop = true;
            this.silkLink.Text = "Silk Icons";
            this.silkLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler( this.silkLink_LinkClicked );
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font( "Tahoma", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.label3.Location = new System.Drawing.Point( 11, 122 );
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size( 48, 19 );
            this.label3.TabIndex = 4;
            this.label3.Text = "Uses:";
            // 
            // voidedLink
            // 
            this.voidedLink.AutoSize = true;
            this.voidedLink.Font = new System.Drawing.Font( "Tahoma", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.voidedLink.Location = new System.Drawing.Point( 81, 38 );
            this.voidedLink.Name = "voidedLink";
            this.voidedLink.Size = new System.Drawing.Size( 71, 23 );
            this.voidedLink.TabIndex = 5;
            this.voidedLink.TabStop = true;
            this.voidedLink.Text = "VoiDeD";
            this.voidedLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler( this.voidedLink_LinkClicked );
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font( "Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.label2.Location = new System.Drawing.Point( 14, 38 );
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size( 56, 13 );
            this.label2.TabIndex = 6;
            this.label2.Text = "SAPI Base";
            // 
            // AboutForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 172, 182 );
            this.Controls.Add( this.label2 );
            this.Controls.Add( this.voidedLink );
            this.Controls.Add( this.label3 );
            this.Controls.Add( this.silkLink );
            this.Controls.Add( this.oswLink );
            this.Controls.Add( this.label1 );
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "AboutForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "About";
            this.ResumeLayout( false );
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.LinkLabel oswLink;
        private System.Windows.Forms.LinkLabel silkLink;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.LinkLabel voidedLink;
        private System.Windows.Forms.Label label2;
    }
}