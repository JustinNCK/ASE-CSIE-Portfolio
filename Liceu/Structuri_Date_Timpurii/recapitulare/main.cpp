az#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;
/*
int main(){
    int *v, m, s, *x;
    cin >> m;
    v = (int *)malloc(m * sizeof(int));

    for(int i = 0; i < m; i++)
        cin >> *(v + i);

    s = 1;
    while(s == 1){
        s = 0;
        for(int i = 0; i < m - 1; i++)
            if(*(v + i) > *(v + i + 1)){
                *(v + i) = *(v + i) + *(v + i + 1);
                *(v + i + 1) = *(v + i) - *(v + i + 1);
                *(v + i) = *(v + i) - *(v + i + 1);
                s = 1;
            }
    }


    for(int i = 0; i < m - 1; i++)
        if(*(v + i) == *(v + i + 1)){
            for(int j = i; j < m - 1; j++)
                *(v + j) = *(v + j + 1);
            i--;
            m--;
        }

    for(int i = 0; i < m; i++)
        cout << *(v + i) << " ";



    s = 0;
    for(int i = 0; i < m - 1; i++)
        if(*(v + i) == *(v + i + 1))
            s++;

    x = (int *)malloc((m - s) * sizeof(int));

    *(x) = *(v);
    s = 0;
    for(int i = 1; i < m; i++)
        if(*(x + s) != *(v + i)){
            s++;
            *(x + s) = *(v + i);
        }

    for(int i = 0; i < s + 1; i++)
        cout << *(x + i) << " ";

    free(v);
    free(x);
}*/



/*
struct Farmacie{
    char *denumire, *adresa;
    int nr_angajati;
    float suprafata;
};

void spatiu_mic(Farmacie *v, int m);
void angajati_max(Farmacie *v, int &m);
void farm(Farmacie *v, int m);

int main(){
    ifstream fin("txt1.txt");
    Farmacie *v;
    int m;
    char aux[21];
    fin >> m;
    v = (Farmacie *)malloc(m * sizeof(Farmacie));

    for(int i = 0; i < m; i++){
        fin >> aux;
        (*(v + i)).denumire = (char *)malloc(strlen(aux) + 1);
        strcpy((*(v + i)).denumire, aux);

        fin >> aux;
        (*(v + i)).adresa = (char *)malloc(strlen(aux) + 1);
        strcpy((*(v + i)).adresa, aux);

        fin >> (*(v + i)).nr_angajati;

        fin >> (*(v + i)).suprafata;
    }

    spatiu_mic(v, m);
    angajati_max(v, m);
    farm(v, m);
    for(int i = 0; i < m; i++)
        cout << (*(v + i)).denumire << endl << (*(v + i)).adresa << endl << (*(v + i)).nr_angajati << endl << (*(v + i)).suprafata << endl << endl;

}


void spatiu_mic(Farmacie *v, int m){
    int max_s;
    int nr = 0;
    cin >> max_s;

    for(int i = 0; i < m; i++)
        if((*(v + i)).suprafata < max_s)
            nr++;

    cout << nr << endl << endl;
}

void angajati_max(Farmacie *v, int &m){
    int max_a, s = 1;
    char *aux;
    cin >> max_a;

    aux = (char *)malloc(20);

    while(s == 1){
        s = 0;
        for(int i = 0; i < m - 1; i++)
            if((*(v + i)).nr_angajati < (*(v + i + 1)).nr_angajati){
                strcpy(aux, (*(v + i)).denumire);
                strcpy((*(v + i)).denumire, (*(v + i + 1)).denumire);
                strcpy((*(v + i + 1)).denumire, aux);

                strcpy(aux, (*(v + i)).adresa);
                strcpy((*(v + i)).adresa, (*(v + i + 1)).adresa);
                strcpy((*(v + i + 1)).adresa, aux);

                (*(v + i)).nr_angajati = (*(v + i)).nr_angajati + (*(v + i + 1)).nr_angajati;
                (*(v + i + 1)).nr_angajati = (*(v + i)).nr_angajati - (*(v + i + 1)).nr_angajati;
                (*(v + i)).nr_angajati = (*(v + i)).nr_angajati - (*(v + i + 1)).nr_angajati;

                (*(v + i)).suprafata = (*(v + i)).suprafata + (*(v + i + 1)).suprafata;
                (*(v + i + 1)).suprafata = (*(v + i)).suprafata - (*(v + i + 1)).suprafata;
                (*(v + i)).suprafata = (*(v + i)).suprafata - (*(v + i + 1)).suprafata;

                s = 1;
            }
    }

    for(int i = 0; i < m; i++)
        if((*(v + i)).nr_angajati < max_a)
            m = i;

    free(aux);
}

void farm(Farmacie *v, int m){
    Farmacie *far;
    int nr, j;
    char x[20];
    cin >> x;

    for(int i = 0; i < m; i++)
        if(strcmp(x, (*(v + i)).denumire) == 0)
            nr++;

    far = (Farmacie *)malloc(nr * sizeof(Farmacie));

    j = 0;
    for(int i = 0; i < m; i++)
        if(strcmp(x, (*(v + i)).denumire) == 0){
            (*(far + j)).denumire = (char *)malloc(strlen((*(v + i)).denumire) + 1);

            (*(far + j)).adresa = (char *)malloc(strlen((*(v + i)).adresa) + 1);

            strcpy((*(far + j)).denumire, (*(v + i)).denumire);

            strcpy((*(far + j)).adresa, (*(v + i)).adresa);

            (*(far + j)).nr_angajati = (*(v + j)).nr_angajati;

            (*(far + j)).suprafata = (*(v + j)).suprafata;

            j++;
        }

    for(int i = 0; i < j; i++)
        cout << (*(far + i)).denumire << endl << (*(far + i)).adresa << endl << (*(far + i)).nr_angajati << endl << (*(far + i)).suprafata << endl << endl;

    for(int i = 0; i < j; i++){
        free((*(far + i)).denumire);
        free((*(far + i)).adresa);
    }

    free(far);
}
*/

