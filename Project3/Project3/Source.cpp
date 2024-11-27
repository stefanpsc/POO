#include<iostream>;
#include<string>
using namespace std;

class Sejur {
	const int id;
	string destinatie;
	float pretBaza;
	int nrExcursiiOptionale;
	float* pretExcursie;
	string numeGhid;
	int durataSejur;
public:
	Sejur(int _id) :id(_id) {
		this->destinatie = "Anonima";
		this->pretBaza = 0;
		this->nrExcursiiOptionale = 0;
		this->pretExcursie = nullptr;
		this->numeGhid = "Anonim";
		this->durataSejur = 0;

	}
	Sejur(string _destinatie = "Anonima", float _pretBaza = 0, int _nrExcursiiOptionale = 0, float* _pretExcursie = nullptr, string _numeGhid = "Anonim", int _durataSejur = 0) :id(id) {
		this->destinatie = _destinatie;
		this->pretBaza = _pretBaza;
		this->nrExcursiiOptionale = _nrExcursiiOptionale;
		if (_nrExcursiiOptionale > 0 && _pretExcursie != nullptr) {
			this->nrExcursiiOptionale = _nrExcursiiOptionale;
			this->pretExcursie = new float[this->nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = _pretExcursie[i];
			}
		}
		this->numeGhid = _numeGhid;
		this->durataSejur = _durataSejur;
	}

	Sejur(const Sejur& s):id(id) {
		this->destinatie = s.destinatie;
		this->pretBaza = s.pretBaza;
		this->nrExcursiiOptionale = s.nrExcursiiOptionale;
		if (s.nrExcursiiOptionale > 0 && s.pretExcursie != nullptr) {
			this->nrExcursiiOptionale = s.nrExcursiiOptionale;
			this->pretExcursie = new float[this->nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = s.pretExcursie[i];
			}
		}
		this->numeGhid = s.numeGhid;
		this->durataSejur = s.durataSejur;
	}
	
	Sejur& operator=(const Sejur& s) {
		if (this != &s) {
			if (this->pretExcursie != nullptr) {
				delete[] this->pretExcursie;
				this->pretExcursie = nullptr;
			}

			this->destinatie = s.destinatie;
			this->pretBaza = s.pretBaza;
			this->nrExcursiiOptionale = s.nrExcursiiOptionale;
			if (s.nrExcursiiOptionale > 0 && s.pretExcursie != nullptr) {
				this->nrExcursiiOptionale = s.nrExcursiiOptionale;
				this->pretExcursie = new float[this->nrExcursiiOptionale];
				for (int i = 0; i < this->nrExcursiiOptionale; i++) {
					this->pretExcursie[i] = s.pretExcursie[i];
				}
			}
			this->numeGhid = s.numeGhid;
			this->durataSejur = s.durataSejur;

		}
	}

	const string getNumeGhid() {
		return this->numeGhid;
	}

	const int getDurataSejur() {
		return this->durataSejur;
	}

	void setNumeGhid(string numeGhid) {
		Sejur::numeGhid = numeGhid;
	}

	void setDurataSejur(int durataSejurNou) {
		if (this->durataSejur >= 1 && this->durataSejur <= 30) {
			durataSejur = durataSejurNou;
		}
		else {
			cout << "Vezi ca depaseste";
		}
	}


	friend ostream& operator<<(ostream& out, const Sejur& s);
	friend istream& operator>>(istream& in, Sejur& s) {
		cout << "Introduceti destinatia: " << endl;
		getline(in,s.destinatie);
		cout << "Introduceti Pret Baza: " << endl;
		in >> s.pretBaza;
		if (s.pretExcursie != nullptr) {
			delete[] s.pretExcursie;
			s.pretExcursie = nullptr;
		}
		cout << "Introduceti nr Excursii Optionale"<<endl;
		in >> s.nrExcursiiOptionale;
		if (s.nrExcursiiOptionale <= 0) {
			s.nrExcursiiOptionale = 0;
			s.pretExcursie = nullptr;
		}
		else {
			s.pretExcursie = new float[s.nrExcursiiOptionale];
			cout << "Introduceti Preturile: " << endl;
			for (int i = 0; i < s.nrExcursiiOptionale; i++) {
				
				in >> s.pretExcursie[i];
			}
		}

		
		cout << "Introduceti numele ghidului"<<endl;
		getline(in, s.numeGhid);
		cout << "Introduceti durata Sejurului in zile"<<endl;
		in >> s.durataSejur;
		return in;

	}
	~Sejur() {
		if (this->pretExcursie != nullptr) {
			delete[] this->pretExcursie;
			this->pretExcursie = nullptr;
		}
	}
};
ostream& operator<<(ostream& out, const Sejur& s) {
	cout << "-------------------------";
	cout << "ID: " << s.id<<endl;
	cout << "Destinatie: " << s.destinatie<<endl;
	cout << "Pret Baza: " << s.pretBaza << endl;
	cout << "Nr Excursii Optionale: " << s.nrExcursiiOptionale << endl;
	cout << "Pret Excursie: "<<endl;
	for (int i = 0; i < s.nrExcursiiOptionale; i++) {
		cout << s.pretExcursie[i] << " " << endl;
	}
	cout << "Nume Ghid: " << s.numeGhid << endl;
	cout << "Durata Sejur: " << s.durataSejur << endl;
	return out;
}


int main() {
	Sejur s1;
	cin >> s1;
	cout << s1;

}