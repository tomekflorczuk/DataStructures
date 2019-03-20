#pragma once

class Element
{
public:
	int Number;
	Element* Previous;
	Element* Next;
	Element(int number);
	Element();
	~Element();
};