/*
struct Film{
    char *titlu, *gen;
    float rainting;
    int numar_minute;
};

void nr_minute(int m, Film *f, int nr);
void stergere(int &m, Film *f, int x, int y);
void medie(int m, Film *f);

int main(){
    ifstream fin("txt2.txt");
    int m, x, y, nr;
    char aux[21];
    Film *f;
    fin >> m;

    f = (Film *)malloc(m * sizeof(Film));

    for(int i = 0; i < m; i++){
        fin >> aux;
        (*(f + i)).titlu = (char *)malloc(strlen(aux) + 1);
        strcpy((*(f + i)).titlu, aux);

        fin >> aux;
        (*(f + i)).gen = (char *)malloc(strlen(aux) + 1);
        strcpy((*(f + i)).gen, aux);

        fin >> (*(f + i)).rainting;

        fin >> (*(f + i)).numar_minute;
    }

    //cin >> nr;
    //nr_minute(m, f, nr);

    //cin >> x >> y;
    //stergere(m, f, x, y);

    medie(m, f);

    //for(int i = 0; i < m; i++)
        //cout << (*(f + i)).titlu << endl << (*(f + i)).gen << endl << (*(f + i)).rainting << endl << (*(f + i)).numar_minute << endl << endl;


    for(int i = 0; i < m; i++){
        free((*(f + i)).titlu);
        free((*(f + i)).gen);
     }

    free(f);
}



void nr_minute(int m, Film *f, int nr){
    int c = 0;
    for(int i = 0; i < m; i++)
        if(nr <= (*(f + i)).numar_minute)
            c++;

    cout << c << endl;
}


void stergere(int &m, Film *f, int x, int y){
     int n, j = 0;
     Film *v;
     n = m - x - y;

     v = (Film *)malloc(n * sizeof(Film));

     for(int i = x; i < m - y; i++){
        (*(v + j)).titlu = (char *)malloc(strlen((*(f + i)).titlu) + 1);
        strcpy((*(v + j)).titlu, (*(f + i)).titlu);

        (*(v + j)).gen = (char *)malloc(strlen((*(f + i)).gen) + 1);
        strcpy((*(v + j)).gen, (*(f + i)).gen);

        (*(v + j)).rainting = (*(f + i)).rainting;

        (*(v + j)).numar_minute = (*(f + i)).numar_minute;

        j++;
     }

     for(int i = 0; i < n; i++){
        (*(f + i)).titlu = (char *)realloc((*(f + i)).titlu ,strlen((*(v + i)).titlu) + 1);
        strcpy((*(f + i)).titlu, (*(v + i)).titlu);

        (*(f + i)).gen = (char *)realloc((*(f + i)).gen ,strlen((*(v + i)).gen) + 1);
        strcpy((*(f + i)).gen, (*(v + i)).gen);

        (*(f + i)).rainting = (*(v + i)).rainting;

        (*(f + i)).numar_minute = (*(v + i)).numar_minute;
     }

     m = n;

     for(int i = 0; i < n; i++){
        free((*(v + i)).titlu);
        free((*(v + i)).gen);
     }

    free(v);
}

void medie(int m, Film *f){
    int j;
    float med;
    Film *v;

    for(int i = 0; i < m; i++){
        med += (*(f + i)).rainting / m;
    }

    j = 0;
    for(int i = 0; i < m; i++)
        if(med <= (*(f + i)).rainting)
            j++;

     v = (Film *)malloc(j * sizeof(Film));

     j = 0;
     for(int i = 0; i < m; i++)
        if(med <= (*(f + i)).rainting){
        (*(v + j)).titlu = (char *)malloc(strlen((*(f + i)).titlu) + 1);
        strcpy((*(v + j)).titlu, (*(f + i)).titlu);

        (*(v + j)).gen = (char *)malloc(strlen((*(f + i)).gen) + 1);
        strcpy((*(v + j)).gen, (*(f + i)).gen);

        (*(v + j)).rainting = (*(f + i)).rainting;

        (*(v + j)).numar_minute = (*(f + i)).numar_minute;

        j++;
     }

    for(int i = 0; i < j; i++)
        if((*(v + i)).rainting >= med)
           cout << (*(v + i)).titlu << endl << (*(v + i)).gen << endl << (*(v + i)).rainting << endl << (*(v + i)).numar_minute << endl << endl;

     for(int i = 0; i < j; i++){
        free((*(v + i)).titlu);
        free((*(v + i)).gen);
     }

    free(v);
}
*/

