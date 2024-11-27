#include<iostream>
using namespace std;

class Masina {
	string model;
	int kilometraj;
	int nrAlimentari;
	float* alimentari;
public:
	Masina() {
		this->model = "Anonim";
		this->kilometraj = 0;
		this->nrAlimentari = 0;
		this->alimentari = nullptr;
	}

	Masina(string _model = "Anonim", int _kilometraj = 0, int _nrAlimentari = 0, float* _alimentari = nullptr) {
		this->model = _model;
		this->kilometraj = _kilometraj;
		if (_nrAlimentari > 0 && _alimentari != nullptr) {
			this->nrAlimentari = _nrAlimentari;
			this->alimentari = new float[this->nrAlimentari];
			for (int i = 0; i < this->nrAlimentari; i++) {
				this->alimentari[i] = _alimentari[i];
			}
		}
		else {
			this->nrAlimentari = 0;
			this->alimentari = nullptr;
		}

	}

	Masina(const Masina& m) {
		this->model = m.model;
		this->kilometraj = m.kilometraj;
		if (m.nrAlimentari > 0 && m.alimentari != nullptr) {
			this->nrAlimentari = m.nrAlimentari;
			this->alimentari = new float[this->nrAlimentari];
			for (int i = 0; i < this->nrAlimentari; i++) {
				this->alimentari[i] = m.alimentari[i];
			}
		}
		else {
			this->nrAlimentari = 0;
			this->alimentari = nullptr;
		}
	}
	void afisare() {
		cout << "\n------------------------------"<<endl;
		cout << "Model: " << this->model << endl;
		cout << "Kilometraj: " << this->kilometraj << endl;
		cout << "Numar Alimentari: " << this->nrAlimentari << endl;
		cout << "Alimentari: ";
		for (int i = 0; i < this->nrAlimentari; i++)
			cout << this->alimentari[i]<<" ";
		cout << "\n------------------------------";
	}
	~Masina() {
		cout << "Apel Destructor----------" << endl;
		if (this->alimentari != nullptr) {
			delete[] this->alimentari;
			this->alimentari = nullptr;
		}
	}
};

int main() {
	float* alimentari = new float[3] {100, 200, 300};
	Masina m1("Camaro", 19000, 2, alimentari);
	m1.afisare();
	Masina m2(m1);
	m2.afisare();
	

}