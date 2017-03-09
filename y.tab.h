#pragma once

enum yytokentype {
	REGEX_START = 258,
	REGEX_END,
	REGEX_FLAGS,
};

union YYSTYPE {
	char *regexStart;
	char *regexEnd;
	char *regexFlags;
};

extern YYSTYPE yylval;
