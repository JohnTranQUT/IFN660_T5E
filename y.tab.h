#pragma once

enum yytokentype {
	REGEX_START = 258, // N9571604 See Chuen Hong
    TRUE = 259, // n9871586 Xuelei Wang
};

union YYSTYPE {
};

extern YYSTYPE yylval;
