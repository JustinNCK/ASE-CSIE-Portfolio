#include <iostream>
#include <string>
using namespace std;

class Autoturism
{
private:
	string marca;
	string model;
	int putere;
	double pret;
	float* distanteParcurse;
	int nrDrumuri; //nr de elemente al vectorului de mai sus
	char* taraDeProductie;

public:
	Autoturism(){
		this->marca = "Necunoscuta";
		this->model = "Necunoscut";
		this->putere = 0;
		this->pret = 5000;
		this->distanteParcurse = nullptr;
		this->taraDeProductie = nullptr;
		this->nrDrumuri = 0;
	}

	Autoturism(string marca, string model, int putere) : Autoturism(){
		this->marca = marca;
		this->model = model;
		this->putere = putere;
	}

	Autoturism(string marca, string model, float* distante, int nrDrumuri) : Autoturism() {
		this->marca = marca;
		this->model = model;
		if (distante != nullptr && nrDrumuri > 0) {
			this->nrDrumuri = nrDrumuri;
			this->distanteParcurse = new float[this->nrDrumuri];
			for (int i = 0; i < this->nrDrumuri; i++)
				this->distanteParcurse[i] = distante[i];
		}
	}

	Autoturism(const Autoturism& m) {
		int n = 0;
		while (m.taraDeProductie[n] != NULL)
			n++;
		this->taraDeProductie = new char[n + 1];
		for (int i = 0; i <= n; i++)
			this->taraDeProductie[i] = m.taraDeProductie[i];

		if (m.distanteParcurse != nullptr && m.nrDrumuri > 0) {
			delete(this->distanteParcurse);
			this->distanteParcurse = new float[m.nrDrumuri];
			for (int i = 0; i < this->nrDrumuri; i++)
				this->distanteParcurse[i] = m.distanteParcurse[i];
		}
		else {
			delete(this->distanteParcurse);
			this->distanteParcurse = nullptr;
		}

		this->marca = m.marca;
		this->model = m.model;
		this->nrDrumuri = m.nrDrumuri;
		this->putere = m.putere;
		this->pret = m.pret;
	}

	~Autoturism() {
		marca = "";
		model = "";
		if (distanteParcurse != nullptr) {
			delete(distanteParcurse);
			distanteParcurse = nullptr;
		}
		if (taraDeProductie != nullptr) {
			delete(taraDeProductie);
			taraDeProductie = nullptr;
		}
		putere = 0;
		pret = 0;
		nrDrumuri = 0;
	}
	string getMarca(){
		return marca;
	}

	void setMarca(string marca){
		if (marca.length() >= 3)
			this->marca = marca;
	}

	int getNrDrumuri(){
		return nrDrumuri;
	}

	float* getDistanteParcurse(){
		if (distanteParcurse == nullptr)
			return nullptr;
		
		float* distante = new float[nrDrumuri];
		for (int i = 0; i < nrDrumuri; i++)
			distante[i] = distanteParcurse[i];

		return distante;
	}

	void setDistante(float* distanteParcurse, int nrDrumuri){
		if (distanteParcurse == nullptr && nrDrumuri <= 0)
			return;

		this->nrDrumuri = nrDrumuri;
		delete(this->distanteParcurse);
		this->distanteParcurse = new float[nrDrumuri];
		for (int i = 0; i < nrDrumuri; i++)
			this->distanteParcurse[i] = distanteParcurse[i];
	}

	char* getTaraDeProductie(){
		return taraDeProductie;
	}

	void setTaraDeProductie(const char* tara){
		int n = 0;
		while (tara[n] != NULL)
			n++;
		taraDeProductie = new char[n + 1];
		for (int i = 0; i <= n; i++)
			taraDeProductie[i] = tara[i];
	}

	char* AdresaInceputTaraDeProductie(){
		return taraDeProductie;
	}
};

//1. Modificati constructorul implicit din clasa Autoturism de mai sus
//acesta va initializa marca cu "Necunoscuta", modelul cu "Necunoscut"
//puterea cu 0, pretul cu 5000, vectorul de distante cu NULL si nrDrumuri cu 0

//---------------------------------------------------------------

//2. Modificati constructorul cu 3 parametri: marca, model, putere
//acesta va initializa cele 3 atribute cu valorile primite
//restul de atribute nu trebuie sa ramana neinitializate si vor folosi aceleasi valori implicite ca mai sus

//---------------------------------------------------------------

//3. Modificati constructorul cu 4 parametri pentru a copia valorile
//primite drept parametri in atributele clasei
//constructorul nu va lasa atribute neinitializate

//---------------------------------------------------------------

//4. Adaugati un destructor in clasa care sterge zonele de memorie anterior alocate
//acesta va seta pointerii pe NULL dupa ce face stergerea

//---------------------------------------------------------------

//5. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor

//---------------------------------------------------------------

//6. Modificati metodele de acces (getteri si setteri) pentru atributul marca
//Setterul va accepta denumiri de marci cu o lungime
//mai mare sau egala de 3 caractere
//in caz contrar marca ramane cea existenta

//---------------------------------------------------------------

//7. Modificati getter-ul pentru vectorul de distante parcurse
//Getter-ul va returna o copie a vectorului din clasa
//Modificati getter-ul si pentru numarul de drumuri

//---------------------------------------------------------------

//8. Modificati setter-ul pentru vectorul de distante
//acesta va modifica simultan vectorul si numarul de elemente
//si nu va accepta decat vectori nenuli si numar de elemente mai mare decat 0

//---------------------------------------------------------------

//9. Adaugati un camp de tip char* in clasa numit taraDeProductie
//modificati getter-ul si setter-ul din clasa pentru a returna,
//respectiv a modifica valoarea acestui camp
//Metoda AdresaInceputTaraDeProductie intoarce adresa primului element din tara de productie
//(da, nu e neaparat safe, dar e necesar pentru test)

//---------------------------------------------------------------

//10. Modificati constructorii, destructorul si alte metode necesare
//astfel incat clasa sa gestioneze corect noul camp

int main() {
}