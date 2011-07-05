using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using SAPIBase;
using Steam4NET;

namespace LBEditor
{
    public partial class RankControl : UserControl
    {
        public RankControl( LeaderboardEntry001_t entry )
        {
            InitializeComponent();

            rankLabel.Text = string.Format( "#{0}", entry.m_nGlobalRank );
            nameLabel.Text = LBContext.Friends.GetFriendPersonaName( entry.m_steamIDUser );
            scoreBox.Text = string.Format( "{0:n0}", entry.m_nScore );
        }
    }
}
