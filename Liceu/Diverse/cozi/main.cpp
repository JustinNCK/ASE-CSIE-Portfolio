#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

struct Film{
    char *titlu, *gen;
    float rating;
    int nr_minute;
};

struct Nod{
    struct Film info;
    struct Nod *next;
};
struct Film creare_info(char *titlu, char *gen, float rating, int nr_minute);
struct Nod *creare_nod(struct Film info);
struct Nod *push(struct Nod *&prim, struct Nod *&ultim, struct Nod *nod);
struct Film pop(struct Nod *&prim, struct Nod *&ultim);
void afisare_info(struct Film info);
void afisare_coada(struct Nod *prim, struct Nod *ultim);

int main(){
    FILE *f = fopen("txt.txt", "r");
    struct Nod *prim = NULL, *ultim = NULL;
    char titlu[21], gen[21];
    float rating;
    int nr_minute, n, i;

    fscanf(f, "%d", &n);
    for(i = 0; i < n; i++){
        fscanf(f, "%s", titlu);
        fscanf(f, "%s", gen);
        fscanf(f, "%f", &rating);
        fscanf(f, "%d", &nr_minute);

        push(prim, ultim, creare_nod(creare_info(titlu, gen, rating, nr_minute)));
    }

    afisare_coada(prim, ultim);
}

struct Film creare_info(char *titlu, char *gen, float rating, int nr_minute){
    struct Film info;

    info.titlu = (char *)malloc(strlen(titlu) + 1);
    strcpy(info.titlu, titlu);

    info.gen = (char *)malloc(strlen(gen) + 1);
    strcpy(info.gen, gen);

    info.rating = rating;

    info.nr_minute = nr_minute;

    return info;
}

struct Nod *creare_nod(struct Film info){
    struct Nod *nod = (struct Nod *)malloc(sizeof(struct Nod));

    nod->info = info;

    nod->next = NULL;

    return nod;
}

struct Nod *push(struct Nod *&prim, struct Nod *&ultim, struct Nod *nod){
    if(prim == NULL){
        prim = nod;
        ultim = nod;
    }
    else{
        ultim->next = nod;
        ultim = nod;
    }
    return prim;
}

struct Film pop(struct Nod *&prim, struct Nod *&ultim){
    struct Film info;
    if(prim != NULL){
        info = prim->info;

        if(prim->next != NULL){
            prim = prim->next;
        }
        else{
            prim = NULL;
            ultim = NULL;
        }

    }

    return info;
}

void afisare_info(struct Film info){
    printf("Titlu: %s\nGen: %s\nRating: %f\nDurata: %d minute\n\n", info.titlu, info.gen, info.rating, info.nr_minute);
}
void afisare_coada(struct Nod *prim, struct Nod *ultim){
    struct Film info;

    if (prim == NULL) {
        printf("coada este goala\n");
        return;
    }

    struct Nod *curent = ultim;

    do{
        info = pop(prim, ultim);
        afisare_info(info);

        struct Nod *nod = creare_nod(info);
        push(prim, ultim, nod);

    }while(curent != prim);

    info = pop(prim, ultim);
    afisare_info(info);

    struct Nod *nod = creare_nod(info);
    push(prim, ultim, nod);
}
