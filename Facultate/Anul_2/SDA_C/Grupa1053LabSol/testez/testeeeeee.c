#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct Client{
	char* nume;
	int id;
	char tip;
	int puncte;
	float medie_cos;
};

typedef struct Client Client;

struct Nod_simplu{
	Client cl;
	struct Nod_simplu* next;
};
struct Nod_dublu{
	Client cl;
	struct Nod_dublu* next, * prev;
};
typedef struct Nod_dublu Nod_dublu;

struct ListaDubla {
	Nod_dublu* prim_dublu, * ultim_dublu;
};

typedef struct Nod_simplu Nod_simplu;
typedef struct ListaDubla ListaDubla;

Nod_simplu* ins_sf_simplu(Nod_simplu* prim, Client cl);
Nod_simplu* ins_id_asc_simplu(Nod_simplu* prim, Client cl);
Nod_simplu* stergere_medie_simplu(Nod_simplu* prim, float medie);
Nod_simplu* stergere_lista_simplu(Nod_simplu* prim);
void traversare_simplu(Nod_simplu* prim);

ListaDubla* ins_sf_dublu(ListaDubla* capete, Client cl);
ListaDubla* ins_id_asc_dublu(ListaDubla* capete, Client cl);
ListaDubla* stergere_medie_dublu(ListaDubla* capete, float medie);
ListaDubla* stergere_lista_dublu(ListaDubla* capete);
void traversare_dublu(ListaDubla* capete);

Nod_simplu* ins_sf_circular(Nod_simplu* prim, Client cl);
Nod_simplu* ins_id_asc_circular(Nod_simplu* prim, Client cl);
Nod_simplu* stergere_medie_circular(Nod_simplu* prim, float medie);
Nod_simplu* stergere_lista_circular(Nod_simplu* prim);
Nod_simplu* intersichmbare_poz(Nod_simplu* prim, int poz);
void traversare_circular(Nod_simplu* prim);

int main() {
	Nod_simplu* prim_simplu = NULL;
	Nod_simplu* prim_id_asc = NULL;

	ListaDubla* capete = (ListaDubla *)malloc(sizeof(ListaDubla));
	capete->prim_dublu = NULL;
	capete->ultim_dublu = NULL;
	ListaDubla* capete_id_asc = (ListaDubla *)malloc(sizeof(ListaDubla));
	capete_id_asc->prim_dublu = NULL;
	capete_id_asc->ultim_dublu = NULL;

	Nod_simplu* prim_circular = NULL;
	Nod_simplu* prim_id_asc_circular = NULL;

	FILE* f;
	f = fopen("Clienti.txt", "r");
	char buffer[256];
	char seps[] = ",\n";

	while (fgets(buffer, sizeof(buffer), f)) {
		Client cl;
		char* token = strtok(buffer, seps);
		cl.nume = (char*)malloc(strlen(token) + 1);
		strcpy(cl.nume, token);

		token = strtok(NULL, seps);
		cl.id = atoi(token);

		token = strtok(NULL, seps);
		cl.tip = token[0];

		token = strtok(NULL, seps);
		cl.puncte = atoi(token);

		token = strtok(NULL, seps);
		cl.medie_cos = (float)atof(token);

		//prim_simplu = ins_sf_simplu(prim_simplu, cl);
		//prim_id_asc = ins_id_asc_simplu(prim_id_asc, cl);

		//capete = ins_sf_dublu(capete, cl);
		//capete_id_asc = ins_id_asc_dublu(capete_id_asc, cl);
		
		prim_circular = ins_sf_circular(prim_circular, cl);
		prim_id_asc = ins_id_asc_circular(prim_id_asc, cl);

		//printf("%s %d %c %d %f\n", cl.nume, cl.id, cl.tip, cl.puncte, cl.medie_cos);
	}

	fclose(f);
	//traversare_simplu(prim_simplu);
	//printf("\n");
	//traversare_simplu(prim_id_asc);
	//prim_simplu = stergere_lista_simpla(prim_simplu);
	//prim_id_asc = stergere_lista_simpla(prim_id_asc);

	/*traversare_dublu(capete);
	printf("\n");
	traversare_dublu(capete_id_asc);
	capete = stergere_lista_dublu(capete);
	capete_id_asc = stergere_lista_dublu(capete_id_asc);*/



}

Nod_simplu* ins_sf_simplu(Nod_simplu* prim, Client cl) {
	Nod_simplu* nod_nou = (Nod_simplu*)malloc(sizeof(Nod_simplu)), *curent = prim;
	nod_nou->cl = cl;
	nod_nou->next = NULL;
	if (prim == NULL) {
		return nod_nou;
	}
	else {
		while (curent->next != NULL)
			curent = curent->next;
		curent->next = nod_nou;
		return prim;
	}
}

