#pragma once
#include <vector>
#include <RuntimeLib/Types/SpecificationTypes/SpecificationTypes.h>
#include <RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h>

class List : public SpecificationType {
	vector<Type *> list;
public:
	List() { }
	BooleanType *_contain(Type *);
};
