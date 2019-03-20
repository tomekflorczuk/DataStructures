#include "Array.h"
#include "time.h"

//Konstruktory
Array::Array(int size)
{
	srand(time(nullptr));
	DynamicArray = new int[size];
	for (int i = 0; i < size; i++) DynamicArray[i] = rand();
	Size = size;
}

Array::Array()
{
	DynamicArray = nullptr;
	Size = 0;
}
//Destruktor
Array::~Array()
{
	delete[] DynamicArray;
}
//Dodawanie na poczatek
void Array::AddFront(int data)
{
	int* array = new int[Size + 1];
	array[0] = data;
	for (int i = 1; i < Size + 1; i++) array[i] = DynamicArray[i - 1];

	delete[] DynamicArray;
	DynamicArray = array;
	Size++;
}
//Dodawanie na koniec
void Array::AddBack(int data)
{
	int* array = new int[Size + 1];
	for (int i = 0; i < Size; i++) array[i] = DynamicArray[i];
	array[Size] = data;
	
	delete[] DynamicArray;
	DynamicArray = array;
	Size++;
}
//Dodawanie w konkretne miejsce
void Array::AddSpecific(int data, int index)
{
	if (index == 0) AddFront(data);
	else if (index == Size - 1) AddBack(data);
	else if (index > 0 && index < Size - 1)
	{
		int* array = new int[Size + 1];
		for (int i = 0; i < index; i++) array[i] = DynamicArray[i];
		array[index] = data;
		for (int i = index + 1; i < Size + 1; i++) array[i] = DynamicArray[i - 1];

		delete[] DynamicArray;
		DynamicArray = array;
		Size++;
	}
	else cout << "W tablicy nie ma takiego indexu"<<endl;
}
//Usuwanie z poczatku
void Array::EraseFront()
{
	if (Size == 0) cout << "Tablica pusta" << endl;
	else
	{
		int* array = new int[Size - 1];
		for (int i = 0; i < Size - 1; i++) array[i] = DynamicArray[i + 1];

		delete[] DynamicArray;
		DynamicArray = array;
		Size--;
	}
}
//Usuwnie z konca
void Array::EraseBack()
{
	if (Size == 0) cout << "Tablica pusta" << endl;
	else
	{
		int* array = new int[Size - 1];
		for (int i = 0; i < Size - 1; i++) array[i] = DynamicArray[i];

		delete[] DynamicArray;
		DynamicArray = array;
		Size--;
	}
}
//Usuwanie z konkretnego miejsca
void Array::EraseSpecific(int index)
{
	if (Size == 0) cout << "Tablica pusta" << endl;
	else
	{
		if (index == 0) EraseFront();
		else if (index == Size - 1) EraseBack();
		else if (index > 0 && index < Size - 1)
		{
			int* array = new int[Size - 1];
			for (int i = 0; i < index; i++) array[i] = DynamicArray[i];
			for (int i = index; i < Size - 1; i++) array[i] = DynamicArray[i + 1];

			delete[] DynamicArray;
			DynamicArray = array;
			Size--;
		}
		else cout << "W tablicy nie ma takiego indexu" << endl;
	}
}
//Wyszukiwanie
int Array::Search(int data)
{
	if (Size == 0) cout << "Tablica pusta" << endl;
	else
	{
		for (int i = 0; i < Size; i++)
		{
			if (DynamicArray[i] == data)
			{
				cout << "Szukana liczba znajduje sie na " << i << " indexie" << endl;
				return i;
			}
		}
		cout << "Nie ma podanej liczby w tablicy" << endl;
	}
}
//Wyswietlanie
void Array::Show()
{
	if (Size == 0) cout << "Tablica pusta" << endl;
	else
	{
		for (int i = 0; i < Size; i++) cout << DynamicArray[i] << ", ";
		cout << endl;
	}
}
//Dostêp do wielkoœci tablicy
int Array::GetSize()
{
	return Size;
}
//Czytanie danych z pliku
bool Array::ReadFromFile(string filename)
{
	int data,size;
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