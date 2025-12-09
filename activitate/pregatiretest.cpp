#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//enum tipAgenda {
//	sim=15, telefon=35, ambele=55
//};
//
////vrei o functie globala de verificare daca exista o denumire intr-un vector
//bool existaInVector(string numeCautat, int dimensiuneVector, string* vectorFolosit) {
//	bool gasit = 0;//inseamna ca pornim de la premisa ca nu se afla numele cautat in agenda
//	for (int i = 0; i < dimensiuneVector; i++) {
//		if (numeCautat == vectorFolosit[i]) {
//			gasit = 1;//inseamna ca am gasit denumirea.
//		}
//	}
//	return gasit;
//}
//
//class AgendaTelefon {
//
//public:
//
//	string posesor;
//	int nrContacte;
//	string* numeContacte;
//	//alt atribut de tip enum si bool la alegere
//	tipAgenda agenda;
//	bool agendaFull;
//	//constructor fara parametri
//	AgendaTelefon() {
//		this->posesor = "X";
//		this->nrContacte = 0;
//		this->numeContacte = nullptr;
//		this->agenda = sim;
//		this->agendaFull = false;
//	}
//	//constructor cu un singur parametru
//	AgendaTelefon(string posesor) {
//		//validari 
//		// validarile pentru string, char* se fac pe numarul de caractere
//		//validarile pentru numerice direct pe valoare
//		//validarile se pun pe parametrii(de obicei ce este in dreapta egalului)
//		//daca faceti validari, trebuie sa puneti si RAMURA DE ELSE IN CONSTRUCTORI!!!!!
//		
//		//validare pentru string
//		if (posesor.size() >= 3) {
//			this->posesor = posesor;
//		}
//		else {
//			this->posesor = "Necunoscut";
//		}
//
//		this->nrContacte = 0;
//		this->numeContacte = nullptr;
//		this->agenda = sim;
//		this->agendaFull = false;
//	}
//
//	//AgendaTelefon(tipAgenda agenda) {
//	//	//validari 
//	//	// validarile pentru string, char* se fac pe numarul de caractere
//	//	//validarile pentru numerice direct pe valoare
//	//	//validarile se pun pe parametrii(de obicei ce este in dreapta egalului)
//	//	//daca faceti validari, trebuie sa puneti si RAMURA DE ELSE IN CONSTRUCTORI!!!!!
//
//	//	//validare pentru string
//	//	this->posesor = "X";
//	//	this->nrContacte = 0;
//	//	this->numeContacte = nullptr;
//	//	if (tolower(agenda) == sim) {
//	//		this->agenda = sim;
//	//	}
//	//	else if (tolower(agenda) == telefon) {
//	//		this->agenda = telefon;
//	//	}
//	//	else {
//	//		this->agenda = ambele;
//	//	}
//	//
//	//	this->agendaFull = false;
//	//}
//
//
//	//AgendaTelefon(int nrContacte) {
//	//	this->posesor = "X";
//	//	this->nrContacte = nrContacte;
//	//	this->numeContacte = new string[this->nrContacte];
//	//	for (int i = 0; i < this->nrContacte; i++) {
//	//		int valoare = i+1;
//	//		string aux = "Contact_" + to_string(valoare);
//	//		this->numeContacte[i] = aux;
//	//	}
//	//	this->agenda = sim;
//	//	this->agendaFull = false;
//	//}
//
//	//AgendaTelefon(string* numeContacte) {
//	//	this->posesor = "X";
//	//	this->nrContacte = sizeof(numeContacte)/sizeof(string);
//	//	this->numeContacte = new string[this->nrContacte];
//	//	for (int i = 0; i < this->nrContacte; i++) {
//	//		this->numeContacte[i] = numeContacte[i];
//	//	}
//	//	this->agenda = sim;
//	//	this->agendaFull = false;
//	//}
//	
//
//
//	//metoda care adauga un nou contact in lista de contacte (numele nu trebuie sa se mai regaseasca)
//	//metoda adauga de obicei doar modifica(asta inseamna ca in majoritatea cazurilor metoda va fi de tipul VOID)
//	void adaugaContact(string numeContact) {
//		bool gasitContact = existaInVector(numeContact, this->nrContacte, this->numeContacte);
//		if (gasitContact == 0) {//adica nu este in agenda
//			int copieNrContacte = this->nrContacte;
//			//string* shallowCopyDenumiri = this->numeContacte;//shallowCopy
//			string* copieDenumiriContacte = new string[copieNrContacte];
//			for (int i = 0; i < copieNrContacte; i++) {
//				copieDenumiriContacte[i] = this->numeContacte[i];
//			}
//			delete[]this->numeContacte;
//			this->nrContacte++;
//			this->numeContacte = new string[this->nrContacte];
//			for (int i = 0; i < copieNrContacte; i++) {
//				this->numeContacte[i] = copieDenumiriContacte[i];
//			}
//			this->numeContacte[this->nrContacte - 1] = numeContact;
//		
//		}
//	}
//	
//	
//	
//	//metoda de afisare
//
//	void afisare() {
//		cout <<"Posesor: " << this->posesor << endl;
//		cout << "Numar Contacte: " << this->nrContacte << endl;
//		cout << "Contacte: ";
//		for (int i = 0; i < this->nrContacte; i++) {
//			cout << this->numeContacte[i] << ", ";
//		}
//		cout << endl;
//		cout << "Tip Agenda(15-sim, 25-telefon, 35- ambele): ";
//		//cout << this->agenda << endl;
//		if (this->agenda == sim) {
//			cout << "Sim" << endl;
//		}
//		else if (this->agenda == telefon) {
//			cout << "Telefon" << endl;
//		}
//		else {
//			cout << "Ambele" << endl;
//		}
//		cout <<"Este agenda full? (1-Da sau 0-Nu): " << this->agendaFull << endl;
//	}
//};
//
//
//int main() {
//	AgendaTelefon at;//obiect construit pe baza constructorului fara parametrii
//	at.afisare();
//	cout << endl << "=========================================================" << endl << endl;
//	AgendaTelefon at1("Ionel");//obiect construit pe baza constructorului cu un parametru
//	at1.afisare();
//	cout << endl << "=========================================================" << endl << endl;
//
//	at1.adaugaContact("George");
//	at1.adaugaContact("George");
//	at1.adaugaContact("George");
//	at1.adaugaContact("Ionel");
//	at1.adaugaContact("Ionel");
//	at1.adaugaContact("Andrei");
//	at1.adaugaContact("David");
//	at1.afisare();
//	cout << endl << "=========================================================" << endl << endl;
//
//	//DEEP COPY SI SHALLOW COPY
//
//	//SHALLOW COPY INSEAMNA COPIE SUPERFICIALA 
//	//SHALLOW COPY SE COPIAZA DOAR ADRESA POINTERULUI, NU SI DATELE DIN SPATELE LUI
//
//	int* v1 = new int[2] {5, 6};
//	int* v2 = v1;//shallow copy
//
//	cout << v1 << endl;
//	cout << v2 << endl;
//	cout << v1[0] << endl;
//	cout << v2[0] << endl;
//	v2[0] = 98;
//
//	cout << v1[0] << endl;
//	cout << v2[0] << endl;
//
//	delete[]v1;
//
//	cout << v2[0];
//
//
//	cout << endl << endl << "=============================================" << endl << endl;
//	//DEEP COPY --> COPIE IN PROFUNZIME
//
//
//	int* v3 = new int[2] {5, 6};
//	int* v4 = new int[2];//deep copy
//
//	for (int i = 0; i < 2; i++) {
//		v4[i] = v3[i];
//	}
//
//	cout << v3 << endl;
//	cout << v4 << endl;
//	cout << v3[0] << endl;
//	cout << v4[0] << endl;
//	v4[0] = 98;
//
//	cout << v3[0] << endl;
//	cout << v4[0] << endl;
//
//	delete[]v3;
//
//	cout << v4[0] << endl;
//}
//
//
//
//
//



