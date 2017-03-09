#pragma once

enum yytokentype {
	REGEX_START = 258,
};

union YYSTYPE {
	char *regexStart;
};

extern YYSTYPE yylval;
