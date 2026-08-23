#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

//sa se realizeze o functie care calculeaza suma a doua numere intregi a si b date ca parametri de intrare
//funcia va furniza la iesire un numar intreg reprezeantand suma celor doua numere

/*int suma(int a, int b)
{
    int s;

    s = a + b;

    return s;
}

int main()
{
    int a, b, s, x, y, s2;
    cin >> a >> b;

    s = suma(a, b);

    cin >> x >> y;
    s2 = suma(x, y);

    cout << s << endl << s2;

    return 0;
}*/

/*float medie_aritmetica(int a, int b, int c)
{
    float ma, s;
    s = a + b + c;
    ma = s / 3;
    return ma;
}

int main()
{
    int m, n, p;
    float ma;
    cin >> m >> n >> p;
    ma = medie_aritmetica(m, n, p);
    cout << ma;
    return 0;
}*/


//TEMA
//1. sa se realizeze un subprogram care detremina oglinditul unui numar dat ca parametru de intrare
//2. sa se realizeze un subprogram care caluculeaza suma cifrelor unui numar
//3. sa se realizeze un subprogram care determina daca un numar este prim (returneaza 1 daca este, returneaza 0 daca nu este)


//1
/*int oglindit(int n)
{
    int rs;
    rs = 0;
    while (n != 0)
    {
        rs = rs * 10 + n % 10;
        n = n / 10;
    }
    return rs;
}

int main()
{
    int n, rs;
    cin >> n;
    rs = oglindit(n);
    cout << rs;
    return 0;
}*/

//2

/*int sumcif(int n)
{
    int s;
    s = 0;
    while (n != 0)
    {
        s = s + n % 10;
        n = n / 10;
    }
    return s;
}

int main()
{
    int n, s;
    cin >> n;
    s = sumcif(n);
    cout << s;
    return 0;
}*/

//3
/*int prim(int n);

int main()
{
    int n, a;
    cin >> n;
    a = 2;
    if (prim(n) == 1)
        cout << "numarul este prim";
    else
        cout << "numarul nu este prim";
    cout << endl << a;
}

int prim(int n)
{
    int d, ok, a;
    a = 5;
    ok = 1;
    for (d = 2; d <= n / 2; d++)
        if (n % d == 0)
        {
            ok = 0;
            break;
        }
    if (ok == 1)
        return 1;
    else
        return 0;
}*/


//se citeste un vetor de n numere intregi,
//sa se realizez o functie care adauga la fiecare element al vectorului valuarea 5
// sa se afiseze in main vectorul
/*void cif(int v[10], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        v[i] = v[i] + 5;
    }
}

int main()
{
    int v[10], n, i;
    cout << "dati nr de elemte: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    cif(v, n);
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= " << v[i] << endl;
    }
}*/



//se citeste de la tastatura un vector de n numere intregi,
//sa se verifice si sa se afiseze pe ecran elementele prime din vector

/*int prim(int x)
{
    int d, ok;
    ok = 1;
    for (d = 2; d < x / 2; d++)
    {
        if (x % d == 0)
        {
            ok = 0;
            break;
        }
    }
    if (ok == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int v[20], i, n;
    cout << "introduceti numarul de elemente: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (prim(v[i]) == 1)
            cout << v[i] << " numarul este prim" << endl;
        else
            cout << v[i] << " numarul nu este prim" << endl;
    }
}*/



//TEMA
//1. Se citeste un vector de numere intregi. Sa se afiseze pe ecran elementele de tip palindrom din vector.
//2. Se citeste o matrice de numere intregi.Sa se afiseze pe ecran elementele prime de pe fiecare linie a matricii.
//3. Sa se verifice daca fiecare linie a unei matrice este ordonata crescator.

//1
/*int palindrom(int a);

int main()
{
    int v[50], n, i;
    cout << "itroduceti numarul de caractere: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (palindrom(v[i]) == 1)
            cout << v[i] << " este numar palindrom" << endl;
        else
            cout << v[i] << " nu este numar palindrom" << endl;
    }
}

int palindrom(int a)
{
    int rs, ca;
    ca = a;
    rs = 0;
    while (a != 0)
    {
        rs = rs * 10 + a % 10;
        a = a / 10;
    }
    if (rs == ca)
        return 1;
    else
        return 0;
}*/


