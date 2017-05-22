#include "RuntimeLib/Evaluations/Expression/Identifiers/Identifiers.h"
#include "RuntimeLib/ExecutionContexts/ExecutionContexts.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/CompletionRecord/CompletionRecordFunc.h"
#include "RuntimeLib/Types/SpecificationTypes/Reference/ReferenceFunc.h"

CompletionRecord *InitializeBoundName(StringType *name, LanguageType *value, EnvironmentRecord *environment) {
	if (environment != nullptr) {
		environment->InitializeBinding(name, value);
		return NormalCompletion(new UndefinedType());
	}
	auto lhs = ResolveBinding(name);
	PutValue(lhs, value);
	return nullptr;
}
