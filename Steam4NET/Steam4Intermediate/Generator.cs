using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.IO;
using System.Text.RegularExpressions;

namespace Steam4Intermediate
{
    class Generator
    {
        Dictionary<string, string> typeDict = new Dictionary<string, string>
        {
            {"char", "SByte"},
            {"signed char", "SByte"},
            {"unsigned char", "Byte"},
            {"short int", "Int16"},
            {"short unsigned int", "UInt16"},
            {"int", "Int32"},
            {"unsigned int", "UInt32"},
            {"long int", "Int32"},
            {"long unsigned int", "UInt32"},
            {"long long int", "Int64"},
            {"long long unsigned int", "UInt64"},
            {"CSteamID", "UInt64"},
            {"CGameID", "UInt64"},
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
            public StructNode(string id, string nname, string nfile, string sz) : base(id) { name = nname; file = nfile; size = Int32.Parse(sz); }
            public override Type Type() { return typeof(StructNode); }

            public string name;
            public int size;

            public string file;
        }

        public class UnionNode : BaseNode
        {
            public UnionNode(string id, string nname, string nfile, string sz) : base(id) { name = nname; file = nfile; size = Int32.Parse(sz); }
            public override Type Type() { return typeof(UnionNode); }

            public string name;
            public int size;

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
            public ClassNode(string id, string nname, string nfile, string sz) : base(id) { name = nname; file = nfile; size = Int32.Parse(sz); }
            public override Type Type() { return typeof(ClassNode); }

            public string name;
            public int size;

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
            public PointerTypeNode(string id, string ntype) : base(id) { type = ntype;  }
            public override Type Type() { return typeof(PointerTypeNode);  }

            public string type;
        }

        public class MethodNode : BaseNode
        {
            public MethodNode(string id, string nname, string nreturn, string nvirtual, string nfile, string nline) : base(id) { name = nname; ret = nreturn; virt = Int32.Parse(nvirtual); arguments = new List<string>(); file = nfile; line = nline; }
            public override Type Type() { return typeof(MethodNode); }

            public string name;
            public string ret;
            public int virt;

            public string file;
            public string line;

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

        public BaseNode AddStruct(string id, string name, string file, string sz)
        {
            StructNode structn = new StructNode(id, name, file, sz);

            nodemap.Add(id, structn);
            return structn;
        }

        public BaseNode AddUnion(string id, string name, string file, string sz)
        {
            UnionNode unionn = new UnionNode(id, name, file, sz);

            nodemap.Add(id, unionn);
            return unionn;
        }

        public BaseNode AddField(string id, string name, string type, string offset)
        {
            FieldNode fieldn = new FieldNode(id, name, type, offset);

            nodemap.Add(id, fieldn);
            return fieldn;
        }

