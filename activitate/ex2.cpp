#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Film
{
	string titlu;
	int durata;
	float* ratinguri;
	int nrRatinguri;
	string gen;
	bool disponibilPePlatforma;
public:
	Film()
	{
		this->titlu = "Necunoscut";
		this->durata = 0;
		this->ratinguri = nullptr;
		this->nrRatinguri = 0;
		this->gen = "Y";
		this->disponibilPePlatforma = false;
	}
	Film(string titlu, int durata, float* ratinguri, int nrRatinguri, string gen, bool disponibilPePlatforma)
	{
		if (titlu.size() >= 2)
		{
			this->titlu = titlu;
		}
		else
			throw exception("Nu exista filmul bossule!");
		if (durata > 0)
		{
			this->durata = durata;
		}
		else
		{
			throw exception("Nu are cum sa aiba durata sub 0!");
		}
		if (nrRatinguri > 0 && ratinguri != nullptr)
		{
			this->nrRatinguri = nrRatinguri;
			this->ratinguri = new float[this->nrRatinguri];
			for (int i = 0; i < this->nrRatinguri; i++)
			{
				this->ratinguri[i] = ratinguri[i];
			}
		}
		else
		{
			throw exception("Nu ai gasit filmul corect!");
		}
		if (gen.size() >= 3)
		{
			this->gen = gen;
		}
		else
			throw exception("Nu stim genul filmului!");
		this->disponibilPePlatforma = disponibilPePlatforma;
	}
	Film(const Film& f)
	{
		if ((f.titlu).size() >= 2)
		{
			this->titlu = f.titlu;
		}
		else
			this->titlu = "Necunoscut";
		if (f.durata > 0)
		{
			this->durata = f.durata;
		}
		else
		{
			this->durata = 0;
		}
		if (f.nrRatinguri > 0 && f.ratinguri != nullptr)
		{
			this->nrRatinguri = f.nrRatinguri;
			this->ratinguri = new float[this->nrRatinguri];
			for (int i = 0; i < this->nrRatinguri; i++)
			{
				this->ratinguri[i] = f.ratinguri[i];
			}
		}
		else
		{
			//throw exception("Nu ai gasit filmul corect!");
			this->nrRatinguri = 0;
			this->ratinguri = nullptr;
		}
		if ((f.gen).size() >= 3)
		{
			this->gen = f.gen;
		}
		else
			//throw exception("Nu stim genul filmului!");
		{
			this->gen = "Y";
		}
		this->disponibilPePlatforma = f.disponibilPePlatforma;
	}
	Film& operator=(const Film& f)
	{
		if (this != &f)
		{
			if ((f.titlu).size() >= 2)
			{
				this->titlu = f.titlu;
			}
			else
			{
				this->titlu = "Necunoscut";
			}
			if (f.durata > 0)
			{
				this->durata = f.durata;
			}
			else
			{
				this->durata = 0;
			}
			if (f.nrRatinguri > 0 && f.ratinguri != nullptr)
			{
				delete[]this->ratinguri;
				this->nrRatinguri = f.nrRatinguri;
				this->ratinguri = new float[this->nrRatinguri];
				for (int i = 0; i < this->nrRatinguri; i++)
				{
					this->ratinguri[i] = f.ratinguri[i];
				}
			}
			else
			{
				this->ratinguri = nullptr;
				this->nrRatinguri = 0;
			}
			if ((f.gen).size() >= 3)
			{
				this->gen = f.gen;
			}
			else
			{
				this->gen = "Y";
			}
			this->disponibilPePlatforma = f.disponibilPePlatforma;
		}
		return *this;
	}
	~Film()
	{
		if (this->ratinguri != nullptr)
		{
			delete[]this->ratinguri;
		}
	}
	float* getratinguri()
	{
		float* copie = new float[this->nrRatinguri];
		for (int i = 0; i < this->nrRatinguri; i++)
		{
			copie[i] = this->ratinguri[i];
		}
		return copie;
	}
	string getgen()
	{
		return this->gen;
	}
	void setratinguri(int nrRatinguri, float* ratinguri)
	{
		if (nrRatinguri > 0 && ratinguri != nullptr)
		{
			delete[]this->ratinguri;
			this->nrRatinguri = nrRatinguri;
			this->ratinguri = new float[this->nrRatinguri];
			for (int i = 0; i < this->nrRatinguri; i++)
			{
				this->ratinguri[i] = ratinguri[i];
			}
		}
	}
	void setgen(string gen)
	{
		if (gen.size() >= 3)
		{
			this->gen = gen;
		}
	}
	friend ostream& operator<<(ostream& out, const Film& f)
	{
		out << "Titlul: " << f.titlu <<",Durata: " << f.durata<< ",Genul: "<<f.gen<<",Disponibil pe platforma(Da-1 si Nu-0): "<<f.disponibilPePlatforma<<",Nr ratinguri:"<<f.nrRatinguri<<",Ratingurile: ";
		for (int i = 0; i < f.nrRatinguri; i++)
		{
			out << f.ratinguri[i] << ",";
		}
		
		return out;
	}
	friend istream& operator>>(istream& in, Film& f)
	{
		cout << "Introduceti titlul: ";
		in >> ws;
		getline(in,f.titlu);
		cout << "Introduceti durata: ";
		in >> f.durata;
		cout << "Introduceti nr de ratinguri: ";
		in >> f.nrRatinguri;
		delete[]f.ratinguri;
		f.ratinguri = new float[f.nrRatinguri];
		for (int i = 0; i < f.nrRatinguri; i++)
		{
			cout << "Introduceti ratingul " << i + 1<<":";
			in >> f.ratinguri[i];
		}
		cout << "Introduceti genul: ";
		in >> ws;
		getline(in, f.gen);
		cout << "Introduceti daca este disponibil pe platforma(1-Da si 0-Nu): ";
		in >> f.disponibilPePlatforma;
		return in;
	}
	float calculareRatingMediu()
	{
		float s = 0;
		for (int i = 0; i < this->nrRatinguri; i++)
		{
			s += this->ratinguri[i];
		}
		return s / this->nrRatinguri;
	}
	explicit operator int()
	{
		return this->nrRatinguri;
	}
	explicit operator float()
	{
		float s = 0;
		for (int i = 0; i < this->nrRatinguri; i++)
		{
			s += this->ratinguri[i];
		}
		return s;

	}
	Film operator+(float durata)
	{
		Film copie = *this;
		copie.durata += durata;
		return copie;
	}
	float operator[](int index)
	{
		if (index >= 0 && index < this->nrRatinguri)
		{
			return this->ratinguri[index];
		}
		else
		{
			 return 0;
		}
	}
	float operator()()
	{
		return this->calculareRatingMediu();
	}
	bool operator!()
	{
		return this->durata > 0;
	}
	Film& operator+=(float valoare)
	{
		int copierating = this->nrRatinguri;
		float* copie = new float[copierating];
		for (int i = 0; i < this->nrRatinguri; i++)
		{
			copie[i] = this->ratinguri[i];
		}
		delete[]this->ratinguri;
		this->nrRatinguri++;
		this->ratinguri = new float[this->nrRatinguri];
		for (int i = 0; i < copierating; i++)
		{
			this->ratinguri[i] = copie[i];
		}
		this->ratinguri[this->nrRatinguri - 1] = valoare;
		return *this;
	}
	Film& operator++()
	{
		this->durata+=56;
		return *this;
	}
	Film operator++(int)
	{
		Film copie = *this;
		for (int i = 0; i < this->nrRatinguri; i++)
		{
			this->ratinguri[i]++;
		}
		return copie;
		
	}
	bool operator!=(Film f)
	{
		bool acelasi = true;
		if (this->titlu != f.titlu && this->durata != f.durata && this->nrRatinguri != f.nrRatinguri && this->gen != f.gen && this->disponibilPePlatforma != f.disponibilPePlatforma)
		{
			for (int i = 0; i < this->nrRatinguri; i++)
			{
				if (this->ratinguri[i] != f.ratinguri[i])
				{
					acelasi = true;
				}
				else
				{
					acelasi = false;
				}
			}
		}
		else
		{
			acelasi = false;
		}
		return acelasi;
	}
	
};
int main()
{
	Film f;
	float ratinguri1[5] = { 7.5,8.7,6.3,9.5,5.9 };
	Film f1("Endgame", 120, ratinguri1, 5, "Science Fiction", true);
	Film f2(f1);
	Film f3 = f;
	try
	{
		Film f4("", -40, nullptr, -7, "S", true);
	}
	catch(exception err)
	{
		cout << err.what() << endl << endl;
	}
	cout << f<<endl<<endl;
	cout << f1 << endl << endl;
	cout << f3 << endl << endl;
	cout << f2 << endl << endl;
	Film f5;
	//cin >> f5;
	cout << f5 << endl << endl;
	//cout << f5.calculareRatingMediu() << endl;
	cout << float(f1) << endl;
	cout << int(f1) << endl;
	Film f6 = f1 + 25.5;
	cout << f6<<endl;
	cout << f1[2] << endl;
	cout << f1[-5] << endl;
	cout << f1() << endl;
	cout << f1 << endl << endl;
	f1 += 8.9;
	cout << f1 << endl<<endl;
	Film f8 = ++f2;
	cout << f8 << endl << endl;
	cout << f2 << endl << endl;
	Film f9 = f1++;
	cout << f1 << endl << endl;
	cout << f9 << endl << endl;
	if (!f1)
	{
		cout << "Durata este mai mare ca 0";
	}
	else
	{
		cout << "Durata este mai mica ca 0";
	}
	cout << endl;
	if (f1 != f2)
	{
		cout << "Nu sunt aceleasi obiecte!";
	}
	else
	{
		cout << "Sunt aceleasi obiecte!";
	}

	return 0;
}