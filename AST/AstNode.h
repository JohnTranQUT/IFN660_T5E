#pragma once
#include <vector>
#include <map>
using namespace std;

class Node {
public:
	explicit Node() {}
	~Node() {};
	virtual void dump(int indent) = 0;
	void dump(int i, char* name);
	void emit(FILE* outputfile, char* fmt, ...);
protected: //Protected members are accessible in the sub-class
	void indent(int N);
	void label(int i, char* fmt, ...);
};

