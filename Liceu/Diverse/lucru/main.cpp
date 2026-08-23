#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

///T7
///SI
/*
1. c
2. b
3. d
bein
beni
bien
bine
bnei
bnie
ebin
4. a
5. b
*/
///SII
/*
1.
a. 27596
b. 74, 54, 10, 0
c.
#include <iostream>
using namespace std;

int main()
{
    unsigned int x, n, c, y;
    cin >> x;
    while(x != 0)
    {
        y = x;
        c = 0;
        while(y > 0)
        {
            if(y % 10 > c)
                c = y % 10;
            y = y / 10;
        }
        n = n * 10 + c;
        cin >> x;
    }
    cout << n;
    return 0;
}
d.
citește x (număr natural)
n <- 0
┌daca x ≠ 0 atunci
│┌repeta
││ y <- x; c <- 0
││ ┌cât timp y > 0 execută
││ │ ┌dacă y % 10 > c atunci
││ │ │ c <- y % 10
││ │ └■
││ │ y <- [y/10]
││ └■
││ n <- n*10+c
││ citește x (număr natural)
│└pana cand x = 0
└■
scrie n

2.
if(e.dataNasterii.an > dataEvenimet.an)
    cout << "ulterior";
else if(e.dataNasterii.luna > dataEvenimet.luna)
        cout << "ulterior";
    else if(e.dataNasterii.zi > dataEvenimet.zi)
            cout << "ulterior";
        else
            cout << "nu";

3. BDUED
s = ADCDUECDA
i = 2
j = 2
t =
s = BDUED
*/
///SIII
/*
1.
void afisare(int x, int y, int k)
{
    int i, ck;
    ck = k;
    for(i = x; i <= y; i++)
        if(ck == 0)
        {
            ck = k;
            i--;
            cout << "* ";
        }
        else
        {
            cout << i << " ";
            ck--;
        }
    cout << "*";
}
int main()
{
    int x, y , k;
    cin >> x >> y >> k;
    afisare(x, y, k);
}
2.
int main()
{
    int mat[100][100], i, j, n, x, k;
    cin >> x;
    i = x;
    n = 0;
    while(i != 0)
    {
        i = i / 10;
        n++;
    }
    k = 10;
    for(i = 0; i < n; i++)
    {
        for(j = n - 1; j >= 0; j--)
        {
            mat[i][j] = (x % k)/(k / 10);
            k = k * 10;
        }
        k = 10;
    }
}
3.
a. Voi intoduce intr-un vector toate cifrele si o sa le sterg pe cele impare dupa aceea o sa le sortez crescator apoi voi afisa vectorul;
b.
int main()
{
    int i, j, n, s, nr, v[100];
    ifstream fin("bac.txt");
    n = 0;
    while(fin >> v[n])
        n++;
    for(i = 0; i < n; i++)
        if(v[i] % 2 == 1)
        {
            for(j = i; j < n - 1; j++)
                v[j] = v[j + 1];
            n--;
            i--;
        }
    s = 1;
    while(s == 1)
    {
        s = 0;
        for(i = 0; i < n - 1; i++)
            if(v[i] > v[i + 1])
            {
                nr = v[i];
                v[i] = v[i + 1];
                v[i + 1] = nr;
                s = 1;
            }
    }
     for(i = 0; i < n; i++)
            cout << v[i] << " ";
}

int main()
{
    ifstream fin("bac.txt");
    int v[10]={0}, i;
    while(fin >> i)
        v[i]++;
    for(i = 0; i < 10; i++)
        if(i % 2 == 0 && v[i] != 0)
        {
            cout << i << " ";
            v[i]--;
            i--;
        }
}*/



