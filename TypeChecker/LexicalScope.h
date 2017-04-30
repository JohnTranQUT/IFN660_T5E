#pragma once
#include <map>
#include "Declaration.h"
class LexicalScope
{
protected:
	LexicalScope *parentScope;
	std::map<std::string, Declaration*> symbol_table;
public:
	LexicalScope();
	Declaration* ResolveHere(std::string symbol);
	Declaration* Resolve(std::string symbol);
	~LexicalScope();
};

