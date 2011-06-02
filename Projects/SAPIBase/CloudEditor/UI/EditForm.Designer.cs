namespace CloudEditor
{
    partial class EditForm
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
            this.dataBox = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // dataBox
            // 
            this.dataBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.dataBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataBox.Font = new System.Drawing.Font( "Lucida Console", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.dataBox.Location = new System.Drawing.Point( 3, 3 );
            this.dataBox.Name = "dataBox";
            this.dataBox.Size = new System.Drawing.Size( 497, 397 );
            this.dataBox.TabIndex = 0;
            this.dataBox.Text = "";
            this.dataBox.TextChanged += new System.EventHandler( this.dataBox_TextChanged );
            // 
            // EditForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 503, 403 );
            this.Controls.Add( this.dataBox );
            this.Name = "EditForm";
            this.Padding = new System.Windows.Forms.Padding( 3 );
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.RichTextBox dataBox;
    }
}