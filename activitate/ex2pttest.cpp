#include<iostream>
#include<string>
using namespace std;
enum Tara{Spania=7,Germania=8,Franta=9,Anglia=10,Italia=11,Nusecunoaste=12};
class clubfotbal
{
	const int id;;
	int anfondatare;
	string nume;
	//char* proprietar;
	int nrjucatori;
	string* numejucatori;
	float* salariijucatori;
	bool estecastigatoaredecupaeuropeana;
	Tara tara;
	static int nrcluburi;
public:
	clubfotbal() :id(++nrcluburi)
	{
		this->anfondatare = 0;
		this->nume = "Necunoscut";
		//this->proprietar = new char[strlen(proprietar) + 1];
		//strcpy(this->proprietar, "Anonim");
		this->nrjucatori = 0;
		this->numejucatori = nullptr;
		this->salariijucatori = nullptr;
		this->estecastigatoaredecupaeuropeana = false;
		this->tara = Nusecunoaste;
	}
	clubfotbal(int anfondatare,string nume,int nrjucatori, string* numejucatori, float* salariijucatori, bool estecastigatoaredecupaeuropeana,Tara tara) :id(++nrcluburi)
	{
		this->anfondatare = anfondatare;
		this->nume =nume;
		//this->proprietar = new char[strlen(proprietar) + 1];
		//strcpy(this->proprietar,proprietar);
		this->nrjucatori = nrjucatori;
		this->numejucatori = new string[this->nrjucatori];
		for (int i = 0; i < this->nrjucatori; i++)
		{
			this->numejucatori[i] = numejucatori[i];
		}
		this->salariijucatori = new float[this->nrjucatori];
		for (int i = 0; i < this->nrjucatori; i++)
		{
			this->salariijucatori[i] = salariijucatori[i];
		}
		this->estecastigatoaredecupaeuropeana = estecastigatoaredecupaeuropeana;
		this->tara = tara;
	}
	clubfotbal(const clubfotbal& copie):id(++nrcluburi)
	{
		this->anfondatare = copie.anfondatare;
		//this->proprietar = new char[strlen(copie.proprietar) + 1];
		//strcpy(copie.proprietar, proprietar);
		this->nume = copie.nume;
		this->nrjucatori = copie.nrjucatori;
		this->tara = copie.tara;
		if (copie.numejucatori != nullptr)
		{
			this->numejucatori = new string[copie.nrjucatori];
			for (int i = 0; i < copie.nrjucatori; i++)
			{
				this->numejucatori[i] = copie.numejucatori[i];
			}
		}
		else
		{
			this->numejucatori = nullptr;
		}
		if(copie.salariijucatori!=nullptr)
		{
			this->salariijucatori = new float[copie.nrjucatori];
			for (int i = 0; i < copie.nrjucatori; i++)
			{
				this->salariijucatori[i] = copie.salariijucatori[i];
			}
		}
		else
		{
			this->salariijucatori = nullptr;
		}
	}
	int getanfondatare()
	{
		return this->anfondatare;
	}
	void setanfondatare(int anfondatare)
	{
		this->anfondatare = anfondatare;
	}
		string getnume()
		{
			return this->nume;
		}
		/*char* getproprietar()
		{
			return this->proprietar;
		}*/
		int getnrjucatori()
		{
			return this->nrjucatori;
		}
		string* getnumejucatori()
		{
			string* copienume = new string[this->nrjucatori];
			for (int i = 0; i < this->nrjucatori; i++)
			{
				copienume[i] = this->numejucatori[i];
			}
			return copienume;
		}
		float* getsalariijucatori()
		{
			float* copiesalarii = new float[this->nrjucatori];
			for (int i = 0; i < this->nrjucatori; i++)
			{
				copiesalarii[i] = this->salariijucatori[i];
			}
			return copiesalarii;
		}
		void setnume(string nume)
		{
			this->nume = nume;
		}
		/*void setproprietar(char* proprietar)
		{
			delete[] this->proprietar;
			this->proprietar = new char[strlen(proprietar) + 1];
			strcpy(this->proprietar, proprietar);
		}*/
		void setnrjucatori(int nrjucatori)
		{
			this->nrjucatori = nrjucatori;
		}
		void setjucatori(string* numejucatori, float* salariijucatori, int nrjucatori)
		{
			delete[] this->numejucatori;
			delete[] this->salariijucatori;
			this->nrjucatori = nrjucatori;
			this-> numejucatori = new string[this->nrjucatori];
		
			for (int i = 0; i < this->nrjucatori; i++)
			{
				this->numejucatori[i] = numejucatori[i];
			}
			this-> salariijucatori = new float[this->nrjucatori];
			for (int i = 0; i < this->nrjucatori; i++)
			{
				this->salariijucatori[i] = salariijucatori[i];
			}
		}
		void settara(Tara tara)
		{
			this->tara = tara;
		}
		
