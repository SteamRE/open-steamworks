using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Windows.Forms;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;

namespace StatsSuite
{
    partial class About : Form
    {
        Bitmap img;

        Timer tmr = new Timer();

        FMOD.System soundSystem = null;
        FMOD.Sound sound = null;
        FMOD.Channel soundChannel = null;
        FMOD.CREATESOUNDEXINFO exInfo = new FMOD.CREATESOUNDEXINFO();

        List<Color> customSpectrum = new List<Color>();

        Random rnd = new Random( Environment.TickCount );


        public About()
        {
            img = Properties.Resources.nfo;
            img.MakeTransparent( Color.Black );

            InitializeComponent();

            exInfo.cbsize = Marshal.SizeOf( exInfo );
            exInfo.length = (uint)Properties.Resources.teh.Length;

            SetStyle( ControlStyles.AllPaintingInWmPaint, true );
            SetStyle( ControlStyles.Opaque, true );
            SetStyle( ControlStyles.OptimizedDoubleBuffer, true );

            int step = 5;

            Color color = Color.FromArgb( 255, 0, 0 );
            customSpectrum.AddRange( Ext.Interpolate( ColorEnum.Green, ChangeEnum.Higher, color, step ) );

            color = Color.FromArgb( 255, 255, 0 );
            customSpectrum.AddRange( Ext.Interpolate( ColorEnum.Red, ChangeEnum.Lower, color, step ) );

            color = Color.FromArgb( 0, 255, 0 );
            customSpectrum.AddRange( Ext.Interpolate( ColorEnum.Blue, ChangeEnum.Higher, color, step ) );

            color = Color.FromArgb( 0, 255, 255 );
            customSpectrum.AddRange( Ext.Interpolate( ColorEnum.Green, ChangeEnum.Lower, color, step ) );

            color = Color.FromArgb( 0, 0, 255 );
            customSpectrum.AddRange( Ext.Interpolate( ColorEnum.Red, ChangeEnum.Higher, color, step ) );

            color = Color.FromArgb( 255, 0, 255 );
            customSpectrum.AddRange( Ext.Interpolate( ColorEnum.Blue, ChangeEnum.Lower, color, step ) );

            DoubleBuffered = true;

            this.Width = img.Width;
            y = -this.Height;

            FMOD.Factory.System_Create( ref soundSystem );

            soundSystem.init( 32, FMOD.INITFLAG.NORMAL | FMOD.INITFLAG.WASAPI_EXCLUSIVE, IntPtr.Zero );
            soundSystem.createSound( Properties.Resources.teh, FMOD.MODE.SOFTWARE | FMOD.MODE._2D | FMOD.MODE.OPENMEMORY | FMOD.MODE.ACCURATETIME | FMOD.MODE.LOOP_NORMAL, ref exInfo, ref sound );
            soundSystem.playSound( FMOD.CHANNELINDEX.REUSE, sound, false, ref soundChannel );

            soundChannel.setVolume( .75f );

            tmr.Interval = 25;
            tmr.Tick += new EventHandler( tmr_Tick );

            tmr.Start();
        }

        uint position = 0;
        void tmr_Tick( object sender, EventArgs e )
        {
            y += 1f;

            if ( y >= img.Height )
                y = -this.Height;

            specValue++;

            if ( specValue > ( customSpectrum.Count - 1 ) )
                specValue = 0;


            soundChannel.getPosition( ref position, FMOD.TIMEUNIT.MS );

            if ( position >= 33500 && position <= 33500 + 2500)
            {
                soundChannel.setPosition( position + 2500, FMOD.TIMEUNIT.MS );
            }

            this.Invalidate();
        }

        float y = 0;
        int specValue = 0;

        List<PointF> lightningPoints = new List<PointF>();
        List<List<PointF>> sparks = new List<List<PointF>>();

