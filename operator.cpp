#include <Type.h>
#include <operator.h>
#include <iostream>
#include <string>

using namespace std;

void  addition(Type * lref, Type * rref)
{
	Type * lval = get_value(lref);
	Type * rval = get_value(rref);
	Type * lprim = ToPrimitive(lval);
	Type * rprim = ToPrimitive(rval);
	if (typeid(*lprim) == typeid(String) | typeid(*rprim) == typeid(String))
	{
		string lstr = ToString(lprim);
		string rstr = ToString(rprim);
		cout << "(" << "string:" << lstr << ")" << "+" << "(" << "string:" << rstr << ")" << "=" << "(" << "string:" << lstr << " " << rstr << ")" << endl;
	}
	else if (typeid(*lprim) == typeid(Number) | typeid(*rprim) == typeid(Number))
	{
		double lstr = ToNumber(lprim);
		double rstr = ToNumber(rprim);
		double sum = lstr + rstr;
		cout << "(" << "number:" << lstr << ")" << "+" << "(" << "number:" << rstr << ")" << "=" << "(" << "number:" << sum << ")" << endl;
	}
}


Type * get_value(Type * value)
{
	return value;
};
		
Type * ToPrimitive(Type * input)
{
	return input;
};

double  ToNumber(Type * argu)
{	
	if (typeid(*argu) == typeid(Number))
	{
		Number * newargu = dynamic_cast <Number *> (argu);
		double value = newargu->VALUE();
		return value;
	};
}

bool  ToBoolean(Type * argu)
{  
	if (typeid(*argu) == typeid(Boolean))
	{
		Boolean * newargu = dynamic_cast <Boolean *> (argu);
		bool value = newargu->VALUE();
		return value;
	};
}

string ToString(Type * argu)
{
	if (typeid(*argu) == typeid(String))
	{
		String * newargu = dynamic_cast <String *> (argu);
		string value = newargu->VALUE();
		return value;
	};
}