///8
///SI
/*
1. c
2. d
3. b
{camasa, cravata, sacou, pantaloni, sosete, pantofi}
{camasa, cravata, sacou, sosete, pantaloni, pantofi}
{camasa, cravata, pantaloni, sacou, sosete, pantofi}
{camasa, cravata, pantaloni, sosete, pantofi, sacou}
{camasa, cravata, pantaloni, sosete, sacou, pantofi}
{camasa, cravata, sosete, pantaloni, sacou, pantofi}
{camasa, cravata, sosete, sacou, pantaloni, pantofi}
{camasa, cravata, sosete, pantaloni, pantofi, sacou}
4. c
5. d
*/
///SII
/*
1.
a. 440
b. 6, 13
c.
int main()
{
    int x, i, n;
    cin >> n;
    x = 0;
    for(i = 1; i <= n; i++)
        if(i % 2 == 0)
            x = x + i * i;
        else
            x = x + (i + 1) * (i + 1);
    cout << x;
}
d.
citește n (număr natural)
x <- 0
i <- 1
┌cat timp i <= n executa
│ ┌dacă i%2=0 atunci
│ │ x <- x+i*i
│ │altfel
│ │ x <- x+(i+1)*(i+1)
│ └■
│  i <- i + 1
└■
scrie x
2.
struct clasa
{
   unsigned int numar;
   struct e
   {
       float sem1, sem2;
   } elev[40];

}p;
3.
s = volt
i = 6
aux = ta

cout 7volt
*/
///SIII
/*
1.
int prim(int n)
{
    int i;
    for(i = 2; i <= n / 2; i++)
        if(n % i == 0)
        {
            return 0;
        }
    return 1;
}
int nrfp(int n)
{
    int m, i, j, nr, k, maxk;
    k = 0;
    maxk = 0;
    for(i = 0; i <= n; i++)
    {
        nr = 0;
        for(j = 2; j <= i; j++)
            if(i % j == 0 && prim(j) == 1)
                nr++;
        if(nr >= maxk)
        {
            k = i;
            maxk = nr;
        }
    }
    return k;
}
int main()
{
    int n;
    cin >> n;
    cout << nrfp(n);
}
2.
int main()
{
    int mat[50][50], n, i, j, s;
    ifstream  fin("bac.txt");
    fin >> n;
    s = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            fin >> mat[i][j];

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(i < j && i + j > n-1 && j < n-1) {
                s = s + mat[i][j];
            }
    // diag sec. = i+j==n-1
    for(i = 2; i < n / 2; i++)
        for(j = n - i; j < n - 2; j++)
            s = s + mat[i][j];
    for(i = n / 2; i < n - 2; i++)
        for(j = i + 1; j < n - 2; j++)
            s = s + mat[i][j];
    cout << s;
}

i = 0; i < n - 2
j = i + 1; j < n - 1

i = 1; i < n -1
j = n - 1; j < n - 1


i = 2; i < n / 2; i++
j = n - i; j < n - 2; j++

i = n / 2; i < n - 2; i++
j = i + 1; j < n - 2; j++


3.
a. Se vor introduce toate numere impare intr-un vector si se vor afisa ultmile doua numere, dar daca sunt mai putin de doua se va afisa mesajul "nu exista".
b.
int main()
{
    ifstream fin ("bac.txt");
    int n, a, b, i;
    n = 0;
    a = 0;
    b = 0;
    while(fin >> i)
        if(i % 2 == 1)
        {
            a = b;
            b = i;
        }
    if (a != 0 && b != 0)
        cout << a << " " << b;
    else
        cout << "nu exista";
}
*/
///T9
///SI
/*
1. a
x = (x / 10 * 10 + 4) * 10 + x % 10
2. c
{salcie, carpen, larice, fag, ulm}
{s, c, l, f, u}1 2 3 4 5
{s, c, l, u, f}1 2 3 5 4
{s, c, f, l, u}1 2 4 3 5
{s, c, f, u, l}1 2 4 5 3
{s, c, u, l, f}1 2 5 3 4
{s, c, u, f, l}1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5
1 4 2 5 3
1 4 3 2 5
1 4 3 5 2
1 4 5 2 3
1 4 5 3 2
...
[5 4 2 3 1]{u, f, c, l, s}
5 4 3 1 2
5 4 3 2 1
3. d
4. a
vectorul de tati
{1, 2, 3, 4, 5, 6, 7, 8}
{0, 0, 1, 2, 3, 3, 1, 1}
5. b
*/
///SII
/*
1.
a. +++@
b. 4,5
c.
int main()
{
    unsigned int n, i, j;
    cin >> n;
    nr = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = i; j <= n; j++)
            cout << "+";
        if(i % 2 == 0)
            cout << "@";
    }
}
d.
citeşte n
(număr natural nenul)
┌pentru i <- 1, n execută
│ j <- i
│┌cat timp j <= n executa
││ scrie ’+’
││ j <- j + 1
│└■
│┌dacă i % 2 ≠ 0 atunci
││ scrie ’@’
│└■
└■
2. 1, 9
f(10, 1)
10/1+
f(9, 1)
9/1+
f(8, 1)
8/1+
. . .
f(2, 1)
2/1+
f(1, 1)
1/1+
3.
{
    if(a[i][j - 1] < 2 && j > 0)
        a[i][j] = a[i][j - 1] + 1;
    if(j == 4)
        a[i + 1][0] = a[i][j];
}
*/
///SIII
/*
1.
void divizor(int a, int b, int k)
{
    int nr, i;
    nr = 0;
    for(i = a; i <= b; i++)
        if(i % k == 0 && i % 10 == k)
            nr++;
    cout << nr;
}
2.
int da(int v[5])
{
    int i, nr;
    nr = 0;
    for(i = 0; i < 5; i++)
        if(v[i] == 1)
            nr++;
    if(nr > 1)
        return 0;
    else
        return 1;
}

int main()
{
    int v[5] = {0}, i;
    char s[100];
    cin.getline(s, 100);
    char* cuv;
    cuv = strtok(s, " ");
    while(cuv != NULL)
    {
        if(strchr(cuv, 'a') != NULL)
            v[0]++;
        if(strchr(cuv, 'e') != NULL)
            v[1]++;
        if(strchr(cuv, 'i') != NULL)
            v[2]++;
        if(strchr(cuv, 'o') != NULL)
            v[3]++;
        if(strchr(cuv, 'u') != NULL)
            v[4]++;
        if(da(v) == 1)
            cout << cuv << endl;
       cuv = strtok(NULL, " ");
       for(i = 0; i < 5; i++)
            v[i] = 0;
    }
}

int main()
{
    int v[10]={0}, n, i;
    ifstream fin("bac.txt");
    while(fin >> n)
        while(n != 0)
        {
            v[n % 10]++;
            n = n / 10;
        }
    for(i = 9; i >= 0; i--)
        if(v[i] > 1)
        {
            cout << i;
            v[i]--;
            i++;
        }
}*/


