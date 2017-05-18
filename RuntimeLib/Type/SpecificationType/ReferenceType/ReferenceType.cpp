#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceType.h>
#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
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
	ReturnIfAbrupt(V);
	if (V->_getType() != "Reference") {
		return V;
	}
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto base = _V->GetBase();
	if (_V->IsUnresolvableReference(_V) == true)
	{
		cout << "ReferenceError" << endl;
	}
	if (_V->IsPropertyReference(_V) == true)
	{
		if (_V->HasPrimitiveBase(_V) == true)
		{
			auto base = ToObject(_V->GetBase());
		}
		else
		{
			cout << "base.[[Get]](GetReferencedName(V), GetThisValue(V))" << endl;
		}
	}
	else
	{
		auto base = dynamic_cast<EnviRecordType *>(V);
		auto RFname = _V->GetReferenceName(_V);
		auto flag = _V->IsStrictReference(_V);
		return base->GetBindingValue(RFname, flag);
	}	
}

Type * PutValue(Type * V, Type * W)
{
	ReturnIfAbrupt(V);
	ReturnIfAbrupt(W);
	if (V->_getType() != "Reference") {
		cout << "ReferenceError" << endl;
	}
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto _base = _V->GetBase();
	if (_V->IsUnresolvableReference(_V) == true)
	{
		if (_V->IsStrictReference(_V) == true)
		{
			cout << "ReferenceError" << endl;
		}
		/*	else
		{
			b.Let globalObj be GetGlobalObject().
			c.Return ? Set(globalObj, GetReferencedName(V), W, false).* /
			exit(0);
		}	*/
	}
	else if (_V->IsPropertyReference(_V) == true)
	{
		if (_V->HasPrimitiveBase(_V) == true)
		{
			auto base = ToObject(_base);
		}
		else
		{
			/*b.Let succeeded be ? base.[[Set]](GetReferencedName(V), W, GetThisValue(V)).
			c.If succeeded is false and IsStrictReference(V) is true, throw a TypeError exception.
			d.Return.	*/
		}
	}
	else
	{
		auto base = dynamic_cast<EnviRecordType *>(_base);
		auto RFname = _V->GetReferenceName(_V);
		auto flag = _V->IsStrictReference(_V);
		return base->SetMutableBinding(RFname, W, flag);
	}
}


Type * InitializeReferencedBinding(Type * V, Type * W)
{
	ReturnIfAbrupt(V);
	ReturnIfAbrupt(W);
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto _base = _V->GetBase();
	auto newbase = dynamic_cast<EnviRecordType *>(_base);
	auto RFname = _V->GetReferenceName(_V);
	return newbase->InitializeBinding(RFname, ToLanguage(W));
	
}

void ReturnIfAbrupt(Type *)
{
}


Type * ReferenceType :: GetBase()
{
	return base;
}

string ReferenceType::GetReferenceName(Type *)
{
	return name;
}

bool ReferenceType::IsStrictReference(Type *)
{
	return strict;
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

