/*
La testele de la exercitul 9 exista o problema care face ca orice rezplvare sa fie gresita.
Aceea este ca la fiecare test in parte nu reactualizeaza vectorul v, rezultand ca dintre cele 3 teste numai primul
sa fie mereu corect, este posibil ca sa gresesc eu, dar am zis sa va zic de acest fapt pentru ca ma gandesc la aceasta
problema de cateva zile si acesta este singurul lucru pe care l-am vazut ca ar fi gersit legat de aceea problema
*/
#include <iostream>
#include <string>
using namespace std;
static int v[] { 0, 5, 7, 9, 12, 99, 100 };

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor


//1. v este un vector global alocat static
//calculati si returnati numarul de elemente al acestui vector
int numar_elemente() 
{
	return sizeof(v) / sizeof(v[0]);
}

//2. Functia de mai jos returneaza maximul dintr-un vector
//alocat dinamic primit ca parametru (alaturi de dimensiune)
//daca vectorul este null sau dimensiunea <= 0
//atunci functia returneaza 0
float maxim_vector(float* vector, int dimensiune) 
{
	if (vector == NULL || dimensiune <= 0)
		return 0;
	float mx = vector[0];
	for (int i = 1; i < dimensiune; i++)
		if (mx < vector[i])
			mx = vector[i];
	return mx;
}

//3. Returnati o copie a vectorului de caractere
//primit drept parametru
char* returnare_copie_vector_caractere(const char* sir) 
{
	char* s = new char[strlen(sir) + 1];

	for (int i = 0; i <= strlen(sir); i++)
		s[i] = sir[i];

 	return s;
}

//4. Functia de mai jos primeste ca si parametri doua stringuri
//returnati lungimea totala a celor doua stringuri
int returnare_lungime_stringuri(string s1, string s2) 
{
	s1 += s2;

	int x = s1.length();

	return x;
}

//5. Functia de mai jos primeste ca si parametri un string si un char*
//si returneaza true daca cele doua siruri de caractere au acelasi continut
bool siruri_egale(string sir1, char* sir2) 
{
	const char* sir3 = sir1.c_str();
	for (int i = 0; sir2[i] != '\0'; i++)
		if (sir2[i] != sir3[i])
			return false;
	return true;
}

//6. Functia de mai jos primeste ca si parametri o matrice alocata dinamic,
//precum si numarul de linii si de coloane
//functia returneaza true daca matricea primita ca parametru este matrice unitate
//(este patratica, iar pe diagonala principala are doar 1, iar restul elementelor sunt 0)
bool matrice_unitate(int** matrice, int linii, int coloane)
{
	if (linii == coloane) {
		for (int i = 0; i < linii; i++)
			for (int j = 0; j < coloane; j++)
				if (i == j) {
					if (matrice[i][j] != 1)
						return false;
				}
				else if (matrice[i][j] != 0)
					return false;
	}
	else
		return false;
	return true;
}

//7. Functia de mai jos returneaza un vector ce contine
//minimul de pe fiecare linie al unei matrice primita ca parametru
//vectorul este alocat dinamic si va contine atatea elemente cate linii are matricea
int* returnare_minim_pe_linii(int** matrice, int linii, int coloane)
{
	int* v = new int[linii];

	for (int i = 0; i < linii; i++) {
		v[i] = matrice[i][0];
		for (int j = 1; j < coloane; j++)
			if (matrice[i][j] < v[i])
				v[i] = matrice[i][j];
	}

	return v;
}

//8. Functia de mai jos este asemanatoare celei de mai sus, doar ca transforma
//elementele vectorului intr-un sir de caractere de tip char* folosind spatii
//ex: daca vectorul returnat mai sus este [1, 2, -2] atunci rezultatul va fi "1 2 -2"
char* returnare_minim_pe_linii_ca_sir(int** matrice, int linii, int coloane)
{
	int* v = new int[linii];

	for (int i = 0; i < linii; i++) {
		v[i] = matrice[i][0];
		for (int j = 1; j < coloane; j++)
			if (matrice[i][j] < v[i])
				v[i] = matrice[i][j];
	}
	int x = 2 * linii - 1;
	for (int i = 0; i < linii; i++)
		if (v[i] <= 0)
			x++;

	char* sir = new char[x + 1];
	int j = 0;

	for (int i = 0; i < linii; i++) {
		if (v[i] < 0) {
			sir[j] = '-';
			v[i] = abs(v[i]);
			j++;
		}

		do {
			sir[j] = char(48 + v[i] % 10);
			v[i] /= 10;
			j++;
		}while (v[i] != 0);
		
		if (i != linii - 1) {
			sir[j] = ' ';
			j++;
		}
	}
		sir[j] = '\0';

	return sir;
}

