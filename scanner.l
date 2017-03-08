%{
#include <y.tab.h>
#include <stdio.h>
#include <string.h>
%}

digit [0-9]
letter [a-zA-Z]

%%                   
int                         { return INT; }
bool                        { return BOOL; }

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

{letter}({letter}|{digit})*     { yylval.name = _strdup(yytext); return IDENT; }
{digit}+                        { yylval.num = atoi(yytext); return NUMBER; }


"="                         { return '='; }
"+"                         { return '+'; }
"<"                         { return '<'; }
"("                         { return '('; }
")"                         { return ')'; }
"{"                         { return '{'; }
"}"                         { return '}'; }
";"                         { return ';'; }

[ \r\n\t]                   /* skip whitespace */

.                           { 
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                                exit(0);
                            }
%%


int yywrap()
{
	return 1;
}