# IFN645-T5E Github Repository

## Current Status
Code Generation

## Project Logs
- Implemented virtual method `AstNode::genCode()` for code generation
- Implemented `Reference` -> `InitializeReferencedBinding()`
- Tests for `LexicalEnvironment` and `EnvironmentRecord` are now available
- Implemented `_listItemsInRecord()` under _Helpers/
- Implemented `InitializeBoundName()` under Evaluations/Expression/Identifiers/ and `ResolveBinding()` under ExecutionContexts/ 
- Operators now accept `Type` instead of `LanguageType`
- Implemented JS Defined `AdditiveOperators`, `MultiplicativeOperators` instead of using C++ native operators **(hint from Michael)**
- Utilities is now called _Helpers
- Destructured `operators` to be under Evaluations/Expression/ as AdditiveOperators and MultiplicativeOperators
- Implemented `Reference` -> `PutValue()`
- Changed Data Types of attributes of `Reference` to `LanguageType`
- Reformed `CompletionRecord` to support `Record`
- Reformed `Record`
- Replaced comments with C++ `#define` Directive to switch between AST and ARITH **(hint from Jason)**
- Added `_TrimDecimal()` to remove trailing zeros and unnecessary decimal when converting `double` to `string`
- Implemented `Reference` -> `GetThisValue()` and improved `Reference` -> `GetValue()`
- Added `Object()`, `Boolean()`, `Number()`, and `String()` as corresponding object constructor
- Fixed `ObjectObject::prototype::valueOf()`; `ToPrimitive()` and `OrdinaryToPrimitive()` are now working properly
- `ObjectObject` is no longer the base class of `BooleanObject`, `NumberObject`, and `StringObject`
- `ObjectObject::prototype::valueOf()` now returns and instantiates `ObjectObject` with blank `ObjectType` (`[object Object]`) instead of pure `ObjectType` (unknown)
- Replaced `ObjectObject::prototype::valueOf()` with dummy (always return blank `ObjectType` instead of `ToObject(value)`) due to limitation in C++
- Implemented Full `OrdinaryToPrimitive()`
- `ToPrimitive()` now supports `ObjectType`
- `ToObject()` now supports `BooleanType`, `StringType` and `NumberType`
- Implemented corresponding `toString()` and `valueOf()` in every `[ObjectType]::prototype`
- Initialized `ObjectObject`, `BooleanObject`, `NumberObject`, `StringObject`
- Type Convertion now returns `LanguageType` instead of Data Types in C++
- `GetValue()` is now under `ReferenceFunc` instead of `SpecificationTypeFunc`
- Implemented `Reference` and `CompletionRecord`
- `GetValue()` now supports `CompletionRecord`
- Initialized `ObjectType::Properties`: `Property` -> `DataProperty` and `Property` -> `AccessorProperty`
- Recode `GetValue()` to support `Reference`
- Restructure Codes
- Created tests in main.cpp
- Implemented `LanguageType` -> `subtraction()`, `multiplication()`, `division()`, `modulus()`
- Implemented `LanguageType` -> `ToBoolean()`, `ToInteger()`, `ToObject()`
- Implemented `LanguageType` -> `addition()`
- Implemented `LanguageType` -> `ToPrimitive()`, `ToNumber()`, `ToString()`
- Implemented `SpecificationType` -> `GetValue()`