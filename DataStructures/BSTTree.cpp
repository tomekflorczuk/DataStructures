#include "BSTTree.h"
#include <ctime>

//Konstruktory
BSTTree::BSTTree(int size)
{
	srand(time(nullptr));

	Size = 0;
	for(int i = 0 ; i < size ; i++) Add(rand());
}

BSTTree::BSTTree()
{	
	Root = nullptr;
	Size = 0;
}
//Destruktor
BSTTree::~BSTTree()
{
	Root = nullptr;
}
//Dodawanie
void BSTTree::Add(int data)
{
	Node* node = new Node(data);

	if(Size == 0)
	{
		Root = node;
		Size++;
	}
	else
	{
		Node* bufor = Root;	
		while (true)
		{
			if (data > bufor->Number)
			{
				if (bufor->RightChild == nullptr)
				{
					bufor->RightChild = node;
					node->Parent = bufor;
					Size++;
					break;
				}
				bufor = bufor->RightChild;				
			}
			else if (data <= bufor->Number)
			{
				if (bufor->LeftChild == nullptr)
				{
					bufor->LeftChild = node;
					node->Parent = bufor;
					Size++;
					break;
				}
				bufor = bufor->LeftChild;
			}
		}
	}
}
//Usuwanie
void BSTTree::Erase(int data)
{
	if (Size == 0) cout << "Drzewo puste" << endl;
	else
	{
		Node* bufor = Search(data);
		if (bufor != nullptr)
		{
		//Przypadek gdy wezel nie ma dzieci
		if(bufor->LeftChild == nullptr && bufor->RightChild == nullptr) 
		{
			if (bufor->Number > bufor->Parent->Number) bufor->Parent->RightChild = nullptr;
			else bufor->Parent->LeftChild = nullptr;
			bufor->Parent = nullptr;
			delete bufor;
		}
		//Przypadek gdy wezel ma jedno dziecko
		else if (bufor->LeftChild == nullptr || bufor->RightChild == nullptr)
		{
			if(bufor->LeftChild != nullptr)
			{
				Node* LeftChild = bufor->LeftChild;
				bufor->Number = LeftChild->Number;
				bufor->LeftChild = LeftChild->LeftChild;
				bufor->RightChild = LeftChild->RightChild;
				delete LeftChild;
			}
			else
			{
				Node* RightChild = bufor->RightChild;
				bufor->Number = RightChild->Number;
				bufor->LeftChild = RightChild->LeftChild;
				bufor->RightChild = RightChild->RightChild;
				delete RightChild;
			}
		}
		//Przypadek gdy wezel ma oboje dzieci
		else
		{
			Node* Next = SerachNext(bufor);
			bufor->Number = Next->Number;
			if (Next->RightChild != nullptr)
			{
				Next->Number = Next->RightChild->Number;
				delete Next->RightChild;
			}
			else delete Next;
		}
		}
	}
}
//Wyszukiwanie
Node* BSTTree::Search(int data)
{
	if (Size == 0) cout << "Drzewo puste" << endl;
	else
	{
		Node* bufor = Root;
		while (bufor != nullptr)
		{
			if (data > bufor->Number) bufor = bufor->RightChild;
			else if (data < bufor->Number) bufor = bufor->LeftChild;
			else
			{
				cout << "Znaleziono" << endl;
				return bufor;
			}
		}
		cout << "Nie ma podanej liczby w drzewie" << endl;
		return nullptr;
	}
}
//Wyszukiwanie nastepnika
Node * BSTTree::SerachNext(Node* node)
{
	if(node->RightChild != nullptr)
	{
		Node* bufor = node->RightChild;
		while(bufor->LeftChild != nullptr)
		{
			bufor = bufor->LeftChild;
		}
		return bufor;
	}
	if(node->RightChild == nullptr)
	{
		Node* bufor = node;
		while(bufor->Number > bufor->Parent->Number)
		{
			bufor = bufor->Parent;
		}
		return bufor->Parent;
	}
}
//Wyswietlanie
void BSTTree::Show(string sp, string sn, Node* i)
{
	string cr, cl, cp;

	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	
	if (Size == 0) cout << "Drzewo puste" << endl;
	else
	{
		string s;

		if (i)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			Show(s + cp, cr, i->RightChild);

			s = s.substr(0, sp.length() - 2);
			cout << s << sn << i->Number << endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			Show(s + cp, cl, i->LeftChild);
		}
	}
}
//Dostêp do korzenia
Node* BSTTree::getRoot()
{
	return Root;
}
//Czytanie danych z pliku
bool BSTTree::ReadFromFile(string filename)
{
	int data, size;
	ifstream file;
	file.open(filename);

	if (file.is_open())
	{
		file >> size;

		for (int i = 0; i < size; i++)
		{
			file >> data;
			Add(data);
		}
		return true;
	}

	cout << "Blad wczytywania pliku" << endl;
	file.close();
	return false;
}