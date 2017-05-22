#pragma once
#include "RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h"
#include "RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h"
#include "RuntimeLib/Types/SpecificationTypes/List/List.h"

class GlobalEnvironmentRecord : public EnvironmentRecord {
public:
	GlobalEnvironmentRecord(
		ObjectEnvironmentRecord *,
		ObjectType *,
		DeclarativeEnvironmentRecord *,
		List * = new List()
	);
	BooleanType *HasBinding(StringType *) override;
	CompletionRecord *CreateMutableBinding(StringType *, BooleanType *) override;
	CompletionRecord *CreateImmutableBinding(StringType *, BooleanType *) override;
	CompletionRecord *InitializeBinding(StringType *, LanguageType *) override;
	CompletionRecord *SetMutableBinding(StringType *, LanguageType *, BooleanType *) override;
	Type *GetBindingValue(StringType *, BooleanType *) override;
	BooleanType *DeleteBinding(StringType *) override;
	BooleanType *HasThisBinding() override;
	BooleanType *HasSuperBinding() override;
	Type *WithBaseObject() override;

	ObjectType *GetThisBinding();
	BooleanType *HasVarDeclaration(StringType *);
	BooleanType *HasLexicalDeclaration(StringType *);
	BooleanType *HasRestrictedGlobalProperty(StringType *);
	BooleanType *CanDeclareGlobalVar(StringType *);
	BooleanType *CanDeclareGlobalFunction(StringType *);
	CompletionRecord *CreateGlobalVarBinding(StringType *, BooleanType *);
	CompletionRecord *CreateGlobalFunctionBinding(StringType *, LanguageType *, BooleanType *);
};
