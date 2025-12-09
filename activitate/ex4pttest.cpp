#include<iostream>
#include<string>
using namespace std;
enum clasificare {Manager=7,Incepator=8,Owner=9,Somer=10};
class Angajat 
{
	const int id;
	static int nrangajati;
	string nume;
	int nrsarcini;
	string* numesarcini;
	bool esteinvacanta;
	clasificare pozitii;
public:
	Angajat() :id(++nrangajati)
	{
		this->nume = "Necunoscut";
		this->nrsarcini = 0;
		this->numesarcini = nullptr;
		this->esteinvacanta = false;
		this->pozitii = Somer;
	}
	Angajat(string nume, int nrsarcini,string* numesarcini) :id(++nrangajati)
	{
		this->nume = nume;
		this->nrsarcini = nrsarcini;
		this->numesarcini = new string[this->nrsarcini];
		for (int i = 0; i < this->nrsarcini; i++)
		{
			this->numesarcini[i] = numesarcini[i];
		}
		this->esteinvacanta = false;
		this->pozitii = Somer;
	}
	Angajat(string nume,int nrsarcini,string* numesarcini,bool esteinvacanta,clasificare pozitii):id(++nrangajati)
	{ 
		this->nume = nume;
		this->nrsarcini = nrsarcini;
		this->numesarcini = new string[this->nrsarcini];
		for (int i = 0; i < this->nrsarcini; i++)
		{
			this->numesarcini[i] = numesarcini[i];
		}
		this->esteinvacanta = esteinvacanta;
		this->pozitii = pozitii;
	}
	Angajat(const Angajat& copie) :id(++nrangajati)
	{
		this->nume = copie.nume;
		this->nrsarcini = copie.nrsarcini;
		if (copie.nrsarcini > 0)
		{
			this->numesarcini = new string[this->nrsarcini];
			for (int i = 0; i < this->nrsarcini; i++)
			{
				this->numesarcini[i] = copie.numesarcini[i];
			}
		}
		else
		{
			this->nrsarcini = 0;
			this->numesarcini = nullptr;
		}
		this->esteinvacanta = copie.esteinvacanta;
		this->pozitii = copie.pozitii;
	}
	Angajat& operator=(const Angajat& copie)
	{
		if (this != &copie)
		{
			delete[]numesarcini;
			this->nume = copie.nume;
			this->nrsarcini = copie.nrsarcini;
			if (copie.nrsarcini > 0)
			{
				this->numesarcini = new string[this->nrsarcini];
				for (int i = 0; i < this->nrsarcini; i++)
				{
					this->numesarcini[i] = copie.numesarcini[i];
				}
			}
			else
			{
				this->nrsarcini = 0;
				this->numesarcini = nullptr;
			}
			this->esteinvacanta = copie.esteinvacanta;
			this->pozitii = copie.pozitii;
		}
		return*this;
	}
	const int getid() 
	{
		return this->id;
	}
	string getnume()
	{
		return this->nume;
	}
	int getnrsarcini()
	{
		return this->nrsarcini;
	}
	string* getnumesarcini()
	{
		return this->numesarcini;
	}
	bool getesteinvacanta()
	{
		return this->esteinvacanta;
	}
	clasificare getpozitii()
	{
		return this->pozitii;
	}
	void setnume(string nume)
	{
		this->nume = nume;
	}
	void setnrsarcini(int nrsarcini)
	{
		this->nrsarcini = nrsarcini;
	}
	void setnumesarcini(string* numesarcini, int nrsarcini)
	{
		delete[]this->numesarcini;
		this->nrsarcini = nrsarcini;
		if (this->nrsarcini > 0)
		{
			this->numesarcini = new string[this->nrsarcini];
			for (int i = 0; i < this->nrsarcini; i++)
			{
				this->numesarcini[i] = numesarcini[i];
			}
		}
		else
		{
			this->nrsarcini = 0;
			this->numesarcini = nullptr;
		}
	}
	void setesteinvacanta(bool esteinvacanta)
	{
		this->esteinvacanta = esteinvacanta;
	}
	void setpozitii(clasificare pozitii)
	{
		this->pozitii = pozitii;
	}
	void afisareAngajat()
	{
		
		cout << this->nume << " are ca nr de sarcini " << this->nrsarcini;
		if (this->nrsarcini != 0 || numesarcini!=nullptr)
		{
			cout << ".Acestea fiind: ";
			for (int i = 0; i < this->nrsarcini - 1; i++)
			{
				cout << this->numesarcini[i] << ",";
			}
			cout << this->numesarcini[this->nrsarcini - 1] << ".";
		}
		else
		{
			cout << " si nu are sarcini de facut.";
		}

		cout << "El are pozitia de";
		if (this->pozitii == Somer)cout << " Somer";
		if (this->pozitii == Incepator)cout << " Incepator";
		if (this->pozitii == Manager)cout << " Manager";
		if (this->pozitii == Owner)cout << " Owner";
		cout << " si este/nu in vacanta(1/0) " << this->esteinvacanta << ".";
		cout << endl << endl<<endl;
	}
	~Angajat()
	{
		delete[]numesarcini;
	}
};
int Angajat::nrangajati = 0;
int main()
{
	Angajat a1;
	a1.afisareAngajat();
	string* numesarcini1 = new string[4]{ "Revizuire proiect","De facut un nou proiect","De verificat statistica profitului","Analiza SWOT" };
	Angajat a2("Vasile Ghita",4,numesarcini1,true,Manager);
	a2.afisareAngajat();
	Angajat a3(a1);
	Angajat a4;
	a4 = a2;
	cout << endl << endl;
	for (int i = 0; i < a2.getnrsarcini(); i++)
	{
		cout << a2.getnumesarcini()[i] << ' ';
	}
	cout << endl << endl;
	a4.afisareAngajat();
	string* numesarcini2 = new string[5]{"De stat peste program ","Revizuire proiect","De facut un nou proiect","De verificat statistica profitului","Analiza SWOT" };
	a4.setnumesarcini(numesarcini2, 5);
	a3.afisareAngajat();
	a4.afisareAngajat();
	delete[]numesarcini1;
	delete[]numesarcini2;
}