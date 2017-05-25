#include <AST/AstStatement.h>
using namespace std;

void BlockStatement::dump(int indent) {
	label(indent, "BlockStatement\n");
	statement->dump(indent + 1);
}
void BlockStatement::GenCode(FILE* file) {
	statement->GenCode(file);
}

void Block::dump(int indent) {
	label(indent, "Block\n");
	stmtList->dump(indent + 1);
}
void Block::GenCode(FILE* file) {
	stmtList->GenCode(file);
}

void ExpressionStatement::dump(int indent) {
	label(indent, "ExpressionStatement\n");
	expression->dump(indent + 1);
}
void ExpressionStatement::GenCode(FILE* file) {
	expression->GenCode(file);
};

void IfStatement::dump(int indent)  {
	label(indent, "IfStatement\n");
	cond->dump(indent + 1, "cond");
	thenStmt->dump(indent + 1, "then");
	if (elseStmt != nullptr)
	{
		elseStmt->dump(indent + 1, "else");
	}
}
void IfStatement::GenCode(FILE* file) {
	int refno;
	refno = cond->GenCode(file);
	emit(file, "if (GetValue(r%d)->ToBoolean()) {", refno);
	thenStmt->GenCode(file);
	emit(file, "}");
	if (elseStmt != nullptr) {
		emit(file, "else {");
		elseStmt->GenCode(file);
		emit(file, "}");
	}
}
