using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;
using System.IO;
using System.Diagnostics;
using System.Windows.Forms;

namespace SAPIBase
{
    class AddIn
    {
        public string DisplayName { get; set; }
        public string Path { get; set; }
    }

    class AddInManager
    {
        List<AddIn> loadedAddins;


        public AddInManager()
        {
            loadedAddins = new List<AddIn>();

            AppDomain.CurrentDomain.ReflectionOnlyAssemblyResolve += new ResolveEventHandler( CurrentDomain_ReflectionOnlyAssemblyResolve );
        }

        Assembly CurrentDomain_ReflectionOnlyAssemblyResolve( object sender, ResolveEventArgs args )
        {
            return Assembly.ReflectionOnlyLoad( args.Name );
        }


        public AddIn[] GetAddIns()
        {
            return loadedAddins.ToArray();
        }


        public void LoadAddIns( string basePath )
        {
            DebugLog.AppendText( "SAPI - Loading AddIns..." );

            string[] files = null;

            try
            {
                Assembly.ReflectionOnlyLoadFrom( Assembly.GetCallingAssembly().Location ); // preload this assembly

                files = Directory.GetFiles( basePath, "*.exe", SearchOption.TopDirectoryOnly );
            }
            catch ( Exception ex )
            {
                DebugLog.AppendText( "Failed: {0}{1}", ex.Message, Environment.NewLine );
                return;
            }

            foreach ( string addinFile in files )
            {
                TryLoadAddIn( addinFile );
            }

            if ( loadedAddins.Count == 0 )
                DebugLog.AppendText( "Warning: 0 AddIns loaded!" );

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );
        }

        bool IsAdded( string name )
        {
            foreach ( var addin in loadedAddins )
            {
                if ( addin.DisplayName.IndexOf( name, StringComparison.OrdinalIgnoreCase ) != -1 )
                    return true;
            }

            return false;
        }

        void TryLoadAddIn( string path )
        {

            Assembly asm = null;
            try
            {
                asm = Assembly.ReflectionOnlyLoadFrom( path );
            }
            catch ( Exception ex )
            {
                DebugLog.AppendText( "Unable to load \"{0}\" to check AddIn attribute: {1}", path, ex.Message );
                return;
            }

            string displayName = null;
            try
            {
                var cadList = CustomAttributeData.GetCustomAttributes( asm );

                foreach ( var cad in cadList )
                {
                    if ( cad.Constructor.ReflectedType.FullName == "SAPIBase.AddInAttribute" )
                    {
                        displayName = ( string )cad.NamedArguments[ 0 ].TypedValue.Value;
                    }
                }
            }
            catch ( Exception ex )
            {
                DebugLog.AppendText( "Unable to get \"{0}\" attribs: {1}", path, ex.Message );
                return;
            }

            if ( displayName == null )
                return;

            if ( IsAdded( displayName ) )
            {
                DebugLog.AppendText( "Unable to load \"{0}\", already loaded as \"{1}\"", path, displayName );
                return;
            }

            AddIn adn = new AddIn()
            {
                DisplayName = displayName,
                Path = path,
            };

            loadedAddins.Add( adn );

        }

        public void LaunchAddIn( AddIn addIn, uint appId )
        {
            if ( !IsAdded( addIn.DisplayName ) )
            {
                DebugLog.AppendText( "AddInManager::LaunchAddIn( \"{0}\" ) Failed: Not loaded!" );
                return;
            }

            string args = string.Format( "-appid={0}", appId );

            try
            {
                ProcessStartInfo psi = new ProcessStartInfo()
                {
                    Arguments = args,
                    FileName = addIn.Path,

                    UseShellExecute = false,
                };

                Process.Start( psi );
            }
            catch ( Exception ex )
            {
                Util.MsgBox( Form.ActiveForm, string.Format( "Unable to launch addin: {0}", ex.Message ) );
            }
        }
    }
}
