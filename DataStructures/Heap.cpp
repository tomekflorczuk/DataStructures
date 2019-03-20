#include "Heap.h"
#include "time.h"

//Konstruktory
Heap::Heap(int size)
{
	srand(time(nullptr));
	
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	
	Size = 0;
	
	Array = new int[size];
	for (int i = 0; i < size; i++)
	{
		Array[i] = rand();
		Size++;
		if (i > 0) FixUp();
	}
}

Heap::Heap()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	
	Size = 0;
	Array = nullptr;
}
//Destruktor
Heap::~Heap()
{
	delete[] Array;
}
//Dodawnie
void Heap::Add(int data)
{
	int* array = new int[Size + 1];
	for (int i = 0; i < Size; i++) array[i] = Array[i];
	array[Size] = data;
	
	delete[] Array;
	Array = array;
	Size++;
	
	FixUp();
}
//Usuwanie
void Heap::Erase()
{
	if (Size == 0) cout << "Kopiec pusty" << endl;
	else
	{	
		Swap(0, Size - 1);

		int* array = new int[Size - 1];	
		for (int i = 0; i < Size - 1; i++) array[i] = Array[i];

		delete Array;
		Array = array;
		Size--;

		FixDown(0);
	}
}
//Zwracanie rodzica
int Heap::getParent(int index)
{
	if(index > 0) return (index - 1) / 2;
	return 0;
}
//Zwracanie lewego potomka
int Heap::getLeftChild(int index)
{
	if(2 * index + 1 < Size) return 2 * index + 1;
	return -1;
}
//Zwracanie prawego potomka
int Heap::getRightChild(int index)
{
	if(2 * index + 2 < Size) return 2 * index + 2;
	return -1;
}
//Naprawianie kopca w gore
void Heap::FixUp()
{
	int index = Size - 1;
	while(Array[index] > Array[getParent(index)])
	{
		Swap(index, getParent(index));
		index = getParent(index);
	}
}
//Naprawianie kopca w dol
void Heap::FixDown(int index)
{
	int higherindex;
	
	while(index > -1)
	{
		
		if (getLeftChild(index) != -1 || getRightChild(index) != -1)
		{
			if(getLeftChild(index) == -1) higherindex = getRightChild(index);
			else if (getRightChild(index) == -1) higherindex = getLeftChild(index);
			else if (Array[getLeftChild(index)] > Array[getRightChild(index)])
			{
				higherindex = getLeftChild(index);
			}
			else higherindex = getRightChild(index);
			  
			if (Array[index] < Array[higherindex])
			{
				Swap(index, higherindex);
				index = higherindex;
			}
			else break;
		}
		else index = -1;
	}
}
//Zamiana dwoch liczb
void Heap::Swap(int index1, int index2)
{
	int bufor;

	bufor = Array[index1];
	Array[index1] = Array[index2];
	Array[index2] = bufor;
}
//Wyszukiwanie
int Heap::Search(int data)
{
	if (Size == 0) cout << "Kopiec pusty" << endl;
	else
	{
		for (int i = 0; i < Size; i++)
		{
			if (Array[i] == data)
			{
				cout << "Szukana liczba znajduje sie na " << i << " indexie" << endl;
				return i;
			}
		}
		cout << "Nie ma podanej liczby w kopcu" << endl;
	}
}
//Wyswietlanie
void Heap::Show(string sp, string sn, int i)
{

	if (Size == 0) cout << "Kopiec pusty" << endl;
	else
	{
		string s;

		if (i < Size)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			Show(s + cp, cr, 2 * i + 2);

			s = s.substr(0, sp.length() - 2);

			cout << s << sn << Array[i] << endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			Show(s + cp, cl, 2 * i + 1);
		}
	}
}
//Czytanie danych z pliku
bool Heap::ReadFromFile(string filename)
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