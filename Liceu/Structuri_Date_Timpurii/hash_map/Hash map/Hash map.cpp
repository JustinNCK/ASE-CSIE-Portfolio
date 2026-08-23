#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
/*
struct pers {
    char nume[30];
    int produse, pret;
    pers* next;
};

struct hash_map {
    pers** array;
    int dim;
};

pers* crearea_nod(char nume[30], int produse, int pret);
pers* inserare(pers* prim, char nume[30], int produse, int pret);
int compute_hash(char nume[30], int dim);
hash_map creare_hash(int dim);
hash_map inserare_hash(hash_map h, char nume[30], int produse, int pret);
void afisare_nod(char nume[30], int produse, int pret);
void afisare_lista(pers* prim);
void afisare_hash(hash_map h);
void funct1(hash_map h);
void funct2(hash_map h);

int main(){
    FILE* f;

    f = fopen("prob.txt", "r");

    char nume[30];
    int produse, pret;

    int nr;

    hash_map h = creare_hash(50);
    

    if (!f)
        printf("Fisierul nu s-a deschis");
    else {
        fscanf(f, "%s %d %d", nume, &produse, &pret);
        //printf("%s %d %d\n", nume, produse, pret);
        h = inserare_hash(h, nume, produse, pret);
        while (!feof(f)) {
            fscanf(f, "%s %d %d", nume, &produse, &pret);
            //printf("%s %d %d\n", nume, produse, pret);
            h = inserare_hash(h, nume, produse, pret);
        }
    }

    //afisare_hash(h);

    printf("Dati numarul functiei: ");
    fflush(stdin);
    scanf("%d", &nr);

    if (nr == 1)
        funct1(h);
    else
        funct2(h);
}

pers* crearea_nod(char nume[30], int produse, int pret){
    pers* nod_nou = (pers*)malloc(sizeof(pers));
    
    strcpy(nod_nou->nume, nume);
    nod_nou->produse = produse;
    nod_nou->pret = pret;
    nod_nou->next = NULL;
    return nod_nou;
}

pers* inserare(pers* prim, char nume[30], int produse, int pret) {
    pers* nod_nou = crearea_nod(nume, produse, pret), *curent = prim;

    if (prim == NULL) {
        prim = nod_nou;
    }
    else {
        while (curent->next != NULL)
            curent = curent->next;

        curent->next = nod_nou;
    }

    return prim;
}

hash_map creare_hash(int dim) {
    hash_map h;
    h.array = (pers**)malloc(dim * sizeof(pers*));
    h.dim = dim;

    for (int i = 0; i < h.dim; i++) {
        h.array[i] = NULL;
    }

    return h;
}

int compute_hash(char nume[30], int dim) {
    int s = 0;

    for (int i = 0; i < strlen(nume); i++)
        s += int(nume[i]);

    s %= dim;

    //printf("Hash la %s este %d\n", nume, s);
       
    return s;
}

hash_map inserare_hash(hash_map h, char nume[30], int produse, int pret) {
    int poz = compute_hash(nume, h.dim);

    h.array[poz] = inserare(h.array[poz], nume, produse, pret);
    return h;
}

void afisare_nod(char nume[30], int produse, int pret) {
    printf("(%s  %d  %d) ", nume, produse, pret);
}

void afisare_lista(pers* prim) {
    while (prim != NULL) {
        afisare_nod(prim->nume, prim->produse, prim->pret);
        prim = prim->next;
    }
    printf("\n");
}

void afisare_hash(hash_map h) {
    for (int i = 0; i < h.dim; i++)
        if (h.array[i] != NULL) {
            printf("%d: ", i);
            afisare_lista(h.array[i]);
        }
        else {
            printf("%d: NULL\n", i);
        }
}

void funct1(hash_map h) {
    int s1, s2;
    pers *curent;
    for (int i = 0; i < h.dim; i++)
        if (h.array[i] != NULL) {
            s1 = 0;
            s2 = 0;
            curent = h.array[i];

            while (curent != NULL) {
                s1 += curent->produse;
                s2 += curent->produse * curent->pret;

                curent = curent->next;
            }

            if (s1 >= 20 || s2 >= 1000)
                printf("%s \n", h.array[i]->nume);

        }
}

void funct2(hash_map h) {
    int* v = (int *)calloc(h.dim, sizeof(int)), nr;
    pers* curent;

    for (int i = 0; i < h.dim; i++)
        if (h.array[i] != NULL) {
            curent = h.array[i];
            while (curent != NULL) {
                v[i] += (curent->produse - curent->produse / 5) * curent->pret;
                
                curent = curent->next;
            }

        }

    for(int i = 0; i < h.dim; i++)
        if (v[i] != 0) {
            nr = 0;
            for(int j = i + 1; j < h.dim; j++)
                if(v[j] != 0)
                    if (v[i] == v[j]) {
                        printf("%s ", h.array[j]->nume);
                        v[j] = 0;
                        nr = 1;
                    }
            if(nr == 1)
                printf("%s", h.array[i]->nume);

            v[i] = 0;

            printf("\n");
        }

    free(v);
}

//TEMA: functie afisare hash, citire info dintr-un fisier, termin problema
*/
/*
struct Serviciu {
    unsigned int id_serv;
    char *tip_serv, *nume_client;
    float suma_plata;
    unsigned int timp_end;
    
    Serviciu* next;
};

struct hash_map {
    Serviciu** array;
    int dim;
};

struct hash_map citire_hash(int dim);
struct hash_map creare_hash_map(int dim);
int compute_hash(char nume[30], int dim);
void inserare_hash(hash_map h, unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end);
struct Serviciu* inserare_lista(struct Serviciu* prim, unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end);
struct Serviciu* creare_nod(unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end);
void funct_1(char nume_client[30], hash_map h);
void funct_2(hash_map h);
void funct_3(hash_map h, unsigned int durata);
void afisare_hash(hash_map h);
void afisare_lista(struct Serviciu* prim);
void afisare_nod(unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end);
struct hash_map stergere_hash(struct hash_map h);
struct Serviciu* stergere_lista(struct Serviciu* prim);
void schimbare_hash(struct hash_map h1);


int main() {
    hash_map h = citire_hash(100);
    char nume_client[30];
    int funct;
    unsigned int durata;

    
	afisare_hash(h);
    printf("Numarul functeiei apelate: ");
    fflush(stdin);
    scanf("%d", &funct);

    
    if (funct == 1) {
        printf("Numele clientului cautat: ");
        scanf("%s", &nume_client);
        funct_1(nume_client, h);
    }
    
    if (funct == 2) {
        funct_2(h);
        afisare_hash(h);
    }

    if (funct == 3){
        printf("Durata maxima: ");
        scanf("%d", &durata);
        funct_3(h, durata);
    }

    //afisare_hash(h);
    //h = stergere_hash(h);
    //afisare_hash(h);
    schimbare_hash(h);
}

struct hash_map citire_hash(int dim) {
    hash_map h = creare_hash_map(dim);
    
    FILE* f;
    f = fopen("date.txt", "r");

    unsigned int id_serv;
    char tip_serv[50], nume_client[30];
    float suma_plata;
    unsigned int timp_end;

    if (!f)
        printf("Nu s-a deschis fisierul\n");
    else {
        fscanf(f, "%d %s %s %f %d", &id_serv, &tip_serv, &nume_client, &suma_plata, &timp_end);
        
        while (!feof(f)) {
            inserare_hash(h, id_serv, tip_serv, nume_client, suma_plata, timp_end);

            fscanf(f, "%d %s %s %f %d", &id_serv, &tip_serv, &nume_client, &suma_plata, &timp_end);
        }

        fclose(f);
    }

    return h;
}

struct hash_map creare_hash_map(int dim) {
    hash_map h;
    h.array = (Serviciu**)malloc(dim * sizeof(Serviciu *));
    h.dim = dim;

    for (int i = 0; i < dim; i++)
        h.array[i] = NULL;

    return h;
}

int compute_hash(char nume[30], int dim) {
    int sum = 0;

    for (int i = 0; i < strlen(nume); i++)
        sum += nume[i];

    return sum % dim;
}

void inserare_hash(hash_map h, unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end) {
    int poz = compute_hash(nume_client, h.dim);

    h.array[poz] = inserare_lista(h.array[poz], id_serv, tip_serv, nume_client, suma_plata, timp_end);
}

struct Serviciu *inserare_lista(struct Serviciu *prim, unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end){
    Serviciu* nod_nou = creare_nod(id_serv, tip_serv, nume_client, suma_plata, timp_end), *curent = NULL;

    if (prim == NULL)
        prim = nod_nou;
    else {
        curent = prim;
        while (curent->next != NULL)
            curent = curent->next;

        curent->next = nod_nou;
    }

    return prim;
}

struct Serviciu *creare_nod(unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end) {
    Serviciu* nod_nou = (Serviciu*)malloc(1 * sizeof(Serviciu));

    if (nod_nou == NULL)
        return NULL;

    nod_nou->id_serv = id_serv;
    
    nod_nou->tip_serv = (char*)malloc(strlen(tip_serv) * sizeof(char) + 1);
    strcpy(nod_nou->tip_serv, tip_serv);
    
    nod_nou->nume_client = (char*)malloc(strlen(nume_client) * sizeof(char) + 1);
    strcpy(nod_nou->nume_client, nume_client);
    
    nod_nou->suma_plata = suma_plata;
    
    nod_nou->timp_end = timp_end;

    nod_nou->next = NULL;

    return nod_nou;
}

void funct_1(char nume_client[30], hash_map h) {
    int poz = compute_hash(nume_client, h.dim), nr = 0;
    struct Serviciu* curent = h.array[poz];

    while (curent != NULL) {
        if (strcmp(nume_client, curent->nume_client) == 0) {
            nr++;
        }

        curent = curent->next;
    }

    printf("%s a avut %d servicii\n", nume_client, nr);
}

void funct_2(struct hash_map h) {
    struct Serviciu* prim = NULL;
    int nr;

    for (int i = 0; i < h.dim; i++)
        if (h.array[i] != NULL) {
            prim = h.array[i];
            nr = i;
        }

    if (prim->next == NULL) {
        free(prim);
        h.array[nr] = NULL;
    }
    else {
        while (prim->next->next != NULL)
            prim = prim->next;

        free(prim->next);
        prim->next = NULL;
    }

}

void funct_3(struct hash_map h, unsigned int durata) {
    struct Serviciu* prim, **v;
    int nr = 0;

    for(int i = 0; i < h.dim; i++)
        if (h.array[i] != NULL) {
            prim = h.array[i];
            while (prim != NULL) {
                if (prim->timp_end > durata)
                    nr++;

				prim = prim->next;
            }
        }

    v = (Serviciu**)malloc(nr * sizeof(Serviciu*));
    nr = 0;
    for (int i = 0; i < h.dim; i++)
        if (h.array[i] != NULL) {
            prim = h.array[i];
            while (prim != NULL) {
                if (prim->timp_end > durata) {
                    v[nr] = prim;
                    nr++;
                }

				prim = prim->next;
            }
        }

    for (int i = 0; i < nr; i++) {
        afisare_nod(v[i]->id_serv, v[i]->tip_serv, v[i]->nume_client, v[i]->suma_plata, v[i]->timp_end);

            printf("\n");
    };
}

void afisare_hash(struct hash_map h) {
    if (h.array == NULL)
        printf("Hash-ul e gol\n");
    else {
        for (int i = 1; i <= h.dim; i++)
            if (h.array[i - 1] != NULL) {
                printf("%d: ", i);
                afisare_lista(h.array[i - 1]);
            }
            else {
                printf("%d: NULL\n", i);
            }
    }
}

void afisare_lista(struct Serviciu* prim) {
	while (prim != NULL) {
		afisare_nod(prim->id_serv, prim->tip_serv, prim->nume_client, prim->suma_plata, prim->timp_end);
		prim = prim->next;
	}
	printf("\n");
}

void afisare_nod(unsigned int id_serv, char tip_serv[50], char nume_client[30], float suma_plata, unsigned int timp_end) {
	printf("(%d %s %s %.2f %d) ", id_serv, tip_serv, nume_client, suma_plata, timp_end);
}

struct hash_map stergere_hash(struct hash_map h) {
    for (int i = 0; i < h.dim; i++)
        if (h.array[i] != NULL)
            h.array[i] = stergere_lista(h.array[i]);

    free(h.array);
    
    h.array = NULL;
    h.dim = 0;

    return h;
}

struct Serviciu* stergere_lista(struct Serviciu* prim) {
    struct Serviciu* curent;
    
    while (prim != NULL) {
        curent = prim->next;
        free(prim->tip_serv);
        free(prim->nume_client);
        prim->tip_serv = NULL;
        prim->nume_client = NULL;
        prim->id_serv = 0;
        prim->suma_plata = 0;
        prim->timp_end = 0;

        prim->next = NULL;

        free(prim);

        prim = curent;
        
    }

    return NULL;
}

void schimbare_hash(struct hash_map h1) {
    struct hash_map h2;
    struct Serviciu* prim;
    int dim;

    printf("Dimensiunea noului hash_map: ");
    fflush(stdin);
    scanf("%d", &dim);
    
    h2 = creare_hash_map(dim);

    for(int i = 0; i < h1.dim; i++)
        if (h1.array[i] != NULL) {
            prim = h1.array[i];
            while (prim != NULL) {
                inserare_hash(h2, prim->id_serv, prim->tip_serv, prim->nume_client, prim->suma_plata, prim->timp_end);
            
                prim = prim->next;
            }
        }
       
	afisare_hash(h2);
}
*/
//TEMA: dezalocare hash, copiere hash creat de 100 intr-un hash nou de 200
//dezalocare hash: stergere_nod, stergere_lista, dezalocare vector din structura hash;
//copiere hash . . . : h1 este hash-ul vechi, iar h2 este hash-ul nou, citind din h1 trec fiecare nod prin tot procesul inca odata pt h2

