#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Banca
{
	string denumire;
	char* locatie;
	int nrAngajati;
	bool areProfit;
public:
	Banca()
	{
		this->denumire = "Necunoscut";
		this->locatie = new char[strlen("X") + 1];
		strcpy(this->locatie, "X");
		this->nrAngajati = 0;
		this->areProfit = true;
	}
	Banca(string denumire, const char* locatie, int nrAngjati, bool areProfit)
	{
		this->denumire = denumire;
		this->locatie = new char[strlen(locatie) + 1];
		strcpy(this->locatie, locatie);
		this->nrAngajati = nrAngjati;
		this->areProfit = areProfit;
	}
	~Banca()
	{
		if (this->locatie != nullptr)
			delete[]this->locatie;
	}
	friend ostream& operator<<(ostream& out,const Banca& b)
	{
		out <<"Denumire:" <<b.denumire << endl;
		out <<"Nr angajati: "<<b.nrAngajati << endl;
		out <<"Locatie: "<< b.locatie << endl;
		out << (b.areProfit?"Are profit":"Nu are profit");
		return out;
	}
	friend ostream& operator<<(fstream& fout, Banca b)
	{
		fout << endl<<"Denumire:" << b.denumire << endl;
		fout << "Nr angajati: " << b.nrAngajati << endl;
		fout << "Locatie: " << b.locatie << endl;
		fout << (b.areProfit ? "Are profit" : "Nu are profit");
		return fout;
	}
	friend istream& operator>>(ifstream& fin, Banca& b1)
	{
		fin >>b1.denumire;
		fin >> b1.nrAngajati;
		if (b1.locatie != nullptr)
		{
			delete[]b1.locatie;
			b1.locatie = nullptr;
		}
		char copie[30];
		fin >> copie;
		b1.locatie = new char[strlen(copie) + 1];
		strcpy(b1.locatie, copie);
			fin >> b1.areProfit;
			return fin;
	}
};

int main()
{
	Banca b;
	Banca b1("BCR", "Calea Victoriei", 8, true);
	//fstream fileStream("Banca.txt", ios::out);
	//fileStream << b1;
	//fileStream.close();
	ifstream inputfileStream("Banca.txt", ios::in);
	inputfileStream >> b;
	inputfileStream.close();
	cout << b;
	cout << b << endl << endl;
	cout << b1 << endl << endl;
	return 0;
	//test operatori,try-catch si atributele constante si statice
}
