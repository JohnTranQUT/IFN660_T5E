#include <Types/SpecificationTypes/SpecificationTypesFunc.h>

using namespace std;

LanguageType *GetValue(Type *V) {
	if (auto _V = dynamic_cast<ReferenceType*>(V)) {
		puts("ReferenceType");
		exit(0);
	} else {
		return dynamic_cast<LanguageType *>(V);
	}
}