//2
/*void linie_prim(int i, int n, int mat[50][50]);


int main()
{
    int mat[50][50], m, n, i, j;
    cout << "Dati numarul de elemente: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (i = 0; i < m; i++)
        linie_prim(i, n, mat);
}

void linie_prim(int i, int n, int mat[50][50])
{
    int j, d, ok;
    for (j = 0; j < n; j++)
    {
        ok = 1;
        for (d = 2; d <= mat[i][j] / 2; d++)
        {
            if (mat[i][j] % d == 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
            cout << "mat[" << i << "][" << j << "]= " << mat[i][j] << endl;
    }
}*/


//3
/*int crescator(int i, int n, int mat[10][10]);

int main()
{
    int mat[10][10], m, n, i, j;
    cout << "Dati numarul de elemente: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (i = 0; i < m; i++)
    {
        if (crescator(i, n, mat) == 1)
            cout << "linia " << i << " este crescatoare" << endl;
    }
}

int crescator(int i, int n, int mat[10][10])
{
    int j, d, ok;
    ok = 1;
    for (j = 0; j < n - 1; j++)
    {
        if (mat[i][j] > mat[i][j + 1])
            ok = 0;
    }
    if (ok == 1)
        return 1;
    else
        return 0;
}*/


//se citeste de la tastatura o matrice de numere intregi
//sa se afiseze pe ecran patratele perfecte de pe fiecare coloana a matrici

/*void coloana(int j, int m, int mat[10][10]);
void perfect(int a);

int main()
{
    int mat[10][10], m, n, i, j;
    cout << "Dati numarul de elemente: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (j = 0; j < n; j++)
        coloana(j, m, mat);
}

void coloana(int j, int m, int mat[10][10])
{
    int i;
    for (i = 0; i < m; i++)
        perfect(mat[i][j]);
    cout << endl;
}

void perfect(int a)
{
    if (sqrt(a) == int(sqrt(a)))
        cout << a << " ";
}*/


//TEMA
//1. Se citeste o matrice de numere reale.
//Sa se determine cel mai mare numar intreg de pe fiecare linie.
//2. Se citeste o matrice de numere intregi.
//Sa se calculeze si sa se afiseze pe ecran factorialul pt fiecare element(folosind subprogram)
//3. Se citeste o matrice de numere intregi.
//Sa se determine cel mai mic element de pe diagonala principala si secundara(folosind un singur subprogram, care calculeaza valoarea maxima dintr - un vector)


//1
/*void linie(int i, int n, float mat[10][10]);
int mare(int a, int b);

int main()
{
    float mat[10][10];
    int m, n, i, j;
    cout << "Dati numarul de elemente: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (i = 0; i < m; i++)
        linie(i, n, mat);
}

void linie(int i, int n, float mat[10][10])
{
    int j;
    double max;
    max = 1.1;
    for (j = 0; j < n; j++)
        if (int(mat[i][j]) == mat[i][j])
        {
            max = mat[i][j];
            j++;
            break;
        }
    for (; j < n; j++)
        if (mare(max, mat[i][j]) == 1 && int(mat[i][j]) == mat[i][j])
            max = mat[i][j];
    if (max == 1.1)
        cout << "linia nu are numere reale" << endl;
    else
        cout << max << endl;
}

int mare(int a, int b)
{
    if (a < b)
        return 1;
    else
        return 0;
}*/


//2
/*void factorial(int a);

int main()
{
    int mat[10][10], m, n, i, j;
    cout << "Dati numarul de elemente: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            factorial(mat[i][j]);
}

void factorial(int a)
{
    int p, f;
    f = 1;
    if (a >= 2)
    {
        for (p = 1; p <= a; p++)
            f = f * p;
        cout << f << " ";
    }
    else
        cout << "1" << " ";
}*/


