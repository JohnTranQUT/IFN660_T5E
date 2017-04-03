%{
	#include <cstdio>
	int yylex();
	void yyerror(char*);

	Script* root;
%}

%code top {
	#include <ast.h>
}

%union {
	char* regex;
	char* str;
	double decimal;
	bool booelan;
	char* ident;
}

%token COMMENT NULL_L
%token <regex> REGEX_LITERAL
%token <str> STRING_L
%token <decimal> DECIMAL
%token <bool> BooleanLiteral
%token <ident> IDENT

%token BREAK DO IN TYPEOF CASE ELSE INSTANCEOF VAR CATCH EXPORT NEW VOID CLASS EXTENDS RETURN WHILE CONST FINALLY SUPER WITH CONTINUE FOR SWITCH YIELD DEBUGGER FUNCTION THIS DEFAULT IF THROW DELETE IMPORT TRY AWAIT ENUM TDOT LE GE EQ DIFF EQTYPE DFTYPE INCREASE DECREASE LSHIFT RSHIFT URSHIFT LOGAND LOOR ADDASS SUBASS MULASS REMASS LSHIFTASS RSHIFTASS URSHIFTASS BWANDASS BWORASS BWXORASS ARROWF EXP EXPASS DIVASS LINE_TERM

%start Script

%%

Script
	: ScriptBody_opt
	;

ScriptBody_opt
	: ScriptBody
	| empty
	;

ScriptBody
	: StatementList
	;

StatementList
	: StatementListItem
	| StatementList StatementListItem
	;

StatementListItem
	: Statement
	| Declaration
	;

/* Level 1 */

Statement
	: BlockStatement
	| VariableStatement
	| EmptyStatement
	| ExpressionStatement
	| IfStatement
	| BreakableStatement
	| ContinueStatement
	| BreakStatement
	| ReturnStatement
	| WithStatement
	| LabelledStatement
	| ThrowStatement
	| TryStatement
	| DebuggerStatement
	;

Declaration
	:
	;

/* Level 2 */

BlockStatement
	:
	;

VariableStatement
	:
	;

EmptyStatement
	:
	;

ExpressionStatement
	: Expression ';'
	;

IfStatement
	:
	;

BreakableStatement
	:
	;

ContinueStatement
	:
	;

BreakStatement
	:
	;

ReturnStatement
	:
	;

WithStatement
	:
	;

LabelledStatement
	:
	;

ThrowStatement
	:
	;

TryStatement
	:
	;

DebuggerStatement
	:
	;

/* Level 3 */

Expression
	: AssignmentExpression
	| Expression ',' AssignmentExpression
	;

/* Level 4 */
AssignmentExpression
	: ConditionalExpression
	| YieldExpression
	| ArrowFunction
	| LeftHandSideExpression '=' AssignmentExpression
	| LeftHandSideExpression AssignmentOperator AssignmentExpression
	;

/* Level 5 */
ConditionalExpression
	: LogicalORExpression
	| LogicalORExpression '?' AssignmentExpression ':' AssignmentExpression
	;

YieldExpression
	:
	;

ArrowFunction
	:
	;

LeftHandSideExpression
	: NewExpression
	| CallExpression
	;

/* Level 6 */
NewExpression
	: MemberExpression
	| NEW NewExpression
	;

CallExpression
	:
	;

LogicalORExpression
	: LogicalANDExpression
	| LogicalORExpression LOOR LogicalANDExpression
	;

/* Level 7 */
MemberExpression
	: PrimaryExpression
	| MemberExpression '[' Expression ']'
	| MemberExpression '.' IdentifierName
	| MemberExpression TemplateLiteral
	| SuperProperty
	| MetaProperty
	| NEW MemberExpression Arguments
	;

LogicalANDExpression
	: BitwiseORExpression
	| LogicalANDExpression LOGAND BitwiseORExpression
	;

/* Level 8 */
PrimaryExpression
	: THIS
	| IdentifierReference
	| Literal
	| ArrayLiteral
	| ObjectLiteral
	| FunctionExpression
	| ClassExpression
	| GeneratorExpression
	| RegularExpressionLiteral
	| TemplateLiteral
	| CoverParenthesizedExpressionAndArrowParameterList
	;

