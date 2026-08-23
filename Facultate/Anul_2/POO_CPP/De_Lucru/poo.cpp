#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // Pentru strcpy, strlen
using namespace std;

//
//class TrotinetaElectrica {
//private:
//	float nivelBaterie;
//	float consumPerKm;
//	float* kmPerSesiuneInchiriere;
//	int nrSesiuniInchiriere;
//
//public:
//	TrotinetaElectrica() {
//		nivelBaterie = 100;
//		consumPerKm = 0;
//		kmPerSesiuneInchiriere = nullptr;
//		nrSesiuniInchiriere = 0;
//	}
//
//	TrotinetaElectrica(float nivelBaterie, float consumPerKm, float* kmPerSesiuneInchiriere, int nrSesiuniInchiriere) : TrotinetaElectrica() {
//		this->nivelBaterie = nivelBaterie;
//		this->consumPerKm = consumPerKm;
//		this->nrSesiuniInchiriere = nrSesiuniInchiriere;
//		this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
//		for (int i = 0; i < this->nrSesiuniInchiriere; i++)
//			this->kmPerSesiuneInchiriere[i] = kmPerSesiuneInchiriere[i];
//	}
//
//	TrotinetaElectrica(const TrotinetaElectrica& t) {
//		this->nivelBaterie = t.nivelBaterie;
//		this->consumPerKm = t.consumPerKm;
//		this->nrSesiuniInchiriere = t.nrSesiuniInchiriere;
//		if (t.kmPerSesiuneInchiriere != nullptr) {
//			this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
//			for (int i = 0; i < this->nrSesiuniInchiriere; i++)
//				this->kmPerSesiuneInchiriere[i] = t.kmPerSesiuneInchiriere[i];
//		}
//		else this->kmPerSesiuneInchiriere = nullptr;
//	}
//
//	~TrotinetaElectrica() {
//		if (kmPerSesiuneInchiriere != nullptr) {
//			delete[] kmPerSesiuneInchiriere;
//			kmPerSesiuneInchiriere = nullptr;	
//		}
//	}
//
//	TrotinetaElectrica& operator=(const TrotinetaElectrica& t) {
//		if (this == &t)
//			return *this;
//		this->nivelBaterie = t.nivelBaterie;
//		this->consumPerKm = t.consumPerKm;
//		this->nrSesiuniInchiriere = t.nrSesiuniInchiriere;
//		if (this->kmPerSesiuneInchiriere != nullptr)
//			delete[] this->kmPerSesiuneInchiriere;
//		if (t.kmPerSesiuneInchiriere != nullptr) {
//			this->kmPerSesiuneInchiriere = new float[this->nrSesiuniInchiriere];
//			for (int i = 0; i < this->nrSesiuniInchiriere; i++)
//				this->kmPerSesiuneInchiriere[i] = t.kmPerSesiuneInchiriere[i];
//		}
//		else this->kmPerSesiuneInchiriere = nullptr;
//
//		return *this;
//	}
//
//	TrotinetaElectrica& operator+=(float sesiuneNoua) {
//		float* aux = new float[nrSesiuniInchiriere + 1];
//		for (int i = 0; i < nrSesiuniInchiriere; i++)
//			aux[i] = kmPerSesiuneInchiriere[i];
//		aux[nrSesiuniInchiriere] = sesiuneNoua;
//		if (kmPerSesiuneInchiriere != nullptr)
//			delete[] kmPerSesiuneInchiriere;
//		kmPerSesiuneInchiriere = aux;
//		nrSesiuniInchiriere++;
//		return *this;
//	}
//
//	float& operator[](int index) {
//		if (index >= 0 && index < nrSesiuniInchiriere)
//			return kmPerSesiuneInchiriere[index];
//	}
//
//	float operator()() {
//		return nivelBaterie / consumPerKm;
//	}
//
//	friend ostream& operator<<(ostream& out, const TrotinetaElectrica& t);
//};
//
//ostream& operator<<(ostream& out, const TrotinetaElectrica& t) {
//	out << "Nivel baterie: " << t.nivelBaterie << endl;
//	out << "Consum pe kilometru: " << t.consumPerKm << endl;
//	out << "Numar de sesiuni de inchiriat: " << t.nrSesiuniInchiriere << endl;
//	if (t.nrSesiuniInchiriere > 0) {
//		out << "Kilometrii pe sesiune de inchiriat: ";
//		for (int i = 0; i < t.nrSesiuniInchiriere; i++)
//			out << t.kmPerSesiuneInchiriere[i] << " ";
//	}
//
//	return out;
//}


