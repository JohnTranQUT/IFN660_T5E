#include <typeinfo>
#include <AST/Declaration/AstDeclaration.h>
using namespace std;

LexicalBinding::LexicalBinding(Expression *_LHS) : LHS(_LHS), RHS(nullptr) {
	next.push_back(LHS);
}

LexicalBinding::LexicalBinding(Expression *_LHS, Expression *_RHS) : LHS(_LHS), RHS(_RHS) {
	next.push_back(RHS);
	next.push_back(LHS);
}

void LexicalBinding::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void LexicalBinding::genCode() {
	for (auto &i : next) {
		i->genCode();
	}
	if (next.size() > 1) {
		auto ident = refs.back();
		refs.pop_back();
		auto initializer = refs.back();
		refs.pop_back();
		Node::genCode(string("InitializeReferencedBinding(") + ident + ", " + initializer + string(")"));
	} else {
		auto ident = refs.back();
		refs.pop_back();
		Node::genCode(string("InitializeReferencedBinding(") + ident + ", " + "new UndefinedType()" + string(")"));
	}
}

BindingList::BindingList(Declaration *_declaration) : declaration(_declaration) {
	declarations.push_back(declaration);
}

BindingList::BindingList(BindingList *_bindingList, Declaration *_declaration) : declaration(_declaration) {
	for (auto &i : _bindingList->declarations) {
		declarations.push_back(i);
	}
	declarations.push_back(declaration);
}

void BindingList::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : declarations) {
		i->dump(indent + 1);
	}
}

void BindingList::genCode() {
	for (auto &i : declarations) {
		i->genCode();
	}
}

LexicalDeclaration::LexicalDeclaration(BindingList *_bindingList) : bindingList(_bindingList) {
	next.push_back(bindingList);
}

void LexicalDeclaration::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

void LexicalDeclaration::genCode() {
	for (auto &i : next) {
		i->genCode();
	}
}