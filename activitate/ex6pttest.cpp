#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Student
{
	const int id;
	char* nrmatricol;
	string nume;
	int nrnote;
	int* note;
	bool arebursa;
	static int nrstudenti;
public:
	Student():id(++nrstudenti)
	{
		this->nrmatricol = new char[strlen("X") + 1];
		strcpy(this->nrmatricol, "X");
		this->nume = "Anonim";
		this->nrnote = 0;
		this->note = nullptr;
		this->arebursa = false;
	}
	Student(string nume):id(++nrstudenti)
	{
		this->nrmatricol = new char[strlen("X") + 1];
		strcpy(this->nrmatricol, "X");
		if (nume.size() >= 3)
		{
			this->nume = nume;
		}
		else
		{
			this->nume = "Anonim";
		}
		this->nrnote = 0;
		this->note = nullptr;
		this->arebursa = false;
	}
	Student(int nrnote, int* note):id(++nrstudenti) 
	{
		this->nrmatricol = new char[strlen("X") + 1];
		strcpy(this->nrmatricol, "X");
		this->nume = "Anonim";
		if (nrnote > 0)
		{
			this->nrnote = nrnote;
			this->note = new int[this->nrnote];
				for (int i = 0; i < this->nrnote; i++)
				{
					this->note[i] = note[i];
				}
		}
		else
		{
			this->nrnote = 0;
			this->note = nullptr;
		}
		this->arebursa = false;
	}
	Student(char* nrmatricol, string nume, int nrnote, int* note, bool arebursa) :id(++nrstudenti)
	{
		if (strlen(nrmatricol) >= 5)
		{
			this->nrmatricol = new char[strlen(nrmatricol) + 1];
			strcpy(this->nrmatricol, nrmatricol);
		}
		else
		{
			this->nrmatricol = new char[strlen("X") + 1];
			strcpy(this->nrmatricol, "X");
		}
		if (nume.size() >= 3)
		{
			this->nume = nume;
		}
		else
		{
			this->nume = "Necunoscut";
		}
		if (nrnote > 0&& note!=nullptr)
		{
			this->nrnote = nrnote;
			this->note = new int[this->nrnote];
			for (int i = 0; i < this->nrnote; i++)
			{
				this->note[i] = note[i];
			}
		}
		else
		{
			this->nrnote = 0;
			this->note = nullptr;
		}
		this->arebursa = arebursa;
	}
	char* nrmatricol()
	{
		return this->nrmatricol;
	}
	int* getnote()
	{
		return this->note;
	}
	void setnrmatricol(char* nrmatricol)
	{
		if (strlen(nrmatricol) >= 5)
		{
			this->nrmatricol = new char[strlen(nrmatricol) + 1];
			strcpy(this->nrmatricol, nrmatricol);
		}
	}
	void setnote(int nrnote, int* note)
	{
		delete[]this->note;
		if (nrnote > 0 && note != nullptr)
		{
			this->nrnote = nrnote;
			this->note = new int[this->nrnote];
			for (int i = 0; i < this->nrnote; i++)
			{
				this->note[i] = note[i];
			}
		}
	}
	Student(const Student& s):id(++nrstudenti)
	{
		
			this->nrmatricol = new char[strlen(s.nrmatricol) + 1];
			strcpy(this->nrmatricol,s.nrmatricol);
	
		
			this->nume = s.nume;
		
		
			if (s.nrnote > 0 && s.note!=nullptr)
			{
				this->nrnote =s. nrnote;
				this->note = new int[this->nrnote];
				for (int i = 0; i < this->nrnote; i++)
				{
					this->note[i] =s. note[i];
				}
			}
		else
		{
			this->nrnote = 0;
			this->note = nullptr;
		}
		this->arebursa = s.arebursa;
	}
	Student& operator=(const Student& st)
	{
		if (this != &st)
		{
			delete[]this->nrmatricol;
			delete[]this->note;
			this->nrmatricol = new char[strlen(st.nrmatricol) + 1];
			strcpy(this->nrmatricol, st.nrmatricol);
			this->nume = st.nume;


			if (st.nrnote > 0 && st.note != nullptr)
			{
				this->nrnote = st.nrnote;
				this->note = new int[this->nrnote];
				for (int i = 0; i < this->nrnote; i++)
				{
					this->note[i] = st.note[i];
				}
			}
			else
			{
				this->nrnote = 0;
				this->note = nullptr;
			}
			this->arebursa = st.arebursa;
		}
		return *this;
	}
	void adauganota(int nota)
	{
		int copienrnote = this->nrnote;
		int* copienote = new int[copienrnote];
			for (int i = 0; i < copienrnote; i++)
			{
				copienote[i] = this->note[i];
			}
			delete[]this->note;
			this->nrnote++;
			this->note = new int[this->nrnote];
			for (int i = 0; i < copienrnote; i++)
			{
				this->note[i] = copienote[i];
			}
			this->note[this->nrnote - 1] = nota;	
			delete[]copienote;
	}
	void afisare()
	{
		cout << this->nume << endl;
		cout << this->nrmatricol << endl;
		cout << this->nrnote << endl;
		for (int i = 0; i < this->nrnote; i++)
		{
			cout << this->note[i] << ",";
		}
		cout << endl;
		cout << this->arebursa << endl;
		cout << endl;
	}
	~Student()
	{
		delete[]this->nrmatricol;
		delete[]this->note;
	}

};
int Student::nrstudenti = 0;
int main()
{
	Student s1;
	s1.afisare();
	Student s2("Yamal");
	s2.afisare();
	cout << endl << endl;
	int note1[] = { 6,7,10,9 };
	Student s3(4,note1);
	s3.afisare();
	s3.adauganota(9);

	s3.afisare();

}