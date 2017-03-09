#pragma once

enum yytokentype {
	REGEX_START = 258,
	REGEX_END,
	REGEX_FLAGS,
	REGEX_BODY,
};

union YYSTYPE {
	char *regexStart;
	char *regexEnd;
	char *regexFlags;
	char *regexBody;
};

extern YYSTYPE yylval;
