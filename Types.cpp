#include <Types.h>

string ResultContainer::dump() const {
	if (type == "String") {
		return strVal;
	}
	return to_string(dblVal);
}
