#include "List.h"
#include <ctime>

//Konstruktory
List::List(int size)
{
	srand(time(nullptr));
	
	Size = 0;
	Head = nullptr;
	Tail = nullptr;

	for(int i = 0;i < size;i++) AddFront(rand());
}

List::List()
{
	Size = 0;
	Head = nullptr;
	Tail = nullptr;
}
//Destruktor
List::~List()
{
	Head = nullptr;
	Tail = nullptr;
}
//Dodawanie na poczatek
void List::AddFront(int data)
{
	Element* element = new Element(data);
	if (Head == nullptr) Head = element;
	else 
	{
		element->Next = Head;
		Head->Previous = element;
		Head = element;
	}
	if (Tail == nullptr) Tail = element;

	Size++;
}
//Dodawnia na koniec
void List::AddBack(int data)
{
	Element* element = new Element(data);
	if (Tail == nullptr) Tail = element;
	else
	{
		element->Previous = Tail;
		Tail->Next = element;
		Tail = element;
	}
	if (Head == nullptr) Head = element;

	Size++;
}
//Dodawanie w konkretne miejsce
void List::AddSpecific(int data, int index)
{
	if (index == 0) AddFront(data);
	else if (index == Size) AddBack(data);
	else if(index > 0 && index < Size)
		{
		Element* element = new Element(data);
		Element* bufor = Head;
		for (int i = 0; i < index-1; i++) bufor = bufor->Next;

		element->Next = bufor->Next;
		element->Previous = bufor;
		bufor->Next = element;
		bufor->Next->Previous = element;

		Size++;
		}
	else cout << "W liscie nie ma takiego indexu" << endl;
}
//Usuwanie z poczatku
void List::EraseFront()
{
	if (Size == 0) cout << "Lista pusta" << endl;
	else
	{
		if (Size > 1)
		{
			Element* element = Head->Next;
			delete Head;
			element->Previous = nullptr;
			Head = element;
		}
		else
		{
			delete Head;
			Head = nullptr;
			Tail = nullptr;
		}
		Size--;
	}
}
//Usuwanie z konca
void List::EraseBack()
{
	if (Size == 0) cout << "Lista pusta" << endl;
	else
	{
		if (Size > 1)
		{
			Element* element = Tail->Previous;
			delete Tail;
			element->Next = nullptr;
			Tail = element;
		}
		else
		{
			delete Tail;
			Head = nullptr;
			Tail = nullptr;
		}
		Size--;
	}
}
//Usuwanie z konkretnego miejsca
void List::EraseSpecific(int index)
{
	if (Size == 0) cout << "Lista pusta" << endl;
	else
	{
		if (index == 0) EraseFront();
		else if (index == Size - 1) EraseBack();
		else if (index > 0 && index < Size - 1)
		{
			Element* bufor = Head;
			for (int i = 0; i < index; i++) bufor = bufor->Next;

			bufor->Previous->Next = bufor->Next;
			bufor->Next->Previous = bufor->Previous;
			delete bufor;

			Size--;
		}
		else cout << "W liscie nie ma takiego indexu" << endl;
	}
}
//Wyszukiwanie
int List::Search(int data)
{
	if (Size == 0) cout << "Lista pusta" << endl;
	else
	{
		Element* element = Head;
		for (int i = 0; i < Size; i++)
		{
			if (element->Number == data)
			{
				cout << "Szukana liczba znajduje sie na " << i << " indexie" << endl;
				return i;
			}
			element = element->Next;
		}
		cout << "Nie ma podanej liczby w liscie" << endl;
		return 0;
	}
}
//Wyswietlanie
void List::Show()
{
	if (Size == 0) cout << "Lista pusta" << endl;
	else
	{
		Element* element = Head;
		for (int i = 0; i < Size; i++)
		{
			cout << element->Number << ", ";
			element = element->Next;
		}
		cout << endl;
	}
}
//Czytanie danych z pliku
bool List::ReadFromFile(string filename)
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
			AddBack(data);
		}
		return true;
	}
	cout << "Blad wczytywania pliku" << endl;
	file.close();
	return false;
}