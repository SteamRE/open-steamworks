using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.IO;

namespace Steam4Intermediate
{
    class Generator
    {
        Dictionary<string, string> typeDict = new Dictionary<string, string>
        {
            {"char", "SByte"},
            {"unsigned char", "Byte"},
            {"short int", "Int16"},
            {"short unsigned int", "UInt16"},
            {"int", "Int32"},
            {"unsigned int", "UInt32"},
            {"long int", "Int32"},
            {"long unsigned int", "UInt32"},
            {"long long int", "Int64"},
            {"long long unsigned int", "UInt64"},
        };

        public abstract class BaseNode
        {
            public BaseNode(string nid) { id = nid; childnodes = new List<BaseNode>(); }
            public abstract Type Type();

            public string id;
            public List<BaseNode> childnodes;
        }

        public class RootNode : BaseNode
        {
            public RootNode() : base("_1") {}
            public override Type Type() { return typeof(RootNode); }
        }

        public class NamespaceNode : BaseNode
        {
            public NamespaceNode(string id, string nsname) : base(id) { name = nsname;  }
            public override Type Type() { return typeof(NamespaceNode); }

            public string name;
        }

        public class EnumNode : BaseNode
        {
            public EnumNode(string id, string nname, string nfile) : base(id) { name = nname; file = nfile; values = new List<EnumValue>(); }
            public class EnumValue
            {
                public EnumValue(string ename, string evalue) { name = ename; value = evalue; }
                public string name;
                public string value;
            }

            public override Type Type() { return typeof(EnumNode); }

            public string name;
            public List<EnumValue> values;

            public string file;
        }

        public class StructNode : BaseNode
        {
            public StructNode(string id, string nname, string nfile) : base(id) { name = nname; file = nfile; }
            public override Type Type() { return typeof(StructNode); }

            public string name;

            public string file;
        }

        public class UnionNode : BaseNode
        {
            public UnionNode(string id, string nname, string nfile) : base(id) { name = nname; file = nfile; }
            public override Type Type() { return typeof(UnionNode); }

            public string name;

            public string file;
        }

        public class FieldNode : BaseNode
        {
            public FieldNode(string id, string nname, string ntype, string noffset) : base(id) { name = nname; type = ntype; offset = noffset; }
            public override Type Type() { return typeof(FieldNode); }

            public string name;
            public string type;
            public string offset;
        }

        public class ClassNode : BaseNode
        {
            public ClassNode(string id, string nname, string nfile) : base(id) { name = nname; file = nfile; }
            public override Type Type() { return typeof(ClassNode); }

            public string name;

            public string file;
        }

        public class FundamentalNode : BaseNode
        {
            public FundamentalNode(string id, string ntype, string nsize, string nalign) : base(id) { type = ntype; size = Int32.Parse(nsize); align = Int32.Parse(nalign); }
            public override Type Type() { return typeof(FundamentalNode); }

            public string type;
            public int size;
            public int align;
        }

        public class TypedefNode : BaseNode
        {
            public TypedefNode(string id, string nname, string ntype) : base(id) { name = nname; type = ntype; }
            public override Type Type() { return typeof(TypedefNode); }

            public string name;
            public string type;
        }

        public class ArrayTypeNode : BaseNode
        {
            public ArrayTypeNode(string id, string ntype, string nsize, string nalign) : base(id) { type = ntype; size = Int32.Parse(nsize); align = Int32.Parse(nalign); }
            public override Type Type() { return typeof(ArrayTypeNode); }

            public string type;
            public int size;
            public int align;
        }

        public class PointerTypeNode : BaseNode
        {
            public PointerTypeNode(string id) : base(id) {}
            public override Type Type() { return typeof(PointerTypeNode);  }
        }

        public class MethodNode : BaseNode
        {
            public MethodNode(string id, string nname, string nreturn, string nvirtual) : base(id) { name = nname; ret = nreturn; virt = Int32.Parse(nvirtual); arguments = new List<string>(); }
            public override Type Type() { return typeof(MethodNode); }

            public string name;
            public string ret;
            public int virt;

            public List<string> arguments;
        }

        private Dictionary<string, BaseNode> nodemap = new Dictionary<string, BaseNode>();
        private BaseNode rootNode;

        private Dictionary<string, string> files = new Dictionary<string, string>();

        public Generator()
        {
            rootNode = AddNamespace("_1", "::");
        }

        public BaseNode AddNamespace(string id, string name)
        {
            NamespaceNode nsnode = new NamespaceNode(id, name);

            nodemap.Add(id, nsnode);
            return nsnode;
        }

        public BaseNode AddEnum(string id, string name, string file)
        {
            EnumNode enumn = new EnumNode(id, name, file);

            nodemap.Add(id, enumn);
            return enumn;
        }

