%{
#include <string>
#include "y.tab.h"

%}

%%
 /* n08706638 Null literal start */
null        {return NULL_L;}
 /* end of Null literal  */
 
 /*n08706638 Chun Chan String literal*/		

(\"(\\.|[^"\x0D\x2028\x2029\x0A])*\")    {
	yylval.name = _strdup(yytext);
	return STRING_L;
	}
	
(\'(\\.|[^'\x0D\x2028\x2029\x0A])*\')    {
	yylval.name = _strdup(yytext);
	return STRING_L;
	}


(\'.*)     {yylval.name = "Syntax Error: String not ended, \"'\"expected\n";
    return ERROR;}
	
(\".*)     {yylval.name = "Syntax Error: String not ended, \"\"\"expected\n";
    return ERROR;}

 /* End of String scanner */
	
.* {yylval.name = "Syntax Error: unhandled pattern\n";
        return ERROR;}
%%
int yywrap()
{
    return 1;
}
