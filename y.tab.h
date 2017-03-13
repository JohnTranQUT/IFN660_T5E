#pragma once

enum yytokentype {
	REGEX_START = 258, // N9571604 See Chuen Hong
    TRUE = 259, // n9871586 Xuelei Wang
	DECIMAL = 260, //n9301836 John Tran
	BREAK = 300, //n9569898 Manh Tuan Nguyen
	TEMPLATE_LITERAL //n9639799 Trung Hieu Tran
};

union YYSTYPE {
};

extern YYSTYPE yylval;
