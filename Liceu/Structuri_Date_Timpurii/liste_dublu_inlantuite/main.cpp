#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

ifstream fin ("lista_apeluri.txt");

typedef struct data {
    int zi, luna, an, ora, minut, sec;
}Data;

typedef struct nod {
    char *apelant;
    char *apelat;
    Data moment;
    int durata;
    struct nod *next;
    struct nod *prev;
} Nod;

typedef struct lista {
    Nod *prim;
    Nod *ultim;
} Lista;

Lista initializare() {
    Lista l;

    l.prim = NULL;
    l.ultim = NULL;

    return l;
}

Nod* creare_nod() {
    Nod *nod_nou = (Nod *)malloc(sizeof(Nod));
    char apelant[30], apelat[30];
    //cout << "cine a apelat: ";
    fin >> apelant;
    //cout << endl << "pe cine: ";
    fin >> apelat;
    //cout << endl << "cand a fost efectuat apelul (aaaa-mm-dd hh:mm:ss): ";
    fin >> nod_nou->moment.an;
    fin >> nod_nou->moment.luna;
    fin >> nod_nou->moment.zi;
    fin >> nod_nou->moment.ora;
    fin >> nod_nou->moment.minut;
    fin >> nod_nou->moment.sec;
    //cout <<endl << "cat a durat apelul: ";
    fin >> nod_nou->durata;
    //cout << endl << endl;
    nod_nou->apelant = (char *)malloc(strlen(apelant));
    nod_nou->apelat = (char *)malloc(strlen(apelat));
    strcpy(nod_nou->apelant, apelant);
    strcpy(nod_nou->apelat, apelat);

    nod_nou->next = NULL;
    nod_nou->prev = NULL;

    return nod_nou;
}

Lista inserare_sfarsit(Lista l) {
    Nod* nod_nou;
    nod_nou = creare_nod();
    if(l.prim == NULL){
        l.prim = nod_nou;
        l.ultim = nod_nou;
        return l;
    }
    else{
        l.ultim->next = nod_nou;
        nod_nou->prev = l.ultim;
        l.ultim = nod_nou;
    }

    return l;
}

Lista inserare_inceput(Lista l) {
    Nod* nod_nou;
    nod_nou = creare_nod();
    if(l.prim == NULL){
        l.prim = nod_nou;
        l.ultim = nod_nou;
    }
    else{
        l.prim->prev = nod_nou;
        nod_nou->next = l.prim;
        l.prim = nod_nou;
    }
    return l;
}

void afisare_nod(Nod* nod) {
    cout << nod->apelant << " a apelat pe " << nod->apelat << " la " << nod->moment.an << "-" << nod->moment.luna << "-" << nod->moment.zi << " " << nod->moment.ora << ":" << nod->moment.minut << ":" << nod->moment.sec << " ";
    cout << "cu durata de: " << nod->durata << " minute" << endl;
}

void afisare_lista_inceput(Lista l){
    Nod *curent;

    if(l.prim == NULL){
        cout << "lista este goala" << endl << endl;
        return;
    }

    for(curent = l.prim; curent != NULL; curent = curent->next)
        afisare_nod(curent);
    cout << endl << endl;
}

void afisare_lista_sfarsit(Lista l){
    Nod *curent;

    if(l.prim == NULL){
        cout << "lista este goala" << endl << endl;
      return;
    }

    for(curent = l.ultim; curent != NULL; curent = curent->prev)
        afisare_nod(curent);
    cout << endl << endl;
}

Lista stergere_prim_element(Lista l){
    Nod* curent;
    if(l.prim == NULL){
        cout << "lista este goala" << endl << endl;
        return l;
    }

    if(l.prim->next == NULL){
        free(l.prim->apelant);
        free(l.prim->apelat);
        free(l.prim);
        l.prim = NULL;
        l.ultim = NULL;
        cout << "lista este goala" << endl << endl;
        return l;
    }

    free(l.prim->apelant);
    free(l.prim->apelat);

    l.prim->next->prev = NULL;

    curent = l.prim->next;
    free(l.prim);
    l.prim = curent;

    return l;
}

Lista stergere_ultim_element(Lista l){
    Nod* curent;
    if(l.ultim == NULL){
        cout << "lista este goala" << endl << endl;
        return l;
    }

    if(l.ultim->prev == NULL){
        free(l.ultim->apelant);
        free(l.ultim->apelat);
        free(l.ultim);
        l.ultim = NULL;
        l.prim = NULL;
        cout << "lista este goala" << endl << endl;
        return l;
    }

    free(l.ultim->apelant);
    free(l.ultim->apelat);

    l.ultim->prev->next = NULL;

    curent = l.ultim->prev;
    free(l.ultim);
    l.ultim = curent;

    return l;
}

