#pragma once
#include <vector>
using namespace std;

class Node {
protected:
	static int numRef;
	static int numLex;
	static vector<string> refs;
	static vector<string> lexs;
public:
	virtual ~Node() = default;
	virtual void dump(int = 0) = 0;
	virtual void evaluate() = 0;
	virtual void instantiate() = 0;
	static void dump(string, int);
	static void emit(string code, bool saveRef = true, bool isLex = false, bool semicolon = true, bool pure = false);
	static void indentation(int);
};

class Container : public Node {
	vector<Node*> children;
	string name;
public:
	explicit Container(vector<Node*>, string);
	void dump(int = 0) override;
	void evaluate() override;
	void instantiate() override;
};
