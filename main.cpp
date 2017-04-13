#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <typeinfo>
#include <Types/LanguageTypes.h>
#include <Utilities/operator.h>
//#include <parser.h>

//extern FILE *yyin;
using namespace std;

string getType(string type) {
	return type.substr(6);
}

void main(int argc, char *argv[]) {
//	fopen_s(&yyin, argv[1], "r");
//	yyparse();
	auto plslhs = new StringType("Hello");
	auto plsrhs = new BooleanType(false);
	auto plsResult = addition(plslhs, plsrhs);
	cout << "(" << getType(typeid(plslhs).name()) << ") " << plslhs->getValue() << "\t + \t(" << getType(typeid(plsrhs).name()) << ") " << plsrhs->getValue() << "\t = \t(" << plsResult->getType() << ") " << plsResult->dump() << endl;
	
	auto sublhs = new NumberType(50);
	auto subrhs = new BooleanType(false);
	auto subResult = subtraction(sublhs, subrhs);
	cout << "(" << getType(typeid(sublhs).name()) << ") " << sublhs->getValue() << "\t - \t(" << getType(typeid(subrhs).name()) << ") " << subrhs->getValue() << "\t = \t(" << subResult->getType() << ") " << subResult->dump() << endl;

	auto mullhs = new StringType("30");
	auto mulrhs = new NumberType(20);
	auto mulResult = multiplication(mullhs, mulrhs);
	cout << "(" << getType(typeid(mullhs).name()) << ") " << mullhs->getValue() << "\t * \t(" << getType(typeid(mulrhs).name()) << ") " << mulrhs->getValue() << "\t = \t(" << mulResult->getType() << ") " << mulResult->dump() << endl;

	auto divlhs = new BooleanType(true);
	auto divrhs = new StringType("1000");
	auto divResult = division(divlhs, divrhs);
	cout << "(" << getType(typeid(divlhs).name()) << ") " << divlhs->getValue() << "\t / \t(" << getType(typeid(divrhs).name()) << ") " << divrhs->getValue() << "\t = \t(" << divResult->getType() << ") " << divResult->dump() << endl;
	
	auto modlhs = new StringType("20");
	auto modrhs = new NumberType(5);
	auto modResult = modulus(modlhs, modrhs);
	cout << "(" << getType(typeid(modlhs).name()) << ") " << modlhs->getValue() << "\t % \t(" << getType(typeid(modrhs).name()) << ") " << modrhs->getValue() << "\t = \t(" << modResult->getType() << ") " << modResult->dump() << endl;
	
}