        public BaseNode AddClass(string id, string name, string file, string sz)
        {
            ClassNode classn = new ClassNode(id, name, file, sz);

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

        public BaseNode AddPointerType(string id, string type)
        {
            PointerTypeNode pointn = new PointerTypeNode(id, type);

            nodemap.Add(id, pointn);
            return pointn;
        }

        public BaseNode AddMethod(string id, string name, string ret, string virt, string file, string line)
        {
            MethodNode methodn = new MethodNode(id, name, ret, virt, file, line);

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

                created = AddMethod(nodeid, name, ret, node.Attributes.GetNamedItem("virtual").Value, node.Attributes.GetNamedItem("file").Value, node.Attributes.GetNamedItem("line").Value);

                foreach (XmlNode valuenode in node.ChildNodes)
                {
                    string argtype = valuenode.Attributes.GetNamedItem("type").Value;
                    AddMethodArgument(nodeid, argtype);
                    InsertNode(xmldoc, xmldoc.GetElementById(argtype), rootNode);
                }

                InsertNode(xmldoc, xmldoc.GetElementById(ret), rootNode);
            }
            else if(node.Name == "Struct")
            {
                parent = rootNode;

                XmlNode sizenode = node.Attributes.GetNamedItem("size");
                string size;

                if (sizenode != null)
                    size = sizenode.Value;
                else
                    size = "0";

                created = AddStruct(nodeid, name, node.Attributes.GetNamedItem("file").Value, size);

                InsertMemberNodes(xmldoc, node, created);
            } 
            else if(node.Name == "Class")
            {
                parent = rootNode;

                XmlNode sizenode = node.Attributes.GetNamedItem("size");
                string size;

                if(sizenode != null)
                    size = sizenode.Value;
                else
                    size = "0";

                created = AddClass(nodeid, name, node.Attributes.GetNamedItem("file").Value, size);

                InsertMemberNodes(xmldoc, node, created);
            } 
            else if(node.Name == "Union")
            {
                created = AddUnion(nodeid, name, node.Attributes.GetNamedItem("file").Value, node.Attributes.GetNamedItem("size").Value);

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
            else if (node.Name == "Typedef" || node.Name == "CvQualifiedType") 
            {
                string type = node.Attributes.GetNamedItem("type").Value;
                created = AddTypedef(nodeid, name, type);

                InsertNode(xmldoc, xmldoc.GetElementById(type), rootNode);
            } 
            else if(node.Name == "PointerType" || node.Name == "ReferenceType")
            {
                string type = node.Attributes.GetNamedItem("type").Value;
                created = AddPointerType(nodeid, type);

                InsertNode(xmldoc, xmldoc.GetElementById(type), rootNode);
            }
            else if(node.Name == "FunctionType")
            {
                created = AddFundamental(nodeid, "IntPtr", "0", "0");
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



        public string ResolveType(string id, out BaseNode on, bool attemptPtrs)
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
                    return ResolveType((node as TypedefNode).type, out on, attemptPtrs);
                }
                else if(node.Type() == typeof(UnionNode))
                {
                    return ResolveType(node.childnodes[0].id, out temp, attemptPtrs);
                }
                else if(node.Type() == typeof(ArrayTypeNode))
                {
                    ArrayTypeNode n = node as ArrayTypeNode;
                    int size = n.size / n.align;

                    string type;
                    if (n.type.Length == 0)
                        type = "(implied) char";
                    else
                        type = ResolveType(n.type, out temp, attemptPtrs);

                    return type;
                }
                else if(node.Type() == typeof(PointerTypeNode))
                {
                    if (attemptPtrs)
                    {
                        BaseNode o = on;
                        string t = ResolveType((node as PointerTypeNode).type, out temp, attemptPtrs);

                        on = temp;

                        if (t == "void")
                            return "IntPtr";
                        else if (t == "char")
                            return "string";
                        else if (t == "unsigned char")
                            return "byte[]";

                        on = o;
                        return t;
                    }
                    else
                        return "IntPtr";
                }
                else
                {
                    return "(UNHANDLED)";
                }
            } else {
                on = null;
                return "(UNKNOWN) " + node.id + " " + node;
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
                    Console.WriteLine("Field: " + fnode.name + " type: " + ResolveType(fnode.type, out n, false) + " (" + fnode.type + ")");
                }
                else if(node.Type() == typeof(MethodNode))
                {
                    MethodNode mnode = node as MethodNode;
                    BaseNode n;
                    Console.WriteLine("Method: " + mnode.name + " virtual: " + mnode.virt + " returns: " + ResolveType(mnode.ret, out n, true) + " (" + mnode.ret + ")");
                }

                Dump(node);
            }
        }




        private int level;
        private StringBuilder sb;
        private string prefix = null;
        private Dictionary<string, int> classmethods;