struct farmacie {
    char* nume;
    float sup;
    unsigned int nr_ang;
    char* adresa;
    
    struct farmacie* next, * prev;
};
void creare_lista(struct farmacie*& prim, struct farmacie*& ultim);
void inserare_lista(struct farmacie*& prim, struct farmacie*& ultim, char nume[30], float sup, unsigned int nr_ang, char adresa[30]);
struct farmacie* creare_nod(char nume[30], float sup, unsigned int nr_ang, char adresa[30]);
void funct1(struct farmacie* prim, struct farmacie* ultim);
void funct2(struct farmacie*& prim, struct farmacie*& ultim);
void funct3(struct farmacie* prim, struct farmacie* ultim);
void afisare_lista(struct farmacie* prim, struct farmacie* ultim);
void afisare_nod(struct farmacie* nod);

void main() {
    struct farmacie* prim = NULL, * ultim = NULL;

    int nr;

    creare_lista(prim, ultim);

    //afisare_lista(prim, ultim);
    
    printf("Nr. functiei: ");
    fflush(stdin);
    scanf("%d", &nr);

    if (nr == 1)
        funct1(prim , ultim);

    if (nr == 2) {
        funct2(prim, ultim);

        afisare_lista(prim, ultim);
    }

    if (nr == 3)
        funct3(prim, ultim);
}

