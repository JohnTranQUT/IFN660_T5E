#define _CRT_SECURE_NO_DEPRECATE
#include <Type.h>
#include <operator.h>
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

Type *  addition(Type * lref, Type * rref)
{
	Type * lval = get_value(lref);
	Type * rval = get_value(rref);
	Type * lprim = ToPrimitive(lval);
	Type * rprim = ToPrimitive(rval);
	if (typeid(*lprim) == typeid(String) | typeid(*rprim) == typeid(String))
	{
		string lstr = ToString(lprim);
		string rstr = ToString(rprim);
		cout << "(" << "string:" << lstr << ")" << "+" << "(" << "string:" << rstr << ")" << "=" << "(" << "string:" << lstr << rstr << ")" << endl;
		string newstring = lstr + rstr;
		Type * value = new String(newstring);
		return value;
	}
	else
	{
		double lstr = ToNumber(lprim);
		double rstr = ToNumber(rprim);
		double sum = lstr + rstr;
		cout << "(" << "number:" << lstr << ")" << "+" << "(" << "number:" << rstr << ")" << "=" << "(" << "number:" << sum << ")" << endl;
		double newnumber = lstr + rstr;
		Type * value = new Number(newnumber);
		return value;
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
	if (typeid(*argu) == typeid(Undefined))
	{
		return NAN;
	}
	else if (typeid(*argu) == typeid(Null))
	{
		return +0;
	}
	else if (typeid(*argu) == typeid(Boolean))
	{
		Boolean * newargu = dynamic_cast <Boolean *> (argu);
		bool value = newargu->VALUE();
		if (value == true) { return 1; }
		if (value == false) { return +0; }
	}
	else if (typeid(*argu) == typeid(Number))
	{
		Number * newargu = dynamic_cast <Number *> (argu);
		double value = newargu->VALUE();
		return value;
	}
	else if (typeid(*argu) == typeid(String))				//not completed
	{
	
	}
	else if (typeid(*argu) == typeid(Symbol))
	{
		cout << "Type Error!" << endl;
		exit(0);
	}
}

bool  ToBoolean(Type * argu)
{
	if (typeid(*argu) == typeid(Undefined))
	{
		return false;
	}
	else if (typeid(*argu) == typeid(Null))
	{
		return false;
	}
	else if (typeid(*argu) == typeid(Boolean))
	{
		Boolean * newargu = dynamic_cast <Boolean *> (argu);
		bool value = newargu->VALUE();
		return value;
	}
	else if (typeid(*argu) == typeid(Number))
	{
		Number * newargu = dynamic_cast <Number *> (argu);
		double value = newargu->VALUE();
		if ((value == 0)| (value == NAN) )
		{ 
			return false; 
		}
		else 
		{ 
			return true; 
		}
	}
	else if (typeid(*argu) == typeid(String))				//not completed
	{
		String * newargu = dynamic_cast <String *> (argu);
		string value = newargu->VALUE();
		if (value == "" )
		{
			cout << "kong" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (typeid(*argu) == typeid(Symbol))
	{
		cout << "true" << endl;
		return true;
	}
}

string ToString(Type * argu)
{
	if (typeid(*argu) == typeid(Undefined))
	{
		return "undefined";
	}
	else if (typeid(*argu) == typeid(Null))
	{
		return "null";
	}
	else if (typeid(*argu) == typeid(Boolean))
	{
		Boolean * newargu = dynamic_cast <Boolean *> (argu);
		bool value = newargu->VALUE();
		if (value == true) { return "true"; }
		if (value == false) { return "false"; }
	}
	else if (typeid(*argu) == typeid(Number))
	{
		Number * newargu = dynamic_cast <Number *> (argu);
		double value_ = newargu->VALUE();
		if (isnan(value_)) 
		{ 
			return "NaN"; 
		}
		else if (isinf(value_))
		{
			return "Infinity";
		}
		else
		{
			String * newargu_ = dynamic_cast <String *> (argu);
			char value[100];
			_itoa(value_, value, 10);
			return value;
		}
	}
	else if (typeid(*argu) == typeid(String))
	{
		String * newargu = dynamic_cast <String *> (argu);
		string value = newargu->VALUE();
		return value;
	}
	else if (typeid(*argu) == typeid(Symbol))
	{
		cout << "Type Error!" << endl;
		exit(0);
	}
}