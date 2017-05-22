#include "RuntimeLib/Types/SpecificationTypes/List/List.h"

BooleanType *List::_contain(Type *input) {
	auto it = find(list.begin(), list.end(), input);
	return new BooleanType(it != list.end());
}
