#include<iostream>
#include<string>
using namespace std;
class Sportiv
{
	char* nume;
	char* sport;
	float* performante;
	int nrPerformante;
	char* tara;
	bool activ;
	int salariu;
public:
	Sportiv()
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->sport = new char[strlen("X") + 1];
		strcpy(this->sport, "X");
		this->performante = nullptr;
		this->nrPerformante = 0;
		this->tara = new char[strlen("Y") + 1];
		strcpy(this->tara, "Y");
		this->activ = false;
		this->salariu = 0;
	}
	Sportiv(const char* nume, const char* sport, float* performante, int nrPerformante, const char* tara, bool activ,int salariu)
	{
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			this->nume = new char[strlen("Anonim") + 1];
			strcpy(this->nume, "Anonim");
		}
		if (sport != nullptr)
		{
			this->sport = new char[strlen(sport) + 1];
			strcpy(this->sport, sport);
		}
		else
		{
			this->sport = new char[strlen("X") + 1];
			strcpy(this->sport, "X");
		}
		if (nrPerformante > 0 && performante != nullptr)
		{
			this->nrPerformante = nrPerformante;
			this->performante = new float[this->nrPerformante];
			for (int i = 0; i < this->nrPerformante; i++)
			{
				this->performante[i] = performante[i];
			}
		}
		else
		{
			this->nrPerformante = 0;
			this->performante = nullptr;
		}
		if (tara != nullptr)
		{
			this->tara = new char[strlen(tara) + 1];
			strcpy(this->tara, tara);
		}
		else
		{
			this->tara = new char[strlen("Y") + 1];
			strcpy(this->tara, "Y");
		}
		this->activ = activ;
		if (salariu > 0)
		{
			this->salariu = salariu;
		}
		else
		{
			this->salariu = 0;
		}
	}
	Sportiv(const Sportiv& s)
	{
		if (s.nume != nullptr)
		{
			this->nume = new char[strlen(s.nume) + 1];
			strcpy(this->nume, s.nume);
		}
		else
		{
			this->nume = new char[strlen("Anonim") + 1];
			strcpy(this->nume, "Anonim");
		}
		if (s.sport != nullptr)
		{
			this->sport = new char[strlen(s.sport) + 1];
			strcpy(this->sport, s.sport);
		}
		else
		{
			this->sport = new char[strlen("X") + 1];
			strcpy(this->sport, "X");
		}
		if (s.nrPerformante > 0 && s.performante != nullptr)
		{
			this->nrPerformante = s.nrPerformante;
			this->performante = new float[this->nrPerformante];
			for (int i = 0; i < this->nrPerformante; i++)
			{
				this->performante[i] = s.performante[i];
			}
		}
		else
		{
			this->nrPerformante = 0;
			this->performante = nullptr;
		}
		if (s.tara != nullptr)
		{
			this->tara = new char[strlen(s.tara) + 1];
			strcpy(this->tara, s.tara);
		}
		else
		{
			this->tara = new char[strlen("Y") + 1];
			strcpy(this->tara, "Y");
		}
		this->activ = s.activ;
		if (s.salariu > 0)
		{
			this->salariu = s.salariu;
		}
		else
		{
			this->salariu = 0;
		}
	}
	 char* getnume()
	{
			char* copie = new char[strlen(this->nume) + 1];
			strcpy(copie, this->nume);
			return copie;
	}
	 char* getsport()
	 {
		 char* copie = new char[strlen(this->sport) + 1];
		 strcpy(copie, this->sport);
		 return copie;
	 }
	 int getnrPerformante()
	 {
		 return this->nrPerformante;
	}
	 float* getperformante()
	 {
		 float* copiep = new float[this->nrPerformante];
		 for (int i = 0; i < this->nrPerformante; i++)
		 {
			 copiep[i] = this->performante[i];
		 }
		 return copiep;
	 }
	 bool getactiv()
	 {
		 return this->activ;
	 }
	 void setperformante(int nrPerformante, float* performante)
	 {
		 delete[]this->performante;
		 this->nrPerformante = nrPerformante;
		 if (nrPerformante > 0)
		 {
			 this->performante = new float[this->nrPerformante];
			 for (int i = 0; i < this->nrPerformante; i++)
			 {
				 this->performante[i] = performante[i];
			 }
		 }
		 else
		 {
			 throw exception( "Nu exista acest sportiv!");
		 }
	 }
	 void setsport(const char* sport)
	 {
		 delete[]this->sport;
		 this->sport = new char[strlen(sport) + 1];
		 strcpy(this->sport, sport);
	 }
	 void setactiv(bool activ)
	 {
		 this->activ = activ;
	 }
	Sportiv& operator=(const Sportiv& s1)
	{
		if (this != &s1)
		{
			if (s1.nume != nullptr)
			{
				this->nume = new char[strlen(s1.nume) + 1];
				strcpy(this->nume, s1.nume);
			}
			else
			{
				this->nume = new char[strlen("Anonim") + 1];
				strcpy(this->nume, "Anonim");
			}
			if (s1.sport != nullptr)
			{
				this->sport = new char[strlen(s1.sport) + 1];
				strcpy(this->sport, s1.sport);
			}
			else
			{
				this->sport = new char[strlen("X") + 1];
				strcpy(this->sport, "X");
			}
			if (s1.nrPerformante > 0 && s1.performante != nullptr)
			{
				this->nrPerformante = s1.nrPerformante;
				this->performante = new float[this->nrPerformante];
				for (int i = 0; i < this->nrPerformante; i++)
				{
					this->performante[i] = s1.performante[i];
				}
			}
			else
			{
				this->nrPerformante = 0;
				this->performante = nullptr;
			}
			if (s1.tara != nullptr)
			{
				this->tara = new char[strlen(s1.tara) + 1];
				strcpy(this->tara, s1.tara);
			}
			else
			{
				this->tara = new char[strlen("Y") + 1];
				strcpy(this->tara, "Y");
			}
			this->activ = s1.activ;
			if (s1.salariu > 0)
			{
				this->salariu = s1.salariu;
			}
			else
			{
				this->salariu = 0;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Sportiv& s)
	{
		out << "Nume: " << s.nume << endl;
		out << "Sportul: " << s.sport << endl;
		out << "Nr performante: " << s.nrPerformante << endl;
		out << "Performantele: ";
		for(int i=0;i<s.nrPerformante;i++)
		{
			out << s.performante[i] << ",";
		}
		out << endl;
		out << "Tara: " << s.tara << endl;
		out << "Activ(Da-1 si Nu-0):" << s.activ << endl;
		out << "Salariul: " << s.salariu << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Sportiv& s)
	{
		delete[]s.nume;
		cout << "Introduceti numele:";
		char aux[100];
		in >> ws;
		in.getline(aux,99);
		s.nume = new char[strlen(aux) + 1];
		strcpy(s.nume, aux);
		delete[]s.sport;
		cout << "Introduceti sport:";
		char aux1[100];
		in >> ws;
		in.getline(aux1, 99);
		s.sport = new char[strlen(aux1) + 1];
		strcpy(s.sport, aux1);
		cout << "Introduceti nr de performante: ";
		in >> s.nrPerformante;
		delete[]s.performante;
		cout << "Introduceti performantele: ";
		s.performante = new float[s.nrPerformante];
		for (int i = 0; i < s.nrPerformante; i++)
		{
			cout << "Performanta " << i << ": ";
			in >> s.performante[i];
		}
		delete[]s.tara;
		cout << "Introduceti tara:";
		char aux2[100];
		in >> ws;
		in.getline(aux2, 99);
		s.tara = new char[strlen(aux2) + 1];
		strcpy(s.tara, aux2);
		cout << "Introduceti daca este activ(1-da si nu-0):";
		in >> s.activ;
		cout << "Introduceti salariul: ";
		in >> s.salariu;
		return in;
	}
	float getPerformantaMaxima()
	{
		float maxim = 0;
		for (int i = 0; i < this->nrPerformante; i++)
		{
			if (this->performante[i] > maxim)
			{
				maxim = this->performante[i];
			}
		}
		return maxim;
	}
	explicit operator int()
	{
		return this->nrPerformante;
	}
	explicit operator float()
	{
		float s=0;
		for (int i = 0; i < this->nrPerformante; i++)
		{
			s += this->performante[i];
		}
		return s / nrPerformante;
	}
	float operator()()
	{
		float s = 0;
		for (int i = 0; i < this->nrPerformante; i++)
		{
			s += this->performante[i];
		}
		return s / nrPerformante;
	}
	float operator[](int index)
	{
		if (index >= 0 && index < this->nrPerformante)
		{
			return this->performante[index];
		}
		else
		{
			return -0.01;
		}
	}
	//operator de pre incrementare++
	Sportiv& operator++()
	{
		this->salariu += 25000;
		return *this;
	}
	//operator post incrementare
	Sportiv operator++(int)
	{
		Sportiv copie = *this;
		for (int i = 0; i < this->nrPerformante; i++)
		{
			this->performante[i]++;
		}
		return copie;

	}
	bool operator!()
	{
		return this->salariu > 0;
	}
	Sportiv& operator+=(int prima)//obiect+=valoare
	{
		this->salariu += prima;
		return *this;
	}
	bool operator>=(int valoare)
	{
		return this->nrPerformante >= valoare;
	}
	bool operator>(Sportiv s)
	{
		return this->salariu > s.salariu;
	}
	friend bool operator!=(int valoare,Sportiv s)
	{
		return valoare != s.salariu;
	}
};
int main()
{
	Sportiv s;
	float performante[4] = { 6.7,5.6,9.5,8.7 };
	Sportiv s1("Maria Ioana", "Volei", performante, 4, "Romania", 1, 15000);
	cout << s << endl << endl;
	cout << s1<<endl<<endl;
	Sportiv s2(s1);
	cout << s2 << endl << endl;
	Sportiv s3;
	s3 = s;
	cout << s3 << endl << endl;
	Sportiv s4;
	//cin >> s4;
	cout << s4 << endl << endl;
	cout << s2.getPerformantaMaxima() << endl;
	cout << (int)s1 << endl;
	cout << (float)s1 << endl;
	cout << s1() << endl;
	cout << s1[3] << endl;
	Sportiv s5=++s1;
	cout << s1 << endl<<endl;
	cout << s5 << endl<<endl;
	Sportiv s6 = s1++;
	cout << s1 << endl << endl;
	cout << s6 << endl << endl;
	cout << !s1 << endl;
	s1 += 34000;
	cout << s1 << endl;
	if (s1 >= 6)
	{
		cout << "Are destule performante!";
	}
	else
	{
		cout << "Nu are destule performante";
	}
	cout << endl;
	if (s1 > s)
	{
		cout<<"Are salariul mai mare!";
	}
	else
	{
		cout << "Are salariul mai mic!";
	}
	cout << endl;
	if (74000 != s1)
	{
		cout << "Nu au acelasi salariu!";
	}
	else
	{
		cout << "Au acelasi salariu!";
	}
	cout << endl;
	try
	{
		s2.setperformante(-1, nullptr);
	}
	catch(exception& err)
	{
		cout << "Eroare: " << err.what() << endl << endl;
	}
}