        public void WriteToFile(BaseNode root)
        {
            if (root == null)
            {
                root = rootNode;
                level = 1;

                sb = new StringBuilder();
                sb.AppendLine("using System;");
                sb.AppendLine("using System.Text;");
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

                    if ( files[ enode.file ].StartsWith( @"G:\dev\C++\Open Steamworks" ) )
                    {
                        if (root.Type() == typeof(StructNode) || root.Type() == typeof(ClassNode))
                        {
                            foreach (EnumNode.EnumValue value in enode.values)
                            {
                                sb.AppendLine(new String('\t', level) + "public const int " + value.name + " = " + value.value + ";");
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

                    if ( files[ snode.file ].StartsWith( @"G:\dev\C++\Open Steamworks" ) && !snode.name.StartsWith( "EnumString" ) )
                    {
                        Console.WriteLine("Struct: " + snode.name);

                        if (prefix != null)
                            sb.AppendLine(new String('\t', level) + prefix);

                        sb.AppendLine(new String('\t', level) + "[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=8,Size=" + snode.size + ")]");
                        sb.AppendLine(new String('\t', level) + "public struct " + snode.name);
                        sb.AppendLine(new String('\t', level) + "{");

                        string oldprefix = prefix;
                        prefix = null;

                        level++;
                        WriteToFile(snode);
                        level--;

                        prefix = oldprefix;

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
                else if(node.Type() == typeof(ClassNode))
                {
                    ClassNode cnode = node as ClassNode;

                    if ( files[ cnode.file ].StartsWith( @"G:\dev\C++\Open Steamworks" ) && !cnode.name.StartsWith( "EnumString" ) )
                    {
                        Console.WriteLine("Class: " + cnode.name);

                        if (cnode.name.StartsWith("I"))
                        {
                            GenerateInterfaceWrapper(cnode);
                        }
                        else
                        {
                            if (prefix != null)
                                sb.AppendLine(new String('\t', level) + prefix);

                            sb.AppendLine(new String('\t', level) + "[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=" + cnode.size + ")]");
                            sb.AppendLine(new String('\t', level) + "public struct " + cnode.name);
                            sb.AppendLine(new String('\t', level) + "{");

                            string oldprefix = prefix;
                            prefix = null;

                            level++;
                            WriteToFile(cnode);
                            level--;

                            prefix = oldprefix;

                            sb.AppendLine(new String('\t', level) + "}");
                            sb.AppendLine(new String('\t', level) + "");
                        }
                    }
                }
                else if(node.Type() == typeof(MethodNode))
                {
 
                }
            }

            if (level == 1)
            {
                sb.AppendLine("}");
                File.WriteAllText(@"G:\dev\C++\Open Steamworks\Steam4NET\test.cs", sb.ToString());
            }
        }

        public void ProcessType(FieldNode fieldbase, string ntype)
        {
            BaseNode n;
            string type = ResolveType(ntype, out n, false);
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

                if ( files[ unode.file ].StartsWith( @"G:\dev\C++\Open Steamworks" ) )
                {
                    string name = unode.name;

                    if (name.Contains("$"))
                        name = fieldbase.name;

                    if (name.Length == 0)
                        name = "value";

                    Console.WriteLine("Union");

                    sb.AppendLine();
                    sb.AppendLine(new String('\t', level) + "[StructLayout(LayoutKind.Explicit,CharSet=CharSet.Ansi,Pack=1,Size=" + unode.size + ")]");
                    sb.AppendLine(new String('\t', level) + "public struct Union" + name);
                    sb.AppendLine(new String('\t', level) + "{");

                    prefix = "[FieldOffset(0)]";

                    level++;
                    WriteToFile(unode);
                    level--;

                    prefix = null;

                    sb.AppendLine(new String('\t', level) + "}");
                    sb.AppendLine(new String('\t', level) + "public Union" + name + " " + name + ";");
                    sb.AppendLine();
                }
              
            }
            else if (n.Type() == typeof(ArrayTypeNode))
            {
                ArrayTypeNode an = n as ArrayTypeNode;

                sb.AppendLine(new String('\t', level) + "[MarshalAs(UnmanagedType.ByValArray, SizeConst = " + (an.size / an.align) + ")]");
                sb.AppendLine(new String('\t', level) + "public " + type + "[] " + fieldbase.name + ";");
            }
            else
            {
                if (type == "bool")
                    sb.AppendLine(new String('\t', level) + "[MarshalAs(UnmanagedType.I1)]");

                sb.AppendLine(new String('\t', level) + "public " + type + " " + fieldbase.name + ";");
            }
        }

        public void GenerateInterfaceWrapper(ClassNode cnode)
        {
            sb.AppendLine(new String('\t', level) + "[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1)]");
            sb.AppendLine(new String('\t', level) + "public class " + cnode.name + "VTable");
            sb.AppendLine(new String('\t', level) + "{");

            level++;
            Dictionary<string, int> names = new Dictionary<string, int>();

            foreach(BaseNode n in cnode.childnodes)
            {
                if (n.Type() == typeof(MethodNode))
                {
                    MethodNode mnode = n as MethodNode;
                    int mc;
                    string ptrname = mnode.name;

                    if (names.TryGetValue(ptrname, out mc))
                    {
                        names[ptrname] = mc + 1;
                        ptrname = ptrname + mc.ToString();
                    }
                    else
                    {
                        names[ptrname] = 1;
                    }

                    sb.AppendLine(new String('\t', level) + "public IntPtr " + ptrname + ";");
                }
            }
            level--;

            sb.AppendLine(new String('\t', level) + "}");
            sb.AppendLine(new String('\t', level) + "");

            sb.AppendLine(new String('\t', level) + "public class " + cnode.name + " : NativeWrapper<" + cnode.name + "VTable>");
            sb.AppendLine(new String('\t', level) + "{");

            level++;
            classmethods = new Dictionary<string, int>();

            foreach (BaseNode n in cnode.childnodes)
            {
                if (n.Type() == typeof(MethodNode))
                {
                    ProcessVirtualMethod(n as MethodNode, cnode);
                }
            }

            classmethods = null;
            level--;

            sb.AppendLine(new String('\t', level) + "}");
            sb.AppendLine(new String('\t', level) + "");
        }

        public void ProcessVirtualMethod(MethodNode mnode, ClassNode cnode)
        {
            if (mnode.virt == 1)
            {
                BaseNode n;
                bool passtypeasparam = false;
                bool utf8magic = false;

                string type = ResolveType(mnode.ret, out n, true);
                string dtype;

                if (type == "CSteamID")
                {
                    passtypeasparam = true;
                }

                if(type == "string")
                {
                    utf8magic = true;
                }

                if (typeDict.TryGetValue(type, out dtype))
                {
                    type = dtype;
                }

                if (type.StartsWith("I", StringComparison.InvariantCulture) && mnode.name.StartsWith("Get", StringComparison.InvariantCulture) && (cnode.name.StartsWith("ISteamClient") || cnode.name.StartsWith("IClientEngine")))
                    type = "IntPtr";

                string mname = mnode.name;
                string delname = mname;
                int mc;

                if (classmethods.TryGetValue(mname, out mc))
                {
                    classmethods[mname] = mc + 1;
                    delname = delname + mc.ToString();
                } else {
                    classmethods[mname] = 1;
                }

                sb.Append(new String('\t', level) + "[UnmanagedFunctionPointer(CallingConvention.ThisCall)] private delegate ");

                if (passtypeasparam)
                {
                    sb.Append("void");
                }
                else
                {
                    sb.Append(type);
                }

                sb.Append(" Native" + delname + "(IntPtr thisobj, ");

                if (passtypeasparam)
                {
                    sb.Append("ref " + type + " ret, ");
                }

                ProcessMethodArgs(mnode, false);

                sb.Remove(sb.Length - 2, 2);

                sb.AppendLine(");");

                sb.Append(new String('\t', level));

                if (type == "bool")
                    sb.Append("[return: MarshalAs(UnmanagedType.I1)] ");

                sb.Append("public " + type + " " + mname + "(");

                ProcessMethodArgs(mnode, false);

                if (mnode.arguments.Count > 0)
                    sb.Remove(sb.Length - 2, 2);

                sb.Append(") { ");

                if (passtypeasparam)
                {
                    sb.Append(type + " ret = 0; ");
                }
                
                sb.Append("var call = this.GetFunction<Native" + delname + ">(this.Functions." + delname + "); ");

                if (type != "void" && !passtypeasparam)
                {
                    sb.Append("return ");

                    if(utf8magic)
                    {
                        sb.Append("Encoding.UTF8.GetString( Encoding.Default.GetBytes( ");
                    }
                }

                sb.Append("call(this.ObjectAddress, ");

                if (passtypeasparam)
                {
                    sb.Append("ref ret, ");
                }

                ProcessMethodArgs(mnode, true);
                sb.Remove(sb.Length - 2, 2);

                if (utf8magic)
                {
                    sb.Append(") ) ");
                }

                sb.Append("); ");

                if (passtypeasparam)
                {
                    sb.Append("return ret; ");
                }

                sb.AppendLine("}");
                sb.AppendLine();
            }
        }

        public void ProcessMethodArgs(MethodNode mnode, bool nameonly)
        {
            BaseNode n;
            int paramnum = 0;

            List<string> argnames = ScrapeArgNames(mnode.file, mnode.line);

            foreach (string arg in mnode.arguments)
            {
                string type = ResolveType(arg, out n, true);
                string dtype;

                bool utf8magic = false;

                if ( type == "string" )
                    utf8magic = true;

                if (typeDict.TryGetValue(type, out dtype))
                {
                    type = dtype;
                }

                if (!nameonly && type == "bool")
                    sb.Append("[MarshalAs(UnmanagedType.I1)] ");

                if (n.Type() == typeof(PointerTypeNode))
                    sb.Append("ref ");

                string argname = argnames[paramnum].Trim();

                if (argname.Length == 0 || argname.EndsWith("*") || argname == "bool" || argname == "float" || argname == type || argname == "CSteamID" || argname == "int" || argname == "short" || argname == "uint32" || argname == "\"\"")
                    argname = "arg" + (paramnum + 1);

                if (argname.StartsWith("*") || argname.StartsWith("&"))
                    argname = argname.Substring(1);

                if (argname.StartsWith("*"))
                    argname = argname.Substring(1);

                if (type == "IntPtr" && !(argname.StartsWith("pCallback") || argname.StartsWith("pFunction")) )
                {
                    type = "byte[]";
                }

                if ( nameonly )
                {
                    if ( utf8magic )
                        sb.Append( "Encoding.Default.GetString( Encoding.UTF8.GetBytes( " );

                    sb.Append( argname /*+ ", "*/ );

                    if ( utf8magic )
                        sb.Append( " ) )" );

                    sb.Append( ", " );
                }
                else
                    sb.Append( type + " " + argname + ", " );

                paramnum++;
            }
        }

        public List<string> ScrapeArgNames(string file, string line)
        {
            string[] lines = File.ReadAllLines(files[file]);

            string func = lines[Int32.Parse(line)-1];

            Console.WriteLine(func);

            List<string> arglist = new List<string>();

            int firstparen = func.IndexOf('(');
            int commapos = func.IndexOf(',');
            while (commapos != -1)
            {
                int space = Math.Max(func.LastIndexOf(' ', commapos, commapos), firstparen);
                string name = func.Substring(space+1, commapos-space - 1);

                arglist.Add(name);

                commapos = func.IndexOf(',', commapos+1);
            }

            int lastarg = func.IndexOf(")");
            if (lastarg != -1)
            {
                int lastspace = func.LastIndexOf(' ', lastarg, lastarg);
                if(lastarg - lastspace <= 1)
                    lastspace = func.LastIndexOf(' ', lastspace - 1, lastspace - 1) - 1;

                if (lastspace != -1)
                {
                    arglist.Add(func.Substring(lastspace + 1, lastarg - lastspace - 1));
                }
            }

            return arglist;
        }
    }
}
