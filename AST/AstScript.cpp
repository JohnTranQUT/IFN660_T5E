#include <AST/AstScript.h>
using namespace std;

void StatementListItem::dump(int indent) {
	label(indent, "StatementListItem\n");
	statement->dump(indent + 1);
}
void StatementListItem::GenCode(FILE* file) {
	statement->GenCode(file);
}

StatementList::StatementList(StatementListItem* item)
{
	items = new vector<StatementListItem*>();
	items->push_back(item);
}
void StatementList::push_back(StatementListItem *item)
{
	items->push_back(item);
}
void StatementList::dump(int indent) {
	label(indent, "StatementList\n");
	for (std::vector<StatementListItem*>::iterator iter = items->begin(); iter != items->end(); ++iter)
		(*iter)->dump(indent + 1);
}
void StatementList::GenCode(FILE* file) {
	for (std::vector<StatementListItem*>::iterator iter = items->begin(); iter != items->end(); ++iter)
		(*iter)->GenCode(file);
}

void ScriptBody::dump(int indent) {
	label(indent, "ScriptBody\n");
	stmtList->dump(indent = 1);
}
void ScriptBody::GenCode(FILE* file) {
	stmtList->GenCode(file);
}

void Script::dump(int indent) {
	label(indent, "Script\n");
	scriptBody->dump(indent + 1);
}
void Script::GenCode(FILE* file) {
	scriptBody->GenCode(file);
}