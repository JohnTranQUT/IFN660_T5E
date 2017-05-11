#include <RuntimeLib/Types/SpecificationTypes/Record/EnvironmentRecord/GlobalEnvironmentRecord/GlobalEnvironmentRecord.h>

GlobalEnvironmentRecord::GlobalEnvironmentRecord(ObjectEnvironmentRecord *ObjectRecord, ObjectType *GlobalThisValue, DeclarativeEnvironmentRecord *DeclarativeRecord, List *VarNames) {
	_insertValue(new StringType("ObjectRecord"), ObjectRecord);
	_insertValue(new StringType("GlobalThisValue"), GlobalThisValue);
	_insertValue(new StringType("DeclarativeRecord"), DeclarativeRecord);
	_insertValue(new StringType("VarNames"), VarNames);
}

BooleanType *GlobalEnvironmentRecord::HasBinding(StringType *N) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	if (DclRec->HasBinding(N)->_getValue()) {
		return new BooleanType(true);
	}
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	return ObjRec->HasBinding(N);
}

void GlobalEnvironmentRecord::CreateMutableBinding(StringType *N, BooleanType *D) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	if (DclRec->HasBinding(N)->_getValue()) {
		puts("TypeError");
		exit(0);
	}
	DclRec->CreateMutableBinding(N, D);
}

void GlobalEnvironmentRecord::CreateImmutableBinding(StringType *N, BooleanType *S) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	if (DclRec->HasBinding(N)->_getValue()) {
		puts("TypeError");
		exit(0);
	}
	DclRec->CreateImmutableBinding(N, S);
}

void GlobalEnvironmentRecord::InitializeBinding(StringType *N, LanguageType *V) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	if (DclRec->HasBinding(N)->_getValue()) {
		DclRec->InitializeBinding(N, V);
	} else {
		auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
		ObjRec->InitializeBinding(N, V);
	}
}

void GlobalEnvironmentRecord::SetMutableBinding(StringType *N, LanguageType *V, BooleanType *S) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	if (DclRec->HasBinding(N)->_getValue()) {
		DclRec->SetMutableBinding(N, V, S);
	} else {
		auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
		ObjRec->SetMutableBinding(N, V, S);
	}
}

Type *GlobalEnvironmentRecord::GetBindingValue(StringType *N, BooleanType *S) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	if (DclRec->HasBinding(N)->_getValue()) {
		return DclRec->GetBindingValue(N, S);
	}
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	return ObjRec->GetBindingValue(N, S);
}

BooleanType *GlobalEnvironmentRecord::DeleteBinding(StringType *N) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	if (DclRec->HasBinding(N)->_getValue()) {
		return DclRec->DeleteBinding(N);
	}
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	puts("GlobalEnvironmentRecord::DeleteBinding()");
	exit(0);
}

BooleanType *GlobalEnvironmentRecord::HasThisBinding() {
	return new BooleanType(true);
}

BooleanType *GlobalEnvironmentRecord::HasSuperBinding() {
	return new BooleanType(false);
}

Type *GlobalEnvironmentRecord::WithBaseObject() {
	return new UndefinedType();
}

ObjectType *GlobalEnvironmentRecord::GetThisBinding() {
	return dynamic_cast<ObjectType *>(_findValue(new StringType("GlobalThisValue")));
}

BooleanType *GlobalEnvironmentRecord::HasVarDeclaration(StringType *N) {
	auto varDeclaredNames = dynamic_cast<List *>(_findValue(new StringType("VarNames")));
	return varDeclaredNames->_contain(N);
}

BooleanType *GlobalEnvironmentRecord::HasLexicalDeclaration(StringType *N) {
	auto DclRec = dynamic_cast<DeclarativeEnvironmentRecord *>(_findValue(new StringType("DeclarativeRecord")));
	return DclRec->HasBinding(N);
}

BooleanType *GlobalEnvironmentRecord::HasRestrictedGlobalProperty(StringType *N) {
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	puts("GlobalEnvironmentRecord::HasRestrictedGlobalProperty()");
	exit(0);
}

BooleanType *GlobalEnvironmentRecord::CanDeclareGlobalVar(StringType *N) {
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	puts("GlobalEnvironmentRecord::CanDeclareGlobalVar()");
	exit(0);
}

BooleanType *GlobalEnvironmentRecord::CanDeclareGlobalFunction(StringType *N) {
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	puts("GlobalEnvironmentRecord::CanDeclareGlobalFunction()");
	exit(0);
}

CompletionRecord *GlobalEnvironmentRecord::CreateGlobalVarBinding(StringType *N, BooleanType *D) {
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	puts("GlobalEnvironmentRecord::CreateGlobalVarBinding()");
	exit(0);
}

CompletionRecord *GlobalEnvironmentRecord::CreateGlobalFunctionBinding(StringType *N, LanguageType *V, BooleanType *D) {
	auto ObjRec = dynamic_cast<ObjectEnvironmentRecord *>(_findValue(new StringType("ObjectRecord")));
	puts("GlobalEnvironmentRecord::CreateGlobalFunctionBinding()");
	exit(0);
}
