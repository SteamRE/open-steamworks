namespace SAPIBase
{
    partial class DebugForm
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
            this.debugLog = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // debugLog
            // 
            this.debugLog.BackColor = System.Drawing.SystemColors.Window;
            this.debugLog.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.debugLog.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.debugLog.Dock = System.Windows.Forms.DockStyle.Fill;
            this.debugLog.Font = new System.Drawing.Font( "Lucida Console", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.debugLog.Location = new System.Drawing.Point( 3, 3 );
            this.debugLog.Name = "debugLog";
            this.debugLog.ReadOnly = true;
            this.debugLog.Size = new System.Drawing.Size( 588, 215 );
            this.debugLog.TabIndex = 0;
            this.debugLog.Text = "";
            // 
            // DebugForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 594, 221 );
            this.Controls.Add( this.debugLog );
            this.Name = "DebugForm";
            this.Padding = new System.Windows.Forms.Padding( 3 );
            this.Text = "Debug Log";
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.RichTextBox debugLog;
    }
}