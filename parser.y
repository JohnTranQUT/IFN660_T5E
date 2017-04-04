%code requires {
	#include <cstdio>
	#include "AstNode.h"
	#include "AstExpression.h"
	#include "AstStatement.h"
	#include "AstScript.h"
	int yylex();
	void yyerror(char *);
}

%union {
	char *regex;
	char * str;
	double decimal;
	char *binary;
	char *octal;
	char *hex;
	bool booelan;
	char *ident;

	Node *root;
	StatementList *statementlist;
	Statement *statement;
	Expression *expression;
}

%token COMMENT NULL_L
%token <regex> REGEX_LITERAL
%token <str> STRING_L
%token <decimal> DECIMAL_L
%token <binary> BINARY_L
%token <octal> OCTAL_L
%token <hex> HEX_L
%token <bool> BooleanLiteral
%token <ident> IDENT

%token BREAK DO IN TYPEOF CASE ELSE INSTANCEOF VAR CATCH EXPORT NEW VOID CLASS EXTENDS RETURN WHILE CONST FINALLY SUPER WITH CONTINUE FOR SWITCH YIELD DEBUGGER FUNCTION THIS DEFAULT IF THROW DELETE IMPORT TRY AWAIT ENUM TDOT LE GE EQ DIFF EQTYPE DFTYPE INCREASE DECREASE LSHIFT RSHIFT URSHIFT LOGAND LOOR ADDASS SUBASS MULASS REMASS LSHIFTASS RSHIFTASS URSHIFTASS BWANDASS BWORASS BWXORASS ARROWF EXP EXPASS DIVASS LINE_TERM

%type <statementlist> StatementList
%type <root> Script ScriptBody_opt ScriptBody StatementListItem
%type <statement> Statement ExpressionStatement
%type <expression> Expression AssignmentExpression ConditionalExpression LogicalORExpression LogicalANDExpression BitwiseORExpression BitwiseXORExpression BitwiseANDExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression ExponentiationExpression UnaryExpression UpdateExpression LeftHandSideExpression NewExpression MemberExpression PrimaryExpression 
%type <expression> IdentifierReference Literal NumericLiteral Identifier DecimalLiteral IdentifierName

%start Script

%%

Script
	: ScriptBody_opt															{ $$ = new Script($1); $$->dump(); }
	;

ScriptBody_opt
	: ScriptBody																{ $$ = new ScriptBody_opt($1); }
	| empty
	;

ScriptBody
	: StatementList																{ $$ = new ScriptBody($1); }
	;

StatementList
	: StatementListItem															{ $$ = new StatementList($1); }
	| StatementList StatementListItem											{ $$ = new StatementList($1, $2); }
	;

StatementListItem
	: Statement																	{ $$ = new StatementListItem($1); }
	| Declaration
	;

/* Level 1 */

Statement
	: BlockStatement
	| VariableStatement
	| EmptyStatement
	| ExpressionStatement														{ $$ = $1; }
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
	: Expression ';'															{ $$ = new ExpressionStatement($1); }
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
	: AssignmentExpression														{ $$ = $1; }
	| Expression ',' AssignmentExpression
	;

/* Level 4 */
AssignmentExpression
	: ConditionalExpression														{ $$ = new AssignmentExpression($1); }
	| YieldExpression
	| ArrowFunction
	| LeftHandSideExpression '=' AssignmentExpression							{ $$ = new AssignmentExpression($1, $3); }
	| LeftHandSideExpression AssignmentOperator AssignmentExpression
	;

/* Level 5 */
ConditionalExpression
	: LogicalORExpression														{ $$ = new ConditionalExpression($1); }
	| LogicalORExpression '?' AssignmentExpression ':' AssignmentExpression
	;

YieldExpression
	:
	;

ArrowFunction
	:
	;

LeftHandSideExpression
	: NewExpression																{ $$ = new LeftHandSideExpression($1); }
	| CallExpression
	;

/* Level 6 */
NewExpression
	: MemberExpression															{ $$ = new NewExpression($1); }
	| NEW NewExpression
	;

CallExpression
	:
	;

LogicalORExpression
	: LogicalANDExpression														{ $$ = new LogicalORExpression($1); }
	| LogicalORExpression LOOR LogicalANDExpression
	;