///T10
///SI
/*
1. b
2. c
3. b
4. d
5. c
*/
///SII
/*
1.
a.ABABABAB
b.20, 19
c.
#include <iostream>
using namespace std;

int main()
{
    unsigned int x, y;
    cin >> x >> y;
    if(x < y)
    {
        x = x - y;
        y = x + y;
        x = y - x;
    }
    while(x >= y)
    {
        cout << "A";
        x = x - y;
        if(x % 2 == 0)
            cout << "A";
        else
            cout << "B";
    }

}
d.
citeşte x, y (numere naturale)
┌dacă x < y atunci
│ x <- x - y; y <-x + y; x <- y - x
└■
┌daca x >= y
│┌repeta
││ scrie ’A’
││ x <- x - y
││┌dacă x % 2 = 0 atunci scrie ’A’
│││altfel scrie ’B’
││└■
│└pana cand x < y
└■
2.struct elev
{
    int cod;
    float nota1, nota2;
}y[30];
3. pom
   verde
*/
///SIII
/*
1.
int armonie(int x, int y)
{
    int a, b, d;
    a = x + 1;
    b = y + 1;
    for(d = 2; d <= x / 2; d++)
        if(x % d == 0)
            a = a + d;
    for(d = 2; d <= y / 2; d++)
        if(y % d == 0)
            b = b + d;
    if(a < b)
        if(y + x > a && y + x < b)
            return 1;
        else
            return 0;
    else
        if(y + x < a && y + x > b)
            return 1;
        else
            return 0;
}
int main()
{
    int x, y;
    cin >> x >> y;
    if(armonie(x, y) == 1)
        cout << "armonie";
    else
        cout << "nu";
}
2.
int main()
{
    int mat[20][20], m, n, i, j;
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    for(j = 0; j < n - 1; j++)
        for(i = m - 1; i > 0; i--)
            if(mat[0][j] == mat[i][n - 1])
            {
                cout << mat[0][j] << " ";
                i = 0;
            }
    return 0;
}
3.
int main()
{
    ifstream fin ("bac.txt");
    int k, nr, p;
    p = 1;
    fin >> nr;
    while(fin >> k)
        if(k < nr)
         p++;
    cout << p;
}*/



