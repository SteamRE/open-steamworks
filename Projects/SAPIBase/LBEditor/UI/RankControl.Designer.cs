namespace LBEditor
{
    partial class RankControl
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.rankLabel = new System.Windows.Forms.Label();
            this.scoreBox = new System.Windows.Forms.TextBox();
            this.nameLabel = new System.Windows.Forms.Label();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Absolute, 70F ) );
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 100F ) );
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Absolute, 150F ) );
            this.tableLayoutPanel1.Controls.Add( this.rankLabel, 0, 0 );
            this.tableLayoutPanel1.Controls.Add( this.scoreBox, 2, 0 );
            this.tableLayoutPanel1.Controls.Add( this.nameLabel, 1, 0 );
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point( 0, 0 );
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Percent, 100F ) );
            this.tableLayoutPanel1.Size = new System.Drawing.Size( 401, 40 );
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // rankLabel
            // 
            this.rankLabel.AutoSize = true;
            this.rankLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rankLabel.Font = new System.Drawing.Font( "Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.rankLabel.Location = new System.Drawing.Point( 3, 0 );
            this.rankLabel.Name = "rankLabel";
            this.rankLabel.Size = new System.Drawing.Size( 64, 40 );
            this.rankLabel.TabIndex = 0;
            this.rankLabel.Text = "#??";
            this.rankLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // scoreBox
            // 
            this.scoreBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.scoreBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.scoreBox.Font = new System.Drawing.Font( "Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.scoreBox.Location = new System.Drawing.Point( 254, 8 );
            this.scoreBox.Name = "scoreBox";
            this.scoreBox.ReadOnly = true;
            this.scoreBox.Size = new System.Drawing.Size( 144, 24 );
            this.scoreBox.TabIndex = 1;
            this.scoreBox.Text = "Score";
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.nameLabel.Font = new System.Drawing.Font( "Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.nameLabel.Location = new System.Drawing.Point( 73, 0 );
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size( 175, 40 );
            this.nameLabel.TabIndex = 2;
            this.nameLabel.Text = "<Name>";
            this.nameLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // RankControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Controls.Add( this.tableLayoutPanel1 );
            this.Name = "RankControl";
            this.Size = new System.Drawing.Size( 401, 40 );
            this.tableLayoutPanel1.ResumeLayout( false );
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label rankLabel;
        private System.Windows.Forms.TextBox scoreBox;
        private System.Windows.Forms.Label nameLabel;
    }
}
