using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using SKYPE4COMLib;

namespace SkypeStatus
{
    static class SkypeContext
    {
        public static SkypeClass Skype { get; private set; }
        public static bool IsReady { get; private set; }

        public static event EventHandler Ready;
        static void OnReady( EventArgs e )
        {
            if ( Ready != null )
                Ready( null, e );
        }

        public static event EventHandler Denied;
        static void OnDenied( EventArgs e )
        {
            if ( Denied != null )
                Denied( null, e );
        }


        public static void Init()
        {
            if ( Skype == null )
            {
                Skype = new SkypeClass();
                Skype._ISkypeEvents_Event_AttachmentStatus += Skype_AttachmentStatus;
            }

            Skype.Attach( Skype.Protocol, false );
        }


        static void Skype_AttachmentStatus( TAttachmentStatus Status )
        {
            if ( Status == TAttachmentStatus.apiAttachSuccess )
            {
                IsReady = true;
                OnReady( EventArgs.Empty );
            }

            if ( Status == TAttachmentStatus.apiAttachRefused )
            {
                OnDenied( EventArgs.Empty );
            }
        }



    }
}
