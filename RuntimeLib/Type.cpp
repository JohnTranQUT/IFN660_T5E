
#include "Type.h"

Type* Type::ToPrimitive()
{
	/*Return this for every type except ObjectType*/
	return this;
}

bool Type::ToBoolean()
{
	/*Return false for every type except ObjectType*/
	return false;
}


