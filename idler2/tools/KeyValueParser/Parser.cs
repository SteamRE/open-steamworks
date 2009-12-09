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
using System.IO;
using System.Text.RegularExpressions;

#endregion

namespace KeyValueParser
{
    /// <summary>
    /// Parser class for key value files
    /// </summary>
    public static class KVParser
    {
        #region WriteToFile

        /// <summary>
        /// Writes <paramref name="kvs"/> to
        /// <paramref name="filePath"/>
        /// </summary>
        /// <param name="kvs">
        /// The KVs to write
        /// </param>
        /// <param name="filePath">
        /// Path to the file to write to
        /// </param>
        public static void WriteToFile(KVItem kvs, string filePath)
        {
            // Holds the lines
            List<string> lines = new List<string>();
            
            // Get the lines
            Write(kvs, lines, 0);

            // Write the lines
            File.WriteAllLines(filePath, lines.ToArray());
        }

        #endregion

        #region Write

        /// <summary>
        /// Writes KVs to a file
        /// </summary>
        /// <param name="kvs">
        /// The KVs to write
        /// </param>
        /// <param name="lines">
        /// The lines collection
        /// </param>
        /// <param name="numOfTabs">
        /// The number of tabs to use
        /// </param>
        public static void Write(KVItem kvs, List<string> lines, int numOfTabs)
        {
            // Is this a section?
            if (kvs.isSection())
            {
                // Add and open the section
                lines.Add(GetTabs(numOfTabs) + "\"" + kvs.key + "\"");
                lines.Add(GetTabs(numOfTabs) + "{");                
            }            

            // Add sub items
            foreach (KVItem item in kvs.subItems)
            {
                // Add the item if it isn't a section
                if (!item.isSection())
                    lines.Add(GetTabs(numOfTabs + 1) +
                              "\"" + item.key + "\"" + GetTabs(2) +
                              "\"" + item.value + "\"");

                // If there are sub items,
                // add them
                if (item.subItems.Count > 0)
                {
                    numOfTabs++;
                    Write(item, lines, numOfTabs);
                    numOfTabs--;
                }
            }

            // Close the section
            lines.Add(GetTabs(numOfTabs) + "}");
        }

        #endregion

        #region GetTabs

        /// <summary>
        /// Returns <paramref name="numOfTabs"/> tabs
        /// </summary>
        /// <param name="numOfTabs">
        /// The number of tabs to return
        /// </param>
        /// <returns>
        /// The tabs
        /// </returns>
        private static string GetTabs(int numOfTabs)
        {
            // Holds the tabs
            string tabs = "";

            // Create the tabs
            for (int i = 0; i < numOfTabs; i++)
                tabs += "\t";

            // Return the tabs
            return tabs;
        }

        #endregion

        #region ReadFromFile

        /// <summary>
        /// Reads a KV file from a file
        /// </summary>
        /// <param name="filePath">
        /// The path to the file
        /// </param>
        /// <returns>
        /// The parsed KVs
        /// </returns>
        public static KVItem ReadFromFile(string filePath)
        {
            // The key values
            KVItem items = new KVItem();
            
            // Read the file
            string[] lines = File.ReadAllLines(filePath);
            
            // Holds the starting index
            int i = 0;

            // Parse the file
            Read(lines, ref i, items);

            // Return the items
            if (items.subItems.Count > 0)
                return items.subItems[0];
            else
                return null;
        }

        #endregion

        #region Read

        /// <summary>
        /// Reads a KV file recursively
        /// </summary>
        /// <param name="lines">
        /// The lines from the KV file
        /// </param>
        /// <param name="index">
        /// The line to start reading at
        /// </param>
        /// <param name="kvs">
        /// The parsed key values
        /// </param>
        private static void Read(string[] lines, ref int index, KVItem kvs)
        {
            // Stores if we are in a multi line comment
            bool multiLC = false;

            // Read the lines
            while (index < lines.Length)
            {
                string cl = lines[index];

                // Increment the counter
                index++;

                // ******* BEGIN: Check for comments

                // At the end of a multi line comment
                if (multiLC && cl.StartsWith("*/"))
                    multiLC = false;

                // In the middle of a multi line comment
                else if (multiLC)
                    ;

                else if (cl.StartsWith("/*"))
                    multiLC = true;

                else if (cl.StartsWith("//"))
                    ;
                // ******* END: Check for comments

                // Check for blank lines
                else if (cl.Trim().Length == 0)
                    ;

                // Real line
                else
                {
                    // Check for in line comments
                    if (cl.Contains("//"))
                    {
                        // Get the index where the comment starts
                        int loc = cl.IndexOf("//");

                        // Remove the comment
                        cl = cl.Remove(loc, cl.Length - loc);
                    }

                    // Check to see if we have a space,
                    // spaces and a brace, or just a brace,
                    // and if any of those are true, skip the line
                    Regex spacesAndOrBrace = new Regex(@"^\s*\{\s*$");

                    if (spacesAndOrBrace.IsMatch(cl))
                        continue;

                    // End of the section, return
                    if (cl.Contains("}"))
                        return;

                    // Read the line as a kv pair
                    KVItem item = new KVItem();
                    int keyStart = -1, keyEnd = -1,
                        valueStart = -1, valueEnd = -1;

                    // Locate the start and end
                    // of the key and value
                    keyStart = cl.IndexOf("\"");
                    keyEnd = cl.IndexOf("\"", keyStart + 1);
                    valueStart = cl.IndexOf("\"", keyEnd + 1);
                    valueEnd = cl.IndexOf("\"", valueStart + 1);

                    // Check for a section with the name and opening brace
                    // on the same line
                    Regex sectionAndBrace = new Regex("^.*[\"].+[\"][\t\x20\r\n]*{.*$");

                    string key = cl.Substring(keyStart + 1, keyEnd - keyStart - 1);

                    if (valueStart >= 0 && valueEnd == -1)
                    {
                        string value = cl.Substring(valueStart + 1);

                        while (index < lines.Length)
                        {
                            string cont = lines[index++];
                            valueEnd = cont.IndexOf("\"", valueStart + 1);
                            if (valueEnd >= 0)
                            {
                                value += cont.Substring(0, valueEnd);
                                break;
                            }
       
                            value += cont;
                        }

                        item.key = key;
                        item.value = value;
                        kvs.subItems.Add(item);
                    }

                    // If there is no value, this is a section
                    else if (valueStart == -1 || valueEnd == -1 || sectionAndBrace.IsMatch(cl))
                    {
                        // Save the key and add the section
                        item.key = key;
                        kvs.subItems.Add(item);

                        // Recursively parse the sub section
                        Read(lines, ref index, item);
                    }

                    // This is a KV pair
                    else
                    {
                        // Set the key and value and add the item
                        item.key = key;
                        item.value = cl.Substring(valueStart + 1, valueEnd - valueStart - 1);
                        kvs.subItems.Add(item);
                    }
                }

            } // End line reading loop            

        } // End method

        #endregion
    }        
}