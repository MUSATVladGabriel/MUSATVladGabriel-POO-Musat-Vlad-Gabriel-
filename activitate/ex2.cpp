#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Produs
{
	const string codDeBare;
	const int id;
	char* denumire;
	float* preturi;
	int nrpreturi;
	bool disponibil;
	string categorie;
	float rating;
	double greutate;
	static int nrproduse;
public:
	Produs() :id(++nrproduse), codDeBare("00AABB")
	{
		this->denumire = new char[strlen("Necunoscut") + 1];
		strcpy(this->denumire, "Necunoscut");
		this->nrpreturi = 0;
		this->preturi = NULL;
		this->disponibil = false;
		this->categorie = "Anonim";
		this->rating = 0;
		this->greutate = 0;
	}
	Produs(const char* denumire, float* preturi, int nrpreturi, bool disponibil, string categorie, float rating, double greutate, string codebare) :id(++nrproduse), codDeBare(codebare)
	{
		if (strlen(denumire) >= 3)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
		{
			this->denumire = new char[strlen("Necunoscut") + 1];
			strcpy(this->denumire, "Necunoscut");
			throw exception("Nu este produsul potrivit!");
		}
		if (nrpreturi > 0 && preturi != nullptr)
		{
			this->nrpreturi = nrpreturi;
			this->preturi = new float[this->nrpreturi];
			for (int i = 0; i < this->nrpreturi; i++)
			{
				this->preturi[i] = preturi[i];
			}
		}
		else
		{
			this->nrpreturi = 0;
			this->preturi = NULL;
			throw new exception("Cum domne sa n aiba pret?!");
		}
		this->disponibil = disponibil;
		if (categorie.size() >= 3)
		{
			this->categorie = categorie;
		}
		else
		{
			this->categorie = "Anonim";
			throw exception("Categorie busita!");
		}
		if (rating >= 0 && rating <= 10)
		{
			this->rating = rating;
		}
		else if (rating < 0)
		{
			this->rating = 0;

		}
		else
		{
			this->rating = 10;
		}
		if (greutate > 0)
		{
			this->greutate = greutate;
		}
		else
		{
			this->greutate = 0;
			throw exception("Greutate busita");
		}
	}
	Produs(const Produs& p) :id(p.id), codDeBare(p.codDeBare)
	{
		if (strlen(p.denumire) >= 3)
		{
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
		}
		else
		{
			this->denumire = new char[strlen("Necunoscut") + 1];
			strcpy(this->denumire, "Necunoscut");
			//throw exception("Nu este produsul potrivit!");
		}
		if (p.nrpreturi > 0 && p.preturi != nullptr)
		{
			this->nrpreturi = p.nrpreturi;
			this->preturi = new float[this->nrpreturi];
			for (int i = 0; i < this->nrpreturi; i++)
			{
				this->preturi[i] = p.preturi[i];
			}
		}
		else
		{
			this->nrpreturi = 0;
			this->preturi = NULL;
			//throw exception("Cum domne sa n aiba pret?!");
		}
		this->disponibil = p.disponibil;
		if ((p.categorie).size() >= 3)
		{
			this->categorie = p.categorie;
		}
		else
		{
			this->categorie = "Anonim";
			//throw exception("Categorie busita!");
		}
		if (p.rating >= 0 && p.rating <= 10)
		{
			this->rating = p.rating;
		}
		else if (p.rating < 0)
		{
			this->rating = 0;

		}
		else
		{
			this->rating = 10;
		}
		if (p.greutate > 0)
		{
			this->greutate = p.greutate;
		}
		else
		{
			this->greutate = 0;
			//throw exception("Greutate busita");
		}
	}
	Produs& operator=(const Produs& p)
	{
		if (this != &p)
		{
			if (strlen(p.denumire) >= 3)
			{
				delete[]this->denumire;
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy(this->denumire, p.denumire);
			}
			else
			{
				this->denumire = new char[strlen("Necunoscut") + 1];
				strcpy(this->denumire, "Necunoscut");
				//throw exception("Nu este produsul potrivit!");
			}
			if (p.nrpreturi > 0 && p.preturi != nullptr)
			{
				delete[]this->preturi;
				this->nrpreturi = p.nrpreturi;
				this->preturi = new float[this->nrpreturi];
				for (int i = 0; i < this->nrpreturi; i++)
				{
					this->preturi[i] = p.preturi[i];
				}
			}
			else
			{
				this->nrpreturi = 0;
				this->preturi = NULL;
				//throw exception("Cum domne sa n aiba pret?!");
			}
			this->disponibil = p.disponibil;
			if ((p.categorie).size() >= 3)
			{
				this->categorie = p.categorie;
			}
			else
			{
				this->categorie = "Anonim";
				//throw exception("Categorie busita!");
			}
			if (p.rating >= 0 && p.rating <= 10)
			{
				this->rating = p.rating;
			}
			else if (p.rating < 0)
			{
				this->rating = 0;

			}
			else
			{
				this->rating = 10;
			}
			if (p.greutate > 0)
			{
				this->greutate = p.greutate;
			}
			else
			{
				this->greutate = 0;
				//throw exception("Greutate busita");
			}
		}
		return *this;
	}
	~Produs()
	{
		if (this->preturi != nullptr && this->denumire != nullptr)
		{
			delete[]this->preturi;
			delete[]this->denumire;
		}
	}
	float* getpreturi()
	{
		float* copie = new float[this->nrpreturi];
		for (int i = 0; i < this->nrpreturi; i++)
		{
			copie[i] = this->preturi[i];
		}
		return copie;
	}
	const int getid()
	{
		return this->id;
	}
	char* getdenumire()
	{
		char* copie = new char[strlen(this->denumire) + 1];
		strcpy(copie, this->denumire);
		return copie;
	}
	int getnrpreturi()
	{
		return this->nrpreturi;
	}
	void setpreturi(int nrpreturi, float* preturi)
	{
		if (nrpreturi > 0 && preturi != nullptr)
		{
			this->nrpreturi = nrpreturi;
			delete[]this->preturi;
			this->preturi = new float[this->nrpreturi];
			for (int i = 0; i < this->nrpreturi; i++)
			{
				this->preturi[i] = preturi[i];
			}
		}
		else
		{
			throw new exception("Ai gresit preturile!");
		}
	}
	void setdenumire(const char* denumire)
	{
		if (strlen(denumire) >= 3)
		{
			delete[]this->denumire;
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
	}
	void setrating(float rating)
	{
		this->rating = rating;
	}
	float pretmediu()
	{
		float s = 0;
		for (int i = 0; i < this->nrpreturi; i++)
		{
			s += this->preturi[i];
		}
		return s / this->nrpreturi;
	}
	void adaugapret(float valoare)
	{
		float copienr = this->nrpreturi;
		float* copie = new float[this->nrpreturi];
		for (int i = 0; i < this->nrpreturi; i++)
		{
			copie[i] = this->preturi[i];
		}
		delete[]this->preturi;
		this->nrpreturi++;
		this->preturi = new float[this->nrpreturi];
		for (int i = 0; i < copienr; i++)
		{
			this->preturi[i] = copie[i];
		}
		this->preturi[this->nrpreturi - 1] = valoare;
	}
	friend ostream& operator<<(ostream& out, const Produs& p)
	{
		out << "Id:" << p.id << endl;
		out << "Cod de bare: " << p.codDeBare << endl;
		out << "Denumire: " << p.denumire << endl;
		out << "Nr de preturi: " << p.nrpreturi << endl;
		out << "Preturile sunt: ";
		for (int i = 0; i < p.nrpreturi; i++)
		{
			out << p.preturi[i] << " lei,";
		}

		out << endl;
		out << "Este disponibil(Da-1 si Nu-0): " << p.disponibil << endl;
		out << "Categorie: " << p.categorie << endl;
		out << "Rating: " << p.rating << endl;
		out << "Greutate: " << p.greutate << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Produs& p)
	{
		delete[]p.denumire;
		cout << "Introduceti denumirea: ";
		char aux[100];
		in >> ws;
		in.getline(aux, 99);
		p.denumire = new char[strlen(aux) + 1];
		strcpy(p.denumire, aux);
		cout << "Introduceti nr de preturi: ";
		in >> p.nrpreturi;
		delete[]p.preturi;
		p.preturi = new float[p.nrpreturi];
		for (int i = 0; i < p.nrpreturi; i++)
		{
			cout << "Introduceti pretul " << i + 1 << ": ";
			in >> p.preturi[i];
		}
		cout << "Introduceti daca este disponibil(1-da si 0-nu): ";
		in >> p.disponibil;
		cout << "Introduceti categoria: ";
		in >> ws;
		getline(in, p.categorie);
		cout << "Introduceti ratingul: ";
		in >> p.rating;
		cout << "Introduceti greutatea : ";
		in >> p.greutate;
		return in;
	}
	Produs operator+(double valoare)
	{
		Produs copie = *this;
		copie.greutate += valoare;
		return copie;
	}
	friend Produs operator+(double valoare, const Produs& p)
	{
		Produs copie = p;
		copie.rating = copie.rating + valoare;
		return copie;
	}
	Produs operator+(const Produs& p)
	{
		Produs copie = *this;
		copie.greutate += p.greutate;
		return copie;

	}
	Produs& operator-=(double rating)
	{
		this->rating -= rating;
		return *this;
	}
	bool operator==(Produs p)
	{
		bool diferit = false;
		if (strcmp(this->denumire, p.denumire) != 0 || this->nrpreturi != p.nrpreturi
			|| this->categorie != p.categorie || this->disponibil != p.disponibil || this->rating != p.rating || this->greutate != p.greutate)
		{
			diferit = true;
		}
		else
		{
			for (int i = 0; i < this->nrpreturi; i++)
			{
				if (this->preturi[i] != p.preturi[i])
				{
					diferit = true;
				}
			}
		}
		if (diferit == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Produs operator+(const Produs p)
	//{
	//	Produs aux = *this;
	//	int copienr = aux.nrpreturi;
	//	float* copie = new float[copienr];
	//	for (int i = 0; i < copienr; i++)
	//	{
	//		copie[i] = this->preturi[i];
	//	}
	//	delete[]this->preturi;
	//	aux.nrpreturi += p.nrpreturi;
	//	this->preturi = new float[aux.nrpreturi];
	//	for (int i = 0; i < copienr; i++)
	//	{
	//		aux.preturi[i] = copie[i];
	//	}
	//	for (int i = copienr; i < this->nrpreturi; i++)
	//	{
	//		aux.preturi[i] = p.preturi[i];
	//	}
	//	return aux;
	//}
	bool operator!()
	{
		return this->rating != 0;
	}
	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrpreturi)
		{
			return this->preturi[index];
		}
	}
	explicit operator float()
	{
		return this->nrpreturi;
	}
	explicit operator int()
	{
		int s = 0;
		for (int i = 0; i < this->nrpreturi; i++)
		{
			s += this->preturi[i];
		}
		return s / this->nrpreturi;
	}
	Produs operator++(int)
	{
		Produs copie = *this;
		for (int i = 0; i < this->nrpreturi; i++)
		{
			this->preturi[i]++;
		}
		return copie;
	}
	Produs& operator++()
	{
		this->greutate++;
		return *this;
	}
	float operator()()
	{
		return this->pretmediu();
	}

};
int Produs::nrproduse = 0;
int main()
{
	Produs p;
	float preturi1[] = { 10,15,18.5,17.9 };
	Produs p1("Milka cu oreo", preturi1, 4, true, "Dulciuri", 7.5, 150,"0099BCD3F");
	Produs p2(p);
	Produs p3;
	p3 = p1;
	cout << p3.getdenumire() << endl;
	cout << p2.getnrpreturi() << endl;
	p2.setdenumire("Branza de vaca");
	cout << p2.getdenumire() << endl;
	float* v = p1.getpreturi();
	for (int i = 0; i < p1.getnrpreturi(); i++)
	{
		cout <<v[i]<<" ";
	}
	cout << endl;
	cout << p << endl << endl;
	cout << p2 << endl << endl << p1 << endl << endl;
	cout << endl;
	cout << p1.pretmediu() << endl;
	p1.adaugapret(12.99);
	cout << p1 << endl << endl;
	cout << p3 << endl << endl;
	Produs p4;
	//cin >> p4;
	//cout << p4;
	try
	{
		
		Produs p7;
		p7.setpreturi(-5, preturi1);
		Produs("E", preturi1, 7, 1, "abcd", 7.2, 450, "ewrwrw");
		Produs("euro", preturi1, -5, 0, "Alab", 10, 80, "oadewew");
	}
	catch (exception* err)
	{
		cout << err->what() << endl << endl;
	}
	catch (exception er)
	{
		cout << er.what() << endl << endl;
	}
	Produs p5 = p1 + 250;
	cout << p5 << endl << endl;
	cout << p1 << endl << endl;
	Produs p6 = 0.3 + p1;
	cout << p6 << endl << endl;
	Produs p7 = p1 + p5;
	cout << p7 << endl;
	Produs p8;
	p8 = p1;
	p8 -= 1.2;
	cout << p8 << endl;
	float preturi2[] = { 12.9,17.12 };
	Produs p9("Danone", preturi2, 2, 1, "Dulciuri", 6.8, 250, "00001321312SADA");
	//Produs p10 = p1 + p9;
	//cout << p10 << endl << endl;
	//cout << p1 << endl << endl;
	//cout << p9 << endl << endl;
	if (p1 == p1)
	{
		cout << "Obiectele sunt identice.";
	}
	else
	{
		cout << "Obiectele sunt diferite.";
	}
	cout << endl;
	if (p1 == p9)
	{
		cout << "Obiectele sunt identice.";
	}
	else
	{
		cout << "Obiectele sunt diferite.";
	}
	cout << endl;
	if (!p1)
	{
		cout << "Ratingul este diferit de 0";
	}
	else
	{
		cout << "Ratingul este egal cu 0";
	}
	cout << endl;
	cout << (int)p1 << endl;
	cout << p9 << endl << endl;
	Produs p10 = ++p9;
	cout << p10 << endl << endl;
	cout << p9 << endl << endl;
	cout << p1 << endl << endl;
	Produs p11 = p1++;
	cout << p11 << endl << endl;
	cout << p1 << endl << endl;
	cout << p9() << endl;
	
}