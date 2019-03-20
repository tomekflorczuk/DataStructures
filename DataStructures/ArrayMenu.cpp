#include "ArrayMenu.h"
#include "Array.h"
#include "Menu.h"

void ArrayMenu::ShowArrayMenu(Array tablica)
{
	int choice;
	ofstream file;
	file.open("czasy.txt");
	do
	{
		cout << "Podaj operacje do wykonania: " << endl;
		cout << "1)Dodawanie na poczatek" << endl;
		cout << "2)Dodawanie na koniec" << endl;
		cout << "3)Dodawanie w konkretne miejsce" << endl;
		cout << "4)Usuwanie z poczatku" << endl;
		cout << "5)Usuwanie z konca" << endl;
		cout << "6)Usuwanie z konkretnego miejsca" << endl;
		cout << "7)Wyszukiwanie" << endl;
		cout << "8)Wyswietlenie" << endl;
		cout << "9)Cofnij" << endl;
		cout << "10)Wyjdz" << endl;

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
			//Dodawania na pocz¹tek
			case(1):
				{
					long long int frequency, start, elapsed;
					int number;

					cout << "Podaj liczbe do dodania: ";
					cin >> number;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.AddFront(number);

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
			}
			//Dodawanie na koniec
			case(2):
				{
					long long int frequency, start, elapsed;
					int number;

					cout << "Podaj liczbe do dodania: ";
					cin >> number;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.AddBack(number);

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
				}
			//Dodawanie w konkretne miejsce
			case(3):
				{
					long long int frequency, start, elapsed;
					int number, index;

					cout << "Podaj liczbe do dodania: ";
					cin >> number;
					cout << "Podaj index wstawienia liczby(od 0): ";
					cin >> index;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.AddSpecific(number, index);

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
				}
			//Usuniêcie z pocz¹tku
			case(4):
				{
					long long int frequency, start, elapsed;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.EraseFront();

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
				}
			//Usuniêcie z koñca
			case(5):
				{
					long long int frequency, start, elapsed;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.EraseBack();

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
				}
			//Usuniêcie z konkretnego miejsca
			case(6):
				{
					long long int frequency, start, elapsed;
					int index;

					cout << "Podaj index usuniecia liczby(od 0): ";
					cin >> index;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.EraseSpecific(index);

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
				}
			//Wyszukiwanie
			case(7):
				{
					long long int frequency, start, elapsed;
					int number;

					cout << "Podaj liczbe ktorej szukasz: ";
					cin >> number;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.Search(number);

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
				}
			//Wyœwietlenie
			case(8):
				{
					long long int frequency, start, elapsed;

					QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
					start = Main::ReadQPC();

					tablica.Show();

					elapsed = Main::ReadQPC() - start;
					cout << "Czas wykonania [ms] = " << setprecision(0) << (1000.0 * elapsed) /
						frequency << endl;

					file << (1000.0 * elapsed) / frequency << endl;
					break;
				}
			//Powrót
			case(9):
			{
				Menu::ShowMainMenu();
				break;
			}
		case(10): exit(0);
		default:
			{
				cout << "Podano zla liczbe" << endl;
				system("pause");
				break;
			}
		}
	}
	while (choice != 9);
	file.close();
}