//
//
//
//
//
//class Masina {
//	string numarMasina;
//	double capacitateRezervor;
//	double capacitateCurenta;
//	int nrAlimentari;
//	double* alimentari;
//
//public:
//	//constructor cu un singur parametru (string)
//	
//	Masina(string numarMasina) {
//		this->numarMasina = numarMasina;
//		this->capacitateRezervor = 0;
//		this->capacitateCurenta = 0;
//		this->nrAlimentari = 0;
//		this->alimentari = nullptr;
//	}
//	//constructor cu parametri (numarMasina, capacitate rezervor)
//	Masina(string numarMasina, double capacitateRezervor) {
//		this->numarMasina = numarMasina;
//		this->capacitateRezervor = capacitateRezervor;
//		this->capacitateCurenta = 0;
//		this->nrAlimentari = 0;
//		this->alimentari = nullptr;
//	}
//	//constructor cu toti parametri (se vor adauga restrictii la nivelul vectorului de alimentari, daca se depaseste pentru 
//	//o alimentare capacitatea rezervorului, atunci aceasta se va inlocui cu capacitatea maxima a rezervorului)
//	Masina(string numarMasina, double capacitateRezervor, double capacitateCurenta, int nrAlimentari, double *alimentari) {
//		if (numarMasina.size() == 6 || numarMasina.size() == 7 || numarMasina.size() == 8) {
//			this->numarMasina = numarMasina;
//		}
//		else {
//			this->numarMasina = "AA00AAA";
//		}
//
//		if (capacitateRezervor > 0) {
//			this->capacitateRezervor = capacitateRezervor;
//		}
//		else {
//			this->capacitateRezervor = 0;
//		}
//		
//		if (capacitateCurenta > 0 && capacitateCurenta <= capacitateRezervor) {
//			this->capacitateCurenta = capacitateCurenta;
//		}
//		else if (capacitateCurenta < 0) {
//			this->capacitateCurenta = 0;
//		}
//		else {
//			this->capacitateCurenta = capacitateRezervor;
//		}
//
//		if (nrAlimentari > 0 && alimentari != nullptr) {
//			this->nrAlimentari = nrAlimentari;
//			this->alimentari = new double[this->nrAlimentari];
//			for (int i = 0; i < this->nrAlimentari; i++) {
//			/*	if (alimentari[i] + this->capacitateCurenta > this->capacitateRezervor) {
//					this->alimentari[i] = this->capacitateRezervor - this->capacitateCurenta;
//				}*/
//
//				if (alimentari[i] > this->capacitateRezervor) {
//					this->alimentari[i] = this->capacitateRezervor;
//				}
//				else {
//					this->alimentari[i] = alimentari[i];
//				}
//			}
//		}
//		else {
//			this->nrAlimentari = 0;
//			this->alimentari = nullptr;
//		}
//	}
//	
//	//metoda care adauga o noua alimentare tinand cont de restrictiile (capacitate curenta si capacitate rezervor)
//	void adaugaAlimentare(double alimentare) {
//		int copieNrAlimentari = this->nrAlimentari;
//		//double* copieAlimentari = this->alimentari;//shallowCopy
//		double* copieAlimentari= new double[copieNrAlimentari];
//		for (int i = 0; i < copieNrAlimentari; i++) {
//			copieAlimentari[i] = this->alimentari[i];
//		}
//		delete[]this->alimentari;
//		this->nrAlimentari++;
//		this->alimentari = new double[this->nrAlimentari];
//		for (int i = 0; i < copieNrAlimentari; i++) {
//			this->alimentari[i] = copieAlimentari[i];
//		}
//
//		if (alimentare + this->capacitateCurenta > this->capacitateRezervor) {
//			this->alimentari[this->nrAlimentari - 1] = this->capacitateRezervor - this->capacitateCurenta;
//		}
//		else {
//			this->alimentari[this->nrAlimentari - 1] = alimentare;
//		}
//	
//	}
//	
//	
//	
//	
//	
//	
//	//metoda de afisare dar care afiseaza in loc de vectorul de alimentari doar media tuturor alimentarilor
//
//	void afisareMasina() {
//		cout << this->numarMasina << endl;
//		cout << this->capacitateRezervor<<" L" << endl;
//		cout << this->capacitateCurenta << " L" << endl;
//		cout << this->nrAlimentari << endl;
//	/*	for (int i = 0; i < this->nrAlimentari; i++) {
//			cout << this->alimentari[i] << " L, ";
//		}*/
//		if (nrAlimentari > 0) {
//			float medieAlimentari = 0;
//			for (int i = 0; i < this->nrAlimentari; i++) {
//				medieAlimentari = medieAlimentari + this->alimentari[i];
//			}
//			medieAlimentari = medieAlimentari / this->nrAlimentari;
//			cout << medieAlimentari << " L " << endl;
//		}
//		else {
//			cout << 0 << " L " << endl;
//		}
//	
//		cout << endl;
//	}
//};
//
//
//int main() {
//	Masina m("B84TRT");
//	Masina m1("IF91TQE");
//	double vectAlimentari[] = { 35,76,33 };
//	Masina m2("B01POT", 40, 3, 3, vectAlimentari);
//
//	m.afisareMasina();
//	cout << endl << "================================" << endl;
//	m1.afisareMasina();
//	cout << endl << "================================" << endl;
//	m2.afisareMasina();
//	cout << endl << "================================" << endl;
//	m2.adaugaAlimentare(90);
//	m2.adaugaAlimentare(20);
//	m2.adaugaAlimentare(30);
//	m2.adaugaAlimentare(50);
//	m2.adaugaAlimentare(11);
//	m2.afisareMasina();
//	cout << endl << "================================" << endl;
//}


