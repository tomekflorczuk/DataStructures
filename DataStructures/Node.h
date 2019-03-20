#pragma once

class Node
{
	public:
	int Number;
	Node* Parent;
	Node* LeftChild;
	Node* RightChild;
	Node(int number);
	Node();
	~Node();
};