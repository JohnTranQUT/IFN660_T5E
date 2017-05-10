#include <RuntimeLib\Expressions\AssignmentOperators.h>

LanguageType* Evaluation(Type* lref, LanguageType* rref) {
	if(true){ // if not lref is ObjectLiteral or ArrayLiteral //THIS INCLUDES REFERENCES
		ReturnIfAbrupt(lref);
		auto rval = GetValue(rref);
		if (IsAnonymousFunctionDefinition()) {
			bool hasNameProperty = HasOwnProperty(rval, "name");
			if (!hasNameProperty) {
				//SetFunctionName(rval, GetReferenceName(lref));
			}
		}
		PutValue(lref, rval);
		return rval;
	}
	auto assignmentPattern = lref;
	auto rval = GetValue(rref);
	//auto status = assignmentPattern;
	//ReturnIfAbrupt(status);
	return rval;
}

bool IsAnonymousFunctionDefinition() {
	return false;
}

bool HasOwnProperty(LanguageType* O, string P) {
	return false;
}