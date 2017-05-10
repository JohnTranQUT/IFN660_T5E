#include <RuntimeLib\Type\SpecificationType\Reference\ReferenceFunc.h>


LanguageType* GetValue(Type* V) {
	ReturnIfAbrupt(V);
	if (!dynamic_cast<Reference *>(V))
		return dynamic_cast<LanguageType *>(V);
	auto _V = dynamic_cast<Reference *>(V);
	auto base = _V->GetBase();
	if (_V->IsUnresolvableReference()->_getValue()) {
		puts("ReferenceError");
		exit(0);
	}
	if (_V->IsPropertyReference()->_getValue())
		if (_V->HasPrimitiveBase()->_getValue()) {
			if (!dynamic_cast<UndefinedType *>(base) && !!dynamic_cast<NullType *>(base))
				true;//WIP base ToObject(base);
			return base;//[[Get]](GetReferenceName(V),GetThisValue(V))
		}
	else //base must be an Environment Records
		return base;//GetBindingValue(GetRefencedName(V),IsStrictReference(V))
}

LanguageType* PutValue(Type* V, Type* W) {
	ReturnIfAbrupt(V);
	ReturnIfAbrupt(W);
	if (!dynamic_cast<Reference *>(V)) {
		puts("ReferenceError");
		exit(0);
	}
	auto _V = dynamic_cast<Reference *>(V);
	auto base = _V->GetBase();
	if (_V->IsUnresolvableReference()->_getValue()) {
		if (_V->IsStrictReference()->_getValue()) {
			puts("ReferenceError");
			exit(0);
		}
		auto globalObj = GetGlobalObject();
		return Set(globalObj, _V->GetReferenceName(), W, new BooleanType(false));

	}
	else if (_V->IsPropertyReference()->_getValue()) {
		if (_V->HasPrimitiveBase()->_getValue()) {
			if (!dynamic_cast<UndefinedType *>(base) && !!dynamic_cast<NullType *>(base))
				true;//WIP base ToObject(base);
			//auto succeeded = base.Set(globalObj, _V->GetReferenceName(),W,new BooleanType(false));
			auto suceeded = new BooleanType(false); // Temp
			if(!suceeded->_getValue() && _V->IsStrictReference()->_getValue()){
				puts("TypeError");
				exit(0);
			}
		}
		return nullptr;
	}
	else {
		auto _base = dynamic_cast<EnvironmentRecord *>(base);
		auto _GetReferenceName = dynamic_cast<StringType *>(_V->GetReferenceName());
		auto _W = dynamic_cast<LanguageType *>(W);
		return _base->SetMutableBinding(_GetReferenceName, _W, _V->IsStrictReference());
		return nullptr;
	}
	
}

//Specification Type methods?

Type* GetGlobalObject() {
	return nullptr;
}

LanguageType* Set(Type* O, LanguageType* P, Type* V, BooleanType* Throw) {
	return nullptr;
}