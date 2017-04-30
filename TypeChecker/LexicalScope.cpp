#include "LexicalScope.h"



LexicalScope::LexicalScope()
{
	parentScope = nullptr;
	symbol_table.clear();
}

Declaration* LexicalScope::ResolveHere(std::string symbol)
{
	std::map<std::string, Declaration*>::iterator iter = symbol_table.find(symbol);
	if (iter != symbol_table.end())
		//Return a Declaration 
		return iter->second;
	return nullptr;
}

//Resolve a name at local scope and parent scope
Declaration* LexicalScope::Resolve(std::string symbol)
{
	Declaration* local = ResolveHere(symbol);
	if (local != nullptr)
		return local;
	else if (parentScope != nullptr)
		return parentScope->Resolve(symbol);
	else
		return nullptr;
}


LexicalScope::~LexicalScope()
{
	
}
