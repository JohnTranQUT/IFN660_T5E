#pragma once
#include <Types/Types.h>
#include <Types/LanguageTypes/LanguageTypes.h>

using namespace std;

class SpecificationType : public Type {
public:
	virtual ~SpecificationType() = 0;
};