#pragma once

enum yytokentype {
	REGEX_START = 258,
	REGEX_END,
};

union YYSTYPE {
	char *regexStart;
	char *regexEnd;
};

extern YYSTYPE yylval;
