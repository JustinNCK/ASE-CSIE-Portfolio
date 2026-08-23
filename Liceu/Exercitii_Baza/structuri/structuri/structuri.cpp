#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/*struct elev
{
    char nume[20];
    int varsta, clasa;
    float medie;
};

int main()
{
    struct elev e;
    cout << "Numele elevului: ";
    cin >> e.nume;
    cout << "Varsta elevului: ";
    cin >> e.varsta;
    cout << "Clasa elevului: ";
    cin >> e.clasa;
    cout << "Media elevului: ";
    cin >> e.medie;

    cout << "Date despre elev: " << endl << e.nume << endl << e.varsta << endl << e.clasa << endl << e.medie;
}*/



/*struct elev
{
    char nume[20];
    int varsta, clasa;
    float medie;
};

int main()
{
    int i, n;
    cout << "dati numarul de elevi: ";
    cin >> n;
    struct elev v[10];
    for (i = 0; i < n; i++)
    {
        cout << "Elev " << i + 1 << ": " << endl;
        cout << "   Nume: ";
        cin >> v[i].nume;
        cout << "   Varsta: ";
        cin >> v[i].varsta;
        cout << "   Clasa: ";
        cin >> v[i].clasa;
        cout << "   Medie: ";
        cin >> v[i].medie;
    }
    cout << "Informatile introduse sunt: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << v[i].nume << " ";
        cout << v[i].varsta << " ";
        cout << v[i].clasa << " ";
        cout << v[i].medie << endl;
    }
}*/



/*struct autoturisme
{
    char marca[15];
    int an;
    float pret;
};

void afis(autoturisme v[20], int n);
void marca(autoturisme v[20], int n);
void descrescator(autoturisme v[20], int n);
void crono(autoturisme v[20], int i);
void alegere(autoturisme v[20], int n);

int main()
{
    autoturisme v[20];
    int i, n, al;
    ifstream fin("date.txt");
    fin >> n;
    cout << "Numarul de autoturisme: " << n << endl << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Autoturismul " << i + 1 << endl;
        cout << "    Marca autoturismului: ";
        fin >> v[i].marca;
        cout << v[i].marca << endl;
        cout << "    Anul de productie: ";
        fin >> v[i].an;
        cout << v[i].an << endl;
        cout << "    Pretul autoturismului: ";
        fin >> v[i].pret;
        cout << v[i].pret << endl;
        cout << endl << endl;
    }
    do
        alegere(v, n);
    while (1);
}

void alegere(autoturisme v[20], int n)
{
    int al;
    cout << "Alegeti ce vreti sa faceti: " << endl;
    cout << "0) Iesire" << endl;
    cout << "1) Afisarea autoturimelor de la marca dorita" << endl;
    cout << "2) Afisarea atutoturismelor mai noi de anul 2000" << endl;
    cout << "3) Autoturismele sa se afiseze in mod descrecscator in functie de pret" << endl;
    cout << "4) Autoturismele de o marca specificata in ordine cronologica" << endl;
    cin >> al;
    if (al == 0)
        exit(0);
    if (al == 1)
        afis(v, n);
    else if (al == 2)
        marca(v, n);
    else if (al == 3)
        descrescator(v, n);
    else if (al == 4)
        crono(v, n);
    else cout << "Optiune invalida" << endl;
}

void afis(autoturisme v[20], int n)
{
    int cont, i;
    char m[10];
    cont = 0;
    cout << "Ce marca doriti sa cautati: ";
    cin >> m;
    cout << endl;
    for (i = 0; i < n; i++)
    {
        if (strcmp(v[i].marca, m) == 0)
        {
            cout << "Autoturismul " << i + 1 << "    " << endl;
            cout << v[i].marca << ", " << v[i].an << ", " << v[i].pret << endl;
            cont = 1;
        }
    }
    if (cont == 0)
        cout << "Nu exista masini de la marca dorita" << endl;
    cout << endl;
}

void marca(autoturisme v[20], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (v[i].an >= 2000)
        {
            cout << "Autoturismul " << i + 1 << endl << "    ";
            cout << v[i].marca << ", " << v[i].an << ", " << v[i].pret << endl;
        }
    cout << endl;
}

void descrescator(autoturisme v[20], int n)
{
    int i, a;
    autoturisme aux;
    a = 1;
    while (a == 1)
    {
        a = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (v[i].pret < v[i + 1].pret)
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                a = 1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << "Autoturismul " << i + 1 << endl << "    ";
        cout << v[i].marca << ", " << v[i].an << ", " << v[i].pret << endl;
    }
    cout << endl;
}

void crono(autoturisme v[20], int n)
{
    int i, a, b, cont;
    char m[10];
    autoturisme con[20], aux;
    cout << "Ce marca doriti sa cautati: ";
    cin >> m;
    cont = 0;
    a = 0;
    for (i = 0; i < n; i++)
        if (strcmp(v[i].marca, m) == 0)
        {
            con[a] = v[i];
            a++;
            cont = 1;
        }
    b = 1;
    while (b == 1)
    {
        b = 0;
        for (i = 0; i < a - 1; i++)
        {
            if (con[i].an > con[i + 1].an)
            {
                aux = con[i];
                con[i] = con[i + 1];
                con[i + 1] = aux;
                b = 1;
            }
        }
    }
    for (i = 0; i < a; i++)
    {
        cout << "Autoturismul " << i + 1 << endl << "    ";
        cout << con[i].marca << ", " << con[i].an << ", " << con[i].pret << endl;
    }
    if (cont == 0)
        cout << "Nu exista autoturisme" << endl;
    cout << endl;
}*/