//class Sejur {
//private:
//    const int id;
//    char* destinatie;
//    float pretBaza;
//    int nrExcursiiOptionale;
//    float* pretExcursie;
//    static int contorId;
//
//public:
//    Sejur() : id(0){
//        destinatie = nullptr;
//        pretBaza = 0;
//        nrExcursiiOptionale = 0;
//        pretExcursie = nullptr;
//        contorId++;
//    }
//
//    Sejur(int Id, char* destinatie, float pretBaza, int nrExcursiiOptionale, float* pretExcursie) : id(Id){
//        this->destinatie = new char[strlen(destinatie) + 1];
//        strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);
//        this->pretBaza = pretBaza;
//        this->nrExcursiiOptionale = nrExcursiiOptionale;
//        this->pretExcursie = new float[nrExcursiiOptionale];
//        for (int i = 0; i < nrExcursiiOptionale; i++)
//            this->pretExcursie[i] = pretExcursie[i];
//        contorId++;
//    }
//
//    ~Sejur() {
//        if (this->destinatie != nullptr)
//            delete[] this->destinatie;
//        if (this->pretExcursie != nullptr)
//            delete[] this->pretExcursie;
//        destinatie = nullptr;
//        pretExcursie = nullptr;
//        contorId--;
//    }
//
//    Sejur& operator=(const Sejur& s) {
//        if (this == &s)
//            return *this;
//        if (this->destinatie != nullptr)
//            delete[] this->destinatie;
//        this->destinatie = new char[strlen(destinatie) + 1];
//        strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);
//        this->pretBaza = s.pretBaza;
//        this->nrExcursiiOptionale = s.nrExcursiiOptionale;
//        if (this->pretExcursie != nullptr)
//            delete[] this->pretExcursie;
//        if (this->nrExcursiiOptionale > 0) {
//            this->pretExcursie = new float[s.nrExcursiiOptionale];
//            for (int i = 0; i < s.nrExcursiiOptionale; i++)
//                this->pretExcursie[i] = pretExcursie[i];
//        }
//        else this->pretExcursie = nullptr;
//
//        return *this;
//    }
//
//    operator float() const {
//        float sum = pretBaza;
//        for (int i = 0; i < nrExcursiiOptionale; i++)
//            sum += pretExcursie[i];
//        return sum;
//    }
//
//    Sejur operator--(int) {
//        Sejur copie = *this;
//        float min = pretExcursie[0], *aux;
//        int nr = 0, j = 0;
//        for (int i = 1; i < nrExcursiiOptionale; i++)
//            if (min > pretExcursie[i])
//                min = pretExcursie[i];
//        for (int i = 0; i < nrExcursiiOptionale; i++)
//            if (min == pretExcursie[i])
//                nr++;
//        aux = new float[nrExcursiiOptionale - nr];
//        for (int i = 0; i < nrExcursiiOptionale; i++)
//            if (min != pretExcursie[i]) {
//                aux[j] = pretExcursie[i];
//                j++;
//            }
//        delete[] pretExcursie;
//        pretExcursie = aux;
//        nrExcursiiOptionale -= nr;
//
//        return copie;
//    }
//
//    int getNrMaximExcursii(float bugetMaxim) {
//        int nr = 0;
//        for (int i = 1; i < nrExcursiiOptionale; i++)
//            if (bugetMaxim <= pretExcursie[i] + pretBaza)
//                nr++;
//
//        return nr;
//    }
//};
//
//int Sejur::contorId = 0;


