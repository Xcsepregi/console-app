using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void kontrola_textu(string retazec, int vstup)
{
	int prepinac_rezim, pocet;
	int dlzka = retazec.length();
	char vstup_rezim, option;
	const char *text = retazec.c_str();
	bool valid_vstup;

	pocet = 0;

	do
	{
		cout << "Zadajte prepinac:";
		cout << endl << "c - spocitanie znakov " << endl << "w - spocitanie slov" << endl << "l - spocitanie riadkov" << endl;
		cout << "Volba:";
		cin >> option;

		if ((int)option == 99)
		{
			prepinac_rezim = 1;
			valid_vstup = true;
		}
		else if ((int)option == 119)
		{
			prepinac_rezim = 2;
			valid_vstup = true;
		}
		else if ((int)option == 108)
		{
			prepinac_rezim = 3;
			valid_vstup = true;
		}
	} while (!valid_vstup);

	if (prepinac_rezim == 1)
	{
		for (int i = 0; i < dlzka; i++)
		{
			if ((int)text[i] != 0) pocet++;
		}

		cout << "Text obsahuje " << pocet << " znakov." << endl;
	}

	if (prepinac_rezim == 2)
	{
		//dorobime
	}

	if (prepinac_rezim == 3)
	{
		if (!retazec.empty())
		{
			pocet = 1;
		}

		if (vstup == 1)
		{
			for (int i = 0; i < dlzka; i++)
			{
				if ((int)text[i] == 92)
				{
					if ((int)text[i + 1] == 110) pocet++;
				}
			}

			if (pocet == 1)cout << "Text obsahuje 1 riadok." << endl;
			else if (pocet>1 && pocet<5)cout << "Text obsahuje " << pocet << " riadky." << endl;
			else cout << "Text obsahuje " << pocet << " riadkov." << endl;
		}

		else if (vstup == 2)
		{
			for (int i = 0; i < dlzka; i++)
			{
				if ((int)text[i] == 10) pocet++;
			}

			if (pocet == 1)cout << "Text obsahuje 1 riadok." << endl;

			else cout << "Text obsahuje " << pocet << " riadkov." << endl;
		}
	}

}

int main()
{
	int prepinac_rezim, prepinac_vstup, option;
	bool stav, input, kontrola;
	string text, filename;

	stav = true;
	kontrola = input = false;

	do
	{
		cout << "Zadajte meno suboru: ";
		getline(cin, filename);

		if (filename.empty())
		{
			cout << "Nezadali ste nazov subora, prechadzam na vstup z konzoly!" << endl;
			cout << "Zadajte text:" << endl;
			getline(cin, text);

			if (text.empty())
			{
				cout << endl << "Zadali ste prazdny vstup, program sa skonci. Dovidenia."<<endl;
				break;
			}
			else
			{
				kontrola_textu(text, 1);
				kontrola = true;
				getchar();
			}
		}

		ifstream subor(filename.c_str(), fstream::in);
		if (!subor.is_open() && !kontrola)
		{
			cout << "Otvorenie suboru zlyhalo, skuste iny subor!" << endl;
		}
		else input = true;

		if (input && (!kontrola))
		{
			text.assign((istreambuf_iterator<char>(subor)), istreambuf_iterator<char>());
			kontrola_textu(text, 2);
			getchar();
		}

		kontrola = false;
	} while (stav);

	system("PAUSE");
	return 0;
}