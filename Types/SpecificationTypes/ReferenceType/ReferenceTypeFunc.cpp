#include <Types/SpecificationTypes/ReferenceType/ReferenceType.h>
#include <Types/SpecificationTypes/RecordType/CompletionType/CompletionTypeFunc.h>

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
				base = ToObject(base);
			}
			puts("Return ? base.[[Get]](_V->GetReferenceName(), GetThisValue(_V)");
			exit(0);
		}
		// EnvironmentRecord
		puts("Return ? base.GetBindingValue(_V->GetReferenceName(), _V->IsStrictReference())");
		exit(0);
	}
	return V;
}

LanguageType *GetThisValue(ReferenceType *V) {
	if (V->IsSuperReference()) {
		return V->_getThisValue();
	}
	return V->GetBase();
}