//3
/*void mic(int v[10], int a);

int main()
{
    int mat[10][10], m, i, j, v[10];
    cout << "Dati numarul de elemente: ";
    cin >> m;
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (i = 0; i < m; i++)
        v[i] = mat[i][i];
    mic(v, m);
    for (j = 0; j < m; j++)
        v[j] = mat[j][m - 1 - j];
    mic(v, m);
}

void mic(int v[10], int a)
{
    int i, min;
    min = v[0];
    for (i = 1; i < a; i++)
    {
        if (min > v[i])
            min = v[i];
    }
    cout << min << endl;
}*/



//tema
/*int main()
{
    int mat[10][10], i, m, j, nr, x, a, e, f;
    cout << "Dati nr de elemnte: ";
    cin >> m;
    nr = 1;
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            mat[i][j] = nr;
            nr++;
        }
    /*for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    x = m;
    a = 0;
    e = 1;
    f = m - 2;
    while (x > 0)
    {
        for (j = a; j < x; j++)
        {
            //cout << "mat[" << a << "][" << j << "]= ";
            cout << mat[a][j] << " ";
        }
        x--;
        for (i = e; i <= x; i++)
        {
            //cout << "mat[" << i << "][" << x << "]= ";
            cout << mat[i][x] << " ";
        }
        
        for (j = x - 1; j >= a; j--)
        {
            //cout << "mat[" << x << "][" << j << "]= ";
            cout << mat[x][j] << " ";
        }
        
        for (i = f; i >= e; i--)
        {
            //cout << "mat[" << i << "][" << a << "]= ";
            cout << mat[i][a] << " ";
        }
        e++;
        f--;
        a++;
    }
}*/


//se cieste de la tastatura un vector de ne intregi
//sa se stearga din vector un element de pe o pozitie specificata
/*int main()
{
    int v[50], i, n, x;
    cout << "dati nr de elemnte: ";
    cin >> n;
    cout << "pozitia elementului care este sters: ";
    cin >> x;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    n--;
    x--;
    for (i = x; i < n; i++)
        v[i] = v[i + 1];
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}*/


//se citeste un vector de numere intregi
//sa se insereze in vector o valuare specificata pe o pozitie specificata
/*int main()
{
    int v[50], i, n, x, a;
    cout << "dati nr de elemnte: ";
    cin >> n;
    cout << "pozitia elementului care este inserat: ";
    cin >> x;
    cout << "dati numarul care este inserat: ";
    cin >> a;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    x--;
    for (i = n; i > x; i--)
        v[i] = v[i - 1];
    v[x] = a;
    for (i = 0; i <= n; i++)
    {
        cout << v[i] << " ";
    }
}*/


//se citeste de le tastatura o matrice de numere intregi
//sa se afiseze pe ecran elemenrtele distincte de pe fiecare linie (adica elementele care apar pe linie afiste o singura data)
/*void linie(double v[10], int n);

int main()
{
    double mat[10][10];
    int i, j, m, n;
    cout << "itroduceti numarul de linii si coloane: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (i = 0; i < m; i++)
        linie(mat[i], n);
}

void linie(double v[10], int n)
{
    int j, i;
    for (j = 0; j < n; j++)
    {
        for (i = j + 1; i < n; i++)
            if (v[i] == v[j])
                v[i] = 1.1;

    }
    for (j = 0; j < n; j++)
        if (v[j] != 1.1)
            cout << v[j] << " ";
    cout << endl;
}*/


//se citeste de la tastatura o matrice de numere intregi
//sa se modifice matricea elminand elemtele de pe diagonala principala
/*void linie(int mat[10], int i, int n);

int main()
{
    int mat[10][10], i, j, m, n;
    cout << "Dati numarul colane si linii: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    n--;
    for (i = 0; i < m; i++)
        linie(mat[i], i, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void linie(int mat[10], int i, int n)
{
    int j;
    for (j = i; j < n; j++)
        mat[j] = mat[j + 1];
}*/


//problema rosii
//https://www.pbinfo.ro/probleme/2453/rosii-mici

