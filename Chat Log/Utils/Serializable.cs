
namespace ChatLog
{
    using System.IO;
    using System.Xml.Serialization;

    /// <summary>
    /// This class provides XML file serialization support for derived classes.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class Serializable<T> where T : Serializable<T>
    {
        /// <summary>
        /// Loads the XML data from the specified file name.
        /// </summary>
        /// <param name="fileName">Name of the file.</param>
        /// <returns>A valid instance of the derived class on success, null on failure.</returns>
        public static T Load( string fileName )
        {
            FileStream fs = null;
            T ret = null;
            try
            {
                fs = File.Open( fileName, FileMode.Open, FileAccess.Read, FileShare.Read );
                XmlSerializer xs = new XmlSerializer( typeof( T ) );
                ret = ( T )xs.Deserialize( fs );

                fs.Close();
            }
            catch
            {
                throw;
            }
            finally
            {
                if ( fs != null )
                    fs.Close();
            }

            return ret;
        }
        /// <summary>
        /// Saves XML to the specified file name.
        /// </summary>
        /// <param name="fileName">Name of the file.</param>
        /// <param name="data">The data to save.</param>
        /// <returns><c>true</c> on success, <c>false</c> on failure.</returns>
        public static bool Save( string fileName, T data )
        {
            FileStream fs = null;
            try
            {
                fs = File.Create( fileName );
                XmlSerializer xs = new XmlSerializer( typeof( T ) );
                xs.Serialize( fs, data );
                fs.Close();

                return true;
            }
            catch
            {
                throw;
            }
            finally
            {
                if ( fs != null )
                    fs.Close();
            }
        }
        /// <summary>
        /// Saves the XML of this instance to the specified file name.
        /// </summary>
        /// <param name="fileName">Name of the file.</param>
        /// <returns><c>true</c> on success, else <c>false</c>.</returns>
        public virtual bool Save( string fileName )
        {
            T data = this as T;

            if ( data != null )
                return Save( fileName, data );
            else
                return false;
        }
    }
}