//class RezervareBilet {
//protected:
//	int cod;
//	float pretBilete;
//	int rand;
//	char loc;
//public:
//	RezervareBilet() {
//		cod = 0;
//		pretBilete = 0;
//		rand = 0;
//		loc = ' ';
//	}
//	RezervareBilet(int cod, float pretBilete, int rand, char loc) : RezervareBilet() {
//		this->cod = cod;
//		this->rand = rand;
//		this->pretBilete = pretBilete;
//		this->loc = loc;
//	}
//	
//	RezervareBilet& operator=(const RezervareBilet& rb) {
//		this->cod = rb.cod;
//		this->rand = rb.rand;
//		this->pretBilete = rb.pretBilete;
//		this->loc = rb.loc;
//
//		return *this;
//	}
//
//	int getCod() {
//		return cod;
//	}
//	float getPretBilete() {
//		return pretBilete;
//	}
//	int getRand() {
//		return rand;
//	}
//	char getLoc() {
//		return loc;
//	}
//
//	void setCod(int cod) {
//		this->cod = cod;
//	}
//	void setPretBilete(float pretBilete) {
//		this->pretBilete = pretBilete;
//	}
//	void setRand(int rand) {
//		this->rand = rand;
//	}
//	void setLoc(char loc) {
//		this->loc = loc;
//	}
//
//	bool operator!=(const RezervareBilet& rb) {
//		return this->cod != rb.cod;
//	}
//
//	bool operator==(const RezervareBilet& rb) {
//		return this->cod == rb.cod;
//	}
//
//	RezervareBilet& operator++() {
//		pretBilete *= 1.1;
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream& out, const RezervareBilet& rb);
//};
//
//ostream& operator<<(ostream& out, const RezervareBilet& rb) {
//	out << "Cod: " << rb.cod << endl;
//	out << "Pret bilet: " << rb.pretBilete << endl;
//	out << "Rand: " << rb.rand << endl;
//	out << "Loc: " << rb.loc << endl;
//
//	return out;	
//}
//
//enum tipzbor { ECONOMIC = 1, BUSINESS = 2 };
//
//class Zbor{
//private:
//	char* nume;
//	char* destinatie;
//	int nrBilete;
//	RezervareBilet* bilete;
//	tipzbor tipZbor;
//public:
//	Zbor() {
//		nume = nullptr;
//		destinatie = nullptr;
//		bilete = nullptr;
//		nrBilete = 0;
//		tipZbor = ECONOMIC;
//	}
//
//	Zbor(char* nume, char* destinatie, int nrBilete, RezervareBilet* bilete, tipzbor tipZbor) : Zbor(){
//		this->nume = new char[strlen(nume) + 1];
//		strcpy_s(this->nume, strlen(nume) + 1, nume);
//		this->destinatie = new char[strlen(destinatie) + 1];
//		strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);
//		this->nrBilete = nrBilete;
//		this->bilete = new RezervareBilet[nrBilete];
//		for (int i = 0; i < nrBilete; i++)
//			this->bilete[i] = bilete[i];
//		this->tipZbor = tipZbor;
//	}
//
//	~Zbor() {
//		if (nume != nullptr) {
//			delete[] nume;
//			nume = nullptr;
//		}
//		if (destinatie != nullptr) {
//			delete[] destinatie;
//			destinatie = nullptr;
//		}
//		if (bilete != nullptr) {
//			delete[] bilete;
//			bilete = nullptr;
//		}
//	}
//
//	Zbor& operator=(const Zbor& z) {
//		if (this->nume != nullptr)
//			delete[] this->nume;
//		this->nume = new char[strlen(z.nume) + 1];
//		strcpy_s(this->nume, strlen(z.nume) + 1, z.nume);
//		if(this->destinatie != nullptr)
//			delete[] this->destinatie;
//		this->destinatie = new char[strlen(z.destinatie) + 1];
//		strcpy_s(this->destinatie, strlen(z.destinatie) + 1, z.destinatie);
//		this->nrBilete = z.nrBilete;
//		if (this->bilete != nullptr)
//			delete[] this->bilete;
//		if (this->nrBilete > 0) {
//			this->bilete = new RezervareBilet[z.nrBilete];
//			for (int i = 0; i < nrBilete; i++)
//				this->bilete[i] = bilete[i];
//		}
//		else this->bilete = nullptr;
//		this->tipZbor = tipZbor;
//
//		return *this;
//	}
//
//	Zbor operator+(const RezervareBilet& rb) {
//		Zbor z = *this;
//		for (int i = 0; i < nrBilete; i++)
//			if (bilete[i] == rb)
//				return *this;
//		delete[] z.bilete;
//		z.bilete = new RezervareBilet[z.nrBilete + 1];
//		for (int i = 0; i < nrBilete; i++)
//			z.bilete[i] = this->bilete[i];
//		z.bilete[z.nrBilete] = rb;
//		z.nrBilete++;
//		return z;
//	}
//
//	bool operator>(const Zbor& z) {
//		return this->nrBilete > z.nrBilete;
//	}
//};