/*int main()
{
    int mat[10][10], v[10], s[10], i, j, m, n, nr, q, x, a, b, c;
    cout << "Dati numarul colane si linii: ";
    cin >> m >> n;
    cout << "Dati numarul de sarcini: ";
    cin >> q;
    cout << "Dati sarciniile: ";
    for (a = 0; a < q; a++)
        cin >> s[a];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    for (a = 0; a < q; a++)
    {
        for (b = 0; b < m; b++)
        {
            nr = 0;
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                    if (mat[j][i] < s[a])
                        nr++;
            }
            v[b] = 0;
        }
        c = 1;
        while (c == 1)
        {
            c = 0;
            for (i = 0; i < n - 1; i++)
            {
                if (v[i] > v[i + 1])
                {
                    a = v[i + 1];
                    v[i + 1] = v[i];
                    v[i] = a;
                    c = 1;
                }
            }
        }
        c = v[0] * n;
        for (b = 1; b < n; b++)
            if (v[b] * (n - b + 1) > c)
                c = v[b] * (n - b + 1);
        cout << c << endl;
    }
}*/


//sa se realizeze un program care permite citerea unui numar intreg n de la tastatura
//si afiseaza pe ecran in mod recursiv numerele intregi de la n la 0;

/*void afisare(int n) {
    if (n == -1) {
        return;
    }
    cout << n << " ";
    afisare(n - 1);
}


7 6 5 4 3 2 1 0 
afisare(7):
    cout << 7 << " ";
    afisare(6):
        cout << 6 << " ";
        afisare (5):
            cout << 5 << " ";
            afisare(4)
                cout << 4 << " ";
                afisare(3):
                    cout << 3 << " ";
                    afisare(2):
                        cout << 2 << " ";
                        afisare(1):
                            cout << 1 << " ";
                            afisare(0):
                                cout << 0 << " ";
                                afisare(-1):
                                    return;


int main()
{
    int n;
    cin >> n;
    afisare(n);
}*/


//sa se afiseze toate numerele pare de la n la 0

/*void par(int n)
{
    if (n == -2)
        return;
    cout << n << " ";
    par(n - 2);
}

int main()
{
    int n;
    cin >> n;
    if(n % 2 == 0)
        par(n);
    else
        par(n - 1);

}*/


//se citeste un numar intreg n
//sa se afiseze toate numerele intregi de la 1 la n

/*void creste(int i, int n)
{
    if (i == n + 1)
    {
        return;
    }
    cout << i << " ";
    creste(i + 1, n);
}

int main()
{
    int i, n;
    cin >> n;
    i = 1;
    creste(i, n);
}*/


//afisre de la 1 la n si dupa de la n la 1;

/*void cd(int n, int i)
{
    if (i == n+1)
        return;
    cout << i << " ";
    cd(n, i + 1);
    cout << i << " ";
}

cd(3, 1):
    cout << 1 << " "
    cd(4, 2):
        cout << 2 << " "
        cd(4,3):
           cout << 3 << " "
           cd(4,4)
               cout << 4 << " "
               cd(4, 5):
                   return
               cout << 4 << " "
           cout << 3 << " "
        cout << 2 << " "
    cout << 1 << " "


int main()
{
    int n;
    cin >> n;
    cd(n, 1);
}*/


//se citeste de la tastatura un numar intreg n
//sa se determine in mod recursiv si sa se afiseze pe ecran suma numerelor de la 1 la n

/*int suma(int n)
{
    if (n == 0)
        return 0;
    return n + suma(n - 1);
}

/*
suma(3):
    return 3 + suma(2): = return 3+3=6
                    return 2 + suma(1): = return 2+1=3
                                    return 1 + suma(0):  = return 1+0=1
                                                    return 0;


int main()
{
    int n;
    cin >> n;
    cout << suma(n);
}*/


//se se calculeze recursiv factorialul lui n

/*int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
}*/