class Student {
	char* nume;
	int* note;
	int nrNote;
	string facultate;
public:
	Student() {
		this->nume = new char[strlen("X") + 1];
		strcpy(this->nume, "X");
		this->note = nullptr;
		this->nrNote = 0;
		this->facultate = "Y";
	}

	Student(const char* nume, string facultate) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->note = nullptr;
		this->nrNote = 0;
		this->facultate = facultate;
	}

	Student(const char* nume, int* note, int nrNote, string facultate) {
		if (strlen(nume) >= 3) {
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else {
			this->nume = new char[strlen("X") + 1];
			strcpy(this->nume, "X");
		}

		if (note != nullptr && nrNote > 0) {
			this->nrNote = nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				if (note[i] > 0 && note[i] <= 10) {
					this->note[i] = note[i];
				}
				else if (note[i] < 0) {
					this->note[i] = 1;
				}
				else {
					this->note[i] = 10;
				}
			}
		}
		else {
			this->note = nullptr;
			this->nrNote = 0;

		}

		if (facultate.size() >= 2) {
			this->facultate = facultate;
		}
		else {
			this->facultate = "Y";
		}
	}


	char* getNume() const {
		return this->nume;
	}

	void setNume(const char* nume) {
		if (strlen(nume) >= 3) {
			delete[]this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
	}


	int getNrNote()const {
		return this->nrNote;
	}

	void setNrNote(int nrNote) {
		if (nrNote > 0) {
			this->nrNote = nrNote;
		}
	}

	int* getNote()const {
		return this->note;
	}

	void setNote(int* note) {
		if (note != nullptr) {
			delete[]this->note;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				if (note[i] > 0 && note[i] <= 10) {
					this->note[i] = note[i];
				}
				else if (note[i] < 0) {
					this->note[i] = 1;
				}
				else {
					this->note[i] = 10;
				}
			}
		}
	}

	void setNoteVect(int nrNote, int* note) {
		if (note != nullptr && nrNote > 0) {
			delete[]this->note;
			this->nrNote = nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				if (note[i] > 0 && note[i] <= 10) {
					this->note[i] = note[i];
				}
				else if (note[i] < 0) {
					this->note[i] = 1;
				}
				else {
					this->note[i] = 10;
				}
			}
		}
	}

	float calculeazaMedie() {
		float medie = 0;
		for (int i = 0; i < this->nrNote; i++) {
			medie = medie + this->note[i];
		}
		return medie / this->nrNote;
	}


	void afiseaza() {
		cout << this->nume << endl;
		cout << this->nrNote << endl;
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << ", ";
		}
		cout << endl;
		cout << this->facultate << endl;
	}

	void afiseazaPeLinie() {
		cout << this->nume << ", ";
		cout << this->nrNote << " note,  ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << ", ";
		}
		cout << this->facultate << ", ";
	}

	void adaugaNota(int nota) {
		int copieNrNote = this->nrNote;
		//int* copieNrNote = this->note;//shallowCopy
		int* copieNote = new int[copieNrNote];
		for (int i = 0; i < copieNrNote; i++) {
			copieNote[i] = this->note[i];
		}
		delete[]this->note;
		this->nrNote++;
		this->note = new int[this->nrNote];
		for (int i = 0; i < copieNrNote; i++) {
			this->note[i] = copieNote[i];
		}
		this->note[this->nrNote - 1] = nota;

	}

	void eliminaUltimaNota() {
		if (this->nrNote > 1) {
			int copieNrNote = this->nrNote;
			//int* copieNrNote = this->note;//shallowCopy
			int* copieNote = new int[copieNrNote];
			for (int i = 0; i < copieNrNote; i++) {
				copieNote[i] = this->note[i];
			}
			delete[]this->note;
			this->nrNote--;
			this->note = new int[this->nrNote];
			for (int i = 0; i < nrNote; i++) {
				this->note[i] = copieNote[i];
			}
		}
	}

	void eliminaNotaCeruta(int nota) {
		int nrNoteGasite = 0;//aici o sa punem cate note gasim in vectorul nostru care sa corespunda cu parametru
		for (int i = 0; i < this->nrNote; i++) {
			if (note[i] == nota) {
				nrNoteGasite++;
			}
		}

		if (nrNoteGasite > 0) {
			int copieNrNote = this->nrNote;
			//int* copieNrNote = this->note;//shallowCopy
			int* copieNote = new int[copieNrNote];
			for (int i = 0; i < copieNrNote; i++) {
				copieNote[i] = this->note[i];
			}
			delete[]this->note;
			this->nrNote = this->nrNote - nrNoteGasite;
			this->note = new int[this->nrNote];
			int pozitie = 0;
			for (int i = 0; i < copieNrNote; i++) {
				if (copieNote[i] != nota) {
					this->note[pozitie] = copieNote[i];
					pozitie++;
				}
			}
		}
	}
};

