#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class TrainRoute
{
private:
	string departure;
	string destination;

	int nbOfStops;
	//distances between stops
	//it has nbOfStops-1 elements
	int* distances;

	char* trainCode;

public:
	TrainRoute(string departure, string destination){
		this->departure = departure;
		this->destination = destination;
		nbOfStops = 0;
		distances = nullptr;
		trainCode = nullptr;
	}

	TrainRoute(TrainRoute& t) {
		this->departure = t.departure;
		this->destination = t.destination;
		this->nbOfStops = t.nbOfStops;
		if (this->distances != nullptr)
			delete[] this->distances;
		if (t.distances != nullptr && t.nbOfStops > 1) {
			this->distances = new int[t.nbOfStops - 1];
			for (int i = 0; i < t.nbOfStops - 1; i++)
				this->distances[i] = t.distances[i];
		}
		else
			this->distances = nullptr;
		if (this->trainCode != nullptr)
			delete[] this->trainCode;
		if (t.trainCode != nullptr) {
			this->trainCode = new char[strlen(t.trainCode) + 1];
			strcpy_s(this->trainCode, strlen(t.trainCode) + 1, t.trainCode);
		}
		else
			this->trainCode;
	}

	~TrainRoute() {
		if (distances != nullptr)
			delete[] distances;
		if (trainCode != nullptr)
			delete[] trainCode;
	}

	void setTrip(int* distances, int nbOfStops){
		this->nbOfStops = nbOfStops;
		if (this->distances != nullptr)
			delete[] this->distances;
		this->distances = new int[nbOfStops - 1];
		for (int i = 0; i < nbOfStops - 1; i++)
			this->distances[i] = distances[i];
	}

	void setTrainCode(const char* trainCode){
		if (this->trainCode != nullptr)
			delete[] this->trainCode;
		this->trainCode = new char[strlen(trainCode) + 1];
		strcpy_s(this->trainCode, strlen(trainCode) + 1, trainCode);
	}

	TrainRoute& operator=(const TrainRoute& t) {
		this->departure = t.departure;
		this->destination = t.destination;
		this->nbOfStops = t.nbOfStops;
		if (this->distances != nullptr)
			delete[] this->distances;
		this->distances = new int[t.nbOfStops - 1];
		for (int i = 0; i < t.nbOfStops - 1; i++)
			this->distances[i] = t.distances[i];
		if (this->trainCode != nullptr)
			delete[] this->trainCode;
		this->trainCode = new char[strlen(t.trainCode) + 1];
		strcpy_s(this->trainCode, strlen(t.trainCode) + 1, t.trainCode);

		return *this;
	}

	bool operator<(TrainRoute& t){
		int dis1 = 0, dis2 = 0;
		cout << 1 << endl;
		for (int i = 0; i < this->nbOfStops - 1; i++)
			dis1 += this->distances[i];
		cout << 1 << endl;
		for (int i = 0; i < t.nbOfStops - 1; i++)
			dis2 += t.distances[i];
		cout << 2 << endl;

		cout << dis1 << " " << dis2;

		return dis1 < dis2;
	}

	TrainRoute& operator+=(int distance){
		if(distances != nullptr){
			int* aux = new int[nbOfStops - 1];
			for (int i = 0; i < nbOfStops - 1; i++)
				aux[i] = distances[i];
			delete[] distances;
			distances = new int[nbOfStops];
			for (int i = 0; i < nbOfStops - 1; i++)
				distances[i] = aux[i];

			distances[nbOfStops - 1] = distance;
			nbOfStops++;
			delete[] aux;
		}
		else{
			nbOfStops = 2;
			distances = new int[1];
			distances[0] = distance;
		}

		return *this;
	}

	void serialize(string fileName){
		ofstream f(fileName, ios::binary);
		int lungimeDeparture = departure.length();
		f.write((char*)&lungimeDeparture, sizeof(lungimeDeparture));
		f.write(departure.c_str(), lungimeDeparture + 1);
		int lungimeDestination = destination.length();
		f.write((char*)&lungimeDestination, sizeof(lungimeDestination));
		f.write(destination.c_str(), lungimeDestination + 1);
		int lungimeTrainCode = strlen(trainCode);
		f.write((char*)&lungimeTrainCode, sizeof(lungimeTrainCode));
		f.write(trainCode, lungimeTrainCode + 1);
		f.write((char*)&nbOfStops, sizeof(nbOfStops));
		for (int i = 0; i < nbOfStops - 1; i++)
			f.write((char*)&distances[i], sizeof(distances[i]));
		f.close();
	}

	void deserialize(string fileName){
		ifstream f(fileName, ios::binary);
		int lungimeDeparture = 0;
		f.read((char*)&lungimeDeparture, sizeof(lungimeDeparture));
		char* buffer = new char[lungimeDeparture + 1];
		f.read(buffer, lungimeDeparture + 1);
		departure = buffer;
		int lungimeDestination = 0;
		f.read((char*)&lungimeDestination, sizeof(lungimeDestination));
		delete[] buffer;
		buffer = new char[lungimeDestination + 1];
		f.read(buffer, lungimeDestination + 1);
		destination = buffer;
		delete[] buffer;
		if(trainCode != nullptr)
			delete[] trainCode;
		int lungimeTrainCode = 0;
		f.read((char*)&lungimeTrainCode, sizeof(lungimeTrainCode));
		trainCode = new char[lungimeTrainCode + 1];
		f.read(trainCode, lungimeTrainCode + 1);
		f.read((char*)&nbOfStops, sizeof(nbOfStops));
		if (distances != nullptr)
			delete[] distances;
		distances = new int[nbOfStops - 1];
		for (int i = 0; i < nbOfStops - 1; i++)
			f.read((char*)&distances[i], sizeof(distances[i]));
		f.close();
	}

	friend ostream& operator<<(ostream& out, TrainRoute r);
	friend istream& operator>>(istream& in, TrainRoute& r);
	friend ofstream& operator<<(ofstream& fout, const TrainRoute& r);
	friend ifstream& operator>>(ifstream& fin, TrainRoute& r);
};