/*
struct Film{
    char *titlu, *gen;
    float rating;
    int nr_minute;
};

struct Nod{
    struct Film info;
    struct Nod *next;
};

void inserare_nod(struct Nod* prim, int nr);
struct Nod* inserare_inceput(struct Nod* prim, struct Film info);
struct Nod* inserare_sfarsit(struct Nod* prim, struct Film info);
struct Film creare_info(char *titlu, char *gen, float rating, int nr_minute);
struct Nod* creare_nod(struct Film info);
struct Nod* stergere_primul_element(struct Nod *prim);
struct Nod* stergere_ultimul_element(struct Nod *prim);
struct Nod* stergere_lista(struct Nod* prim);
struct Nod* stergere_elem_poz(struct Nod* prim);
void afisare_nod(struct Nod *nod);

int main(){
    ifstream fin("txt2.txt");
    struct Nod *prim = NULL, *curent;
    struct Film info;
    int n, i, nr;
    char aux[21];

    fin >> n;
    for(i = 0; i < n; i++){
        fin >> aux;
        info.titlu = (char *)malloc(strlen(aux) + 1);
        strcpy(info.titlu, aux);

        fin >> aux;
        info.gen = (char *)malloc(strlen(aux) + 1);
        strcpy(info.gen, aux);

        fin >> info.rating >> info.nr_minute;

        prim = inserare_inceput(prim, info);
    }

    curent = prim;
    /*for(i = 0; i < n; i++){
        afisare_nod(curent);
        curent = curent->next;
    }*/

    //cout << "Pe ce loc sa fie introdus filmul: ";
    //cin >> nr;

    //inserare_nod(prim, nr);

    //prim = stergere_primul_element(prim);
    //prim = stergere_ultimul_element(prim);
    //stergere_lista(prim);
    /*while(curent != NULL){
        afisare_nod(curent);
        curent = curent->next;
    }

    stergere_elem_poz(prim);
    curent = prim;

    while(curent != NULL){
        afisare_nod(curent);
        curent = curent->next;
    }
}

struct Film creare_info(char *titlu, char *gen, float rating, int nr_minute){
    struct Film info;

    info.titlu = (char *)malloc(strlen(titlu) + 1);
    strcpy(info.titlu, titlu);

    info.gen = (char *)malloc(strlen(gen) + 1);
    strcpy(info.gen, gen);

    info.nr_minute = nr_minute;

    info.rating = rating;

    return info;
}

struct Nod* creare_nod(struct Film info){
    struct Nod *nod_nou;

    nod_nou = (Nod *)malloc(sizeof(Nod));

    nod_nou->info = info;

    nod_nou->next = NULL;

    return nod_nou;
}

struct Nod* inserare_sfarsit(struct Nod* prim, struct Film info){
    struct Nod* nod_nou = creare_nod(info);

    if(prim == NULL) {
        prim = nod_nou;
    } else {
        struct Nod* curent = prim;

        while(curent->next != NULL) {
            curent = curent->next;
        }
        curent->next = nod_nou;
    }
    return prim;
}

struct Nod* inserare_inceput(struct Nod* prim, struct Film info){
    struct Nod* nod_nou = creare_nod(info);

    if(prim == NULL)
        prim = nod_nou;
    else{
        nod_nou->next = prim;
        prim = nod_nou;
    }

    return prim;
}

void afisare_nod(struct Nod *nod){
    cout << nod->info.titlu << " " << nod->info.gen << " " << nod->info.rating << " " << nod->info.nr_minute << endl;
}

void inserare_nod(struct Nod* prim, int nr){
    struct Nod* nod_nou, *curent;
    char aux[21];
    int i;

    nod_nou = (Nod *)malloc(sizeof(Nod));

    curent = prim;
    for(i = 1; i < nr - 1; i++)
        curent = curent->next;

    cout << "Titlul filmului: ";
    cin >> aux;
    nod_nou->info.titlu = (char *)malloc(strlen(aux) + 1);
    strcpy(nod_nou->info.titlu, aux);

    cout << "Genul filmului: ";
    cin >> aux;
    nod_nou->info.gen = (char *)malloc(strlen(aux) + 1);
    strcpy(nod_nou->info.gen, aux);

    cout << "Rating-ul filmului: ";
    cin >> nod_nou->info.rating;

    cout << "Numarul de minute ale filmului: ";
    cin >> nod_nou->info.nr_minute;


    nod_nou->next = curent->next;
    curent->next = nod_nou;
}

struct Nod *stergere_primul_element(struct Nod *prim){
    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    struct Nod* curent;

    curent = prim->next;
    free(prim->info.gen);
    free(prim->info.titlu);
    prim->next = NULL;
    free(prim);

    return curent;
}

struct Nod *stergere_ultimul_element(struct Nod *prim){
    struct Nod* curent;

    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    if(prim->next == NULL){
        free(prim->info.gen);
        free(prim->info.titlu);
        prim->next = NULL;
        free(prim);
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    curent = prim;
    while(curent->next->next != NULL)
        curent = curent->next;

    free(curent->next->info.gen);
    free(curent->next->info.titlu);
    free(curent->next);

    curent->next = NULL;
    return prim;
}

struct Nod* stergere_lista(struct Nod* prim){
    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    struct Nod* curent;

    while(prim != NULL){
        curent = prim->next;
        free(prim->info.gen);
        free(prim->info.titlu);
        prim->next = NULL;
        free(prim);
        prim = curent;
    }

    return NULL;
}


struct Nod* stergere_elem_poz(struct Nod* prim){
    struct Nod *curent, *aux;
    int poz;

    curent = prim;

    cout << "Ce pozitie sa fie stearsa: ";
    cin >> poz;
    poz -= 1;
    while(poz != 1){
        poz -= 1;
        curent = curent->next;
    }

    aux = curent->next->next;
    free(curent->next);
    curent->next = aux;
}*/
///TEMA
/*
stergerea primului element
stergerea ultimului element
stergerea de pe o pozitie specificata a unul element
stergerea intregii liste
*/


