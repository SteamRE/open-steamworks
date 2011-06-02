namespace ChatLog
{
    partial class LinkIDForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager( typeof( LinkIDForm ) );
            this.linkView = new System.Windows.Forms.ListView();
            this.columnHeader1 = new System.Windows.Forms.ColumnHeader();
            this.columnHeader2 = new System.Windows.Forms.ColumnHeader();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip( this.components );
            this.removeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.steamIdBox = new System.Windows.Forms.TextBox();
            this.displayBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.addButton = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.contextMenuStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // linkView
            // 
            this.linkView.Columns.AddRange( new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2} );
            this.linkView.ContextMenuStrip = this.contextMenuStrip1;
            this.linkView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.linkView.FullRowSelect = true;
            this.linkView.GridLines = true;
            this.linkView.Location = new System.Drawing.Point( 3, 16 );
            this.linkView.MultiSelect = false;
            this.linkView.Name = "linkView";
            this.linkView.Size = new System.Drawing.Size( 293, 262 );
            this.linkView.TabIndex = 0;
            this.linkView.UseCompatibleStateImageBehavior = false;
            this.linkView.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "SteamID";
            this.columnHeader1.Width = 136;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Name";
            this.columnHeader2.Width = 153;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.removeToolStripMenuItem} );
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size( 118, 26 );
            this.contextMenuStrip1.Opening += new System.ComponentModel.CancelEventHandler( this.contextMenuStrip1_Opening );
            // 
            // removeToolStripMenuItem
            // 
            this.removeToolStripMenuItem.Name = "removeToolStripMenuItem";
            this.removeToolStripMenuItem.Size = new System.Drawing.Size( 117, 22 );
            this.removeToolStripMenuItem.Text = "Remove";
            this.removeToolStripMenuItem.Click += new System.EventHandler( this.removeToolStripMenuItem_Click );
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point( 6, 16 );
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size( 131, 13 );
            this.label1.TabIndex = 1;
            this.label1.Text = "SteamID or Community ID:";
            // 
            // steamIdBox
            // 
            this.steamIdBox.Location = new System.Drawing.Point( 6, 32 );
            this.steamIdBox.Name = "steamIdBox";
            this.steamIdBox.Size = new System.Drawing.Size( 287, 20 );
            this.steamIdBox.TabIndex = 2;
            // 
            // displayBox
            // 
            this.displayBox.Location = new System.Drawing.Point( 6, 71 );
            this.displayBox.Name = "displayBox";
            this.displayBox.Size = new System.Drawing.Size( 287, 20 );
            this.displayBox.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point( 6, 55 );
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size( 75, 13 );
            this.label2.TabIndex = 3;
            this.label2.Text = "Display Name:";
            // 
            // addButton
            // 
            this.addButton.Location = new System.Drawing.Point( 6, 97 );
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size( 287, 23 );
            this.addButton.TabIndex = 5;
            this.addButton.Text = "Add";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler( this.addButton_Click );
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add( this.linkView );
            this.groupBox1.Location = new System.Drawing.Point( 12, 144 );
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size( 299, 281 );
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Link IDs";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add( this.displayBox );
            this.groupBox2.Controls.Add( this.label1 );
            this.groupBox2.Controls.Add( this.addButton );
            this.groupBox2.Controls.Add( this.steamIdBox );
            this.groupBox2.Controls.Add( this.label2 );
            this.groupBox2.Location = new System.Drawing.Point( 12, 12 );
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size( 299, 126 );
            this.groupBox2.TabIndex = 7;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Add Link ID";
            // 
            // LinkIDForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 323, 437 );
            this.Controls.Add( this.groupBox2 );
            this.Controls.Add( this.groupBox1 );
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ( (System.Drawing.Icon)( resources.GetObject( "$this.Icon" ) ) );
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "LinkIDForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "LinkIDs";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler( this.LinkIDForm_FormClosing );
            this.contextMenuStrip1.ResumeLayout( false );
            this.groupBox1.ResumeLayout( false );
            this.groupBox2.ResumeLayout( false );
            this.groupBox2.PerformLayout();
            this.ResumeLayout( false );

        }

        #endregion

        private System.Windows.Forms.ListView linkView;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox steamIdBox;
        private System.Windows.Forms.TextBox displayBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem removeToolStripMenuItem;
    }
}