#pragma once
#include <cstdarg>
using namespace std;

class Node {
public:
	virtual ~Node() = default;
	virtual void dump(int indent) = 0;
	void dump(int i, char* name)
	{
		label(i, "%s:\n", name);
		dump(i + 1);
	}
protected: //Protected members are accessible in the sub-class
	void indent(int N)
	{
		for (int i = 0; i < N; i++)
			printf("  ");
	}
	void label(int i, char* fmt, ...)
	{
		indent(i);
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}
};