//TEMA
// 1. se citesc 2 nr intregi x si p
//sa se calculeze in mod recursiv si sa se afiseze x la puterea p
// 2. sa se determine in mod recursiv rezultatul urmatoarei expresi
//1 + 1/2 + 1/3 + 1/4 +... + 1/n-1 + 1/n
// 3. se citesc de la tastatura 2 nr n si m
//sa se calculeze in mod recursiv si sa se afiseze cmmdc dintre n si m
// 4. se citeste de la testatura un nr intreg n
//sa se calculeze in mod recursiv suma cifrelor lui n
// 5. se citesc de la testatura 2 nr a si b
//sa se calculeze in mod recursiv media aritmetica dintre numerele a si b


//1
/*int putere(int x, int p)
{
    if (p == 0)
        return 1;
    return x * putere(x, p - 1);
}

int main()
{
    int x, p;
    cin >> x >> p;
    cout << putere(x, p);
}*/


//2
/*float suma(int n)
{
    if (n == 1)
        return 1;
    return 1.0/n + suma(n-1);
}

int main()
{
    int n;
    double s;
    cin >> n;
    cout << suma(n);
}*/


//3
//mai e o rezolvare cu doi vectri care retin divizori propri si daca gaseste amandoi divizorii
//in ambii vectori ii inmulteste
/*int cmmdc(int a, int b, int d, int max)
{
    if (d == b)
        return max;
    if (a % (d + 1) == 0 && b % (d + 1) == 0)
        max = d + 1;
    cmmdc(a, b, d + 1, max);
}

int main()
{
    int n, m, d, max;
    cin >> n >> m;
    max = 1;
    d = 1;
    if (n > m)
        cout << cmmdc(n, m, d, max);
    else
        cout << cmmdc(m, n, d, max);
}*/

//4
/*int suma(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + suma(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << suma(n);
}*/


//5
/*double ma(int a, int b)
{
    if (a == b)
        return a;
    return a + ma(a + 1, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << ma(a, b) / (b - a + 1);
}*/



//un program care afiseaza un vector recursiv
/*void afisare(int v[10], int i, int n, int cont)
{
    if (i == n)
        return;
    if (cont == 1)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    else
        cout << v[i] << " ";
    afisare(v, i + 1, n, cont);
}

int main()
{
    int v[10], i, n, cont;
    cin >> n;
    i = 0;
    cont = 1;
    afisare(v, i, n, cont);
    cont = 0;
    afisare(v, i, n, cont);
}*/


//suma elementelor unui vector recursiv
/*int afisare(int v[10], int i, int n)
{
    if (i == n - 1)
        return v[i];
    return v[i] + afisare(v, i + 1, n);
}

int main()
{
    int v[10], i, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }

    cout << afisare(v, 0, n);
}*/


//cel mai mare nr dintr-un vector
/*int mare(int v[10], int i, int n, int max)
{
    if (i == n)
        return max;
    if (v[i] > max)
        max = v[i];
    mare(v, i + 1, n, max);
}

/*mare([1, 2], 1, 2, 1) {
*     max = 2;
*     mare([1, 2], 2, 2, 2) {
*         return 2;
*     }
* }
*

int main()
{
    int v[10], i, n, max;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    max = v[0];
    cout << mare(v, 1, n, max);
}*/


//TEMA
//1. Se citeste de la tastatura un vector de numere intregi si un numar intreg x
//Sa se determine in mod recursiv daca elementul x se afla in vector.

/*int afla(int v[20], int n, int i, int x)
{
    if (v[i] == x)
        return 1;
    return afla(v, n, i + 1, x);
}

int main()
{
    int v[20], n, i, x;
    cout << "dati numarul de elemente: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
    cout << endl << "dati numarul x: ";
    cin >> x;
    if (afla(v, n, 0, x) == 1)
        cout << "numarul x se afla in vector";
    else
        cout << "numarul x nu se afla in vector";
}*/


//2. probleme variante bac
//SI
//1. b
//2. d
//3. b

