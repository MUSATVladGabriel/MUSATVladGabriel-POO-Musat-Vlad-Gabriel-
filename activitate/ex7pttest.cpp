#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
enum tip{Carnivor=7,Ierbivor=8,Omnivor=9};
class Animal
{
	const int id;
	static int nranimale;
	char* idveterinaranimale;
	string nume;
	int nrrase;
	string* numerase;
	float* greutatemedierase;
	bool estevaccinat;
	tip fel;
public:
	Animal() :id(++nranimale)
	{
		this->idveterinaranimale = new char[strlen("X") + 1];
		strcpy(this->idveterinaranimale, "X");
		this->nume = "Necunoscut";
		this->nrrase = 0;
		this->numerase = nullptr;
		this->greutatemedierase = nullptr;
		this->estevaccinat = false;
		this->fel = Carnivor;
	}
	Animal(const char* idveterinaranimal, string nume):id(++nranimale)
	{
		if (strlen(idveterinaranimal) >= 3)
		{
			this->idveterinaranimale = new char[strlen(idveterinaranimal) + 1];
			strcpy(this->idveterinaranimale, idveterinaranimal);
		}
		else
		{
			this->idveterinaranimale = new char[strlen("X") + 1];
			strcpy(this->idveterinaranimale, "X");
		}
		if (nume.size() >= 3)
		{
			this->nume = nume;
		}
		else
		{
			this->nume = "Necunoscut";
		}
		this->nrrase = 0;
		this->numerase = nullptr;
		this->greutatemedierase = nullptr;
		this->estevaccinat = false;
		this->fel = Carnivor;
	}
	Animal(const char* idveterinaranimal, string nume,int nrrase,string* numerase,float* greutatemedierase,bool estevaccinat,tip fel) :id(++nranimale)
	{
		if (strlen(idveterinaranimal) >= 3)
		{
			this->idveterinaranimale = new char[strlen(idveterinaranimal) + 1];
			strcpy(this->idveterinaranimale, idveterinaranimal);
		}
		else
		{
			this->idveterinaranimale = new char[strlen("X") + 1];
			strcpy(this->idveterinaranimale, "X");
		}
		if (nume.size() >= 3)
		{
			this->nume = nume;
		}
		else
		{
			this->nume = "Necunoscut";
		}
		if (nrrase > 0 && numerase != nullptr && greutatemedierase != nullptr)
		{
			this->nrrase = nrrase;
			this->numerase = new string[this->nrrase];
			this->greutatemedierase = new float[this->nrrase];
			for (int i = 0; i < this->nrrase; i++)
			{
				this->numerase[i] = numerase[i];
				this->greutatemedierase[i] = greutatemedierase[i];
			}
		}
		else
		{
			this->nrrase = 0;
			this->numerase = nullptr;
			this->greutatemedierase = nullptr;
		}
		this->estevaccinat = estevaccinat;
		this->fel = fel;
	}
	Animal(const Animal& a) :id(++nranimale)
	{
		
			this->idveterinaranimale = new char[strlen(a.idveterinaranimale) + 1];
			strcpy(this->idveterinaranimale,a. idveterinaranimale);
			this->nume =a. nume;
		
	
		if (a.nrrase > 0 && a.numerase != nullptr && a.greutatemedierase != nullptr)
		{
			this->nrrase =a. nrrase;
			this->numerase = new string[this->nrrase];
			this->greutatemedierase = new float[this->nrrase];
			for (int i = 0; i < this->nrrase; i++)
			{
				this->numerase[i] =a.numerase[i];
				this->greutatemedierase[i] =a.greutatemedierase[i];
			}
		}
		else
		{
			this->nrrase = 0;
			this->numerase = nullptr;
			this->greutatemedierase = nullptr;
		}
		this->estevaccinat = a.estevaccinat;
		this->fel = a.fel;
	}
	char* getidveterinaranimal()
	{
		return this->idveterinaranimale;
	}
	void setidveterinaranimale(char* idveterinaranimale)
	{
		if (strlen(idveterinaranimale) >= 3)
		{
			delete[]this->idveterinaranimale;
			this->idveterinaranimale = new char[strlen(idveterinaranimale) + 1];
			strcpy(this->idveterinaranimale, idveterinaranimale);
		}
	}
	float* getgreutatemedierase()
	{
		return this->greutatemedierase;
	}
	void setrase(float* greutatemedierase, string* numerase, int nrrase)
	{
		delete[]this->greutatemedierase;
		delete[]this->numerase;
		if (nrrase > 0 && greutatemedierase != nullptr && numerase != nullptr)
		{
			this->nrrase = nrrase;
			this->greutatemedierase = new float[this->nrrase];
			this->numerase = new string[this->nrrase];
			for (int i = 0; i < this->nrrase; i++)
			{
				this->numerase[i] = numerase[i];
				this->greutatemedierase[i] = greutatemedierase[i];
			}
		}
	}
	Animal& operator=(const Animal& an)
	{
		if (this != &an)
		{
			this->idveterinaranimale = new char[strlen(an.idveterinaranimale) + 1];
			strcpy(this->idveterinaranimale, an.idveterinaranimale);
			this->nume = an.nume;


			if (an.nrrase > 0 && an.numerase != nullptr && an.greutatemedierase != nullptr)
			{
				this->nrrase = an.nrrase;
				this->numerase = new string[this->nrrase];
				this->greutatemedierase = new float[this->nrrase];
				for (int i = 0; i < this->nrrase; i++)
				{
					this->numerase[i] = an.numerase[i];
					this->greutatemedierase[i] = an.greutatemedierase[i];
				}
			}
			else
			{
				this->nrrase = 0;
				this->numerase = nullptr;
				this->greutatemedierase = nullptr;
			}
			this->estevaccinat = an.estevaccinat;
			this->fel = an.fel;
		}
		return *this;
	}
	void afisare()
	{
		cout << this->idveterinaranimale << endl;
		cout << this->nume << endl;
		cout << this->nrrase << endl;
		for (int i = 0; i < this->nrrase; i++)
		{
			cout << this->numerase[i] << ",";
		}
		cout << endl;
		for (int i = 0; i < this->nrrase; i++)
		{
			cout << this->greutatemedierase[i] << "kg,";
		}
		cout << endl;
		cout << this->estevaccinat << endl;
		if (this->fel == Carnivor)
			cout << "Carnivor";
		if (this->fel == Omnivor)
			cout << "Omnivor"; 
		if (this->fel == Ierbivor)
			cout << "Ierbivor";
	
	}
	void adaugarasa(string numerasa,float greutate)
	{
		int copienrrase = this->nrrase;
		string* copienumerase = new string[copienrrase];
		float* copiegreutatemedierase = new float[copienrrase];
		for (int i = 0; i < copienrrase; i++)
		{
			copienumerase[i] = this->numerase[i];
			copiegreutatemedierase[i] = this->greutatemedierase[i];
		}
		delete[]this->numerase;
		delete[]this->greutatemedierase;
		this->nrrase++;
		this->numerase = new string[this->nrrase];
		this->greutatemedierase = new float[this->nrrase];
		for (int i = 0; i < copienrrase; i++)
		{
			this->numerase[i] = copienumerase[i];
			this->greutatemedierase[i] = copiegreutatemedierase[i];
		}
		this->numerase[this->nrrase - 1] = numerasa;
		this->greutatemedierase[this->nrrase - 1] = greutate;
		delete[]copiegreutatemedierase;
		delete[]copienumerase;
	}
	~Animal()
	{
		delete[]this->numerase;
		delete[]this->greutatemedierase;
	}
};
int Animal::nranimale = 0;
int main()
{
	Animal a1;
	a1.afisare();
	cout << endl << endl;
	Animal a2("B43291CR", "Pisica");
	a2.afisare();
	cout << endl << endl;
	string numerase1[] = { "British Short Hair","Scottish Fold","Pisica salbatica" };
	float greutatemedierase[] = { 3.5,4.2,2.7 };
	Animal a3("BT5421TRE", "Pisica", 3, numerase1, greutatemedierase, true, Omnivor);
	a3.afisare();
	cout << endl << endl;
	a3.adaugarasa("Pisica Siberiana", 3.3);
	cout << endl << endl;
	a3.afisare();
	cout << endl << endl;
	Animal a4(a3);
	a4.afisare();
	Animal a5;
	a5 = a2;
	a5.afisare();
	
}