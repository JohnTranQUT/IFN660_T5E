#include <vector>
enum yytokentype
{
	NUMBER = 258,
	IDENT = 259,
	IF = 260,
	ELSE = 261,
	INT = 262,
	BOOL = 263,
	TEMPLATE_LITERAL=264
};
typedef union YYSTYPE
{
	char* name;
	int num;
	char* templateLiteral;
};

extern YYSTYPE yylval;
