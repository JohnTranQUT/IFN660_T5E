#include <stdio.h>
#include <y.tab.h>
int yylex();

int main(int argc, char* argv[])
{
	int token;
	do
	{
		
			token = yylex();
			printf("token %d\n", token);
		} while (token != 0);

		return 0;



}
