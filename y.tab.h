#pragma once

enum yytokentype {
	TRUE = 323,                     // N9871586	Xuelei Wang
	FALSE,                   // N9871586	Xuelei Wang
	DB_STR_CHARACTER,         // N9871586	Xuelei Wang
	SG_STR_CHARACTER,         // N9871586	Xuelei Wang
	LineContinuation,         // N9871586	Xuelei Wang
};

union YYSTYPE {
	char *dbstrcharacter;
	char *sgstrcharacter;
};

extern YYSTYPE yylval;