		void afisareclubfotbal()
		{
			cout << "Clubul de fotbal " << this->nume << " a fost fondat in anul " << this->anfondatare << " este din ";
			if (this->tara == Spania)cout << "Spania ";
			if (this->tara == Germania)cout << "Germania ";
			if (this->tara == Anglia)cout << "Anglia ";
			if (this->tara == Italia)cout << "Italia ";
			if (this->tara == Franta)cout << "Franta ";
			cout << "si are " << this->nrjucatori << " jucatori si este castigatoare de cupa euroapeana(1/0) "<<this->estecastigatoaredecupaeuropeana<<".Pe acestia ii cheama: ";
			
			if (this->nrjucatori == 0 || this->numejucatori == nullptr)
				cout << "nu exista.";
			else
			{
				for (int i = 0; i < this->nrjucatori-1; i++)
				{
					cout << this->numejucatori[i] << " avand salariul ";
					if (this->salariijucatori != nullptr)
						cout << this->salariijucatori[i] << ",";
				}
				cout << this->numejucatori[this->nrjucatori - 1] << " avand salariul" << this->salariijucatori[this->nrjucatori - 1] << ".";
				
				
			}
			cout << endl << endl;
		}
		void operator=(const clubfotbal& fc)
		{
			this->anfondatare = fc.anfondatare;
			this->nume = fc.nume;
			this->nrjucatori = fc.nrjucatori;
			if (numejucatori != nullptr)
			{
				delete[]this->numejucatori;
				numejucatori = nullptr;
			}
			if(fc.numejucatori!=nullptr)
			{
				this->numejucatori = new string[fc.nrjucatori];
				for (int i = 0; i < fc.nrjucatori; i++)
				{
					this->numejucatori[i] = fc.numejucatori[i];
				}
			}
			else
			{
				this->numejucatori = nullptr;
			}
			if (salariijucatori != nullptr)
			{
				delete[]this->salariijucatori;
				this->salariijucatori = nullptr;
			}
			if (fc.salariijucatori != nullptr)
			{
				this->salariijucatori = new float[fc.nrjucatori];
				for (int i = 0; i < fc.nrjucatori; i++)
				{
					this->salariijucatori[i] = fc.salariijucatori[i];
				}
			}
			else
			{
				this->salariijucatori = nullptr;
			}
			this->estecastigatoaredecupaeuropeana = fc.estecastigatoaredecupaeuropeana;
			this->tara = fc.tara;
		}
		~clubfotbal()
		{
			delete[]this->numejucatori;
			delete[]this->salariijucatori;
		}
};
int clubfotbal::nrcluburi = 0;
int main()
{
	clubfotbal realmadrid;
	realmadrid.afisareclubfotbal();
	string* numejucatori1=new string[6] {"Lionel Messi","Pedri","Lamine Yamal","Gavi","Araujo","Cubarsi"};
	string* numejucatori2 = new string[6]{ "Gerd Muller","Kimmich","Olise","Luis Diaz","Harry Kane","Upamecano"};
	float* salariijucatori1=new float[6] {350000, 100000, 140000, 90000, 70000, 80000};
	clubfotbal* a=new clubfotbal(1899,"FC Barcelona", 6, numejucatori1, salariijucatori1, true, Spania);
	a->afisareclubfotbal();
	clubfotbal c(*a);
	c.afisareclubfotbal();
	clubfotbal* b = new clubfotbal(1900, "FC Bayern Munchen", 6, numejucatori2, salariijucatori1, true, Germania);
	b->afisareclubfotbal();
	*b = *a;
	b->afisareclubfotbal();
	clubfotbal e(1899, "FC Barcelona", 6, numejucatori1, salariijucatori1, true, Spania);
	e.afisareclubfotbal();
	delete[]numejucatori1;
	delete[]salariijucatori1;
	delete[]numejucatori2;
	delete b;
	delete a;
	return 0;
}