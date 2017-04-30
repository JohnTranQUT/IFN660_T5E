#pragma once
#include  <cstdio>
#include "TypeChecker/LexicalScope.h"
using namespace std;

class Node {
public:
	virtual ~Node() = default;
	virtual void dump(int indent) = 0;
	//virtual bool ResolveNames(LexicalScope* scope) = 0;
	void dump(int i, char* name);
protected: //Protected members are accessible in the sub-class
	void indent(int N);
	void label(int i, char* fmt, ...);
};
