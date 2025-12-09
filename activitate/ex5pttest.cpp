#include<iostream>
#include<string>
using namespace std;
enum Tip{Informatica=7,Relatiicupublicu=8,Economie=9};
class Departament
{
	const int id;
	static int nrdepartamente;
	string numecompanii;
	int nrangajati;
	string* numeangajati;
	float* salariiangajati;
	bool arecalculatoaredeultimageneratie;
	Tip tip;
public:
	Departament() :id(++nrdepartamente)
	{
		this->numecompanii = "Necunoscut";
		this->nrangajati = 0;
		this->numeangajati = nullptr;
		this->salariiangajati = nullptr;
		this->arecalculatoaredeultimageneratie = false;
		this->tip = Relatiicupublicu;
	}
	Departament(string numecompanii, int nrangajati, string* numeangajati, float* salariiangajati, bool arecalculatoaredeultimageneratie, Tip tip) :id(++nrdepartamente)
	{
		this->numecompanii = numecompanii;
		this->nrangajati = nrangajati;
		if (nrangajati > 0)
		{
			this->numeangajati = new string[this->nrangajati];
			for (int i = 0; i < this->nrangajati; i++)
			{
				this->numeangajati[i] = numeangajati[i];
			}
			this->salariiangajati = new float[this->nrangajati];
			for (int i = 0; i < this->nrangajati; i++)
			{
				this->salariiangajati[i] = salariiangajati[i];
			}
		}
		else
		{
			this->nrangajati = 0;
			this->numeangajati = nullptr;
			this->salariiangajati = nullptr;
		}
		this->arecalculatoaredeultimageneratie = arecalculatoaredeultimageneratie;
		this->tip = tip;
	}
	Departament(const Departament& d) :id(++nrdepartamente)
	{
		this->numecompanii =d.numecompanii;
		this->nrangajati =d.nrangajati;
		if (d.nrangajati > 0)
		{
			this->numeangajati = new string[this->nrangajati];
			for (int i = 0; i < this->nrangajati; i++)
			{
				this->numeangajati[i] =d.numeangajati[i];
			}
			this->salariiangajati = new float[this->nrangajati];
			for (int i = 0; i < this->nrangajati; i++)
			{
				this->salariiangajati[i] = d.salariiangajati[i];
			}
		}
		else
		{
			this->nrangajati = 0;
			this->numeangajati = nullptr;
			this->salariiangajati = nullptr;
		}
		this->arecalculatoaredeultimageneratie =d. arecalculatoaredeultimageneratie;
		this->tip =d.tip;
	}
	float* getsalariiangajati()
	{
		return this->salariiangajati;
	}
	string* getnumeangajati()
	{
		return this->numeangajati;
	}
	int getnrangajati()
	{
		return this->nrangajati;
	}
	void setnrangajati(int nrangajati)
	{
		this->nrangajati = nrangajati;
	}
	void setangajati(string* numeangajati, float* salariiangajati, int nrangajati)
	{
		delete[]this->numeangajati;
		delete[]this->salariiangajati;
		this->nrangajati = nrangajati;
		this->numeangajati = new string[this->nrangajati];
		for (int i = 0; i < this->nrangajati; i++)
		{
			this->numeangajati[i] = numeangajati[i];
		}
		this->salariiangajati = new float[this->nrangajati];
		for (int i = 0; i < this->nrangajati; i++)
		{
			this->salariiangajati[i] = salariiangajati[i];
		}
	}
	Departament& operator=(const Departament& de)
	{
		if (this != &de)
		{
			delete[]this->numeangajati;
			delete[]this->salariiangajati;
			this->numecompanii = de.numecompanii;
			this->nrangajati = de.nrangajati;
			if (de.nrangajati > 0)
			{
				this->numeangajati = new string[this->nrangajati];
				for (int i = 0; i < this->nrangajati; i++)
				{
					this->numeangajati[i] = de.numeangajati[i];
				}
				this->salariiangajati = new float[this->nrangajati];
				for (int i = 0; i < this->nrangajati; i++)
				{
					this->salariiangajati[i] = de.salariiangajati[i];
				}
			}
			else
			{
				this->nrangajati = 0;
				this->numeangajati = nullptr;
				this->salariiangajati = nullptr;
			}
			this->arecalculatoaredeultimageneratie = de.arecalculatoaredeultimageneratie;
			this->tip = de.tip;
		}
		return *this;
	}
	