///Tema
//creare lista dubla
//cat pot din operatile facute la liste simple

struct Film{
    char *titlu, *gen;
    float rating;
    int nr_minute;
};

struct Nod{
    struct Film info;
    struct Nod *next, *prev;
};

void inserare_nod(struct Nod* prim);
struct Nod* inserare_inceput(struct Nod* prim, struct Film info);
struct Nod* inserare_sfarsit(struct Nod* prim, struct Film info);
struct Film creare_info(char *titlu, char *gen, float rating, int nr_minute);
struct Nod* creare_nod(struct Film info);
struct Nod* stergere_primul_element(struct Nod *prim);
struct Nod* stergere_ultimul_element(struct Nod *prim);
struct Nod* stergere_lista(struct Nod* prim);
struct Nod* stergere_elem_poz(struct Nod* prim);
struct Nod* schimb_prim_cu_ultim(struct Nod* prim);
struct Nod* schimb_doua_poz_alaturate(struct Nod* prim);
void afisare_nod(struct Nod *nod);

int main(){
    ifstream fin("txt2.txt");
    struct Nod *prim = NULL, *curent;
    struct Film info;
    int n, i;
    char aux[21];

    fin >> n;
    for(i = 0; i < n; i++){
        fin >> aux;
        info.titlu = (char *)malloc(strlen(aux) + 1);
        strcpy(info.titlu, aux);

        fin >> aux;
        info.gen = (char *)malloc(strlen(aux) + 1);
        strcpy(info.gen, aux);

        fin >> info.rating >> info.nr_minute;

        prim = inserare_sfarsit(prim, info);
    }

    //inserare_nod(prim);
    //prim = stergere_primul_element(prim);
    //prim = stergere_ultimul_element(prim);
    //prim = stergere_lista(prim);
    //stergere_elem_poz(prim);
    //prim = schimb_prim_cu_ultim(prim);
    prim = schimb_doua_poz_alaturate(prim);

    curent = prim;
    if(prim == NULL)
        cout << "Lista e goala";
    else{
        while(curent != NULL){
            afisare_nod(curent);
            curent = curent->next;
        }
        curent = prim;
        while(curent->next != NULL)
            curent = curent->next;
        cout << endl << endl;
        while(curent != NULL){
            afisare_nod(curent);
            curent = curent->prev;
        }
    }
}

