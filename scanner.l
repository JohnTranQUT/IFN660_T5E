%{
#include <y.tab.h>
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
}