        public void AddEnumValue(string id, string name, string value)
        {
            EnumNode enumn = nodemap[id] as EnumNode;
            enumn.values.Add(new EnumNode.EnumValue(name, value));
        }

        public BaseNode AddStruct(string id, string name, string file)
        {
            StructNode structn = new StructNode(id, name, file);

            nodemap.Add(id, structn);
            return structn;
        }

        public BaseNode AddUnion(string id, string name, string file)
        {
            UnionNode unionn = new UnionNode(id, name, file);

            nodemap.Add(id, unionn);
            return unionn;
        }

        public BaseNode AddField(string id, string name, string type, string offset)
        {
            FieldNode fieldn = new FieldNode(id, name, type, offset);

            nodemap.Add(id, fieldn);
            return fieldn;
        }

        public BaseNode AddClass(string id, string name, string file)
        {
            ClassNode classn = new ClassNode(id, name, file);

            nodemap.Add(id, classn);
            return classn;
        }

        public BaseNode AddFundamental(string id, string type, string size, string align)
        {
            FundamentalNode funn = new FundamentalNode(id, type, size, align);

            nodemap.Add(id, funn);
            return funn;
        }

        public BaseNode AddTypedef(string id, string name, string type)
        {
            TypedefNode typen = new TypedefNode(id, name, type);

            nodemap.Add(id, typen);
            return typen;
        }

        public BaseNode AddArrayType(string id, string type, string size, string align)
        {
            ArrayTypeNode arrn = new ArrayTypeNode(id, type, size, align);

            nodemap.Add(id, arrn);
            return arrn;
        }

        public BaseNode AddPointerType(string id)
        {
            PointerTypeNode pointn = new PointerTypeNode(id);

            nodemap.Add(id, pointn);
            return pointn;
        }

        public BaseNode AddMethod(string id, string name, string ret, string virt)
        {
            MethodNode methodn = new MethodNode(id, name, ret, virt);

            nodemap.Add(id, methodn);
            return methodn;
        }

        public void AddMethodArgument(string id, string type)
        {
            MethodNode methodn = nodemap[id] as MethodNode;
            methodn.arguments.Add(type);
        }

        public void InsertMemberNodes(XmlDocument xmldoc, XmlNode node, BaseNode created)
        {
            XmlNode membernode = node.Attributes.GetNamedItem("members");
            if (membernode != null && membernode.Value.Length > 0)
            {
                string[] list = membernode.Value.Trim().Split(' ');

                foreach (string mnode in list)
                {
                    InsertNode(xmldoc, xmldoc.GetElementById(mnode), created);
                }
            }
        }

        public BaseNode InsertNode(XmlDocument xmldoc, XmlNode node, BaseNode parent)
        {
            string nodeid = node.Attributes.GetNamedItem("id").Value;
            BaseNode exisitingnode;

            XmlNode contextnode = node.Attributes.GetNamedItem("context");

            if(contextnode != null)
            {
                string id = contextnode.Value;
                contextnode = xmldoc.GetElementById(id);
                parent = InsertNode(xmldoc, contextnode, parent);
            }

            if (nodemap.TryGetValue(nodeid, out exisitingnode))
                return exisitingnode;

            if(parent == null && node.Name != "File")
            {
                //Dump(null);
                Console.WriteLine("no parent");
            }

            BaseNode created = null;

            string name;
            if (node.Attributes.GetNamedItem("name") != null)
                name = node.Attributes.GetNamedItem("name").Value;
            else if (node.Attributes.GetNamedItem("demangled") != null)
                name = node.Attributes.GetNamedItem("demangled").Value;
            else
                name = nodeid;

            if (node.Name == "Namespace")
            {
                created = AddNamespace(nodeid, name);
            }
            else if(node.Name == "Enumeration")
            {
                created = AddEnum(nodeid, name, node.Attributes.GetNamedItem("file").Value);

                foreach (XmlNode valuenode in node.ChildNodes)
                {
                    AddEnumValue(nodeid, valuenode.Attributes.GetNamedItem("name").Value, valuenode.Attributes.GetNamedItem("init").Value);
                }
            }
            else if(node.Name == "Method")
            {
                string ret = node.Attributes.GetNamedItem("returns").Value;

                created = AddMethod(nodeid, name, ret, node.Attributes.GetNamedItem("virtual").Value);

                foreach (XmlNode valuenode in node.ChildNodes)
                {
                    AddMethodArgument(nodeid, valuenode.Attributes.GetNamedItem("type").Value);
                }

                InsertNode(xmldoc, xmldoc.GetElementById(ret), rootNode);
            }
            else if(node.Name == "Struct")
            {
                created = AddStruct(nodeid, name, node.Attributes.GetNamedItem("file").Value);

                InsertMemberNodes(xmldoc, node, created);
            } 
            else if(node.Name == "Class")
            {
                created = AddClass(nodeid, name, node.Attributes.GetNamedItem("file").Value);

                InsertMemberNodes(xmldoc, node, created);
            } 
            else if(node.Name == "Union")
            {
                created = AddUnion(nodeid, name, node.Attributes.GetNamedItem("file").Value);

                InsertMemberNodes(xmldoc, node, created);
            } 
            else if(node.Name == "Field")
            {
                string type = node.Attributes.GetNamedItem("type").Value;
                created = AddField(nodeid, name, type, node.Attributes.GetNamedItem("offset").Value);

                InsertNode(xmldoc, xmldoc.GetElementById(type), rootNode);
            } 
            else if(node.Name == "FundamentalType")
            {
                string size;
                XmlNode sizen = node.Attributes.GetNamedItem("size");

                if (sizen != null)
                    size = sizen.Value;
                else
                    size = "0";

                created = AddFundamental(nodeid, name, size, node.Attributes.GetNamedItem("align").Value);
            } 
            else if(node.Name == "ArrayType")
            {
                string type;
                XmlNode typen = node.Attributes.GetNamedItem("type");

                if (typen != null)
                    type = typen.Value;
                else
                    type = "";

                string size;
                XmlNode sizen = node.Attributes.GetNamedItem("size");

                if (sizen != null)
                    size = sizen.Value;
                else
                    size = "0";

                created = AddArrayType(nodeid, type, size, node.Attributes.GetNamedItem("align").Value);
            } 
            else if(node.Name == "Typedef") 
            {
                string type = node.Attributes.GetNamedItem("type").Value;
                created = AddTypedef(nodeid, name, type);

                InsertNode(xmldoc, xmldoc.GetElementById(type), rootNode);
            } 
            else if(node.Name == "PointerType")
            {
                created = AddPointerType(nodeid);
            }
            else if(node.Name == "File")
            {
                files[nodeid] = name;
            }
            else
            {
                Console.WriteLine("Unhandled node " + node.Name);
            }

            if (created != null)
            {
                if(parent.childnodes.Contains(created))
                {
                    Console.WriteLine("Duplicate detected!");
                }

                parent.childnodes.Add(created);
            }
            return created;
        }



