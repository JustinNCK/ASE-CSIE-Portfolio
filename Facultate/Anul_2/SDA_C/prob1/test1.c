#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define DIMENSIUNE_HASHMAP 49

struct CursaAeriana {
	char* cod, * destinatie, * plecare, * ora_plecare, * status_cursa;
};

typedef struct CursaAeriana CursaAeriana;

struct Nod {
	CursaAeriana ca;
	Nod* next;
};

typedef struct Nod Nod;

void InserareCursaAerianaTabela(Nod** hash_map, CursaAeriana ca);
int CalculareHash(char* destinatie);
Nod* InserareCursaAeriana(Nod* hash_map, CursaAeriana ca);
int NumarCurse(Nod** hash_map, char* cheie, char* plecare);
void StergereCurse(Nod** hash_map, char* cheie, char* status_cursa);
Nod* StergereLista(Nod* prim);
Nod** StergereTabela(Nod** hash_map);
int main() {

	Nod** hash_map;
	hash_map = (Nod**)malloc(DIMENSIUNE_HASHMAP * sizeof(Nod*));
	for (int i = 0; i < DIMENSIUNE_HASHMAP; i++)
		hash_map[i] = NULL;

	FILE* f;
	f = fopen("Curse.txt", "r");

	char buffer[256];
	char seps[] = ",\n";

	while (fgets(buffer, sizeof(buffer), f)) {
		CursaAeriana ca;
		char* token = strtok(buffer, seps);
		ca.cod = (char*)malloc(strlen(token) + 1);
		strcpy(ca.cod, token);
		
		token = strtok(NULL, seps);
		ca.destinatie = (char*)malloc(strlen(token) + 1);
		strcpy(ca.destinatie, token);
		
		token = strtok(NULL, seps);
		ca.ora_plecare = (char*)malloc(strlen(token) + 1);
		strcpy(ca.ora_plecare, token);
		
		token = strtok(NULL, seps);
		ca.plecare = (char*)malloc(strlen(token) + 1);
		strcpy(ca.plecare, token);
		
		token = strtok(NULL, seps);
		ca.status_cursa = (char*)malloc(strlen(token) + 1);
		strcpy(ca.status_cursa, token);

		InserareCursaAerianaTabela(hash_map,ca);
	}
	printf("De unde sa plece avionul: ");
	scanf("%s", buffer);
	char* x = (char*)malloc(strlen(buffer) + 1);
	strcpy(x, buffer);
	printf("La cat sa plece avionul: ");
	scanf("%s", buffer);
	char* y = (char*)malloc(strlen(buffer) + 1);
	strcpy(y, buffer);
	printf("Numarul de curse care ajung la: %s, cu ora de plecare: %s, sunt: %d", x, y, NumarCurse(hash_map, x, y));
	free(x);
	free(y);

	printf("De unde sa plece avionul: ");
	scanf("%s", buffer);
	x = (char*)malloc(strlen(buffer) + 1);
	strcpy(x, buffer);
	printf("Ce status sa aiba avionul: ");
	scanf("%s", buffer);
	y = (char*)malloc(strlen(buffer) + 1);
	strcpy(y, buffer);
	StergereCurse(hash_map, x, y);
	free(x);
	free(y);
}

void InserareCursaAerianaTabela(Nod** hash_map, CursaAeriana ca) {
	int poz = CalculareHash(ca.destinatie);
	
	hash_map[poz] = InserareCursaAeriana(hash_map[poz], ca);
}

int CalculareHash(char* destinatie) {
	int s = 0;
	for (int i = 0; i < strlen(destinatie); i++)
		s += (int)destinatie[i];

	return s % DIMENSIUNE_HASHMAP;
}

Nod* InserareCursaAeriana(Nod* hash_map, CursaAeriana ca) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->ca = ca;
	nou->next = hash_map;
	return nou;
}

int NumarCurse(Nod** hash_map, char* cheie, char* plecare) {
	int poz = CalculareHash(cheie), nr = 0;
	Nod* curent;

	if (hash_map[poz] == NULL)
		return 0;
	curent = hash_map[poz];
	while (curent) {
		if (strcmp(curent->ca.plecare, plecare) == 0)
			nr++;
		curent = curent->next;
	}

	return nr;
}

void StergereCurse(Nod** hash_map, char* cheie, char* status_cursa) {
	int poz = CalculareHash(cheie), nr = 0;
	Nod* curent, * aux;

	if (hash_map[poz] == NULL)
		return;
	if (hash_map[poz]) {
		while (hash_map[poz] && strcmp(hash_map[poz]->ca.status_cursa, status_cursa) == 0) {
			curent = hash_map[poz];
			hash_map[poz] = hash_map[poz]->next;
			free(curent->ca.cod);
			free(curent->ca.destinatie);
			free(curent->ca.ora_plecare);
			free(curent->ca.status_cursa);
			free(curent->ca.plecare);
			free(curent);
		}
		if (hash_map[poz]) {
			curent = hash_map[poz];
			while (curent->next) {
				if (strcmp(curent->next->ca.status_cursa, status_cursa) == 0) {
					aux = curent->next;
					curent->next = aux->next;
					free(aux->ca.cod);
					free(aux->ca.destinatie);
					free(aux->ca.ora_plecare);
					free(aux->ca.status_cursa);
					free(aux->ca.plecare);
					free(aux);
				}
				else
					curent = curent->next;
			}
		}
	}
}


Nod* StergereLista(Nod* prim) {
	Nod* curent = prim;
	if (prim == NULL)
		return NULL;
	while (prim) {
		curent = prim;
		prim = prim->next;
		free(curent->ca.cod);
		free(curent->ca.destinatie);
		free(curent->ca.ora_plecare);
		free(curent->ca.plecare);
		free(curent->ca.status_cursa);
		free(curent);
	}
	return NULL;
}

Nod** StergereTabela(Nod** hash_map) {
	for (int i = 0; i < DIMENSIUNE_HASHMAP; i++)
		hash_map[i] = StergereLista(hash_map[i]);
	free(hash_map);
	return NULL;
}