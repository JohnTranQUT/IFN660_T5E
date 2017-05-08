#pragma once
#include <RuntimeLib\Type\Type.h>
#include <cstdio>
#include <string>

using namespace std;

class SpecificationType : public Type{
public:
	virtual ~SpecificationType() {};
	string _getType() override;
};
