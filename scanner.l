%{
#include <y.tab.h>
#include <string>
#include <cstdio>

using namespace std;
string templateLiteral;
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
SingleEscChar ('"\\bfnrtv)
NonEscChar ([^{EscChar}{LineTerminator}])
EscChar ({SingleEscChar}0-9xu)
HexEscSeq (x[0-9A-Fa-f]{2})
UnicodeEscSeq (u([0-9A-Fa-f]{4})|\{[0-9A-Fa-f][0-9A-Fa-f]*\})
DoubleStrChar ([^"\\\x0D\x0A]|\\{EscSeq}|{LineCont})
SingleStrChar ([^'\\\x0D\x0A]|\\{EscSeq}|{LineCont})

nonZeroDigit [1-9]
whitespace [\x09\x0B\x0C\x20\xC2A0\xEFBBBF]
singleLineCommentStart "/""/"
sourceCharNotTermLine [^\x0A\x0D\xE280AC\xE280A9]
multiLineCommentStart "/""*"
multiLineCommentEnd "*""/"
astrix ["*"]
sourceCharNotAstrix [^"*"]

%x template_head
%x template_start
%x template_component

%x __REGEX
%x __REGEX_FLAGS

%x __BINARYSTART __OCTALSTART

%%

{singleLineCommentStart}{sourceCharNotTermLine}*{line_term}		{  yylval.name = _strdup(yytext); return COMMENT;}

{multiLineCommentStart}{sourceCharNotAstrix}*{multiLineCommentEnd}		{ yylval.name = _strdup(yytext); return COMMENT;}

[\/]/{_regex_char}+[\/]			{	// Regex Begins
									yylval.regexStart = _strdup(yytext);
									BEGIN(__REGEX);
									return REGEX_START;
								}
<__REGEX>{_regex_char}*			{	// Regex Body
									yylval.regexBody = _strdup(yytext);
									return REGEX_BODY;
								}
<__REGEX>[\/]/{_regex_flags}+	{	// Regex Ends with Flags
									yylval.regexEnd = _strdup(yytext);
									BEGIN(__REGEX_FLAGS);
									return REGEX_END;
								}
<__REGEX>[\/]					{	// Regex Ends without Flags
									yylval.regexEnd = _strdup(yytext);
									BEGIN(INITIAL);
									return REGEX_END;
								}
<__REGEX_FLAGS>{_regex_flags}+	{	// Regex Flags
									yylval.regexFlags = _strdup(yytext);
									BEGIN(INITIAL);
									return REGEX_FLAGS;
								}

`										{
											BEGIN(template_start);
											templateLiteral="";
											printf("\n");
										}

<template_start>{sourceChar}*\$\{		{
											//Template head
											BEGIN(template_component);
											templateLiteral+=yytext;
										}

<template_component>{sourceChar}+/\}	{
											printf("\tLiteral component: ${%s} \n",yytext);
											BEGIN(template_start);
											templateLiteral+=yytext;
										}

<template_start>\}{sourceChar}*\$\{		{
											//Template middle
											BEGIN(template_component);
											templateLiteral+=yytext;
										}
<template_start>\}{sourceChar}*\`		{
											//Literal tail
											templateLiteral+=yytext;
											yylval.templateLiteral=_strdup( templateLiteral.c_str());
											BEGIN(0);
											return TEMPLATE_LITERAL;
										}
<template_start>{sourceChar}*\`         {
											//No substitution
											BEGIN(0);
											templateLiteral+=yytext;
											yylval.templateLiteral=_strdup( templateLiteral.c_str());
											return TEMPLATE_LITERAL;
										}

null						{ return NULL_L; }
(\"{DoubleStrChar}*\")		{
								yylval.name = _strdup(yytext);
								return STRING_L;
							}
(\'{SingleStrChar}*\')		{
								yylval.name = _strdup(yytext);
								return STRING_L;
							}

({nonZeroDigit}{digit}*|0)"."{digit}*([eE](["+"-])?{digit}+)?			{ yylval.num = atof(yytext); return DECIMAL; }

"."{digit}+([eE](["+"-])?{digit}+)?										{ yylval.num = atof(yytext); return DECIMAL; }

(0|({nonZeroDigit}{digit}*))([eE](["+"-])?{digit}+)?					{ yylval.num = atof(yytext); return DECIMAL; }

0[bB]											{ yylval.name = _strdup(yytext); BEGIN(__BINARYSTART); return BINARYSTART; }

<__BINARYSTART>[01]+							{ yylval.num = std::stoi(yytext, nullptr, 2); BEGIN(INITIAL); return BINARY; }

0[oO]											{ yylval.name = _strdup(yytext); BEGIN(__OCTALSTART); return OCTALSTART; }

<__OCTALSTART>[0-7]+							{ yylval.num = std::stoi(yytext, nullptr, 8); BEGIN(INITIAL); return OCTAL; }

0[xX][0-9a-fA-F]+		{ yylval.num = strtof(yytext, NULL); return HEXIDECIMAL; }

true					{
							return TRUE; 
						}

false                   {
							return FALSE;
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

{LineTerminator}			{return LINE_TERM;}

[ \r\n\t]                   /* skip whitespace */

.                           {
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                            }
%%


int yywrap() {
	return 1;
}
