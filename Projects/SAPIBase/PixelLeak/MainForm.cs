using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using SAPIBase;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;
using Steam4NET;

namespace PixelLeak
{
    public partial class MainForm : Form
    {
        int appId;

        public MainForm( int appId )
        {
            this.appId = appId;

            InitializeComponent();
        }


        private void btnLoad_Click( object sender, EventArgs e )
        {
            OpenFileDialog ofd = new OpenFileDialog();

            ofd.AddExtension = true;
            ofd.AutoUpgradeEnabled = true;
            ofd.CheckFileExists = true;
            ofd.CheckPathExists = true;
            ofd.Multiselect = false;
            ofd.Title = "Open Image...";

            if ( ofd.ShowDialog() != DialogResult.OK )
            {
                return;
            }

            Image img = null;

            try
            {
                img = Image.FromFile( ofd.FileName );
            }
            catch ( Exception ex )
            {
                Util.MsgBox( this, "Unable to load image: " + ex.Message );
                return;
            }

            imgBox.Image = img;
        }

        private void btnUpload_Click( object sender, EventArgs e )
        {
            Image img = imgBox.Image;

            if ( img == null )
            {
                Util.MsgBox( this, "Unable to upload image: No image loaded!" );
                return;
            }

            byte[] imgData = null;

            using ( Bitmap bitmap = new Bitmap( img ) )
            {
                BitmapData bitData = bitmap.LockBits( new Rectangle( Point.Empty, img.Size ), ImageLockMode.ReadOnly, PixelFormat.Format24bppRgb );

                imgData = new byte[ img.Width * img.Height * 3 ];
                Marshal.Copy( bitData.Scan0, imgData, 0, imgData.Length );

                bitmap.UnlockBits( bitData );
            }

            
            for ( int x = 0 ; x < imgData.Length ; x += 3 )
            {
                Array.Reverse( imgData, x, 3 );
            }

            int width = img.Width + 1;
            int height = img.Height;

            Pixel.Screenshots.WriteScreenshot( imgData, ( uint )imgData.Length, width, height );
        }
    }
}
