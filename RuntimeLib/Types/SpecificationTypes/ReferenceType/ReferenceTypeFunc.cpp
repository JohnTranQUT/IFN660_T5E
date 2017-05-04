#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceType.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/CompletionType/CompletionTypeFunc.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>
#include "ReferenceTypeFunc.h"

using namespace std;

Type *GetValue(Type *V) {
	if (auto _V = dynamic_cast<CompletionType *>(V)) {
		auto isArruptCompletion = ReturnIfAbrupt(_V);
		if (dynamic_cast<CompletionType *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		V = isArruptCompletion;
	}
	if (auto _V = dynamic_cast<ReferenceType *>(V)) {
		auto base = _V->GetBase();
		if (_V->IsUnresolvableReference()) {
			puts("ReferenceError");
			exit(0);
		}
		if (_V->IsPropertyReference()) {
			if (_V->HasPrimitiveBase()) {
				base = ToObject(dynamic_cast<LanguageType *>(base));
			}
			puts("Return ? base.[[Get]](_V->GetReferenceName(), GetThisValue(_V)");
			exit(0);
		}
		auto _base = dynamic_cast<EnvironmentRecord *>(base);
		return _base->GetBindingValue(dynamic_cast<StringType *>(_V->GetReferencedName()), _V->IsStrictReference());
	}
	return V;
}

Type *PutValue(Type *V, Type *W) {
	if (auto _V = dynamic_cast<CompletionType *>(V)) {
		auto isArruptCompletion = ReturnIfAbrupt(_V);
		if (dynamic_cast<CompletionType *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		V = isArruptCompletion;
	}
	if (auto _W = dynamic_cast<CompletionType *>(W)) {
		auto isArruptCompletion = ReturnIfAbrupt(_W);
		if (dynamic_cast<CompletionType *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		W = isArruptCompletion;
	}
	if (auto _V = dynamic_cast<ReferenceType *>(V)) {
		auto base = _V->GetBase();
		if (_V->IsUnresolvableReference()) {
			if (_V->IsStrictReference()) {
				puts("ReferenceError");
				exit(0);
			}
			//			auto globalObj = GetGlobalObject();
			//			return Set(globalObject, V->GetReferencedName(), W, new BooleanType(false));
			puts("Set(globalObject, V->GetReferencedName(), W, new BooleanType(false))");
			exit(0);
		} else if (_V->IsPropertyReference()) {
			if (_V->HasPrimitiveBase()) {
				base = ToObject(dynamic_cast<LanguageType *>(base));
			}
			//			auto succeeded = base.[[Set]](_V->GetReferencedName(), W, GetThisValue(_V));
			//			if (!succeeded->_getValue() && _V->IsStrictReference()->_getValue()) {
			//				puts("TypeError");
			//				exit(0);
			//			}
			puts("base.[[Set]](_V->GetReferencedName(), W, GetThisValue(_V))");
			exit(0);
		} else {
			auto _base = dynamic_cast<EnvironmentRecord *>(base);
			_base->SetMutableBinding(ToString(_V->GetReferencedName()), dynamic_cast<LanguageType *>(W), _V->IsStrictReference());
		}
	} else {
		puts("ReferenceError");
		exit(0);
	}
	return nullptr;
}

Type *GetThisValue(ReferenceType *V) {
	if (V->IsSuperReference()) {
		return V->_getThisValue();
	}
	return V->GetBase();
}
