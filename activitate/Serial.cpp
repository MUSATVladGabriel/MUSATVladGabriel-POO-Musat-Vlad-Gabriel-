#include<iostream>
using namespace std;

class Serial
{
	string titlu;
	int numarEpisoade;
	int* durateEpisoade;
	float ratingIMDB;
	string gen;
	bool esteFinalizat;
public:
	Serial()
	{
		this->titlu = "Anonim";
		this->numarEpisoade = 0;
		this->durateEpisoade = nullptr;
		this->ratingIMDB = 0;
		this->gen = "Necunoscut";
		this->esteFinalizat = false;
	}
	Serial(string titlu, int numarEpisoade, int* durateEpisoade, float ratingIMDB, string gen, bool esteFinalizat)
	{
		this->titlu = titlu;
		this->numarEpisoade = numarEpisoade;
		this->durateEpisoade = new int[this->numarEpisoade];
		for (int i = 0; i < this->numarEpisoade; i++)
		{
			this->durateEpisoade[i] = durateEpisoade[i];
		}
		this->ratingIMDB = ratingIMDB;
		this->gen = gen;
		this->esteFinalizat = esteFinalizat;
	}
	Serial(const Serial& s)
	{
		this->titlu = s.titlu;
		this->numarEpisoade = s.numarEpisoade;
		this->durateEpisoade = new int[this->numarEpisoade];
		for (int i = 0; i < this->numarEpisoade; i++)
		{
			this->durateEpisoade[i] = s.durateEpisoade[i];
		}
		this->ratingIMDB = s.ratingIMDB;
		this->gen = s.gen;
		this->esteFinalizat = s.esteFinalizat;
	}
	string getgen()
	{
		return this->gen;
	}
	bool getesteFinalizat()
	{
		return this->esteFinalizat;
	}
	void setgen(string gen)
	{
		this->gen = gen;
	}
	void setesteFinalizat(bool esteFinalizat)
	{
		this->esteFinalizat = esteFinalizat;
	}
	friend ostream& operator<<(ostream& out, const Serial& s);
	int calculeazaDurataTotala()
	{
		int s = 0;
		for (int i = 0; i < this->numarEpisoade; i++)
		{
			s += this->durateEpisoade[i];
			
		}
		return s;
	}
	explicit operator int()
	{
		return this->numarEpisoade;
	}
	explicit operator float()
	{
		int s = 0;
		for (int i = 0; i < this->numarEpisoade; i++)
		{
			s += this->durateEpisoade[i];
		}
		return s;
	}
	float operator()()
	{
		return this->ratingIMDB;
	}
	Serial operator+(int durata)
	{
		Serial aux = *this;
		int copienumarEpisoade = aux.numarEpisoade;
		int* copiedurateEpisoade = new int[copienumarEpisoade];
		for (int i = 0; i < copienumarEpisoade; i++)
		{
			copiedurateEpisoade[i] = aux.durateEpisoade[i];
		}
		delete[]aux.durateEpisoade;
		aux.numarEpisoade++;
		aux.durateEpisoade = new int[aux.numarEpisoade];
		for (int i = 0; i < copienumarEpisoade; i++)
		{
			aux.durateEpisoade[i] = copiedurateEpisoade[i];
		}
		aux.durateEpisoade[aux.numarEpisoade - 1] = durata;
		return aux;
	}
	~Serial()
	{
		delete[]this->durateEpisoade;
	}
};
ostream& operator<<(ostream& out, const Serial& s)
{
	out << s.titlu << "," << s.gen << "," << "(DA=1/NU=0) " << s.esteFinalizat<<", "<<s.ratingIMDB << "," << s.numarEpisoade << ",duratele: ";
	for (int i = 0; i < s.numarEpisoade; i++)
	{
		out << s.durateEpisoade[i] << ",";
	}
	return out;
}


int main()
{
	Serial s;
	Serial s1(s);
	int durateEpisoade1[4] = { 120,150,170,190 };
	Serial s2("Avengers", 4, durateEpisoade1, 7.5, "Science Fiction", 1);
	cout << s1<<endl<<endl;
	cout << s2<<endl<<endl;
	cout << s2.calculeazaDurataTotala() << endl << endl;
	cout << (float)s2 << endl;
	cout << (int)s1 << endl;
	cout << (int)s2 << endl;
	cout << s2() << endl;
	cout << s2 + 570 << endl << endl;
	cout << s1 + 670 << endl << endl;
	cout << s2.getgen() << endl;
	cout << s1.getesteFinalizat() << endl;
	s1.setgen("Thriller");
	cout << s1.getgen() << endl;
	s2.setesteFinalizat(false);
	cout << s2.getesteFinalizat() << endl;
}