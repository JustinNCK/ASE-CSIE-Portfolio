#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

//exercitu exemplu
/*int main()
{
    char sir[20];
    int dim, i;
    //Varianta 1: de citire preluata de la vectori
    cout << "Dati denumirea sirului: ";
    cin >> dim;
    cout << "Introduceti sirul (v1): ";
    for (i = 0; i < dim; i++)
        cin >> sir[i];
    sir[dim] = '\0';
    //Varianta 1: afisarea preluata de la vectori
    cout << "Sirul este: ";
    for (i = 0; i < dim; i++)
        cout << sir[i];
    cout << endl;


    //Varianta 2: citire simpla cu cin
    cout << "Introduceti sirul(v2 - cin): ";
    cin >> sir;
    cout << "Sirul introdus este: " << sir << endl;
    //Varianta 3: citire simpla cu cin.getline
    fflush(stdin); // functia coleste de caractere buffer-ul in care se stocheaza
                   // temporar caracterele citite de la tastatura (in acest caz 
                   // buffer-ul are '\n' de la ENTER-ul de la cin-ul anterior)
    cout << "Introduceti sirul(v2 - cin.getline): ";
    cin.getline(sir, 20);
    cout << "Sirul introdus este: " << sir;
    return 0;
}*/



/*int main()
{
    char sir[50];
    char a;
    cout << "Introduceti sirul: ";
    cin.getline(sir, 50);
    cout << endl;
    cout << "Introdiceti caracterul: ";
    cin >> a;
    if (strchr(sir, a) != NULL)
        cout << "caracterul a fost gasit in sir";
    else
        cout << "caracterul nu a fost gasit in sir";
    return 0;
}*/


//sa se determine cate vocale are un sir de caractere folosint functia "strchr"
/*int main()
{
    char sir[50];
    char a, e, i, o, u, n;
    cout << "Introduceti sirul: ";
    cin.getline(sir, 50);
    n = 0;
    a = 'a';
    e = 'e';
    i = 'i';
    o = 'o';
    u = 'u';
    if (strchr(sir, a) == NULL || strchr(sir, e) == NULL || strchr(sir, i) == NULL || strchr(sir, o) == NULL || strchr(sir, u) == NULL)
        n == 1;
    if (n == 0)
        cout << "sirul de carcatere are vocale";
    else
        cout << "sirul de carcatere nu are vocale";
    return 0;
}*/

/*int main()
{
    char sir[50];
    char a, n, i;
    cout << "Introduceti sirul: ";
    cin.getline(sir, 50);
    n = 0;
    for (i = 0; i < strlen(sir); i++)
        if (strchr("aeiuo", sir[i]) != NULL)
            n = 1;
    if (n == 1)
        cout << "sirul de carcatere are vocale";
    else
        cout << "sirul de carcatere nu are vocale";
    return 0;
}*/



/*int main()
{
    char sir1[50], sir2[50];
    cout << "itroduceti primul sir: ";
    cin.getline(sir1, 50);
    cout << endl;
    cout << "itroduceti al doilea sir: ";
    cin.getline(sir2, 50);
    if (strstr(sir1, sir2) != NULL)
        cout << "sir2 se afla in sir1";
    else
        cout << "sir2 nu se afla in sir1";
    return 0;
}*/

//se introduc de la tastatura doua siruri, sa se verifice daca un sir il contine pe celalalt
/*int main()
{
    char sir1[50], sir2[50];
    cout << "itroduceti primul sir: ";
    cin.getline(sir1, 50);
    cout << endl;
    cout << "itroduceti al doilea sir: ";
    cin.getline(sir2, 50);
    if (strstr(sir1, sir2) != NULL ||  strstr(sir2, sir1) != NULL)
        cout << "sir2 contine sir1 si sir1 contine sir2";
    else
        cout << "sir2 nu contine sir1 si sir1 nu contine sir2";
    return 0;
}*/


//se citeste un sir de caractere sa se determine cate cifre contine sirul respectiv
/*int main()
{
    char sir[50];
    int n, i;
    n = 0;
    cout << "Itroduceti sirul: ";
    cin.getline(sir, 50);
    for (i = 0; i < strlen(sir); i++)
        if (strchr("1234567890", sir[i]) != NULL)
            n++;
    cout << n;
}*/



/*TEMA: 1) se citesc de la tastatura 2 siruri de caractere, sa se afiseze pe ecran daca sirurile contin aceleasi caractere(nu neaparat in aceiasi ordine)(cabagrame)
        2) se citeste de la tastatura un sir de caractere, sa se afiseze pe ecran cate consoane are sirul
        3) se citesc de la tastatura 2 siruri de caractere, sa se construieasca un al treilea sir format din cele doua siruri alipite
*/


//1
/*int main()
{
    char sir1[50], sir2[50];
    int v[123] = {0};
    int i, j, ok;
    cout << "itroduceti primul sir: ";
    cin.getline(sir1, 50);
    cout << "itroduceti al doilea sir: ";
    cin.getline(sir2, 50);
    for (i = 0; i < strlen(sir1); i++)
        for (j = 0; j < 123; j++)
            if (j == sir1[i])
                v[j] = 1;
    for (i = 0; i < strlen(sir2); i++)
        for (j = 0; j < 123; j++)
            if (j == sir2[i] && v[j] != j)
            {
                if (v[j] == 1)
                    v[j] = j;
                else
                    v[j] = 1;
                break;
            }
    ok = 1;
    for (i = 0; i < 123; i++)
        if (v[i] != i || v[i] != 0)
            if (v[i] == 1)
                ok = 0;
    if (ok == 1)
        cout << "da";
    else
        cout << "nu";
    //for (i = 0; i < 123; i++)
        //cout << "v[" << i << "]= " << v[i] << endl;
    return 0;
}*/



