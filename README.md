# IFN645-T5E Github Repository

## Current Status
Semantic Analysis - Function-Oriented (Alfred)

## Project Logs
- Tests for `LexicalEnvironment` and `EnvironmentRecord` are now available
- Implemented `_listItemsInRecord()` under _Helpers/
- Implemented `InitializeBoundName()` under Expression/Identifiers/ and `ResolveBinding()` under ExecutionContexts/ 
- Data Type of Record::value is now `map<string, Type *>` instead of `map<StringType *, Type *>`
- `GetIdentifierReference()`, `GetValue()`, and `PutValue()` now find the exact `EnvironmentRecord`
- Operators now accept Types instead of LanguageTypes
- Implemented JS Defined `AdditiveOperators`, `MultiplicativeOperators` instead of using C++ native operators **(hint from Michael)**
- Utilities are now called _Helpers
- Destructured `operators` to be under Evaluations/Expression/ as AdditiveOperators and MultiplicativeOperators
- Implemented `PutValue()` under `ReferenceType` 
- Changed Data Types of attributes of `ReferenceType` to LanguageTypes
- Reformed `CompletionType` to support `RecordType`
- Reformed `RecordType`
- Replaced comments with C++ `#define` Directive to switch between AST and SA **(hint from Jason)**
- Added `_TrimDecimal()` to remove trailing zeros and unnecessary decimal when converting double to string
- Implemented `ReferenceType` -> `GetThisValue()` and improved `ReferenceType` -> `GetValue()`
- Added `Object()`, `Boolean()`, `Number()`, and `String()` as corresponding object constructor
- Fixed `ObjectObject::prototype::valueOf()`. `ToPrimitive()` and `OrdinaryToPrimitive()` are now working properly
- `ObjectObject` is no longer the base class of `BooleanObject`, `NumberObject`, and `StringObject`
- `ObjectObject::prototype::valueOf()` now returns and instantiates `ObjectObject` with blank `ObjectType` (`[object Object]`) instead of pure `ObjectType` (unknown)
- Replaced `ObjectObject::prototype::valueOf()` with dummy (always return blank `ObjectType` instead of `ToObject(value)`) due to limitation in C++
- Implemented Full `OrdinaryToPrimitive()`
- `ToPrimitive()` now supports `ObjectType`
- `ToObject()` now supports `BooleanType`, `StringType` and `NumberType`
- Implemented corresponding `toString()` and `valueOf()` in every `ObjectType` prototype
- Initialized `ObjectObject`, `BooleanObject`, `NumberObject`, `StringObject`
- Type Convertion now returns LanguageTypes instead of Data Types in C++
- `GetValue()` is now under `ReferenceType` instead of SpecificationTypes
- Implemented `ReferenceType` and `CompletionType`
- `GetValue()` now supports `CompletionType`
- Initialized Object Keys and Properties
- Initialized Object Properties: Data Property and Accessor Property
- Recode `GetValue()` to support `ReferenceType`
- Restructure Codes
- Created tests in main.cpp
- Implemented LanguageTypes `subtraction()`, `multiplication()`, `division()`, `modulus()`
- Implemented LanguageTypes `ToBoolean()`, `ToInteger()`, `ToObject()`
- Implemented LanguageTypes `addition()`
- Implemented LanguageTypes `ToPrimitive()`, `ToNumber()`, `ToString()`
- Implemented SpecificationTypes `GetValue()`