///T11
///SI
/*
1. c
2. d
3. a
4. c
5. d
1020
1021
1022
11
110
1100
1101
1102
111
1110
1111
1112
112
1120
1121
1122
12
120
1200
1201
1202
121
1210
1211
1212
122
1220
1221
1222
2
20
200
2000
2001
2002
201
2010
2011
2012
202
2020
21
210
211
212
22
220
221
222
*/
///SII
/*
1.
a. ****
m = 11
n = 9
b. 1, 158
c.
int main()
{
    unsigned int m, n;
    cin >> m >> n;
    if(m > n)
        swap(m, n);
    if(m % 2 == 0)
        m = m + 1;
    while(m <= n)
    {
        m = m + 2;
        cout << "*";
    }
}
d.
citește m, n (numere naturale)
┌dacă m > n atunci
│ n <-> m
└■
┌dacă m % 2 = 0 atunci
│ m <- m + 1
└■
┌daca m <= n atunci
│┌repeta
││ m <- m + 2
││ scrie ‘*’
│└pana cand m > n
└■
2.f(2) return 2
  f(21) return 10
3.cout: 2021
        b!a!c!
*/
///SIII
/*
1.
void imog(int x, int y, int &rez)
{
    int a, b, p;
    a = 0;
    b = 0;
    p = 1;
    while(x != 0)
        if(x%2 == 1)
        {
            a = a * 10 + x % 10;
            x = x / 10;
        }
        else
            x = x / 10;
    while(y != 0)
        if(y%2 == 1)
        {
            b = b + (y % 10) * p;
            p = p * 10;
            y = y / 10;
        }
        else
            y = y / 10;
    if(a == b)
        rez = 1;
}
int main()
{
    int x, y, rez;
    cin >> x >> y;
    rez = 0;
    imog(x, y, rez);
    cout << rez;
}
2.
int main()
{
    int mat[20][20], i, j, n, k;
    cin >> n >> k;
    k--;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    for(i = 0; i < k; i++)
    {
        mat[i][k] = mat[i][k] + mat[k][i];
        mat[k][i] = mat[i][k] - mat[k][i];
        mat[i][k] = mat[i][k] - mat[k][i];
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
3.
a. Se afla n cu ajutorul formulei si numerelor
citite de la tastatura, apoi se afiseaza in fisierul
"bac.out" cu ajutorul unui "for" si formulei.
b.
int main()
{
    int n, x, y, i;
    ofstream fout("bac.txt");
    cin >> x >> y;
    n = (y - x) / 2;
    fout << y << " " << x << " ";
    for(i = n - 1; i >= 1; i--)
    {
        fout << x - 2 * i << " ";
        x = x - 2 * i;
    }
    return 0;
}
*/


///T12
///SI
/*
1. c
2. a
3. d
4. b
5. c
*/
///SII
/*
1.
a. 2 2 4 4 9
b. 19, 23
c.
#include <iostream>
using namespace std;

int main()
{
    int n, k, t, i, j;
    cin >> n >> k;
    t = 1;
    for(i = 1; i <= int(n / k); i++)
    {
        for(j = 1; j <= k; j++)
            cout << 2 * t << " ";
        t = t + 1;
    }
    for(i = n % k; i >= 1; i--)
        cout << 3 * t << " ";
}
d.
citește n,k
(numere naturale nenule)
t <- 1
┌pentru i <- 1,[n/k] execută
│┌pentru j <- 1,k execută
││ scrie 2*t,' '
│└■
│ t <- t+1
└■
i <- n % k
┌cat timp i >= 1 execută
│ scrie 3*t,' '
│ i <- i - 1
└■
2.
lant elementar 1, 6, 3, 5, 4
ciclu neelementar 4, 2, 1, 6, 2, 4
3.
for(i = 0; i < strlen(s); i++)
    if(strchr("OAU", s[i]) != NULL)
        cout << "*";
    else
        cout << s[i];
*/
///SIII
/*
1.
void frate(int x, int &y)
{
    int p;
    p = 1;
    while(x != 0)
        if(x % 10 == 9)
        {
            y = -1;
            return;
        }
        else
        {
            y = y + (x % 10 + 1) * p;
            p = p * 10;
            x = x / 10;
        }
}
int main()
{
    int x, y;
    cin >> x;
    y = 0;
    frate(x, y);
    cout << y;
}
2.
int main()
{
    int mat[20][20], i, j, n, k;
    cin >> n >> k;
    k--;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    for(i = n - k - 2; i > 0; i--)
    {
        mat[k][i] = mat[k][i] + mat[k][i - 1];
        mat[k][i - 1] = mat[k][i] - mat[k][i - 1];
        mat[k][i] = mat[k][i] - mat[k][i - 1];
    }
    cout << endl;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
3.
a.Se citeste primul numar, apoi cu un ajutorul unui "while", care citeste din fisier, verific daca numarul
introdus este mai mare sau egal, daca este un contor va aduna plus unu.
b.
int main()
{
    ifstream fin ("bac.txt");
    int k, nr, p;
    p = 1;
    fin >> nr;
    while(fin >> k)
        if(k >= nr)
         p++;
    cout << p;
}
*/




