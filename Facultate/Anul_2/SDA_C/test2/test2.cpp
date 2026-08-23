#define _CRT_SECURE_NO_WARNINGS;

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Comanda {
	unsigned int id;
	char* data_lansare;
	char* data_livrare;
	char* nume_client;
	float pret;
};

typedef struct Comanda Comanda;

struct Nod {
	Comanda c;
	Nod* next, * prev;
};

typedef struct Nod Nod;

struct Lista {
	Nod* prim, * ultim;
};

typedef struct Lista Lista;

Lista* InserareLista(Lista* lista, Comanda c);
void AfisareLista(Lista* lista);
Lista* StergereLista(Lista* lista);
int NumarComenzi(Lista* lista, char* data_livrare);
Lista* StergereComenzi(Lista* lista, char* data_livrare);

int main() {
	Lista* lista = (Lista *)malloc(sizeof(Lista));
	lista->prim = NULL;
	lista->ultim = NULL;

	FILE* f;
	f = fopen("Comenzii.txt", "r");
	char buffer[256];
	char seps[] = ",\n";

	while (fgets(buffer, sizeof(buffer), f)) {
		Comanda c;
		char* token = strtok(buffer, seps);
		c.id = atoi(token);

		token = strtok(NULL, seps);
		c.data_lansare = (char*)malloc(strlen(token) + 1);
		strcpy(c.data_lansare, token);

		token = strtok(NULL, seps);
		c.data_livrare = (char*)malloc(strlen(token) + 1);
		strcpy(c.data_livrare, token);

		token = strtok(NULL, seps);
		c.nume_client = (char*)malloc(strlen(token) + 1);
		strcpy(c.nume_client, token);

		token = strtok(NULL, seps);
		c.pret = (float)atof(token);

		lista = InserareLista(lista, c);
	}

	printf("Dupa ce data de livare sa se caute(ex.: 03/04/2016): ");
	scanf("%s", buffer);
	char* x = (char*)malloc(strlen(buffer) + 1);
	strcpy(x, buffer);
	printf("Numarul de comenzi gasite este: %d\n", NumarComenzi(lista, x));

	NumarComenzi(lista, x);
	AfisareLista(lista);
	free(x);
}

Lista* InserareLista(Lista* lista, Comanda c) {
	if (lista == NULL)
		return NULL;

	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->c = c;
	nou->next = nou->prev = NULL;
	if (lista->prim == NULL)
		lista->prim = lista->ultim = nou;
	else {
		lista->ultim->next = nou;
		nou->prev = lista->ultim;
		lista->ultim = nou;
	}

	return lista;
}

void AfisareLista(Lista* lista) {
	if (lista == NULL || lista->prim == NULL)
		return;

	Nod* curent;

	printf("Afisare de la stanga la dreapta:\n");
	curent = lista->prim;
	while (curent) {
		printf("%d %s %s %s %f", curent->c.id, curent->c.data_lansare, curent->c.data_livrare, curent->c.nume_client, curent->c.pret);
		curent = curent->next;
	}

	printf("Afisare de la dreapta la stanga:\n");
	curent = lista->ultim;
	while (curent) {
		printf("%d %s %s %s %f", curent->c.id, curent->c.data_lansare, curent->c.data_livrare, curent->c.nume_client, curent->c.pret);
		curent = curent->prev;
	}
}

Lista* StergereLista(Lista* lista) {
	if (!lista) return;
	Nod* curent = lista->prim;
	while (curent) {
		Nod* aux = curent;
		curent = curent->next;
		free(aux->c.data_lansare);
		free(aux->c.data_livrare);
		free(aux->c.nume_client);
		free(aux);
	}
	free(lista);

	return NULL;
}

int NumarComenzi(Lista* lista, char* data_livrare) {
	if (lista == NULL || lista->prim == NULL)
		return 0;

	Nod* curent = lista->prim;
	int nr = 0;
	while (curent) {
		if (strcmp(curent->c.data_livrare, data_livrare) == 0)
			nr++;
		curent = curent->next;
	}

	return nr;
}

Lista* StergereComenzi(Lista* lista, char* data_livrare) {
	if (lista == NULL || lista->prim == NULL)
		return 0;

	Nod* curent = lista->prim;
	Nod* next, * prev;

	while (curent) {
		next = curent->next;
		prev = curent->prev;
		if (strcmp(curent->c.data_livrare, data_livrare) == 0) {
			free(curent->c.data_lansare);
			free(curent->c.data_livrare);
			free(curent->c.nume_client);
			free(curent);

			if (next == NULL && prev == NULL) {
				free(lista);
				lista = NULL;
			}
			else if (prev == NULL) {
				next->prev = NULL;
				lista->prim = next;
				curent = next;
			}
			else if (next == NULL) {
				prev->next = NULL;
				lista->ultim = prev;
				curent = NULL;
			}
			else {
				prev->next = next;
				next->prev = prev;
				curent = next;
			}
		}
		else
			curent = curent->next;
	}
}