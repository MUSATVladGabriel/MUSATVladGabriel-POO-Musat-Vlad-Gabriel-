#include<iostream>
#include<string>
using namespace std;
enum Tip {Economie=7,Statistica=8,Informatica=9};
class Proiect
{
	const int id;
	static int nrproiecte;
	string nume;
	int nrparticipanti;
	string* numeparticipanti;
	float durata;
	Tip tip;
public:
	Proiect():id(++nrproiecte)
	{
		this->nume = "Necunoscut";
		this->nrparticipanti = 0;
		this->numeparticipanti = nullptr;
		this->durata = 0;
		this->tip = Economie;
	}
	Proiect(string nume, int nrparticipanti, string* numeparticipanti, float durata,Tip tip):id(++nrproiecte)
	{
		this->nume = nume;
		this->nrparticipanti = nrparticipanti;
		this->numeparticipanti = new string[this->nrparticipanti];
		for (int i = 0; i < this->nrparticipanti; i++)
		{
			this->numeparticipanti[i] = numeparticipanti[i];
		}
		this->durata = durata;
		this->tip = tip;
	}
	Proiect(const Proiect& copie) :id(++nrproiecte)
	{
		this->nume = copie.nume;
		this->nrparticipanti = copie.nrparticipanti;
		this->numeparticipanti = new string[copie.nrparticipanti];
		if (copie.numeparticipanti != nullptr)
		{
			for (int i = 0; i < copie.nrparticipanti; i++)
			{
				this->numeparticipanti[i] = copie.numeparticipanti[i];
			}
		}
		else
		{
			this->numeparticipanti = nullptr;
		}
		this->durata = copie.durata;
		this->tip = copie.tip;
	}
	string getnume()
	{
		return this->nume;
	}
	int getnrparticipanti()
	{
		return this->nrparticipanti;
	}
	float getdurata()
	{
		return this->durata;
	}
	Tip gettip()
	{
		return this->tip;
	}
	string* getnumeparticipanti()
	{
		string* copienume=new string[this->nrparticipanti];
		for (int i = 0; i < this->nrparticipanti; i++)
		{
			copienume[i] = this->numeparticipanti[i];
		}
		return copienume;
	}
	void setnumeparticipanti(string* numeparticipanti, int nrparticipanti)
	{
		delete[]numeparticipanti;
		this->nrparticipanti = nrparticipanti;
		this->numeparticipanti = new string[this->nrparticipanti];
		for (int i = 0; i < this->nrparticipanti; i++)
		{
			this->numeparticipanti[i] = numeparticipanti[i];
		}
	}
	void setnume(string nume)
	{
		this->nume = nume;
	}
	void settip(Tip tip)
	{
		this->tip = tip;
	}
	void afisareProiect()
	{
		cout << "Proiectul cu numele " << this->nume << " a avut nr de participanti de " << this->nrparticipanti << " a fost despre ";
		if (this->tip == Economie)  cout << "Economie "; 
		if (this->tip == Statistica)  cout << "Statistica"; 
		if (this->tip == Informatica)  cout << "Informatica "; 
		cout << " si a durat " << this->durata<<".";
		cout << "Acesta a fost realizat de: ";
		if (this->numeparticipanti != nullptr) 
		{
			for (int i = 0; i < this->nrparticipanti - 2; i++)
			{
				cout << this->numeparticipanti[i] << ",";
			}
			cout << " " << this->numeparticipanti[nrparticipanti - 2] << " si " << this->numeparticipanti[nrparticipanti - 1] << ".";
		}
		else
		{
			cout << "Nimeni.";
		}
		cout << endl << endl;
	}
	float operator=(Proiect pr)
	{
		return this->durata = pr.durata;
	}
	~Proiect()
	{
		delete[]numeparticipanti;
	}
};
int Proiect::nrproiecte = 0;
int main()
{
	Proiect p;
	p.afisareProiect();
	string* numeparticipanti = new string[3]{ "Steluta Mihai","Olaru Darius","Petrila Claudiu" };
	string* numeparticipanti1 = new string[3]{ "Alex Dobre","Olaru Darius","Petrila Claudiu" };
	Proiect* java = new Proiect("informatii generale despre limbaje de programare", 3, numeparticipanti, 50.30, Informatica);
	java->afisareProiect();
	Proiect python(*java);
	python.afisareProiect();
	Proiect* C=new Proiect("informatii generale despre limbajul de programare C", 3, numeparticipanti1, 50.40, Informatica);
	C->afisareProiect();
	*C = python;
	C->afisareProiect();
	p.settip(Statistica);
	p.afisareProiect();
	delete[]numeparticipanti;
	delete[]numeparticipanti1;
	delete C;
	delete java;
	return 0;
}
