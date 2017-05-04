#include <typeinfo>
#include "AST/AstNode.h"
#include "AST/AstStatement.h"
#include "AST/AstScript.h"

using namespace std;

StatementListItem::StatementListItem(Statement *_statement) : statement(_statement) {
	
}

void StatementListItem::dump(int indent) {
	label(indent, "StatementListItem\n");
	statement->dump(indent + 1);
}

/*
StatementList::StatementList(vector<StatementListItem*>* items): items(items)
{
}
*/
StatementList::StatementList(StatementListItem* item)
{
	items = new vector<StatementListItem*>();
	items->push_back(item);
}

void StatementList::push_back(StatementListItem* item)
{
	items->push_back(item);
}

void StatementList::dump(int indent)
{
	label(indent, "StatementList\n");
	for (std::vector<StatementListItem*>::iterator iter = items->begin(); iter != items->end(); ++iter)
		(*iter)->dump(indent + 1);
}


ScriptBody::ScriptBody(StatementList* stmtList): stmtList(stmtList)
{
}

void ScriptBody::dump(int indent) {
	label(indent, "ScriptBody\n");
	stmtList->dump(indent = 1);
}



Script::Script(ScriptBody *scriptBody): scriptBody(scriptBody)
{
}

void Script::dump(int indent) {
	label(indent, "Script\n");
	scriptBody->dump(indent + 1);
}
