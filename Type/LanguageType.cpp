#pragma once
#include "LanguageType.h"

Number::Number(double input, bool positive, bool isNaN) 
{ 
	value = input; 
	_isPositive = positive; 
	_isNaN = isNaN;
}


void Number::set(double input, bool positive) 
{ 
	value = input; 
	_isPositive = positive; 
	_isNaN = false; 
}

void Number::set(Number input)
{
	value = input.get();
	_isInfinitive = input.isInfinitive();
	_isNaN = input.isNaN();
	_isPositive = input.isPositive();

}

double Number::get() 
{ 
	return value; 
}

string Number::to_string() 
{ 
	if (_isNaN) return "NaN";
	if (_isInfinitive) return string(_isPositive ? "" : "-") + string("Infinity");
	return std::to_string(value); 
}

Type* Number::to_number() 
{ 
	return this; 
}

void Number::setInfinitive(bool infinitive, bool positive) 
{ 
	_isInfinitive = infinitive; 
	_isPositive = positive;  
	_isNaN = false;  
}


Number Number::operator+(const Number &rhs)
{
	Number result;
	//  If either operand is NaN, the result is NaN.
	if (this->_isNaN || rhs._isNaN) return Number(0,true,true);
	//	The sum of two infinities of opposite sign is NaN.
	//	The sum of two infinities of the same sign is the infinity of that sign.
	if (this->_isInfinitive && rhs._isInfinitive)
	{
		if (this->_isPositive != rhs._isPositive) return Number(0,true,true);
		return *this;
	}
	//	The sum of an infinity and a finite value is equal to the infinite operand.
	if (this->_isInfinitive) return *this;
	if (rhs._isInfinitive) return rhs;
	//	The sum of two negative zeroes is - 0. The sum of two positive zeroes, or of two zeroes of opposite sign, is + 0.
	if (this->value == 0 && rhs.value == 0)
	{
		if (!this->_isPositive && !rhs._isPositive) return *this;
		return Number(0.0);
	}
	//	The sum of a zero and a nonzero finite value is equal to the nonzero operand.
	if (this->value == 0) return rhs;
	if (rhs.value == 0) return *this;
	//	The sum of two nonzero finite values of the same magnitude and opposite sign is + 0.
	//	In the remaining cases, where neither an infinity, nor a zero, nor NaN is involved, and the operands have the same sign or have different magnitudes, the sum is computed and rounded to the nearest representable value using IEEE 754 - 2008 round to nearest, ties to even mode.If the magnitude is too large to represent, the operation overflows and the result is then an infinity of appropriate sign.The ECMAScript language requires support of gradual underflow as defined by IEEE 754 - 2008.
	if ((this->value < 0 == rhs.value < 0) && (abs(this->value) > numeric_limits<double>::max() - abs(rhs.value)))
	{ //exceed numeric limit of double
		result.setInfinitive(true, this->value > 0);
		return result;
	}
	result.set(this->value + rhs.value);
	return result;
}
//
//double ToNumber(Type obj)
//{
//		if (typeid(obj) == typeid(Undefined)) return NULL;
//		if (typeid(obj) == typeid(String)) return NULL; //not implemented
//		if (typeid(obj) == typeid(Function)) return NULL; //not implemented
//		if (typeid(obj) == typeid(Object)) return NULL; //not implemented
//		return obj.to_number();
//}
