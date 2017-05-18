#include <cstdio>
#include <RuntimeLib\Type\LanguageType\BooleanType\BooleanType.h>
#include <RuntimeLib\Type\LanguageType\NullType\NullType.h>
#include <RuntimeLib\Type\LanguageType\NumberType\NumberType.h>
#include <RuntimeLib\Type\LanguageType\ObjectType\ObjectType.h>
#include <RuntimeLib\Type\LanguageType\StringType\StringType.h>
#include <RuntimeLib\Type\LanguageType\SymbolType\SymbolType.h>
#include <RuntimeLib\Type\LanguageType\UndefinedType\UndefinedType.h>
#include <RuntimeLib\Expressions\ExecutionContexts.h>
#include <RuntimeLib\Expressions\AssignmentOperators.h>
#include <RuntimeLib\Type\SpecificationType\EnvironmentRecordType\EnvironmentRecordType.h>
#include <RuntimeLib\Type\SpecificationType\LexicalEnvironmentType\LexicalEnvironmentType.h>
#include <RuntimeLib\Expressions\AdditiveOperators.h>
#include <string>
#include <iostream>

//#include <parser.h>
//extern FILE *yyin;
using namespace std;

void main(int argc, char *argv[]) {
//	auto temp = additiveOperator(new StringType("version"), new NumberType(2));
//	auto _temp = dynamic_cast<StringType *>(temp);
//	puts(_temp->_getValue().c_str());
//	puts(_temp->_getType().c_str());
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
//	addition();
	auto LexEnv = NewDeclEnvi(nullptr); 
		LexEnv->getER()->CreateMutableBinding("x", false);
		LexEnv->getER()->CreateMutableBinding("y", false);
	auto xvalue = InitializeReferencedBinding(ResolveBinding("x", LexEnv), new StringType("20"));
	auto yvalue = InitializeReferencedBinding(ResolveBinding("y", LexEnv), new UndefinedType("")); 
	auto yright = AdditiveOperator(xvalue, new NumberType(17));
	auto y = AssignmentOperator(yvalue, yright);
	auto value = ToNumber(ToLanguage(y));
	cout << value << endl;
}