        public string ResolveType(string id, out BaseNode on)
        {
            BaseNode node;
            BaseNode temp;

            if(nodemap.TryGetValue(id, out node))
            {
                on = node;
                Console.WriteLine(node.Type());

                if (node.Type() == typeof(ClassNode))
                {
                    return (node as ClassNode).name;
                }
                else if(node.Type() == typeof(FundamentalNode))
                {
                    return (node as FundamentalNode).type;
                }
                else if(node.Type() == typeof(StructNode))
                {
                    return (node as StructNode).name;
                }
                else if(node.Type() == typeof(EnumNode))
                {
                    return (node as EnumNode).name;
                }
                else if(node.Type() == typeof(TypedefNode))
                {
                    return ResolveType((node as TypedefNode).type, out on);
                }
                else if(node.Type() == typeof(UnionNode))
                {
                    return ResolveType(node.childnodes[0].id, out temp);
                }
                else if(node.Type() == typeof(ArrayTypeNode))
                {
                    ArrayTypeNode n = node as ArrayTypeNode;
                    int size = n.size / n.align;

                    string type;
                    if (n.type.Length == 0)
                        type = "(implied) char";
                    else
                        type = ResolveType(n.type, out temp);

                    return type;
                }
                else if(node.Type() == typeof(PointerTypeNode))
                {
                    return "IntPtr";
                }
                else
                {
                    return "(UNHANDLED)";
                }
            } else {
                on = null;
                return "(UNKNOWN)";
            }
        }



        public void Dump(BaseNode root)
        {
            if (root == null)
                root = rootNode;

            foreach(BaseNode node in root.childnodes)
            {
                if(node.Type() == typeof(EnumNode))
                {
                    EnumNode enode = node as EnumNode;
                    Console.WriteLine("Enum: " + enode.name);
                }
                else if(node.Type() == typeof(StructNode))
                {
                    StructNode snode = node as StructNode;
                    Console.WriteLine("Struct: " + snode.name);
                }
                else if(node.Type() == typeof(UnionNode))
                {
                    UnionNode unode = node as UnionNode;
                    Console.WriteLine("Union: " + unode.name);
                }
                else if(node.Type() == typeof(ClassNode))
                {
                    ClassNode cnode = node as ClassNode;
                    Console.WriteLine("Class: " + cnode.name);
                }
                else if(node.Type() == typeof(FieldNode))
                {
                    FieldNode fnode = node as FieldNode;
                    BaseNode n;
                    Console.WriteLine("Field: " + fnode.name + " type: " + ResolveType(fnode.type, out n) + " (" + fnode.type + ")");
                }
                else if(node.Type() == typeof(MethodNode))
                {
                    MethodNode mnode = node as MethodNode;
                    BaseNode n;
                    Console.WriteLine("Method: " + mnode.name + " virtual: " + mnode.virt + " returns: " + ResolveType(mnode.ret, out n) + " (" + mnode.ret + ")");
                }

                Dump(node);
            }
        }




