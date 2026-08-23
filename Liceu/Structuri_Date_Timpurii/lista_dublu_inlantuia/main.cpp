#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct date{
    int data;
    struct date *next, *prev;
};

struct date* creare_nod(int data);
struct date* inserare_inceput(int data, struct date *prim);
void afisare_lista(struct date *prim, FILE *f);
void afisare_nod(struct date *curent, FILE *f);
struct date* stergere_lista(struct date *prim);

int main(){
    struct date *prim = NULL, *curent, *aux;
    FILE *f;
    int n, i, data, nr;

    f = fopen("txt.txt", "a+");

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &data);
        prim = inserare_inceput(data, prim);
    }

    scanf("%d", &nr);

    afisare_lista(prim, f);

    curent = prim;
    while(curent->next != NULL)
        curent = curent->next;
    aux = creare_nod(nr);
    curent->next = aux;
    aux->prev = curent;

    afisare_lista(prim, f);

    prim = stergere_lista(prim);

    afisare_lista(prim, f);
}

struct date* creare_nod(int data){
    struct date *nod_nou;

    nod_nou = (struct date *)malloc(sizeof(struct date));

    nod_nou->data = data;
    nod_nou->next = NULL;
    nod_nou->prev = NULL;

    return nod_nou;
}

struct date* inserare_inceput(int data, struct date *prim){
    struct date *nod_nou = creare_nod(data);

    if(prim != NULL){
        prim->prev = nod_nou;
        nod_nou->next = prim;
    }

    prim = nod_nou;

    return prim;
}

void afisare_lista(struct date *prim, FILE *f){
    if(prim == NULL){
        fprintf(f, "Lista este goala \n");
        return;
    }

    while(prim != NULL){
        afisare_nod(prim, f);
        prim = prim->next;
    }

    fprintf(f, "\n");
}

void afisare_nod(struct date *curent, FILE *f){
    fprintf(f, "%d ", curent->data);
}

struct date* stergere_lista(struct date *prim){
    struct date *curent;

    while(prim != NULL){
        curent = prim;
        prim = prim->next;

        curent->data = 0;
        curent->next = NULL;
        curent->prev = NULL;

        free(curent);
    }

    return NULL;
}
