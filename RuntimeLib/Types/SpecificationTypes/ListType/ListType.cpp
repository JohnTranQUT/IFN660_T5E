#include <RuntimeLib/Types/SpecificationTypes/ListType/ListType.h>

BooleanType *ListType::_contain(Type *input) {
	auto it = find(list.begin(), list.end(), input);
	return new BooleanType(it != list.end());
}