//Bac
//SI
//1. b
//2. b
//3. a

//SII

//1.

// a.
// n = 205579
// m = 0
// c = 9
// n = 20557
// m = -1
// 
// c = 7 
// n = 2055
// m = -1
// 
// c = 5
// n = 205
// m = -1
// 
// c = 5
// n = 20
// m = -1
// 
// c = 0
// n = 2
// m = -1
// 
// c = 2
// n = 0
// m = -1
// 
// scrie -1

//b. 7889, 7999, 7899

//c.
/*int main()
{
    int n, m, c;
    cin >> n;
    m = 10;
    if (n == 0)
        m = 0;
    else
        do
        {
            c = n % 10;
            n = n / 10;
            if (c <= m)
                m = c;
            else
                m = -1;
        } while (n != 0);
    cout << m;
}*/

//d. 
//citește n(număr natural)
//m <- 10
//┌cat timp n != 0 executa
//│ c <- n % 10; n <- [n / 10]
//│┌dacă c <= m atunci m <- c
//││altfel m <- 1
//│└■
//└■
//scrie m


//3. 
// cout 1: 7
// s2: 2021
// s2: 2020-
// s2: 2020-2021
// cout 2: 2020-2021
// 7
// 2020-2021


//SIII
//1.
/*void divX(int n, int x)
{
    int v[50], i;
    for (i = 1; i <= n; i++)
        v[i] = i * x;
    for (i = n; i >= 1; i--)
        cout << v[i] << " ";
}

int main()
{
    int n, x;
    cout << "Dati numere n si x: ";
    cin >> n >> x;
    divX(n, x);
}*/


//2.
/*int main()
{
    int mat[100][100], i, j, n;
    cout << "Dati numarul n: ";
    cin >> n;
    for(i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (i = 0; i < n; i++)
        cout << mat[i][0] << " ";
    for (i = 1; i < n; i++)
        cout << mat[n - 1][i] << " ";
    for (i = n - 2; i >= 0; i--)
        cout << mat[i][n - 1] << " ";
    for (i = n - 2; i >= 1; i--)
        cout << mat[0][i] << " ";
}*/


//TEMA 
// v1, sIII, 3
// v2
// sI 1, 2
// sII 1, 2, 3
// sIII 1, 2, 3

//SIII
//3.
/*int main()
{
    int v[100] = { 0 }, b[2] = { 0 }, i, n, j, a, aux, cont, ok;
    ifstream fin("bac.txt");
    n = 0;
    /*cont = 2;
    while (fin >> v[n])
        n++;
    for (i = 98; i >= 10 && cont != 0; i--)
    {
        ok = 1;
        for (j = 0; j < n; j++)
            if (i == v[j])
            {
                ok = 0;
                j = n;
            }
        if (ok == 1 && i % 10 != i / 10)
        {
            cout << i << " ";
            cont--;
        }
    }
    cont = 0;
    while (fin >> a)
        if (a <= 99)
            v[a] = 1;
    for (i = 98; i >= 10 && cont != 2; i--)
        if (v[i] == 0 && (i % 10 != i / 10))
        {
            b[cont] = i;
            cont++;
        }
    if (cont < 2)
        cout << "nu exista";
    else
        cout << b[0] << " " << b[1];
}*/