        protected override void OnPaint( PaintEventArgs e )
        {
            RectangleF srcRect = new RectangleF( 0, y, this.Width, this.Height );

            float scrollY = this.Height / 2; /*( ( y + this.Height ) / ( img.Height + this.Height ) ) * this.Height;*/

            int widSet = 8;
            int rightSet = this.Width - widSet - 4;
            int leftSet = widSet;
            int guideBarLen = 20;
            int guideBarWid = 1;
            int mainLen = 3;
            int mainWid = 3;

            int spectrumAccuracy = 64 * 1;
            float[] spectrum = new float[ spectrumAccuracy ];
            FMOD.RESULT result = soundChannel.getSpectrum( spectrum, spectrumAccuracy, 0, FMOD.DSP_FFT_WINDOW.BLACKMAN );

            float avg = spectrum.Average();
            avg *= 100;

            float[] bassSpec = spectrum.Take( spectrumAccuracy / 8 ).ToArray();

            float bassAvg = bassSpec.Average();
            bassAvg *= 25;

            Color baseColor = Color.LightBlue;

            int colorRange = 40;
            int rOff = rnd.Next( -colorRange, colorRange + 1 );
            int gOff = rnd.Next( -colorRange, colorRange + 1 );
            int bOff = rnd.Next( -colorRange, colorRange + 1 );

            int newRed = Math.Min( baseColor.R + rOff, 255 );
            int newGreen = Math.Min( baseColor.G + gOff, 255 );
            int newBlue = Math.Min( baseColor.B + bOff, 255 );

            baseColor = Color.FromArgb( newRed, newGreen, newBlue );

            Pen basePen = new Pen( baseColor, bassAvg );

            RectangleF scrollRect = new RectangleF( rightSet, scrollY, mainWid, mainLen );
            RectangleF topRect = new RectangleF( rightSet + ( ( scrollRect.Width / 2.0f ) - ( guideBarWid / 2.0f ) ), scrollY - guideBarLen, guideBarWid, guideBarLen );
            RectangleF bottomRect = new RectangleF( rightSet + ( ( scrollRect.Width / 2.0f ) - ( guideBarWid / 2.0f ) ), scrollY + scrollRect.Height, guideBarWid, guideBarLen );


            RectangleF scrollRect2 = new RectangleF( leftSet, scrollY, mainWid, mainLen );
            RectangleF topRect2 = new RectangleF( leftSet + ( ( scrollRect.Width / 2.0f ) - ( guideBarWid / 2.0f ) ), scrollY - guideBarLen, guideBarWid, guideBarLen );
            RectangleF bottomRect2 = new RectangleF( leftSet + ( ( scrollRect.Width / 2.0f ) - ( guideBarWid / 2.0f ) ), scrollY + scrollRect.Height, guideBarWid, guideBarLen );

            Color textColor = customSpectrum[ specValue ];

            ColorMap[] map = new ColorMap[ 1 ];
            map[ 0 ] = new ColorMap();
            map[ 0 ].OldColor = Color.Magenta;
            map[ 0 ].NewColor = textColor;

            ImageAttributes attr = new ImageAttributes();
            attr.SetRemapTable( map );

            e.Graphics.DrawImage( img, new Rectangle( 0, 0, this.Width, this.Height ), srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height, GraphicsUnit.Pixel, attr  );

            PointF midRight = new PointF( ( scrollRect.X + ( scrollRect.Width / 2.0f ) ), ( scrollRect.Y + ( scrollRect.Height / 2.0f ) ) );

            e.Graphics.FillRectangle( Brushes.White, scrollRect );
            e.Graphics.FillRectangle( Brushes.WhiteSmoke, topRect );
            e.Graphics.FillRectangle( Brushes.WhiteSmoke, bottomRect );


            PointF midLeft = new PointF( ( scrollRect2.X + ( scrollRect2.Width / 2.0f ) ), ( scrollRect2.Y + ( scrollRect2.Height / 2.0f ) ) );

            e.Graphics.FillRectangle( Brushes.White, scrollRect2 );
            e.Graphics.FillRectangle( Brushes.WhiteSmoke, topRect2 );
            e.Graphics.FillRectangle( Brushes.WhiteSmoke, bottomRect2 );

            if ( avg > 1.4 )
            {
                // lightning
                int subDivs = rnd.Next( 2, 10 );
                float subWid = this.Width / ( float )subDivs;
                float range = 20; // +-30 pixels from the origin

                if ( rnd.Next( 0, 2 ) != 0 )
                    return;

                lightningPoints.Clear();

                lightningPoints.Add( midLeft );
                for ( int i = 1 ; i < subDivs ; i++ )
                {
                    float currX = midLeft.X;
                    float currY = midLeft.Y;

                    float yMin = currY - ( range * avg );
                    float yMax = currY + ( range * avg );

                    float pointY = rnd.Next( ( int )yMin, ( int )yMax + 1 );

                    float xOffset = rnd.Next( -25, 26 );

                    PointF lightPoint = new PointF( ( subWid * i ) + xOffset, pointY );
                    lightningPoints.Add( lightPoint );

                }
                lightningPoints.Add( midRight );

                e.Graphics.DrawLines( basePen, lightningPoints.ToArray() );
            }
            else
            {

                if ( rnd.Next( 0, 3 ) != 0 )
                    return;

                // no connection, lets just spark

                int numSparks = rnd.Next( 1, 4 );
                float maxDist = rnd.Next( 20, this.Width / 6 );
                int direction = rnd.Next( -115, 116 );

                maxDist *= avg;

                sparks.Clear();

                for ( int i = 0 ; i < numSparks; i++ )
                {
                    var spark = new List<PointF>();

                    float origX = midLeft.X;
                    float origY = midLeft.Y;

                    spark.Add( new PointF( origX, origY ) );

                    origX += maxDist * ( float )Math.Cos( DegreeToRadian( direction ) );
                    origY += maxDist * ( float )Math.Sin( DegreeToRadian( direction ) );

                    spark.Add( new PointF( origX, origY ) );

                    maxDist = rnd.Next( 20, this.Width / 6 );
                    maxDist *= avg;

                    direction = rnd.Next( -90, 91 );

                    origX += maxDist * ( float )Math.Cos( DegreeToRadian( direction ) );
                    origY += maxDist * ( float )Math.Sin( DegreeToRadian( direction ) );

                    spark.Add( new PointF( origX, origY ) );

                    sparks.Add( spark );
                }

                foreach ( var spark in sparks )
                {
                    e.Graphics.DrawLines( basePen, spark.ToArray() );
                }


                sparks.Clear();

                for ( int i = 0 ; i < numSparks ; i++ )
                {
                    var spark = new List<PointF>();

                    float origX = midRight.X;
                    float origY = midRight.Y;

                    spark.Add( new PointF( origX, origY ) );

                    origX -= maxDist * ( float )Math.Cos( DegreeToRadian( direction ) );
                    origY -= maxDist * ( float )Math.Sin( DegreeToRadian( direction ) );

                    spark.Add( new PointF( origX, origY ) );

                    maxDist = rnd.Next( 20, this.Width  / 6 );
                    maxDist *= avg;

                    direction = rnd.Next( -90, 91 );

                    origX -= maxDist * ( float )Math.Cos( DegreeToRadian( direction ) );
                    origY -= maxDist * ( float )Math.Sin( DegreeToRadian( direction ) );

                    spark.Add( new PointF( origX, origY ) );

                    sparks.Add( spark );
                }

                foreach ( var spark in sparks )
                {
                    e.Graphics.DrawLines( basePen, spark.ToArray() );
                }
            }
        }
        private double DegreeToRadian( double angle )
        {
            return Math.PI * angle / 180.0;
        }

