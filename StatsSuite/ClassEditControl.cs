using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using dotnetworks;

namespace StatsSuite
{
    public partial class ClassEditControl : UserControl
    {
        public Image ClassImage
        {
            get { return pictureBox1.Image; }
            set { pictureBox1.Image = value; }
        }

        const int ExpandedHeight = 176;
        const int CollapsedHeight = 85;

        public string Class;

        public bool Expanded
        {
            get { return this.Height == ExpandedHeight; }
        }
        public bool Collapsed
        {
            get { return this.Height == CollapsedHeight; }
        }

        public string TimePlayed
        {
            get { return textBox1.Text; }
            set { textBox1.Text = value; }
        }
        public string MaxPoints
        {
            get { return textBox2.Text; }
            set { textBox2.Text = value; }
        }
        public string MaxKills
        {
            get { return textBox3.Text; }
            set { textBox3.Text = value; }
        }
        public string MaxDamage
        {
            get { return textBox4.Text; }
            set { textBox4.Text = value; }
        }
        public string LongestLife
        {
            get { return textBox5.Text; }
            set { textBox5.Text = value; }
        }

        public string MostPoints2
        {
            get { return textBox6.Text; }
            set { textBox6.Text = value; }
        }
        public string MostDestruction
        {
            get { return textBox7.Text; }
            set { textBox7.Text = value; }
        }
        public string MostKills2
        {
            get { return textBox8.Text; }
            set { textBox8.Text = value; }
        }
        public string MostDominations
        {
            get { return textBox9.Text; }
            set { textBox9.Text = value; }
        }
        public string MostAssists
        {
            get { return textBox10.Text; }
            set { textBox10.Text = value; }
        }
        public string MostRevenges
        {
            get { return textBox11.Text; }
            set { textBox11.Text = value; }
        }
        public string MostCaptures
        {
            get { return textBox12.Text; }
            set { textBox12.Text = value; }
        }
        public string MostUberCharges
        {
            get { return textBox13.Text; }
            set { textBox13.Text = value; }
        }
        public string MostDefenses
        {
            get { return textBox14.Text; }
            set { textBox14.Text = value; }
        }
        public string MostDamage
        {
            get { return textBox16.Text; }
            set { textBox16.Text = value; }
        }

        StatsAccessor statsAcc;
        
        public string GetStatString( string statName )
        {
            return statsAcc.GetStatString(Class + "." + statName);
        }
        public bool SetStatInt( string statName, string value)
        {
            int intValue;

            if ( !Int32.TryParse( value, out intValue ) )
            {
                return false;
            }

            bool ret = statsAcc.SetStatValue( Class + "." + statName, intValue );
            if (!ret)
                MessageBox.Show("Error setting \"" + statName + "\".");

            return ret;
        }
        
        public ClassEditControl( string classPrefix )
        {
            InitializeComponent();

            // assign member vars
            Class = classPrefix;

        }

        public void LoadStats( StatsAccessor statsAcc )
        {
            this.statsAcc = statsAcc;

            // assign defaults (top bit)
            TimePlayed = GetStatString( "accum.iPlayTime" );
            MaxPoints = GetStatString( "accum.iPointsScored" );
            MaxKills = GetStatString( "accum.iNumberOfKills" );
            MaxDamage = GetStatString( "accum.iDamageDealt" );
            LongestLife = GetStatString( "max.iPlayTime" );

            // assign defaults (details)
            MostPoints2 = GetStatString( "max.iPointsScored" );
            MostKills2 = GetStatString( "max.iNumberOfKills" );
            MostAssists = GetStatString( "max.iKillAssists" );
            MostCaptures = GetStatString( "max.iPointCaptures" );
            MostDefenses = GetStatString( "max.iPointDefenses" );
            MostDamage = GetStatString( "max.iDamageDealt" );
            MostDestruction = GetStatString( "max.iBuildingsDestroyed" );
            MostDominations = GetStatString( "max.iDominations" );
            MostRevenges = GetStatString( "max.iRevenge" );
            MostUberCharges = GetStatString( "max.iNumInvulnerable" );
        }
        public void SetStat( StatsAccessor statsAcc )
        {
            this.statsAcc = statsAcc; // redundancy, but whatever

            SetStatInt( "accum.iPlayTime", TimePlayed );
            SetStatInt( "accum.iPointsScored", MaxPoints );
            SetStatInt( "accum.iNumberOfKills", MaxKills );
            SetStatInt( "accum.iDamageDealt", MaxDamage );
            SetStatInt( "max.iPlayTime", LongestLife );

            SetStatInt( "max.iPointsScored", MostPoints2 );
            SetStatInt( "max.iNumberOfKills", MostKills2 );
            SetStatInt( "max.iKillAssists", MostAssists );
            SetStatInt( "max.iPointCaptures", MostCaptures );
            SetStatInt( "max.iPointDefenses", MostDefenses );
            SetStatInt( "max.iDamageDealt", MostDamage );
            SetStatInt( "max.iBuildingsDestroyed", MostDestruction );
            SetStatInt( "max.iDominations", MostDominations );
            SetStatInt( "max.iRevenge", MostRevenges );
            SetStatInt( "max.iNumInvulnerable", MostUberCharges );
        }

        public void ClearStats()
        {
            SetAllStats( "0" );
        }
        public void MaxStats()
        {
            SetAllStats( Int32.MaxValue.ToString() );
        }

        public void SetAllStats( string value )
        {
            TimePlayed = value;
            MaxPoints = value;
            MaxKills = value;
            MaxDamage = value;
            LongestLife = value;

            MostPoints2 = value;
            MostKills2 = value;
            MostAssists = value;
            MostCaptures = value;
            MostDefenses = value;
            MostDamage = value;
            MostDestruction = value;
            MostDominations = value;
            MostRevenges = value;
            MostUberCharges = value;
        }

        public void Expand()
        {
            this.ParentForm.SuspendLayout();
            this.Parent.SuspendLayout();
            this.SuspendLayout();

            this.Height = ExpandedHeight;

            this.tableLayoutPanel1.SetColumnSpan( this.button1, 1 );
            button1.Text = "Collapse";

            tableLayoutPanel2.Visible = true;

            this.ResumeLayout();
            this.Parent.ResumeLayout();
            this.ParentForm.ResumeLayout();
        }

        public void Collapse()
        {
            this.ParentForm.SuspendLayout();
            this.Parent.SuspendLayout();
            this.SuspendLayout();

            this.Height = CollapsedHeight;

            this.tableLayoutPanel1.SetColumnSpan( this.button1, 6 );
            button1.Text = "Expand";

            tableLayoutPanel2.Visible = false;

            this.ResumeLayout();
            this.Parent.ResumeLayout();
            this.ParentForm.ResumeLayout();
        }

        private void button1_Click( object sender, EventArgs e )
        {
            if ( Collapsed )
                Expand();
            else
                Collapse();
        }
    }
}
