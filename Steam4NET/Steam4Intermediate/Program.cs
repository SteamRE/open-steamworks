using System;
using System.IO;
using System.Xml;

namespace Steam4Intermediate
{
    class Program
    {
        static void Main(string[] args)
        {
            if (!File.Exists(@"E:\opensteamworks\Steam4NET\Steam4Intermediate\osw.xml"))
            {
                Console.WriteLine("Generate osw.xml!");
                Console.WriteLine("gccxml.exe \"E:\\opensteamworks\\Open Steamworks\\steamworks.h\" -fxml=\"E:\\opensteamworks\\Steam4NET\\Steam4Intermediate\\osw.xml\" -fshort-enums");
            }

            XmlReaderSettings settings = new XmlReaderSettings();

            settings.ProhibitDtd = false;

            using (XmlReader reader = XmlReader.Create(@"E:\opensteamworks\Steam4NET\Steam4Intermediate\osw.xml", settings))
            {
                XmlDocument xmldoc = new XmlDocument();
                xmldoc.Load(reader);

                ParseXML(xmldoc);
            }
        }

        static void ParseXML(XmlDocument xmldoc)
        {
            Generator gen = new Generator();

            foreach (XmlNode node in xmldoc.SelectNodes("/GCC_XML/Enumeration"))
            {
                gen.InsertNode(xmldoc, node, null);
            }

            foreach (XmlNode node in xmldoc.SelectNodes("/GCC_XML/Struct"))
            {
                gen.InsertNode(xmldoc, node, null);
            }

            foreach (XmlNode node in xmldoc.SelectNodes("/GCC_XML/Class"))
            {
                gen.InsertNode(xmldoc, node, null);
            }

            foreach (XmlNode node in xmldoc.SelectNodes("/GCC_XML/File"))
            {
                gen.InsertNode(xmldoc, node, null);
            }

            gen.WriteToFile(null);
        }
    }
}
