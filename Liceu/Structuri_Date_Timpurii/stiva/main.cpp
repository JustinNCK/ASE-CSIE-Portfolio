#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct Film{
    char *titlu, *gen;
    float rating;
    int nr_minute;
};

struct Nod{
    struct Film info;
    struct Nod *next;
};

struct Film creeare_info(char *titlu, char *gen, float rating, int nr_minute);
struct Nod* creeare_nod(struct Film info);
struct Nod* push(struct Nod *peak, struct Film info);
void afisare_info(struct Film info);
struct Film pop(struct Nod **peak);
struct Nod* afisare_stiva(struct Nod *peak);
struct Nod *golire_stiva(struct Nod *peak);
struct Nod *schimbare_prim_ultim(struct Nod *peak);

int main(){
    ifstream fin("txt.txt");

    int i, n;
    int nr_minute;
    float rating;
    char titlu[100], gen[100];
    struct Film info;
    struct Nod *peak = NULL;

    fin >> n;
    for(i = 0; i < n; i++){
        fin >> titlu >> gen >> rating >> nr_minute;

        info = creeare_info(titlu, gen, rating, nr_minute);

        peak = push(peak, info);
    }

    peak = afisare_stiva(peak);

    peak = schimbare_prim_ultim(peak);

    peak = afisare_stiva(peak);

    peak = golire_stiva(peak);

    peak = afisare_stiva(peak);
}

struct Film creeare_info(char *titlu, char *gen, float rating, int nr_minute){
    struct Film info;

    info.titlu = (char *)malloc(strlen(titlu) + 1);
    strcpy(info.titlu, titlu);

    info.gen = (char *)malloc(strlen(gen) + 1);
    strcpy(info.gen, gen);

    info.rating = rating;

    info.nr_minute = nr_minute;

    return info;
}

struct Nod* creeare_nod(struct Film info){
    struct Nod *nod;

    nod = (struct Nod *)malloc(sizeof(struct Nod));

    nod->info = info;

    nod->next = NULL;

    return nod;
}


struct Nod* push(struct Nod *peak, struct Film info){
    struct Nod *nod_nou = creeare_nod(info);

    if(peak == NULL)
        peak = nod_nou;
    else{
        nod_nou->next = peak;
        peak = nod_nou;
    }

    return peak;
}

void afisare_info(struct Film info){
    cout << info.titlu << endl << info.gen << endl << info.rating << endl << info.nr_minute << endl << endl;
}

struct Nod* afisare_stiva(struct Nod *peak){
    struct Film info;
    struct Nod *peak_aux = NULL;

    if(peak == NULL){
        cout << "stiva este goala";
        return peak;
    }

    while(peak != NULL){
        info = pop(&peak);

        afisare_info(info);

        peak_aux = push(peak_aux, info);
    }

    peak = NULL;

    while(peak_aux != NULL){
        info = pop(&peak_aux);

        peak = push(peak, info);
    }
    return peak;
}

struct Film pop(struct Nod **peak){
    struct Film curent_info = (*peak)->info;
    struct Nod *curent = *peak;

    *peak = (*peak)->next;

    curent->next = NULL;
    free(curent);

    return curent_info;
}

struct Nod *golire_stiva(struct Nod *peak){
    struct Film curent;

    while(peak != NULL){
        curent = pop(&peak);
        free(curent.gen);
        free(curent.titlu);
    }

    return NULL;
}

struct Nod *schimbare_prim_ultim(struct Nod *peak){
    struct Nod *curent = NULL;
    struct Film aux, aux2;

    aux = pop(&peak);
    while(peak->next != NULL)
        curent = push(curent, pop(&peak));

    aux2 = pop(&peak);

    peak = push(peak, aux);

    while(curent != NULL)
        peak = push(peak, pop(&curent));

    peak = push(peak, aux2);

    return peak;
}
