
%{
#include <y.tab.h>
#include <cstdio>
%}

d [0-9]
w [a-zA-Z_]
W [ \r\n\t]

%%

[/]							{	// N9571604 See Chuen Hong
								return REGEX_START;
							}
true                        {   // N9871586	Xuelei Wang
                                return TRUE; 
							}
break						{ // n9569898 Manh Tuan Nguyen
								return BREAK;
							}							
(([1-9]{d}*|0)"."{d}*([eE](["+"-])?{d}+)?)|("."{d}+([eE](["+"-])?{d}+)?)	{
								//John Tran
								return DECIMAL;
							}
							
`							{
								//n9639799 Trung Hieu Tran
								return TEMPLATE_LITERAL;
							}
							
{W}
.                           {
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                                exit(0);
                            }
%%

int yywrap() {
    return 1;
}
