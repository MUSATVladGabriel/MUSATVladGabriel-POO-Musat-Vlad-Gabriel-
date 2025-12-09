#include<iostream>
#include<string>
using namespace std;
enum tip{Chinezesc=5,Normal=10,Japonez=15,Spaniol=20};
class Restaurant
{
	const int id;
	char* nume;
	char* oras;
	float* ratinguri;
	int nrrating;
	tip categorie;
	bool deschis;
	static int nrrestaurante;
public:
	Restaurant():id(++nrrestaurante)
	{
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->oras = new char[strlen("XYZAb") + 1];
		strcpy(this->oras, "XYZAb");
		this->ratinguri = nullptr;
		this->nrrating = 0;
		this->categorie = Normal;
		this->deschis = false;
	}
	Restaurant(const char* nume,const char* oras,float* ratinguri,int nrrating,tip categorie,bool deschis) :id(++nrrestaurante)
	{
		if (strlen(nume) >= 3)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
			throw exception("Bai nenicule nu exista acest restaurant");
		}
		if (strlen(oras) >= 4)
		{
			this->oras = new char[strlen(oras) + 1];
			strcpy(this->oras, oras);
		}
		else
		{
			this->oras = new char[strlen("XYZAb") + 1];
			strcpy(this->oras, "XYZAb");
			throw exception("Acest oras nu exista");
		}
		if (nrrating > 0 && ratinguri != nullptr)
		{
			this->nrrating = nrrating;
			this->ratinguri = new float[this->nrrating];
			for (int i = 0; i < this->nrrating; i++)
			{
				this->ratinguri[i] = ratinguri[i];
			}
		}
		else
		{
			this->ratinguri = nullptr;
			this->nrrating = 0;
			throw exception("Nu are ratinguri!");
		}
		this->categorie = categorie;
		this->deschis = deschis;
	}
	Restaurant(const Restaurant& r):id(r.id)
	{
		if (strlen(r.nume) >= 3)
		{
			this->nume = new char[strlen(r.nume) + 1];
			strcpy(this->nume,r.nume);
		}
		else
		{
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
			//throw exception("Bai nenicule nu exista acest restaurant");
		}
		if (strlen(r.oras) >= 4)
		{
			this->oras = new char[strlen(r.oras) + 1];
			strcpy(this->oras, r.oras);
		}
		else
		{
			this->oras = new char[strlen("XYZAb") + 1];
			strcpy(this->oras, "XYZAb");
			//throw exception("Acest oras nu exista");
		}
		if (r.nrrating > 0 && r.ratinguri != nullptr)
		{
			this->nrrating = r.nrrating;
			this->ratinguri = new float[this->nrrating];
			for (int i = 0; i < this->nrrating; i++)
			{
				this->ratinguri[i] = r.ratinguri[i];
			}
		}
		else
		{
			this->ratinguri = nullptr;
			this->nrrating = 0;
			//throw exception("Nu are ratinguri!");
		}
		this->categorie = r.categorie;
		this->deschis = r.deschis;
	}
	Restaurant& operator=(const Restaurant& r)
	{
		if (this != &r)
		{
			if (strlen(r.nume) >= 3)
			{
				delete[]this->nume;
				this->nume = new char[strlen(r.nume) + 1];
				strcpy(this->nume, r.nume);
			}
			else
			{
				this->nume = new char[strlen("Necunoscut") + 1];
				strcpy(this->nume, "Necunoscut");
				//throw exception("Bai nenicule nu exista acest restaurant");
			}
			if (strlen(r.oras) >= 4)
			{
				delete[]this->oras;
				this->oras = new char[strlen(r.oras) + 1];
				strcpy(this->oras, r.oras);
			}
			else
			{
				this->oras = new char[strlen("XYZAb") + 1];
				strcpy(this->oras, "XYZAb");
				//throw exception("Acest oras nu exista");
			}
			if (r.nrrating > 0 && r.ratinguri != nullptr)
			{
				delete[]this->ratinguri;
				this->nrrating = r.nrrating;
				this->ratinguri = new float[this->nrrating];
				for (int i = 0; i < this->nrrating; i++)
				{
					this->ratinguri[i] = r.ratinguri[i];
				}
			}
			else
			{
				this->ratinguri = nullptr;
				this->nrrating = 0;
				//throw exception("Nu are ratinguri!");
			}
			this->categorie = r.categorie;
			this->deschis = r.deschis;
		}
		return *this;
	}
	~Restaurant()
	{
		if (this->nume != nullptr && this->oras != nullptr && this->ratinguri != nullptr)
		{
			delete[]this->nume;
			delete[]this->ratinguri;
			delete[]this->oras;
		}
	}
	float* getratinguri()
	{
		float* copie = new float[this->nrrating];
		for (int i = 0; i < this->nrrating; i++)
		{
			copie[i] = this->ratinguri[i];
		}
		return copie;
	}
	char* getnume()
	{
		char* copie = new char[strlen(this->nume) + 1];
		strcpy(copie, this->nume);
		return copie;
	}
	const int getid()
	{
		return this->id;
	}
	void setratinguri(int nrrating, float* ratinguri)
	{
		if (nrrating > 0 && ratinguri != nullptr)
		{
			delete[]this->ratinguri;
			this->nrrating = nrrating;
			this->ratinguri = new float[this->nrrating];
			for (int i = 0; i < this->nrrating; i++)
			{
				this->ratinguri[i] = ratinguri[i];
			}
		}
		else
		{
			throw new exception("Baaaaaaaa unde ne duci?!");
		}
	}
	void setdeschis(bool deschis)
	{
		this->deschis = deschis;
	}
	friend ostream& operator<<(ostream& out, const Restaurant& r)
	{
		out << "Idul: " << r.id << endl;
		out << "Numele: " << r.nume<<endl;
		out << "Orasul: " << r.oras << endl;
		out << "Nr de ratinguri: " << r.nrrating << endl;
		out << "Ratingurile sunt: ";
		for (int i = 0; i < r.nrrating; i++)
		{
			out << r.ratinguri[i] << ",";
		}
		out << endl;
		out << "Categoria: ";
		if (r.categorie == Chinezesc)
		{
			out << "Chinezesc";
		}
		else if (r.categorie == Spaniol)
		{
			out << "Spaniol";
		}
		else if (r.categorie == Japonez)
		{
			out << "Japonez";
		}
		else if (r.categorie == Normal)
		{
			out << "Normal";
		}
		out << endl;
		out << "Deschis(Da-1 si Nu-0): " << r.deschis<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, Restaurant& r)
	{
		delete[]r.nume;
		cout << "Introduceti numele: ";
		char aux[100];
		in >> ws;
		in.getline(aux, 99);
		r.nume = new char[strlen(aux) + 1];
		strcpy(r.nume, aux);
		delete[]r.oras;
		cout << "Introduceti orasul: ";
		char aux1[100];
		in >> ws;
		in.getline(aux1, 99);
		r.oras = new char[strlen(aux1) + 1];
		strcpy(r.oras, aux1);
		cout << "Introduceti nr de ratinguri: ";
		in >> r.nrrating;
		delete[]r.ratinguri;
		r.ratinguri = new float[r.nrrating];
		for (int i = 0; i < r.nrrating; i++)
		{
			cout << "Introduceti ratingul " << i + 1 << ":";
			in >> r.ratinguri[i];
		}
		int tip;
		cout << "Introduceti tipul(5-chinezesc 10-Spaniol 15-Japonez 20-Normal): ";
		in >> tip;
		if (tip == 5)
		{
			r.categorie = Chinezesc;
		}
		else if (tip == 10)
		{
			r.categorie = Spaniol;
		}
		else if (tip == 15)
		{
			r.categorie = Japonez;
		}
		else
		{
			r.categorie = Normal;
		}
		cout << "Introduceti daca este deschis(Da-1 si Nu-0): ";
		in >> r.deschis;
		return in;
	}
	Restaurant operator+(const Restaurant &r)
	{
		Restaurant copie = *this;
		copie.nrrating += r.nrrating;
		return copie;
	}
	float ratingmediu()
	{
		float s = 0;
		for (int i = 0; i < this->nrrating; i++)
		{
			s += this->ratinguri[i];
		}
		return s / this->nrrating;
	}
	explicit operator int()
	{
		 return this->ratingmediu();
	}
	explicit operator char*()
	{
		return this->nume;
	}
	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrrating)
		{
			return this->ratinguri[index];
		}
		else
		{
			throw exception("Nu ai ales indexul potrivit!");
		}
	}
	Restaurant& operator++()
	{
		for (int i = 0; i < this->nrrating; i++)
		{
			this->ratinguri[i]++;
		}
		return *this;
	}
	Restaurant operator++(int)
	{
		Restaurant copie = *this;
		for (int i = 0; i < this->nrrating; i++)
		{
			this->ratinguri[i]++;
		}
		return copie;
	}
	bool operator!=(Restaurant r)
	{
		bool acelasi = false;
		if (strcmp(this->nume, r.nume) == 0 && strcmp(this->oras, r.oras) == 0 &&
			this->nrrating == r.nrrating && this->categorie == r.categorie && this->deschis == r.deschis)
		{
			acelasi = true;
		}
		else
		{
			for (int i = 0; i < this->nrrating; i++)
			{
				if (this->ratinguri[i] == r.ratinguri[i])
				{
					acelasi = true;
				}
			}
		}
		if (acelasi == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	float operator()()
	{
		return this->ratingmediu();
	}
	bool operator!()
	{
		return this->nrrating != 0;
	}
	
};
int Restaurant::nrrestaurante = 0;
int main()
{
	Restaurant r;
	float ratinguri1[] = { 7.5,8.9,9.5,7.9 };
	Restaurant r1("Al Pacino", "Bucuresti", ratinguri1, 4, Spaniol, true);
	Restaurant r2(r);
	Restaurant r3;
	r3 = r1;
	cout << r << endl<<endl;
	cout << r1 << endl << endl;
	cout << r3 << endl << endl;
	try
	{
		cout << r1[-5] << endl;
		Restaurant r5;
		r5.setratinguri(-5, NULL);
		Restaurant r4("e", "O", ratinguri1, 4, Normal, 0);
	}
	catch (exception err)
	{
		cout << err.what() << endl << endl;
	}
	catch (exception* er)
	{
		cout << er->what() << endl << endl;
	}
	Restaurant r4=r1+r;
	//cin >> r4;
	//cout << r4;
	cout << r4 << endl << endl;
	cout << r1.ratingmediu() << endl;
	cout << (int)r1 << endl;
	cout << (char*)r << endl;
	cout << r1[2] << endl;
	cout << r1 << endl << endl;
	Restaurant r5 = r1++;
	cout << r5 << endl << endl;
	cout << r1 << endl << endl;
	Restaurant r6 = ++r1;
	cout << r6 << endl << endl;
	cout << r1 << endl << endl;
	if (r1 != r1)
	{
		cout << "Obiectele sunt diferite";
	}
	else
	{
		cout << "Obiectele sunt aceleasi";
	}
	cout << endl;
	if (r2 != r1)
	{
		cout << "Obiectele sunt diferite";
	}
	else
	{
		cout << "Obiectele sunt aceleasi";
	}
	cout << endl << r6() << endl;
	if (!r5)
	{
		cout << "Rating!=0";
	}
	else
	{
		cout << "Rating=0";
	}
	return 0;
}