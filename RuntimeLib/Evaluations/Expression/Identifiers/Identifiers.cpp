#include <RuntimeLib/Evaluations/Expression/Identifiers/Identifiers.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/GlobalEnvironmentRecord/GlobalEnvironmentRecord.h>
#include <RuntimeLib/ExecutionContexts/ExecutionContexts.h>
#include <RuntimeLib/Types/SpecificationTypes/ReferenceType/ReferenceTypeFunc.h>

CompletionType *InitializeBoundName(StringType *name, LanguageType *value, EnvironmentRecord *environment) {
	if (environment != nullptr) {
		if (auto _env = dynamic_cast<DeclarativeEnvironmentRecord *>(environment)) {
			_env->InitializeBinding(name, value);
			return NormalCompletion(new UndefinedType());
		} else if (auto _env = dynamic_cast<ObjectEnvironmentRecord *>(environment)) {
			_env->InitializeBinding(name, value);
			return NormalCompletion(new UndefinedType());
		} else if (auto _env = dynamic_cast<GlobalEnvironmentRecord *>(environment)) {
			_env->InitializeBinding(name, value);
			return NormalCompletion(new UndefinedType());
		}
		puts("EnvironmentRecord");
		exit(0);
	}
	auto lhs = ResolveBinding(name);
	PutValue(lhs, value);
	return nullptr;
}
