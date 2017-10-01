using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

template<typename T>
size_t pocitadlo(stringstream s)
{
	return distance(istream_iterator<T>(s), istream_iterator<T>());
}

int main(int argc, char * argv[])
{
	size_t pocet;
	stringstream text;
	string aux;
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

		while (*pVstup >> text.rdbuf());
	}

	else
	{
		pVstup = &cin;
		cout << "Zadajte text:" << endl;
		
		while (*pVstup >> text.rdbuf());
	}

		if (argv[1] == string("-c"))
		{
			pocet = distance(istream_iterator<char>(text), istream_iterator<char>());
			cout << "Pocet znakov v texte :" << pocet << endl;
		}
		else if (argv[1] == string("-w"))
		{
			pocet = distance(istream_iterator<string>(text), istream_iterator<string>());
			cout << "Pocet slov v texte :" << pocet << endl;
		}
		else if (argv[1] == string("-l"))
		{
			aux = text.str();
			if (!aux.empty())pocet++;
			pocet = pocet + count(aux.begin(), aux.end(), '\n');
			cout << "Pocet riadkov v texte :" << pocet << endl;
		}

	system("PAUSE");
	return 0;
}