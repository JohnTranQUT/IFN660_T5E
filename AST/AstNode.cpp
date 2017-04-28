#include <cstdio>
#include "AST/AstNode.h"
#include <cstdarg>

using namespace std;


void Node::dump(int i, char* name)
{
	label(i, "%s:\n", name);
	dump(i + 1);
}

void Node::indent(int N)
{
	for (int i = 0; i < N; i++)
		printf("    ");
}

void Node::label(int i, char* fmt, ...)
{
	indent(i);
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
}
