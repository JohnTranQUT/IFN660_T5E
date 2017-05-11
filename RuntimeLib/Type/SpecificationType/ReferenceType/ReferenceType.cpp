
#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <string>
#include <iostream>

using namespace std;
string ReferenceType::_getType()
{
	return _type;
}

Type * GetValue(Type * V)
{
	//ReturnIfAbrupt(V);
	if (V->_getType() != "Reference") {
		return V;
	}
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto base = _V->GetBase(_V);
	if (_V->IsUnresolvableReference(_V) == true)
	{
		cout << "ReferenceError" << endl;
	}
	if (_V->IsPropertyReference(_V) == true)
	{
		if (_V->HasPrimitiveBase(_V) == true)
		{
			auto base = ToObject(_V->GetBase(_V));
		}
		/*else
		{
			return base.[[Get]](GetReferencedName(V), GetThisValue(V));
		}
	}
	else
	{
		auto base = dynamic_cast<EnvironmentRecordType *>(V);
		return base.GetBindingValue(GetReferencedName(V), IsStrictReference(V));
	}	*/
	}
}

void ReferenceType :: ReturnIfAbrupt(Type* V) {
	//Will fill
}

Type * ReferenceType :: GetBase(Type * V){
	if (V->_getType() != "Undefined")
	{
		auto _V = dynamic_cast<UndefinedType *>(V);
		_V->_getValue();
		return _V;
	}
	if (V->_getType() != "Boolean")
	{
		auto _V = dynamic_cast<BooleanType *>(V);
		_V->_getValue();
		return _V;
	}
	if (V->_getType() != "String")
	{
		auto _V = dynamic_cast<StringType *>(V);
		_V->_getValue();
		return _V;
	}
	if (V->_getType() != "Number")
	{
		auto _V = dynamic_cast<NumberType *>(V);
		_V->_getValue();
		return _V;
	}
	//if (dynamic_cast<ObjectType *>(V))
	//if (dynamic_cast<EnvironmentRecord *>(V))
	
}

bool ReferenceType::IsUnresolvableReference(Type * V)
{
	if (V->_getType() == "Undefined")
	{
		return true;
	}
	else { return false; }
}

bool ReferenceType :: IsPropertyReference(Type *V)
{
	if ((V->_getType() == "Object") | (HasPrimitiveBase(V) == true))
		return true;
	else { return false; }
}

bool ReferenceType :: HasPrimitiveBase(Type * V)
{
	if ((V->_getType() == "Number") | (V->_getType() == "String") | (V->_getType() == "Boolean") | (V->_getType() == "symbol"))
		return true;
	else { return false; }
}

