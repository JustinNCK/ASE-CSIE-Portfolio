#include <iostream>
#include <string>
using namespace std;

class Cartus{
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

class Imprimanta{
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

	Imprimanta(int SerialNumber, char* producator, int nrPaginiPrintate) : serialNumber(SerialNumber) {
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
		this->producator = new char[strlen(m.producator) + 1];
		strcpy_s(this->producator, strlen(m.producator) + 1, m.producator);
		this->nrPaginiPrintate = m.nrPaginiPrintate;

		return *this;
	}

	static string getTipImprimanta(){
		return tipImprimanta;
	}

	static void setTipImprimanta(string tipImprimanta) {
		Imprimanta::tipImprimanta = tipImprimanta;
	}

	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, const char* producator){
		long sum = 0;

		if (nrImprimante == 0 || imprimante == nullptr)
			return sum;

		for (int i = 0; i < nrImprimante; i++)
			if (strcmp(imprimante[i].producator, producator) == 0)
				sum += imprimante[i].nrPaginiPrintate;

		return sum;
	}

	void setCartus(Cartus c){
		cartus = c;
	}

	Cartus getCartus(){
		return cartus;
	}

	int getNumarPaginiRamase(){
		if (nrPaginiPrintate >= cartus.getNrPaginiRamase())
			return 0;
		else
			return cartus.getNrPaginiRamase() - nrPaginiPrintate;
	}
};
string Imprimanta::tipImprimanta = "Cerneala";

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//--------------------------------------------------------------------------------

//1. Modificati constructorul implicit din clasa Imprimanta de mai sus
//acesta va initializa producatorul cu un sir de caractere vid ("")
//si numarul de pagini printate cu 0

//--------------------------------------------------------------------------------

//2. Modificati constructorul cu 3 parametri: serialNumber, producator, nrPaginiPrintate
//acesta va initializa cele 3 atribute cu valorile primite
//atributul constant nu va mai fi initializat la definire
//constructorul implicit va initializa acest atribut cu 1

//--------------------------------------------------------------------------------

//3. Adaugati un destructor in clasa pentru a dezaloca
//campul(urile) alocate dinamic

//--------------------------------------------------------------------------------

//4. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor
//se va realiza si copierea campului constant
 
//--------------------------------------------------------------------------------

//5. Modificati supraincarcarea pentru operator=
//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
//operatorul accepta apeluri in cascada

//--------------------------------------------------------------------------------

//6. Initializati membrul static tipImprimanta
// cu valoarea "Cerneala"

//--------------------------------------------------------------------------------

//7. Modificati metodele de acces pentru campul static
//astfel incat acestea sa permita modificarea si obtinerea valorii acestui camp

//--------------------------------------------------------------------------------

//8. Modificati metoda getTotalPaginiPerProducator pentru a returna numarul total de pagini
//printate de toate imprimantele din vectorul de imprimante primit ca parametru
//care sunt produse de producatorul primit drept parametru
//De ex daca avem 3 imprimante: "Dell" - 120 de pagini, "HP" - 150 de pagini, "Dell" - 170 de pagini
//functia va returna 290 de pagini daca primeste ca parametru producatorul "Dell"
//si 150 de pagini daca primeste ca parametru producatorul "HP"
//pentru orice alt producator functia va returna 0

//--------------------------------------------------------------------------------

//9. Modelati o relatie de compunere intre clasa Cartus si clasa Imprimanta
//astfel incat sa reiasa faptul ca Imprimanta are (foloseste) un Cartus
//Modificati metoda setCartus astfel incat sa puteti schimba cartusul curent al imprimantei
//cu cel primit drept parametru si metoda getCartus pentru a returna cartusul curent

//--------------------------------------------------------------------------------

//10. Modificati metoda getNumarPaginiRamase astfel incat sa returneze numarul de pagini
//pe care imprimanta respectiva la mai poate printa avand in vedere ca stim 
//cate pagini se pot printa maxim cu cartusul curent si cate pagini au fost printate pana acum
//functia nu poate returna o valoare negativa, asa ca daca numarul curent de pagini il
//depaseste pe cel maxim, va returna 0

int main() {

}