%{
#include <y.tab.h>
#include <stdio.h>
#include <iostream>
#include <string>
%}

digit [0-9]
nonZeroDigit [1-9]
letter [a-zA-Z]
line_term [\x0A\x0D\xE280AC\xE280A9]
whitespace [\x09\x0B\x0C\x20\xC2A0\xEFBBBF]
singleLineCommentStart "/""/"
sourceCharNotTermLine [^\x0A\x0D\xE280AC\xE280A9]
multiLineCommentStart "/""*"
multiLineCommentEnd "*""/"
astrix ["*"]
sourceCharNotAstrix [^"*"]

%x __BINARYSTART __OCTALSTART

%%

if                          { return IF; }
else                        { return ELSE; }
int                         { return INT; }
bool                        { return BOOL; }

{letter}({letter}|{digit})*     { yylval.name = _strdup(yytext); return IDENT; }

%{ //John Tran - White Space %}
{whitespace}		/* skip whitespace */

%{ //John Tran - Termination %}
{line_term}		{return LINE_TERM;}

%{ //John Tran - Comments SingleLine %}
{singleLineCommentStart}{sourceCharNotTermLine}*{line_term}		{  yylval.name = _strdup(yytext); return COMMENT;}

%{ //John Tran - Comments MultiLine %}
{multiLineCommentStart}{sourceCharNotAstrix}*{multiLineCommentEnd}		{ yylval.name = _strdup(yytext); return COMMENT;}

%{ //John Tran - Numeric Literals %}
%{ //Numeric Decimal%}
({nonZeroDigit}{digit}*|0)"."{digit}*([eE](["+"-])?{digit}+)?			{ yylval.num = atof(yytext); return DECIMAL; }
"."{digit}+([eE](["+"-])?{digit}+)?										{ yylval.num = atof(yytext); return DECIMAL; }
%{ //Numeric Decimal Integer %}
(0|({nonZeroDigit}{digit}*))([eE](["+"-])?{digit}+)?					{ yylval.num = atof(yytext); return DECIMAL; }
%{ //Numeric Binary, Octal, Hexemal %}
0[bB]											{ yylval.name = _strdup(yytext); BEGIN(__BINARYSTART); return BINARYSTART; }
<__BINARYSTART>[01]+							{ yylval.num = std::stoi(yytext, nullptr, 2); BEGIN(INITIAL); return BINARY; }
0[oO]											{ yylval.name = _strdup(yytext); BEGIN(__OCTALSTART); return OCTALSTART; }
<__OCTALSTART>[0-7]+							{ yylval.num = std::stoi(yytext, nullptr, 8); BEGIN(INITIAL); return OCTAL; }
0[xX][0-9a-fA-F]+		{ yylval.num = strtof(yytext, NULL); return HEXIDECIMAL; }



"="                         { return '='; }
"+"                         { return '+'; }
"<"                         { return '<'; }
"("                         { return '('; }
")"                         { return ')'; }
"{"                         { return '{'; }
"}"                         { return '}'; }
";"                         { return ';'; }



.                           { 
                                fprintf(stderr, "invalid character '%c'\n", *yytext);
                                //exit(0);
                            }
%%

int yywrap()
{
    return 1;
}