MemberExpression
	:
	;

SuperProperty
	:
	;

MetaProperty
	:
	;

Arguments
	:
	;

BitwiseORExpression
	: BitwiseXORExpression
	| BitwiseORExpression '|' BitwiseXORExpression
	;

/* Level 9 */
IdentifierReference
	: Identifier
	| YIELD
	;

Literal
	: NullLiteral
	| BooleanLiteral
	| NumericLiteral
	| StringLiteral
	;

ArrayLiteral
	:
	;

ObjectLiteral
	:
	;

FunctionExpression
	:
	;

ClassExpression
	:
	;

GeneratorExpression
	:
	;

CoverParenthesizedExpressionAndArrowParameterList
	:
	;

BitwiseXORExpression
	: BitwiseANDExpression
	| BitwiseXORExpression '^' BitwiseANDExpression
	;

/* Level 10 */
Identifier
	: IdentifierName
	;

BitwiseANDExpression
	: EqualityExpression
	| BitwiseANDExpression '&' EqualityExpression
	;

NumericLiteral
	: DecimalLiteral
	| BinaryIntegerLiteral
	| OctalIntegerLiteral
	| HexIntegerLiteral
	;

/* Level 11 */
EqualityExpression
	: RelationalExpression
	| EqualityExpression EQ RelationalExpression
	| EqualityExpression DIFF RelationalExpression
	| EqualityExpression EQTYPE RelationalExpression
	| EqualityExpression DFTYPE RelationalExpression
	;

/* Level 12 */
RelationalExpression
	: ShiftExpression
	| RelationalExpression '<' ShiftExpression
	| RelationalExpression '>' ShiftExpression
	| RelationalExpression LE ShiftExpression
	| RelationalExpression GE ShiftExpression
	| RelationalExpression INSTANCEOF ShiftExpression
	| RelationalExpression IN ShiftExpression
	;

/* Level 13 */
ShiftExpression
	: AdditiveExpression
	| ShiftExpression LSHIFT AdditiveExpression
	| ShiftExpression RSHIFT AdditiveExpression
	| ShiftExpression URSHIFT AdditiveExpression
	;

/* Level 14 */
AdditiveExpression
	: MultiplicativeExpression
	| AdditiveExpression '+' MultiplicativeExpression
	| AdditiveExpression '-' MultiplicativeExpression
	;

/* Level 15 */
MultiplicativeExpression
	: ExponentiationExpression
	| MultiplicativeExpression MultiplicativeOperator ExponentiationExpression
	;

/* Level 16 */
ExponentiationExpression
	: UnaryExpression
	| UpdateExpression EXP ExponentiationExpression
	;

/* Level 17 */
UnaryExpression
	: UpdateExpression
	| DELETE UnaryExpression
	| VOID UnaryExpression
	| TYPEOF UnaryExpression
	| '+' UnaryExpression
	| '-' UnaryExpression
	| '~' UnaryExpression
	| '!' UnaryExpression
	;

UpdateExpression
	: LeftHandSideExpression
	| LeftHandSideExpression INCREASE
	| LeftHandSideExpression DECREASE
	| INCREASE UnaryExpression
	| DECREASE UnaryExpression
	;

/* END */
IdentifierName
	: IDENT
	;

TemplateLiteral
	:
	;

RegularExpressionLiteral
	:
	;

NullLiteral
	:
	;

StringLiteral
	:
	;

DecimalLiteral
	: DECIMAL
	;

BinaryIntegerLiteral
	:
	;

OctalIntegerLiteral
	:
	;

HexIntegerLiteral
	:
	;

/* Utility */

AssignmentOperator
	: ADDASS
	| SUBASS
	| MULASS
	| REMASS
	| DIVASS
	| LSHIFTASS
	| RSHIFTASS
	| URSHIFTASS
	| BWANDASS
	| BWXORASS
	| BWORASS
	| EXPASS
	;

MultiplicativeOperator
	: '*'
	| '/'
	| '%'
	;

empty
	:
	;

%%
