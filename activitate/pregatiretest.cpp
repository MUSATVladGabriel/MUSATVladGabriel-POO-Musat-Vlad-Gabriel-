#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
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
