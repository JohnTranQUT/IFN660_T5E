%{
#include <y.tab.h>
%}

digit [0-9]
letter [a-zA-Z]

%%

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
