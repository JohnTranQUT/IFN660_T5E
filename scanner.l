
%{
#include <y.tab.h>
#include <cstdio>
%}

%%

.                           {
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                                exit(0);
                            }

%%

int yywrap() {
    return 1;
}
