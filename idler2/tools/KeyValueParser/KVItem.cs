#region Program Header

// THE BELOW HEADER MUST NOT BE REMOVED OR MODIFIED
//
// This file is part of KeyValueParser.
//
// KeyValueParser is licensed under the
// Creative Commons Attribution-Noncommercial-Share Alike 3.0
// (http://creativecommons.org/licenses/by-nc-sa/3.0/us/) license.
//
// For more information visit
// http://creativecommons.org/licenses/by-nc-sa/3.0/us/
//
// THE ABOVE HEADER MUST NOT BE REMOVED OR MODIFIED

#endregion

#region Using

// Default using
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

#endregion

namespace KeyValueParser
{
    /// <summary>
    /// KV item class
    /// </summary>
    /// <remarks>
    /// This class supports unlimited
    /// levels of sub items
    /// </remarks>
    public class KVItem
    {
        #region Public Objects

        /// <summary>
        /// The key
        /// </summary>
        public string key = null;

        /// <summary>
        /// The value
        /// </summary>
        /// <remarks>
        /// If null, this is a section
        /// </remarks>
        public string value = null;       

        /// <summary>
        /// Any sub items
        /// </summary>
        public List<KVItem> subItems = new List<KVItem>();

        #endregion

        #region Constructors

        /// <summary>
        /// Constructor
        /// </summary>
        public KVItem()
        {

        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="key">
        /// The key
        /// </param>
        /// <param name="value">
        /// The value
        /// </param>
        public KVItem(string key, string value)
        {
            // Save the key and value
            this.key = key;
            this.value = value;
        }

        #endregion

        /// <summary>
        /// Gets if this is a section
        /// </summary>
        /// <returns></returns>
        public bool isSection() { return value == null; }

        /// <summary>
        /// Gets if this seciton has sub items
        /// </summary>
        /// <returns></returns>
        public bool hasSubItems() { return subItems.Count > 0; }
    }
}
