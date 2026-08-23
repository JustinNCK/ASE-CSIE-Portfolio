#include <iostream>
using namespace std;

#define NULL 0
static int variabila = 99;
static float dummy_value = 123;

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//1. Pentru a testa proiectul de teste unitare, scrieti corpul/codul acestei functii
//astfel incat sa returneze corect suma dintre parametrii x si y
long suma(int x, int y) 
{
	return x + y;
}

//2. Definiti un pointer la float in functia urmatoare si initializati-l cu NULL
//returnati acest pointer
float* returnare_pointer_null() 
{
	float* pointer = NULL;

	return pointer;
}

//3. Definiti un pointer la int si initializati-l cu adresa
//variabilei globale numita variabila, returnati acest pointer
int* returnare_pointer_adresa() 
{
	int* pointer = &variabila;

	return pointer;
}

//4. Functia de mai jos primeste ca si parametru un pointer la double
//returnati valoarea aflata la acea adresa
double returnare_valoare_de_la_adresa(double* pointer) 
{
	return *pointer;
}

//5. Functia de mai jos primeste ca si parametru un pointer la int
//returnati adresa urmatorului intreg utilizand operatori specifici pointerilor
int* returnare_adresa_intreg_urmator(int* pointer) 
{	
	return pointer + 1;
}

//6. Functia de mai jos primeste drept parametru un pointer la long
//returnati valoarea de la adresa mai mica cu 2 * sizeof(long) fata de aceasta
//utilizand operatori specifici pointerilor
long returnare_adresa_long_precedent(long* pointer)
{
	return *(pointer - 2);
}

//7. Functia de mai jos primeste drept parametri 2 pointeri la int
//returnati numarul de intregi care incap intre cele doua adrese de memorie
//8. Asigurati-va ca rezultatul este tot timpul unul pozitiv
//(indiferent de ordinea din memorie a pointerilor)
int returnare_diferenta_pointeri(int* pointer1, int* pointer2) 
{
	if (pointer1 > pointer2)
		return pointer1 - pointer2;
	return pointer2 - pointer1;
}

//9. Functia de mai jos primeste ca si parametru un pointer la pointer la int
//acesta reprezinta adresa unei adrese la care se gaseste un intreg
//returnati acel intreg
int returnare_valoare_adresa_de_adresa(int** pointer)
{
	int x = **pointer;
	
	return x;
}

//10. Functia de mai jos este similara functiei de mai sus cu o mica diferenta
//al doilea parametru ne spune tipul de pointer => I pentru intreg sau L pentru long
//transformati pointerul primit ca parametru in tipul corespunzator
//si apoi returnati valoarea obtinuta la fel ca in functia de mai sus
long returneaza_valoarea_adresa_de_adresa_void(void** pointer, char tip_pointer)
{
	if (tip_pointer == 'L') {
		long** x = (long**)pointer;
		return **x;
	}
	else{
		int** x = (int **)pointer;
		return **x;
	}
}

int main() 
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}