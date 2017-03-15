#pragma once

enum yytokentype
{
	NUMBER = 258,
	IDENT = 259,
	IF = 260,
	ELSE = 261,
	INT = 262,
	BOOL = 263,
	//John Tran n9301836 - Extra Numeric Types and LINE_TERM
	DECIMAL = 264,
	INTEGER = 265,
	BINARYSTART = 267,
	BINARY = 268,
	OCTALSTART = 269,
	OCTAL = 270,
	HEXIDECIMALSTART = 271, //This is not required.
	HEXIDECIMAL = 272,
	LINE_TERM = 273,
	COMMENT = 274,
	TEST = 300
};
typedef union YYSTYPE
{
	char* name;
	int integer;
	float num;
};
extern YYSTYPE yylval;
