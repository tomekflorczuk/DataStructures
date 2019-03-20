#include "HeapMenu.h"
#include "Heap.h"
#include "Main.h"
#include "Menu.h"

void HeapMenu::ShowHeapMenu(Heap kopiec)
{
	int choice;
	ofstream file;
	file.open("czasy.txt");
	do
	{
		cout << "Podaj operacje do wykonania: " << endl;
		cout << "1)Dodawanie" << endl;
		cout << "2)Usuwanie" << endl;
		cout << "3)Wyszukiwanie" << endl;
		cout << "4)Wyswietlenie" << endl;
		cout << "5)Cofnij" << endl;
		cout << "6)Wyjdz" << endl;

		cin >> choice;
		//Sprawdzenie czy zosta³a wprowadzona liczba
		if (cin.fail())
		{
			cout << "Nie podano liczby" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("pause");
			continue;
		}

		switch (choice)
		{
		//Dodawanie
		case(1):
			{
				long long int frequency, start, elapsed;
				int number;

				cout << "Podaj liczbe do dodania: ";
				cin >> number;

				QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
				start = Main::ReadQPC();

				kopiec.Add(number);

				elapsed = Main::ReadQPC() - start;
				cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
					frequency << endl;

				file << (1000.0 * elapsed) / frequency << endl;

				break;
			}
		//Usuwanie
		case(2):
			{
			long long int frequency, start, elapsed;


			QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			start = Main::ReadQPC();

			kopiec.Erase();

			elapsed = Main::ReadQPC() - start;
			cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
				frequency << endl;

			file << (1000.0 * elapsed) / frequency << endl;

			break;
			}
		//Wyszukiwanie
		case(3):
			{
			long long int frequency, start, elapsed;
			int number;

			cout << "Podaj liczbe ktorej szukasz: ";
			cin >> number;

			QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			start = Main::ReadQPC();

			kopiec.Search(number);

			elapsed = Main::ReadQPC() - start;
			cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
				frequency << endl;

			file << (1000.0 * elapsed) / frequency << endl;

			break;
			}
		//Wyœwietlanie
		case(4):
			{
			long long int frequency, start, elapsed;

			QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
			start = Main::ReadQPC();

			kopiec.Show("", "", 0);

			elapsed = Main::ReadQPC() - start;
			cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
				frequency << endl;

			break;
			}
		case(5):
			{
			Menu::ShowMainMenu();

			break;
			}
		case(6): exit(0);
		default:
			{
				cout << "Podano zla liczbe" << endl;
				system("pause");
				break;
			}
		}
	}
	while (choice != 6);
}