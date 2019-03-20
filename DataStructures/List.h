#pragma once
#include "Main.h"
#include "Element.h"

using namespace std;

class List
{
	int Size;
	Element* Head;
	Element* Tail;	
public:
	List(int size);
	List();
	~List();
	//Funkcje
	void AddFront(int data);
	void AddBack(int data);
	void AddSpecific(int data, int index);
	void EraseFront();
	void EraseBack();
	void EraseSpecific(int index);
	int Search(int data);
	void Show();
	bool ReadFromFile(string filename);
};