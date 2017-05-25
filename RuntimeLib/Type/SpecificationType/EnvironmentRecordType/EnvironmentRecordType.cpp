#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
#include <RuntimeLib\Expressions\AdditiveOperators.h>
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
	Type * value = new UndefinedType();
	ER.insert(pair<string, Type *>(N, value));
	return nullptr;
}

Type * EnviRecordType::InitializeBinding(string N, LanguageType * V)
{
	auto envRec = ER.find(N);
	envRec->second = V;
	return nullptr;
}

Type * EnviRecordType::GetBindingValue(string N, bool S)
{
	auto envRec = ER.find(N);
	if (S == true)
	{
		cout << "ReferenceError" << endl;
		exit(0);
	}
	if (S == false) 
		if (envRec != ER.end())
		{
			auto value = envRec->second;
			return value;
		}
		else
		{
			cout << "ReferenceError" << endl;
			exit(0);
		}
}

Type * EnviRecordType::SetMutableBinding(string N, Type * V, bool S)
{
	auto envRec = ER.find(N);
	if (envRec == ER.end())
	{
		if (S == true)
		{
			cout << "ReferenceError" << endl;
		}
		else
		{
			CreateMutableBinding(N, true);
			auto _V = dynamic_cast<LanguageType *>(V);
			InitializeBinding(N, _V);
			return nullptr;
		}
	}
	if (envRec != ER.end())
	{
		if (envRec->second == nullptr)
		{
			cout << "ReferenceError" << endl;
		}
		else
		{
			envRec->second = V;
		}
	}
	return nullptr;
}

map<string, Type*> EnviRecordType::getmap()
{
	return ER;
}

void GetERvalue(EnviRecordType * _ER)
{
	auto ERmap = _ER->getmap();
	map<string, Type*>::iterator it;
	for (it = ERmap.begin(); it != ERmap.end(); it++)
	{
		cout << it->first << " = ";	
		if (auto _it = dynamic_cast<NumberType *>(it->second))
				cout << ToNumber(_it) << endl;
		if (auto _it = dynamic_cast<StringType *>(it->second))
				cout << ToString(_it) << endl;

		
	}
}

