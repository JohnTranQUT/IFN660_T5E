#define _CRT_SECURE_NO_DEPRECATE
#include <limits>
#include <parser.h>
#include <fstream>

extern FILE *yyin;
extern Node *root;

int Node::numRef = 1;
int Node::numLex = 1;
int Node::indent = 0;
vector<string> Node::refs;
vector<string> Node::lexs;
ofstream output;

using namespace std;

void main(int argc, char *argv[]) {

	fopen_s(&yyin, argv[1], "r");
	yyparse();

	output.open(argv[2], ofstream::out | ofstream::trunc);
	root->evaluate();
	output.close();
	puts("Code Generated Successfully");

}