//class Tramvai {
//protected:
//	const int nrTramvai;
//	char* numeVatman;
//	int nrStatii;
//	int* minStatii;
//public:
//	Tramvai() : nrTramvai(0){
//		numeVatman = nullptr;
//		nrStatii = 0;
//		minStatii = nullptr;
//	}
//
//	Tramvai(int NrTramvai, char* numeVatman, int nrStatii, int* minStatii) : nrTramvai(NrTramvai){
//		this->numeVatman = new char[strlen(numeVatman) + 1];
//		strcpy_s(this->numeVatman, strlen(numeVatman) + 1, numeVatman);
//		this->nrStatii = nrStatii;
//		if (this->nrStatii > 0) {
//			this->minStatii = new int[this->nrStatii];
//			for (int i = 0; i < this->nrStatii; i++)
//				this->minStatii[i] = minStatii[i];
//		}
//	}
//
//	Tramvai(const Tramvai& t) : nrTramvai(t.nrTramvai){
//		this->numeVatman = new char[strlen(t.numeVatman) + 1];
//		strcpy_s(this->numeVatman, strlen(t.numeVatman) + 1, t.numeVatman);
//		this->nrStatii = t.nrStatii;
//		if (this->nrStatii > 0) {
//			this->minStatii = new int[this->nrStatii];
//			for (int i = 0; i < this->nrStatii; i++)
//				this->minStatii[i] = t.minStatii[i];
//		}
//	}
//
//	virtual ~Tramvai() {
//		if (numeVatman != nullptr) {
//			delete[] numeVatman;
//			numeVatman = nullptr;
//		}
//		if (minStatii != nullptr) {
//			delete[] minStatii;
//			minStatii = nullptr;
//		}
//	}
//
//	Tramvai& operator=(const Tramvai& t){
//		if (this == &t)
//			return *this;
//		
//		if (numeVatman != nullptr) {
//			delete[] numeVatman;
//			numeVatman = nullptr;
//		}
//		if (minStatii != nullptr) {
//			delete[] minStatii;
//			minStatii = nullptr;
//		}
//		this->numeVatman = new char[strlen(t.numeVatman) + 1];
//		strcpy_s(this->numeVatman, strlen(t.numeVatman) + 1, t.numeVatman);
//		this->nrStatii = t.nrStatii;
//		if (this->nrStatii > 0) {
//			this->minStatii = new int[this->nrStatii];
//			for (int i = 0; i < this->nrStatii; i++)
//				this->minStatii[i] = t.minStatii[i];
//		}
//
//		return *this;
//	}
//
//	int calculMinuteStationate(int indexStart, int indexEnd) {
//		int sum = 0;
//		for (int i = indexStart; i < indexEnd; i++)
//			sum += minStatii[i];
//		return sum;
//	}
//
//	virtual int totalMinuteStationate() {
//		return calculMinuteStationate(0, nrStatii);
//	}
//
//	void adaugaStatie(int nrMinute) {
//		int* aux = new int[nrStatii + 1];
//		for (int i = 0; i < nrStatii; i++)
//			aux[i] = minStatii[i];
//		aux[nrStatii] = nrMinute;
//		nrStatii++;
//		delete[] minStatii;
//		minStatii = aux;
//	}
//
//	int& operator[](int index) {
//		if (index >= 0 && index < nrStatii)
//			return minStatii[index];
//		else
//			throw exception("Index invalid!");
//	}
//
//	friend ostream& operator<<(ostream& out, const Tramvai& t);
//};
//
//ostream& operator<<(ostream& out, const Tramvai& t) {
//	out << "Numar tramvai: " << t.nrTramvai << endl;
//	out << "Nume vatman: " << t.numeVatman << endl;
//	out << "Numar Statii: " << t.nrStatii << endl;
//	if (t.nrStatii > 0)
//		for (int i = 0; i < t.nrStatii; i++)
//			out << t.minStatii[i] << " ";
//	out << endl;
//	return out;
//}
//
//class TramvaiHibrid : public Tramvai {
//private:
//	int capacitateBaterie;
//	int timpIncarcare;
//public:
//	TramvaiHibrid() : Tramvai() {
//		capacitateBaterie = 100;
//		timpIncarcare = 0;
//	}
//
//	TramvaiHibrid(int capacitateBaterie, int timpIncarcare, int NrTramvai, char* numeVatman, int nrStatii, int* minStatii) : Tramvai(NrTramvai, numeVatman, nrStatii, minStatii) {
//		this->capacitateBaterie = capacitateBaterie;
//		this->timpIncarcare = timpIncarcare;
//	}
//
//	TramvaiHibrid(const TramvaiHibrid& th) : Tramvai(th){
//		this->capacitateBaterie = th.capacitateBaterie;
//		this->timpIncarcare = th.timpIncarcare;
//	}
//
//	~TramvaiHibrid(){}
//
//	int totalMinuteStationate() override {
//		return Tramvai::totalMinuteStationate() + this->timpIncarcare;
//	}
//
//	TramvaiHibrid& operator=(const TramvaiHibrid& th) {
//		if (this == &th)
//			return *this;
//		Tramvai::operator=(th);
//		this->capacitateBaterie = th.capacitateBaterie;
//		this->timpIncarcare = th.timpIncarcare;
//
//		return *this;
//	}	
//};
//
//int main() {
//	Tramvai t;
//	TramvaiHibrid th;
//	vector<Tramvai>* tr;
//	tr = new vector<Tramvai>[2];
//	tr->push_back(t);
//	tr->push_back(th);
//	for (vector<Tramvai>::iterator i = tr->begin(); i != tr->end(); i++) {
//		cout << i->totalMinuteStationate() << " ";
//	}
//}
