#include "operators.h"

static std::string addition(std::string lval, std::string rval) 
{ return lval + rval; }

template <class T2>
static std::string addition(std::string lval, T2 rval)
{
	auto temp = rval;
	if (typeid(temp) == typeid(bool)) {
		if (temp) return lval + std::string("true");
		else return lval + std::string("false");
	}
	return lval + std::to_string(temp);
}


template <class T1>
static std::string addition(T1 lval, std::string rval)
{
	auto temp = lval;
	std::cout << typeid(temp).name() << "\n";
	if (typeid(temp) == typeid(bool)) {
		if (temp) return std::string("true") + rval;
		else return std::string("false") + rval;
	}
	return std::to_string(temp) + rval;
}

static int addition(int lval, int rval)
{
	return lval + rval;
}

template<class T1, class T2>
static double addition(T1 lval, T2 rval)
{
	return lval + rval;
}