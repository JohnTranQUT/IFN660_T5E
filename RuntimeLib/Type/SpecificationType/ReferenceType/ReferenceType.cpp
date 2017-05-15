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
	/*else
	{
		auto base = dynamic_cast<EnviRecordType *>(V);
		return base->GetBindingValue(GetReferencedName(V), IsStrictReference(V));
	}	*/
	return V;
}

Type * PutValue(Type * V, Type * W)
{
	ReturnIfAbrupt(V);
	ReturnIfAbrupt(W);
	if (V->_getType() != "Reference") {
		cout << "ReferenceError" << endl;
	}
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto base = _V->GetBase();
	if (_V->IsUnresolvableReference(_V) == true)
	{
		/*a.If IsStrictReference(V) is true, theni.Throw a ReferenceError exception.
		b.Let globalObj be GetGlobalObject().
		c.Return ? Set(globalObj, GetReferencedName(V), W, false).*/
		exit(0);
	}
	else if (_V->IsPropertyReference(_V) == true)
	{
		if (_V->HasPrimitiveBase(_V) == true)
		{
			cout << "In this case, base will never be null or undefined." << endl;
			exit(0);
		}
		else
		{
			/*b.Let succeeded be ? base.[[Set]](GetReferencedName(V), W, GetThisValue(V)).
			c.If succeeded is false and IsStrictReference(V) is true, throw a TypeError exception.
			d.Return.	*/
			exit(0);
		}
	}
	else
	{
		auto newbase = dynamic_cast<EnviRecordType *>(_V->GetBase());
		cout << "Return ? base.SetMutableBinding(GetReferencedName(V), W, IsStrictReference(V))" << endl;
	}
}


Type * InitializeReferencedBinding(Type * V, Type * W)
{
	ReturnIfAbrupt(V);
	ReturnIfAbrupt(W);
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto newbase = _V->GetBase();
	auto _base = dynamic_cast<EnviRecordType *>(newbase);
	auto newV = _V->GetReferenceName(_V);
	cout << "1" << endl;
	string newstringV = ToString(newV);
	cout << newstringV << endl;
	return _base->InitializeBinding(newstringV, ToLanguageType(W));
	
}

void ReturnIfAbrupt(Type *)
{
}


Type * ReferenceType :: GetBase()
{
	return base;
}

LanguageType * ReferenceType::GetReferenceName(Type *)
{
	return RF;
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

