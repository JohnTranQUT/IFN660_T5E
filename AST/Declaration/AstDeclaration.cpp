#include <typeinfo>
#include <AST/Declaration/AstDeclaration.h>
using namespace std;

LexicalBinding::LexicalBinding(Expression *_LHS) : LHS(_LHS),
                                                   RHS(nullptr) {
	children.push_back(LHS);
}

LexicalBinding::LexicalBinding(Expression *_LHS, Expression *_RHS) : LHS(_LHS),
                                                                     RHS(_RHS) {
	children.push_back(RHS);
	children.push_back(LHS);
}

void LexicalBinding::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void LexicalBinding::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
	if (children.size() > 1) {
		auto ident = refs.back();
		refs.pop_back();
		auto initializer = refs.back();
		refs.pop_back();
		emit(string("InitializeReferencedBinding(") + ident + ", " + initializer + string(");"), false);
	} else {
		auto ident = refs.back();
		refs.pop_back();
		emit(string("InitializeReferencedBinding(") + ident + ", " + "new UndefinedType()" + string(");"), false);
	}
}

void LexicalBinding::instantiate() {
	for (auto &i : children) {
		i->instantiate();
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

void BindingList::evaluate() {
	for (auto &i : declarations) {
		i->evaluate();
	}
}

void BindingList::instantiate() {
	for (auto &i : declarations) {
		i->instantiate();
	}
}

LexicalDeclaration::LexicalDeclaration(BindingList *_bindingList) : bindingList(_bindingList) {
	children.push_back(bindingList);
}

void LexicalDeclaration::dump(int indent) {
	auto message = string(typeid(*this).name()).substr(6) + ": ";
	Node::dump(message, indent);
	for (auto &i : children) {
		i->dump(indent + 1);
	}
}

void LexicalDeclaration::evaluate() {
	for (auto &i : children) {
		i->evaluate();
	}
}

void LexicalDeclaration::instantiate() {
	for (auto &i : children) {
		i->instantiate();
	}
}