/* Level 7 */
MemberExpression
	: PrimaryExpression															{ $$ = new MemberExpression($1); }
	| MemberExpression '[' Expression ']'
	| MemberExpression '.' IdentifierName
	| MemberExpression TemplateLiteral
	| SuperProperty
	| MetaProperty
	| NEW MemberExpression Arguments
	;

LogicalANDExpression
	: BitwiseORExpression														{ $$ = new LogicalANDExpression($1); }
	| LogicalANDExpression LOGAND BitwiseORExpression
	;

/* Level 8 */
PrimaryExpression
	: THIS
	| IdentifierReference														{ $$ = new PrimaryExpression($1); }
	| Literal																	{ $$ = new PrimaryExpression($1); }
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
	: BitwiseXORExpression														{ $$ = new BitwiseORExpression($1); }
	| BitwiseORExpression '|' BitwiseXORExpression
	;

/* Level 9 */
IdentifierReference
	: Identifier																{ $$ = new IdentifierReference($1); }
	| YIELD
	;

Literal
	: NullLiteral
	| BooleanLiteral
	| NumericLiteral															{ $$ = new Literal($1); }
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
	: BitwiseANDExpression														{ $$ = new BitwiseXORExpression($1); }
	| BitwiseXORExpression '^' BitwiseANDExpression
	;

/* Level 10 */
Identifier
	: IdentifierName															{ $$ = new Identifier($1); }
	;

BitwiseANDExpression
	: EqualityExpression														{ $$ = new BitwiseANDExpression($1); }
	| BitwiseANDExpression '&' EqualityExpression
	;

NumericLiteral
	: DecimalLiteral															{ $$ = new NumericLiteral($1); }
	| BinaryIntegerLiteral
	| OctalIntegerLiteral
	| HexIntegerLiteral
	;

/* Level 11 */
EqualityExpression
	: RelationalExpression														{ $$ = new EqualityExpression($1); }
	| EqualityExpression EQ RelationalExpression
	| EqualityExpression DIFF RelationalExpression
	| EqualityExpression EQTYPE RelationalExpression
	| EqualityExpression DFTYPE RelationalExpression
	;

/* Level 12 */
RelationalExpression
	: ShiftExpression															{ $$ = new RelationalExpression($1); }
	| RelationalExpression '<' ShiftExpression
	| RelationalExpression '>' ShiftExpression
	| RelationalExpression LE ShiftExpression
	| RelationalExpression GE ShiftExpression
	| RelationalExpression INSTANCEOF ShiftExpression
	| RelationalExpression IN ShiftExpression
	;

/* Level 13 */
ShiftExpression
	: AdditiveExpression														{ $$ = new ShiftExpression($1); }
	| ShiftExpression LSHIFT AdditiveExpression
	| ShiftExpression RSHIFT AdditiveExpression
	| ShiftExpression URSHIFT AdditiveExpression
	;

/* Level 14 */
AdditiveExpression
	: MultiplicativeExpression													{ $$ = new AdditiveExpression($1); }
	| AdditiveExpression '+' MultiplicativeExpression
	| AdditiveExpression '-' MultiplicativeExpression
	;

/* Level 15 */
MultiplicativeExpression
	: ExponentiationExpression													{ $$ = new MultiplicativeExpression($1); }
	| MultiplicativeExpression MultiplicativeOperator ExponentiationExpression
	;

/* Level 16 */
ExponentiationExpression
	: UnaryExpression															{ $$ = new ExponentiationExpression($1); }
	| UpdateExpression EXP ExponentiationExpression
	;

/* Level 17 */
UnaryExpression
	: UpdateExpression															{ $$ = new UnaryExpression($1); }
	| DELETE UnaryExpression
	| VOID UnaryExpression
	| TYPEOF UnaryExpression
	| '+' UnaryExpression
	| '-' UnaryExpression
	| '~' UnaryExpression
	| '!' UnaryExpression
	;

UpdateExpression
	: LeftHandSideExpression													{ $$ = new UpdateExpression($1); }
	| LeftHandSideExpression INCREASE
	| LeftHandSideExpression DECREASE
	| INCREASE UnaryExpression
	| DECREASE UnaryExpression
	;

/* END */
IdentifierName
	: IDENT																		{ $$ = new IdentifierName($1); }
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
	: DECIMAL_L																	{ $$ = new DecimalLiteral($1); }
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
