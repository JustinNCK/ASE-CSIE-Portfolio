#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
///*
//class PetrolStation{
//private:
//	int pumpid;
//	string location, brand;
//	bool isDisel = false;
//	int* liters;
//	int noClients;
//	float PRICE_PER_LITER = 7.3;
//
//public:
//	~PetrolStation() {
//		if (liters != nullptr)
//			free(liters);
//	}
//
//	PetrolStation(int pumpId, string Location) {
//		this->pumpid = pumpId;
//		this->location = Location;
//	}
//
//	PetrolStation(int pumpId, string Location, int* Liters, int noclients, string Brand) {
//		this->pumpid = pumpId;
//		this->noClients = noclients;
//		if (noClients != 0) {
//			this->liters = new int[noClients];
//
//			for (int i = 0; i < noClients; i++)
//				this->liters[i] = Liters[i];
//		}
//		else
//			this->liters = nullptr;
//
//		this->brand = Brand;
//	}
//
//	void setLocation(string Location) {
//		this->location = Location;
//	}
//
//	void setDisel() {
//		this->isDisel = true;
//	}
//	
//	void setPetrolPrice(float price) {
//		this->PRICE_PER_LITER = price;
//	}
//	
//	int getTotalLiters() {
//		int sum = 0, i;
//
//		for (i = 0; i < this->noClients; i++)
//			sum += this->liters[i];
//
//		return sum;
//	}
//
//	int getId() {
//		return this->pumpid;
//	}
//
//	string getLocation() {
//		return this->location;
//	}
//
//	int getNoClients() {
//		return this->noClients;
//	}
//
//	int getIncome() {
//		int sum = 0;
//
//		for (int i = 0; i < this->noClients; i++)
//			sum += this->liters[i];
//
//		sum *= this->PRICE_PER_LITER;
//
//		return sum;
//	}
//
//	void sellGasoline(int new_pers) {
//		if (new_pers > 1000) {
//			cout << "Too much";
//			return;
//		}
//
//		int* aux = new int[this->noClients];
//
//		for (int i = 0; i < this->noClients; i++)
//			aux[i] = this->liters[i];
//
//		free(this->liters);
//		this->noClients += 1;
//		this->liters = new int[this->noClients];
//
//		for (int i = 0; i < this->noClients - 1; i++)
//			this->liters[i] = aux[i];
//
//		this->liters[this->noClients - 1] = new_pers;
//	}
//};
//
//
//int main() {
//	PetrolStation station1(23, "Bucharest");
//	cout << station1.getLocation() << endl;
//	station1.setLocation("Ploiesti");
//	cout << station1.getLocation() << endl;
//
//
//
//
//	int liters[]{ 100, 200, 300 };
//	PetrolStation station2(24, "Ploiesti", liters, 3, "PETROM");
//	cout << station2.getTotalLiters() << endl;
//
//
//	cout << station2.getId() << endl;
//	station2.setDisel();
//
//	station2.sellGasoline(500);
//	cout << station2.getNoClients() << endl;
//
//	//trolStation::PRICE_PER_LITER = 6.4;
//	station2.setPetrolPrice(6.4);
//	cout << "Total revenue: " << station2.getIncome();
//}
//*/
///*
//enum type { GASOLINE, DISEL, ELECTRIC, HYBRID };
//
//class Car {
//private:
//	string const vehiclePlates;
//	string brand;
//	enum type fuelType;
//	bool hasAutopilot;
//	float* kmPerTrip;
//	int noTrips;
//	static const int AVRAGE_LITERS_PER_100KM = 7.5;
//
//public:
//	Car() {
//		this->brand = nullptr;
//		this->fuelType = GASOLINE;
//		this->hasAutopilot = false;
//		this->kmPerTrip = nullptr;
//		this->noTrips = 0;
//	}
//
//	Car(string VehiclePlates, string brand, enum type x) : vehiclePlates(VehiclePlates) {
//		this->brand = brand;
//		this->fuelType = x;
//	}
//
//	~Car() {
//		free(this->kmPerTrip);
//	}
//
//	float* getKmPerTrip() {
//		return this->kmPerTrip;
//	}
//
//};
//
//int main() {
//	
//	Car c1("B-01-INF", "Dacia", GASOLINE);
//}
//*/
//
////class numarMare {
////private:
////	int* v;
////
////public:
////	numarMare() {
////		int nrElem;
////		cin >> nrElem;
////		v = new int[nrElem + 1];
////		v[0] = nrElem;
////		for (int i = 1; i <= nrElem; i++)
////			cin >> v[i];
////	}
////
////	numarMare operator =(numarMare a) {
////		if(this->v != nullptr)
////			free(this->v);
////		this->v = new int[a.getV(0) + 1];
////		this->v[0] = a.getV(0);
////		for (int i = this->v[0]; i >= 1; i--)
////			this->v[i] = a.getV(i);
////
////		return *this;
////	}
////
////	void afis() {
////		if (v[1] != 0)
////			cout << v[1];
////
////		for (int i = 2; i <= v[0]; i++)
////			cout << v[i];
////	}
////	
////	int getV(int i){
////		return this->v[i];
////	}
////
////	void adunare(numarMare a) {
////		int* c, x, y, aux;
////
////		if (a.getV(0) >= this->v[0]) {
////			c = new int(a.getV(0) + 2);
////			c[0] = a.getV(0) + 1;
////			x = this->v[0];
////			//cout << x << endl << endl;
////			for (int i = c[0]; i > 0; i--) {
////				if (x > 0)
////					c[i] = this->v[x];
////				else
////					c[i] = 0;
////
////				x--;
////			}
////			/*for (int i = 0; i <= c[0]; i++)
////				cout << c[i] << " ";
////			cout << endl;*/
////			for (int i = c[0]; i > 1; i--) {
////				//cout << c[i] << " ";
////				c[i] += a.getV(i - 1);
////				if(c[i] > 9)
////					c[i - 1] += c[i] / 10;
////				c[i] %= 10;
////				//cout << c[i] << endl;
////			}
////		}
////		else {
////			c = new int(this->v[0] + 2);
////			c[0] = this->v[0] + 1;
////			x = a.getV(0);
////			for (int i = c[0]; i > 0; i--) {
////				if (x > 0)
////					c[i] = a.getV(x);
////				else
////					c[i] = 0;
////
////				x--;
////			}
////			for (int i = c[0]; i > 1; i--) {
////				c[i] += this->v[i - 1];
////				if (c[i] > 9)
////					c[i - 1] += c[i] / 10;
////				c[i] %= 10;
////			}
////		}
////
////		if (c[1] != 0)
////			cout << c[1];
////		for (int i = 2; i <= c[0]; i++)
////			cout << c[i];
////	}
////
////	numarMare operator +(numarMare a) {
////		numarMare c;
////		int x, y, aux;
////
////		if (a.getV(0) >= this->v[0]) {
////			c.v = new int(a.getV(0) + 2);
////			c.v[0] = a.getV(0) + 1;
////			x = this->v[0];
////			//cout << x << endl << endl;
////			for (int i = c.v[0]; i > 0; i--) {
////				if (x > 0)
////					c.v[i] = this->v[x];
////				else
////					c.v[i] = 0;
////
////				x--;
////			}
////			/*for (int i = 0; i <= c[0]; i++)
////				cout << c[i] << " ";
////			cout << endl;*/
////			for (int i = c.v[0]; i > 1; i--) {
////				//cout << c[i] << " ";
////				c.v[i] += a.getV(i - 1);
////				if (c.v[i] > 9)
////					c.v[i - 1] += c.v[i] / 10;
////				c.v[i] %= 10;
////				//cout << c[i] << endl;
////			}
////		}
////		else {
////			c.v = new int(this->v[0] + 2);
////			c.v[0] = this->v[0] + 1;
////			x = a.getV(0);
////			for (int i = c.v[0]; i > 0; i--) {
////				if (x > 0)
////					c.v[i] = a.getV(x);
////				else
////					c.v[i] = 0;
////
////				x--;
////			}
////			for (int i = c.v[0]; i > 1; i--) {
////				c.v[i] += this->v[i - 1];
////				if (c.v[i] > 9)
////					c.v[i - 1] += c.v[i] / 10;
////				c.v[i] %= 10;
////			}
////		}
////		return c;
////	}	
////
////	friend istream& operator>>(istream& in, numarMare& a);
////
////};
////
////istream& operator>>(istream& in, numarMare& a) {
////	int n;
////	in >> n;
////	a.v = new int[n + 1];
////	a.v[0] = n;
////	for (int i = 1; i <= n; i++)
////		in >> a.v[i];
////
////	return in;
////}
////
////int main() {
////	numarMare a;
////	//a.adunare(b);
////	//a = b;
////	//c = a + b;
////	//c.afis();
////
////	cin >> a;
////	a.afis();
////}
//// supra incarcare + si supra incarcare >>
//
//