//2
/*int main()
{
    char sir[50];
    char a, i;
    int n;
    n = 0;
    cout << "Introduceti sirul: ";
    cin.getline(sir, 50);
    for (i = 0; i < strlen(sir); i++)
        if (sir[i] >= 'a' && sir[i] <= 'z' && strchr("aeiuo", sir[i]) == NULL)
            n++;
    cout << n;
    return 0;
}*/



//3
/*int main()
{
    char sir1[50], sir2[50];
    char sir3[100];
    int i;
    cout << "itroduceti primul sir: ";
    cin.getline(sir1, 50);
    cout << "itroduceti al doilea sir: ";
    cin.getline(sir2, 50);
    for (i = 0; i < strlen(sir1); i++)
        sir3[i] = sir1[i];
    for (i = 0; i <= strlen(sir2); i++)
    {
        sir3[strlen(sir1) + i] = sir2[i];
    }
    cout << sir3;
    return 0;
}*/


/*int main()
{
    char sir1[50], sir2[50];
    char sir3[100];
    cout << "itroduceti primul sir: ";
    cin.getline(sir1, 50);
    cout << "itroduceti al doilea sir: ";
    cin.getline(sir2, 50);
    strcpy(sir3, sir1);
    strcpy(sir3 + strlen(sir1), sir2);
    cout << sir3;
    return 0;
}*/


//MODEL strtok
//se citeste de la tastatura un sir de caractere ce contine cuvinte separate prin spatiu
//sa se afiseze pe ecran cate caracatere contine fiecare cuvant
/*int main()
{
    char sir[50];
    char* cuv;
    cout << "introduceti sirul: ";
    cin.getline(sir, 50);

    cuv = strtok(sir, " ");
    while (cuv != NULL) {
        cout << strlen(cuv) << endl;
        cuv = strtok(NULL, " ");
    }
}*/


//sa se realizeze un program ce citeste de la tastatura un sir de caractere
//sa se afiseze pe ecran cate vocale contine fecare cuvant
/*int main()
{
    char sir[50];
    char* cuv;
    int n, i;
    cout << "introduceti sirul: ";
    cin.getline(sir, 50);
    cuv = strtok(sir, " ");
    while (cuv != NULL) 
    {
        n = 0;
        for (i = 0; i < strlen(cuv); i++)
        if (strchr("aeoiu", cuv[i]) != NULL)
            n++;
        cout << n << " ";
        cuv = strtok(NULL, " ");
    }
}*/


//se citesc de la tastatura doua siriru de caractere
//sa se afiseze pe ecran daca cele doua siruri au cel putin un cuvat comun
/*int main()
{
    char sir1[50], sir2[50];
    char* cuv, *cuv2;
    int ok;
    cout << "introduceti sirul: ";
    cin.getline(sir1, 50);
    cout << "introduce ti sirul: ";
    cin.getline(sir2, 50);
    cuv = strtok(sir1, " ");
    ok = 0;
    while (cuv != NULL) 
    {
        cuv2 = strtok(sir2, " ");
        while (cuv2 != NULL) {
            if (strcmp(cuv, cuv2) == 0) {
                ok = 1;
                break;
            }
            cuv2 = strtok(NULL, " ");
        }
        cuv = strtok(NULL, " ");
    }
    if (ok == 1)
        cout << "exista cel putin un cuvant comun";
    else
        cout << "nu exista cel putin un cuvant comun";
    return 0;
}*/


//1. Se citeste de la tastatura un sir de cuvinte despartite prin spatiu.
//Sa se modifice fiecare cuvant astfel incat acesta sa aiba prima litera mare si restul mici. Sa se afiseze pe ecran rezultatul.
//65 - 90 sunt litere mari
//97 - 122 sunt litere mici
//32 este diferenta
/*int main()
{
    char sir[50], sir2[50];
    char* cuv;
    int n, i;
    cout << "introduceti sirul: ";
    cin.getline(sir, 50);
    cuv = strtok(sir, " ");
    while (cuv != NULL)
    {
        if (cuv[0] >= 'a' && cuv[0] <= 'z')
        {
            n = cuv[0];
            n = n - 32;
            cuv[0] = n;
        }
        for (i = 1; i < strlen(cuv); i++)
        {
            if (cuv[i] >= 'A' && cuv[i] <= 'Z')
            {
                n = cuv[i];
                n = n + 32;
                cuv[i] = n;
            }
        }
        cout << cuv << " ";
        cuv = strtok(NULL, " ");
    }
    return 0;
}*/




//2. Se citeste de la tastatura un sir de cuvinte despartite prin spatiu.
//Sa se determine cate numere contine sirul.
/*int main()
{
    char sir[50];
    char* cuv;
    int nr, i;
    cout << "introduceti sirul: ";
    cin.getline(sir, 50);
    nr = 0;
    cuv = strtok(sir, " ");
    while (cuv != NULL)
    {
        for (i = 0; i < strlen(cuv); i++)
            if (strchr("1234567890", cuv[i]) != NULL)   // sau if (cuv[i] >= '0' && cuv[i] <= '9')
            {
                nr++;
                break;
            }
        cuv = strtok(NULL, " ");
    }
    cout << nr;
    return 0;
}*/