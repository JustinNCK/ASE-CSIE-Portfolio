#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

#define CRT_NO_SECURE_WARNINGS

using namespace std;

/*
struct produs{
    char *denumire;
    int pret;
    struct produs* next;
};

struct produs* creare_nod(char denumire[30], int pret){
    struct produs *nod_nou = (struct produs *)malloc(sizeof(struct produs));
    nod_nou->denumire = (char *)malloc(strlen(denumire) + 1);
    strcpy(nod_nou->denumire, denumire);
    nod_nou->pret = pret;
    nod_nou->next = NULL;

    return nod_nou;
}

struct produs* inserare_sfarsit(struct produs* prim, char denumire[30], int pret){
    struct produs* nod_nou = creare_nod(denumire, pret), *curent;

    if(prim == NULL) {
        nod_nou->next = nod_nou;
        return nod_nou;
    } else{
        curent = prim;

       do{
            curent = curent->next;
        }while(curent->next != prim);

        curent->next = nod_nou;

        nod_nou->next = prim;
    }

    return prim;
}

void afisare_nod(struct produs* nod){
    cout << nod->denumire << " " << nod->pret << endl;
}

void afisare_lista(struct produs* prim){
    struct produs* curent = prim;

    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return;
    }
    cout << endl;
    do{
        afisare_nod(curent);
        curent = curent->next;
    }while(curent != prim);
}

struct produs* stergere_lista(struct produs* prim){
    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    struct produs* curent;

    while(prim != NULL){
        curent = prim->next;
        free(prim->denumire);
        prim->next = NULL;
        free(prim);
        prim = curent;
    }

    return NULL;
}

int main()
{
    struct produs* prim = NULL;
    int i, n, pret;
    char denumire[30];

    scanf("%d", &n);
    for(i = 0 ; i < n; i++){
        cin >> denumire >> pret;
        prim = inserare_sfarsit(prim, denumire, pret);
    }


    afisare_lista(prim);
}
*/

/**
7
banane 6
mere 4
castraveti 5
gogosari 10
ardei 15
lamie 12
varza 20
*/


struct client{
    char *nume;
    int produse;
    struct client* next;
};

struct client* creare_nod(char nume[16], int produse){
    struct client *nod_nou = (struct client *)malloc(sizeof(struct client));
    nod_nou->nume = (char *)malloc(strlen(nume) + 1);
    strcpy(nod_nou->nume, nume);
    nod_nou->produse = produse;
    nod_nou->next = NULL;

    return nod_nou;
}

struct client* inserare_sfarsit(struct client* prim, char nume[16], int produse){
    struct client* nod_nou = creare_nod(nume, produse), *curent;

    if(prim == NULL) {
        nod_nou->next = nod_nou;
        return nod_nou;
    } else{
        curent = prim;

       do{
            curent = curent->next;
        }while(curent->next != prim);

        curent->next = nod_nou;

        nod_nou->next = prim;
    }

    return prim;
}

void afisare_nod(struct client* nod){
    cout << nod->nume << " " << nod->produse << endl;
}

void afisare_lista(struct client* prim){
    struct client* curent = prim;

    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return;
    }
    cout << endl;
    do{
        afisare_nod(curent);
        curent = curent->next;
    }while(curent != prim);
}

struct client* stergere_lista(struct client* prim){
    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    struct client* curent;

    while(prim != NULL){
        curent = prim->next;
        free(prim->nume);
        prim->next = NULL;
        free(prim);
        prim = curent;
    }

    return NULL;
}

void push(struct client *&prim, struct client *ultim, char nume[16], int produse){
    struct client *nod_nou = creare_nod(nume, produse);

    if(prim == NULL)
        prim = nod_nou;
    else
        ultim->next = nod_nou;

    ultim = nod_nou;
}

void pop(struct client *&prim, struct client *ultim, char nume[16], int &produse){
    struct client *curent;

    strcpy(nume, prim->nume);
    produse = prim->produse;

    curent = prim;
    prim = prim->next;

    free(curent->nume);
    curent->next = NULL;
    free(curent);
}

int main()
{
    struct client* prim = NULL, *ultim = NULL, *dump = NULL, *c1 = NUL, *c2 = NULL;
    int i, n, produse;
    char nume[16];

    cin >> n
    for(i = 0 ; i < n; i++){
        cin >> nume >> produse;
        prim = inserare_sfarsit(prim, nume, produse);
    }

    ultim = prim->next;
    prim->next = NULL;





    afisare_lista(prim);
}

