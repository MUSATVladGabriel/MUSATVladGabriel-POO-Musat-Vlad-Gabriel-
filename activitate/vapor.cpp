#include<iostream>
#include<string>
using namespace std;
class Vapor
{
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePasageri;
	//am folosit ca parametru denumirea vaporului si viteza maxima ca fiecare
	// vapor are o denumire diferita si o viteza maxima diferita.
	string denumire;
	int vitezamaxima;
public:
	Vapor() 
	{
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstePasageri = nullptr;
		this->denumire = "Necunoscut";
		this->vitezamaxima = 0;
	}
	Vapor(int vitezamaxima, int capacitate, int nrPersoaneImbarcate, int* varstePasageri, string denumire) 
	{
		if (capacitate > 0)
		{
			this->capacitate = capacitate;
		}
		else
		{
			this->capacitate = 0;
		}
	
		
		if (nrPersoaneImbarcate <= capacitate && nrPersoaneImbarcate > 0 && varstePasageri != nullptr)
		{
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
			this->varstePasageri = new int[this->nrPersoaneImbarcate];
			for (int i = 0; i < this->nrPersoaneImbarcate; i++)
			{
				this->varstePasageri[i] = varstePasageri[i];
			}
		}
		else
		{
			this->nrPersoaneImbarcate = 0;
			this->varstePasageri = nullptr;
		}
		if (denumire.size() > 0)
		{
			this->denumire = denumire;
		}
		else
		{
			this->denumire = "Necunoscut";
		}
		if (this->vitezamaxima != 0)
		{
			this->vitezamaxima = vitezamaxima;
		}
		else
		{
			this->vitezamaxima = 0;
		}
	}
	Vapor(const Vapor& v)
	{
		if (v.capacitate > 0)
		{
			this->capacitate = v.capacitate;
		}
		else
		{
			this->capacitate = 0;
		}


		if (v.nrPersoaneImbarcate <= capacitate && v.nrPersoaneImbarcate > 0 && v.varstePasageri != nullptr)
		{
			this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
			this->varstePasageri = new int[this->nrPersoaneImbarcate];
			for (int i = 0; i < this->nrPersoaneImbarcate; i++)
			{
				this->varstePasageri[i] = v.varstePasageri[i];
			}
		}
		else
		{
			this->nrPersoaneImbarcate = 0;
			this->varstePasageri = nullptr;
		}
		if (v.denumire.size() > 0)
		{
			this->denumire = v.denumire;
		}
		else
		{
			this->denumire = "Necunoscut";
		}
		if (v.vitezamaxima != 0)
		{
			this->vitezamaxima = v.vitezamaxima;
		}
		else
		{
			this->vitezamaxima = 0;
		}

	}
	 int getvitezamaxima()
	{
		return this->vitezamaxima;
	}
	string getdenumire()
	{
		return this->denumire;
	}
	void setdenumire(string denumire)
	{
		
		this->denumire = denumire;
	}
	void setvitezamaxima(int vitezamaxima)
	{
		this->vitezamaxima = vitezamaxima;
	}
	Vapor& operator=(const Vapor& va)
	{
		if (this != &va)
		{
			if (va.capacitate > 0)
			{
				this->capacitate = va.capacitate;
			}
			else
			{
				this->capacitate = 0;
			}


			if (va.nrPersoaneImbarcate <= capacitate && va.nrPersoaneImbarcate > 0 && va.varstePasageri != nullptr)
			{
				this->nrPersoaneImbarcate = va.nrPersoaneImbarcate;
				this->varstePasageri = new int[this->nrPersoaneImbarcate];
				for (int i = 0; i < this->nrPersoaneImbarcate; i++)
				{
					this->varstePasageri[i] = va.varstePasageri[i];
				}
			}
			else
			{
				this->nrPersoaneImbarcate = 0;
				this->varstePasageri = nullptr;
			}
			if (va.denumire.size() > 0)
			{
				this->denumire = va.denumire;
			}
			else
			{
				this->denumire = "Necunoscut";
			}
			if (va.vitezamaxima != 0)
			{
				this->vitezamaxima = va.vitezamaxima;
			}
			else
			{
				this->vitezamaxima = 0;
			}
		}
		return *this;
	}
	float calculareVarstaMedie()
	{
		float s = 0.0f;
		for (int i = 0; i < this->nrPersoaneImbarcate; i++)
		{
			s += this->varstePasageri[i];
		}
		return s / this->nrPersoaneImbarcate;
	}
	void afisare()
	{
		cout << this->vitezamaxima<< endl;
		cout << this->capacitate << endl;
		cout << this->nrPersoaneImbarcate << endl;
		for (int i = 0; i < this->nrPersoaneImbarcate; i++)
		{
			cout << this->varstePasageri[i] << ",";
		}
		cout << endl;
		cout << this->denumire << endl;
	}
	~Vapor()
	{
		delete[]this->varstePasageri;
	}

};
int main()
{
	Vapor a;
	a.afisare();
	int varstepasageri1[] = { 15,25,30,45,54 };
	Vapor a1(20, 100, 5, varstepasageri1, "Titanic");
	cout << endl << endl;
	a1.afisare();
	Vapor a2(a1);
	cout << endl << endl;
	a2.afisare();
	cout << endl;
	cout<<a2.calculareVarstaMedie();
	int varstepasageri2[] = { 15,25,30,45,54,47,23,45,11,81 };
	Vapor a3(150, 499, 10, varstepasageri2, "Randal");
	cout << endl;
	a3.afisare();
	cout << endl;
	cout << a3.calculareVarstaMedie();
	cout << endl << endl;
	a3 = a2;
	a3.afisare();
	cout << endl;
	cout << a3.calculareVarstaMedie();
	cout << endl;
	cout << a2.getdenumire() << endl;
	cout << a3.getvitezamaxima() << endl<<endl;
	a3.setdenumire("Fabulos");
	a3.afisare();
}