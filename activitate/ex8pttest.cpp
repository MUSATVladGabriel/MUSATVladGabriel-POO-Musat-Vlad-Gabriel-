#include<iostream>
#include<string>

using namespace std;
enum pozitie{Atacant=9,Mijlocas=11,Fundas=12,Portar=13};
class Jucatordefotbal 
{
	const int idjucator;
	static int nrjucatori;
	char* tara;
	string nume;
	int nrcluburi;
	string* numecluburi;
	int* nraparente;
	bool acastigatbalonuldeaur;
	pozitie pozitii;
public:
	Jucatordefotbal() :idjucator(++nrjucatori)
	{
		this->tara = new char[strlen("X") + 1];
		strcpy(this->tara, "X");
		this->nume = "Anonim";
		this->nrcluburi = 0;
		this->numecluburi = nullptr;
		this->nraparente = nullptr;
		this->acastigatbalonuldeaur = false;
		this->pozitii = Portar;
	}
	Jucatordefotbal(const char* tara,bool acastigatbalonuldeaur) :idjucator(++nrjucatori)
	{
		if (strlen(tara) > 1)
		{
			this->tara = new char[strlen(tara) + 1];
			strcpy(this->tara, tara);
		}
		else
		{
			this->tara = new char[strlen("X") + 1];
			strcpy(this->tara, "X");
		}
		this->nume = "Anonim";
		this->nrcluburi = 0;
		this->numecluburi = nullptr;
		this->nraparente = nullptr;
		this->acastigatbalonuldeaur = acastigatbalonuldeaur;
		this->pozitii = Portar;
	}
	Jucatordefotbal(const char* tara,string nume,int nrcluburi,string* numecluburi,int* nraparente, bool acastigatbalonuldeaur,pozitie pozitii) :idjucator(++nrjucatori)
	{
		if (strlen(tara) > 1)
		{
			this->tara = new char[strlen(tara) + 1];
			strcpy(this->tara, tara);
		}
		else
		{
			this->tara = new char[strlen("X") + 1];
			strcpy(this->tara, "X");
		}
		if (nume.size() >= 3)
		{
			this->nume = nume;
		}
		else
		{
			this->nume = "Anonim";
		}
		if (nrcluburi > 0 && numecluburi != nullptr && nraparente != nullptr)
		{
			this->nrcluburi = nrcluburi;
			this->numecluburi = new string[this->nrcluburi];
			this->nraparente = new int[this->nrcluburi];
			for (int i = 0; i < this->nrcluburi; i++)
			{
				this->numecluburi[i] = numecluburi[i];
				this->nraparente[i] = nraparente[i];
			}
		}
		else
		{
			this->nrcluburi = 0;
			this->numecluburi = nullptr;
			this->nraparente = nullptr;
		}
		this->acastigatbalonuldeaur = acastigatbalonuldeaur;
		this->pozitii =pozitii;
	}
	const char* gettara() const
	{
		return this->tara;
	}
	string* getnumecluburi()
	{
		string* copienumecluburi = new string[this->nrcluburi];
		for (int i = 0; i < this->nrcluburi; i++)
		{
			copienumecluburi[i] = this->numecluburi[i];
		}
		return copienumecluburi;
	}
	void setcluburi(int nrcluburi, string* numecluburi, int* nraparente)
	{
		delete[]this->numecluburi;
		delete[]this->nraparente;
		if (nrcluburi > 0 && numecluburi != nullptr && nraparente != nullptr)
		{
			this->nrcluburi = nrcluburi;
			this->numecluburi = new string[this->nrcluburi];
			this->nraparente = new int[this->nrcluburi];
			for (int i = 0; i < this->nrcluburi; i++)
			{
				this->nraparente[i] = nraparente[i];
				this->numecluburi[i] = numecluburi[i];
			}
		}
	}
	Jucatordefotbal(const Jucatordefotbal& j) :idjucator(++nrjucatori)
	{
		if (strlen(j.tara) > 1)
		{
			this->tara = new char[strlen(j.tara) + 1];
			strcpy(this->tara, j.tara);
		}
		
		if (j.nume.size() >= 3)
		{
			this->nume =j. nume;
		}
		
		if (j.nrcluburi > 0 && j.numecluburi != nullptr && j.nraparente != nullptr)
		{
			this->nrcluburi = nrcluburi;
			this->numecluburi = new string[this->nrcluburi];
			this->nraparente = new int[this->nrcluburi];
			for (int i = 0; i < this->nrcluburi; i++)
			{
				this->numecluburi[i] = numecluburi[i];
				this->nraparente[i] = nraparente[i];
			}
		}
		else
		{
			this->nrcluburi = 0;
			this->numecluburi = nullptr;
			this->nraparente = nullptr;
		}
		this->acastigatbalonuldeaur = j.acastigatbalonuldeaur;
		this->pozitii = j.pozitii;
	}
	Jucatordefotbal& operator=(const Jucatordefotbal& ju)
	{
		if (this != &ju)
		{
			if (strlen(ju.tara) > 1)
			{
				this->tara = new char[strlen(ju.tara) + 1];
				strcpy(this->tara, ju.tara);
			}

			if (ju.nume.size() >= 3)
			{
				this->nume = ju.nume;
			}

			if (ju.nrcluburi > 0 && ju.numecluburi != nullptr && ju.nraparente != nullptr)
			{
				this->nrcluburi = nrcluburi;
				this->numecluburi = new string[this->nrcluburi];
				this->nraparente = new int[this->nrcluburi];
				for (int i = 0; i < this->nrcluburi; i++)
				{
					this->numecluburi[i] = numecluburi[i];
					this->nraparente[i] = nraparente[i];
				}
			}
			else
			{
				this->nrcluburi = 0;
				this->numecluburi = nullptr;
				this->nraparente = nullptr;
			}
			this->acastigatbalonuldeaur = ju.acastigatbalonuldeaur;
			this->pozitii = ju.pozitii;
		}
		return *this;
	}
	void afisare()
	{
		cout << this->idjucator << endl;
		cout << this->nume << endl;
		cout << this->tara << endl;
		cout << this->nrcluburi << endl;
		for (int i = 0; i < this->nrcluburi; i++)
		{
			cout << this->numecluburi[i] << ",";
		}
		cout << endl;
		for (int i = 0; i < this->nrcluburi; i++)
		{
			cout << this->nraparente[i] << ",";
		}
		cout << endl;
		cout <<"DA/Nu(1/0)"<< this->acastigatbalonuldeaur << endl;
		if (this->pozitii == Atacant)cout << "Atacant";
		if (this->pozitii == Mijlocas)cout << "Mijlocas";
		if (this->pozitii == Fundas)cout << "Fundas";
		if (this->pozitii == Portar)cout << "Portar";
	}
	void adaugaclub(string nume, int nraparente)
	{
		int copienrcluburi = this->nrcluburi;
		string* copienumecluburi = new string[copienrcluburi];
		int* copienraparente = new int[copienrcluburi];
		for (int i = 0; i < copienrcluburi; i++)
		{
			copienraparente[i] = this->nraparente[i];
			copienumecluburi[i] = this->numecluburi[i];
		}
		delete[]this->numecluburi;
		delete[]this->nraparente;
		this->nrcluburi++;
		this->numecluburi = new string[this->nrcluburi];
		this->nraparente = new int[this->nrcluburi];
		for (int i = 0; i < copienrcluburi; i++)
		{
			this->numecluburi[i] = copienumecluburi[i];
			this->nraparente[i] = copienraparente[i];
		}
		this->numecluburi[this->nrcluburi - 1] = nume;
		this->nraparente[this->nrcluburi - 1] = nraparente;
		delete[]copienraparente;
		delete[]copienumecluburi;
	}
	void eliminaclub(string nume, int nraparente)
	{
		int nrcluburigasite = 0;
		for (int i = 0; i < this->nrcluburi; i++)
		{
			if (this->numecluburi[i] == nume && this->nraparente[i] == nraparente)
			{
				nrcluburigasite++;
			}
		}
		int copienrcluburi = this->nrcluburi;
		string* copienumecluburi = new string[copienrcluburi];
		int* copienraparente = new int[copienrcluburi];
		for (int i = 0; i < copienrcluburi; i++)
		{
			copienumecluburi[i] = this->numecluburi[i];
			copienraparente[i] = this->nraparente[i];
		}
		delete[]this->numecluburi;
		delete[]this->nraparente;
		this->nrcluburi = copienrcluburi - nrcluburigasite;
		this->numecluburi = new string[this->nrcluburi];
		this->nraparente = new int[this->nrcluburi];
		int pozitie = 0;
		for (int i = 0; i < copienrcluburi; i++)
		{
			if (copienumecluburi[i] != nume || copienraparente[i] != nraparente)
			{
				this->numecluburi[pozitie] = copienumecluburi[i];
				this->nraparente[pozitie] = copienraparente[i];
				pozitie++;
			}
		}
		delete[]copienraparente;
		delete[]copienumecluburi;
	}
	~Jucatordefotbal()
	{
		delete[]this->numecluburi;
		delete[]this->nraparente;
	}

};
int Jucatordefotbal::nrjucatori = 0;
int main()
{
	Jucatordefotbal j1;
	Jucatordefotbal j2("Romania", true);
	j1.afisare();
	cout << endl << endl;
	j2.afisare();
	cout << endl << endl;
	string numecluburi1[] = { "FCSB","Dinamo","FC Barcelona","Real Madrid" };
	int nraparente1[] = { 100,60,254,353 };
	Jucatordefotbal j3("Romania", "Gheorghe Hagi", 4, numecluburi1, nraparente1, true, Mijlocas);
	j3.afisare();
	j3.adaugaclub("Galatasaray", 454);
	cout << endl << endl;
	j3.afisare();
	j3.eliminaclub("Dinamo", 60);
	cout << endl << endl;
	j3.afisare();
	Jucatordefotbal j4(j2);
	cout << endl << endl;
	j4.afisare();
	cout << endl << endl;
	Jucatordefotbal j5("Spania", true);
	j5.afisare();
	cout << endl << endl;
	j5 = j3;
	j5.afisare();
}