int main() {
	Student s;//constructor fara param
	cout << s.getNume() << endl;
	cout << s.getNrNote() << endl;
	for (int i = 0; i < s.getNrNote(); i++) {
		cout << s.getNote()[i] << ", ";
	}
	cout << endl;

	s.setNume("Daniel");
	s.setNume("Xu");
	s.setNrNote(4);
	s.setNrNote(-5);
	int noteNoi[] = { 6,11,-1,5 };
	s.setNote(noteNoi);
	s.setNoteVect(4, noteNoi);
	cout << endl << endl;
	cout << s.getNume() << endl;
	cout << s.getNrNote() << endl;
	for (int i = 0; i < s.getNrNote(); i++) {
		cout << s.getNote()[i] << ", ";
	}
	cout << endl;
	cout << endl << "=========================================" << endl << endl;
	Student s1("Gica", "ASE");
	cout << s1.getNume() << endl;
	cout << s1.getNrNote() << endl;
	for (int i = 0; i < s1.getNrNote(); i++) {
		cout << s1.getNote()[i] << ", ";
	}
	cout << endl;
	cout << endl << "=========================================" << endl << endl;

	int note[] = { 9,11,-4 };
	Student s2("Georgica", note, 3, "UPB");
	cout << s2.getNume() << endl;
	cout << s2.getNrNote() << endl;
	for (int i = 0; i < s2.getNrNote(); i++) {
		cout << s2.getNote()[i] << ", ";
	}
	cout << endl << endl;


	cout << s2.calculeazaMedie() << endl;

	cout << endl << endl;

	s2.afiseaza();
	cout << endl << endl;
	s2.adaugaNota(10);
	s2.adaugaNota(7);
	s2.adaugaNota(8);
	s2.adaugaNota(9);
	s2.adaugaNota(10);
	s2.adaugaNota(10);
	s2.adaugaNota(10);
	s2.adaugaNota(8);
	s2.adaugaNota(10);
	cout << endl << endl;
	cout << endl << "=========================================" << endl << endl;
	s2.afiseaza();
	s2.eliminaUltimaNota();
	s2.afiseaza();

	cout << endl << endl;
	cout << endl << "=========================================" << endl << endl;
	s2.eliminaNotaCeruta(10);
	s2.afiseaza();


	cout << endl << endl;
	s2.afiseazaPeLinie();
}