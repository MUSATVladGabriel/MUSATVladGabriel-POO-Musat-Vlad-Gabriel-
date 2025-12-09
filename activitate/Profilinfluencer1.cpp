#include<iostream>
using namespace std;
class ProfilInfluencer
{
	string numeCont;
	int numarUrmaritori;
	int numarPostari;
	int* aprecieriPostari;
public:
	ProfilInfluencer()
	{
		this->numeCont = "Necunoscut";
		this->numarUrmaritori = 0;
		this->numarPostari = 0;
		this->aprecieriPostari = nullptr;
	}
	string getnumeCont()
	{
		return this->numeCont;
	}
	int getnumarUrmaritori()
	{
		return this->numarUrmaritori;
	}
	void setnumeCont(string numeCont)
	{
		this->numeCont = numeCont;
	}
	void setnumarUrmaritori(int numarUrmaritori)
	{
		this->numarUrmaritori = numarUrmaritori;
	}
	ProfilInfluencer(string numeCont, int numarUrmaritori, int numarPostari, int* aprecieriPostari)
	{
		if (numeCont.size() > 0)
		{
			this->numeCont = numeCont;
		}
		else
		{
			this->numeCont = "Necunoscut";
		}
		if (numarUrmaritori > 1000)
		{
			this->numarUrmaritori = numarUrmaritori;
		}
		else
		{
			this->numarUrmaritori = 0;
		}
		if (numarPostari != 0 && aprecieriPostari != nullptr)
		{
			this->numarPostari = numarPostari;
			this->aprecieriPostari = new int[this->numarPostari];
			for (int i = 0; i < this->numarPostari; i++)
			{
				this->aprecieriPostari[i] = aprecieriPostari[i];
			}
		}
		else
		{
			this->numarPostari = 0;
			this->aprecieriPostari = nullptr;
		}

	}
	ProfilInfluencer(const ProfilInfluencer& p)
	{
		if (p.numeCont.size() > 0)
		{
			this->numeCont = p.numeCont;
		}
		else
		{
			this->numeCont = "Necunoscut";
		}
		if (p.numarUrmaritori > 1000)
		{
			this->numarUrmaritori = p.numarUrmaritori;
		}
		else
		{
			this->numarUrmaritori = 0;
		}
		if (p.numarPostari != 0 && p.aprecieriPostari != nullptr)
		{
			this->numarPostari = p.numarPostari;
			this->aprecieriPostari = new int[this->numarPostari];
			for (int i = 0; i < this->numarPostari; i++)
			{
				this->aprecieriPostari[i] = p.aprecieriPostari[i];
			}
		}
		else
		{
			this->numarPostari = 0;
			this->aprecieriPostari = nullptr;
		}

	}
	~ProfilInfluencer()
	{
		delete[]this->aprecieriPostari;
	}
	ProfilInfluencer& operator=(const ProfilInfluencer& pr)
	{
		if (this != &pr)
		{
			if (pr.numeCont.size() > 0)
			{
				this->numeCont = pr.numeCont;
			}
			else
			{
				this->numeCont = "Necunoscut";
			}
			if (pr.numarUrmaritori > 1000)
			{
				this->numarUrmaritori = pr.numarUrmaritori;
			}
			else
			{
				this->numarUrmaritori = 0;
			}
			if (pr.numarPostari != 0 && pr.aprecieriPostari != nullptr)
			{
				this->numarPostari = pr.numarPostari;
				this->aprecieriPostari = new int[this->numarPostari];
				for (int i = 0; i < this->numarPostari; i++)
				{
					this->aprecieriPostari[i] = pr.aprecieriPostari[i];
				}
			}
			else
			{
				this->numarPostari = 0;
				this->aprecieriPostari = nullptr;
			}
		}
		return *this;
	}
	void adaugaPostare(int aprecieri)
	{
		int copienumarPostari;
		copienumarPostari = this->numarPostari;
		int* copieaprecieriPostari = new int[copienumarPostari];
		for (int i = 0; i < copienumarPostari; i++)
		{
			copieaprecieriPostari[i] = this->aprecieriPostari[i];
		}
		delete[]this->aprecieriPostari;
		this->numarPostari++;
		this->aprecieriPostari = new int[this->numarPostari];
		for (int i = 0; i < copienumarPostari; i++)
		{
			this->aprecieriPostari[i] = copieaprecieriPostari[i];
		}
		this->aprecieriPostari[this->numarPostari - 1] = aprecieri;
	}
	friend ostream& operator<<(ostream& out, const ProfilInfluencer& p);
	friend istream& operator>>(istream& in, ProfilInfluencer& p);
};
ostream& operator<<(ostream& out, const ProfilInfluencer& p)
{
	out << p.numeCont << " " << p.numarUrmaritori << " urmaritori " << p.numarPostari << " postari si nr de aprecieri:";
	for (int i = 0; i < p.numarPostari; i++)
	{
		out << p.aprecieriPostari[i] << " ";
	}
	return out;
}
istream& operator>>(istream& in, ProfilInfluencer& p)
{
	cout << "Numele contului: ";
	in >> p.numeCont;
	cout << "Numar urmaritori: ";
	in >> p.numarUrmaritori;
	cout << "Numar postari: ";
	in >> p.numarPostari;
	cout << "Nr de aprecieri la postari: ";
	delete[]p.aprecieriPostari;
	 p.aprecieriPostari = new int[p.numarPostari];
	for (int i = 0; i < p.numarPostari; i++)
	{
		in >> p.aprecieriPostari[i];
	}
	return in;
}


int main()
{
	ProfilInfluencer p;
	p.setnumeCont("Alex");
	p.setnumarUrmaritori(2000);
	cout << "============= getteri ================="<<endl<<endl;
	cout << p.getnumarUrmaritori() << endl;
	cout << p.getnumeCont() << endl<<endl;
	cout << "============ operator<< ==============="<<endl<<endl;
	cout << p << endl<<endl;
	cout << "========= constructorcopiere =========="<<endl<<endl;
	ProfilInfluencer p1(p);
	cout << p1 << endl;
	int aprecieripostari1[5] = { 100000,250000,350000,80000,70000 };
	ProfilInfluencer p2("Selly", 2000000, 5, aprecieripostari1);
	ProfilInfluencer p3;
	cout << p2<<endl<<endl;
	
	cout <<"============= operator= ==============="<< endl<<endl;
	p3 = p2;
	cout << p3 << endl<<endl;
	cout << "======= metodadeadaugarepostare =======" << endl<<endl;
	p2.adaugaPostare(900000);
	cout << p2 << endl<<endl;
	cout << "=========== operator>> ================" << endl<<endl;
	ProfilInfluencer p4;
	cin >> p4;
	cout << p4 << endl;
}