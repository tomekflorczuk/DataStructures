#pragma once
#include "Main.h"

using namespace std;

class Heap
{
	int* Array;
	int Size;
	string cr, cl, cp;
public:
	Heap(int size);
	Heap();
	~Heap();
	void Add(int data);
	void Erase();
	int getParent(int index);
	int getLeftChild(int index);
	int getRightChild(int index);
	void FixUp();
	void FixDown(int index);
	void Swap(int index1, int index2);
	int Search(int data);
	void Show(string sp, string sn, int v);
	bool ReadFromFile(string filename);
};