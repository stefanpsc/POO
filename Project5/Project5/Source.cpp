#include <iostream>
using namespace std;

class Plantatie {
	const int id;
	string adresa;
	int nrPomi;
	int* varsta;
	static int varstaMinimaRod;
	string numeRoade;
	int numarRoade;
public:
	Plantatie(int _id):id(_id) {
		this->adresa = "Anonima";
		this->nrPomi = 0;
		this->varsta = nullptr;
		this->numeRoade = "Anonim";
		this->numarRoade = 0;

	}

	Plantatie(string _adresa = "Anonim", int _nrPomi = 0, int* _varsta = nullptr, string _numeRoade = "Anonim", int _numarRoade = 0) :id(id) {
		this->adresa = _adresa;
		this->nrPomi = _nrPomi;
		if (_nrPomi > 0 && _varsta != nullptr) {
			this->nrPomi = _nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++) {
				this->varsta[i] = _varsta[i];
			}
		}
		this->numeRoade = _numeRoade;
		this->numarRoade = _numarRoade;
	}

	Plantatie(const Plantatie& p):id(id){
		this->adresa = p.adresa;
		this->nrPomi = p.nrPomi;
		if (p.nrPomi > 0 && p.varsta != nullptr) {
			this->nrPomi = p.nrPomi;
			this->varsta = new int[this->nrPomi];
			for (int i = 0; i < this->nrPomi; i++) {
				this->varsta[i] = p.varsta[i];
			}
		}
		this->numeRoade = p.numeRoade;
		this->numarRoade = p.numarRoade;
	}

	Plantatie operator =(const Plantatie& p) {
		if (this != &p) {
			if (this->varsta != nullptr) {
				delete[]this->varsta;
				this->varsta = nullptr;
			}

			this->adresa = p.adresa;
			this->nrPomi = p.nrPomi;
			if (p.nrPomi > 0 && p.varsta != nullptr) {
				this->nrPomi = p.nrPomi;
				this->varsta = new int[this->nrPomi];
				for (int i = 0; i < this->nrPomi; i++) {
					this->varsta[i] = p.varsta[i];
				}
			}
			this->numeRoade = p.numeRoade;
			this->numarRoade = p.numarRoade;
		}
		return *this;
	}

	string getNumeRoade() {
		return this->numeRoade;

	}

	void setNumeRoade(string numeRoadeNoi) {
		if (numeRoadeNoi != "") {
			this->numeRoade = numeRoadeNoi;
		}
	}
	void setNumarRoade(int numarRoadeNoi) {
		if (numarRoadeNoi != 0) {
			this->numarRoade = numarRoadeNoi;
		}
	}
	int getNumarRoade() {
		return this->numarRoade;
	}

	int getNrPomiVarstaMinima(int varstaMinima) {
		int contor = 0;
		if (varsta != nullptr) {
			for (int i = 0; i <nrPomi; i++) {
				if (varsta[i] >= varstaMinima) {
					contor++;
				}
			}
		}
		return contor;
	}

	friend ostream& operator<<(ostream& out, const Plantatie& p);
	friend istream& operator>>(istream& in, Plantatie& p) {
		cout << "Introduceti Adresa: " << endl;
		in >> p.adresa;
		cout << "Introduceti Numar Pomi: " << endl;
		in >> p.nrPomi;
		if (p.nrPomi <= 0) {
			p.nrPomi = 0;
			p.varsta = nullptr;
		}
		else {
			p.varsta = new int[p.nrPomi];
			cout << "Introduceti Varsta: " << endl;
			for (int i = 0; i < p.nrPomi; i++) {
				in >> p.varsta[i];
			}
		}
		cout << "Introduceti nume Roade"<<endl;
		in >> p.numeRoade;
		cout << "Introduceti numar Roade" << endl;
		in >> p.numarRoade;

		return in;
	}

	bool operator ==(const Plantatie& p) const {
		if (this->id != p.id) {
			return false;
		}
		if (this->adresa != p.adresa) {
			return false;
		}
		if (this->nrPomi != p.nrPomi) {
			return false;
		}
		if (this->nrPomi > 0 && p.nrPomi > 0) {
			for (int i = 0; i < this->nrPomi; i++) {
				if (this->varsta[i] != p.varsta[i]) {
					return false;
				}
			}
		}
		if (this->numarRoade != p.numarRoade) {
			return false;
		}
		if (this->numeRoade != p.numeRoade) {
			return false;
		}
		return true;
	
	}

	operator int() const  {
		int contor = 0;

		if (varsta != nullptr) {
			for (int i = 0; i < nrPomi; i++) {
				if ( varsta[i] >= varstaMinimaRod) {
					contor++;
				}
			}
		}
		return contor;
	}

	~Plantatie() {
		if (this->varsta != nullptr) {
			delete[]this->varsta;
			this->varsta = nullptr;
		}
	}
};

int Plantatie::varstaMinimaRod =1;

ostream& operator<<(ostream& out, const Plantatie& p) {
	out << "---------------------------"<<endl;
	out << "Id: " << p.id << endl;
	out << "Adresa: " << p.adresa << endl;
	out << "Numar Pomi: " << p.nrPomi << endl;
	out << "Varsta: "<<endl;
	for (int i = 0; i < p.nrPomi; i++) {
		out << p.varsta[i]<<" "<<endl;
	}
	out << "Nume Roade: " << p.numeRoade << endl;
	out << "Numar Roade: " << p.numarRoade << endl;
	return out;
}

int main() {
	//Plantatie p;
	////cout << p;
	///*int varsta[] ={10,30};
	//Plantatie p2("Bradului", 2, varsta, "Caise", 100);*/
	//cin >> p;
	//cout << p<<endl;
	//cout<<p.getNumarRoade()<<endl;
	//cout << p.getNumeRoade()<<endl;
	//p.setNumarRoade(100);
	//cout << p;
	//p.setNumeRoade("Diamante");
	//cout << p;

	///*Plantatie p3;
	//p3 = p2;
	//cout << p3;*/

	int varsta1[] = { 100,200,300 };
	Plantatie p1("Bradului", 3, varsta1, "Caise", 100);

	int varsta2[] = { 1,2,3 };
	Plantatie p2("Bradului", 3, varsta2, "Caise", 100);

	cout << "p1==p2: " << (p1 == p2 ? "true" : "false") << endl;

	int pomicuRod = (int)p2;
	cout << "Pomi cu rod: " << pomicuRod<<endl;
}