//SII
//1.
//a)
/*
n = 8172039
m = 0
p = 1

n = 8172039
u = 9
m = 0
p = 1

n = 817203
u = 3
m = 3
p = 10

n = 81720
u = 0
m = 3
p = 100

n = 8172
u = 2
m = 203
p = 100

n = 817
u = 7
m = 203
p = 1000

n = 81
u = 1
m = 1203
p = 1000

n = 8
u = 8
m = 1203
p = 1000

n = 0

scrie 1203
*/
//b) 333
//c)
/*int main()
{
    int n, m, p, u;
    cin >> n;
    m = 0;
    p = 1;
    while (n > 0)
    {
        u = n % 10;
        if (u <= 3)
        {
            m = u * p + m;
            p = p * 10;
        }
        n = n / 10;
    }
    cout << m;
}*/
//d)
/*citeste n (numar natural)
m <- 0;
p <- 1;
daca n > 0 atunci
    repeta
        u < n % 10;
        daca u <= 3
            m <- u * p + m;
            p <- p * 10;
        n = [n / 10]
    pana cand n <= 0
scrie m;
*/


//3.
/*
k = 0;
for(i = 0; i <= 9; i++)
    if(A[x][i] < 0 and i % 3 == 0)
    k++;
cout << k;
*/


//SIII
//1.
/*int dublu(int n, int cn)
{
    int nr, i, x;
    nr = 0;
    while (cn != 0)
    {
        nr++;
        cn = cn / 10;
    }
    if (nr % 2 == 0)
        return -1;
    i = nr;
    x = 1;
    while (n != 0)
        if (i != (nr + 1) / 2)
        {
            cn = cn + (n % 10) * x;
            x = x * 10;
            i--;
            n = n / 10;
        }
        else
        {
            cn = cn + (n % 10) * x + (n % 10) * x * 10;
            x = x * 100;
            i--;
            n = n / 10;
        }
    return cn;
}

int main()
{
    int n;
    cin >> n;
    cout << dublu(n, n);
}*/



//sa se calculeze in mod recursiv expresia
// 1/(1+a) + 1/(1+a+1) + 1/(1+a+2) + 1/(1+a+3) + . . . + 1/(1+b-2) + 1/(1+b-1) + 1/(1+b)
//unde a si b sunt doua numere intregi citite de la tastatura(se garanteaza a < b)

/*double suma(double a, int b)
{
    if (a == b + 1)
        return 0;
    return 1 / a + suma(a + 1, b);
}

int main()
{
    int a, b;
    cout << "dati numarul a: ";
    cin >> a;
    cout << "dati numarul b: ";
    cin >> b;
    cout << suma(a + 1, b + 1);
}*/


//sa se calculeze sirul lui fibonacci in mod recursiv pana la n

/*void fibonacci(int n, int a, int b)
{
    int c;
    c = a + b;
    if (c > n)
        return;
    cout << c << " ";
    fibonacci(n, b, c);
}

int main()
{
    int n;
    cin >> n;
    fibonacci(n, 0, 1);
}*/


//TEMA
//1. Se citeste o matrice cu valori de 0 si 1.
//Sa se determine recursiv cate valori de 1 are matricea.
//2.Se citeste o matrice de valori intregi.
//Sa se determine recursiv maximul matricii.
//Sa se genereze recursiv toate numerele de trei cifre cu cifre impare.

//1
/*void afla(int mat[10][10], int m, int n, int i, int j, int& a)
{
    if (i == m - 1 && j == n)
        return;
    if (j == n && i < m)
    {
        j = 0;
        i++;
    }
    if (mat[i][j] == 1)
        a++;
    afla(mat, m, n, i, j + 1, a);
}

int main()
{
    int mat[10][10], i, j, m, n, a;
    cout << "dati numarul de linii si coloane: ";
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    a = 0;
    afla(mat, m, n, 0, 0, a);
    cout << a;
}*/


//2
/*void afla(int mat[10][10], int m, int n, int i, int j, int& max)
{
    if (i == m - 1 && j == n)
        return;
    if (j == n && i < m)
    {
        j = 0;
        i++;
    }
    if (max < mat[i][j])
        max = mat[i][j];
    afla(mat, m, n, i, j + 1, max);
}

int main()
{
    int mat[10][10], i, j, m, n, max;
    cout << "dati numarul de linii si coloane: ";
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cout << "mat[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    max = mat[0][0];
    afla(mat, m, n, 0, 1, max);
    cout << max;
}*/


