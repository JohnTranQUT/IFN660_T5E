#pragma once
enum yytokentype {
	// JIN - START -------------------------------------------------------
	BREAK = 258,
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
	ENUM,
	TDOT,
	LE,
	GE,
	EQ,
	DIFF,
	EQTYPE,
	DFTYPE,
	INCREASE,
	DECREASE,
	LSHIFT,
	RSHIFT,
	URSHIFT,
	LOGAND,
	LOOR,
	ADDASS,
	SUBASS,
	MULASS,
	REMASS,
	LSHIFTASS,
	RSHIFTASS,
	URSHIFTASS,
	BWANDASS,
	BWORASS,
	BWXORASS,
	ARROWF,
	EXP,
	EXPASS,
	DIVASS,
	// JIN - END -------------------------------------------------------
	// JASON - START -------------------------------------------------------
	TEMPLATE_LITERAL,
	// JASON - END -------------------------------------------------------
	// ALFRED - START -------------------------------------------------------
	REGEX_START,
	REGEX_END,
	REGEX_FLAGS,
	REGEX_BODY,
	// ALFRED - END -------------------------------------------------------
};

union YYSTYPE {
	char* name;
	int num;
	char* templateLiteral;
	char *regexStart;
	char *regexEnd;
	char *regexFlags;
	char *regexBody;
};

extern YYSTYPE yylval;
