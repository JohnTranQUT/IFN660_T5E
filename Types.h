#pragma once
#include <string>

using namespace std;
class Type {
public:
	virtual ~Type() { };
};

class ResultContainer {
	string strVal;
	double dblVal;
	string type;
public:
	explicit ResultContainer(string _strVal) : strVal(_strVal), dblVal(0), type("String") { };
	explicit ResultContainer(double _dblVal) : strVal(""), dblVal(_dblVal), type("Number") { };
	string dump() const;
	string getType() const;
};