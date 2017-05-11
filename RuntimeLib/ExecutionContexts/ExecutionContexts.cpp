#include <RuntimeLib/ExecutionContexts/ExecutionContexts.h>
#include <RuntimeLib/Types/SpecificationTypes/LexicalEnvironment/LexicalEnvironmentFunc.h>

Reference *ResolveBinding(StringType *name, LexicalEnvironment *env) {
	if (env == nullptr) {
		puts("Set env to the running execution context's LexicalEnvironment.");
		exit(0);
	}
	return GetIdentifierReference(env, name, new BooleanType(false));
}
