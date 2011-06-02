namespace LBEditor
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.searchGroupBox = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.searchBox = new System.Windows.Forms.TextBox();
            this.searchButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.rankGroupBox = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.rankLabel = new System.Windows.Forms.Label();
            this.rankBox = new System.Windows.Forms.TextBox();
            this.setButton = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.leaderPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.panel1.SuspendLayout();
            this.searchGroupBox.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.rankGroupBox.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.panel3.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add( this.searchGroupBox );
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point( 0, 0 );
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size( 451, 51 );
            this.panel1.TabIndex = 0;
            // 
            // searchGroupBox
            // 
            this.searchGroupBox.Controls.Add( this.tableLayoutPanel1 );
            this.searchGroupBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.searchGroupBox.Location = new System.Drawing.Point( 0, 0 );
            this.searchGroupBox.Name = "searchGroupBox";
            this.searchGroupBox.Size = new System.Drawing.Size( 449, 49 );
            this.searchGroupBox.TabIndex = 0;
            this.searchGroupBox.TabStop = false;
            this.searchGroupBox.Text = "Search";
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Absolute, 76F ) );
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 100F ) );
            this.tableLayoutPanel1.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Absolute, 90F ) );
            this.tableLayoutPanel1.Controls.Add( this.searchBox, 1, 0 );
            this.tableLayoutPanel1.Controls.Add( this.searchButton, 2, 0 );
            this.tableLayoutPanel1.Controls.Add( this.label1, 0, 0 );
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point( 3, 16 );
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Percent, 100F ) );
            this.tableLayoutPanel1.Size = new System.Drawing.Size( 443, 30 );
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // searchBox
            // 
            this.searchBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.searchBox.Location = new System.Drawing.Point( 79, 5 );
            this.searchBox.Name = "searchBox";
            this.searchBox.Size = new System.Drawing.Size( 271, 20 );
            this.searchBox.TabIndex = 1;
            // 
            // searchButton
            // 
            this.searchButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.searchButton.Location = new System.Drawing.Point( 356, 3 );
            this.searchButton.Name = "searchButton";
            this.searchButton.Size = new System.Drawing.Size( 84, 24 );
            this.searchButton.TabIndex = 2;
            this.searchButton.Text = "Load";
            this.searchButton.UseVisualStyleBackColor = true;
            this.searchButton.Click += new System.EventHandler( this.searchButton_Click );
            // 
            // label1
            // 
            this.label1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label1.Location = new System.Drawing.Point( 3, 0 );
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size( 70, 30 );
            this.label1.TabIndex = 3;
            this.label1.Text = "Leaderboard:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add( this.rankGroupBox );
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point( 0, 51 );
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size( 451, 62 );
            this.panel2.TabIndex = 1;
            // 
            // rankGroupBox
            // 
            this.rankGroupBox.Controls.Add( this.tableLayoutPanel2 );
            this.rankGroupBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rankGroupBox.Enabled = false;
            this.rankGroupBox.Location = new System.Drawing.Point( 0, 0 );
            this.rankGroupBox.Name = "rankGroupBox";
            this.rankGroupBox.Size = new System.Drawing.Size( 449, 60 );
            this.rankGroupBox.TabIndex = 0;
            this.rankGroupBox.TabStop = false;
            this.rankGroupBox.Text = "Ranking";
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 3;
            this.tableLayoutPanel2.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle() );
            this.tableLayoutPanel2.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Percent, 100F ) );
            this.tableLayoutPanel2.ColumnStyles.Add( new System.Windows.Forms.ColumnStyle( System.Windows.Forms.SizeType.Absolute, 90F ) );
            this.tableLayoutPanel2.Controls.Add( this.rankLabel, 0, 0 );
            this.tableLayoutPanel2.Controls.Add( this.rankBox, 1, 0 );
            this.tableLayoutPanel2.Controls.Add( this.setButton, 2, 0 );
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point( 3, 16 );
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 1;
            this.tableLayoutPanel2.RowStyles.Add( new System.Windows.Forms.RowStyle( System.Windows.Forms.SizeType.Percent, 100F ) );
            this.tableLayoutPanel2.Size = new System.Drawing.Size( 443, 41 );
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // rankLabel
            // 
            this.rankLabel.AutoSize = true;
            this.rankLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rankLabel.Font = new System.Drawing.Font( "Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.rankLabel.Location = new System.Drawing.Point( 3, 0 );
            this.rankLabel.Name = "rankLabel";
            this.rankLabel.Size = new System.Drawing.Size( 54, 41 );
            this.rankLabel.TabIndex = 0;
            this.rankLabel.Text = "#?";
            this.rankLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // rankBox
            // 
            this.rankBox.Anchor = ( ( System.Windows.Forms.AnchorStyles )( ( System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right ) ) );
            this.rankBox.Font = new System.Drawing.Font( "Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ( ( byte )( 0 ) ) );
            this.rankBox.Location = new System.Drawing.Point( 63, 6 );
            this.rankBox.Name = "rankBox";
            this.rankBox.Size = new System.Drawing.Size( 287, 29 );
            this.rankBox.TabIndex = 1;
            // 
            // setButton
            // 
            this.setButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.setButton.Location = new System.Drawing.Point( 356, 3 );
            this.setButton.Name = "setButton";
            this.setButton.Size = new System.Drawing.Size( 84, 35 );
            this.setButton.TabIndex = 2;
            this.setButton.Text = "Set";
            this.setButton.UseVisualStyleBackColor = true;
            this.setButton.Click += new System.EventHandler( this.setButton_Click );
            // 
            // panel3
            // 
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel3.Controls.Add( this.groupBox3 );
            this.panel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel3.Location = new System.Drawing.Point( 0, 113 );
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size( 451, 257 );
            this.panel3.TabIndex = 2;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add( this.leaderPanel );
            this.groupBox3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox3.Location = new System.Drawing.Point( 0, 0 );
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size( 449, 255 );
            this.groupBox3.TabIndex = 0;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Leaderboard";
            // 
            // leaderPanel
            // 
            this.leaderPanel.AutoScroll = true;
            this.leaderPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.leaderPanel.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.leaderPanel.Location = new System.Drawing.Point( 3, 16 );
            this.leaderPanel.Name = "leaderPanel";
            this.leaderPanel.Size = new System.Drawing.Size( 443, 236 );
            this.leaderPanel.TabIndex = 0;
            this.leaderPanel.WrapContents = false;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 451, 370 );
            this.Controls.Add( this.panel3 );
            this.Controls.Add( this.panel2 );
            this.Controls.Add( this.panel1 );
            this.MinimumSize = new System.Drawing.Size( 450, 320 );
            this.Name = "MainForm";
            this.Text = "Leaderboard Editor";
            this.panel1.ResumeLayout( false );
            this.searchGroupBox.ResumeLayout( false );
            this.tableLayoutPanel1.ResumeLayout( false );
            this.tableLayoutPanel1.PerformLayout();
            this.panel2.ResumeLayout( false );
            this.rankGroupBox.ResumeLayout( false );
            this.tableLayoutPanel2.ResumeLayout( false );
            this.tableLayoutPanel2.PerformLayout();
            this.panel3.ResumeLayout( false );
            this.groupBox3.ResumeLayout( false );
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox searchGroupBox;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TextBox searchBox;
        private System.Windows.Forms.Button searchButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.GroupBox rankGroupBox;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label rankLabel;
        private System.Windows.Forms.TextBox rankBox;
        private System.Windows.Forms.Button setButton;
        private System.Windows.Forms.FlowLayoutPanel leaderPanel;


    }
}