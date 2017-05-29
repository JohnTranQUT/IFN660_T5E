#include <RuntimeLib\Expressions\AssignmentOperators.h>

LanguageType* Assignment(Type* lref, Type* rref) {
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
	//Bottom part is skipped for most our stuff
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