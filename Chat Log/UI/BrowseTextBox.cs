using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace ChatLog
{
    public partial class BrowseTextBox : UserControl
    {
        public override string Text
        {
            get { return textBox.Text; }
            set {textBox.Text = value; }
        }

        public BrowseTextBox()
        {
            InitializeComponent();
        }

        private void browseButton_Click( object sender, EventArgs e )
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();

            fbd.Description = "Please select the folder where chatlogs will be stored.";
            fbd.ShowNewFolderButton = true;

            if ( fbd.ShowDialog() != DialogResult.OK )
                return;

            if ( !Directory.Exists( fbd.SelectedPath ) )
            {
                try
                {
                    Directory.CreateDirectory( fbd.SelectedPath );
                }
                catch ( Exception ex )
                {
                    Util.ShowError( this, "Unable to create logging directory: " + ex.Message );
                    return;
                }
            }

            textBox.Text = fbd.SelectedPath;
        }
    }
}
