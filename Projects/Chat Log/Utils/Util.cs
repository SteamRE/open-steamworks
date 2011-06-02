
namespace ChatLog
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Text.RegularExpressions;
    using System.Web.UI;
    using System.Windows.Forms;

    static class Util
    {
        const string ErrorTitle = "ChatLog - Error";
        const string FatalTitle = "ChatLog - Fatal Error!";
        const string WarningTitle = "ChatLog - Warning";

        public static void ShowError( IWin32Window parent, string message )
        {
            MessageBox.Show( parent, message, ErrorTitle, MessageBoxButtons.OK, MessageBoxIcon.Error );
        }
        public static void ShowFatalError( IWin32Window parent, string message )
        {
            MessageBox.Show( parent, message, FatalTitle, MessageBoxButtons.OK, MessageBoxIcon.Error );
            Application.Exit();
        }
        public static void ShowWarning( IWin32Window parent, string message )
        {
            MessageBox.Show( parent, message, WarningTitle, MessageBoxButtons.OK, MessageBoxIcon.Information );
        }

        public static string StripInvalidChars( string input, string replacement )
        {
            return input.Replace( Path.GetInvalidFileNameChars(), replacement ).Replace( Path.GetInvalidPathChars(), replacement );
        }

        public static string Replace( this string str, char[] chars, string replacement )
        {
            string tempStr = str;
            foreach ( char invalidChar in chars )
            {
                tempStr = tempStr.Replace( invalidChar.ToString(), replacement );
            }

            return tempStr;
        }

        // courtesy of James Newton-King
        // http://james.newtonking.com/archive/2008/03/29/formatwith-2-0-string-formatting-with-named-variables.aspx
        public static string FormatWith( this string format, object source )
        {
            return FormatWith( format, null, source );
        }
        public static string FormatWith( this string format, IFormatProvider provider, object source )
        {
            if ( format == null )
                throw new ArgumentNullException( "format" );

            Regex r = new Regex( @"(?<start>\{)+(?<property>[\w\.\[\]]+)(?<format>:[^}]+)?(?<end>\})+",
              RegexOptions.Compiled | RegexOptions.CultureInvariant | RegexOptions.IgnoreCase );

            List<object> values = new List<object>();
            string rewrittenFormat = r.Replace( format, delegate( Match m )
            {
                Group startGroup = m.Groups[ "start" ];
                Group propertyGroup = m.Groups[ "property" ];
                Group formatGroup = m.Groups[ "format" ];
                Group endGroup = m.Groups[ "end" ];

                try
                {
                    values.Add( ( propertyGroup.Value == "0" ) ? source : DataBinder.Eval( source, propertyGroup.Value ) );
                }
                catch
                {
                    return "{{" + propertyGroup.Value + "}}"; // ignore a non-existant format specifier
                }

                return new string( '{', startGroup.Captures.Count ) + ( values.Count - 1 ) + formatGroup.Value + new string( '}', endGroup.Captures.Count );

            }
            );

            return string.Format( provider, rewrittenFormat, values.ToArray() );

        }
    }
}
