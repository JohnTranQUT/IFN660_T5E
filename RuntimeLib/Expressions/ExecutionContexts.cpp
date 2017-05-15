#include <RuntimeLib\Expressions\ExecutionContexts.h>
#include <iostream>

Type * ResolveBinding(string name , LexiEnviType * ENVI)
{
	
	if (ENVI = nullptr)
	{
		cout << "a.Let env be the running execution context's LexicalEnvironment." << endl;
		exit(0);
	}
	else
	{
		auto ref = GetIdentRefe(ENVI, name, false);
		return ref;
	}
	
}
