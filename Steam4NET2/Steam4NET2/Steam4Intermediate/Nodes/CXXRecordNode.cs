using System;
using System.Xml;
using Steam4Intermediate.NodeBehavior;

namespace Steam4Intermediate.Nodes
{
    class CXXRecordNode : LinkBehavior
    {
        public CXXRecordNode(XmlAttributeCollection collection)
            : base(collection)
        {

        }

        private bool ShouldEmitMember( INode member )
        {
            if ( member is CXXMethodNode && ( member.GetName().StartsWith( "operator" ) || member.GetAttribute("virtual") != "1" ) )
            {
                return false;
            }

            return true;
        }

        public bool ContainsVirtualMethods()
        {
            int nvirt = 0;

            foreach (INode child in children)
            {
                if (child is CXXMethodNode && ShouldEmitMember(child))
                {
                    nvirt++;
                }
            }

            return (nvirt > 0);
        }

        public int GetChildCount()
        {
            return children.Count;
        }

        private void EmitCodeClass(Generator generator, int depth, int ident)
        {
            generator.EmitLine("[StructLayout(LayoutKind.Sequential,Pack=4)]", depth);
            generator.EmitLine("public class " + name + "VTable", depth);
            generator.EmitLine("{", depth);

            int index = 0;
            foreach (INode child in children)
            {
                if (child is CXXMethodNode && ShouldEmitMember(child))
                {
                    generator.EmitLine("public IntPtr " + child.GetName() + index++ + ";", depth + 1);
                }
                else if (child is CXXDestructorNode)
                {
                    generator.EmitLine("private IntPtr DTor" + GetName() + index++ + ";", depth + 1);
                }
            }

            generator.EmitLine("};", depth);
            generator.EmitLine("", depth);



            generator.EmitLine("public class " + GetName() + " : InteropHelp.NativeWrapper<" + GetName() + "VTable>", depth);
            generator.EmitLine("{", depth);

            index = 0;

            foreach (INode child in children)
            {
                if (child is CXXDestructorNode)
                {
                    index++;
                }
                else if (child is CXXMethodNode && ShouldEmitMember(child))
                {
                    child.EmitCode(generator, depth + 1, index++);
                }
            }

            generator.EmitLine("};", depth);
        }


        private void EmitCodeStruct(Generator generator, int depth, int ident)
        {
            generator.EmitLine("[StructLayout(LayoutKind.Sequential,Pack=8)]", depth);
            generator.EmitLine("public struct " + name, depth);
            generator.EmitLine("{", depth);

            foreach (INode child in children)
            {
                if ( child is FieldNode && !String.IsNullOrEmpty( child.GetName() ) )
                {
                    INode basetype;
                    bool constness, pointer;
                    bool arraytype = false;

                    string size = "";
                    string types = child.ResolveType( 0, out basetype, out constness, out pointer );

                    if ( basetype is ArrayTypeNode )
                    {
                        size = basetype.GetAttribute("size");
                        types = basetype.ResolveType(1, out basetype, out constness, out pointer);

                        pointer = true;
                        arraytype = true;
                    }

                    types = generator.ResolveType( types, constness, pointer, true, false );

                    if ( types == "bool" )
                    {
                        generator.EmitLine( "[MarshalAs(UnmanagedType.I1)]", depth + 1 );
                    }
                    else if ( types == "string" )
                    {
                        if (arraytype)
                        {
                            generator.EmitLine("[MarshalAs(UnmanagedType.ByValTStr, SizeConst = " + size + ")]", depth + 1);
                        }
                        else
                        {
                            types = "IntPtr";
                        }
                    }
                    else if ( types == "Byte[]" )
                    {
                        if (arraytype)
                        {
                            generator.EmitLine("[MarshalAs(UnmanagedType.ByValArray, SizeConst = " + size + ")]", depth + 1);
                        }
                        else
                        {
                            types = "IntPtr";
                        }
                    }
                    else if ( types == "CSteamID" || types == "CGameID" )
                    {
                        types = "UInt64";
                    }
                    else if (pointer)
                    {
                        types = "IntPtr";
                    }
                    else if (types == child.GetName())
                    {
                        continue;
                    }

                    generator.EmitLine( String.Format( "{0} {1};", types, child.GetName() ), depth + 1 );
                }
            }

            generator.EmitLine("};", depth);
            generator.EmitLine("", depth);
        }

        public override void EmitCode(Generator generator, int depth, int ident)
        {
            if (ident == 0)
            {
                EmitCodeClass(generator, depth, ident);
            }
            else if(ident == 1)
            {
                EmitCodeStruct(generator, depth, ident);
            }
        }

    }
}