///SIMULARE 2022
///SI
/*
1. d
!(x > 3) || !(x <= 30)
2. b
f(0, 4, v)
    return f(0, 2, v) + f(3, 4, v) = 3
    f(0, 2, v) = 2
        return f(0, 1, v) + f(2, 2, v) = 2
        f(0, 1, v) = 1
            return f(0, 0, v) + f(1, 1, v) = 1
                f(0, 0, v)
                    return 0;
                f(1, 1, v)
                    return 1;
        f(2, 2, v)
            return 1;
    f(3, 4, v) = 1
        return f(3, 3, v) + f(4, 4, v) = 1
        f(3, 3, v)
            return 0;
        f(4, 4, v)
            return 1;
3. c
{A, B, C, R, S, V}
{1, 2, 3, 4, 5, 6}
(3)   C = lider
(1/6) A/V = lider/secund
(2)   B = secund
{lider, secund, vice-skip, skip}
(1, 2, 4, 5)
(1, 2, 5, 6)
(1, 6, 4, 5)
(1, 6, 5, 4)
(3, 1, 4, 5)
(3, 1, 5, 4)
(3, 2, 4, 5)
(3, 2, 5, 4)
(3, 6, 4, 5)
(3, 6, 5, 4) = {C, V, S, R}
(6, 1, 4, 5) = {V, A, R, S}
4. a
oras[0].nrLocuitori/oras[0].suprafata
5. c
*/
///SII
/*
a.
n = 6
x = 16
y = 4273
nr = 3
b. 2233, 2255
c.
int main()
{
    int n, x, nr = 0, i = 1, y;
    cin >> n >> x;
    while(i <= n)
    {
        cin >> y;
        while(y != 0 && y % 2 != x % 2)
            y = y / 10;
        if(y == x)
            nr = nr + 1;
        i = i + 1;
    }
    cout << nr;
}
d.
citește n,x (numere naturale nenule)
nr <- 0
┌pentru i <- 1, n executa
│ citește y (număr natural)
│┌cât timp y ≠ 0 și y % 2 ≠ x % 2 execută
││ y <- [y/10]
│└■
│┌dacă y = x atunci nr <- nr + 1
│└■
└■
scrie nr
2.
1, 4, 6
3.
ok = 0;
for(j = 1; j < 14; j++)
    if(a[0][j] == a[1][j - 1] && a[1][j - 1] == a[2][j] && a[2][j] == a[1][j + 1])
    {
        ok = 1;
        j = 14;
    }
*/
///SIII
/*
1.
void rest(int x, int y, int n, int &k)
{
    int i;
    for(i = n; i >= 2; i--)
        if(i % x == 2 && i % y == 2)
        {
            k = i;
            return;
        }
}
int main()
{
    int x, y, n, k;
    cin >> x >> y >> n;
    k = 0;
    rest(x, y, n, k);
    cout << k;
}
2.
int main()
{
    char *nume, inv[251], x[10];
    cin.getline(inv, 251);
    cin >> x;
    nume = strtok(inv, " ");
    while(nume != NULL)
    {
        if(strcmp(nume, x) == 0)
            cout << strtok(NULL, ";") << " ";
        nume = strtok(NULL, " ");
    }
}
3.
a.
b.
int main()
{
    int p, i, kp;
    long long int n, nr, k;
    ofstream fout("bac.txt");
    cin >> n;
    p = 0;
    nr = 2;
    k = 45;
    kp = 1;
    for(i = 3; i <= n; i++)
        nr *= i;
        cout << nr << endl;
    while(k <= nr)
    {
        cout << k << " " << kp << " " << p << endl;
        if(nr % k == 0)
            p = kp;
        k = k * 45;
        kp++;
    }
    fout << p;
}

int main()
{
    ifstream fin("bac.txt");
    int n, i = 0, p1 = 0, p2 = 0;
    while(fin >> n)
    {
        i++;
        if(n < 0 && p1 == 0)
            p1 = i;
        if(n < 0)
            p2 = i;
    }
    if(i - p1 > p2)
        cout << i - p1 + 1;
    else
        cout << p2 + 1;
}
*/

