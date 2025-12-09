#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class FilmPremium
{
	char* titlu;
	int durata;
	float rating;
	char* gen;
	bool abonamentPremium;
public:
	FilmPremium()
	{
		this->titlu = new char[strlen("Necunoscut") + 1];
		strcpy(this->titlu, "Necunoscut");
		this->durata = 0;
		this->rating = 0;
		this->gen = new char[strlen("X") + 1];
		strcpy(this->gen, "X");
		this->abonamentPremium = false;
	}
	FilmPremium(const char* titlu, int durata, float rating, const char* gen, bool abonamentPremium)
	{
		if (strlen(titlu) >= 3)
		{
			this->titlu = new char[strlen(titlu) + 1];
			strcpy(this->titlu, titlu);
		}
		else
		{
			throw exception("NU ai gasit filmul domne!");
		}
		if (durata > 0)
		{
			this->durata = durata;
		}
		else
		{
			throw exception("Unde te uiti domne?!");
		}
		if (rating > 0)
		{
			this->rating = rating;
		}
		else
		{
			throw exception("Nu stii sa scrii!");
		}
		if (strlen(gen) >= 3)
		{
			this->gen = new char[strlen(gen) + 1];
			strcpy(this->gen, gen);
		}
		else
		{
			throw exception("Nu ai gasit genul potrivit!");
		}
		this->abonamentPremium = abonamentPremium;
	}
	FilmPremium(const FilmPremium& f)
	{
		if (strlen(f.titlu) >= 3)
		{
			this->titlu = new char[strlen(f.titlu) + 1];
			strcpy(this->titlu, f.titlu);
		}
		else
		{
			this->titlu = new char[strlen("Necunoscut") + 1];
			strcpy(this->titlu, "Necunoscut");
			//throw exception("NU ai gasit filmul domne!");
		}
		if (f.durata > 0)
		{
			this->durata = f.durata;
		}
		else
		{
			this->durata = 0;
			//throw exception("Unde te uiti domne?!");
		}
		if (f.rating > 0)
		{
			this->rating = f.rating;
		}
		else
		{
			this->rating = 0;
			//throw exception("Nu stii sa scrii!");
		}
		if (strlen(f.gen) >= 3)
		{
			this->gen = new char[strlen(f.gen) + 1];
			strcpy(this->gen, f.gen);
		}
		else
		{
			this->gen = new char[strlen("X") + 1];
			strcpy(this->gen, "X");
			//throw exception("Nu ai gasit genul potrivit!");
		}
		this->abonamentPremium = f.abonamentPremium;
	}
	FilmPremium& operator=(const FilmPremium& f)
	{
		if (this != &f)
		{
			if (strlen(f.titlu) >= 3)
			{
				delete[]this->titlu;
				this->titlu = new char[strlen(f.titlu) + 1];
				strcpy(this->titlu, f.titlu);
			}
			else
			{
				this->titlu = new char[strlen("Necunoscut") + 1];
				strcpy(this->titlu, "Necunoscut");
				//throw exception("NU ai gasit filmul domne!");
			}
			if (f.durata > 0)
			{
				this->durata = f.durata;
			}
			else
			{
				this->durata = 0;
				//throw exception("Unde te uiti domne?!");
			}
			if (f.rating > 0)
			{
				this->rating = f.rating;
			}
			else
			{
				this->rating = 0;
				//throw exception("Nu stii sa scrii!");
			}
			if (strlen(f.gen) >= 3)
			{
				delete[]this->gen;
				this->gen = new char[strlen(f.gen) + 1];
				strcpy(this->gen, f.gen);
			}
			else
			{
				this->gen = new char[strlen("X") + 1];
				strcpy(this->gen, "X");
				//throw exception("Nu ai gasit genul potrivit!");
			}
			this->abonamentPremium = f.abonamentPremium;
		}
		return *this;
	}
	char* gettitlu()
	{
		char* copie = new char[strlen(this->titlu) + 1];
		strcpy(copie, this->titlu);
		return copie;
	}
	int getdurata()
	{
		return this->durata;
	}
	void settitlu(const char* titlu)
	{
		if (strlen(titlu) >= 3)
		{
			delete[]this->titlu;
			this->titlu=new char[strlen(titlu)+1];
			strcpy(this->titlu, titlu);
		}
	}
	void setdurata(int durata)
	{
		if (durata > 0)
		{
			this->durata = durata;
		}
	}
	~FilmPremium()
	{
		if (this->titlu != nullptr && this->gen != nullptr)
		{
			delete[]this->titlu;
			delete[]this->gen;
		}
	}
	friend ostream& operator<<(ostream& out, const FilmPremium& f)
	{
		out << "Titlul: " << f.titlu << ",Genul: " << f.gen << ",abonament premium(Da-1 si nu-0): " << f.abonamentPremium << ",Durata: " << f.durata << ",ratingul:" << f.rating;
		return out;
	}
	friend istream& operator>>(istream& in, FilmPremium& f)
	{
		delete[]f.titlu;
		cout << "Introduceti titlul: ";
		char aux[100];
		in >> ws;
		in.getline(aux, 99);
		f.titlu = new char[strlen(aux) + 1];
		strcpy(f.titlu, aux);
		cout << "Introduceti durata: ";
		in >> f.durata;
		cout << "Introduceti ratingul: ";
		in >> f.rating;
		delete[]f.gen;
		cout << "Introduceti genul: ";
		char aux1[100];
		in >> ws;
		in.getline(aux1, 99);
		f.gen = new char[strlen(aux1) + 1];
		strcpy(f.gen, aux1);
		cout << "Introduceti daca are abonament premium(1=Da si 0=NU): ";
		in >> f.abonamentPremium;
		return in;
	}
	bool operator!()
	{
		return this->durata != 0;
	}
	bool operator>(FilmPremium f)
	{
		bool estemaimare = true;
		if (strcmp(this->titlu, f.titlu) > 0 && this->durata > f.durata && this->rating > f.rating && strcmp(this->gen, f.gen) > 0)
		{
			estemaimare = true;
		}
		else
		{
			estemaimare = false;
		}
		return estemaimare;
	}
	FilmPremium& operator++()
	{
		this->durata += 45;
		return *this;
	}
	FilmPremium operator++(int)
	{
		FilmPremium copie = *this;
		this->rating++;
		return copie;
	}
	char operator[](int index)
	{
		if (index >= 0 && index < strlen(this->titlu))
		{
			return this->titlu[index];
		}
		else
		{
			return NULL;
		}
	}
	explicit operator int()
	{
		return this->durata;
	}
	explicit operator float()
	{
		return this->rating;
	}
	char operator()()
	{
		return this->titlu[0];
	}
	bool operator<(FilmPremium f)
	{
		return this->rating < f.rating;
	}
	friend FilmPremium operator+(int valoare,FilmPremium f )
	{
		FilmPremium copie = f;
		copie.durata = valoare + copie.durata;
		return copie;
	}
	FilmPremium& operator*=(float val)
	{
		this->rating *= val;
		return *this;
	}

};
int main()
{
	FilmPremium f;
	FilmPremium f1("Batman", 140, 8.4, "Actiune", true);
	FilmPremium f2(f);
	FilmPremium f3;
	f3 = f1;
	cout << f << endl << endl;
	cout << f1 << endl << endl;
	cout << f2 << endl << endl;
	cout << f3 << endl << endl;
	FilmPremium f4;
	//cin >> f4;
	cout << f4 << endl << endl;
	try
	{
		FilmPremium f5("Marcel Ciolacu", -9, 8.5, "Comedie", true);
	}
	catch(exception err)
	{
		cout << err.what() << endl << endl;
	}
	if (!f1)
	{
		cout << "Nu este egal cu 0";
	}
	else
	{
		cout << "este egal cu 0";
	}
	cout << endl;
	FilmPremium f6("Zamfirescu ZXYDEQRT", 180, 9.2, "Science Fiction", true);
	if (f6 > f1)
	{
		cout << "Obiectul f6 este mai mare dpdv lexicografic si numeric";
	}
	else
	{
		cout << "Obiectul f6 este mai mic";
	}
	cout << endl;
	if (f1 < f6)
		cout << "Ratingul filmului f1 este mai mic fata de f6";
	else
		cout << "Ratingul filmului f1 este mai mare fata de f6";
	cout << endl << endl << endl;;
	FilmPremium f7 = ++f1;
	cout << f1 << endl << endl;
	cout << f7 << endl << endl;
	FilmPremium f8 = f6++;
	cout << f6 << endl << endl;
	cout << f8 << endl << endl;
	cout << f6[2] << endl;
	cout << f6[-3] << endl;
	cout << (int)f6 << endl;
	cout << (float)f1 << endl;
	cout << f1() << endl;
	FilmPremium f9 = 25 + f1;
	cout << f1 << endl<<endl;
	cout << f9 << endl << endl;
	f6 *= 1.2;
	cout << f6 << endl << endl;
}