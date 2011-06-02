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
    public delegate string StringAction();

    public partial class PreviewTextBox : UserControl
    {
        public override string Text
        {
            get { return textBox.Text; }
            set {textBox.Text = value; }
        }

        public StringAction PreviewFunction;

        public PreviewTextBox()
        {
            InitializeComponent();
        }

        public string GetPreviewString()
        {
            string prevString = string.Empty;

            try
            {
                prevString = PreviewFunction();
            }
            catch
            {
                prevString = "Invalid.";
            }

            return prevString;
        }

        public new void Update()
        {
            textBox_TextChanged(null, EventArgs.Empty);

            base.Update();
        }

        private void textBox_TextChanged( object sender, EventArgs e )
        {
            label1.Text = "Preview: " + GetPreviewString();
        }
    }
}
