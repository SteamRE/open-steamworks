using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using KeyValueParser;
using System.IO;

namespace ResourceConverter
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<string, string> langdict = new Dictionary<string, string>();

            KVItem langtree = KVParser.ReadFromFile("tf_english.txt");
            for (int i = 0; i < langtree.subItems.Count; i++)
            {
                for (int x = 0; x < langtree.subItems[i].subItems.Count; x++)
                {
                    KVItem subitem = langtree.subItems[i].subItems[x];
                    string lower = subitem.key.ToLower();

                    langdict.Add(lower, subitem.value);
                }
            }

            KVItem tree = KVParser.ReadFromFile("items.txt");
            List<short> indexes = new List<short>();
            List<string> names = new List<string>();

            for (int i = 0; i < tree.subItems.Count; i++)
            {
                string index = tree.subItems[i].key;

                for (int x = 0; x < tree.subItems[i].subItems.Count; x++)
                {
                    KVItem subitem = tree.subItems[i].subItems[x];

                    if(subitem.key == "item_name")
                    {
                        string lang = subitem.value;

                        if (lang.Substring(0, 1) == "#")
                        {
                            lang = langdict[lang.Substring(1).ToLower()];
                            if (lang.Length > 63)
                                lang = lang.Substring(0, 63);
                        }

                        indexes.Add(Int16.Parse(index));
                        names.Add(lang);

                        break;
                    }
                }

            }

            FileStream fs = File.Create("item.db");
            BinaryWriter bw = new BinaryWriter(fs);

            bw.Write((Int16)indexes.Count);
            for (int x = 0; x < indexes.Count; x++)
            {
                bw.Write(indexes[x]);
                bw.Write(names[x]);
            }

            bw.Close();
            fs.Close();

            Console.WriteLine("Completed. (" + indexes.Count + " items)");
        }
    }
}