//v2
//SI
//1. a
//2. d

//SII
//1.
//a
// n = 2186310
// s = 1
// c1 = 0
// n = 218631
// c2 = 1
// s = -1
// 
// c1 = 1
// n = 21863
// c2 = 3
// 
// c1 = 3
// n = 2186
// c2 = 6
// 
// c1 = 6
// n = 218
// c2 = 8
// 
// c1 = 8
// n = 21
// c2 = 1
// 
// scrie -1 21

//b. 12345, 12356

//c.
/*int main()
{
    int n, c1, c2, s;
    s = 1;
    cin >> n;
    c1 = n % 10;
    n = n / 10;
    c2 = n % 10;
    if (c1 == c2)
        s = 0;
    else if (c1 < c2)
        s = -1;
    while ((c1 - c2) * s > 0 && n > 9)
    {
        c1 = n % 10;
        n = n / 10;
        c2 = n % 10;
    }
    cout << s << " " << n;
}*/

//d.
/*citește n(număr natural, n > 9)
s <- 1
c1 <- n % 10; n <- [n / 10]; c2 <- n % 10
┌dacă c1 = c2 atunci s <- 0
│altfel
│┌dacă c1 < c2 atunci s <- - 1
│└■
└■
┌daca (c1 - c2) * s > 0 și n > 9 atunci
│ ┌executa
│ │c1 <- n % 10; n <- [n / 10]; c2 <- n % 10
│ └■cat timp (c1 - c2) * s > 0 și n > 9
└■
scrie s, ' ', n
*/

//2.
/*struct polinom
{
    int grad, coeficienti[100];
};*/


//3.
/*int main()
{
    char v[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}, i, j, a, n, cuv[20];
    n = 10;
    cout << "Scrieti textul: ";
    cin.getline(cuv, 20);
    for (i = 0; i < strlen(cuv); i++)
    {
        for (j = 0; j < n; j++)
            if (cuv[i] == v[j])
            {
                for (a = j; a < n - 1; a++)
                    v[a] = v[a + 1];
                n--;
            }
    }
    cout << endl;
    for (i = 0; i < n; i++)
        cout << v[i] << " ";
}*/


//SIII
//1.
/*int prim(int i);
void factori(int m, int n);

int main()
{
    int m, n;
    cout << "Dati numerele n si m: ";
    cin >> n >> m;
    factori(m, n);
}

void factori(int m, int n)
{
    int a[n / 2 + 1], b[m / 2 + 1], i, d;
    for (i = 2; i <= n / 2; i++)
        a[i] = 1;
    for (i = 2; i <= n / 2; i++)
        if (n % i == 0)
            if (prim(i))
            {
                a[i] = a[i] * i;
                n = n / i;
                i--;
            }
    for (i = 2; i <= m / 2; i++)
        b[i] = 1;
    for (i = 2; i <= m / 2; i++)
        if (m % i == 0)
            if (prim(i))
            {
                b[i] = b[i] * i;
                m = m / i;
                i--;
            }
    for (i = 2; i <= n / 2; i++)
        if (a[i] == b[i] && a[i] != 1 && b[i] != 1)
            cout << i << " ";
}

int prim(int i)
{
    int d;
    for (d = 2; d <= i / 2; d++)
        if (i % d == 0)
        {
            return 0;
        }
    return 1;
}*/


//2.
/*int main()
{
    int mat[20][20], n, i, j;
    cout << "Dati numarul n: ";
    cin >> n;
    for (i = 0; i < n; i++)
        mat[n - i - 1][i] = n;
    n--;
    while (n != 0)
    {
        for (i = 0; i < n; i++)
        {
            mat[n - i - 1][i] = n;
            mat[i][n - i - 1] = n;
        }
        n--;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}*/



//3.
/*int main()
{
    int v[1000], i, n;
    ifstream fin("bac.in");
    n = 0;
    i = 0;
    while (fin >> v[i])
    {
        i++;
        n++;
    }
    for (i = 0; i < n; i++)
        if (i <= n / 2)
            if (v[i] >= 0)
                cout << n - i;
            else
                cout << "";
        else
            if (v[i] >= 0)
                cout << n - (n - i);
}*/