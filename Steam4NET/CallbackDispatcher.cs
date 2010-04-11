using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Threading;

namespace Steam4NET
{
    public interface ICallback
    {
        void Run(IntPtr param);
    }

    public interface IAPICallback : ICallback
    {
        int GetCallback();
    }

    public class Callback<CallbackType> : ICallback
    {
        public delegate void DispatchDelegate(CallbackType param);
        public event DispatchDelegate OnRun;

        protected Callback()
        {
        }

        public Callback(int iCallback)
        {
            CallbackDispatcher.RegisterCallback(this, iCallback);
        }

        public Callback(DispatchDelegate myFunc, int iCallback) : this(iCallback)
        {
            this.OnRun += myFunc;
        }

        public void Run(IntPtr pubParam)
        {
            if(this.OnRun != null)
                this.OnRun((CallbackType)Marshal.PtrToStructure(pubParam, typeof(CallbackType)));
        }
    }

    public class APICallCallback<CallbackType> : Callback<CallbackType>, IAPICallback
    {
        private int callback;
        private UInt64 callhandle = 0;

        public APICallCallback(int iCallback)
        {
            callback = iCallback;
        }

        public APICallCallback(DispatchDelegate myFunc, int iCallback) : this(iCallback)
        {
            this.OnRun += myFunc;
        }

        public APICallCallback(DispatchDelegate myFunc, int iCallback, UInt64 apicallhandle) : this(myFunc, iCallback)
        {
            SetAPICallHandle(apicallhandle);
        }

        public void SetAPICallHandle(UInt64 newcallhandle)
        {
            if (callhandle != 0)
                CallbackDispatcher.ClearAPICallCallback(this, callhandle);

            CallbackDispatcher.RegisterAPICallCallback(this, newcallhandle);
        }

        public int GetCallback()
        {
            return callback;
        }
    }

    public class CallbackUnhandled
    {
        public delegate void DispatchDelegate(CallbackMsg_t msg);
        public event DispatchDelegate OnRun;

        public CallbackUnhandled()
        {
            CallbackDispatcher.SetUnhandledCallback( this );
        }

        public CallbackUnhandled(DispatchDelegate myFunc)
            : this()
        {
            this.OnRun += myFunc;
        }

        public void Run(CallbackMsg_t msg)
        {
            if (this.OnRun != null)
                this.OnRun(msg);
        }
    }

    public class CallbackDispatcher
    {
        private static Dictionary<int, ICallback> registeredCallbacks = new Dictionary<int, ICallback>();
        private static Dictionary<UInt64, IAPICallback> regiseredAPICallbacks = new Dictionary<UInt64, IAPICallback>();

        private static CallbackUnhandled unhandledCallback = null;

        private static Dictionary<int, Thread> managedThreads = new Dictionary<int, Thread>();

        public static void RegisterCallback(ICallback callback, int iCallback)
        {
            registeredCallbacks.Add(iCallback, callback);
        }

        public static void RegisterAPICallCallback(IAPICallback callback, UInt64 callhandle)
        {
            regiseredAPICallbacks.Add(callhandle, callback);
        }

        public static void ClearAPICallCallback(IAPICallback callback, UInt64 callhandle)
        {
            regiseredAPICallbacks.Remove(callhandle);
        }

        public static void SetUnhandledCallback(CallbackUnhandled callback)
        {
            unhandledCallback = callback;
        }

        private static void RunAPICallbacks(SteamAPICallCompleted_t apicall)
        {
            IAPICallback apicallback;
            if(regiseredAPICallbacks.TryGetValue(apicall.m_hAsyncCall, out apicallback))
            {
                // (Use Steam_GetAPICallResult) etc..
            }
        }

        public static void RunCallbacks(int pipe)
        {
            CallbackMsg_t callbackmsg = new CallbackMsg_t();
            int steamcall = 0;

            if(Steamworks.GetCallback(pipe, ref callbackmsg, ref steamcall))
            {
                if(callbackmsg.m_iCallback == SteamAPICallCompleted_t.k_iCallback)
                {
                    RunAPICallbacks((SteamAPICallCompleted_t)Marshal.PtrToStructure(callbackmsg.m_pubParam, typeof(SteamAPICallCompleted_t)));
                }

                ICallback callback;
                if(registeredCallbacks.TryGetValue(callbackmsg.m_iCallback, out callback))
                {
                    callback.Run(callbackmsg.m_pubParam);
                }
                else if (unhandledCallback != null)
                {
                    unhandledCallback.Run(callbackmsg);
                }

                Steamworks.FreeLastCallback(pipe);
            }
        }

        private static void DispatchThread(object param)
        {
            int pipe = (int)param;

            while (true)
            {
                RunCallbacks(pipe);
                Thread.Sleep( 1 );
            }
        }

        public static void SpawnDispatchThread(int pipe)
        {
            if(managedThreads.ContainsKey(pipe))
                return;

            Thread dispatchThread = new Thread(DispatchThread);
            dispatchThread.Start(pipe);

            managedThreads[pipe] = dispatchThread;
        }

        public static void StopDispatchThread(int pipe)
        {
            Thread dispatchThread;

            if(managedThreads.TryGetValue(pipe, out dispatchThread))
            {
                dispatchThread.Abort();
                dispatchThread.Join(2500);

                managedThreads.Remove(pipe);
            }
        }
    }
}
