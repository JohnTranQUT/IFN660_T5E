
%{
#include <y.tab.h>
#include <cstdio>
%}

d [0-9]
w [a-zA-Z]
W [ \r\n\t]
_line_term [\n\r(\xE2\x80\xA8)(\xE2\x80\xA9)]
dsc        [^\"\\\x0A\x0D]                                                      
void_dsc    ^\"\"$
ssc        [^\'\\\x0A\x0D]              
void_ssc    ^\'\'$
%%
                                                                              
true                                                                             { // N9871586	Xuelei Wang
                                                                                         return TRUE; }
false                                                                            { // N9871586	Xuelei Wang
                                                                                         return FALSE;}
{void_dsc}                                                                       { // N9871586	Xuelei Wang
                                                                                      yylval.dbstrcharacter = _strdup(yytext);
                                                                                         return DB_STR_CHARACTER;}	
\"{dsc}+\" 					                                                     { // N9871586	Xuelei Wang   //NOT EXCLUDE <LS> <PS>
																					  yylval.dbstrcharacter = _strdup(yytext);
																						 return DB_STR_CHARACTER;}
{void_ssc}																		 { // N9871586	Xuelei Wang
																					  yylval.sgstrcharacter = _strdup(yytext);
																						 return SG_STR_CHARACTER;}	
\'{ssc}+\' 																		 { // N9871586	Xuelei Wang   //NOT EXCLUDE <LS> <PS>
																					  yylval.sgstrcharacter = _strdup(yytext);
																						 return SG_STR_CHARACTER;}
[\x0A\x0D(\xE2\x80\xA8)(\xE2\x80\xA9)]|(\x0D\x0A)								 { // N9871586	Xuelei Wang
																						 return LineContinuation;}
{W}
.                           {
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                                exit(0);
                            }
%%

int yywrap() {
    return 1;
}