struct Film creare_info(char *titlu, char *gen, float rating, int nr_minute){
    struct Film info;

    info.titlu = (char *)malloc(strlen(titlu) + 1);
    strcpy(info.titlu, titlu);

    info.gen = (char *)malloc(strlen(gen) + 1);
    strcpy(info.gen, gen);

    info.nr_minute = nr_minute;

    info.rating = rating;

    return info;
}

struct Nod* creare_nod(struct Film info){
    struct Nod *nod_nou;

    nod_nou = (Nod *)malloc(sizeof(Nod));

    nod_nou->info = info;

    nod_nou->next = NULL;

    nod_nou->prev = NULL;

    return nod_nou;
}

struct Nod* inserare_sfarsit(struct Nod* prim, struct Film info){
    struct Nod* nod_nou = creare_nod(info);

    if(prim == NULL) {
        prim = nod_nou;
    } else {
        struct Nod* curent = prim;

        while(curent->next != NULL) {
            curent = curent->next;
        }
        curent->next = nod_nou;
        nod_nou->prev = curent;
    }
    return prim;
}

struct Nod* inserare_inceput(struct Nod* prim, struct Film info){
    struct Nod* nod_nou = creare_nod(info), *aux;

    if(prim == NULL)
        prim = nod_nou;
    else{
        /*nod_nou->next = prim;
        aux = prim;
        prim = nod_nou;
        aux->prev = prim;*/
        nod_nou->next = prim;
        prim->prev = nod_nou;
        prim = nod_nou;
    }