Nod_simplu* ins_id_asc_simplu(Nod_simplu* prim, Client cl) {
	Nod_simplu* nod_nou = (Nod_simplu*)malloc(sizeof(Nod_simplu)), * curent = prim;
	nod_nou->cl = cl;

	if (prim == NULL) {
		nod_nou->next = NULL;
		return nod_nou;
	}
	else {
		//daca id este mai mic decat la primul
		if (prim->cl.id > nod_nou->cl.id) {
			nod_nou->next = prim;
			return nod_nou;
		}
		else {
			if (curent->next == NULL) {
				curent->next = nod_nou;
				nod_nou->next = NULL;
			}
			else {
				while (curent->next) {
					if (curent->next->cl.id > nod_nou->cl.id) {
						nod_nou->next = curent->next;
						curent->next = nod_nou;
						return prim;
					}

					curent = curent->next;
				}


				curent->next = nod_nou;
				nod_nou->next = NULL;
			}
			return prim;
		}
	}
}

Nod_simplu* stergere_medie_simplu(Nod_simplu* prim, float medie) {
	Nod_simplu* curent, *aux;
	if (prim) {
		while (prim && prim->cl.medie_cos == medie) {
			curent = prim;
			prim = prim->next;
			free(curent->cl.nume);
			free(curent);
		}
		if (prim) {
			curent = prim;
			while (curent->next) {
				if (curent->next->cl.medie_cos == medie) {
					aux = curent->next;
					curent->next = curent->next->next;

					free(aux->cl.nume);
					free(aux);
				}
				else
					curent = curent->next;
			}
		}
	}
	return prim;
}

Nod_simplu* stergere_lista_simpla(Nod_simplu* prim) {
	Nod_simplu* curent;
	while (prim) {
		curent = prim;
		prim = prim->next;
		free(curent->cl.nume);
		free(curent);
	}
	return prim;
}

void traversare_simplu(Nod_simplu* prim) {
	Nod_simplu* curent = prim;
	while (curent) {
		printf("%d      %s %c %d %f\n", curent->cl.id, curent->cl.nume, curent->cl.tip, curent->cl.puncte, curent->cl.medie_cos);
		curent = curent->next;
	}
}

ListaDubla* ins_sf_dublu(ListaDubla* capete, Client cl) {
	if (capete == NULL) {
		printf("List este goala");
		return NULL;
	}

	Nod_dublu* nod_nou = (Nod_dublu*)malloc(sizeof(Nod_dublu));
	nod_nou->cl = cl;
	nod_nou->next = NULL;
	nod_nou->prev = NULL;
	if (capete->ultim_dublu == NULL) {
		capete->prim_dublu = nod_nou;
		capete->ultim_dublu = nod_nou;
	}else {
		capete->ultim_dublu->next = nod_nou;
		nod_nou->prev = capete->ultim_dublu;
		capete->ultim_dublu = nod_nou;
	}
	
	return capete;
}

ListaDubla* ins_id_asc_dublu(ListaDubla* capete, Client cl) {
	if(capete == NULL) {
		printf("List este goala");
		return NULL;
	}
	Nod_dublu* nod_nou = (Nod_dublu*)malloc(sizeof(Nod_dublu)), * curent;
	nod_nou->cl = cl;
	nod_nou->next = NULL;
	nod_nou->prev = NULL;

	if (capete->ultim_dublu == NULL) {
		capete->prim_dublu = nod_nou;
		capete->ultim_dublu = nod_nou;
	} else if(capete->prim_dublu->cl.id > nod_nou->cl.id){
		nod_nou->next = capete->prim_dublu;
		capete->prim_dublu->prev = nod_nou;
		capete->prim_dublu = nod_nou;
	} else if (capete->ultim_dublu->cl.id <= nod_nou->cl.id) {
		capete->ultim_dublu->next = nod_nou;
		nod_nou->prev = capete->ultim_dublu;
		capete->ultim_dublu = nod_nou;
	} else{
		curent = capete->prim_dublu;
		while (curent->next != NULL && curent->next->cl.id < nod_nou->cl.id)
			curent = curent->next;

		nod_nou->next = curent->next;
		nod_nou->prev = curent;

		if (curent->next != NULL) {
			curent->next->prev = nod_nou;
		}
		else {
			capete->ultim_dublu = nod_nou;
		}
		curent->next = nod_nou;
	}

	return capete;
}

