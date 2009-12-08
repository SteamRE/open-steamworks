
namespace ChatLog
{
    using System;

    class LogFailureEventArgs : EventArgs
    {
        public string Reason { get; private set; }

        public LogFailureEventArgs( string reason )
        {
            this.Reason = reason;
        }
    }
}
