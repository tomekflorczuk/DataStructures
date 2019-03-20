#include "Menu.h"
#include "Main.h"

//Funkcje
long long int Main::ReadQPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}

//Program glowny
void main()
{
	Menu::ShowMainMenu();
}