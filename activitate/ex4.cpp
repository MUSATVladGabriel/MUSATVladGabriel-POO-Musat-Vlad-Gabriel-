#include<iostream>
#include<string>
#include<cstring>
using namespace std;
enum tip {Poveste=5,RPG=10,Shooter=15,Competitiv=20};
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
	JocVideo():id(++nrjocuri)
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
	JocVideo(const char* titlu,int durataJoc,float rating,const char* gen,bool disponibilPeSteam,tip Tip) :id(++nrjocuri)
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
		else if(rating<=0)
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
	JocVideo(const JocVideo& j):id(j.id)
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
		out << "Titlul: " << j.titlu<<endl;
		out << "Durata jocului: " << j.durataJoc<<endl;
		out << "Ratingul: " << j.rating<<endl;
		out << "Genul: " << j.gen << endl;
		out << "Disponibil pe steam(1-da 0-NU): " << j.disponibilPeSteam<<endl;
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


};
int JocVideo::nrjocuri = 0;
int main()
{
	JocVideo j;
	JocVideo j1("Counter Strike 2", 50, 6.5, "Peste 12 ani", 1,Shooter);
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
		j5.setgen("An");

	}
	catch(exception err)
	{
		cout << err.what() << endl << endl;
	}
	cout << (int)j3 << endl;
	cout << (float)j2 << endl;
}