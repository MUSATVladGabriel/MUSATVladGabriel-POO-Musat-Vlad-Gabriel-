#include<iostream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
enum tipspecializare { fullstack = 5, backend = 7, frontend = 8, devops = 9, necunoscut = 0 };
class Persoana
{
	char* nume;
	int varsta;
public:
	Persoana()
	{
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->varsta = 0;
	}
	Persoana(const char* nume, int varsta)
	{
		if (strlen(nume)>=3)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else 
		{
			throw exception("Nu stim numele");
			//this->nume = new char[strlen("Necunoscut") + 1];
			//strcpy(this->nume, "Necunoscut");
		}
		if (varsta > 0)
		{
			this->varsta = varsta;
		}
		else
		{
			throw exception("Nu i stim varsta!");
			//this->varsta = 0;
		}
	}
	Persoana(const Persoana& p)
	{
		if (p.nume != nullptr)
		{
			this->nume = new char[strlen(p.nume) + 1];
			strcpy(this->nume, p.nume);
		}
		else
		{
			//throw exception("Nu stim numele");
			this->nume = new char[strlen("Necunoscut") + 1];
			strcpy(this->nume, "Necunoscut");
		}
		if (p.varsta > 0)
		{
			this->varsta = p.varsta;
		}
		else
		{
			//throw exception("Nu i stim varsta!");
			this->varsta = 0;
		}
	}

