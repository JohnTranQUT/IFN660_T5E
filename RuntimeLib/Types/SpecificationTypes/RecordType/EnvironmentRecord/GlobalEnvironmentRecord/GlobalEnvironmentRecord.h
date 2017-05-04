#pragma once
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/EnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/ObjectEnvironmentRecord/ObjectEnvironmentRecord.h>
#include <RuntimeLib/Types/LanguageTypes/ObjectType/ObjectType.h>
#include <RuntimeLib/Types/SpecificationTypes/RecordType/EnvironmentRecord/DeclarativeEnvironmentRecord/DeclarativeEnvironmentRecord.h>
#include <RuntimeLib/Types/SpecificationTypes/ListType/ListType.h>

class GlobalEnvironmentRecord : public EnvironmentRecord {
public:
	GlobalEnvironmentRecord(
		ObjectEnvironmentRecord *,
		ObjectType *,
		DeclarativeEnvironmentRecord *,
		ListType * = new ListType()
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
	CompletionType *CreateGlobalVarBinding(StringType *, BooleanType *);
	CompletionType *CreateGlobalFunctionBinding(StringType *, LanguageType *, BooleanType *);
};