        private void About_FormClosing( object sender, FormClosingEventArgs e )
        {
            if ( soundChannel != null )
                soundChannel.stop();

            if ( sound != null )
                sound.release();

            if (soundSystem != null)
            soundSystem.close();
        }

        private void About_Click( object sender, EventArgs e )
        {
            this.Close();
        }
    }
    public enum ColorEnum
    {
        Red,
        Green,
        Blue,
    }
    public enum ChangeEnum
    {
        Higher,
        Lower,
    }
    public static class Ext
    {
        public static List<Color> Interpolate( Color first, Color second, int steps )
        {
            List<Color> colors = new List<Color>();

            colors.Add( first );

            for ( int x = 1 ; x < steps ; x++ )
            {
                float stepR = ( float )( second.R - first.R ) / ( float )( steps - 1 );
                float stepG = ( float )( second.G - first.G ) / ( float )( steps - 1 );
                float stepB = ( float )( second.B - first.B ) / ( float )( steps - 1 );

                colors.Add( colors[ x - 1 ].Add( Color.FromArgb( ( byte )stepR, ( byte )stepG, ( byte )stepB ) ) );
            }

            return colors;
        }

        public static Color Add( this Color clr, Color other )
        {
            return Color.FromArgb( ( byte )( clr.R + other.R ), ( byte )( clr.G + other.G ), ( byte )( clr.B + other.B ) );
        }

        public static List<Color> Interpolate( ColorEnum color, ChangeEnum change, Color baseColor, int step )
        {
            List<Color> colors = new List<Color>();

            if ( change == ChangeEnum.Higher )
            {
                for ( int x = 0 ; x < 255 ; x += step )
                {
                    colors.Add( GetColor( color, baseColor, x ) );
                }
            }
            else
            {
                for ( int x = 255 ; x > 0 ; x -= step )
                {
                    colors.Add( GetColor( color, baseColor, x ) );
                }
            }

            return colors;

        }

        private static Color GetColor( ColorEnum color, Color baseColor, int x )
        {
            Color newColor = Color.FromArgb( baseColor.R, baseColor.G, baseColor.B );
            switch ( color )
            {
                case ColorEnum.Blue:
                    newColor = Color.FromArgb( baseColor.R, baseColor.G, ( byte )x );
                    //newColor.Blue = ( byte )x;
                    break;
                case ColorEnum.Red:
                    newColor = Color.FromArgb( ( byte )x, baseColor.G, baseColor.B );
                    //newColor.Red = ( byte )x;
                    break;
                case ColorEnum.Green:
                    newColor = Color.FromArgb( baseColor.R, ( byte )x, baseColor.B );
                    //newColor.Green = ( byte )x;
                    break;
            }
            return newColor;
        }
    }
}
