
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
(({nonZeroDigit}{digit}*|0)"."{digit}*([eE](["+"-])?{digit}+)?)|("."{digit}+([eE](["+"-])?{digit}+)?	{
								//John Tran
								return DECIMAL;
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