void creare_lista(struct farmacie*& prim, struct farmacie*& ultim) {
    FILE* f;

    f = fopen("farmacie.txt", "r");

    char nume[30];
    float sup;
    unsigned int nr_ang;
    char adresa[30];

    if (!f)
        printf("Fisierul nu s-a deschis");
    else {
        fscanf(f, "%s %f %d %s", &nume, &sup, &nr_ang, &adresa);
        while (!feof(f)) {

            inserare_lista(prim, ultim, nume, sup, nr_ang, adresa);

            fscanf(f, "%s %f %d %s", &nume, &sup, &nr_ang, &adresa);
        }

        fclose(f);
    }
}

void inserare_lista(struct farmacie*& prim, struct farmacie*& ultim, char nume[30], float sup, unsigned int nr_ang, char adresa[30]) {
    struct farmacie* nod_nou = creare_nod(nume, sup, nr_ang, adresa);

    if (prim == NULL) {
        prim = nod_nou;
        //printf("0\n");
    }
    else {
        ultim->next = nod_nou;
        nod_nou->prev = ultim;

        //printf("2\n");

    }

    ultim = nod_nou;

    //printf("%s   %s\n", ultim->nume, nod_nou->nume);
}

struct farmacie* creare_nod(char nume[30], float sup, unsigned int nr_ang, char adresa[30]) {
    struct farmacie* nod_nou = (struct farmacie*)malloc(sizeof(farmacie));

