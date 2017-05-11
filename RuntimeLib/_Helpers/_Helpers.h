#pragma once
#include <iostream>
#include <iomanip>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypeFunc.h>
#include <RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h>
#include <RuntimeLib/Evaluations/Expression/MultiplicativeOperators/MultiplicativeOperators.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/Record.h>

void _calculate(LanguageType *, string, LanguageType *);
void _listItemsInRecord(Record *);