//ostream& operator<<(ostream& out, ConglomeratImprimate a);

class Cartus {
private:
	string producator;
	int nrTotalPagini;

public:
	Cartus() {
		producator = "";
		nrTotalPagini = 0;
	}

	Cartus(string producator, int nrTotalPagini) {
		this->producator = producator;
		this->nrTotalPagini = nrTotalPagini;
	}

	int getNrPaginiRamase() {
		return nrTotalPagini;
	}
};

class Imprimanta {
private:
	const int serialNumber;
	char* producator;
	int nrPaginiPrintate;
	static string tipImprimanta;
	Cartus cartus;

public:
	Imprimanta() : serialNumber(1) {
		producator = new char[1];
		producator[0] = '\0';
		nrPaginiPrintate = 0;
		tipImprimanta = "Cerneala";
	}

	Imprimanta(int SerialNumber, const char* producator, int nrPaginiPrintate) : serialNumber(SerialNumber) {
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
		this->nrPaginiPrintate = nrPaginiPrintate;
	}

	Imprimanta(Imprimanta& m) : serialNumber(m.serialNumber) {
		this->producator = new char[strlen(m.producator) + 1];
		strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
		this->nrPaginiPrintate = m.nrPaginiPrintate;
	}

	~Imprimanta() {
		delete[] producator;
		producator = nullptr;
	}

