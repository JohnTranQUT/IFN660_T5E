#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>

string ObjectType::_getValue() {
	return "[object Object]";
}

string ObjectType::_getType() {
	return _type;
}
