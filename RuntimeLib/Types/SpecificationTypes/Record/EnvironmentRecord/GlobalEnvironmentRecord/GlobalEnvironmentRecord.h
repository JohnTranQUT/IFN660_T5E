#pragma once
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>
#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/List/List.h>

class GlobalEnvironmentRecord : public EnvironmentRecord {
public:
	GlobalEnvironmentRecord(
		ObjectEnvironmentRecord *,
		ObjectType *,
		DeclarativeEnvironmentRecord *,
		List * = new List()
	);
	BooleanType *HasBinding(StringType *);
	void CreateMutableBinding(StringType *, BooleanType *);
	void CreateImmutableBinding(StringType *, BooleanType *);
	void InitializeBinding(StringType *, LanguageType *);
	void SetMutableBinding(StringType *, LanguageType *, BooleanType *);
	Type *GetBindingValue(StringType *, BooleanType *);
	BooleanType *DeleteBinding(StringType *);
	static BooleanType *HasThisBinding();
	static BooleanType *HasSuperBinding();
	static Type *WithBaseObject();

	ObjectType *GetThisBinding();
	BooleanType *HasVarDeclaration(StringType *);
	BooleanType *HasLexicalDeclaration(StringType *);
	BooleanType *HasRestrictedGlobalProperty(StringType *);
	BooleanType *CanDeclareGlobalVar(StringType *);
	BooleanType *CanDeclareGlobalFunction(StringType *);
	CompletionRecord *CreateGlobalVarBinding(StringType *, BooleanType *);
	CompletionRecord *CreateGlobalFunctionBinding(StringType *, LanguageType *, BooleanType *);
};
