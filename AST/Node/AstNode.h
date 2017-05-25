#pragma once
#include <vector>
#include <sstream>
using namespace std;

class Node {
public:
	virtual ~Node() = default;
	virtual void dump(int = 0) = 0;
	static void dump(string, int);
	static void indentation(int);
	virtual void genCode(int *registerNum) = 0;
	static void genCode(string);
};

class Container : public Node {
	vector<Node*> next;
	string name;
public:
	explicit Container(vector<Node*>, string);
	void dump(int = 0) override;
	void genCode(int *registerNum) override;
};
