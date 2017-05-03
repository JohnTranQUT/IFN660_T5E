
#include "JSValue.h"

JSValue* JSValue::ToPrimitive()
{
	/*Return this for every type except ObjectValue*/
	return this;
}

bool JSValue::ToBoolean()
{
	/*Return false for every type except ObjectValue*/
	return false;
}


