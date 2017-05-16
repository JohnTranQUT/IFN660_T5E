#pragma once
#include <vector>
#include <AST/Script/AstScript.h>
#include <AST/Expression/AstExpression.h>
using namespace std;

class Declaration : public Node {
public:
	virtual ~Declaration() = default;
	void dump(int = 0) override = 0;
};

class LexicalDeclaration : public Declaration {
	vector<Node *> next;
	Declaration *declaration;
public:
	explicit LexicalDeclaration(Declaration *);
	void dump(int = 0) override;
};

class BindingList : public Declaration {
	Declaration *declaration;
public:
	explicit BindingList(Declaration *);
	explicit BindingList(BindingList *, Declaration *);
	void dump(int = 0) override;
};

class LexicalBinding : public Declaration {
	vector<Node *> next;
	Expression *lhs;
	Expression *rhs;
public:
	explicit LexicalBinding(Expression *);
	explicit LexicalBinding(Expression *, Expression *);
	void dump(int = 0) override;
};