ListaDubla* stergere_medie_dublu(ListaDubla* capete, float medie) {
	if (capete == NULL) {
		printf("List este goala");
		return NULL;
	}
	Nod_dublu* curent = capete->prim_dublu;
	Nod_dublu* next, * prev;
	
	while (curent) {
		if (curent->cl.medie_cos == medie) {
			next = curent->next;
			prev = curent->prev;

			free(curent->cl.nume);
			free(curent);

			if (next == NULL && prev == NULL) {
				capete->prim_dublu = capete->ultim_dublu = NULL;
				curent = NULL;
			}
			else if (prev == NULL) {
				next->prev = NULL;
				capete->prim_dublu = next;
				curent = next;
			}
			else if (next == NULL) {
				prev->next = NULL;
				capete->ultim_dublu = prev;
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

	return capete;
}

ListaDubla* stergere_lista_dublu(ListaDubla* capete) {
	if (capete == NULL)
		return NULL;

	Nod_dublu* curent;
	while (capete->prim_dublu) {
		curent = capete->prim_dublu;
		capete->prim_dublu = capete->prim_dublu->next;
		free(curent->cl.nume);
		free(curent);
	}
	free(capete);
	capete = NULL;
	return capete;
}

void traversare_dublu(ListaDubla* capete) {
	if (capete == NULL || capete->prim_dublu == NULL) {
		printf("List este goala");
		return;
	}
	
	Nod_dublu* curent;

	printf("Afisarea de la stanga la dreapta:\n");
	curent = capete->prim_dublu;
	while (curent) {
		printf("%s %d %c %d %f\n", curent->cl.nume, curent->cl.id, curent->cl.tip, curent->cl.puncte, curent->cl.medie_cos);
		curent = curent->next;
	}
	printf("\n\n");

	printf("Afisarea de la dreapta la stanga:\n");
	curent = capete->ultim_dublu;
	while (curent) {
		printf("%s %d %c %d %f\n", curent->cl.nume, curent->cl.id, curent->cl.tip, curent->cl.puncte, curent->cl.medie_cos);
		curent = curent->prev;
	}
	printf("\n\n");
}

Nod_simplu* ins_sf_circular(Nod_simplu* prim, Client cl) {
	Nod_simplu* nod_nou = (Nod_simplu*)malloc(sizeof(Nod_simplu)), * curent = prim;
	nod_nou->cl = cl;
	if (prim == NULL) {
		nod_nou->next = nod_nou;
		return nod_nou;
	}
	else {
		while (curent->next != prim)
			curent = curent->next;
		curent->next = nod_nou;
		nod_nou->next = prim;
		return prim;
	}
}

Nod_simplu* ins_id_asc_circular(Nod_simplu* prim, Client cl){
	Nod_simplu* nod_nou = (Nod_simplu*)malloc(sizeof(Nod_simplu)), * curent = prim;
	nod_nou->cl = cl;

	if (prim == NULL) {
		nod_nou->next = nod_nou;
		return nod_nou;
	}
	else {
		if (prim->cl.id > nod_nou->cl.id) {
			curent = prim;
			while (curent->next != prim)
				curent = curent->next;

			nod_nou->next = prim;
			curent->next = nod_nou;
			return nod_nou;
		}
		else {
			curent = prim;
			if (curent->next == prim) {
				curent->next = nod_nou;
				nod_nou->next = curent;
			}
			else {
				while (curent->next != prim) {
					if (curent->next->cl.id > nod_nou->cl.id) {
						nod_nou->next = curent->next;
						curent->next = nod_nou;
						return prim;
					}

					curent = curent->next;
				}


				curent->next = nod_nou;
				nod_nou->next = prim;
			}
			return prim;
		}
	}
}

Nod_simplu* stergere_medie_circular(Nod_simplu* prim, float medie) {
	Nod_simplu* curent, * aux, *ultim = prim;
	while (ultim->next != prim) {
		ultim = ultim->next;
	}
	if (prim) {
		while (prim && prim->cl.medie_cos == medie) {
			if (prim == ultim) {
				free(prim->cl.nume);
				free(prim);
				prim = NULL;
				return prim;
			}
			curent = prim;
			prim = prim->next;
			ultim->next = prim;
			free(curent->cl.nume);
			free(curent);
		}
		if (prim) {
			curent = prim;
			while (curent->next != prim) {
				if (curent->next->cl.medie_cos == medie) {
					aux = curent->next;
					curent->next = aux->next;

					free(aux->cl.nume);
					free(aux);
				}
				else
					curent = curent->next;
			}
		}
	}
	return prim;
}

Nod_simplu* stergere_lista_circular(Nod_simplu* prim) {
	if (prim == NULL)
		return;
	
	Nod_simplu* curent, *ultim = prim;
	while (ultim->next != prim) {
		ultim = ultim->next;
	}
	ultim->next = NULL;
	while (prim) {
		curent = prim;
		prim = prim->next;
		free(curent->cl.nume);
		free(curent);
	}
	return prim;
}

Nod_simplu* intersichmbare_poz(Nod_simplu* prim, int poz) {
	if (prim == NULL || prim->next == prim) return prim;

	int s = 0;
	Nod_simplu* curent = prim;
	do {
		s++;
		curent = curent->next;
	} while (curent != prim);

	if (poz < 1 || poz > s) return prim;

	Nod_simplu* prev = prim;
	Nod_simplu* ultim = prim;
	while (ultim->next != prim)
		ultim = ultim->next;

	if (poz == 1) {
		prev = ultim;
	}
	else {
		for (int i = 1; i < poz - 1; i++) {
			prev = prev->next;
		}
	}

	// prev -> p -> q -> restul listei
	Nod_simplu* p = prev->next;
	Nod_simplu* q = p->next;

	p->next = q->next;
	q->next = p;
	prev->next = q;

	if (poz == 1) {
		prim = q;
	}

	return prim;
}

void traversare_circular(Nod_simplu* prim) {
	Nod_simplu* curent = prim;
	if (prim == NULL)
		return;

	do {
		printf("%d      %s %c %d %f\n", curent->cl.id, curent->cl.nume, curent->cl.tip, curent->cl.puncte, curent->cl.medie_cos);
		curent = curent->next;
	} while (curent != prim)
}