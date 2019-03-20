#include "Menu.h"
#include "ArrayMenu.h"
#include "Array.h"
#include "List.h"
#include "ListMenu.h"
#include "HeapMenu.h"
#include "Heap.h"
#include "BSTTree.h"
#include "BSTTreeMenu.h"

//Wyœwietl menu g³ówne
void Menu::ShowMainMenu()
{
	int choice;
	do
	{
		system("CLS");
		cout << "Wybierz strukture danych: " << endl;
		cout << "1)Tablica dynamiczna" << endl;
		cout << "2)Lista" << endl;
		cout << "3)Kopiec" << endl;
		cout << "4)Drzewo BST" << endl;
		cout << "5)Drzewo czerwono-czarne" << endl;
		cout << "6)Zamknij" << endl;

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
		//Tablica
		case(1):
			{
				switch (ShowInputMenu())
					{
					//Przypadek generowania danych
					case(1):
						{
							int amount;

							cout << "Podaj ilosc danych do wygenerowania: ";
							cin >> amount;
							Array tablica(amount);
							ArrayMenu::ShowArrayMenu(tablica);
							break;
						}
					//Przypadek czytania z pliku
					case(2):
						{
							string filename;
							bool success;

							do
							{
								cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane(dodaj .txt):" << endl;
								cout << "Wpisz 0 by wyjsc" << endl;
								cin >> filename;
								if (filename == "0") exit(0);
								Array tablica;
								success = tablica.ReadFromFile(filename);
								if(success == true) ArrayMenu::ShowArrayMenu(tablica);
							} while (success == false);
						break;
						}
						default: break;
						}
			}
		//Lista
		case(2):
			{
				switch (ShowInputMenu())
				{
					//Przypadek generowania danych
					case(1):
						{
							int amount;

							cout << "Podaj ilosc danych do wygenerowania: ";
							//amount = Main::InputControl();
							cin >> amount;
							List lista(amount);
							ListMenu::ShowListMenu(lista);
							break;
						}
					//Przypadek czytania z pliku
					case(2):
						{
						string filename;
						bool success;

						do
						{
							cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane(dodaj .txt):" << endl;
							cout << "Wpisz 0 by wyjsc" << endl;
							cin >> filename;
							if (filename == "0") exit(0);
							List lista;
							success = lista.ReadFromFile(filename);
							if (success == true) ListMenu::ShowListMenu(lista);
						} while (success == false);
						break;
						}
					default: break;
				}
			}
		//Kopiec
		case(3):
			{
				switch (ShowInputMenu())
				{
					//Przypadek generowania danych
					case(1):
					{
						int amount;

						cout << "Podaj ilosc danych do wygenerowania: ";
						cin >> amount;
						Heap kopiec(amount);
						HeapMenu::ShowHeapMenu(kopiec);
						break;
					}
					//Przypadek czytania z pliku
					case(2):
					{
						string filename;
						bool success;

						do
						{
							cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane(dodaj .txt):" << endl;
							cout << "Wpisz 0 by wyjsc" << endl;
							cin >> filename;
							if (filename == "0") exit(0);
							Heap kopiec;
							success = kopiec.ReadFromFile(filename);
							if (success == true) HeapMenu::ShowHeapMenu(kopiec);
						} while (success == false);
						break;
					}
					default: break;
				}
			}
		//Drzewo
		case(4):
			{
				switch (ShowInputMenu())
				{
				//Przypadek generowania danych
				case(1):
				{
					int amount;

					cout << "Podaj ilosc danych do wygenerowania: ";
					cin >> amount;
					BSTTree drzewo(amount);
					BSTTreeMenu::ShowBSTTreeMenu(drzewo);
				}
				//Przypadek czytania z pliku
				case(2):
				{
					string filename;
					bool success;

					do
					{
						cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane(dodaj .txt):" << endl;
						cout << "Wpisz 0 by wyjsc" << endl;
						cin >> filename;
						if (filename == "0") exit(0);
						BSTTree drzewo;
						success = drzewo.ReadFromFile(filename);
						if (success == true) BSTTreeMenu::ShowBSTTreeMenu(drzewo);
					} while (success == false);
					break;
				}
				default: break;
				}
			}
		//Drzewo czerowno-czarne
		case(5):
			{
			cout << "Nie zaimplementowano" << endl;
			system("pause");
			break;
			}
		case(6): exit(0);
		default:
			{
				cout << "Bledy wybor" << endl;
				system("pause");
				break;
			}
		}
	}
	while (choice != 6);
}
//Wyœwietl menu wprowadzania danych
int Menu::ShowInputMenu()
{
	int choice;
	do
	{
		cout << "Podaj metode pobrania danych wejsciowych:" << endl;
		cout << "1)Losowo wygenerowane" << endl;
		cout << "2)Plik" << endl;
		cout << "3)Cofnij" << endl;
		cout << "4)Wyjdz" << endl;

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
		//Losowo generowane
		case(1):
		{
			return 1;
		}
		//Czytanie z pliku
		case(2):
		{
			return 2;
		}
		case(3): ShowMainMenu();
		case(4): exit(0);
		default:
		{
			cout << "Podano zla liczbe" << endl;
			break;
		}
		}
	}
	while (choice != 3);
}