#pragma once
#include <vector>
#include <RuntimeLib/Types/SpecificationTypes/SpecificationTypes.h>
#include <RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h>

class ListType : public SpecificationType {
	vector<Type *> list;
public:
	ListType() { }
	BooleanType *_contain(Type *);
};
