#include <iostream>
#include <string>
using namespace std;

class Prajitura {
	char* denumire;
	int nrCalorii;
	int nrIngrediente;
	double* gramajIngrediente;
	bool esteVegan;
	static int nrPrajituri;
	string numePrajitura;
public:
	Prajitura() {
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy_s(this->denumire, strlen("Anonim") + 1, "Anonim");
		this->nrCalorii = 0;
		this->nrIngrediente = 0;
		this->gramajIngrediente = nullptr;
		this->esteVegan = false;
		this->numePrajitura = "Anonim";
	}

	Prajitura(const char* _denumire , int _nrCalorii, int _nrIngrediente, double* _gramajIngrediente, bool _esteVegan, string _numePrajitura) {

		this->denumire = new char[strlen(_denumire) + 1];
		strcpy_s(this->denumire, strlen(_denumire) + 1, _denumire);
		this->nrCalorii = _nrCalorii;
		this->nrIngrediente = _nrIngrediente;
		if (_nrIngrediente > 0 && _gramajIngrediente != nullptr) {
			this->nrIngrediente = _nrIngrediente;
			this->gramajIngrediente = new double[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->gramajIngrediente[i] = _gramajIngrediente[i];
			}
		}
		this->esteVegan = _esteVegan;
		this->numePrajitura = _numePrajitura;

	}

	Prajitura(const Prajitura& p) {
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
		this->nrCalorii = p.nrCalorii;
		this->nrIngrediente = p.nrIngrediente;
		if (p.nrIngrediente > 0 && p.gramajIngrediente != nullptr) {
			this->nrIngrediente = p.nrIngrediente;
			this->gramajIngrediente = new double[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}
		}
		this->esteVegan = p.esteVegan;
		this->numePrajitura = p.numePrajitura;
	}

	string getNumePrajitura() {
		return this->numePrajitura;
	}

	static int getNrPrajitura() {
		return Prajitura::nrPrajituri;
	}

	void setNumePrajitura(string numePrajituraNoua) {
		if (this->numePrajitura != " ") {
			this->numePrajitura = numePrajituraNoua;
		}
	}

	void setNrPrajitura(int nrNouPrajitura) {
		if (nrPrajituri > 0) {
			nrPrajituri = nrNouPrajitura;
		}
	}

	int getGramajTotal() {
		int rez = 0;
		if (this->gramajIngrediente != nullptr) {
			for (int i = 0; i < this->nrIngrediente; i++) {
				rez += gramajIngrediente[i];
			}
		}
		return rez;
	}

	Prajitura operator=(const Prajitura& p) {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}

		if (this->gramajIngrediente != nullptr) {
			delete[] this->gramajIngrediente;
			this->gramajIngrediente = nullptr;
		}

		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
		this->nrCalorii = p.nrCalorii;
		this->nrIngrediente = p.nrIngrediente;
		if (p.nrIngrediente > 0 && p.gramajIngrediente != nullptr) {
			this->nrIngrediente = p.nrIngrediente;
			this->gramajIngrediente = new double[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++) {
				this->gramajIngrediente[i] = p.gramajIngrediente[i];
			}
		}
		this->esteVegan = p.esteVegan;
		this->numePrajitura = p.numePrajitura;

		return *this;
	}

	friend ostream& operator<<(ostream& out, const Prajitura& p);
	friend istream& operator>>(istream& in, Prajitura& p) {
		if (p.denumire != nullptr) {
			delete[] p.denumire;
			p.denumire = nullptr;
		} 
		cout << "Introduceti Denumirea: " << endl;
		string denumire;
		getline(in,denumire);
		p.denumire = new char[denumire.length() + 1];
		strcpy_s(p.denumire, denumire.length() + 1, denumire.data());
		cout << "Introduceri numar Calorii: " << endl;
		in >> p.nrCalorii;

		if (p.gramajIngrediente != nullptr) {
			delete[] p.gramajIngrediente;
			p.gramajIngrediente = nullptr;
		}
		cout << "Introduceti numar Ingrediente: "<<endl;
		in >> p.nrIngrediente;


		if (p.nrIngrediente <= 0) {
			p.nrIngrediente = 0;
			p.gramajIngrediente = nullptr;
		}
		else {
			cout << "Introduceti Gramajele: " << endl;
			p.gramajIngrediente = new double[p.nrIngrediente];
			for (int i = 0; i < p.nrIngrediente; i++) {
				in >> p.gramajIngrediente[i];
			}
		}
		cout << "Este Vegana? 1 pt Da 0 pt Nu: "<<endl;
		in >> p.esteVegan;

		in.ignore();
		cout << "Nume: " << endl;
		getline(in,p.numePrajitura);

		return in;
	}


	~Prajitura() {
		cout << "Apel Destructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}

		if (this->gramajIngrediente != nullptr) {
			delete[] this->gramajIngrediente;
			this->gramajIngrediente = nullptr;
		}
	}

};

ostream& operator<<(ostream& out, const Prajitura& p) {
	out << "-------------------------------------"<<endl;
	out << "Denumire: " << p.denumire<<endl;
	out << "Numar Calorii: " << p.nrCalorii<<endl;
	out << "Numar Ingrediente: " << p.nrIngrediente << endl;
	out << "Gramaj: " << endl;
	for (int i = 0; i < p.nrIngrediente; i++) {
		out << p.gramajIngrediente[i]<<endl;
	}
	out << "Este Vegan: " << p.esteVegan << endl;
	out << "Nume Prajitura: " << p.numePrajitura << endl;
	return out;
}

int main() {
	/*double gramaj[] = { 100,200 };
	Prajitura p1("Cake", 100, 2, gramaj,false, "Cake");
	cout << p1;
	Prajitura p2;
	p2 = p1;
	cout << p2<<endl;

	int gramajTotal = p1.getGramajTotal();
	cout << "Gramaj Total: " << gramajTotal;*/

	Prajitura p5;
	cin >> p5;
	cout << p5;
}