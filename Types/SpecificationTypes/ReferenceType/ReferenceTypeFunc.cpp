#include <Types/SpecificationTypes/ReferenceType/ReferenceType.h>
#include <Types/SpecificationTypes/RecordType/CompletionType/CompletionTypeFunc.h>

using namespace std;

Type *GetValue(Type *V) {
	if (auto _V = dynamic_cast<CompletionType *>(V)) {
		auto isArruptCompletion = ReturnIfAbrupt(_V);
		if (dynamic_cast<CompletionType *>(isArruptCompletion)) {
			return isArruptCompletion;
		} else {
			V = isArruptCompletion;
		}
	}
	if (auto _V = dynamic_cast<ReferenceType*>(V)) {
		auto base = _V->GetBase();
		if (_V->IsUnresolvableReference()) {
			puts("ReferenceError");
			exit(0);
		}
		if (_V->IsPropertyReference()) {
			if (_V->HasPrimitiveBase()) {
				base = ToObject(base);
			}
			puts("Object");
			puts("Return ? base.[[Get]](GetReferenceName(), GetThisValue()");
			exit(0);
		} else {
			puts("EnvironmentRecord");
			puts("Return ? base.GetBindingValue(GetReferenceName(), IsStrictReference())");
			exit(0);
		}
	} else {
		return V;
	}
}