ostream& operator<<(ostream& out, TrainRoute r){
	out << "Departure: " << r.departure << endl;
	out << "Destination: " << r.destination << endl;
	out << "Train code: " << r.trainCode << endl;
	out << "Number of stops: " << r.nbOfStops<< endl;
	out << "Distances between stops: ";
	if (r.distances != nullptr) {
		for (int i = 0; i < r.nbOfStops - 1; i++)
			out << r.distances[i] << " ";
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, TrainRoute& r)
{
	in >> ws;
	cout << "Departure: ";
	getline(in, r.departure);
	cout << "Destination: ";
	getline(in, r.destination);
	cout << "Train code: ";
	string aux;
	getline(in, aux);
	if (r.trainCode != nullptr)
		delete[] r.trainCode;
	r.trainCode = new char[aux.length() + 1];
	strcpy_s(r.trainCode, aux.length() + 1, aux.c_str());
	cout << "Number of stops: ";
	in >> r.nbOfStops;
	if (r.distances != nullptr) {
		delete[] r.distances;
		r.distances = nullptr;
	}
	if (r.nbOfStops > 1) {
		r.distances = new int[r.nbOfStops - 1];
		cout << "Distances between stops: ";
		for (int i = 0; i < r.nbOfStops - 1; i++) {
			cout << "Stop " << i + 1 << ": ";
			in >> r.distances[i];
		}
	}
	return in;
}

ofstream& operator<<(ofstream& fout, const TrainRoute& r) {
	if (fout.is_open()) {
		fout << r.departure << endl;
		fout << r.destination << endl;
		fout << r.trainCode << endl;
		fout << r.nbOfStops << endl;
		if(r.distances != nullptr){
		for (int i = 0; i < r.nbOfStops - 1; i++)
			fout << r.distances[i] << endl;
		}
		fout << endl;
	}

	return fout;
}

ifstream& operator>>(ifstream& fin, TrainRoute& r)
{
	if (fin.is_open()) {
		getline(fin, r.departure);
		getline(fin, r.destination);
		string aux;
		getline(fin, aux);
		if (r.trainCode != nullptr)
			delete[] r.trainCode;
		r.trainCode = new char[aux.length() + 1];
		strcpy_s(r.trainCode, aux.length() + 1, aux.c_str());
		fin >> r.nbOfStops;
		if (r.distances != nullptr) {
			delete[] r.distances;
			r.distances = nullptr;
		}
		if (r.nbOfStops > 1) {
			r.distances = new int[r.nbOfStops - 1];
			for (int i = 0; i < r.nbOfStops - 1; i++)
				fin >> r.distances[i];
		}
	}

	return fin;
}

//1. Modificati constructorul cu parametri pentru a initializa
//statia de plecare si statia de sosire
//numarul de opriri va fi initializat cu 0, iar cei doi vectori
//(vectorul de distante si codul trenului) cu null

//2. Modificati metoda setTrip astfel incat vectorul existent de distante
//sa fie inlocuit de cel primit drept parametru
//nu uitati faptul ca vectorul are cu un element mai putin decat numarul de statii

//3. Modificati metoda setTrainCode pentru a inlocui codul existent
//cu cel primit drept parametru

//4. Respectati "regula celor 3" in cadrul clasei de mai sus

//5. Modificati supraincarcarea operatorului <
//acesta va returna true daca distanta totala a rutei reprezentata de primul operand
//este mai mica decat distanta totala a rutei reprezentate de al doilea operand

//6. Modificati operatorul += pentru a adauga un element in vectorul de distante
//numarul de statii va fi de asemenea incrementat

//7. Modificati operatorul de scriere la consola pentru a afisa informatiile despre ruta
//se pot folosi functii friend sau getteri
//afisarea va fi de forma:
//Departure: departure
//Destination: destination
//Train code: trainCode
//Number of stops: nbOfStops
//Distances between stops: distance1 distance2 distance3 etc

//8. Modificati operatorul de citire de la consola pentru a citi informatii despre ruta
//se vor citi in ordine urmatoarele informatii (fiecare pe o linie noua)
//Departure
//Destination
//Train code
//Number of stops
//distance 1
//distance 2
//distance 3
//etc
//se pot folosi setteri sau functii friend
//operatorul trebuie sa poata citi siruri de caractere ce contin spatii

//9. Supraincarcati operatorii de scriere si citire din fisiere text
//operatorii functioneaza pe fisiere text deschise deja

//10. Modificati metodele serialize si deserialize pentru a scrie
//si a citi obiectul curent de clasa TrainRoute intr-un/dintr-un fisier binar
//se vor serializa toate campurile (ordinea nu conteaza)
//numele fisierului este primit drept parametru
//metodele deschid si inchid fisierele specificate

int main(){
	float t = 20;
	cout << t / 100;
}