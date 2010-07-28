using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

/*
 Steamworks and NativeWrapper classes provided by Rick - http://gib.me/
*/

namespace Steam4NET
{
    public interface INativeWrapper
    {
        void SetupFunctions(IntPtr objectAddress);
    }

    public abstract class NativeWrapper<TNativeFunctions> : INativeWrapper
    {
        protected IntPtr ObjectAddress;

        public IntPtr Interface
        {
            get { return ObjectAddress; }
        }

        protected TNativeFunctions Functions;

        public override string ToString()
        {
            return string.Format(
                "Steam Interface<{0}> #{1:X8}",
                typeof(TNativeFunctions),
                this.ObjectAddress.ToInt32());
        }


        public void SetupFunctions(IntPtr objectAddress)
        {
            this.ObjectAddress = objectAddress;

            IntPtr vtableptr = Marshal.ReadIntPtr(this.ObjectAddress);

            this.Functions = (TNativeFunctions)Marshal.PtrToStructure(
                vtableptr, typeof(TNativeFunctions));
        }

        private Dictionary<IntPtr, Delegate> FunctionCache = new Dictionary<IntPtr, Delegate>();

        protected Delegate GetDelegate<TDelegate>(IntPtr pointer)
        {
            Delegate function;

            if (this.FunctionCache.ContainsKey(pointer) == false)
            {
                function = Marshal.GetDelegateForFunctionPointer(pointer, typeof(TDelegate));
                this.FunctionCache[pointer] = function;
            }
            else
            {
                function = this.FunctionCache[pointer];
            }

            return function;
        }

        protected TDelegate GetFunction<TDelegate>(IntPtr pointer)
            where TDelegate : class
        {
            return (TDelegate)((object)this.GetDelegate<TDelegate>(pointer));
        }

        protected void Call<TDelegate>(IntPtr pointer, params object[] args)
        {
            this.GetDelegate<TDelegate>(pointer).DynamicInvoke(args);
        }

        protected TReturn Call<TReturn, TDelegate>(IntPtr pointer, params object[] args)
        {
            return (TReturn)this.GetDelegate<TDelegate>(pointer).DynamicInvoke(args);
        }
    }
}