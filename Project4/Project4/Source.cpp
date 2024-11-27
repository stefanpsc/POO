#include<iostream>
#include<string>
using namespace std;

class Prajitura {

	char* denumire;
	int nrCalorii;
	int nrIngrediente;
	double* gramajIngrediente;
	bool esteVegana;
	static int numarPrajituri;
	double pret;
public:
	Prajitura() {
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy_s(this->denumire, strlen("anonim")+1, "Anonim");
		this->nrCalorii = 0;
		this->nrIngrediente = 0;
		this->gramajIngrediente = nullptr;
		this->esteVegana = false;
		this->pret = 0;
	}
	static int getNrPrajituri() {
		return Prajitura::numarPrajituri;
	}
	double getPret() {
		return this->pret;

	}
	static void setNumarPrajituri(int numarNou) {
		if (numarNou > 0) {
			numarPrajituri = numarNou;
		}
		else {
			cout << "Valoarea trebuie sa fie mai mare decat 0";
		}
		
	}

	int getGramajTotal() {
		int rez = 0;
		for (int i = 0; i < this->nrIngrediente; i++)
			rez += this->gramajIngrediente[i];
		return rez;
	}

	void setPret(double pretNou) {
		if (pretNou > 0) {
			this->pret = pretNou;
		}
		else {
			cout << "Pretul trebuie sa fie mai mare decat 0";
		}
	}


	 Prajitura(const char* _denumire,int _nrCalorii, int _nrIngrediente, double* _gramajIngrediente, bool _esteVegana, double _pret) {
		if (_denumire != nullptr) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy_s(this->denumire, strlen(_denumire) + 1, _denumire);
		}
		else {
			this->denumire = nullptr;
		}
			this->nrCalorii = _nrCalorii;
			this->nrIngrediente = _nrIngrediente;
			if (_nrIngrediente > 0 && _gramajIngrediente != nullptr) {
				this->nrIngrediente = _nrIngrediente;
				this->gramajIngrediente = new double[this->nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++) {
					this->gramajIngrediente[i] = _gramajIngrediente[i];
				}
			}
			this->esteVegana = _esteVegana;
			this->pret = _pret;
		

	}

	Prajitura(const Prajitura& p) {
		if (p.denumire != nullptr) {
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
		}
		else {
			this->denumire = nullptr;
		}
			this->nrCalorii = p.nrCalorii;
			this->nrIngrediente = p.nrIngrediente;
			if (p.nrIngrediente > 0 && p.gramajIngrediente != nullptr) {
				this->nrIngrediente = p.nrIngrediente;
				this->gramajIngrediente = new double[this->nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++) {
					this->gramajIngrediente[i] = p.gramajIngrediente[i];
				}
			}
			this->esteVegana = p.esteVegana;
			this->pret = p.pret;
		
	}

	Prajitura& operator =(const Prajitura& p) {
		if (this != &p) {
			if (this->gramajIngrediente != nullptr) {
				delete[] this->gramajIngrediente;
				this->gramajIngrediente = nullptr;
			}

			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}

			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1];
				strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
			}
			else {
				this->denumire = nullptr;
			}
				this->nrCalorii = p.nrCalorii;
				this->nrIngrediente = p.nrIngrediente;
			if (p.nrIngrediente > 0 && p.gramajIngrediente != nullptr) {
					this->nrIngrediente = p.nrIngrediente;
					this->gramajIngrediente = new double[this->nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++) {
						this->gramajIngrediente[i] = p.gramajIngrediente[i];
				}
			}
				this->esteVegana = p.esteVegana;
				this->pret = p.pret;
			
		}
		return *this;
	}
	Prajitura& operator*=(int x) {
		if (x > 0 && nrIngrediente > 0 && gramajIngrediente != nullptr) {
			for (int i = 0; i < nrIngrediente; i++) {
				gramajIngrediente[i] *= x;
			}
		}
		return *this;
}

	friend ostream& operator<<(ostream& out, const Prajitura& p);
	friend istream& operator>>(istream& in, Prajitura& p) {
		
		if (p.denumire != nullptr) {
			delete[] p.denumire;
			p.denumire = nullptr;
		}
		cout << "Introduceti denumire" << endl;
		string denumire;
		getline(in, denumire);
		p.denumire = new char[denumire.length() + 1];
		strcpy_s(p.denumire, denumire.length() + 1, denumire.data());
		cout << "Introduceti Numar Calorii" << endl;
		in >> p.nrCalorii;
		
		if (p.gramajIngrediente != nullptr) {
			delete[]p.gramajIngrediente;
			p.gramajIngrediente = nullptr;
		}
		cout << "Introduceti Numar Ingrediente: " << endl;
		in >> p.nrIngrediente;
		if (p.nrIngrediente <= 0) {
			p.nrIngrediente = 0;
			p.gramajIngrediente = nullptr;
		}
		else {
			p.gramajIngrediente = new double[p.nrIngrediente];
			cout << "Introduceti gramajele: " <<endl;
			for ( int i = 0; i < p.nrIngrediente; i++)
			in >> p.gramajIngrediente[i];
		}

		cout << "Este vegana?1 pentru DA, 0 pentru NU " << endl;
		in >> p.esteVegana;
		cout << "pretul: "<<endl;
		in >> p.pret;

		return in;
	}

	~Prajitura() {
		if (this->gramajIngrediente != nullptr) {
			delete[] this->gramajIngrediente;
			this->gramajIngrediente = nullptr;
		}

		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}
};

ostream& operator<<(ostream& out, const Prajitura& p) {
	out << "-----------------------------------";
	out << "Denumire: " << p.denumire<<endl;
	out << "Calorii: " << p.nrCalorii<<endl;
	out << "Numar Ingrediente: " << p.nrIngrediente<<endl;
	out << "Gramaj ingrediente: "<<endl;
	for (int i = 0; i < p.nrIngrediente; i++) {
		out << p.gramajIngrediente[i]<<" ";
	}
	out << "Vegana?" << p.esteVegana<<endl;
	out << "Pret: " << p.pret << endl;
	out << "--------------------------------------";
	return out;
}

int main() {
	/*double gramaje[] = { 100.5, 50.3, 200.0 };
	Prajitura p2("Tiramisu", 450, 3, gramaje, false, 25.5);
	cout<<p2;*/
	Prajitura p4;
	cin >> p4;
	cout << p4<<endl;
	cout << p4.getGramajTotal() << endl;;

}