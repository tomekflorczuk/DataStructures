#pragma once
#include "Main.h"

using namespace std;

class Array
{
	int* DynamicArray;
	int Size;
public:
	Array(int size);
	Array();
	~Array();
	void AddFront(int data);
	void AddBack(int data);
	void AddSpecific(int data, int index);
	void EraseFront();
	void EraseBack();
	void EraseSpecific(int index);
	int Search(int data);
	void Show();
	int GetSize();
	bool ReadFromFile(string filename);
};