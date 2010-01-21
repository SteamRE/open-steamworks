using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Threading;

namespace Steam4NET
{
    public class Callback<CallbackType>
    {
        public delegate void DispatchDelegate(CallbackType param);
        private DispatchDelegate myCallback;

        public Callback(DispatchDelegate callback, int iCallback)
        {
            myCallback = callback;
            CallbackDispatcher.RegisterCallback(Run, iCallback);
        }

        private void Run(IntPtr pubParam)
        {
            CallbackType param = (CallbackType)Marshal.PtrToStructure(pubParam, typeof(CallbackType));
            myCallback(param);
        }
    }

    public class CallbackDispatcher
    {
        public delegate void RunCallback(IntPtr callbackParam);
        private static Dictionary<int, RunCallback> registeredCallbacks = new Dictionary<int, RunCallback>();

        private static Dictionary<int, Thread> managedThreads = new Dictionary<int, Thread>();

        public static void RegisterCallback(RunCallback del, int iCallback)
        {
            registeredCallbacks[iCallback] = del;
        }

        public static void RunCallbacks(int pipe)
        {
            CallbackMsg_t callbackmsg = new CallbackMsg_t();
            int steamcall = 0;

            while(Steamworks.GetCallback(pipe, ref callbackmsg, ref steamcall))
            {
                Console.WriteLine("Callback: " + callbackmsg.m_iCallback);

                RunCallback callbackdelegate;
                if(registeredCallbacks.TryGetValue(callbackmsg.m_iCallback, out callbackdelegate))
                {
                    callbackdelegate(callbackmsg.m_pubParam);
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
                Thread.Sleep(500);
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
            }
        }
    }
}
