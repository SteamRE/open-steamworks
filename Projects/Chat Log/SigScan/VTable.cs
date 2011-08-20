using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace ChatLog
{
    unsafe class VTable
    {
        IntPtr vtObject;
        int *vTable;

        public VTable( IntPtr classObj )
        {
            this.vtObject = classObj;

            vTable = ( ( int* )*( int* )vtObject.ToInt32() );
        }

        public T GetFunc<T>( int index )
        {
            IntPtr virtFunc = new IntPtr( vTable[ index ] );

            return ( T )( object )Marshal.GetDelegateForFunctionPointer( virtFunc, typeof( T ) );
        }
    }
}
