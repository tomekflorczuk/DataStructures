#pragma once
#include "Main.h"
#include "Node.h"

using namespace std;

class BSTTree
{
	int Size;
	Node* Root;
	string cr, cl, cp;
public:
	BSTTree(int size);
	BSTTree();
	~BSTTree();
	void Add(int data);
	void Erase(int data);
	Node* Search(int data);
	Node* SerachNext(Node* node);
	void Show(string sp, string sn, Node* i);
	Node* getRoot();
	bool ReadFromFile(string filename);
};