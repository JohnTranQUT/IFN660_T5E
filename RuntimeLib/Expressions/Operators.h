#pragma once
#include <RuntimeLib\Type\Type.h>
#include <RuntimeLib\Type\Record\Record.h>

Type* additiveOperator(Type* lref, Type* rref);
Type* subtractiveOperator(Type* lref, Type* rref);
double AdditiveOperatorsToNumbers(double lnum, double rnum);
Type *assignment(Type *lref, Type *rref);

Type* GetValue(Type* V);
void PutValue(Type* V, Type* W);
Type* ToPrimative(Type* input, Type* preferredType = nullptr);

StringType* ToString(Type* V);
NumberType* ToNumber(Type* V);

void ReturnIfAbrupt(Type* V);
LexicalEnvironment* NewDeclarativeEnvironment(LexicalEnvironment* E);
Reference* ResolveBinding(string name, LexicalEnvironment * env);
Reference* GetIdentifierReference(LexicalEnvironment *lex, string name);