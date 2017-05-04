#include <js_type.h>
#include "LexicalEnvironment.h"
//Type *GetValue(Type *V)
//{
//	return V; //not check reference
//}

GeneralType* GetValue(Type *V) {
	if (V->_getType() != "reference")
	{
		return static_cast<GeneralType*>(V);
	}
	else
	{	//Type(V) is Reference
		Reference* reference = static_cast<Reference*>(V);
		//let base be GetBase(v)
		//base must be an Environment Record
		EnvironmentRecord *base = static_cast<EnvironmentRecord*>(reference->GetBase());
		string refName = reference->GetReferenceName();
		GeneralType* value = base->GetBindingValue(refName);
		return value;
	}

}

void PutValue(Type* V, GeneralType* W)
{
	//if Type(v) is not Reference, throw a ReferenceError exception
	if (V->_getType() != "reference") {
		throw new exception("ReferenceError");
	}
	else
	{
		Reference* reference = static_cast<Reference*>(V);
		Type* base = reference->GetBase();
		//base must be an Environment Record
		EnvironmentRecord *envr = static_cast<EnvironmentRecord*>(base);
		std::string name = reference->GetReferenceName();
		envr->SetMutableBinding(name, W);
	}
}