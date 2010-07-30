using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace SAPIBase
{
    public partial class GamePanel : FlowLayoutPanel
    {
        public GameControl SelectedGame { get; private set; }


        public GamePanel()
        {
            BorderStyle = BorderStyle.FixedSingle;
            AutoScroll = true;
        }

        public void SelectGame( GameControl gameControl )
        {
            foreach ( GameControl gc in this.Controls )
            {
                if ( gc.Selected )
                {
                    gc.Selected = false;
                    gc.Invalidate();
                }
            }

            this.SelectedGame = gameControl;

            MainForm mf = Form.ActiveForm as MainForm;

            if ( mf == null )
            {
                DebugLog.AppendText( "GamePanel::SelectGame() - ActiveForm is not MainForm!!!" );
                return;
            }


            mf.UpdateSelected( gameControl );

            if ( gameControl == null )
                return;

            gameControl.Selected = true;
            gameControl.Invalidate();
        }


        protected override void OnMouseClick( MouseEventArgs e )
        {
            SelectGame( null );
        }

    }
}
