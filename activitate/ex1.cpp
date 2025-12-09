#include<iostream>
#include<string>
#include<cstring>
using namespace std;
enum tip { Poveste = 5, RPG = 10, Shooter = 15, Competitiv = 20 };
class JocVideo
{
	const int  id;
	char* titlu;
	int durataJoc;
	float rating;
	char* gen;
	bool disponibilPeSteam;
	tip Tip;
	static int nrjocuri;
public:
	JocVideo() :id(++nrjocuri)
	{
		this->titlu = new char[strlen("Necunoscut") + 1];
		strcpy(this->titlu, "Necunoscut");
		this->durataJoc = 0;
		this->rating = 0;
		this->gen = new char[strlen("X") + 1];
		strcpy(this->gen, "X");
		this->disponibilPeSteam = false;
		this->Tip = Competitiv;
	}
	JocVideo(const char* titlu, int durataJoc, float rating, const char* gen, bool disponibilPeSteam, tip Tip) :id(++nrjocuri)
	{
		if (strlen(titlu) >= 3)
		{
			this->titlu = new char[strlen(titlu) + 1];
			strcpy(this->titlu, titlu);
		}
		else
		{
			this->titlu = new char[strlen("Necunoscut") + 1];
			strcpy(this->titlu, "Necunoscut");
			throw exception("Nu este bun jocul!");
		}
		if (durataJoc > 0)
		{
			this->durataJoc = durataJoc;
		}
		else
		{
			this->durataJoc = 0;
			throw exception("Nu exista!");
		}
		if (rating > 0 && rating <= 10)
		{
			this->rating = rating;
		}
		else if (rating <= 0)
		{
			this->rating = 0;
		}
		else
		{
			this->rating = 10;
		}
		if (strlen(gen) >= 3)
		{
			this->gen = new char[strlen(gen) + 1];
			strcpy(this->gen, gen);
		}
		else
		{
			this->gen = new char[strlen("X") + 1];
			strcpy(this->gen, "X");
			throw exception("MAMAAMMAA");
		}
		this->disponibilPeSteam = disponibilPeSteam;
		this->Tip = Tip;
	}
	JocVideo(const JocVideo& j) :id(j.id)
	{
		if (strlen(j.titlu) >= 3)
		{
			this->titlu = new char[strlen(j.titlu) + 1];
			strcpy(this->titlu, j.titlu);
		}
		else
		{
			this->titlu = new char[strlen("Necunoscut") + 1];
			strcpy(this->titlu, "Necunoscut");
			//throw exception("Nu este bun jocul!");
		}
		if (j.durataJoc > 0)
		{
			this->durataJoc = j.durataJoc;
		}
		else
		{
			this->durataJoc = 0;
			//throw exception("Nu exista!");
		}
		if (j.rating > 0 && j.rating <= 10)
		{
			this->rating = j.rating;
		}
		else if (j.rating <= 0)
		{
			this->rating = 0;
		}
		else
		{
			this->rating = 10;
		}
		if (strlen(j.gen) >= 3)
		{
			this->gen = new char[strlen(j.gen) + 1];
			strcpy(this->gen, j.gen);
		}
		else
		{
			this->gen = new char[strlen("X") + 1];
			strcpy(this->gen, "X");
			//throw exception("MAMAAMMAA");
		}
		this->disponibilPeSteam = j.disponibilPeSteam;
		this->Tip = j.Tip;
	}
	char* getgen()
	{
		char* copie = new char[strlen(this->gen) + 1];
		strcpy(copie, this->gen);
		return copie;
	}
	bool getdisponibilpesteam()
	{
		return this->disponibilPeSteam;
	}
	const int getid()
	{
		return this->id;
	}
	string getTiptxt()
	{
		if (this->Tip == Poveste)
		{
			return "Poveste";
		}
		else if (this->Tip == RPG)
		{
			return "RPG";
		}
		else if (this->Tip == Shooter)
		{
			return "Shooter";
		}
		else
		{
			return "Competitiv";
		}
	}
	void setgen(const char* gen)
	{
		if (strlen(gen) >= 3)
		{
			delete[]this->gen;
			this->gen = new char[strlen(gen) + 1];
			strcpy(this->gen, gen);
		}
		else
		{
			throw exception("Nu exista jocul fmmm!");
		}
	}
	void setTip(tip Tip)
	{
		this->Tip = Tip;
	}
	void setdisponibilPesteam(bool dispnibilpesteam)
	{
		this->disponibilPeSteam = dispnibilpesteam;
	}
	~JocVideo()
	{
		if (this->titlu != nullptr && this->gen != nullptr)
		{
			delete[]this->titlu;
			delete[]this->gen;
		}
	}
	friend ostream& operator<<(ostream& out, JocVideo j)
	{
		out << "Id ul: " << j.id << endl;
		out << "Titlul: " << j.titlu << endl;
		out << "Durata jocului: " << j.durataJoc << endl;
		out << "Ratingul: " << j.rating << endl;
		out << "Genul: " << j.gen << endl;
		out << "Disponibil pe steam(1-da 0-NU): " << j.disponibilPeSteam << endl;
		out << "Tipul jocului: ";
		if (j.Tip == Poveste)
		{
			out << "Poveste";
		}
		else if (j.Tip == RPG)
		{
			out << "RPG";
		}
		else if (j.Tip == Shooter)
		{
			out << "Shooter";
		}
		else
		{
			out << "Competitiv";
		}
		return out;
	}
	JocVideo& operator=(const JocVideo& j)
	{
		if (this != &j)
		{
			if (strlen(j.titlu) >= 3)
			{
				this->titlu = new char[strlen(j.titlu) + 1];
				strcpy(this->titlu, j.titlu);
			}
			else
			{
				this->titlu = new char[strlen("Necunoscut") + 1];
				strcpy(this->titlu, "Necunoscut");
				//throw exception("Nu este bun jocul!");
			}
			if (j.durataJoc > 0)
			{
				this->durataJoc = j.durataJoc;
			}
			else
			{
				this->durataJoc = 0;
				//throw exception("Nu exista!");
			}
			if (j.rating > 0 && j.rating <= 10)
			{
				this->rating = j.rating;
			}
			else if (j.rating <= 0)
			{
				this->rating = 0;
			}
			else
			{
				this->rating = 10;
			}
			if (strlen(j.gen) >= 3)
			{
				this->gen = new char[strlen(j.gen) + 1];
				strcpy(this->gen, j.gen);
			}
			else
			{
				this->gen = new char[strlen("X") + 1];
				strcpy(this->gen, "X");
				//throw exception("MAMAAMMAA");
			}
			this->disponibilPeSteam = j.disponibilPeSteam;
			this->Tip = j.Tip;
		}
		return *this;
	}
	explicit operator float()
	{
		return this->rating;
	}
	explicit operator int()
	{
		return this->durataJoc;
	}
	JocVideo operator+(int valoare)
	{
		JocVideo copie = *this;
		copie.durataJoc = copie.durataJoc + valoare;
		return copie;
	}
	JocVideo& operator++()
	{
		this->rating++;
		return *this;
	}
	JocVideo operator++(int)
	{
		JocVideo copie = *this;
		this->durataJoc++;
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
			throw exception("Pune alt index bai nenicule!");
		}
	}
	char& operator()(char aux, int index)
	{
		if (index >= 0 && index < strlen(gen))
		{
			this->gen[index] = aux;
		}
		return this->gen[index];
	}
	JocVideo& operator += (const JocVideo& j)
	{
		this->durataJoc += j.durataJoc;
		return *this;
	}
	bool operator!()
	{
		if (!this->rating)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator==(JocVideo j)
	{
		bool diferit = false;
		if (strcmp(this->titlu, j.titlu) != 0 || strcmp(this->gen, j.gen) != 0 ||
			this->rating != j.rating || this->durataJoc != j.durataJoc ||
			this->disponibilPeSteam != j.disponibilPeSteam || this->Tip != j.Tip)
			diferit = true;
		
		if (diferit == true)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator>(JocVideo j)
	{
		return this->rating > j.rating;
	}
	friend istream& operator>>(istream& in, JocVideo& j)
	{
		delete[]j.titlu;
		cout << "Introduceti titlul: ";
		char aux[100];
		in >> ws;
		in.getline(aux, 99);
		j.titlu = new char[strlen(aux) + 1];
		strcpy(j.titlu, aux);
		cout << "Introduceti durata: ";
		in >> j.durataJoc;
		cout << "Introduceti ratingul: ";
		in >> j.rating;
		delete[]j.gen;
		cout << "Introduceti genul: ";
		char aux1[100];
		in >> ws;
		in.getline(aux1, 99);
		j.gen= new char[strlen(aux) + 1];
		strcpy(j.gen, aux);
		cout << "Introduceti daca este disponibil pe steam(1-Da si 0-NU): ";
		in >> j.disponibilPeSteam;
		cout << "Introduceti tipul(5 10 15 20): ";
		int tip;
		in >> tip;
		if (tip == 5)
			j.Tip = Poveste;
		else if (tip == 10)
			j.Tip == RPG;
		else if (tip == 15)
		{
			j.Tip = Shooter;
		}
		else
			j.Tip = Competitiv;
		return in;
	}

};
int JocVideo::nrjocuri = 0;
int main()
{
	JocVideo j;
	JocVideo j1("Counter Strike 2", 50, 6.5, "Peste 12 ani", 1, Shooter);
	cout << j << endl << endl;
	cout << j1 << endl << endl;
	JocVideo j2(j);
	JocVideo j3;
	j3 = j1;
	cout << j2 << endl << endl;
	cout << j3 << endl << endl;
	try
	{
		JocVideo j4("Oert", 25, 7.2, "ureche", 0, Competitiv);
		JocVideo j5;
		j5.setgen("Ant2");
		cout << j1[-5] << endl;
	}
	catch (exception err)
	{
		cout << err.what() << endl << endl;
	}
	cout << (int)j3 << endl;
	cout << (float)j2 << endl;
	cout << j1 << endl << endl;
	JocVideo j4 = j1 + 25;
	cout << j4 << endl << endl;
	cout << j4 << endl;
	JocVideo j5 = ++j4;
	cout << j4 << endl << endl;
	cout << j5 << endl << endl;
	cout << j1 << endl<<endl;
	JocVideo j6 = j1++;
	cout << j1 << endl << endl;
	cout << j6 << endl << endl;
	cout << j1[2] << endl;
	cout << j3('u', 1) << endl << endl;
	JocVideo j7("Clash Royale",4,6.2,"Pe telefon",0,RPG);
		j7+= j6;
		cout << j6 << endl << endl;
		cout << j7 << endl << endl;
		if (!j)
		{
			cout << "Este egal cu 0";
		}
		else
		{
			cout << "Este diferit de 0";
		}
		cout << endl << endl;
		if (j1 == j1)
		{
			cout << "Obiectele sunt identice.";
		}
		else
		{
			cout << "Obiectele nu sunt identice.";
		}
		cout << endl;
		if (j6 == j1)
		{
			cout << "Obiectele sunt identice.";
		}
		else
		{
			cout << "Obiectele nu sunt identice.";
		}
		cout << endl;
		if (j1 > j7)
		{
			cout << "Ratingul jocului 1 e mai mare!";
		}
		else
		{
			cout << "Ratingul jocului 1 e mai mic!";
		}
		cout << endl << endl;
		JocVideo j8;
		cin >> j8;
		cout << j8 << endl << endl;
}