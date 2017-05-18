#pragma once
#include <vector>
#include <AST/Expression/AstExpression.h>
using namespace std;

class Declaration : public Node {
public:
	virtual ~Declaration() = default;
	void dump(int = 0) override = 0;
	void genCode(bool = false) override = 0;
};

class LexicalBinding : public Declaration {
	vector<Node *> next;
	Expression *LHS;
	Expression *RHS;
public:
	explicit LexicalBinding(Expression *);
	explicit LexicalBinding(Expression *, Expression *);
	void dump(int = 0) override;
	void genCode(bool = false) override;
};

class BindingList : public Declaration {
	Declaration *declaration;
public:
	vector<Declaration *> declarations;
	explicit BindingList(Declaration *);
	explicit BindingList(BindingList *, Declaration *);
	void dump(int = 0) override;
	void genCode(bool = false) override;
};

class LexicalDeclaration : public Declaration {
	vector<Node *> next;
	BindingList *bindingList;
public:
	explicit LexicalDeclaration(BindingList *);
	void dump(int = 0) override;
	void genCode(bool = false) override;
};