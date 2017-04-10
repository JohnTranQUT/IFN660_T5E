# IFN645-T5E Github Repository

## Current Status
Abstract Syntax Tree

## Project Logs
This list is inversed, meaning latest log at the top while oldest log at the bottom
- Implemented Full IfStatement, BlockStatement, and Block
- Implemented Full RelationalExpression and EqualityExpression
- Implemented Full StatementList to support multiple StatementListItem
- Implemented all formal rules needed for x = 42; to work
	- Node
	- Script
		- ScriptBody_opt
		- ScriptBody
		- StatementList
		- StatementListItem
	- Statement
		- ExpressionStatement
	- Expression
		- AssignmentExpression
		- ConditionalExpression
		- LogicalORExpression
		- LogicalANDExpression
		- BitwiseORExpression
		- BitwiseXORExpression
		- BitwiseANDExpression
		- EqualityExpression
		- RelationalExpression
		- ShiftExpression
		- AdditiveExpression
		- MultiplicativeExpression
		- ExponentiationExpression
		- UnaryExpression
		- UpdateExpression
		- LeftHandSideExpression
		- NewExpression
		- MemberExpression
		- PrimaryExpression
		- IdentifierReference
		- Identifier
		- IdentifierName
		- Literal
		- NumericLiteral
		- DecimalLiteral
- Fixed NumericLiteral incompleteness in scanner.l
- Seperated AST rules into four sections
	- AstNode
	- AstScript
	- AstStatement
	- AstExpression
- Implemented universal dump function
- Implemented basic rules
- Initialized basic rules in AST.h and AST.cpp
	- Node
	- Script
	- Statement
	- ExpressionStatement
	- Expression
	- AssignmentExpression
	- Identifier
	- DecimalLiteral
- Initialized AST.h and AST.cpp
- Initialized main.cpp for AST testing