    nod_nou->nume = (char*)malloc(strlen(nume) * sizeof(char) + 1);
    strcpy(nod_nou->nume, nume);

    nod_nou->sup = sup;

    nod_nou->nr_ang = nr_ang;

    nod_nou->adresa = (char*)malloc(strlen(adresa) * sizeof(char) + 1);
    strcpy(nod_nou->adresa, adresa);

    nod_nou->next = NULL;
    nod_nou->prev = NULL;

    return nod_nou;
}

void funct1(struct farmacie* prim, struct farmacie* ultim) {
    float sup;
    int nr = 0;
    struct farmacie* curent = prim;

    printf("Suprafata limta: ");
    fflush(stdin);
    scanf("%f", &sup);

    //printf("\n%.2f\n\n", sup);

    while (curent != NULL) {
        //printf("%.2f\n", curent->sup);

        if (curent->sup < sup) {
            nr++;
            //printf("%.2f\n", curent->sup);
        }

        curent = curent->next;
    }

    printf("Numarul de farmacii cu suprafata mai mica decat %.2f sunt: %d", sup, nr);
}

void funct2(struct farmacie*& prim, struct farmacie*& ultim) {
    struct farmacie* curent, *aux = NULL;

    char nume[30];
    //char nume[] = "OmicronSoft";
    int nr = 0;
    printf("Numele cautat: ");
    fflush(stdin);
    scanf("%s", &nume);

    if (prim == ultim && prim == NULL) {
        printf("Lista e goala\n");

        return;
    }

    if (prim == ultim) {
        if (strcmp(prim->nume, nume) == 0) {
            free(prim->adresa);
            free(prim->nume);

            free(prim);

            prim = NULL;
            ultim = NULL;
        }
    }
    else {
        curent = prim;

        while (curent != NULL) {
            if (strcmp(curent->nume, nume) == 0) {
                //printf("%d\n", ++nr);

                //printf("%s\n", curent->nume);
                
                aux = curent->next;

                if(curent->prev != NULL)
                    curent->prev->next = aux;

                if (aux != NULL)
                    aux->prev = curent->prev;

                free(curent->adresa);
                free(curent->nume);

                free(curent);

                curent = aux;
                if (aux && aux->prev == NULL) {
                    prim = aux;
                }
            }
            else
                curent = curent->next;
        }
    }
}

