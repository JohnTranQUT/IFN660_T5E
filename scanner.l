%{
#include <string>
#include "y.tab.h"

%}
illegal_escape (\\[^\\'"bfnrtv])

%%
null|NULL        {return NULL_L;}

(\".*{illegal_escape}.*) 	{yylval.name = "Syntax Error: Illegal escape sequence detected\n";
        return ERROR;}
		
(\'.*{illegal_escape}.*) 	{yylval.name = "Syntax Error: Illegal escape sequence detected\n";
        return ERROR;}	
		

(\"(\\.|[^"\r\n])*\")    {
	yylval.name = _strdup(yytext);
	return STRING_L;
	}

	
(\'(\\.|[^'\r\n])*\')    {
	yylval.name = _strdup(yytext);
	return STRING_L;
	}


(\'(\\.|[^'\r\n])*)     {yylval.name = "Syntax Error: String not ended, \"'\"expected\n";
    return ERROR;}
	
(\"(\\.|[^"\r\n])*)     {yylval.name = "Syntax Error: String not ended, \"\"\"expected\n";
    return ERROR;}
	
.* {yylval.name = "Syntax Error: unhandled pattern\n";
        return ERROR;}
%%
int yywrap()
{
    return 1;
}
