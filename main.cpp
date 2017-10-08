using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include "Counter.h"
int main(int argc, char * argv[])
{
	size_t pocet;
	stringstream text;
	istream *pVstup;
	ifstream fs;

	if (argc < 2 || argc > 3)
	{
		cout << "Nebol zadany povinny argument!" << endl;
		cout << "Povinny argument je jeden z nasledujucich:" << endl;
		cout << "-c - spocitanie znakov " << endl;
		cout << "-w - spocitanie slov" << endl;
		cout << "-l - spocitanie riadkov" << endl;
		
		system("pause");
		return 0;
	}

	pocet = 0;

	if (argc == 3)
	{
		fs.open(argv[2]);

		if (!fs.is_open())
		{
			cout << "Zlyhanie otvorenia suboru." << endl;
			system("pause");
			return -1;
		}
		pVstup = &fs;
	}

	else
	{
		pVstup = &cin;
		cout << "Zadajte text:" << endl;
		
		while (*pVstup >> text.rdbuf());
	}

		if (argv[1] == string("-c"))
		{
			pocet = pocitadlo<char>(text);
			cout << "Pocet znakov v texte :" << pocet << endl;
		}
		else if (argv[1] == string("-w"))
		{
			pocet = pocitadlo<string>(text);
			cout << "Pocet slov v texte :" << pocet << endl;
		}
		else if (argv[1] == string("-l"))
		{
			pocet = pocitadlo<Line>(text);
			cout << "Pocet riadkov v texte :" << pocet << endl;
		}
		else
		{
			cout << "Zly prepinac!" << endl;
			return -1;
		}

	system("PAUSE");
	return 0;
}
