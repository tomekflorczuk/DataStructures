#include "Element.h"

//Konstruktory
Element::Element(int number)
{
	Number = number;
	Next = nullptr;
	Previous = nullptr;
}

Element::Element()
{
	Next = nullptr;
	Previous = nullptr;
}
//Destruktor
Element::~Element()
{
	Previous = nullptr;
	Next = nullptr;
}