    return prim;
}

void afisare_nod(struct Nod *nod){
    cout << nod->info.titlu << " " << nod->info.gen << " " << nod->info.rating << " " << nod->info.nr_minute << endl;
}

void inserare_nod(struct Nod* prim){
    struct Nod* nod_nou, *curent, *nod;
    char aux[21];
    int i, poz;

    cout << "Pe ce loc sa fie introdus filmul: ";
    cin >> poz;
    poz -= 1;
    curent = prim;
    while(poz != 1){
        poz -= 1;
        curent = curent->next;
    }

    nod_nou = (Nod *)malloc(sizeof(Nod));

    cout << "Titlul filmului: ";
    cin >> aux;
    nod_nou->info.titlu = (char *)malloc(strlen(aux) + 1);
    strcpy(nod_nou->info.titlu, aux);

    cout << "Genul filmului: ";
    cin >> aux;
    nod_nou->info.gen = (char *)malloc(strlen(aux) + 1);
    strcpy(nod_nou->info.gen, aux);

    cout << "Rating-ul filmului: ";
    cin >> nod_nou->info.rating;

    cout << "Numarul de minute ale filmului: ";
    cin >> nod_nou->info.nr_minute;


    nod = curent->next;
    curent->next = nod_nou;
    nod_nou->prev = curent;
    nod_nou->next = nod;
    nod->prev = nod_nou;
}

struct Nod *stergere_primul_element(struct Nod *prim){
    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    struct Nod* curent;

    curent = prim->next;
    free(prim->info.gen);
    free(prim->info.titlu);
    prim->next->prev = NULL;
    prim->next = NULL;
    free(prim);

    return curent;
}

struct Nod *stergere_ultimul_element(struct Nod *prim){
    struct Nod* curent;

    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    if(prim->next == NULL){
        free(prim->info.gen);
        free(prim->info.titlu);
        prim->next = NULL;
        prim->prev = NULL;
        free(prim);
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    curent = prim;
    while(curent->next->next != NULL)
        curent = curent->next;

    free(curent->next->info.gen);
    free(curent->next->info.titlu);
    free(curent->next);

    curent->next->prev = NULL;
    curent->next = NULL;
    return prim;
}

struct Nod* stergere_lista(struct Nod* prim){
    if(prim == NULL){
        cout << endl << "lista este goala" << endl;
        return NULL;
    }

    struct Nod* curent;

    while(prim != NULL){
        curent = prim->next;
        free(prim->info.gen);
        free(prim->info.titlu);
        prim->prev = NULL;
        prim->next = NULL;
        free(prim);
        prim = curent;
    }

    return prim;
}


struct Nod* stergere_elem_poz(struct Nod* prim){
    struct Nod *curent, *aux;
    int poz;

    curent = prim;

    cout << "Ce pozitie sa fie stearsa: ";
    cin >> poz;
    poz -= 1;
    while(poz != 1){
        poz -= 1;
        curent = curent->next;
    }

    aux = curent->next->next;
    free(curent->next);
    curent->next = aux;
    aux->prev = curent;
}


struct Nod* schimb_prim_cu_ultim(struct Nod* prim){
    struct Nod *curent = prim;

    while(curent->next != NULL)
        curent = curent->next;

    curent->prev->next = prim;
    prim->next->prev = curent;
    curent->next = prim->next;
    prim->prev = curent->prev;
    curent->prev = NULL;
    prim->next = NULL;


    return curent;

}


struct Nod* schimb_doua_poz_alaturate(struct Nod* prim){
    struct Nod *curent = prim, *aux;
    int poz;

    cout << "Ce pozitie sa fie schimbata: ";
    cin >> poz;
    while(poz != 1){
        poz -= 1;
        curent = curent->next;
    }

    curent->next->next->prev = curent;
    curent->prev->next = curent->next;

    aux = curent->prev;
    curent->prev = curent->next;
    curent->next->prev = aux;

    aux = curent->next->next;
    curent->next->next = curent;
    curent->next = aux;

    return prim;
}
