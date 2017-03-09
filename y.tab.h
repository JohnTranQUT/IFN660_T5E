enum yytokentype
{
	NUMBER = 258,
	IDENT = 259,
	INT = 262,
	BOOL = 263,
	//Manh Tuan Nguyen (Jin) - 20170308
	BREAK = 300,
	DO,
	IN,
	TYPEOF,
	CASE,
	ELSE,
	INSTANCEOF,
	VAR,
	CATCH,
	EXPORT,
	NEW,
	VOID,
	CLASS,
	EXTENDS,
	RETURN,
	WHILE,
	CONST,
	FINALLY,
	SUPER,
	WITH,
	CONTINUE,
	FOR,
	SWITCH,
	YIELD,
	DEBUGGER,
	FUNCTION,
	THIS,
	DEFAULT,
	IF,
	THROW,
	DELETE,
	IMPORT,
	TRY,
	AWAIT,
	ENUM
};

typedef union YYSTYPE
{
	char* name;
	int num;
};

extern YYSTYPE yylval;
