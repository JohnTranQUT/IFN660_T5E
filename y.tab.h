enum yytokentype
{
	NUMBER = 258,
	IDENT = 259,
	INT = 262,
	BOOL = 263,
	//Manh Tuan Nguyen (Jin) - 20170308
	BREAK = 264,
	DO = 265,
	IN = 266,
	TYPEOF = 267,
	CASE = 268,
	ELSE = 269,
	INSTANCEOF = 270,
	VAR = 271,
	CATCH = 272,
	EXPORT = 273,
	NEW = 274,
	VOID = 275,
	CLASS = 276,
	EXTENDS = 277,
	RETURN = 278,
	WHILE = 279,
	CONST = 280,
	FINALLY = 281,
	SUPER = 282,
	WITH = 283,
	CONTINUE = 284,
	FOR = 285,
	SWITCH = 286,
	YIELD = 287,
	DEBUGGER = 288,
	FUNCTION = 289,
	THIS = 290,
	DEFAULT = 291,
	IF = 292,
	THROW = 293,
	DELETE = 294,
	IMPORT = 295,
	TRY = 296
};

typedef union YYSTYPE
{
	char* name;
	int num;
};

extern YYSTYPE yylval;