Lista stergere_i_element(Lista l, int x, int n){
    Nod* curent, *ante, *post;

    if(l.prim == NULL || l.ultim == NULL){
        cout << "lista este goala" << endl << endl;
        return l;
    }

    if(x < 1 || x > n){
        cout << "convorbirea nu exista" << endl << endl;
        return l;
    }

    if(x == 1)
        return stergere_prim_element(l);

    if(x == n)
        return stergere_ultim_element(l);

    curent = l.prim;
    for(int i = 0; i < x - 1; i++)
        curent = curent->next;

    free(curent->apelant);
    free(curent->apelat);

    post = curent->next;
    ante = curent->prev;

    curent->prev->next = post;
    curent->next->prev = ante;

    free(curent);

    return l;
}

Lista adugare_i_element(Lista l, int x, int* n){
    Nod* curent, *nod_nou;
    int m = *n;

    if(l.prim == NULL || l.ultim == NULL){
        cout << "lista este goala" << endl << endl;
        return l;
    }

    if(x < 1 || x > m + 1){
        cout << "nu se poate aduga pe pozitia " << x << " deoarece nu se afla in lista"<< endl << endl;
        return l;
    }

    if(x == 1)
        return inserare_inceput(l);

    if(x == m + 1){
        n = n + 1;
        return inserare_sfarsit(l);
    }

    curent = l.prim;
    for(int i = 0; i < x - 2; i++)
        curent = curent->next;
    nod_nou = creare_nod();

    nod_nou->prev = curent;
    nod_nou->next = curent->next;
    curent->next->prev = nod_nou;
    curent->next = nod_nou;

    return l;
}

Lista stergere_lista(Lista l){
    Nod* urm;

    if(l.prim == NULL || l.ultim == NULL){
        cout << "lista este goala" << endl << endl;
        return l;
    }

    while(l.prim != NULL){
        urm = l.prim->next;

        free(l.prim->apelant);
        free(l.prim->apelat);
        l.prim->next = NULL;
        l.prim->prev = NULL;
        free(l.prim);

        l.prim = urm;
    }
    l.ultim = NULL;

    return l;
}

Lista inter_prim_ultim(Lista l){
    Nod* aux;

    l.prim->next->prev = l.ultim;
    l.ultim->prev->next = l.prim;

    l.prim->prev = l.ultim->prev;
    l.ultim->next = l.prim->next;

    l.ultim->prev = NULL;
    l.prim->next = NULL;

    aux = l.prim;
    l.prim = l.ultim;
    l.ultim = aux;

    return l;
}

Lista inter_i_i1(Lista l, int x, int n){
    Nod* curent, *aux, *n1, *n2, *n3, *n4;

    if(x <= 0 || x >= n){
        cout << "nu exista pozitia";
        return l;
    }

    if(x == 1){
        l.prim->next->next->prev = l.prim;

        aux = l.prim->next;

        l.prim->prev = aux;
        l.prim->next = aux->next;

        aux->next = l.prim;
        aux->prev = NULL;

        l.prim = aux;

        return l;
    }

    if(x == n - 1){
        l.ultim->prev->prev->next = l.ultim;

        aux = l.ultim->prev;

        l.ultim->next = aux;
        l.ultim->prev = aux->prev;

        aux->prev = l.ultim;
        aux->next = NULL;

        l.ultim = aux;

        return l;
    }

    curent = l.prim;
    for(int i = 0; i < x - 2; i++){
        curent = curent->next;
    }

    n1 = curent->next->next->next;
    n2 = curent->next;
    n3 = curent->next->next;
    n4 = curent;


    curent->next = n3;
    curent->next->next->prev = n2;
    n3->next = n2;
    n3->prev = n4;
    n2->next = n1;
    n2->prev = n3;


    return l;
}


Lista stergere_lista(Lista l);
Nod* creare_nod();
void afisare_nod(Nod* nod);
void afisare_lista_inceput(Lista l);
void afisare_lista_sfarsit(Lista l);
Lista stergere_prim_element(Lista l);
Lista stergere_ultim_element(Lista l);
Lista stergere_i_element(Lista l, int x, int* n);
Lista adugare_i_element(Lista l, int x, int* n);
Lista stergere_prim_element(Lista l);
Lista stergere_ultim_element(Lista l);

int main()
{
    Lista l;
    int x, n;

    l = initializare();

    fin >> n;
    for(int i = 0; i < n; i++)
        l = inserare_sfarsit(l);

    //afisare_lista_inceput(l);
    //afisare_lista_sfarsit(l);

    /*l = stergere_prim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);
    l = stergere_prim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);
    l = stergere_prim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);
    l = stergere_prim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);*/

    /*l = stergere_ultim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);
    l = stergere_ultim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);
    l = stergere_ultim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);
    l = stergere_ultim_element(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);*/

    /*cout << "ce convorbire sa fie stersa: ";
    cin >> x;
    l = stergere_i_element(l, x, n);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);*/

    /*cout << "unde sa fie adaugata o convorbire: ";
    cin >> x;
    l = adugare_i_element(l, x, &n);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);*/

    /*l = stergere_lista(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);*/

    /*l = inter_prim_ultim(l);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);*/

    cout << "ce poziti sa fie interschimbate: ";
    cin >> x;
    l = inter_i_i1(l, x, n);
    afisare_lista_inceput(l);
    afisare_lista_sfarsit(l);

    return 0;
}

///Tema: termina adugare un element pe o poziteie specificata
///+stergerea listei