	~Persoana()
	{
		delete[]this->nume;
	}
	char* getnume()
	{
		char* copie = new char[strlen(this->nume) + 1];
		strcpy(copie, this->nume);
		return copie;
	}
	int getvarsta()
	{
		return this->varsta;
	}
	void setvarsta(int varsta)
	{
		if (varsta > 0)
		{
			this->varsta = varsta;
		}

	}
	void setnume(const char* nume)
	{

		delete[]this->nume;
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}

	}
	Persoana& operator=(const Persoana& pe)
	{
		if (this != &pe)
		{
			if (pe.nume != nullptr)
			{
				delete[]this->nume;
				this->nume = new char[strlen(pe.nume) + 1];
				strcpy(this->nume, pe.nume);
			}
			else
			{
				//throw exception("Nu stim numele");
				this->nume = new char[strlen("Necunoscut") + 1];
				strcpy(this->nume, "Necunoscut");
			}
			if (pe.varsta > 0)
			{
				this->varsta = pe.varsta;
			}
			else
			{
				//throw exception("Nu i stim varsta!");
				this->varsta = 0;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Persoana& p);
	friend istream& operator>>(istream& in, Persoana& p);

};
istream& operator>>(istream& in, Persoana& p)
{

	char aux[100];
	cout << "Introduceti numele: ";
	in >> ws;
	in.getline(aux, 99);
	delete[]p.nume;
	p.nume = new char[strlen(aux) + 1];
	strcpy(p.nume, aux);
	cout << "Introduceti Varsta: ";
	in >> p.varsta;
	return in;
}
ostream& operator<<(ostream& out, const Persoana& p)
{
	out << "Numele: " << p.nume << endl;
	out << "Varsta: " << p.varsta << endl;
	return out;
}
class Angajat :public Persoana
{
	const double salariuminimacceptabil;
	char* numeManager;
	double salariu;
	int idAngajat;
public:
	Angajat() :Persoana(), salariuminimacceptabil(0)
	{
		this->numeManager = new char[strlen("Anonim") + 1];
		strcpy(this->numeManager, "Anonim");
		this->salariu = 0;
		this->idAngajat = 0;
	}
	Angajat(const char* numeManager, double salariu, int id, const char* nume, int varsta) :Persoana(nume, varsta), salariuminimacceptabil(500)
	{
		if (numeManager != nullptr)
		{
			this->numeManager = new char[strlen(numeManager) + 1];
			strcpy(this->numeManager, numeManager);
		}
		else
		{
			//throw exception("Nu exista numele managerului!");
			this->numeManager = new char[strlen("Anonim") + 1];
			strcpy(this->numeManager, "Anonim");
		}

		if (salariu > 0)
		{
			this->salariu = salariu;
		}
		else
		{
			//throw exception("Nu stim salariul angajatului!");
			this->salariu = 0;
			

		}

		if (id >= 0)
		{
			this->idAngajat = id;
		}
		else
		{
			//throw exception("Nu exista id-ul angajatului!");
			this->idAngajat = 0;
			

		}
	}
	Angajat(const Angajat& a) :Persoana(a), salariuminimacceptabil(1)
	{
		if (a.numeManager != nullptr)
		{
			this->numeManager = new char[strlen(a.numeManager) + 1];
			strcpy(this->numeManager, a.numeManager);
		}
		else
		{
			//throw exception("Nu exista numele managerului!");
			this->numeManager = new char[strlen("Anonim") + 1];
			strcpy(this->numeManager, "Anonim");
		}

		if (a.salariu > 0)
		{
			
			this->salariu = a.salariu;
		}
		else
		{
			//throw exception("Nu stim salariul angajatului!");
			this->salariu = 0;
		}

		if (a.idAngajat >= 0)
		{
			this->idAngajat = a.idAngajat;
		}
		else
		{
			//throw exception("Nu exista id-ul angajatului!");
			this->idAngajat = 0;
		}
	}
	~Angajat()
	{
		delete[]this->numeManager;
	}
	const int getsalariuminimacceptabil()
	{
		return this->salariuminimacceptabil;
	}
	char* getnumeManager()
	{
		char* copie = new char[strlen(this->numeManager) + 1];
		strcpy(copie, this->numeManager);
		return copie;
	}
	double getsalariu()
	{
		return this->salariu;
	}
	int getidAngajat()
	{
		return this->idAngajat;
	}
	void setidAngajat(int idAngajat)
	{
		if (idAngajat > 0)
		{
			this->idAngajat = idAngajat;
		}
	}
	void setsalariu(double salariu)
	{
		if (salariu > 0)
		{
			this->salariu = salariu;
		}
	}
	void setnumeManager(const char* numeManager)
	{
		delete[]this->numeManager;
		if (numeManager != nullptr)
		{
			this->numeManager = new char[strlen(numeManager) + 1];
			strcpy(this->numeManager, numeManager);
		}
	}
	Angajat& operator=(const Angajat& an)
	{
		if (this != &an)
		{
			Persoana::operator=(an);
			if (an.numeManager != nullptr)
			{
				delete[]this->numeManager;
				this->numeManager = new char[strlen(an.numeManager) + 1];
				strcpy(this->numeManager, an.numeManager);
			}
			else
			{
				//throw exception("Nu exista numele managerului!");
				this->numeManager = new char[strlen("Anonim") + 1];
				strcpy(this->numeManager, "Anonim");

			}

			if (an.salariu > 0)
			{
				this->salariu = an.salariu;
			}
			else
			{
				//throw exception("Nu stim salariul angajatului!");
				this->salariu = 0;
			}

			if (an.idAngajat >= 0)
			{
				this->idAngajat = an.idAngajat;
			}
			else
			{
				//throw exception("Nu exista id-ul angajatului!");
				this->idAngajat = 0;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Angajat& a);
	friend istream& operator>>(istream& in, Angajat& a);

};
ostream& operator<<(ostream& out, const Angajat& a)
{
	out << (Persoana)a;
	out << "Nume manager: " << a.numeManager << endl;
	out << "Salariul: " << a.salariu << endl;
	out << "ID: " << a.idAngajat << endl;
	return out;
}
istream& operator>>(istream& in, Angajat& a)
{
	in >> (Persoana&)a;
	cout << "Introduceti Nume manager: ";
	char aux[100];
	in >> ws;
	in.getline(aux, 99);
	delete[]a.numeManager;
	a.numeManager = new char[strlen(aux) + 1];
	strcpy(a.numeManager, aux);
	cout << "Introduceti Salariul: ";
	in >> a.salariu;
	cout << "Introduceti id: ";
	in >> a.idAngajat;
	return in;
}
class Programator :public Angajat
{
	char* limbajProgramareFolosit;
	tipspecializare specializare;
public:
	Programator() :Angajat()
	{
		this->limbajProgramareFolosit = new char[strlen("Niciunul") + 1];
		strcpy(this->limbajProgramareFolosit, "Niciunul");
		this->specializare = necunoscut;
	}
	Programator(const char* limbajProgramareFolosit, tipspecializare specializare, const char* numeManager, double salariu, int id, const char* nume, int varsta) :Angajat(numeManager, salariu, id, nume, varsta)
	{
		if (limbajProgramareFolosit != nullptr)
		{
			this->limbajProgramareFolosit = new char[strlen(limbajProgramareFolosit) + 1];
			strcpy(this->limbajProgramareFolosit, limbajProgramareFolosit);
		}
		else
		{
			//throw exception("Nu stie niciun limbaj de programare!");
			this->limbajProgramareFolosit = new char[strlen("Niciunul") + 1];
			strcpy(this->limbajProgramareFolosit, "Niciunul");
		}
		if (specializare != 0)
		{
			this->specializare = specializare;
		}
		else
		{
			//throw exception("Nu are nicio specializare!");
			this->specializare = necunoscut;
		}
	}
	Programator(const Programator& p) :Angajat(p)
	{
		if (p.limbajProgramareFolosit != nullptr)
		{
			this->limbajProgramareFolosit = new char[strlen(p.limbajProgramareFolosit) + 1];
			strcpy(this->limbajProgramareFolosit, p.limbajProgramareFolosit);
		}
		else
		{
			//throw exception("Nu stie niciun limbaj de programare!");
			this->limbajProgramareFolosit = new char[strlen("Niciunul") + 1];
			strcpy(this->limbajProgramareFolosit, "Niciunul");
		}
		if (p.specializare != 0)
		{
			this->specializare = p.specializare;
		}
		else
		{
			//throw exception("Nu are nicio specializare!");
			this->specializare = necunoscut;
		}
	}
	~Programator()
	{
		delete[]this->limbajProgramareFolosit;
	}
	Programator& operator=(const Programator& pr)
	{
		if (this != &pr)
		{
			Angajat::operator=(pr);
			if (pr.limbajProgramareFolosit != nullptr)
			{
				delete[]this->limbajProgramareFolosit;
				this->limbajProgramareFolosit = new char[strlen(pr.limbajProgramareFolosit) + 1];
				strcpy(this->limbajProgramareFolosit, pr.limbajProgramareFolosit);
			}
			else
			{
				//throw exception("Nu stie niciun limbaj de programare!");
				this->limbajProgramareFolosit = new char[strlen("Niciunul") + 1];
				strcpy(this->limbajProgramareFolosit, "Niciunul");
				

			}
			if (pr.specializare != 0)
			{
				this->specializare = pr.specializare;
			}
			else
			{
				//throw exception("Nu are nicio specializare!");
				this->specializare = necunoscut;
			}
		}
		return *this;
	}
	char* getlimbajProgramareFolosit()
	{
		char* copie = new char[strlen(this->limbajProgramareFolosit) + 1];
		strcpy(copie, this->limbajProgramareFolosit);
		return copie;
	}
	tipspecializare getspecializare()
	{
		return this->specializare;
	}
	void setlimbajProgramareFolosit(const char* limbajProgramareFolosit)
	{
		delete[]this->limbajProgramareFolosit;
		if (limbajProgramareFolosit != nullptr)
		{
			this->limbajProgramareFolosit = new char[strlen(limbajProgramareFolosit) + 1];
			strcpy(this->limbajProgramareFolosit, limbajProgramareFolosit);
		}
	}
	void setspecializare(tipspecializare specializare)
	{
		if (specializare != 0)
		{
			this->specializare = specializare;
		}
	}
	friend ostream& operator<<(ostream& out, const Programator& pr);
	friend istream& operator>>(istream& in, Programator& p);
};
ostream& operator<<(ostream& out, const Programator& pr)
{
	out << (Angajat)pr;
	out << "Limbajul de programare folosit este: " << pr.limbajProgramareFolosit << endl;
	out << "Specializarea este: ";
	if (pr.specializare == fullstack)
		out << "fullstack" << endl;
	else if (pr.specializare == backend)
		out << "backend" << endl;
	else if (pr.specializare == frontend)
		out << "frontend" << endl;
	else if (pr.specializare == necunoscut)
		out << "necunoscut" << endl;
	else if (pr.specializare == devops)
		out << "devops" << endl;
	return out;
}
istream& operator>>(istream& in, Programator& p)
{
	in >> (Angajat&)p;
	cout << "Introduceti limbajul de programare: ";
	char aux[100];
	in >> ws;
	in.getline(aux, 99);
	delete[]p.limbajProgramareFolosit;
	p.limbajProgramareFolosit = new char[strlen(aux) + 1];
	strcpy(p.limbajProgramareFolosit, aux);
	cout << "Introduceti specializarea: ";
	int tip;
	in >> tip;
	if (tip == 5)
		p.specializare = fullstack;
	else if (tip == 7)
		p.specializare = backend;
	else if (tip == 8)
		p.specializare = frontend;
	else if (tip == 9)
		p.specializare = devops;
	else if (tip == 0)
		p.specializare = necunoscut;
	return in;
}
class Departament
{
	string denumire;
	Angajat* pAngajati;
	int nrAngajati;
	static int nrtotalangajati;
public:
	Departament()
	{
		this->denumire = "Necunoscut";
		this->pAngajati = nullptr;
		this->nrAngajati = 0;
		nrtotalangajati += this->nrAngajati;
	}
	Departament(string denumire)
	{
		if (denumire.size() > 0)
		{
			this->denumire = denumire;
		}
		else
		{
			//throw exception("Nu stim denumirea departamentului!");
			this->denumire = "Necunoscuta";
			
		}
		this->pAngajati = nullptr;
		this->nrAngajati = 0;
		nrtotalangajati += this->nrAngajati;
	}
	Departament(string denumire, Angajat* pAngajati, int nrAngajati)
	{
		if (denumire.size() > 0)
		{
			this->denumire = denumire;
		}
		else
		{
			//throw exception("Nu stim denumirea departamentului!");
			this->denumire = "Necunoscuta";
			

		}
		if (nrAngajati > 0 && pAngajati != nullptr)
		{
			this->nrAngajati = nrAngajati;
			this->pAngajati = new Angajat[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++)
			{
				this->pAngajati[i] = pAngajati[i];
			}
		}
		else
		{
			//throw exception("Nu exista angajati in departament!");
			this->pAngajati = nullptr;
			this->nrAngajati = 0;
			

		}
		nrtotalangajati += this->nrAngajati;
	}
	Departament(const Departament& d)
	{
		if ((d.denumire).size() > 0)
		{
			this->denumire = d.denumire;
		}
		else
		{
			//throw exception("Nu stim denumirea departamentului!");
			this->denumire = "Necunoscuta";
			

		}
		if (d.nrAngajati > 0 && d.pAngajati != nullptr)
		{
			this->nrAngajati = d.nrAngajati;
			this->pAngajati = new Angajat[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++)
			{
				this->pAngajati[i] = d.pAngajati[i];
			}
		}
		else
		{
			//throw exception("Nu exista angajati in departament!");
			this->pAngajati = nullptr;
			this->nrAngajati = 0;
			
		}
		nrtotalangajati += this->nrAngajati;
	}
	~Departament()
	{
		delete[]this->pAngajati;
	}
	string getdenumire()
	{
		return this->denumire;
	}
	Angajat* getpAngajati()
	{
		Angajat* copie = new Angajat[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			copie[i] = this->pAngajati[i];
		}
		return copie;
	}
	int getnrAngajati()
	{
		return this->nrAngajati;
	}
	void setdenumire(string denumire)
	{
		if (denumire.size() > 0)
		{
			this->denumire = denumire;
		}
	}
	void setAngajati(Angajat* pAngajati, int nrAngajati)
	{
		delete[]this->pAngajati;
		if (pAngajati != nullptr && nrAngajati > 0)
		{
			this->nrAngajati = nrAngajati;
			this->pAngajati = new Angajat[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++)
			{
				this->pAngajati[i] = pAngajati[i];
			}
		}
	}
	Departament& operator=(const Departament& de)
	{
		if (this != &de)
		{
			if ((de.denumire).size() > 0)
			{
				this->denumire = de.denumire;
			}
			else
			{
				//throw exception("Nu stim denumirea departamentului!");
				this->denumire = "Necunoscuta";
				

			}
			if (de.nrAngajati > 0 && de.pAngajati != nullptr)
			{
				delete[]this->pAngajati;
				this->nrAngajati = de.nrAngajati;
				this->pAngajati = new Angajat[this->nrAngajati];
				for (int i = 0; i < this->nrAngajati; i++)
				{
					this->pAngajati[i] = de.pAngajati[i];
				}
			}
			else
			{
				//throw exception("Nu exista angajati in departament!");
				this->pAngajati = nullptr;
				this->nrAngajati = 0;
				

			}
			nrtotalangajati += this->nrAngajati;
		}
		return *this;
	}
	double cheltuieliSalariale()
	{
		double total = 0;
		for (int i = 0; i < this->nrAngajati; i++)
		{
			total += this->pAngajati[i].getsalariu();
		}
		return total;
	}
	friend ostream& operator<<(ostream& out, const Departament& d);
	friend istream& operator>>(istream& in, Departament& d);
};
ostream& operator<<(ostream& out, const Departament& d)
{
	out << "Denumire departament: " << d.denumire << endl;
	out << "Nr de angajati: " << d.nrAngajati << endl;
	out << "Angajatii sunt:\n ";
	for (int i = 0; i < d.nrAngajati; i++)
	{
		out << d.pAngajati[i] << "Urmatorul Angajat este:\n ";
	}
	out << "Nr total angajati: " << d.nrtotalangajati << endl;
	return out;
}
istream& operator>>(istream& in, Departament& d)
{
	cout << "Introduceti denumirea departamentului: ";
	in >> ws;
	getline(in, d.denumire);
	cout << "Introduceti nr de angajati: ";
	in >> d.nrAngajati;
	Departament::nrtotalangajati += d.nrAngajati;
	cout << "Introduceti Angajatii:" << endl;
	delete[]d.pAngajati;
	d.pAngajati = new Angajat[d.nrAngajati];
	for (int i = 0; i < d.nrAngajati; i++)
	{
		cout << "Angajat: " << i + 1 << ":\n";
		in >> d.pAngajati[i];
	}
	return in;
}
int Departament::nrtotalangajati = 0;
int main()
{
	Persoana p;
	Persoana p1(p);
	Persoana p2("Vasile Maftei", 54);
	Persoana p3;
	p3 = p2;
	cout << p3 << endl;
	cout << p2.getnume() << endl << endl;
	p2.setvarsta(34);
	cout << p2.getvarsta() << endl;
	p3.setnume("Marcel Ion");
	cout << p3.getnume() << endl << endl;
	cout << p3.getvarsta() << endl;
	cout << p << endl << endl;
	Persoana p4;
	//cin >> p4;
	cout << p4 << endl << endl<<endl<<endl<<endl<<endl;
	Angajat a;
	Angajat a1(a);
	cout << a << endl << endl;
	cout << a1 << endl << endl;
	Angajat a2("Ioana Stanciu", 20000.5, 135, "Alexandra Popescu", 29);
	cout << a2 << endl;
	Angajat a3;
	//cin >> a3;
	cout << a3 << endl<<endl;
	Angajat a4;
	a4 = a3;
	Angajat a5;
	a5 = a2;
	Angajat a6("Theodora Tudor", 7500.7, 143, "Marina Cristina", 34);
	cout << a5 << endl << endl;
	cout << a6 << endl << endl;
	Angajat a7("Maria Ioana", 6500.7, 143, "Mariana Cristiana", 34);
	Angajat a8("Maria Denisa", 5500, 123, "Claudia Maria", 22);
	cout << a8.getnumeManager()<<endl;
	cout << a8.getnume() << endl;
	cout << a8.getsalariu() << endl;
	cout << a8.getvarsta() << endl;
	cout << a4 << endl << endl << endl << endl << endl << endl;
	Programator pr;
	Programator pr1;
	pr1 = pr;
	Programator pr6(pr);
	cout << pr1 << endl << endl;
	Programator pr2("Java", backend, "Cristina Ana", 25000.7, 467, "Vlad Gigi", 23);
	cout << pr2 << endl << endl;
	Programator pr3(pr2);
	Programator pr7;
	pr7 = pr3;
	cout << pr3 << endl << endl;
	Programator pr4;
	//cin >> pr4;
	cout << pr4 << endl << endl;
	Programator pr5;
	pr5 = pr4;
	Programator pr8;
	Programator pr9("C#", devops, "Cristiana", 45000.32, 678, "Vlad Matei", 21);
	cout << pr9 << endl << endl;
	cout << pr9.getlimbajProgramareFolosit()<<endl;
	cout << pr9.getspecializare() << endl;
	cout << pr5 << endl << endl << endl << endl << endl << endl;
	Departament d;
	Departament d1(d);
	Departament d2;
	d2 = d1;
	cout << d << endl << endl;
	cout << d1 << endl << endl;
	Departament d3("Relatii cu clientii");
	cout << d3 << endl << endl;
	Angajat pAngajati1[4] = { a,a2,a6,a5 };
	Angajat pAngajati2[5] = { a2,a6,a5,a7,a8 };
	Departament d4("Cyber Security", pAngajati1, 4);
	Departament d5("Frontend developers", pAngajati2, 5);
	cout << d5 << endl << endl;
	cout << d5.cheltuieliSalariale() << endl;
	Departament d6;
	d6 = d5;
	Departament d7;
	d7 = d4;
	cout << d7 << endl << endl;
	cout << d7.getdenumire() << endl;
	cout << d.getnrAngajati() << endl;
	Angajat* angajati = d7.getpAngajati();
	for (int i = 0; i < d7.getnrAngajati(); i++)
	{
		cout << angajati[i] << endl;
	}
	d.setAngajati(pAngajati2, 5);
	cout << d.getnrAngajati() << endl;
	Angajat* angajati1 = d.getpAngajati();
	for (int i = 0; i < d.getnrAngajati(); i++)
	{
		cout << angajati1[i] << endl;
	}
	Departament d8;
	//cin >> d8;
	cout << d8 << endl << endl;
	delete[]angajati1;
	delete[] angajati;
	try
	{
		Persoana("", -20);
	}
	catch (exception er)
	{
		cout << er.what() << endl << endl;
	}
	return 0;
}