void funct3(struct farmacie* prim, struct farmacie* ultim) {
    struct farmacie* curent = prim, * v;
    int nr = 0, i = 0;

    char nume[30];
    //char nume[] = "OmicronSoft";
    printf("Numele cautat: ");
    fflush(stdin);
    scanf("%s", &nume);

    if (prim == ultim && prim == NULL) {
        printf("Lista e goala\n");

        return;
    }

    while (curent != NULL) {
        if (strcmp(curent->nume, nume) == 0)
            nr++;

        curent = curent->next;
    }

    v = (farmacie*)malloc(nr * sizeof(farmacie));
    curent = prim;

    while (curent != NULL) {
        if (strcmp(curent->nume, nume) == 0) {
            v[i].nume = (char*)malloc(strlen(curent->nume) * sizeof(char) + 1);
            strcpy(v[i].nume, curent->nume);

            v[i].adresa = (char*)malloc(strlen(curent->adresa) * sizeof(char) + 1);
            strcpy(v[i].adresa, curent->adresa);

            v[i].sup = curent->sup;

            v[i].nr_ang = curent->nr_ang;

            i++;
        }

        curent = curent->next;
    }

    for (i = 0; i < nr; i++)
        printf("%s %.2f %d %s\n", v[i].nume, v[i].sup, v[i].nr_ang, v[i].adresa);

    for (i = 0; i < nr; i++) {
        free(v[i].nume);

        free(v[i].adresa);
    }

    free(v);
}

void afisare_lista(struct farmacie* prim, struct farmacie* ultim) {
    struct farmacie* curent = prim;
    int nr = 1;
    
    if (ultim == NULL && prim == NULL) {
        printf("Lista este goala\n");
            
        return;
    }

    while (curent != NULL) {
        afisare_nod(curent);

        curent = curent->next;
    }
}

void afisare_nod(struct farmacie* nod) {
    printf("%s %.2f %d %s\n", nod->nume, nod->sup, nod->nr_ang, nod->adresa);
}