%{
#include <parser.h>
#include <cstdio>

int lines = 0;

using namespace std;
%}

digit [0-9]
letter [a-zA-Z]

sourceChar [a-zA-Z0-9_ \n]

_regex_char [^/]|(\\\/)
_regex_flags [gimuy]

LineTerminator (\x0D\x0A)
LineCont (\\{LineTerminatorSeq})
LineTerminatorSeq (\x0A\x0D|\x0D[^\x0A]|\x0A)
EscSeq ({CharEscSeq}|0[^0-9]|{HexEscSeq}|{UnicodeEscSeq})
CharEscSeq ([{SingleEscChar}]|{NonEscChar})
SingleEscChar ['"\\bfnrtv]
NonEscChar ([^{EscChar}{LineTerminator}])
EscChar ({SingleEscChar}|[0-9]|x|u)
HexEscSeq (x[0-9A-Fa-f]{2})
UnicodeEscSeq (u([0-9A-Fa-f]{4})|u\{[0-9A-Fa-f][0-9A-Fa-f]*\})
DoubleStrChar ([^"\\\x0D\x0A]|\\{EscSeq}|{LineCont})
SingleStrChar ([^'\\\x0D\x0A]|\\{EscSeq}|{LineCont})

whitespace [\x09\x0B\x0C\x20\xC2A0\xEFBBBF]

/* Numeric Literal Definitions*/
DecimalDigit [0-9]
NonZeroDigit [1-9]
DecimalDigits {DecimalDigit}+
DecimalDigitsopt {DecimalDigits}?				
SignedInteger {DecimalDigits}|("+"{DecimalDigits})|("-"{DecimalDigits})		
ExponentIndicator [eE]
ExponentPart {ExponentIndicator}{SignedInteger}
ExponentPartopt {ExponentPart}?
DecimalIntegerLiteral ([0]|({NonZeroDigit}{DecimalDigitsopt}))
DecimalLiteral	({DecimalIntegerLiteral}"."{DecimalDigitsopt}{ExponentPartopt})|("."{DecimalDigits}{ExponentPartopt})|({DecimalIntegerLiteral}{ExponentPartopt})
BinaryDigit [01]
BinaryDigits {BinaryDigit}+
BinaryIntegerLiteral 0[bB]{BinaryDigits}
OctalDigit [0-7]
OctalDigits {OctalDigit}+
OctalIntegerLiteral 0[oO]{OctalDigits}
HexDigit [0-9a-fA-F]
HexDigits {HexDigit}+
HexIntegerLiteral 0[xX]{HexDigits}
/* Comments Definitions */
MultiLineNotForwardSlashOrAsteriskChar [^"/"^"*"]
PostAsteriskCommentChars ({MultiLineNotForwardSlashOrAsteriskChar})
MultiLineNotAsteriskChar [^"*"]
MultiLineCommentChars (({MultiLineNotAsteriskChar})*|("*"{PostAsteriskCommentChars})*)+
MultiLineCommentCharsopt {MultiLineCommentChars}?
MultiLineComment "/""*"{MultiLineCommentCharsopt}"*""/"
SingleLineCommentChars [^\x0A^\x0D^\xE280AC^\xE280A9]+
SingleLineCommentCharsopt {SingleLineCommentChars}?
SingleLineComment "/""/"{SingleLineCommentCharsopt}

%x template_head
%x template_start
%x template_component

%%


{MultiLineComment}|{SingleLineComment}		{  return COMMENT;}

[\/]{_regex_char}+[\/]{_regex_flags}*	{	// Regex Literal
											return REGEX_LITERAL;
										}

null						{ return NULL_L; }

(\"{DoubleStrChar}*\")		{
								return STRING_L;
							}
(\'{SingleStrChar}*\')		{
								return STRING_L;
							}

{DecimalLiteral}			{
								yylval.decimal = atof(yytext);
								return DECIMAL_L;
							}

{BinaryIntegerLiteral}		{
								return BINARY_L;
							}

{OctalIntegerLiteral}		{
								return OCTAL_L;
							}

{HexIntegerLiteral}			{
								return HEX_L;
							}

true|false			    {
							return BooleanLiteral;
						}

break						{ return BREAK; }
do							{ return DO; }
in							{ return IN; }
typeof						{ return TYPEOF; }
case						{ return CASE; }
else						{ return ELSE; }
instanceof					{ return INSTANCEOF; }
var							{ return VAR; }
catch						{ return CATCH; }
export						{ return EXPORT; }
new							{ return NEW; }
void						{ return VOID; }
class						{ return CLASS; }
extends						{ return EXTENDS; }
return						{ return RETURN; }
while						{ return WHILE; }
const						{ return CONST; }
finally						{ return FINALLY; }
super						{ return SUPER; }
with						{ return WITH; }
continue					{ return CONTINUE; }
for							{ return FOR; }
switch						{ return SWITCH; }
yield						{ return YIELD; }
debugger					{ return DEBUGGER; }
function					{ return FUNCTION; }
this						{ return THIS; }
default						{ return DEFAULT; }
if							{ return IF; }
throw						{ return THROW; }
delete						{ return DELETE; }
import						{ return IMPORT; }
try							{ return TRY; }
await						{ return AWAIT; }
enum						{ return ENUM; }
"{"							{ return '{'; }
"}"							{ return '}'; }
"("							{ return '('; }
")"							{ return ')'; }
"["							{ return '['; }
"]"							{ return ']'; }
"."							{ return '.'; }
"..."						{ return TDOT; }
";"							{ return ';'; }
","							{ return ','; }
"<"							{ return '<'; }
">"							{ return '>'; }
"<="						{ return LE; }
">="						{ return GE; }
"=="						{ return EQ; }
"!="						{ return DIFF; }
"==="						{ return EQTYPE; }
"!=="						{ return DFTYPE; }
"+"							{ return '+'; }
"-"							{ return '-'; }
"*"							{ return '*'; }
"%"							{ return '%'; }
"++"						{ return INCREASE; }
"--"						{ return DECREASE; }
"<<"						{ return LSHIFT; }
">>"						{ return RSHIFT; }
">>>"						{ return URSHIFT; }
"&"							{ return '&'; }
"|"							{ return '|'; }
"^"							{ return '^'; }
"!"							{ return '!'; }
"~"							{ return '~'; }
"&&"						{ return LOGAND; }
"||"						{ return LOOR; }
"?"							{ return '?'; }
":"							{ return ':'; }
"="							{ return '='; }
"+="						{ return ADDASS; }
"-="						{ return SUBASS; }
"*="						{ return MULASS; }
"%="						{ return REMASS; }
"<<="						{ return LSHIFTASS; }
">>="						{ return RSHIFTASS; }
">>>="						{ return URSHIFTASS; }
"&="						{ return BWANDASS; }
"|="						{ return BWORASS; }
"^="						{ return BWXORASS; }
"=>"						{ return ARROWF; }
"**"						{ return EXP; }
"**="						{ return EXPASS; }
"/"							{ return '/'; }
"/="						{ return DIVASS; }

([a-zA-Z]|[$_]|(\u[{]?[0-9a-fA-F]{4}[}]?))([0-9]|[a-zA-Z]|[$_]|(\u[{]?[0-9a-fA-F]{4}[}]?))* { yylval.ident = _strdup(yytext); return IDENT; }

{LineTerminator}			{ return LINE_TERM; }

[ \r\n\t]                   /* skip whitespace */

.                           {
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                            }
%%


int yywrap() {
	return 1;
}

void yyerror(char* message) {
	fprintf(stderr, "Error: line %d, %s\n", lines, message);
}
