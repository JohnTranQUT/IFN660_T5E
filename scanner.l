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

LineTerminator (\x0D\x2028\x2029\x0A)
LineCont (\\{LineTerminatorSeq})
LineTerminatorSeq (\x0A\x0D|\x0D[^\x0A]|[\x0A\x2028\x2029])
EscSeq ({CharEscSeq}|0[^0-9]|{HexEscSeq}|{UnicodeEscSeq})
CharEscSeq ([{SingleEscChar}]|{NonEscChar})
SingleEscChar ('"\\bfnrtv)
NonEscChar ([^{EscChar}{LineTerminator}])
EscChar ({SingleEscChar}0-9xu)
HexEscSeq (x[0-9A-Fa-f]{2})
UnicodeEscSeq (u([0-9A-Fa-f]{4})|\{[0-9A-Fa-f][0-9A-Fa-f]*\})
DoubleStrChar ([ 0-9]|[^"\\\x0D\x2028\x2029\x0A]|\\{EscSeq}|{LineCont})
SingleStrChar ([ 0-9]|[^'\\\x0D\x2028\x2029\x0A]|\\{EscSeq}|{LineCont})

%x template_head
%x template_start
%x template_component

%x __REGEX
%x __REGEX_FLAGS

%%

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

[ \r\n\t]                   /* skip whitespace */

.                           { 
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                            }

%%


int yywrap() {
	return 1;
}
