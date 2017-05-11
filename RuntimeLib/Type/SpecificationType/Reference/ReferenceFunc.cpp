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
	if (_V->IsPropertyReference()->_getValue()) {
		if (_V->HasPrimitiveBase()->_getValue()) {
			if (!dynamic_cast<UndefinedType *>(base) && !!dynamic_cast<NullType *>(base))
				true;//WIP base ToObject(base); // Return base in object form?!?!?
		}
		return base;//->.Get(GetReferenceName(V),GetThisValue(V)) //UNSURE OF THE THIS METHOD. Recursively return the object within the object for property types?
	}else{
		auto _base = dynamic_cast<EnvironmentRecord *>(base);
		auto _GetReferenceName = dynamic_cast<StringType *>(_V->GetReferenceName());
		return _base->GetBindingValue(_GetReferenceName, _V->IsStrictReference());
	}
}

CompletionRecord* PutValue(Type* V, Type* W) {
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

CompletionRecord* InitializedReferencedBinding(Type * V, Type * W){
	ReturnIfAbrupt(V);
	ReturnIfAbrupt(W);
	auto _V = dynamic_cast<Reference *>(V); // convert into reference
	_V->IsUnresolvableReference()->_getValue(); // is resolvable
	auto base = _V->GetBase();
	auto _base = dynamic_cast<EnvironmentRecord *>(base);
	auto _GetReferenceName = dynamic_cast<StringType *>(_V->GetReferenceName()); //  need stringtype to pass
	return _base->InitializeBinding(_GetReferenceName, W);
}

//Specification Type methods?

Type* GetGlobalObject() {
	return nullptr;
}

CompletionRecord* Set(Type* O, LanguageType* P, Type* V, BooleanType* Throw) {
	return nullptr;
}