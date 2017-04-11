#pragma once
#include <Types.h>
#include <LanguageTypes.h>

using namespace std;

LanguageType *GetValue(LanguageType *);

class SpecificationType : public Type {
public:
	virtual ~SpecificationType() = 0;
};

class ListType : public SpecificationType {
public:
	virtual ~ListType() = 0;
};

class RecordType : public SpecificationType {
public:
	virtual ~RecordType() = 0;
};

class CompletionType : public RecordType { };

class ReferenceType : public SpecificationType { };