	Imprimanta& operator=(const Imprimanta& m) {
		if (this->producator) {
			delete[] this->producator;
		}
		this->producator = new char[strlen(m.producator) + 1];
		strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
		this->nrPaginiPrintate = m.nrPaginiPrintate;

		return *this;
	}

	static string getTipImprimanta() {
		return tipImprimanta;
	}

	static void setTipImprimanta(string tipImprimanta) {
		Imprimanta::tipImprimanta = tipImprimanta;
	}

	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, const char* producator) {
		long sum = 0;

		if (nrImprimante == 0 || imprimante == nullptr)
			return sum;

		for (int i = 0; i < nrImprimante; i++)
			if (strcmp(imprimante[i].producator, producator) == 0)
				sum += imprimante[i].nrPaginiPrintate;

		return sum;
	}

	void setCartus(Cartus c) {
		cartus = c;
	}

	Cartus getCartus() {
		return cartus;
	}

	int getNumarPaginiRamase() {
		if (nrPaginiPrintate >= cartus.getNrPaginiRamase())
			return 0;
		else
			return cartus.getNrPaginiRamase() - nrPaginiPrintate;
	}

	void afisImprimanta() {
		cout << serialNumber << " " << producator << endl << nrPaginiPrintate << endl << tipImprimanta << endl;
	}


	int getSerialNumber() const { return serialNumber; }
	const char* getProducator() const { return producator; }
	int getNrPaginiPrintate() const { return nrPaginiPrintate; }

	friend ostream& operator<<(ostream& out, Imprimanta a);
};

class ConglomeratImprimate : public Imprimanta{
private:
	string nume_sala;
	int n, nr_sala;
	Imprimanta** arr;

public:
	ConglomeratImprimate() {
		nume_sala = "N/A";
		n = 0;
		nr_sala = 100;
		arr = nullptr;
	}
	
	ConglomeratImprimate(string nume_sala, int n, int nr_sala, Imprimanta** imp) {
		this->nume_sala = nume_sala;
		this->n = n;
		this->nr_sala = nr_sala;

		arr = new Imprimanta * [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Imprimanta[n];
			for (int j = 0; j < n; j++)
				arr[i][j] = imp[i][j];
		}
	}

	~ConglomeratImprimate() {
		for (int i = 0; i < n; i++) {
			delete[] arr[i];
			//cout << "Del " << n << endl;
		}

		delete[] arr;
	}

	ConglomeratImprimate& operator=(ConglomeratImprimate& m) {
		this->nume_sala = m.nume_sala;
		this->n = m.n;
		this->nr_sala = m.nr_sala;

		if (m.arr != nullptr || m.n > 0) {
			for (int i = 0; i < n; i++)
				delete[] this->arr[i];
			delete[] this->arr;

			this->arr = new Imprimanta * [n];
			for (int i = 0; i < n; i++) {
				this->arr[i] = new Imprimanta[n];
				for (int j = 0; j < n; j++)
					this->arr[i][j] = m.arr[i][j];
			}
		}
		else {
			for (int i = 0; i < n; i++)
				delete[] this->arr[i];
			delete[] this->arr;

			this->arr = nullptr;
		}

		return *this;
	}

	Imprimanta getImprimanta(int i, int j) {
		return arr[i][j];
	}

	void setImprimanta(Imprimanta imp, int i, int j) {
		arr[i][j] = imp;
	}

	void afisSala() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j].afisImprimanta();
				cout << endl;
			}
			cout << endl;
		}
	}

	friend ostream& operator<<(ostream& out, ConglomeratImprimate a);
};
string Imprimanta::tipImprimanta = "Cerneala";

ostream& operator<<(ostream& out, ConglomeratImprimate a) {
	out << "Numele salii: " << a.nume_sala << endl;
	out << "Numarul salii: " << a.nr_sala << endl;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			out << a.arr[i][j].getSerialNumber() << " " << a.arr[i][j].getProducator() << endl << a.arr[i][j].getNrPaginiPrintate() << endl << Imprimanta::getTipImprimanta() << endl;
			out << endl;
		}
		out << endl;
	}

	return out;
}

int main() {
	Imprimanta **a = new Imprimanta*[1], x(123, "Dell", 3);
	for (int i = 0; i < 1; i++) {
		a[i] = new Imprimanta[1];
		for (int j = 0; j < 1; j++)
			a[i][j] = x;
	}
	ConglomeratImprimate m("parter", 1, 1030, a);
	cout << m;
}