//9. Functia de mai jos primeste drept parametri un vector alocat dinamic,
//dimensiunea sa si elementul ce se doreste a fi sters
//si returneaza vectorul obtinut prin stergerea elementului
int* sterge_element(int* vector, int dimensiune, int element)
{
	for (int i = 0; i < dimensiune; i++)
		if (vector[i] == element) {
			for (int j = i; j < dimensiune - 1; j++)
				vector[j] = vector[j + 1];
			dimensiune--;
			i--;
		}

	return vector;
}

//10. Functia de mai jos arhiveaza un sir de caractere primit ca parametru
//arhivarea unui sir de caractere se face prin notarea numarului de repetari
//ale unui caracter atunci cand acesta apare de mai mult (sau egal) de 2 ori consecutiv
//ex1: pentru sirul AAABBC, versiunea arhivata este 3A2BC
//ex2: pentru sirul XYYYYYYYZTTT, versiunea arhivata este X7YZ3T
//precizare: sirul contine doar caractere uppercase (litere mari)
char* arhivare_sir(const char* sir) 
{
	/*if (sir == nullptr)
		return;

	int x = 0, sum, j;
	for (int i = 0; sir[i] != NULL; i++)
		if (sir[i] != sir[i + 1])
			x++;
	x *= 2;

	char* sZip = new char[x + 1];
	j = 0;
	for (int i = 0; sir[i] != NULL; i++)
		if (sir[i] != sir[i + 1]) {
			sZip[j] = sir[i];
			j++;
		}
		else {
			sum = 1;
			while (sir[i] == sir[i + 1]) {
				i++;
				sum++;
			}
			sum++;
			int aux;
			while (sum != 0) {
				aux = aux * 10 + sum % 10;
				sum /= 10;
			}

			do {
				sZip[j] = char(48 + aux % 10);
				aux /= 10;
				j++;
			} while (aux != 0);
			
			i++;
			sZip[j] = sir[i];
		}

	return sZip;*/
	return nullptr;
}

int main() 
{
	/*const char* sir = "AAABBC";
	char* rezultat = arhivare_sir(sir);
	cout << rezultat << endl;
	const char* sir2 = "XYYYYYYYZTTT";
	rezultat = arhivare_sir(sir2);
	cout << rezultat << endl;
	const char* sir3 = "BBBCCD";
	rezultat = arhivare_sir(sir3);
	cout << rezultat << endl;*/


	/*int** z = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		z[i] = new int[3];
	}
	z[0][0] = 1; z[0][1] = 7; z[0][2] = -2;
	z[1][0] = 0; z[1][1] = 1; z[1][2] = 2;
	z[2][0] = 99; z[2][1] = 3; z[2][2] = 1;
	z[3][0] = 98; z[3][1] = -3; z[3][2] = 1;
	const char* rezultat = returnare_minim_pe_linii_ca_sir(z, 4, 3);
	cout << rezultat << endl;
	cout << strcmp(rezultat, "-2 0 1 -3") << endl;*/

	//const char* sir = "ana are mere";
	//returnare_copie_vector_caractere(sir);
	//cout << endl << returnare_copie_vector_caractere(sir) << endl;

	/*
	float* v;
	int dimenusiune;
	cout << "Dimensiunea vectorului: ";
	cin >> dimenusiune;
	v = new float[dimenusiune];
	cout << "Elementele vectorului: ";
	for (int i = 0; i < dimenusiune; i++)
		cin >> v[i];

	cout << maxim_vector(v, dimenusiune) << endl;

	string s1 = "Ana are mere", s2 = "Maria are pere";
	cout << returnare_lungime_stringuri(s1, s2) << endl;
	*/

	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}