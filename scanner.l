%{
#include <y.tab.h>
<<<<<<< HEAD
#include <string>

using namespace std;
string templateLiteral;
%}

digit [0-9]
letter [a-zA-Z]
sourceChar [a-zA-Z0-9_ \n]

%x template_head
%x template_start
%x template_component

%%

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
											printf("\t*)Literal component: ${%s} \n",yytext);									
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
=======
#include <cstdio>
%}

d [0-9]
w [a-zA-Z_]
W [ \r\n\t]
_regex_char [^/]|(\\\/)

_regex_flags [gimuy]

%x __REGEX
%x __REGEX_FLAGS

%%
[\/]							{	// Regex Begins
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
{W}
.								{
									fprintf(stderr, "invalid character '%c'\n", *yytext);
									exit(0);
								}
%%

int yywrap() {
    return 1;
>>>>>>> 0f6687b226cc5e9dc3b7a2afcec7040b9c813118
}
