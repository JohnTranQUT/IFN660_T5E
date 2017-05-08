#pragma once
#include <RuntimeLib\Type\SpecificationType\Record\Record.h>
#include <RuntimeLib\Type\LanguageType\LanguageType.h>

class CompletionRecord : Record {
	string _type = "normal";//Type of completion normal, break, return or throw
	LanguageType* Value;//Value to produce
	LanguageType* Target;//target label for direct control transfers
public :
	explicit CompletionRecord(string _type, LanguageType* Value, LanguageType* Target = nullptr)
		: _type(_type), Value(Value), Target(Target) {};
	bool AbruptCompletion();
	string _getType();
	LanguageType* _getValue();
	LanguageType* _getTarget();
 };