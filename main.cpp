using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

enum TokenizeOption {Znak, Slovo, Riadok};

template<typename T>
size_t pocitadlo(istream &s)
{
	return distance(istream_iterator<T>(s), istream_iterator<T>(s));
}

int main(int argc, char * argv[])
{
	size_t pocet;
	istream *pVstup=nullptr;

	if (argc < 2 || argc > 3)
	{
		cout << "Nebol zadany povinny argument!" << endl;
		cout << "Povinny argument je jeden z nasledujucich:" << endl;
		cout << "c - spocitanie znakov " << endl;
		cout << "w - spocitanie slov" << endl;
		cout << "l - spocitanie riadkov" << endl;
		
		system("pause");
		return 0;
	}

	if (argc == 3)
	{
		//nacitavanie zo suboru
	}

	else
	{
		//nacitavanie z konzoly
	}

	system("PAUSE");
	return 0;
}