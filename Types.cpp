#include <Types.h>

string ResultContainer::dump() const {
	if (type == "String") {
		return strVal;
	}
	return to_string(dblVal);
}

string ResultContainer::getType() const {
	return type;
}