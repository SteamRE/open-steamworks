using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.IO;
using SAPIBase;

namespace CloudEditor
{
    public partial class FileListView : ListView
    {
        public FileListView()
        {
            GridLines = true;
            View = View.Details;

            MultiSelect = false;
            FullRowSelect = true;

            Columns.Add( new ColumnHeader() { Text = "Name", Width = 300 } );
            Columns.Add( new ColumnHeader() { Text = "Size", Width = 100 } );
            Columns.Add( new ColumnHeader() { Text = "Type", Width = 100 } );
        }
    }

    public class FileListViewItem : ListViewItem
    {
        static Dictionary<string, string> FileTypeMap = new Dictionary<string, string>()
        {
            { "CFG", "Config File" },
            { "VMT", "Valve Material Type" },
            { "VTF", "Valve Texture Format" },
        };

        public string FileName { get { return Text; } set { Text = value; } }
        public string FileNameShort { get; private set; }

        public FileListViewItem( string fileName, int byteSize )
        {
            Text = fileName;

            FileNameShort = Path.GetFileName( fileName );

            Util.SizeType type;
            float bytes = Util.BytesToLargest( byteSize, out type );

            SubItems.Add( bytes + " " + type );

            string ext = GetExtension( fileName );

            SubItems.Add( ext );
        }

        static string GetExtension( string fileName )
        {
            string ext = Path.GetExtension( fileName );
            ext = ext.Replace( ".", "" );
            ext = ext.ToUpper();

            if ( FileTypeMap.ContainsKey( ext ) )
                ext = FileTypeMap[ ext ];
            else
                ext += " File";

            return ext;
        }
    }
}
