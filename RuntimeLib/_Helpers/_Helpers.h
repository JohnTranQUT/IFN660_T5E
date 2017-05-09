#pragma once
#include <iostream>
#include <iomanip>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypesFunc.h>
#include <RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h>
#include <RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/RecordType.h>

void _calculate(LanguageType *, string, LanguageType *);
void _listItemsInRecord(RecordType *);
