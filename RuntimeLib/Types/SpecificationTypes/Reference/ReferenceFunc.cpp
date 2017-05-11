#include <RuntimeLib/Types/SpecificationTypes/Reference/Reference.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecordFunc.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/GlobalEnvironmentRecord/GlobalEnvironmentRecord.h>

using namespace std;

Type *GetValue(Type *V) {
	if (auto _V = dynamic_cast<CompletionRecord *>(V)) {
		auto isArruptCompletion = ReturnIfAbrupt(_V);
		if (dynamic_cast<CompletionRecord *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		V = isArruptCompletion;
	}
	if (auto _V = dynamic_cast<Reference *>(V)) {
		auto base = _V->GetBase();
		if (_V->IsUnresolvableReference()->_getValue()) {
			puts("ReferenceError");
			exit(0);
		}
		if (_V->IsPropertyReference()->_getValue()) {
			if (_V->HasPrimitiveBase()->_getValue()) {
				base = ToObject(dynamic_cast<LanguageType *>(base));
			}
			puts("Return ? base.[[Get]](_V->GetReferenceName(), GetThisValue(_V)");
			exit(0);
		}
		if (auto _base = dynamic_cast<DeclarativeEnvironmentRecord *>(base)) {
			return _base->GetBindingValue(dynamic_cast<StringType *>(_V->GetReferencedName()), _V->IsStrictReference());
		}
		if (auto _base = dynamic_cast<ObjectEnvironmentRecord *>(base)) {
			return _base->GetBindingValue(dynamic_cast<StringType *>(_V->GetReferencedName()), _V->IsStrictReference());
		}
		if (auto _base = dynamic_cast<GlobalEnvironmentRecord *>(base)) {
			return _base->GetBindingValue(dynamic_cast<StringType *>(_V->GetReferencedName()), _V->IsStrictReference());
		}
		puts("EnvironmentRecord");
		exit(0);
	}
	return V;
}

Type *PutValue(Type *V, Type *W) {
	if (auto _V = dynamic_cast<CompletionRecord *>(V)) {
		auto isArruptCompletion = ReturnIfAbrupt(_V);
		if (dynamic_cast<CompletionRecord *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		V = isArruptCompletion;
	}
	if (auto _W = dynamic_cast<CompletionRecord *>(W)) {
		auto isArruptCompletion = ReturnIfAbrupt(_W);
		if (dynamic_cast<CompletionRecord *>(isArruptCompletion)) {
			return isArruptCompletion;
		}
		W = isArruptCompletion;
	}
	if (auto _V = dynamic_cast<Reference *>(V)) {
		auto base = _V->GetBase();
		if (_V->IsUnresolvableReference()->_getValue()) {
			if (_V->IsStrictReference()->_getValue()) {
				puts("ReferenceError");
				exit(0);
			}
			//						auto globalObj = GetGlobalObject();
			//						return Set(globalObject, V->GetReferencedName(), W, new BooleanType(false));
			puts("Set(globalObject, V->GetReferencedName(), W, new BooleanType(false))");
			exit(0);
		} else if (_V->IsPropertyReference()->_getValue()) {
			if (_V->HasPrimitiveBase()->_getValue()) {
				base = ToObject(dynamic_cast<LanguageType *>(base));
			}
			//			auto succeeded = base.[[Set]](_V->GetReferencedName(), W, GetThisValue(_V));
			//			if (!succeeded->_getValue() && _V->IsStrictReference()->_getValue()) {
			//				puts("TypeError");
			//				exit(0);
			//			}
			puts("base.[[Set]](_V->GetReferencedName(), W, GetThisValue(_V))");
			exit(0);
		}
		if (auto _base = dynamic_cast<DeclarativeEnvironmentRecord *>(base)) {
			_base->SetMutableBinding(ToString(_V->GetReferencedName()), dynamic_cast<LanguageType *>(W), _V->IsStrictReference());
		} else if (auto _base = dynamic_cast<ObjectEnvironmentRecord *>(base)) {
			_base->SetMutableBinding(ToString(_V->GetReferencedName()), dynamic_cast<LanguageType *>(W), _V->IsStrictReference());
		} else if (auto _base = dynamic_cast<GlobalEnvironmentRecord *>(base)) {
			_base->SetMutableBinding(ToString(_V->GetReferencedName()), dynamic_cast<LanguageType *>(W), _V->IsStrictReference());
		} else {
			puts("EnvironmentRecord");
			exit(0);
		}
	} else {
		puts("ReferenceError");
		exit(0);
	}
	return nullptr;
}

Type *GetThisValue(Reference *V) {
	if (V->IsSuperReference()) {
		return V->_getThisValue();
	}
	return V->GetBase();
}
