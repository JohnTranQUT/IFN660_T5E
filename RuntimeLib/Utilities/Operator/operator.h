#pragma once
#include <iomanip>
#include <RuntimeLib/Types/Types.h>
#include <RuntimeLib/Types/LanguageTypes/LanguageTypes.h>

void _calculate(LanguageType *, string, LanguageType *);
LanguageType *addition(LanguageType *, LanguageType *);
LanguageType *subtraction(LanguageType *, LanguageType *);
LanguageType *multiplication(LanguageType *, LanguageType *);
LanguageType *division(LanguageType *, LanguageType *);
LanguageType *modulus(LanguageType *, LanguageType *);