	void afisareDepartament()
	{
		cout << "Departamentul de la " << this->numecompanii << " are nr de angajati de " << this->nrangajati;
		if (this->nrangajati > 0 ||this->numeangajati!=nullptr || this->salariiangajati != nullptr)
		{
			float s = 0;
			
			cout << ".Numele lor sunt: ";
			for (int i = 0; i < this->nrangajati - 1; i++)
			{
				cout << this->numeangajati[i] << ",";
			}
			cout << this->numeangajati[this->nrangajati - 1] << ".Salariul mediu al unui salariat din acest departament este ";
			for (int i = 0; i < this->nrangajati; i++)
			{
				s += this->salariiangajati[i];
			}
			cout << s /this->nrangajati ;
		}
		else
		{
			cout << " nu are angajati.";
		}
			cout << ".Departamentul este de tipul ";
			if (this->tip == Informatica)cout << "Informatica ";
			if (this->tip == Economie)cout << "Economie ";
			if (this->tip == Relatiicupublicu)cout << "Relatii cu publicu ";
			cout << "si are/nu are calculatoare de ultima generatie(1/0)" << this->arecalculatoaredeultimageneratie;
		
	}
	void adaugaangajat(string nume,float salariu)
	{
		int copienrangajati = this->nrangajati;
		
		string* copienume = new string[copienrangajati];
		float* copiesalarii = new float[copienrangajati];
		for (int i = 0; i < copienrangajati; i++)
		{
			copienume[i] = this->numeangajati[i];
			copiesalarii[i] = this->salariiangajati[i];
		}
		delete[]this->numeangajati;
		delete[] this->salariiangajati;
		this->nrangajati++;
		this->numeangajati = new string[this->nrangajati];
		this->salariiangajati = new float[this->nrangajati];
		for (int i = 0; i <copienrangajati; i++)
		{
			this->numeangajati[i] = copienume[i];
			this->salariiangajati[i] = copiesalarii[i];
		}
		this->numeangajati[this->nrangajati - 1] = nume;
		this->salariiangajati[this->nrangajati - 1] =salariu;
		delete[]copienume;
		delete[]copiesalarii;

	}
	void eliminaangajat()
	{
		if (nrangajati > 1)
		{
			this->nrangajati = nrangajati - 1;
		}
	}
	~Departament()
	{
		delete[]numeangajati;
		delete[]salariiangajati;
	}
};
int Departament::nrdepartamente = 0;
int main() {
	Departament d1;
	d1.afisareDepartament();
	cout << endl << endl << endl;
	float* salariiangajati1 = new float[3] {15000, 10000, 7500};
	string* numesalariati1 = new string[3]{ "Vasile Andrei","Darius Olaru","Nicholas Jackson" };
	Departament d2("Sheraton", 3, numesalariati1, salariiangajati1, true, Informatica);
	d2.afisareDepartament();
	cout << endl << endl << endl;
	Departament d3(d2);
	d3.afisareDepartament();
	cout << endl << endl;
	Departament d4("Microsoft",3, numesalariati1, salariiangajati1, true, Informatica);
	d4.afisareDepartament();
	cout << endl << endl;
	d4 =d3;
	cout << endl << endl;
	d4.afisareDepartament();
	cout << endl << endl;
	d4.adaugaangajat("Marius Maftei", 4500);
	d4.afisareDepartament();
	cout << endl << endl;
	d4.eliminaangajat();
	d4.afisareDepartament();

}