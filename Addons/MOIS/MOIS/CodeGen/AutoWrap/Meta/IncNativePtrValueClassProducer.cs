using System;
using System.Collections.Generic;
using System.Text;

namespace AutoWrap.Meta
{
    class IncNativePtrValueClassProducer : IncClassProducer
    {
        protected override string GetTopBaseClassName()
        {
            return null;
        }

        protected override void AddDefinition()
        {
            _sb.AppendIndent("");
            if (!_t.IsNested)
                _sb.Append("public ");
            else
                _sb.Append(GetProtectionString(_t.ProtectionType) + ": ");
            _sb.AppendFormat("value class {0}\n", _t.CLRName);
        }

        protected override void AddPreDeclarations()
        {
            if (!_t.IsNested)
            {
                _wrapper.AddPreDeclaration("value class " + _t.CLRName + ";");
                _wrapper.AddPragmaMakePublicForType(_t);
            }
        }

        protected override void AddPrivateDeclarations()
        {
            base.AddPrivateDeclarations();
            _sb.AppendLine(_t.FullNativeName + "* _native;");
        }

        protected override void AddPublicDeclarations()
        {
            base.AddPublicDeclarations();

            _sb.AppendLine("DEFINE_MANAGED_NATIVE_CONVERSIONS_FOR_NATIVEPTRVALUECLASS( " + GetClassName() + ", " + _t.FullNativeName + " )");
            _sb.AppendLine();

            _sb.AppendLine();
            _sb.AppendLine("property IntPtr NativePtr");
            _sb.AppendLine("{");
            _sb.AppendLine("\tIntPtr get() { return (IntPtr)_native; }");
            _sb.AppendLine("}");

            if (!IsReadOnly && IsConstructable)
            {
                _sb.AppendLine();
                AddCreators();

                _sb.AppendLine();
                _sb.AppendLine("void DestroyNativePtr()");
                _sb.AppendLine("{");
                _sb.AppendLine("\tif (_native)  { delete _native; _native = 0; }");
                _sb.AppendLine("}");
            }

            _sb.AppendLine();
            _sb.AppendLine("property bool IsNull");
            _sb.AppendLine("{");
            _sb.AppendLine("\tbool get() { return (_native == 0); }");
            _sb.AppendLine("}");
        }

        protected override void AddPublicConstructors()
        {
        }

        protected virtual void AddCreators()
        {
            if (_t.IsNativeAbstractClass)
                return;

            if (_t.Constructors.Length > 0)
            {
                foreach (DefFunction func in _t.Constructors)
                    if (func.ProtectionType == ProtectionType.Public)
                        AddCreator(func);
            }
            else
                AddCreator(null);
        }

        protected virtual void AddCreator(DefFunction f)
        {
            if (f == null)
                _sb.AppendLine("static " + _t.CLRName + " Create();");
            else
            {
                int defcount = 0;

                if (!f.HasAttribute<NoDefaultParamOverloadsAttribute>())
                {
                    foreach (DefParam param in f.Parameters)
                        if (param.DefaultValue != null)
                            defcount++;
                }

                // The overloads (because of default values)
                for (int dc = 0; dc <= defcount; dc++)
                {
                    if (dc < defcount && f.HasAttribute<HideParamsWithDefaultValuesAttribute>())
                        continue;

                    _sb.AppendIndent("static " + _t.CLRName + " Create");
                    AddMethodParameters(f, f.Parameters.Count - dc);
                    _sb.Append(";\n");
                }

            }
        }

        public IncNativePtrValueClassProducer(Wrapper wrapper, DefClass t, IndentStringBuilder sb)
            : base(wrapper, t, sb)
        {
        }
    }
}
