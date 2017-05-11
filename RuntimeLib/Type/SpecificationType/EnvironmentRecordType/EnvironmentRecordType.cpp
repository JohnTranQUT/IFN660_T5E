#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
#include <string>
#include <map>
#include <iostream>



bool EnviRecordType::HasBinding(string N)
{
	auto envRec = ER.find(N);
	if (envRec != ER.end())
		return true;
	else return false;
}

Type * EnviRecordType::CreateMutableBinding(string N, bool D)
{
	auto envRec = ER.find(N);
	cout << "does not already have a binding for " << N << endl;
	ER.insert(pair<string, Type *>(N, value));
	return value;
}

Type * EnviRecordType::InitializeBinding(string N, LanguageType * V)
{
	auto envRec = ER.find(N);
	cout << "must have an uninitialized binding for " << N << endl;
	ER.insert(pair<string, LanguageType *>(N, V));
	return V;
}

string EnviRecordType::GetBindingValue(string N, bool S)
{
	auto envRec = ER.find(N);
	cout << "has a binding for " << N << endl;
	ER.insert(pair<string, Type *>(N, value));
	return N;
}