//3
/*void impar(int a, int b, int c)
{
    if (a == 9 and b == 9 and c == 11)
        return;
    if (b == 9 and a < 9)
    {
        b = 1;
        a = a + 2;
    }
    if (c == 11 and b < 9)
    {
        c = 1;
        b = b + 2;
    }
    cout << a << b << c << " ";
    impar(a, b, c + 2);
}

int main()
{
    impar(1, 1, 1);
}*/


/*int verifica(int nr)
{
    int cont;
    cont = 0;
    while (nr != 0 && cont == 0)
    {
        if ((nr % 10) % 2 == 0)
            cont = 1;
        nr = nr / 10;
    }
    return cont;
}

void numar(int min, int max)
{
    if (min == max)
        return;
    if (verifica(min) == 0)
        cout << min << " ";
    numar(min + 1, max);
}

int main()
{
    int min, max, a, b;
    cin >> min >> max;
    a = 1;
    b = 1;
    while (min > 0)
    {
        a = a * 10;
        min--;
    }
    while (max > 0)
    {
        b = b * 10;
        max--;
    }
    numar(a, b);
}*/



//SIII - 3
/*int main()
{
    int n1, n2, x, y, cont, i1, i2;
    ifstream bac1("bac1.txt");
    if (!bac1)
    {
        cout << "bac1 nu exista";
        return -1;
    }
    ifstream bac2("bac2.txt");
    bac1 >> n1;
    bac2 >> n2;
    cont = 0;
    i1 = 1;
    i2 = 1;
    bac1 >> x;
    bac2 >> y;
    while (i1 <= n1 && i2 <= n2)
        if (x < y)
        {
            if (x % 5 == 0)
            {
                cout << x << " ";
                cont = 1;
            }
            bac1 >> x;
            i1++;
        }
        else
        {
            if (y % 5 == 0)
            {
                cout << y << " ";
                cont = 1;
                bac2 >> y;
            }
            bac2 >> y;
            i2++;
        }
    while (i1 <= n1)
    {
        if (x % 5 == 0)
        {
            cout << x << " ";
            cont = 1;
        }
        bac1 >> x;
        i1++;
    }
        
    while (bac2 >> y)
    {
        if (y % 5 == 0)
        {
            cout << y << " ";
            cont = 1;
        }
        bac2 >> y;
        i2++;
    }

       if (cont == 0)
           cout << "nu exista";
       bac1.close();
       bac2.close();
       return 0;
}*/



// TESTUL 10
// 3. Y(8, 12, 19, 30, 52)


// TESTUL 12
// 2.



//SIII
//1.
/*int rest(int x, int y, int n)
{
    int k, i;
    k = 0;
    for (i = n; i >= min(x, y) && k == 0; i--)
        if (i % x == 2 && i % y == 2)
            k = i;
    return k;
}

int main()
{
    int x, y, n;
    cout << "dati numerele x, y si n in acesta ordine: ";
    cin >> x >> y >> n;
    cout << rest(x, y, n);
    return 0;
}*/



//2.
/*int main()
{
    char inv[250], caut[15];
    char* num, *prn;
    cout << "Dati numele invitatilor: ";
    cin.getline (inv, 250);
    cout << "Dati numele cautat: ";
    cin >> caut;
    num = strtok(inv, " ");
    prn = strtok(NULL, ";");
    while (num != NULL && prn != NULL)
    {
        if (strcmp(caut, num) == 0)
            cout << prn << " ";
        num = strtok(NULL, " ");
        prn = strtok(NULL, ";");
    }
    return 0;
}*/



//3.
/*int main()
{
    int n, i, x;
    double nr;
    fstream fout("bac.txt");
    cout << "Dati numarul n: ";
    cin >> n;
    nr = 1;
    for (i = 1; i <= n; i++)
        nr = nr * i;
    a = 45;
    x = 0;
    while (nr / 45 == int(nr / 45))
    {
        x++;
        nr = nr / 45;
    }
    fout << x;
    fout.close();
    return 0;
}*/