/*struct cuvant
{
    char rom[10], engl[10];
}cuv[100];

int main()
{
    ifstream fin("dex.txt");
    char *p, s[100];
    int n = 0, i, ok;
    float nr = 0, t = 0;
    cin.getline(s, 100);
    while(fin >> cuv[n].rom)
    {
        fin >> cuv[n].engl;
        n++;
    }
    p = strtok(s, " ");
    while(p != NULL)
    {
        t++;
        ok = 0;
        for(i = 0; i < n; i++)
            if(strcmp(p, cuv[i].rom) == 0)
            {
                cout << cuv[i].engl << " ";
                ok = 1;
                nr++;
                break;
            }
        if(ok == 0)
            cout << "(" << p << ") ";
        p = strtok(NULL, " ");
    }
    cout << endl << nr * (100 / t) << "% din cuvinte traduse";
}*/

/*int main()
{
    ifstream fin("bac.txt");
    int s, smax, k;
    fin >> s;
    smax = s;
    while(fin >> k)
    {
        s += k;
        if(s > smax)
            smax = s;
        else if(k > smax)
            {
                smax = k;
                s = k;
            }
    }
    cout << smax;
}*/

/*int main()
{
    int x, s, s_max, reset;
    ifstream f_in("bac.txt");
    f_in >> s;
    s_max = s;
    reset = 0;
    while(f_in >> x)
    {
        if (x < 0 && reset == 0)
        {
            s = s + x;
            if (s < 0)
            {
                s = x;
                reset = 1;
            }
        }
        else
        {
            if(reset == 1)
                s = 0;
            s = s + x;
            reset = 0;
        }
        if (s > s_max)
        {
            s_max = s;
        }
    }

    cout << s_max;
    return 0;
}*/
///T4
///SII
/*
1.
c.
int main()
{
    unsigned int n;
    int c1, c2;
    cin >> n;
    do
    {
        c1 = n % 10;
        n = n / 10;
        c2 = n % 10;
        if(c1 > c2)
        {
            c2 = c1;
            c1 = n % 10;
        }
        while(c1 < c2)
        {
            cout << c1;
            c2 = c2 / 2;
        }
    }while(n > 9);
}
*/
///SIII
//1.
/*void generatoare(int n)
{
    int i, j;
    for(i = 0; i <= n; i++)
        for(j = n; j >= 1; j--)
            if(i * j + int(i / j) == n && i % 2 == 0)
                cout << i << "-" << j << " ";
}

int main()
{
    int n;
    cin >> n;
    generatoare(n);
}*/

//2
/*int main()
{
    int i, j, m, n, mat[20][20], ok = 0, nr = 0;
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    for(j = 1; j < n; j++)
    {
        ok = 0;
        for(i = 0; i < m; i++)
            if(mat[i][0] == mat[i][j])
            {
                ok = 1;
                i = m;
            }
        if(ok == 0)
            nr++;
    }
    cout << nr;
}*/

//3
/*int main()
{
    int k , nr = 1, c;
    ifstream fin("bac.txt");
    fin >> c;
    while(fin >> k)
    {
        if(c == k)
            nr++;
        else
        {
            if(nr == 2)
                cout << c << " ";
            c = k;
            nr = 1;
        }
    }
    if(nr == 2)
                cout << c << " ";
}*/
