#include<iostream>
#include<string>
using namespace std;
enum Tip
{
	SEDAN = 8, Hedgeback = 9, limuzina = 10
};
class masina
{
	const int seriadesasiu;
	string nrinmatriculare;
	int nrdotari;
	string* dotari;
	float pret;
	Tip tip;
	static int nrmasini;
public:
	masina() :seriadesasiu(++nrmasini)
	{
		this->nrinmatriculare = "Necunoscut";
		this->nrdotari = 0;
		this->dotari = nullptr;
		this->pret = 0;
		this->tip = SEDAN;
	}
	masina(string nrinmatriculare, int nrdotari, string* dotari, float pret,Tip tip) :seriadesasiu(++nrmasini)
	{
		this->nrinmatriculare = nrinmatriculare;
		this->nrdotari = nrdotari;
		this->dotari = new string[this->nrdotari];
		for (int i = 0; i <this->nrdotari; i++)
		{
			this->dotari[i] = dotari[i];
		}
		this->tip = tip;
	}
	masina(const masina& copie):seriadesasiu(++nrmasini)
	{
		this->nrinmatriculare = copie.nrinmatriculare;
		this->nrdotari = copie.nrdotari;
		this->pret = copie.pret;
		this->tip = copie.tip;
		if (copie.dotari != nullptr)
		{
			this->dotari = new string[copie.nrdotari];
			for (int i = 0; i < copie.nrdotari; i++)
			{
				this->dotari[i] = copie.dotari[i];
			}
		}
		else
		{
			this->dotari = nullptr;
		}
	}
	string getnrmatricol()
	{
		return this->nrinmatriculare;
	}
	int getnrdotari()
	{
		return this->nrdotari;
	}
	string* getdotari()
	{

		string* copiemarci = new string[this->nrdotari];
		for (int i = 0; i < this->nrdotari; i++)
		{
			copiemarci[i] = this->dotari[i];
		}
		return copiemarci;
	}
	float getpret()
	{
		return this->pret;
	}
	Tip gettip()
	{
		return this->tip;
	}
	void setnrmatricol(string nrmatricol)
	{
		this->nrinmatriculare = nrinmatriculare;
	}
	void setnrdotari(int nrdotari)
	{
		this->nrdotari = nrdotari;
	}
	void setdotari(string* dotari, int nrdotari)
	{
		delete[] this->dotari;
		dotari = new string[nrdotari];
		for (int i = 0; i < this->nrdotari; i++)
		{
			this->dotari[i] = dotari[i];
		}

	}
	void setpret(float pret)
	{
		this->pret = pret;
	}
	void settip(Tip tip)
	{
		this->tip = tip;
	}
	void afisaremasina()
	{
		cout << "Masina are seria de sasiu " << this->seriadesasiu << " ,are nr de inmatriculare " << this->nrinmatriculare<<", fiind de tipul ";
		if (this->tip == SEDAN)
			cout << " sedan, ";
		if (this->tip == Hedgeback)
			cout << " hatchback, ";
		if (this->tip == limuzina)
			cout << " limuzina, ";
		cout << "avand nr de dotari " << this->nrdotari<<"acestea fiind: ";
		
		if (this->dotari != nullptr)
		{
			for (int i = 0; i < this->nrdotari-1; i++)
			{
				cout << this->dotari[i] <<", ";
			}
			cout << this->dotari[this->nrdotari - 1] << ".";
		}
		cout << endl;
	}
	~masina()
	{
		if (this->dotari != nullptr)
		{
			delete[] this->dotari;
		}
	}
};
int masina::nrmasini = 0;
int main()
{
	masina seria3;
	seria3.afisaremasina();
	string* dotari = new string[5]{ "scaune incalzite", "trapa", "lumini ambientale", "abs", "Head-up display"};
	masina* seria7 = new masina("B300ABC", 5, dotari, 50000,limuzina);
	seria7->afisaremasina();
	masina sclass(*seria7);
	sclass.afisaremasina();
	sclass.setnrdotari(7);
	cout << seria3.getnrdotari();
	cout << endl << endl;

	cout << sclass.getnrdotari();
	cout << endl << endl;
	seria3.getnrdotari();
	
	
	delete[] dotari;
	string *dotari1 = new string[7]{ "usb-c","Head up display","scaune incalzite","trapa in stele","sistem audio bool and olsen","abs","lumini ambientale" };
	masina* phantom = new masina("GL 250 ABC", 7, dotari1, 250000, limuzina);
	phantom->afisaremasina();
	delete seria7;

}