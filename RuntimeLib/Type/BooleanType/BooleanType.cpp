#include <RuntimeLib\Type\BooleanType\BooleanType.h>
#include <string>

using namespace std;

bool BooleanType::_getValue() const {
	return _value;
}

string BooleanType::_getType(){
	return _type;
}
