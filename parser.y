%code requires {
	#include <cstdio>
	#include "AST/Node/AstNode.h"
	#include "AST/Expression/AstExpression.h"
	#include "AST/Statement/AstStatement.h"
	#include "AST/Script/AstScript.h"
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
%{
Node *root;
%}
%type <statementlist> StatementList StatementList_opt
%type <root> Script ScriptBody_opt ScriptBody StatementListItem
%type <statement> Statement BlockStatement Block ExpressionStatement IfStatement
%type <expression> Expression AssignmentExpression ConditionalExpression LogicalORExpression LogicalANDExpression BitwiseORExpression BitwiseXORExpression BitwiseANDExpression EqualityExpression RelationalExpression ShiftExpression AdditiveExpression MultiplicativeExpression ExponentiationExpression UnaryExpression UpdateExpression LeftHandSideExpression NewExpression MemberExpression PrimaryExpression 
%type <expression> IdentifierReference Literal NumericLiteral Identifier DecimalLiteral IdentifierName

%start Script

%%

Script
	: ScriptBody_opt															{ $$ = new Script($1); root = $$;}
	;

ScriptBody_opt
	: ScriptBody																{ $$ = $1 }
	| empty
	;

ScriptBody
	: StatementList																{ $$ = new ScriptBody($1); }
	;

StatementList_opt
	: StatementList																{ $$ = $1; }
	| empty
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
	| IfStatement																{ $$ = $1; }
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
	: Block																		{ $$ = new BlockStatement($1); }
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
	: IF '(' Expression ')' Statement ELSE Statement							{ $$ = new IfStatement($3, $5, $7); }
	| IF '(' Expression ')' Statement											{ $$ = new IfStatement($3, $5); }
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

Block
	: '{' StatementList_opt '}'													{ $$ = new Block($2); }
	;

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
	| EqualityExpression EQ RelationalExpression								{ $$ = new EqualityExpression($1, $3, "=="); }
	| EqualityExpression DIFF RelationalExpression								{ $$ = new EqualityExpression($1, $3, "!="); }
	| EqualityExpression EQTYPE RelationalExpression							{ $$ = new EqualityExpression($1, $3, "==="); }
	| EqualityExpression DFTYPE RelationalExpression							{ $$ = new EqualityExpression($1, $3, "!=="); }
	;

/* Level 12 */
RelationalExpression
	: ShiftExpression															{ $$ = new RelationalExpression($1); }
	| RelationalExpression '<' ShiftExpression									{ $$ = new RelationalExpression($1, $3, "<"); }
	| RelationalExpression '>' ShiftExpression									{ $$ = new RelationalExpression($1, $3, ">"); }
	| RelationalExpression LE ShiftExpression									{ $$ = new RelationalExpression($1, $3, "<="); }
	| RelationalExpression GE ShiftExpression									{ $$ = new RelationalExpression($1, $3, ">="); }
	| RelationalExpression INSTANCEOF ShiftExpression							{ $$ = new RelationalExpression($1, $3, "instanceof"); }
	| RelationalExpression IN ShiftExpression									{ $$ = new RelationalExpression($1, $3, "in"); }
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
	| AdditiveExpression '+' MultiplicativeExpression							{ $$ = new AdditiveExpression($1, $3, "+");}
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