        private int level;
        private StringBuilder sb;

        public void WriteToFile(BaseNode root)
        {
            if (root == null)
            {
                root = rootNode;
                level = 1;

                sb = new StringBuilder();
                sb.AppendLine("using System;");
                sb.AppendLine("using System.Runtime.InteropServices;");
                sb.AppendLine("using Steam4NET;");
                sb.AppendLine("");
                sb.AppendLine("namespace Steam4NET");
                sb.AppendLine("{");
            }

            foreach (BaseNode node in root.childnodes)
            {
                if (node.Type() == typeof(EnumNode))
                {
                    EnumNode enode = node as EnumNode;

                    if(files[enode.file].StartsWith(@"E:\opensteamworks"))
                    {
                        if (root.Type() == typeof(StructNode))
                        {
                            foreach (EnumNode.EnumValue value in enode.values)
                            {
                                sb.AppendLine(new String('\t', level) + "const int " + value.name + " = " + value.value + ";");
                            }
                        }
                        else
                        {
                            Console.WriteLine("Enum: " + enode.name);
                            sb.AppendLine(new String('\t', level) + "public enum " + enode.name);
                            sb.AppendLine(new String('\t', level) + "{");

                            level++;
                            foreach (EnumNode.EnumValue value in enode.values)
                            {
                                sb.AppendLine(new String('\t', level) + value.name + " = " + value.value + ",");
                            }
                            level--;

                            sb.AppendLine(new String('\t', level) + "}");
                            sb.AppendLine(new String('\t', level) + "");
                        }
                    }
                }
                else if(node.Type() == typeof(StructNode))
                {
                    StructNode snode = node as StructNode;

                    if (files[snode.file].StartsWith(@"E:\opensteamworks") && !snode.name.StartsWith("EnumString"))
                    {
                        Console.WriteLine("Struct: " + snode.name);
                        sb.AppendLine(new String('\t', level) + "public unsafe struct " + snode.name);
                        sb.AppendLine(new String('\t', level) + "{");

                        level++;
                        WriteToFile(snode);
                        level--;

                        sb.AppendLine(new String('\t', level) + "}");
                        sb.AppendLine(new String('\t', level) + "");
                    }
                }
                else if(node.Type() == typeof(FieldNode))
                {
                    FieldNode fnode = node as FieldNode;

                    Console.WriteLine("Field: " + fnode.name);

                    ProcessType(fnode, fnode.type);
                }
            }

            if (level == 1)
            {
                sb.AppendLine("}");
                File.WriteAllText(@"E:\opensteamworks\Steam4NET\test.cs", sb.ToString());
            }
        }

        string prefix = null;

        public void ProcessType(FieldNode fieldbase, string ntype)
        {
            BaseNode n;
            string type = ResolveType(ntype, out n);
            string dtype;

            if (typeDict.TryGetValue(type, out dtype))
            {
                type = dtype;
            }

            if (prefix != null)
                sb.AppendLine(new String('\t', level) + prefix);

            if (n.Type() == typeof(UnionNode))
            {
                UnionNode unode = n as UnionNode;

                if (files[unode.file].StartsWith(@"E:\opensteamworks"))
                {
                    string name = unode.name;

                    if(name.Contains("$"))
                        name = fieldbase.name + "Union";

                    Console.WriteLine("Union");

                    sb.AppendLine();
                    sb.AppendLine(new String('\t', level) + "[System.Runtime.InteropServices.StructLayout(LayoutKind.Explicit)]");
                    sb.AppendLine(new String('\t', level) + "struct " + name);
                    sb.AppendLine(new String('\t', level) + "{");

                    prefix = "[System.Runtime.InteropServices.FieldOffset(0)]";

                    level++;
                    WriteToFile(unode);
                    level--;

                    prefix = null;

                    sb.AppendLine(new String('\t', level) + "}");
                    sb.AppendLine(new String('\t', level) + "");
                }
              
            }
            else if (n.Type() == typeof(ArrayTypeNode))
            {
                //sb.AppendLine("[System.Runtime.InteropServices.FieldOffset(" + fieldbase.offset + ")]");
                sb.AppendLine(new String('\t', level) + "fixed " + type + " " + fieldbase.name + "[" + (n as ArrayTypeNode).size + "];");
            }
            else
            {
                //sb.AppendLine("[System.Runtime.InteropServices.FieldOffset(" + fieldbase.offset + ")]");
                sb.AppendLine(new String('\t', level) + type + " " + fieldbase.name + ";");
            }
        }
    }
}
