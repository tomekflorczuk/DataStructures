#include "Node.h"

//Konstruktory
Node::Node(int number)
{
	Number = number; 
	Parent = nullptr;
	LeftChild = nullptr;
	RightChild = nullptr;
}

Node::Node()
{
	Parent = nullptr;
	LeftChild = nullptr;
	RightChild = nullptr;
}
//Destruktor
Node::~Node()
{
	Parent = nullptr;
	LeftChild = nullptr;
	RightChild = nullptr;
}