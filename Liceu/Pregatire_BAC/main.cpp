#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

///BAC 2023

///SI
///1 d
/*
a = 460 / 4 = 115
b = 20/2*23/2 = 115
c = (20*23) / 2 = 230
d = (20*23)/2*2 = 460
*/

///2 010111 c
/*
f(23)
cout << 23%2 = 1
    f(11)
    cout << 11%2 = 1
        f(5)
        cout << 5%2 = 1
            f(2)
            cout << 2%2 = 0
                f(1)
                cout << 1%2 = 1
                    f(0)
                    cout << 0%2 = 0
*/


///3 c
/*
s = bac2023
s[2] = '\0';
k = 2
*/


///4 b
/*
a
1 2 3 4 5 6 7
0 1 2 1 1 1 2

b
1 2 3 4 5 6 7
3 0 2 1 3 2 1

c
1 2 3 4 5 6 7
4 3 0 3 4 4 3

d
1 2 3 4 5 6 7
5 4 3 0 2 3 4
*/


///5 a
/*
1, 3, 5 = mere
2, 4 = pere
6 = piersici

6 -> 1 -> 5 -> 2
          5 -> 4
*/


///SII
///1
///a 9752
/*
x = 6907512
p = 1
m = -1

c = 2

m = 2
p = 10

c = 1

x = 69075*10 + 2 = 690752

c = 5

m = 5
p = 100

c = 7

m = 7
p = 1000

c = 0

x = 69*1000 + 752 = 69752

c = 9

m = 9
p = 10000

c = 6

x = 0 * 10000 + 9752 = 9752


scrie 9752
*/

///b 321 654

///c
/*
#include <iostream>

using namespace std;

int main()
{
    int p, m, c, x;

    cin >> x;

    p = 1;
    m = -1;

    while(p <= x){
        c = (x / p) % 10;
        if(c > m){
            m = c;
            p = p * 10;
        }
        else
            x = (x / (p * 10)) * p + x % p;
    }

    if(m >= 0)
        cout << x;
    else
        cout << "nul";

    return 0;
}
*/

///d
/*
citeşte x (număr natural)
p -> 1; m ->  -1
┌repetă
│ c -> [x / p] % 10
│┌dacă c>m atunci
││ m -> c; p -> p*10
││altfel
││ x -> [x / (p * 10)]* p + x % p
│└■
└până când p > x
┌dacă m >= 0 atunci scrie x
│ altfel scrie "nul"
└■
*/


///2 (mare, rau), (ocean, ploaie, rau)
/*
{lac, mare, ocean, ploaie, rau}
{l, m, o, p, r}
dulce - l, p, r
sarata - m, o

(l, m)
(l, m, p)
(l, m, r)
(l, o)
(l, o, p)
(l, o, r)
(m, p)
(m, p, r)
(m, r)
(o, p)
(o, p, r)
*/


///3
/*
struct lalea{
    char denumire[20];
    struct stoc{
        int nrFire, pretFir;
    };
}f[10];
*/


///SIII
///1
/*
#include <iostream>

using namespace std;

int abundent(int n){
    int k, d;
    float s = 0, Sn = 0;

    for(d = 1; d <= n; d++)
        if(n % d == 0)
            s += d;

    Sn = s / n;

    for(k = 0; k < n; k++){
        s = 0;
        for(d = 1; d <= k; d++)
            if(k % d == 0)
                s += d;
        if(Sn <= s / k)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    cin >> n;

    if(abundent(n) == 1)
        cout << "numarul " << n << " este un numar abundent";
    else
        cout << "numarul " << n << " nu este un numar abundent";
}*/


///2
/*
#include <iostream>

using namespace std;

int main()
{
    int np, ns, m[1001][51], i, j, a;

    cin >> ns >> np;

    for(i = 1; i <= np; i++)
        for(j = 1; j <= ns; j++)
            cin >> m[i][j];

    for(i = 1; i <= np; i++){
        a = 1;
        for(j = 1; j <= ns; j++)
            if(m[i][j] > m[i][a])
                a = j;
        cout << " " << i << ":" << a << " ";
    }
}*/

/*
4 6

2 4 5 3
2 6 6 3
1 5 2 5
1 3 3 3
3 4 3 5
0 1 2 1
*/


///3
/*
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("bac.txt");

    int m[2][10000], i, j, n = 0, x, pre, suf, nr = 0;

    while(fin >> x){
        if(x > 99 && x < 1000){
            m[0][n] = x / 10;
            m[1][n] = x % 100;
            n += 1;
        }

        if(x > 999 && x < 10000){
            m[0][n] = x / 100;
            m[1][n] = x % 100;
            n += 1;
        }

    }


    for(i = 0; i < n; i++){
        pre = 0;
        suf = 0;
        for(j = 0; j < n; j++){
            if(m[0][i] == m[0][j] && m[0][i] != 0)
                pre += 1;

            if(m[0][i] == m[1][j] && m[0][i] != 0)
                suf += 1;
        }
        m[0][i] = 0;

        if(suf == pre){
            nr += 1;
        }
    }

    cout << nr;

    return 0;
}*/


///Admitere universitate 2023

///1 a.315
/*
n = 22
val = 0

k = 1

i = 1

val = 1

A[1][1] = 1

i = 2

val = 2

A[2][2] = 2
...

i = 18

val = 18

A[18][18] = 18
...
i = 21

val = 21

A[21][21] = 21


i = 1

val = 22

A[1][22] = 22

i = 2

val = 23

A[2][22] = 23

i = 3

val = 24

A[3][22] = 24

...

i = 21

val = 42

A[21][22] = 42



i = 22

val = 43

A[22][22] = 43

i = 21

val = 44

A[22][21] = 44

i = 20

val = 45

A[22][20] = 45
...


i = 1

val = 63

A[22][1] = 63


i = 21

val = 64

A[21][1] = 64

i = 20

val = 65

A[20][1] = 65

i = 19

val = 66

A[19][1] = 66
...


i = 2

val = 82

k = 1 (84)

for1 = val + 21

for2 = val + 21

for3 = val + 22

for4 = val + 20


k = 2 (76)

for1 = val + 19

for2 = val + 19

for3 = val + 20

for4 = val + 18


k = 3 (68)

for1 = val + 17

for2 = val + 17

for3 = val + 18

for4 = val + 16



k = 4 (60)

for1 = val + 15

for2 = val + 15

for3 = val + 17

for4 = val + 13


k = 5 (41)

for1 = val + 13

for2 = val + 13

for3 = val + 15

*/



/*int main()
{
    int n, val, m[23][23], k, i, j;

    n = 22;
    val = 0;

    for(k = 1; k <= (n+1)/2; k++){
        for(i = k; i <= n - k; i++){
            val += 1;
            m[k][i] = val;
        }

        for(i = k; i <= n - k; i++){
            val += 1;
            m[i][n-k+1] = val;
        }

        for(i = n-k+1; i >= k; i--){
            val += 1;
            m[n-k+1][i] = val;
        }

        for(i = n - k; i >= k + 1; i--){
            val += 1;
            m[i][k] = val;
        }
    }

    cout << m[18][18] << endl;
    for(i = 1; i <= 22; i++){
        cout << endl;
        for(j = 1; j <= 22; j++){
            cout << m[i][j] << " ";
            //cout << i << " : " << j << "  " << m[i][j] << endl;
        }

    }
}*/

// col 22: 4 * 21
// col 21: 4 * 19
// col 20: 4 * 17
// col 19: 4 * 15
// col 18: 13+14
// Total: 288



///2 c.13

///3 c. (n-1)*(y-x+1)
///problema este bazata pe algoritmul bubble sort
/*
n > 5
x = [1, n]
y = [1, n]

ex: n = 6, x = 3, y = 5

i = 1
v[1] = 10

i = 2
v[2] = 20

i = 3
v[3] = 30

i = 4
v[4] = 40

i = 5
v[5] = 50

i = 6
v[6] = 60

a = 30
v[3] = 50 (v[5])
v[5] = 30 (a)

v[1] = 10
v[2] = 20
v[3] = 50
v[4] = 40
v[5] = 30
v[6] = 60

v[1] = 10
v[2] = 20
v[3] = 30
v[4] = 40
v[5] = 50
v[6] = 60


k = 1
rez = 0

k = 0
i = 1

i = 2
rez = 1

i = 3


a = 50
v[3] = 40 (v[4])
v[4] = 50 (a)
k = 1

rez = 2

i = 4

a = 50
v[4] = 30 (v[5])
v[5] = 50 (a)
k = 1

rez = 3

i = 5
rez 4

k = 0
i = 1

i = 2
rez = 5

i = 3

a = 40
v[3] = 30 (v[4])
v[4] = 40 (a)
k = 1

rez = 6

i = 4
rez = 7

i = 5
rez = 8

i = 1
k = 0

i = 2
rez = 9

i = 3
rez = 10

i = 4
rez = 11

i = 5
rez = 12

rez = 12
*/


///4 a.89
/*
1 0 1 0 1 0 1 0 1 0
1 0 1 0 1 0 1 0 0 1
1 0 1 0 1 0 1 0 0 0
1 0 1 0 1 0 0 1 0 1
1 0 1 0 1 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0
1 0 1 0 1 0 0 0 0 0
1 0 1 0 0 1 0 1 0 1
1 0 1 0 0 1 0 1 0 0
1 0 1 0 0 1 0 0 0 1
1 0 1 0 0 1 0 0 1 0
1 0 1 0 0 0 1 0 1 0
1 0 1 0 0 0 1 0 0 0
1 0 1 0 0 0 0 1 0 1
1 0 1 0 0 0 0 1 0 0
1 0 1 0 0 0 0 0 1 0
1 0 1 0 0 0 0 0 0 1
1 0 1 0 0 0 0 0 0 0
1 0 0 1 0 1 0 1 0 1
1 0 0 1 0 1 0 1 0 0
1 0 0 1 0 1 0 0 1 0
1 0 0 1 0 1 0 0 0 0
1 0 0 1 0 0 1 0 1 0
1 0 0 1 0 0 1 0 0 1
1 0 0 1 0 0 1 0 0 0
1 0 0 1 0 0 0 1 0 1
1 0 0 1 0 0 0 1 0 0
1 0 0 1 0 0 0 0 1 0
1 0 0 1 0 0 0 0 0 0
1 0 0 0 1 0 1 0 1 0
1 0 0 0 1 0 1 0 0 1
1 0 0 0 1 0 1 0 0 0
1 0 0 0 1 0 0 1 0 1
1 0 0 0 1 0 0 1 0 0
1 0 0 0 1 0 0 0 1 0
1 0 0 0 1 0 0 0 0 1
1 0 0 0 1 0 0 0 0 0
1 0 0 0 0 1 0 1 0 1
1 0 0 0 0 1 0 1 0 0
1 0 0 0 0 1 0 0 1 0
1 0 0 0 0 1 0 0 0 1
1 0 0 0 0 1 0 0 0 0
1 0 0 0 0 0 1 0 1 0
1 0 0 0 0 0 1 0 0 1
1 0 0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 0 1 0 0
1 0 0 0 0 0 0 0 1 0
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0
0 1 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0 0
0 1 0 1 0 1 0 0 1 0
0 1 0 1 0 1 0 0 0 1
0 1 0 1 0 0 1 0 1 0
0 1 0 1 0 0 1 0 0 1
0 1 0 1 0 0 1 0 0 0
0 1 0 0 1 0 1 0 1 0
0 1 0 0 1 0 1 0 0 1
0 1 0 0 1 0 1 0 0 0
0 1 0 0 1 0 0 1 0 1
0 1 0 0 1 0 0 1 0 0
0 1 0 0 1 0 0 1 0 1
0 1 0 0 1 0 0 1 0 0
0 1 0 0 1 0 0 0 1 0
0 1 0 0 1 0 0 0 0 1
0 1 0 0 1 0 0 0 0 0
0 0 1 0 1 0 1 0 1 0
0 0
*/


///5 a.5
/*
201057

201.0.5.7
20.1.0.57
20.10.5.7
2.0.10.57
2.0.105.7

*/

///6 c.3


///7 a.20
/*
n = 214354322
a = 10
b = -1

return 20

f(214354322, 10, -1)
    a = 2
    b = 2
    return 2 - 2 + f(21435432, 2, 2) = 20
        f(21435432, 2, 2)
            a = 2
            b = 2
            return 2 - 2 + f(2143543, 2, 2) = 20
                f(2143543, 2, 2)
                a = 2
                b = 3
                return 3 - 2 + f(214354, 2, 3) = 20
                    f(214354, 2, 3)
                        a = 2
                        b = 4
                        return 4 - 2 + f(21435, 2, 4) = 19
                            f(21435, 2, 4)
                                a = 2
                                b = 5
                                return 5 - 2 + f(2143, 2, 5) = 17
                                f(2143, 2, 5)
                                    a = 2
                                    b = 5
                                    return 5 - 2 + f(214, 2, 5) = 14
                                        f(214, 2, 5)
                                            a = 2
                                            b = 5
                                            return 5 - 2 + f(21, 2, 5) = 11
                                                f(21, 2, 5)
                                                    a = 1
                                                    b = 5
                                                    return 5 - 1 + f(2, 1, 5) = 8
                                                        f(2, 1, 5)
                                                        a = 1
                                                        b = 5
                                                        return 5 - 1 + f(0, 1 5) = 4
                                                            f(0, 1, 5)
                                                                return 0;

*/

///8 b.1



///9 b.2^10


///10 c.3


///11
/*
1 - 1
2 - 10
3 - 11
4 - 100
5 - 101
6 - 110
7 - 111
8 - 1000
9 - 1001
10 - 1010
11 - 1011
12 - 1100
13 - 1101
14 - 1110
15 - 1111
16 - 10000

*/

/**
1 3 8 20

*/


///12 a.58


///13 d.123


///14 b.2


///15 a.2^n




///bac 2007 var 36
///SI
//1 d
//2 d
//3 b
//4 a
//5 b
//6 a
//7 b
//8 c


///SII
//1 8
/*
n = 81832
p = 10
q = 1

p = 100
q = 10

p = 1000
q = 100

p = 10000
q = 1000

p = 100000
q = 10000

8
*/

//2  55211

//3 100 numere
/*
abc: a = {3}, b, c = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
100 numere
*/

//4
/*
#inculde <iostream>

using namespace std;

int main()
{
    int n, p, q;

    cin >> n;
    p = 10;
    q = 1;

    do{
        p = p * 10;
        q = q * 10;
    }while(q > n || n > p);

    cout << n / q;

    return 0;
}
*/



///SIII
//1
/*
#inculde <iostream>

using namespace std;

int main()
{
    int i, nr = 0;

    for(i = 10; i <= 98; i += 2){
        if(nr == 5){
            cout << endl;
            nr = 0;
        }
        nr++;
        cout << i << " ";
    }

    int i, j;

    for(i = 1; i <= 9; i++){
        for(j = 0; j <= 8; j += 2)
            cout << i << j << " ";
        cout << endl;
    }
}
*/


//2
/*
#inculde <iostream>

using namespace std;


int main()
{
    int v[55], a[55][55], n, i, j, nr = 0;

    cin >> n;
    for(i = 0; i < n*(n - 1) / 2; i++)
        cin >> v[i];
    for(i = 0; i < n; i++){
        for(j =i + 1; j < n; j++){
            a[i][j] = v[nr];
            a[j][i] = v[nr];
            nr++;
        }
    }

    for(i = 0; i < n; i++){
        cout << endl;
        for(j = 0; j < n; j++)
            cout << a[i][j] << " ";
    }
}*/


//3
/*
#inculde <iostream>

using namespace std;

int main()
{
    ifstream fin("serbare.txt");
    int n, p, v[11], i, j, x, a;

    for(i = 0; i < 11; i++)
        v[i] = 0;

    fin >> n >> p;

    for(i = 1; i <= n; i++){
        fin >> x >> a;
        v[a] += x;
    }

    for(j = 0; j < p; j++){
        x = 1;
        for(i = 1; i <= n; i++)
            if(v[x] < v[i])
                x = i;
        v[x] = 0;
        cout << x << " ";
    }
}*/


///tema termin 3 si testul urmator (test 37)


///bac 2007 var 37
///SI
//1 d.1361015

//2 c. ultimului nod

//3 c. 5
/*
f(5)
    f(4) + f(3) = 3
        f(3) + f(2) = 3
            f(2) + f(1)
            return 1;

            return 1;
    f(3)
    return 1;
*/

//4 c. 2^n(n-1)/2


//5 a.


//6 a.


//7 d. b = {1, 0, 2, 3}
/*
a = {0, 1, 3, 2}
b = {1, 0, 2, 3}
a[b[i]] = b[a[i]]
i = 0
1 = 1

i = 1
0 = 0

i = 2
2 = 2

i = 3
3 = 3
*/


//10 b. 4
/*
1 + 2 + 3 + 4
1 + 2 + 7
1 + 3 + 6
1 + 4 + 5
1 + 9
2 + 8
3 + 7
...
*/


///SII
//1 3
/*
n = 30
nr = 0

i = 1
j = 1
s = 0

s = 1
j = 2

s = 3
j = 3

s = 6
j = 4

s = 10
j = 5

s = 15
j = 6

s = 21
j = 7

s = 28
j = 8

s = 36
j = 9

s != n

j = 2
s = 0

s = 2
j = 3

s = 5
j = 4

s = 9
j = 5

s = 14
j = 6

s = 20
j = 7

s = 27
j = 8

s = 35
j = 9

s != n

j = 3
s = 0

s = 3
j = 4

s = 7
j = 5

s = 12
j = 6

s = 18
j = 7

s = 25
j = 8

s = 33
j = 9

s != n

j = 4
s = 0

s = 4
j = 5

s = 9
j = 6

s = 15
j = 7

s = 22
j = 8

s = 30
j = 9

s == n
nr = 1

j = 5
s = 0

s = 5
j = 6

s = 11
j = 7

s = 18
j = 8

s = 26
j = 9

s = 35
j = 10

s != n

j = 6
s = 0

s = 6
j = 7

s = 13
j = 8

s = 21
j = 9

s = 30
j = 10

s == n
nr = 2

pt j = 7 s = 34
nr = 2

pt j = 8 s = 38
nr = 2

pt j = 9 s = 30
nr = 3

pt j = 10 s = 33
nr = 3

pt j = 11 s = 36
nr = 3

pt j = 12 s = 38
nr = 3

pt j = 13 s = 42
nr = 3

pt j = 14 s = 45
nr = 3

pt j = 15 s = 31
nr = 3
*/

//2 36

/*
#include <iostream>

using namespace std;

int main()
{
    int n, nr, i, j, s;
    cin >> n;
    nr = 0;
    for(i = 1; i <= n/2; i++){
        j = i;
        s = 0;
        while(s < n){
            s = s + j;
            j = j + 1;
        }

        if(s == n)
            nr = nr + 1;
    }

    cout <<nr;
}*/

//4
/*
citeste n (numar natural)
nr <- 0
┌pentru i = 1 , [n/2] executa
│ j <- i
│ s <- 0
│┌cât timp s < n executa
││  s <- s + j
││  j <- j + 1
│└■
│┌daca s = n atunci
││┌cat timp s > 0 executa
│││scrie j - 1, ' + '
│││s <- s - j
│││j <- j - 1
││└■
││  nr <- nr + 1
│└■
└■
scrie nr
*/


///SIII
/*
#include <iostream>

using namespace std;

int main()
{
    int a[11][21], m, n, i, j, x = 1, v[211];
    cin  >> m >> n;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++){
            v[x] = a[i][j];
            x += 1;
        }
    for(i = 1; i <= m*n; i++)
    if(v[i] != v[m*n - i + 1]){
        cout << "NU";
        return 0;
    }
    cout << "DA";
    return 0;

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(a[i][j] != a[m - i + 1][n - j + 1]){
                cout << "NU";
                return 0;
            }
    cout << "DA";
    return 0;
}*/


//2
/*
#include <iostream>

using namespace std;

int elimin(int n)
{
    int x = 1, cn = n;
    while(cn > 9){
        cn /= 10;
        x *= 10;
    }

    return n % x;
}

int main()
{
    int n, p;
    cin >> n >> p;
    while(p != 0){
        p -= 1;
        n = elimin(n);
    }

    cout << n;
    return 0;
}*/


//3

/*
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n > 9){
        cout << "1 2 3 4 5 6 7 8 9 ";
        n -= 9;
    }
    while(n != 0){
        cout << n << " ";
        n -= 1;
    }
}*/



///bac 2007 var 38
///SI
//1 b

//2 d

/*
2

4

4
*/

//3 c

//4 a

//5 c

//6 b

//7 b

//8 c

///SII
//1
/*
n = 1999

n = 28
nr = 1

n = 10
nr = 2

n = 1
nr = 3

scrie 3
*/

//2 1000

//3 9992
/*
9992

29
1

11
2

2
3
*/

//4

/*
#inculde <iostream>
using namespace std;

int suma(int n)
{
    int a;
    while(n != 0){
        a = a + n%10;
        n = n / 10;
    }
    return a;
}

int main()
{
    int n, nr;
    cin >> n;
    nr = 0;
    while(n > 9){
        n = suma(n);
        nr = nr + 1;
    }
    cout << nr;
    return 0;
}
*/

///SIII
//1
/*int main()
{
    int n, m, a[11][21], k, i, j, b = 1;
    cin >> m >> n;

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];
    cin >> k;

    for(j = 2; j <= n; j++)
        if(a[k][b] < a[k][j])
            b = j;

    cout << a[k][b];
}*/

//2
//a
/*int fibb(int n)
{
    int a = 1, b = 1;
    while(b < n){
        b += a;
        a = b - a;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    cout << fibb(n);
}*/

//b
/*int fibb(int n)
{
    int a = 1, b = 1;
    while(b < n){
        b += a;
        a = b - a;
    }
    return a;
}

int main()
{
    int n, i, v[10000];
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> v[i];

    for(i = 0; i < n; i++)
        cout << fibb(v[i]) << " ";
}*/


//3
/*
#include <iostream>

using namespace std;


int main()
{
    ifstream fin("F1.txt");
    ifstream gin("F2.txt");

    float *f, *g;
    int n = 0, m = 0, i, j, nr;
    f = (float *)malloc(1 * sizeof(float));
    g = (float *)malloc(1 * sizeof(float));

    while(fin >> f[n]){
        n += 1;
        f = (float *)realloc(f, (n + 1) * sizeof(float));
    }

    while(gin >> g[m]){
        m += 1;
        g = (float *)realloc(g, (m + 1) * sizeof(float));
    }

    for(i = 0; i < n; i++){
        nr = 0;
        for(j = 0; j < m; j++)
            if(f[i] == g[j])
                nr += 1;
        cout << f[i] << " " << nr << endl;
    }

    free(f);
    free(g);
}*/


///
/*x^2 + n = y^2
y^2 - x^2 = n
(y - x)(y + x) = n
y > x
*/

///bac 2007 var 39

///SIII
//2
/*int main()
{
    int x, y, n;
    cin >> n;

    for(x = 1; x <= n; x++)
        for(y = x + 1; y <= n; y++){
            //cout << n << " " << x << " " << y << "       " << x * x + n << " " << y * y  << endl;
            if(x * x + n == y * y)
                cout << "pt n = " << n << " exista perechea (x, y) = (" << x << ", " << y << ")" << endl;
        }
}*/


//3

/*struct elev{
char nume[100];
float media;
};

int main()
{
    struct elev v[30];
    int n, i, x;
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> v[i].nume >> v[i].media;

    for(i = 0; i < n; i++)
        cout << v[i].nume << " " << v[i].media << endl;
    cout << endl << endl;

    while(n != 0){
        x = 0;
        for(i = 0; i < n; i++)
            if(v[x].media < v[i].media)
                x = i;

        cout << v[x].nume << " " << v[x].media << endl;

        for(i = x; i < n - 1; i++){
            strcpy(v[i].nume, v[i + 1].nume);
            v[i].media = v[i + 1].media;
        }
        n--;
    }
}*/
/*
5

Mihai 9.34
Alex 8.47
Maria 3.21
Ana 5.30
Dani 9.85
*/



///bac 2007 var 40
///SI
//1 d
/*
000
001
010
011
100
101
110
111
*/

//2 c

//3 d

//4 d

//5 c

//6 a

//7 b
/*
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
0 0 0 0 1
0 0 0 1 0
*/

//8 c

///SII
//1 D
/*
z = max(mult(3, 2), mult(3, 5)) = max(0, 0) = 0
z = 0

r = 100

scrie D
*/

//2 n = 5

//3 5 numere
/*
1 3 6 7 9
*/

//4
/*int mult(int n, int a);
int main()
{
    int m, n, z, r, i;
    cin >> m >> n;
    z = max(mult(n, 2), mult(n, 5));
    r = 10 * m;


    for(i = 1; i <= z; i++){
        r = r % n * 10;
    }

    if(r != 0)
        cout << "D";
    else
        cout << "N";

    return 0;
}

int mult(int n, int a)
{
    int i = 0;
    while(n % a == 0){
        i++;
        n /= a;
    }
    return i;
}*/


///SIII
//1
/*int main()
{
    ifstream fin("MAT.TXT");
    int n, m, i, j, mat[10][20];
    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            fin >> mat[i][j];

    for(i = 0; i < n; i++){
        cout << endl;
        for(j = 0; j < m; j++)
            cout << mat[i][j] << " ";
    }
}*/

//2
/*int s1(int x[100], int p, int q);
void s2(int x[100], int p, int q, int &mn);

int main()
{
	int a[100], b[100], n, m, i, mn, mx;
	cin >> n >> m;
	for(i = 0; i < n; i++)
		cin >> a[i];

	for(i = 0; i < m; i++)
		cin >> b[i];

	mx = s1(a, 0, n - 1);


    s2(b, 0, m - 1, mn);

    if(mx < mn)
        cout << "DA";
    else
        cout << "NU";
}

int s1(int x[100], int p, int q)
{
	int i, mx = x[p];

	for(i = p + 1; i <= q; i++)
        if(x[i] > mx)
            mx = x[i];

    return mx;
}

void s2(int x[100], int p, int q, int &mn)
{
	int i;
    mn =  x[p];
	for(i = p + 1; i <= q; i++)
        if(x[i] < mn)
            mn = x[i];
}*/

//3
/*int main()
{
    int i;
    for(i = 11; i <= 97; i += 2){
        cout << i << " " << i + 2 << endl;
        i += 2;
    }
    cout << 99;

    return 0;
}*/


///simulare iasi 2022
///SI
//1 c
/*
!(x%y!=0 || y>=7)
x%y==0 & y < 7
*/

//2 b
/*
343254321
p(i, j)
p(1, 5)
    p(2, 4)
        p(3, 3)
            p(4, 2)
            cout << 3;
        cout << 432;
    cout << 54321;


*/

//3 b

//4 b
/*
10237
10246
10264
10273
10345
10354
*/

//5 c

///SII
//1
//a
/*
scrie 1121491234
n = 4
*/

//b 1 9

//c
/*
#include <iostream>

using namespace std;

int main()
{
    int n, j, i;
    cin >> n;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= i; j++)
            if(i % 2 == 0)
                cout << j;
            else
                cout << j * j;

    return 0;
}
*/

//d
/*
citeste n (număr natural nenul)
pentru i <- 1, n execută
│j <- 1
│executa
││dacă i % 2 = 0 atunci
│││ scrie j
│││ altfel  scrie j * j
││└■
││j <- j + 1
│└pana cand j > i
└■
*/

//2
/*
struct vauto{
    unsigned int km, pret;
    float cosnsum;
}m[300];
*/

//3
/*
for (i=0; i<6; i++)
    for (j=0; j<4; j++){
        if(j % 2 == 0)
            a[i][j] = char(65 + i);
        else
            a[i][j] = char(97 + i);
    }
*/

/*int main()
{
    char a[7][5];
    int i, j;
    for (i=0; i<6; i++)
        for (j=0; j<4; j++){
            if(j % 2 == 0)
                a[i][j] = char(65 + i);
            else
                a[i][j] = char(97 + i);
        }

    for (i=0; i<6; i++){
        cout << endl;
        for (j=0; j<4; j++)
            cout << a[i][j] << " ";
    }
}*/

///SIII
//1
/*void numimp(int n, int v[100], int &c)
{
    int i, cv;
    for(i = 0; i < n; i++){
        cv = v[i];
        while(cv != 0){
            if(cv % 2 == 1){
                c++;
                cv = 0;
                //break;
            }
            else
                cv /= 10;
        }
    }
}

int main()
{
    int n, v[100], c = 0, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> v[i];

    numimp(n, v, c);

    cout << c;

    return 0;
}*/

//2
/*int main()
{
    char s[101], a[101][20], cuv[11], *l;
    int n = 0, i, ok;

    cin.getline(s, 101);
    cin >> cuv;

    l = strstr(s, cuv);
    if(l == NULL){
        cout << "NU EXISTA";
        return 0;
    }

    l = strtok(s, " ");
    while(l != NULL){
        strcpy(a[n], l);
        l = strtok(NULL, " ");
        n += 1;
    }

    ok = 0;
    for(i = 1; i < n - 1; i++){
        if(strcmp(cuv, a[i]) == 0){
            cout << a[i - 1] << " " << a[i + 1] << endl;
            ok = 1;
        }
    }

    if(ok == 0)
        cout << "NU EXISTA";

    return 0;
}*/
/*
bac

a fost la bac si apoi a plecat cu un bac la mare
*/

//3
/*int main()
{
    ifstream fin("valori.in");
    int n, i;
    long int difmx, difmn, nr1, nr2, nr3, nr4, x, x_ant;

    fin >> n;
    fin >> nr1 >> nr2;
    nr3 = nr1;
    nr4 = nr2;

    difmx = abs(nr1 - nr2);
    difmn = abs(nr3 - nr4);

    x_ant = nr2;
    for(i = 2; i < n; i++){
        fin >> x;

        if(difmx <= abs(x_ant - x)){
            nr1 = x_ant;
            nr2 = x;
            difmx = abs(x_ant - x);
        }

        if(difmn >= abs(x_ant - x)){
            nr3 = x_ant;
            nr4 = x;
            difmn = abs(x_ant - x);
        }

        x_ant = x;
    }

    cout << difmx << " " << difmn << endl;;
    if(nr1 < nr2)
        cout << nr1 << " " << nr2 << endl;
    else
        cout << nr2 << " " << nr1 << endl;
    if(nr3 < nr4)
        cout << nr3 << " " << nr4 << endl;
    else
        cout << nr4 << " " << nr3 << endl;
}*/


///model bac2024 noiembrie
///SI
//1 c

//2
/*
f1(24)
24 * 25 / 2 = 12 * 25 = 300

f2(24)
1 + 2 + 3 + . . . + 24 = f1(24) = 300

f3(24)
24 * 24 / 4 + 2 * f3(12) = 144 + 156 = 300o
	f(12)
	12 * 12 / 4 + 2 * f3(6) = 36 + 42 = 78
		f(6)
		6 * 6 / 4 + 2 * f3(3) = 21
			f3(3)
			3 + f(2) = 6
				f(2)
				2 * 2 / 4 + 2 * f3(1) = 3
					f3(1)
					1 + f3(0) = 1
						f3(0)
						return 0
*/

//3 a
/*
{b, ca, co, o, p, s}
{1, 2,  3,  4, 5, 6}
b(1) si co(3) nu in aceiasi multime
p(5) este mereu ultimul element din multime
smantana(6) sta inainte de cascaval(2)

{1, 2, 4, 5}
{1, 4, 2, 5}
{1, 4, 6, 2}
{1, 4, 6, 5}
{1, 6, 2, 4}
{1, 6, 2, 5}
{1, 6, 4, 2}
*/

//4 b

//5 b

///SII
//1
//a scrie 2024
/*
i = 4

x = 721
x = 72
x = 7

m = 7

i = 3

x = 20020
x = 2002

m = 2009

i = 2

x = 1321
x = 132
x = 13

m = 2022

i = 1

x = 211
x = 21
x = 2

m = 2024

i = 0
*/

//b 10 11

//c
/*
include <iostream>

using namespace std;

int main()
{
    int n, m, i, x;

    cin >> n;
    m = 0;
    i = n;

    while(i >= 1){
        cin >> x;
        while(x % 10 <= x / 10 % 10)
            x /= 10;

        m += x;
        i -= 1;
    }

    if(m != n)
        cout << m;
    else
        cout << "egale";
}
*/

//d
/*
citește n (număr natural nenul)
m <- 0
┌pentru i <- n, 1, -1 execută
│ citește x (număr natural)
│┌cât timp x % 10 ≤ [x / 10] % 10 execută
││ x <- [x / 10]
│└■
│ m <- m+x
└■
┌dacă m≠n atunci scrie m
│altfel scrie „egal”
└■
*/

//2
/*
struct telefon{
    char producator;
    int frecventa;
    float dimensiune[3];
}t;
*/

//3
/*
for(i = 0; i < 2024; i++)
    if(a[1][i] == 2024 && a[3][i] == 2024)
        cout << i << " ";
*/

///SIII
//1
/*int produs(int a, int b){
    int d, p = 1;
    for(d = 1; d <= a; d++)
        if(a % d == 0 && b % d == 0)
            p *= d;
    return p;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << produs(a, b);
}*/

//2
/*int main(){
    char *c, s[101], x[101] = "", v[101] = "";
    int n, i = 0, ok1 = 0, ok2 = 0;

    cin.getline(s, 101);
    cin >> n;

    c = strtok(s, " ");
    while(c != NULL){
        if(strlen(c) < n){
            strcat(x, c);
            strcat(x, " ");
            ok1 = 1;
        }

        if(strlen(c) > n){
            strcat(v, c);
            strcat(v, " ");
            ok2 = 1;
        }

        c = strtok(NULL, " ");
    }

    if(ok1 * ok2 == 0)
        cout << "nu exista";
    else
        cout << x << endl << v;
}*/

/*int main(){
    char s[101];
    int n, i, j, x, ok1 = 0, ok2 = 0;

    cin.getline(s, 101);
    cin >> n;

    x = 0;
    for(i = 0; i < strlen(s); i++){
        if(s[i] == ' '){
            if(x < n){
                for(j = i - x; j < i; j++)
                    cout << s[j];
                cout << " ";
                ok1 = 1;
            }
            x = 0;
        }
        else {
            x++;
        }
    }

    cout << endl;

    x = 0;
    for(i = 0; i < strlen(s); i++){
        if(s[i] == ' '){
            if(x > n){
                for(j = i - x; j < i; j++)
                    cout << s[j];
                cout << " ";
                ok2 = 1;
            }
            x = 0;
        }
        else {
            x++;
        }
    }
    if(ok1 * ok2 == 0)
        cout << "nu exista";
}*/
/*
era o apa rece si cu gust bun

3
*/

//3
/*int main(){
    ifstream fin("bac1.txt");
    int n1, n2, n3, mx = 0, v[1001] = {0}, x, i, ok1 , ok2, ok3;

    fin >> n1 >> n2 >> n3;

    while(fin >> x){
        if(x > mx)
            mx = x;
        v[x]++;
    }

    ok1 = n1;
    ok2 = n2;
    ok3 = n3;

    for(i = mx; i >= 1; i--){
        if(v[i] >= n1){
            cout << i << " ";
            v[i] = 0;
            n1 = i;
        }
    }

    for(i = n1; i >= 1; i--){
        if(v[i] >= n2){
            cout << i << " ";
            v[i] = 0;
            n2 = i;
        }
    }

    for(i = n2; i >= 1; i--){
        if(v[i] >= n3){
            cout << i << " ";
            v[i] = 0;
            n3 = i;
        }
    }

}*/


///simulare BAC 2023
///SI
//1 d

//2 b
/*
f(2023)
    f(202) * 10 + 2 = 3232
        f(202)
            f(20) * 10 + 3 323
                f(20)
                    f(2) * 10 + 2 = 32
                        f(2)
                            f(0) * 10 + 3 = 3
                                return 0;
*/

//3 a

//4 d
/*
{matcha, mate, moringa, oolong, tulsi}
{1, 2, 3, 4, 5}
1 2 3
1 2 4
1 2 5
1 3 4

1 2 5
3 4 5
2 3 4
4 5 1
*/

//5 c
/*
8 raioane
3 zone importante (nr par nenul)

2 2 4
2 4 2
4 2 2
*/

///SII
//2
/*
(4, 1, 1, 0, 7, 4, 4)
(1, 2, 3, 4, 5, 6, 7)

(2, 3) (1, 6) (6, 5)
*/

//3
/*int main(){
int a[5][5] = {{0}}, i, j;
for(i = 1; i <= 5; i++)
    for(j = 1; j <= 5; j++)
        if(a[j][i] == 0){
            a[j][i] = 5 - i;
            a[5 - i + 1][5 - j + 1] = 5 - i;
        }

for(i = 1; i <= 5; i++){
    cout << endl;
    for(j = 1; j <= 5; j++)
        cout << a[i][j] << " ";
}
}*/


/*int dublu(int n){
    int cn, i = 0, nr = 0, p = 1, u;
    cn = n;
    while(cn){
        nr++;
        cn /= 10;
    }
    if(nr % 2 == 0)
        return -1;

    while(n){
        u = n % 10;
        if(i == (nr - 1) / 2){
            cn += u * p;
            p *= 10;
        }
        cn += u * p;
        p *= 10;

        n /= 10;
        i++;
    }
    return cn;
}

int main(){
    int n;
    cin >> n;
    cout << dublu(n);
}*/


/*int main(){
    ifstream fin("bac3.txt");
    int m, n, v[100000], i, j, x, a;
    fin >> n;
    for(i = 0; i < n; i++)
        fin >> v[i];
    fin >> m;
    a = m + n;
    for(; i < a; i++)
        fin >> v[i];

    x = 1;
    while(x == 1){
        x = 0;
        for(i = 0; i < a - 1; i++)
            if(v[i] > v[i + 1]){
                v[i] = v[i + 1] + v[i];
                v[i + 1] = v[i] - v[i + 1];
                v[i] = v[i] - v[i + 1];
                x = 1;
            }
    }

    for(i = 0; i < a - 1; i++)
        if(v[i] == v[i + 1]){
            for(j = i; j < a - 1; j++)
                v[j] = v[j + 1];
            i--;
            a--;
        }

    for(i = 0; i < a; i++)
        if(v[i] % 3 == 0)
            cout << v[i] << " ";
}*/


/*int main(){
    int n, p, i = 1;
    cin >> n;
    while(n){
        if(n % 3 == 0 || n % 5 == 0)
            i *= n;
        if(i % 45 == 0){
            p++;
            i /= 45;**
        }
        n--;
    }
    cout << p;
}*/


/*void secventa(int &n){
    int cn = 0, p = 1;
    while(n){
        if(n % 100 == 22){
            cn += 20 * p;
            n /= 10;
            p *= 10;
        }
        else
            cn += n % 10 * p;
        n /= 10;
        p *= 10;
    }
    n = cn;
}

int main(){
    int n;
    cin >> n;
    secventa(n);
    cout << n;
}*/

/*int main(){
    ifstream fin("bac4.txt");
    int x, y, nr = 0, a = 0, b;
    while(fin >> b || b <= y){
        if(a != b && b >= x)
            nr++;
        a = b;
    }
    cout << nr;
}*/


/*int main(){
    int d, i, nr, s = 0, n;
    cin >> n;
    for(i = 2; i <= n; i++){
        if(n % i == 0){
            nr = 0;
            for(d = 2; d*d <= i; d++)
                if(i % d == 0)
                    nr = 1;
            if(nr == 0){
                while(n % i == 0){
                    nr++;
                    n /= i;
                }
                if(nr % 2 == 1)
                    s += i;
            }
        }
    }
    cout << s;
}*/


/*int main(){
    ifstream fin("bac5.txt");
    int x, a, b, m = 0, n = 0;
    fin >> x;
    while(fin >> b){
        if(b % 1000 == x){
            a = b;
            fin >> b;
            if(b % 1000 == x){
                m = a;
                n = b;
            }
        a = b;
        }
    }
    if(m != 0 && n != 0)
        cout << m << " " << n;
    else
        cout << "nu exista";
}*/


/*int main(){
    int a[5][5]={1}, i, j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++){
            if(i == j && i != 0)
                a[i][j] = a[i-1][j-1] + 2;
            if(j > i){
                a[i][j] = a[i][j - 1];
                a[j][i] = a[j - 1][i];
            }
            if(i == 0 && j == 0)
                a[i][j] = 0;
        }
    for(i=0;i<5;i++){
        cout << endl;
        for(j=0;j<5;j++)
            cout << a[i][j] << " ";
    }
}*/



/*int Impare(int n){
    int x, cn, p;
    x = 0;
    p = 1;
    while(n != 0){
        if(n % 10 % 2 != 0){
            x += p*(n % 10 + n % 10 * 10);
            p *= 10;
        }
        else
            x += p*(n % 10);
        p *= 10;
        n /= 10;
    }
    if(x == cn)
        return -1;
    else
        return x;

}


int main(){
    int n;
    cin >> n;
    cout << Impare(n);
}*/


/*int main(){
    char s[101], l[100][11], x[101], *p;
    int n, i, ok;
    x[0] = '\0';
    cin >> n;
    for(i = 0; i < n ; i++)
        cin >> l[i];

    cin.get();
    cin.getline(s, 101);

    p = strtok(s, " ");
    while(p != NULL){
        if(p[0] == '*'){
            ok = 0;
            for(i = 0; i < n; i++)
                if(strlen(p) == strlen(l[i])){
                    strcat(x, l[i]);
                    strcat(x, " ");
                    ok = 1;
                    break;
                }
            if(ok == 0){
                cout << "imposibil";
                return 0;
            }
        }
        else{
            strcat(x, p);
            strcat(x, " ");
        }
        p = strtok(NULL, " ");
    }
    cout << x;
    return 0;
}*/

/*int main(){
    int v[1001] = {0}, y[1000], n = 0, x;
    ifstream fin("bac.in");
    while(fin >> x){
        v[x]++;
        y[n] = x;
        n++;
    }
    for(int i = 0; i < n; i++)
        if(v[y[i]] > y[i] || v[y[i]] % 2 != y[i] % 2){
            cout << "NU";
            return 0;
        }
    cout << "DA";
    return 0;
}*/




///bac 2020 VAR 6
///SI
//1 c

//2 a
/*
f(n, k)
f(35, 3)
    2 + 10 * f(11, 3) = 1022
        f(11, 3)
            2 + 10 * f(3, 3) = 102
                f(3, 3)
                    0 + 10 * f(1, 3) = 10
                        f(1, 3)
                            1 + 10 * f(0, 3) = 1
                                f(0, 3) = 0
*/


//3 d
/*
v = p.lg * p.lt * p.h
*/


//4 b
/*
{A, M, U, R, G}
{1, 2, 3, 4, 5}
R precede A si M
4 precede 1 si 2

34125
34152
34215
34251
34512
. . .
53421
54123
GRAMU

*/


//5 c


///SII
//1
//a 233223222
/*
1;1 1;2 1;3
2;1 2;2 2;3
3;1 3;2 3;3

cout: 233223222
*/

//b 6, 7

//c
/*
#include <iostream>
using namespace std;

int main(){
    int n, i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(j <= i)
                cout << 2;
            else
                cout << 3;
    return 0;
}
*/


//d
/*
citește n
(număr natural nenul)
┌pentru i <- 1,n execută
│j <- 1
│┌cat timp j <= n executa
││┌dacă j <= i atunci
│││ scrie 2
│││altfel
│││ scrie 3
││└■
││j <- j + 1
│└■
└■
*/


//2 descendentii nodului 2 sunt: 4, 5, 6, 7


//3
/*
if(s[k] == s[0]){
    strcpy(s + k + 1, "\0"); SAU s[k + 1] = '\0';
    cout << s << " ";
}
*/


///SIII
//1
/*void Putere(int n, int &x, int &p){
    int i, nr, a;
    float cn;
    x = n;
    p = 1;
    for(i = 2; i < n; i++)
        if(n % i == 0){
            cn = n;
            a = n;
            nr = 0;
            while(a % i == 0){
                cn /= i;
                a = cn;
                nr++;
            }

            if(p <= nr && cn == 1){
                p = nr;
                x = i;
            }
        }
}

int main(){
    int n, x, p;
    cin >> n;
    Putere(n, x, p);
    cout << x << " " << p;
}*/


//2
/*int main(){
    int m[20][20], i, j, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> m[0][i];

    for(i = 1; i < n; i++)
        for(j = 0; j < n; j++)
            if(i + j < n)
                m[i][j] = (m[i - 1][j] + m[i - 1][j + 1]) % 100;
            else
                m[i][j] = -1;

    for(i = 0; i < n; i++){
        cout << endl;
        for(j = 0; j < n; j++)
            cout << m[i][j] << " ";
    }
}*/


//3
/*int main(){
    ifstream fin("bac6.txt");
    int mx, mn, x, y, a, nr = 2, nrmx = 0, ok = 1;
    fin >> mn >> mx;
    while(fin >> a){
        if(a >= mn && a <= mx){
            ok = 0;
            if(nrmx == 0)
                cout << nr + 1 << " ";
            nrmx = nr;
        }

        if(mn > a)
            mn = a;
        if(mx < a)
            mx = a;

        nr++;
    }
    if(ok == 1)
        cout << "nu exista";
    else
        cout << nrmx + 1;
}*/



///Simulare BAC 2023
///SI
//1 d

//2 b
/*
f(2023)
    f(202) * 10 + 2 = 3232
        f(202)
            f(20) * 10 + 3 = 323
                f(20)
                    f(2) * 10 + 2 = 32
                        f(2)
                            f(0) * 10 + 3 = 3
                                f(0) = 0
*/

//3 a

//4 d
/*
{matcha, mate, moringa, oolong, tulsi}
{   1  ,  2  ,    3   ,   4   ,   5  }

123
124
125
134
*/

//5 c



///SII
//1
//a 474
/*
n = 5174
x = 5

cn = 5174
n = 0
p = 1

c = 4
n = 4
cn = 517
p = 10

c = 7
c = 74
cn = 51
p = 100

c = 1
n = 174
cn = 5
p = 1000

c = 5
n = 174
cn = 0
p = 10000

x = 4

c = 4
n = 1
cn = 17
p = 10

c = 7
n = 17
cn = 1
p = 100

c = 1
n = 171
cn = 0
p = 1000

. . .

x = 1

c = 1
n = 4
cn = 17
p = 10

c = 7
n = 74
cn = 1
p = 100

c = 1
n = 474
cn = 0
p = 1000
*/

//b 521, 531, 5031

//c
/*
#include <iostream>
using namespace std;

int main(){
    int x, n, cn, p, c;
    cin >> n;
    x = 5;
    do{
        cn = n;
        n = 0;
        p = 1;
        do{
            c = cn % 10;
            if(c == x)
                c = 5 - c;
            n = c * p + n;
            cn /= 10;
            p *= 10;
        }while(cn != 0);
        x -= 1;
    }while(x != 0);

    cout << n;
    return 0;
}
*/

//d
/*
citeşte n
(număr natural)
┌pentru x <- 5, 0, -1 executa
│ cn <- n; n <- 0; p <- 1
│┌repetă
││ c <- cn%10
││┌dacă c=x atunci c <- 5-c
││└■
││ n <- c*p+n; cn <- [cn/10]; p <- p*10
│└până când cn=0
└■
scrie n
*/


//2 [1,6], [4,5], [2,3]


//3
/*
1;1 1;2 1;3 1;4 1;5
2;1 2;2 2;3 2;4 2;5
3;1 3;2 3;3 3;4 3;5
4;1 4;2 4;3 4;4 4;5
5;1 5;2 5;3 5;4 5;5

if(i + j <= 5){
    a[j][i] = 5 - i;
    a[6 - i][6 - j] = 5 - i;
}

if(i + j == 6 && i != 1 && j != 5)
    a[i][j] = 5 - j;
*/


///SIII
//1
/*
void NrImp(int x, int y, int &nr){
    int d, i, ok;
    nr = 0;
    for(i = x; i <= y; i++){
        ok = 0;
        for(d = 1; d <= i; d++)
            if(i % d == 0 && d % 2 == 1)
                ok++;
        if(ok == 3)
            nr++;
    }
}

int main(){
    int x, y, nr;
    cin >> x >> y;
    NrImp(x, y, nr);
    cout << nr;
}
*/


//2
/*int main(){
    char s[101], p[101] = "", *cuv;

    cin.getline(s,101);

    cuv = strtok(s, " ");
    while(cuv != NULL){
        if(cuv[0] == 's' || cuv[0] == 'S')
            strcat(p, "spe. ");
        else if(cuv[0] == 'f' || cuv[0] == 'F')
            strcat(p, "fam. ");
        else
            strcat(p, "gen. ");
        cuv = strtok(NULL, " ");
        strcat(p, cuv);
        strcat(p, " ");

        cuv = strtok(NULL, " ");
    }

    cout << p;
}*/


//3
/*int main(){
    ifstream fin("bac7.txt");
    int x, mx = 0, nr = 1, ante = 0;
    while(fin >> x){
       if(mx <= x && ante != x){
            cout << nr << " ";
            mx = x;
       }
       ante = x;
       nr++;
    }
}*/


///BAC 2021 VAR 4
///SI
//1 d
//((x + y) / 5 + (x - y) / 2) / (x + 2)

//2 b
/*
f(1234)
    0 * 4 + f(123) = 4
        f(123)
            1 * 3 + f(12) = 4
                f(12)
                    0 * 2 + f(1) = 1
                        f(1)
                            1 * 1 + f(0) = 1
                                f(0)
                                    return 0
*/

//3 a

//4 b

//5 c
/*
1-11-21-1
2-12
3-13
4-14
5-15
6-16
7-17
8-18
9-19
10-20
*/


///SII
//1
//a 3 4 6 8 9 15

//b 5 5 5, 2 2 2

//c
/*
#include <iostream>

using namespace std;

int main(){
    int n, x, y, i, ok;
    cin >> n >> x >> y;

    ok = 0;
    for(i = 1; i <= n; i++){
        if((i % x == 0 && i % y != 0) || (i % x != 0 && i % y == 0)){
            cout << i << " ";
            ok = 1;
        }
    }

    if(ok == 0)
        cout << 0;

    return 0;
}
*/

//d
/*
citește n, x, y
(numere naturale nenule, x <= n, y <= n)
ok <- 0; i = 1
┌cat timp i <= n executa
│┌dacă (i % x = 0 și i % y != 0) sau
││ (i % x != 0 și i % y = 0) atunci
││ scrie i, ' '
││ ok <- 1
│└■
│i <- i + 1
└■
┌dacă ok = 0 atunci scrie 0
└■
*/

//2 ARMONIA

//3
/*
a[0].dp.anNastere = 2000;
a[0].venit = 4000;
*/


///SIII
//1
/*
void cuburi(int n){
    while(n){
        cout << n * n * n << " ";
        n--;
    }
}

int main(){
    int n;
    cin >> n;
    cuburi(n);
}
*/


//2
/*
int main(){
    int n, k, i, j, a[100][100];
    cin >> n >> k;

    for(i = 0; i < n; i++){
        a[i][0] =  k * (i + 1) - i;
        for(j = 1; j < n; j++)
            a[i][j] = a[i][j - 1] + 1;
    }

    for(i = 0; i < n; i++){
        cout << endl;
        for(j = 0; j < n; j++)
            cout << a[i][j] << " ";
    }
}
*/


//3
/*
int main(){
    ifstream fin("bac8.txt");

    int x, nr = 0, a[2][100] = {0}, na, nb;

    fin >> na >> nb;
    for(int i = 0; i < na; i++){
        fin >> x;
        x %= 100;
        if(x % 10 > x / 10)
            x = x % 10 * 10 + x / 10;
        a[0][x]++;
    }
    for(int i = 0; i < nb; i++){
        fin >> x;
        x %= 100;
        if(x % 10 < x / 10)
            x = x % 10 * 10 + x / 10;
        a[1][x]++;
    }

    for(int i = 1; i < 100; i++){
        nr += a[0][i] * a[1][i % 10 * 10 + i / 10];
    }

    cout << nr;
}
*/


///BAC 2020 TEST 6
///SI
//1 c
/*
(x >= 18) && (x >= 19 && x <=20) && (x <= 21)
*/

//2 c
/*
{caprifoi, iasomie, liliac, tamarix, scumpie}
{c, i, l, t, s}
{1, 2, 3, 4, 5}

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
. . .
5 4 3 1 2
{s, t, l, c, i}

//3 a

//4 d
5 - 4, 3
4 - 2
3 - 1, 6

//5 b
*/

///SII
//1
//a scrie 4
/*
n = 7
nr = 0
i = 1

nr = 1

i = 2

x = 0
y = 1
j = 1

r = -1
x = 1
y = -1
j = 2

i = 3

x = 0
y = 1
j = 1

r = -1
x = 1
y = -1
j = 2

r = 3
x = -1
y = 3
j = 3

i = 4

nr = 2

x = 0
y = 1
j = 1

r = -1
x = 1
y = -1
j = 2

r = 3
x = -1
y = 3
j = 3

r = -5
x = 3
y = -5
j = 4

i = 5

x = 0
y = 1
j = 1

r = -1
x = 1
y = -1
j = 2

r = 3
x = -1
y = 3
j = 3

r = -5
x = 3
y = -5
j = 4

r = 11
x = -5
y = 11
j = 5

i = 5

nr = 3




x = 0
y = 1
j = 1

r = -1
x = 1
y = -1
j = 2

r = 3
x = -1
y = 3
j = 3

r = -5
x = 3
y = -5
j = 4

r = 11
x = -5
y = 11
j = 5

r = -21
x = 11
y = -21
j = 6

r = 43
x = -21
y = 43
j = 7

r = -85
x = 43
y = -85
j = 8

*/

//b 19 20
/*
p n p n p n p n p n  p  n  p  n
1 2 3 4 5 6 7 8 9 10 11 12 13 14
1 1 2 2 3 3 4 4 5 5  6  6  7  7
*/

//c
/*
#include <iostream>
using namespace std;

int main(){
    int n, nr , i, j, x, y, r;
    cin >> n;

    nr = 0;
    i = 1;
    while(i <= n){
        x = 0;
        y = 1;
        j = 1;

        while(j < i){
            r = 2 * x - y;
            x = y;
            y = r;
            j += 1;
        }

        i += 1;

        y > 0 ? nr += 1 : nr;
    }

    cout << nr;
    return 0;
}
*/

//d
/*
citește n (număr natural nenul)
nr <- 0;
┌pentru i <- 1, n execută
│ x <- 0; y <- 1; j <- 1
│ ┌cât timp j < i execută
│ │ r <- 2 * x - y; x <- y; y <- r
│ │ j <- j + 1
│ └■
│ ┌dacă y > 0 atunci
│ │ nr <- nr + 1
│ └■
└■
scrie nr
*/

//2 x1 = 6, x2 = 10
/*
f(10, 6)
    10 / 6 + f(4, 6) = 5
        f(4, 6)
            6 / 4 + f(4, 2) = 4
                f(4, 2)
                    4 / 2 + f(2, 2) = 3
                        f(2, 2) = 1
                            return 1

//3
/*
a[0][0] = 16;
for(i = 0; i < 4; i++){
    for(j = 1; j < 5; j++)
        a[i][j] = a[i][j - 1] + 1;
    if(i < 4)
        a[i + 1][0] = a[i][0] - 5;
}
*/

///SIII
//1
/*
void prodprim(int n, int &p){
    int d;
    for(d = 2; d <= n; d++)
        if(n % d == 0){
            p *= d;
            while(n % d == 0)
                n /= d;
        }
}

int main(){
    int n, p;
    cin >> n;
    p = 1;
    prodprim(n, p);
    cout << p;
}
*/

//2
//ei au plantat tamarix ea a adus iasomie
/*
int main(){
    char txt[101], *cuv;
    int c, v, ok = 0;
    cin.get(txt, 101);
    cuv = strtok(txt, " ");

    while(cuv != NULL){
        c = 0;
        v = 0;
        for(int i = 0; i < strlen(cuv); i++)
            if(strchr("aeiou", cuv[i]) != NULL)
                v++;
            else
                c++;
        if(c > v){
            cout << cuv << endl;
            ok = 1;
        }
        cuv = strtok(NULL, " ");
    }

    if(ok == 0)
        cout << "nu exista";
}
*/


//3
//a
/*
int main(){
    int p1, p2, d1, d2, x, nr = 0;
    cin >> p1 >> p2;

    for(d1 = p1; d1 >= 1; d1--){
        if(p1 % d1 == 0 && d1 <= 9 && p1 / d1 <= 9){
            x = 9;
            while(x >= 0){
                for(d2 = p2; d2 >= 1; d2--)
                    if(p2 % d2 == 0 && d2 <= 9 && p2 / d2 <= 9)
                        cout << d1 << p1 / d1 << x << x << x << d2 << p2 / d2 << endl;
                x--;
            }
        }
    }
}
*/
//b
/*
Se construieste numarul cu ajutorul variabilelor d1 si d2.
Cele doua vor fi mereu verificate, alaturi de "p1 / d1" si
"p2 / d2", sa nu fie numere, ci cifre care inmultite sa rezulte
p1 respectiv p2.Cu ajutorul a doua for-uri, doua if-uri si un while
programul afisaza numerele cerute in fisier, cu propietatile
mentionate.
*/



///BAC 2020 TEST 7
///SI
//1 d
/*
x >= 2001 && x <= 2002 || x >= 2019 && x <= 2020
*/

//2 a

//3 b
/*
{albizia, jacaranda, laburnum, magnolie, mimoza, sakura}
{a, j, l, ma, mi, s}
{1, 2, 3, 4,  5,  6}

1 2 3 4
1 2 3 5
1 2 3 6
1 2 4 5
1 2 4 6

a.4 5 3 6
b.2 4 5 6
c.2 3 4 5 6
d.1 2 4 3
*/

//4 c

//5 c


///SII
//1
//a scrie 7533
/*
n = 253387

x = 1
m = 0
p = 1

cn = 253387

c = 7
cn = 25338

. . .
m = 7533
*/

//b  20 88

//c
/*
#include <iostteam>
using namespace std;

int main(){
    int n, x, m, p, cn, c;
    cin >> n;

    x = 1;
    m = 0;
    p = 1;

    while(x < 10){
        cn = n;
        while(cn){
            c = cn % 10;
            cn /= 10;
            if(c == x){
                m += c * p;
                p *= 10;
            }
        }
        x += 2;
    }

    cout << m;
    return 0;
}
*/

//d
/*
citește n
(număr natural nenul)
m <- 0; p <- 1
┌pentru x <- 1, 9, 2 executa
│ cn <- n
│┌cât timp cn != 0 execută
││ c <- cn % 10; cn <- [cn / 10]
││┌dacă c = x atunci
│││ m <- c * p + m; p <- p * 10
││└■
│└■
└■
scrie m
*/

//2
/*
struct biblioteca{
    int numar;
    struct Carte{
        char titlu[21], autor[21];
    }carte[100];
}c;
*/

//3
/*
cout: ou
      rosu

s = rosu
a b c d e f g h i j k l m n o p q r s t u v w x y z
*/


///SIII
//1
/*
int putere(int n, int p){
    int i = -1;
    for(int d = 2; d * d <= p; d++)
        if(p % d == 0)
            return i;
    i = 0;
    while(n % p == 0){
        i++;
        n /= p;
    }
    return i;
}

int main(){
    int n, p, x;
    cin >> n >> p;
    x = putere(n, p);
    cout << x;
}
*/

//2
/*
#include <iostream>
using namespace std;

int main(){
    int a[20][20], i, j, m, n, ok = 0;
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> a[i][j];
    for(i = 0; i < m; i++)
        for(j = 0; j < m; j++)
            if(a[i][0] == a[j][n - 1]){
                cout << a[i][0] << " ";
                j = m;
                ok = 1;
            }
    if(ok == 0)
        cout << "nepolarizat";
    return 0;
}
*/


//3
/*
int main(){
    ifstream fin("bac9.txt");
    int x, s;
    fin >> s;
    while(fin >> x){
        if(s + x < x)
            s += x;
        else
            s = x;
        cout << s << endl;
    }
    cout << s;
}
*/


///BAC 2024 Sesiune Speciala VAR4
///SI
//1 a
/*
!(x > 25 || y < 6)
x <= 25 && y >= 6
*/

//2 b
/*
cout: 545522
f(9)
    x = 22
        f(22)
            x = 55
                f(55)
                    x = 54
                    cout 54
            cout 55
    cout 22
*/

//3 d
/*
SV-68-CAB:  SV-68-BAC
SV-68-CAB:  TL-24-BAC
*/

//4 d
/*
t.achizitionare.an
*/

//5 c

///SII
//1
//a 1 1 3 1 5
/*
scrie: 1 1 3 1 5

n = 10
i = 1

m = 1

i = 2

m = 2
m = 1

scrie 1
. . .
*/

//b 16 17

//c
/*
#include <iostream>
using namespace std;

int main(){
    int n, i, m;
    cin >> n;
    i = 1;
    while(i <= n){
        m = i;

        while(m % 2 == 0)
            m /= 2;

        if(m != i)
            cout << m << " ";

        i += 1;
    }
}
*/

//d
/*
citeşte n
(număr natural, n >= 2)
┌pentru i <- 1, n executa
│ m <- i
│┌cât timp m % 2 = 0 executa
││ m <- [m / 2]
│└■
│┌dacă m != i atunci
││ scrie m,’ ’
│└■
└■
*/

//2
/*
[1,2], [2,3], [2,4], [2,5], [4,6]
*/

//3
/*
c = 0;
for(i = 1; i <= 10; i++){
    cin >> s;
    if(strlen(s) == 2)
        if(strchr("aeiou", s[0]) != NULL && strchr("aeiou", s[1]) == NULL)
            c = 1;
        else
            if(strchr("aeiou", s[1]) != NULL && strchr("aeiou", s[0]) == NULL)
                c = 1;
}
*/


///SIII
//1
/*
int fulg(int n){
    int x, a = 0, b = 0, c = 0, d = 0;
    if(n < 100000000)
        return 0;

    while(n){
        x = n % 10;
        if(x == 1)
            a = 1;
        else if(x == 2)
            b = 1;
        else if(x == 3)
            c = 1;
        else if(x == 4)
            d = 1;
        else
            return 0;

        n /= 10;
    }

    if(a == 1 && b == 1 && c == 1 && d == 1)
        return 1;
    else
        return 0;
}

int main(){
    int n;
    cin >> n;
    cout << fulg(n);
}
*/

//2
/*
int main(){
    int a[51][51], m, n, i, j, ci, cj;
    cin >> m >> n;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(i < j){
                cj = j;
                ci = i;
                while(cj){
                    ci *= 10;
                    cj /= 10;
                }
                a[i][j] = ci + j;
            }
            else{
                cj = j;
                ci = i;
                while(ci){
                    cj *= 10;
                    ci /= 10;
                }
                a[i][j] = cj + i;
            }

    for(i = 1; i <= m; i++){
        cout << endl;
        for(j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    }
}
*/


//3
//b
/*
int main(){
    ifstream fin("bac10.txt");

    int x, mx = 0, st = -1, fn = -1;
    while(fin >> x){
        if(x % 10 > mx){
            mx = x % 10;
            st = x;
            fn = -1;
        }
        else if(x / 10 == mx || x % 10 == mx){
            fn = x;
        }
        if(x / 10 > mx){
            mx = x / 10;
            st = x;
            fn = -1;
        }
        else if(x / 10 == mx || x % 10 == mx){
            fn = x;
        }
    }

    if(fn == -1)
        cout << "nu exista";
    else
        cout << st << " " << fn;
}
*/

//a
/*
Metoda va cauta mereu cea mai mare cifra din fisier,
la gasirea cifrei, cu ajutorul variabilei "st", se
va retine numarul unde s-a gasit cea mai mare cifra
pana la acel moment. Variabila "st" se va actualia pe
parcursul programului daca se va gasi o noua cea mai
mare cifra. Cu ajutorul variabilei "fn" se va retine
ultimul numar care contine cea mai mare cifra din fisier,
pana la moentul dat, dar se va actaliza de fiecare data cand
se gaseste o cifra mai mare cu -1, deaorece exista posinilitatea
ca cea mai mare cifra sa fie continuta de un singur numara,
asadar nu se poate crea un sir. In concluzie programul este
unul eficient deoarece toate operatiile se intapla pe parcursul
citirii fisierului.
*/



///BAC 2020 TEST 8
///SI
//1 b
/*
(x >= -2020 && x <= -2019) || (x >= 2019 && x <= 2020)
*/

//2 a
/*
578

5
55
555
557
558
57
577
578
58
7
*/

//3 c

//4 d

//5 b

///SII
//1
//a 202888
/*
x = 201920
y = 20

c = 0
x = 20192

c = 2
x = 2019
y = 202

c = 9
x = 202
y = 2028

c = 1
x = 20
y = 20288

c = 0
x = 2

c = 2
x = 0
y = 202888
*/

//b 101 110

//c
/*
#include <iostream>
using namespace std;

int main(){
    int x, y, c;
    cin >> x >> y;
    do{
        c = x % 10;
        x /= 10;

        if(c != 0){
            if(y % 10 < c)
                y = y * 10 + c;
            else
                y = y * 10 - c;
        }
    }while(x != 0);

    cout << y;
}
*/

//d
/*
citește x, y
(numere naturale)
┌cat timp x != 0 executa
│ c <- x % 10
│ x <- [x / 10]
│┌dacă c != 0 atunci
││┌dacă y % 10 < c atunci
│││ y <- y * 10 + c
│││altfel
│││ y <- y * 10 - c
││└■
│└■
└■
scrie y
*/

//2
/*
lant elemtar: 2, 1, 6, 5
ciclu neelementar: 2, 6, 5, 3, 6, 2
*/

//3
/*
cout: ou
      rosu

s = ou
s = rosu

a b c d e f g h i j k l m o p q r s t u v w x y z
*/


///SIII
//1
/*
int suma(int n){
    int s = 0, d;
    for(d = 2; d <= n; d++){
        if(n % d == 0){
            s += d;
            while(n % d == 0)
                n /= d;
        }
    }

    return s;
}

int main(){
    int n;
    cin >> n;
    cout << suma(n);
}
*/

//2
/*
#include <iostream>
using namespace std;

int main(){
    int a[21][21], k, n, i, j, x;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];

    x = a[k][1];
    for(i = 1; i < k - 1; i++)
        a[k][i] = a[k][i + 1];
    a[k][k - 1] = x;

    for(i = 1; i <= n; i++){
        cout << endl;
        for(j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    }
}
*/
/*
1 2 3 4 5 6
6 7 8 9 0 1
2 4 6 8 0 2
1 3 5 7 9 5
6 2 7 4 5 7
3 9 4 8 5 7
*/


//3
/*
int main(){
    ifstream fin("bac11.txt");

    int a[2][10] = {0}, i, n = 1, x;
    while(fin >> x){
        a[1][x % 10] = n;
        a[0][x % 10]++;
        n++;
    }

    x = 0;
    for(i = 1; i < 10; i++)
        if(a[0][i] > x)
            x = a[0][i];

    for(i = 1; i < 10; i++)
        if(a[0][i] == x)
        cout << a[1][i] << " ";
}
*/


///BAC 2020 TEST 9
///SI
//1 d

//2 b
/*
0 5: 0
1 4: 4
2 3: 2
3 2: 2
4 1: 4
5 0: 0
*/

//3 a
/*
{rosu, galben, verde, albastru, violet}
{r, g, ve, a, vi}
{1, 2, 3, 4, 5}

1 2 3
1 2 4
1 2 5
1 3 2
. . .
5 4 2 = {violet, albastru, galben}
5 4 3
*/

//4 c
/*
(2, 5, 4, 0, 4, 1, 5, 5, 3, 4)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
5: 2, 7, 8
*/

//5 b


///SII
//1
//a 1 1 1 2 2 2 3 3
/*
n = 8
k = 3
*/

//b 46 50

//c
/*
#include <iostream>
using namespace std;


int main(){
    int n, k, t, i, j;

    cin >> n >> k;
    t = 1;

    for(i = 1; i <= n / k; i++){
        for(j = 1; j <= k; j++)
            cout << t << " ";
        t += 1;
    }

    for(i = n % k; i >= 1; i--)
        cout << t << " ";
}
*/

//d
/*
citește n,k
(numere naturale nenule)
t <- 1
┌pentru i <- 1 ,[n / k] executa
│┌pentru j <- 1 ,k executa
││ scrie t,' '
│└■
│ t <- t+1
└■
i <- n % k
┌cat timp i >= 1 executa
│ scrie t, ' ';
│ i <- i - 1
└■
*/

//2 f(0) = 0; f(2020) = 6
/*
f(2020)
    return 0 + f(101) = 6
        f(101)
            return 1 + f(5)= 6
                f(5)
                    return 5 + f(0) = 5
                        f(0)
                            return 0
*/

//3 3 componente conexe cu nodurile
//(4, 7) apartinnad celei mai mica componente

///SIII
//1
/*
void suma(int n, int &s){
    int i, a[10] = {0};
    s = 0;
    while(n){
        if((n % 10) % 2 == 1)
            a[n % 10] = 1;
        n /= 10;
    }

    for(i = 1; i < 10; i += 2)
        if(a[i] == 1)
            s += i;
}

int main(){
    int n, s;
    cin >> n;
    s = 0;
    suma(n, s);
    cout << s;
}


//2
/*
int main(){
    char txt[20][21], pref[21], cuv[21];
    int n, i, ok = 0, x;
    cin >> n;
    n--;
    for(i = 0; i < n; i++)
        cin >> txt[i];
    cin >> pref;

    for(i = 0; i < n; i++){
        strcpy(cuv, txt[i]);
        if(strcmp(strcat(strstr(txt[i], pref), strstr(txt[i], pref) + strlen(pref)), txt[i]) == 0){
        //sau: if(strstr(txt[i], pref) == txt[i])
            cout << cuv << " ";
            ok = 1;
        }
    }
    if(ok == 0)
        cout << "nu exista";
}
*/
//3
/*
int main(){
    ifstream fin("bac12.txt");
    int x, mxnr = 0, s = 1, k, nr = 0;
    fin >> k;
    while(fin >> x){
        if(x % k == 0){
            nr++;
        }
        else{
            if(nr > mxnr){
                mxnr = nr;
                s = 1;
            }
            else{
                if(nr == mxnr)
                    s++;
            }
            nr = 0;
        }
        if(nr == mxnr)
            s++;
    }

    cout << mxnr << " " << s;
}
*/


///BAC 2020 TEST 10
///SI
//1 d

//2 b
/*
f(19, 20)
    f(18, 21)
        f(15, 22)
            f(8, 23)
                f(-8, 24)
*/

//3 c
/*
{cal, câine, papagal, porumbel, ponei}
{1, 2, 3, 4, 5}

1 3 5 - nu se afla in poz. alaturate

1 2 1 2
1 2 1 4
1 2 2 1
1 2 2 2
1 2 2 3
1 2 2 4
1 2 2 5
1 2 3 2
. . . .

2 . . 4
  1 2
  1 4
  2 1
  2 2
  2 3
  2 4
  2 5
  3 2
  3 4
  4 1
  4 2
  4 3
  4 4
  4 5
  5 2
  5 4
*/

//4 a

//5 c



///SII
//1
//a 60
/*
x = 16
y = 7

x = 7
y = 16

i = 7
j = 16
s = 0

s = 16
i = 8
j = 15

s = 24
i = 9
j = 14

s = 38
i = 10
j = 13

s = 48
i = 11
j = 12

s = 60
j = 12
j = 11

scrie 60

7  8  9  10 11
16 15 14 13 12
16 8 14 10 12
*/

//b 20, 21
/*
19 11 17 13 15 15

10 11 12 13 14 15
20 19 18 17 16 15
11 19 13 17 15 15

10 11 12 13 14 15
21 20 19 18 17 16
10 20 12 18 14 16
*/

//c
/*
#include <iostream>
using namespace std;

int main(){
    int x , y, i, j, s;
    cin >> x >> y;

    if(x > y){
        x += y;
        y = x - y;
        x -= y;
    }

    i = x;
    j = y;
    s = 0;

    do{
        s += (i % 2) * j + (j % 2) * i;
        i += 1;
        j -= 1;
    }while(i <= j);

    cout << s;
    return 0;
}
*/

//d
/*
citește x, y
(numere naturale nenule)
┌dacă x > y atunci
| x -> y
└■
i -> x; j -> y; s -> 0
┌cat timp i <= j executa
| s -> s + (i % 2) * j + (j % 2) * i
│ i -> i + 1; j -> j - 1
└■
scrie s
*/

//2
/*
struct spectacol{
    int cod, nrActori, varsta[4];
}s[20];
*/

//3
/*
for(i = 0; i < 4; i++){
    a[i][0] = 5 * (i + 1);
    for(j = 1; j < 5; j++)
        a[i][j] = a[i][j - 1] - 1;
}
*/

///SIII
//1
/*
void suma(int n, int &p){
    int i, a[10] = {0};
    p = 1;
    while(n){
        if((n % 10) % 2 == 0)
            a[n % 10] = 1;
        n /= 10;
    }

    for(i = 0; i < 10; i += 2)
        if(a[i] == 1)
            p *= i;
}

int main(){
    int n, p;
    cin >> n;
    p = 1;
    suma(n, p);
    cout << p;
}
*/

//2
/*
int main(){
    char txt[200], *ante, *post, s[200];
    int ok = 0;
    cin.getline(txt, 200);

    ante = strtok(txt, " ");
    strcpy(s, ante);
    post = strtok(NULL, " ");

    while(post != NULL){
        if(ante[strlen(ante) - 1] == post[strlen(post) - 1]){
            strcat(s, " scucces ");
            strcat(s, post);
            ok = 1;
        }
        else{
            strcat(s, " ");
            strcat(s, post);
        }

        strcpy(ante, post);
        post = strtok(NULL, " ");
    }


    if(ok == 1)
        cout << s;
    else
        cout << "nu exista";
}
*/

//3
/*
int main(){
    ifstream fin("bac13.txt");
    int a, b, c, l, lmx, r, rmx, aux;
    fin >> a >> b >> c;
    if(b - a == c - b){
        r = b - a;
        rmx = b - a;
        lmx = 2;
        l = 2;
    }
    while(fin >> a){
        aux = a;
        a = b;
        b = c;
        c = aux;
        if(b - a == r && c - b == r){
            l++;
        }
        else{
            l = 0;
            r = c - b;
        }
        if(l >= lmx){
            if(l > lmx)
                lmx = l;
            rmx = r;
        }
    }

    cout << rmx;
}
*/


///BAC 2020 TEST 11
///SI
//1 d

//2 d
/*
{azalea, begonia, vriesea, busuioc, feriga}
{a, be, v, bu, f}
{1, 2, 3, 4, 5}

1 4 2
1 4 3
1 5 2
1 5 3
2 4 1
2 4 3
2 5 1
2 5 3
3 4 1
*/

//3 a
/*
f(2020, 2)
     1 + f(1010, 2) = 2022
        f(1010, 2)
            1 + f(505, 2) = 2021
                f(505, 2)
                    return 2020
*/

//4 b
/*
1 - 2
2 - 4
4 - 8
2 - 16
*/

//5 c


///SII
//1
//a 10
/*
n = 45530
m = 0

c = 0
n = 4553
m = 0

c = 3
n = 455
m = 3

. . .
c = 4
n = 0
m = 10
*/

//b 1000, 1100

//c
/*
#include <iostream>
using namespace std;

int main(){
    int m, n, c;
    cin >> n;
    m = 0;

    if(n == 0)
        m = 10;
    else{
        do{
            c = n % 10;
            n /= 10;
            if(c >= m)
                m = c;
            else
                m = 10;
        }while(n);
    }

    cout << m;

    return 0;
}
*/

//d
/*
citeşte n (număr natural)
m <- 0
┌daca n = 0 atunci
│ m <- 10
│altfel
│┌cat timp n != 0 executa
││ c <- n % 10; n <- [n / 10]
││┌daca c >= m atunci
│││ m <- c
│││altfel
│││ m <- 10
││└■
│└■
└■
scrie m
*/

//2
/*
struct sera{
    int numar
    struct Specie{
        char denumireStiintifica[21];
        char denumirePopulara[21];
    }specie[100];
}s;
*/

//3
/*
p = 1;
for(i = 0; i < 7; i++)
    p *= a[i][i];

for(i = 6; i >= 0; i--){
    cout << p << " ";
    p /= a[i][i];
}
*/


///SII
//1
//a 952
/*
n = 2592
nr = 0
c = 9

m = 2592
m = 259

nr = 9

m = 2592
m = 259
m = 25
m = 2
m = 0
. . .
n = 952
*/

//b 2002 2020 2200

//c
/*
#include <iostream>
using namespace std;

int main(){
    int m , n, c, nr;
    cin >> n;

    nr = 0;
    c = 9;

    while(c >= 0){
        m = n;

        while(m != 0 && m % 10 != c)
            m /= 10;

        if(m != 0)
            nr = nr * 10 + m % 10;

        c--;
    }

    cout << nr;
    return 0;
}
*/

//d
/*
citește n (număr natural nenul)
nr <- 0
┌pentru c <- 9, 0, -1 executa
│ m <- n
│┌cat timp m != 0 și m % 10 <- c executa
││ m <- [m / 10]
│└■
│┌daca m <- 0 atunci
││ nr <- nr * 10 + m % 10
│└■
└■
scrie nr
*/

//2
/*
struct specii_flori{
    int cod, nrVarietati, nrExemplare[10];
}f[20];
*/

//3
/*
12456
13456
23456
*/


///SIII
//1
/*
void patrate(int x, int y){
    int i = 0, s = 0, ok = 0;

    while(i * i <= x)
        i++;

    for(i; i * i <= y; i++){
        ok = 1;
        if((i + 1) * (i + 1) >= y)
            cout << i * i;
        else
            cout << i * i << "+";
        s += i * i;
    }

    if(ok == 1)
        cout << "=" << s;
    else
        cout << "nu exista";
}

int main(){
    int x, y;
    cin >> x >> y;
    patrate(x, y);
}
*/

//2
/*
#include <iostream>
#include <string.>

using namespace std;

int main(){
    char s[101], *cuv, t[101];
    int i;
    cin.getline(s, 100);
    t[0] = '\0';
    cuv = strtok(s, " ");

    while(cuv != NULL){
        if(cuv[0] >= 'a' && cuv[0] <= 'z')
            cuv[0] -= 32;
        for(i = 1; i < strlen(cuv); i++)
            if(cuv[i] >= 'A' && cuv[i] <= 'Z')
                cuv[i] += 32;

        strcat(t, cuv);
        strcat(t, " ");

        cuv = strtok(NULL, " ");
    }

    strcpy(s, t);

    cout << s;
}
*/

//3
/*
int main(){
    ifstream fin("bac14.txt");

    int x, ante, nr;
    fin >> ante;
    nr = 1;

    while(fin >> x){
        if(x != ante){
            cout << ante << " " << nr << " ";
            nr = 1;
        }
        else
            nr++;

        ante = x;
    }

    cout << ante << " " << nr << " ";
}
*/



///BAC 2020 TEST 12
///SI
//1 d

//2 a

//3 b
/*
f(54321)
    f(5432)
        f(543)
            f(54)
                f(5)
                    f(0)
            cout << 4;
    cout << 2;
*/

//4 b

//5 c

///SIII
//1
/*
int pDoi(int n){
    int x = 1;
    while(x * 2 <= n)
        x *= 2;

    return x;
}

int main(){
    int n;
    cin >> n;
    cout << pDoi(n);
}
*/

//2
/*
int main(){
    char s[101];
    int i, x;
    cin.getline(s, 101);
    x = strlen(s);

    for(i = x - 1; i >= 0; i--)
        if(strchr("aeiou", s[i]) != NULL){
                strcpy(s + i, s + i + 1);
                i = -1;
        }


    if(strlen(s) != x)
        cout << s;
    else
        cout << "nu exista";
}
*/

//3
/*
int main(){
    int x = 0, n = 0, mx, a[10000];
    cin >> mx;

    while(x < mx){
        n++;

        if(n <= 10)
            x++;
        else if(n > 10 && n % 2 == 1)
                x *= 2;
        else
            x += 1;

        a[n - 1] = x;
    }

    for(int i = n - 1; i >= 0; i--)
        cout << a[i] << " ";
}
*/


///BAC 2020 TEST 13
///SI
//1 a

//2 d
/*
f(200200)
    2 * f(20020) = 320
        f(20020)
            2 * f(2002) = 160
                f(2002)
                    2 * f(200) = 80
                        f(200)
                            2 * f(20) = 40
                                f(20)
                                    return 20
*/

//3 a
/*
{5, 6, 7, 8}
5
55
555
557
565
567
57
575
577
585
587
65
*/

//4 c
/*
(2, 8, 2, 9, 8, 9, 0, 7, 7, 9)

1 3 4 5 6 10
*/

//5 b



///SII
//1
//a 10375
/*
n = 12345
p = 1
m = 0
k = 0

x = 25
i = 0
c = 5

m = 5
n = 1234
p = 10
k = 1


x = 2070
i = 1
x = 207
c = 7

m = 75
n = 123
p = 100
k = 2


x = 49
i = 2
x = 0
c = 3

m = 375
n = 12
p = 1000
k = 3


x = 270135
i = 3
x = 270
c = 0

m = 375
n = 1
p = 10000
k = 4

x = 21
i = 4
x = 0
c = 1

m = 10375
n = 0
p = 100000
k = 5

scrie 10375
*/

//b 1100, 1010, 1000

//c
/*
#include <iostream>
uisng namespace std;

int main(){
    int m , n, p, x, k, c, i;
    cin >> n;
    p = 1;
    m = 0;
    k = 0;

    while(n){
        cin >> x;
        i = k;

        while(i){
            x /= 10;
            i --;
        }

        if(x == 0)
            c = n % 10;
        else
            c = x % 10;


        m += c * p;
        n /= 10;
        p *= 10;
        k++;
    }

    cout << m;
}
*/

//d
/*
citeste n (numar natural)
p <- 1; m <- 0; k <- 0
┌cât timp n != 0 executa
│ citeste x (numar natural)
│ x <- [x / p]
│┌daca x = 0 atunci c <- n % 10
││altfel c <- x % 10
│└■
│ m <- c * p + m; n <- [n / 10]
│ p <- p * 10; k <- k + 1
└■
scrie m
*/

//2
/*
struct cerc{
    int raza;
    struct Centru_cerc{
        int x, y;
    }centru;
}c;
*/

//3
/*
cout: ou
      rosu
s = rosu

s[0] = s[0] + (0-1)*(1-0%2)+3*(2*0/3-1)*(0%2) = -1 = r
s[1] = s[0] + (1-1)*(1-1%2)+3*(2*1/3-1)*(1%2) = -3 = o
s[2] = s[0] + (2-1)*(1-2%2)+3*(2*2/3-1)*(2%2) = 1 = s
s[3] = s[0] + (3-1)*(1-3%2)+3*(2*3/3-1)*(3%2) = 3 = u
*/


///SIII
//1
/*
void putere(int n, int &d, int &p){
    int i, nrp;
    p = n;
    for(i = 2; i <= n; i++){
        if(n % i == 0){
            nrp = 0;
            while(n % i == 0){
                nrp++;
                n /= i;
            }
            if(nrp < p){
                d = i;
                p = nrp;
            }
        }
    }
}

int main(){
    int n, d = 0, p = 0;
    cin >> n;
    putere(n, d, p);

    cout << d << " " << p;
}


//2
/*
int main(){
    int a[400][20], n, k, i, j, x;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(x = 0; x < k; x++)
                a[i * k + x][j] = i + j + 1;


    for(i = 0; i < n * k; i++){
        cout << endl;
        for(j = 0; j < n; j++)
            cout << a[i][j] << " ";
    }
}
*/

//3
/*
int main(){
    int n, i = 1;
    cin >> n;
    while(i * 2 <= n)
        i *= 2;

    while(i){
        cout << i << " ";
        i /= 2;
    }
}
*/
/*
int main(){
    int n, x = 1, y = 2;
    cin >> n;
    while(3 * y - 2 * x <= n){
        y = 3 * y - 2 * x;
        x = (y + 2 * x)/ 3;
    }

    while(y >= 1){
        cout << y << " ";
        n = y;
        y = x;
        x = (3 * y - n)/ 2;
    }
}
*/


///BAC 2020 TEST 14
///SI
//1 a

//2 c
/*
f(2020, 20)
    f(101, 2000)
        f(0, -1899)
            return -1899
*/

//3 b
/*
{cască, costum de înot, cleme, dopuri de urechi, plută, mască de snorkeling, ochelari, snorkel}
{1,             2,        3,          4,           5,          6,               7,        8   }
{1,   2,   3,  4,  5,  6,   7,  8}
{40, 400, 30, 30, 10, 400, 70, 60}

1 2 3 4
1 2 8
1 3 4 6
2 3 5 8
2 3 7
*/

//4 c

//5 b

///SII
//1
//a 4188262
/*
n = 1527894
m = 0

c = 4
n = 152789
m = 4

c = 9
c = 1
n = 15278
m = 41
. . .
m = 4188262
*/

//b 90 900 9000

//c
/*
#include <iostream>
using namespace std;

int main(){
    int m , n, c;
    cin >> n;
    m = 0;
    do{
        c = n % 10;
        n /= 10;
        if(c == 9)
            c = 1;
        else if(c % 2 == 1)
            c += 1;
        m = m * 10 + c;
    }while(n);

    cout << m;
}
*/

//d
/*
┌cat timp n != 0 executa
│ c <- n % 10; n <- [n / 10]
│┌daca c = 9 atunci c <- 1
││altfel
││┌daca c % 2 = 1 atunci
│││c <- c+1
││└■
│└■
│ m <- m * 10 + c
└■
scrie m
*/

//2
/*
struct rasa{
    int cod, nrExemplare, varsta[10];
}r[20];
*/

//3
/*
for(i = 0; i < 5; i++)
    a[i][6] = 1;
for(i = 0; i < 7; i++)
    a[0][i] = 1;

for(i = 1; i < 5; i++)
    for(j = 5; j >= 0; j--)
        a[i][j] = (a[i - 1][j] + a[i][j + 1]) % 10;
*/


///SIII
//1
/*
void perechi(int n){
    int d, ok = 0;
    for(d = 1; d * d < n; d++)
        if(n % d == 0 && d % 2 != n / d % 2){
            cout << "[" << d << " " << n / d << "] ";
            ok = 1;
        }

    if(ok == 0)
        cout << "nu exista";
}

int main(){
    int n;
    cin >> n;
    perechi(n);
}
*/

//2
/*
int main(){
    char s[101];
    int i;
    cin.getline(s, 101);
    for(i = 0; i < strlen(s); i++)
        if(s[i] == '-')
            strcpy(s + i, s + i + 1);

    cout << s;
}
*/

//3
/*
int main(){
    int x, a = 0, b = 0, c = 0, mx , mn;
    ifstream fin("bac15.txt");
    while(c == 0){
        fin >> x;
        if(x % 100 == 20)
            if(a == 0)
                a = x;
            else if(b == 0)
                b = x;
            else
                c = x;
    }

    if(a > b && a > c)
        mx = a;

    if(b > a && b > c)
        mx = b;

    if(c > a && c > b)
        mx = c;

    if(a < b && a < c)
        mn = a;

    if(b < a && b < c)
        mn = b;

    if(c < a && c < b)
        mn = c;


    //mx = b
    //if(a > b)
        //mx = a;
    //if (c > mx)
        //mx = c;

    //mn = b;
    //if(a < b)
        //mn = a;
    //if (c < b)
        //mn = c;



    b = a + b + c - mx - mn;
    a = mn;
    b = mx;

    while(fin >> x){
        if(x % 100 == 20)
            if(x < c)
                if(x < b)
                    if(x < a){
                        c = b;
                        b = a;
                        a = x;
                    }
                    else{
                        c = b;
                        b = x;
                    }
                else
                    c = x;
    }

    cout << a << " " << b << " " << c;
}
*/


///BAC 2020 TEST 15
///SI
//1 b
//(x>=16) && ( x>=17 && x<=19) && (x<=20)

//2 c
/*
{creti, iacobini, jucatori, rotati, tobosari}
{c, i, j, r, t}
(1, 2, 3, 4, 5)

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
. . .
5 4 3 1 2
*/

//3 a

//4 c

//5 b


///SII
//1
//a scrie 2
/*
n = 5
nr = 0

i = 5

x = 0
y = 1

r = -1
x = 1
y = -1
j = 1

r = 3
x = -1
y = 3
j = 2

r = -5
x = 3
y = -5
j = 3

r = 11
x = -5
y = 11
j = 4

r = -21
x = 11
y = -21
i = 5

nr = 1
*/

//b 28 29


//c
/*
#include <iostream>
using namespce std;

int main(){
    int n, nr, x, y, r, i, j;
    cin >> n;
    nr = 0;
    for(i = n; i >= 1; i--){
        x = 0;
        y = 1;
        for(j = 1; j <= i; j++){
            r = 2 * x - y;
            x = y;
            y = r;
        }
        if(y > 0)
            nr += 1;
    }
    cout << nr;
    return 0;
}
*/

//d
/*
citeste n (numar natural)
nr <- 0; i <- n
┌cat timp i >= 1 executa
│ x <- 0; y <- 1
│ ┌pentru j <- 1, i executa
│ │ r <- 2 * x - y; x <- y; y <- r
│ └■
│ ┌daca y > 0 atunci
│ │ nr <- nr + 1
│ └■
│ i <- i - 1
└■
scrie nr
*/

//2 x1 = 4, x2 = 10
/*
2 + 2 + 1
10 4
6 4
2 4
2 2
*/

//3
/*
for(i = 0; i < 4; i++)
    for(j = 0; j < 5; j++)
        a[i][j] = i + 1 + 4 * j;
*/



///SIII
//1
/*
void divPrimMax(int n, int &p){
    for(p = 2; p <= n; p++)
        if(n % p == 0)
            while(n % p == 0)
                n /= p;
    p--;
}

int main(){
    int n, p = 0;
    cin >> n;
    divPrimMax(n, p);
    cout << p;
}
*/

//2
/*
int main(){
    char txt[101], *cuv;
    int c, v, i, nr = 0;
    cin.getline(txt, 101);
    cuv = strtok(txt, " ");
    while(cuv != NULL){
        c = 0;
        v = 0;
        for(i = 0; i < strlen(cuv); i++)
            if(strchr("aeiou", cuv[i]) != NULL)
                v++;
            else
                c++;
        if(c == v)
            nr++;
        cuv = strtok(NULL, " ");
    }

    cout << nr;
}
*/

//3
/*
int main(){
    int p1, p2, d1, d2, i, nr = 0;
    cin >> p1 >> p2;

    for(d1 = 1; d1 <= p1; d1++)
        if(p1 % d1 == 0 && p1 / d1 <= 9 && d1 <= 9)
            for(i = 0; i <= 9; i++)
                for(d2 = 1; d2 <= p2; d2++)
                    if(p2 % d2 == 0 && p2 / d2 <= 9 && d2 <= 9)
                        cout << d1 << p1 / d1 << i << i << i << d2 << p2 / d2 << endl;


}
*/


///BAC 2020 TEST 16
///SI
//1 b
/*
(x<17) || (x>18 && x<20) || (x>21)
*/

//2 c
/*
123
125
127
129
145
147
149
167
169
*/

//3 b

//4 c

//5 d


///SII
//1
//a 2020
/*
n = 812302105
k = 4

nr = 0
p = 1
c = 5
n = 81230210
k = 3

c = 0
n = 8123021
nr = 0
p = 10

c = 1
n = 812302
k = 2

c = 2
n = 81230
nr = 20
p = 100

c = 0
n = 8123
nr = 20
p = 1000

c = 3
n = 812
k = 1

c = 2
n = 81
nr = 2020
p = 10000

c = 1
n = 8
k = 0
*/

//b 122 144

//c
/*
#include <iostream>

using namespace std;

int main(){
    int n, k, c, nr, p;
    cin >> n >> k;
    if(k == 0)
        nr = -1;
    else{
        nr = 0;
        p = 1;
        do{
            c = n % 10;
            n /= 10;
            if(c % 2 == 0){
                nr += c * p;
                p *= 10;
            }
            else
                k -= 1;
        }while(n != 0 && k != 0);
    }
    cout << nr;
}
*/

//d
/*
citește n,k
(numere naturale)
┌daca k = 0 atunci nr <- -1
│altfel
│ nr <- 0
│ p <- 1
│┌cat timp n != 0 si k !=0 executa
││ c <- n%10; n <- [n/10]
││┌daca c % 2 = 0 atunci
│││ nr <- nr + c * p; p <- p * 10
│││altfel k <- k-1
││└■
│└■
└■
scrie nr
*/

//2
/*
scrie:5 3 1
      1 2 3 4 5
f(5)
    cout << 5;
    f(4)
        f(3)
            cout << 3;
            f(2)
                f(1)
                    cout << 1;
                    f(0)
                        cout << endl;
                    cout << 1;
                cout << 2;
            cout << 3;
        cout << 4;
    cout << 5;
*/

//3
/*
scrie: 15bac2020
s1 = bacalaureat2020
s2 = 2020
s1 = bac2020
*/


///SIII
//1
/*
int nrDivPrimi(int n){
    int d, nr, x = 0;
    for(d = 2; d <= n; d++)
        if(n % d == 0){
            nr = 0;
            while(n % d == 0){
                n /= d;
                nr++;
            }
            if(nr % 2 == 1)
                x++;
        }

    return x;
}

int main(){
    int n;
    cin >> n;
    cout << nrDivPrimi(n);
}
*/

//2
/*
int main(){
    int a[100][100], n, m, x = 1, i, j;
    cin >> n >> m;
    for(i = n - 1; i >= 0; i--)
        for(j = m - 1; j >= 0; j--){
            a[i][j] = x * x;
            x += 2;
        }

    for(i =0; i < n; i++){
        cout << endl;
        for(j = 0; j < m; j++)
            cout << a[i][j] << " ";
    }
}
*/

//3
/*
int main(){
    ifstream fin("bac16.txt");
    int a[10000], m, n, i, j, ante, x;
    fin >> m >> n;

    for(i = 0; i < m; i++)
        fin >> a[i];

    fin >> x;
    ante = x;
    i = 0;
    j = 0;
    while(i < m && j < n) {
        if(x < a[i]) {
            if(x%2 != ante%2) {
                cout << x << " ";
                ante = x;
            }
            fin >> x;
            j++;
        }
        else if (x > a[i]) {
            if (a[i]%2 != ante%2) {
                cout << a[i] << " ";
                ante = a[i];
            }
            i++;
        }
        else {
            if (x%2 != ante%2) {
                cout << x << " ";
                ante = x;
            }
            fin >> x;
            i++;
            j++;
        }
    }

    while(i < m){
        if(ante % 2 != a[i] % 2){
            cout << a[i] << " ";
            ante = a[i];
        }
        i++;
    }

    while(j < n){
            fin >> x;
        if(ante % 2 != x % 2){
            cout << x << " ";
            ante = x;
        }
        j++;
    }

    return 0;
}
*/



///BAC 2020 TEST 17
///SI
//1 d

//2 d
/*
f(2, 20)
    f(3, 19)
        f(5, 18)
            f(9, 17)
                f(17, 16)
                cout << 33;
            cout << 26;
        cout << 23;
    cout << 22;
cout << 22;
*/

//3 b
/*
{Hanging, Meteora, Sumela, Taktsang, Taung Kalat}
{   1,       2,      3,        4,         5     }
{1, 2, 3, 4, 5}
1 != 3 != 5

1 2 3
1 2 4
1 2 5
1 4 2
1 4 3
1 4 5
. . .
2 1 4
2 3 4
2 4 1
2 4 3
2 4 5
2 5 4
*/

//4 a

//5 b


///SII
//1
//a 35
/*
x = 3
y = 12

i = 3
j = 12
s = 0

s = 3
i = 4
j = 11

s = 14
i = 5
j = 10

s = 19
i = 6
j = 9

s = 28
i = 7
j = 8

s = 35
i = 8
j = 9

scrie 35
*/

//b x = 1, y = 9 si x = 2, y = 8
/*
1  2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
1 2 3 4 5
9 8 7 6 5
2 3 4 5
8 7 6 5
*/

//c
/*
#include <iostream>
using namespace std;

int main(){
    int x, y, i, j, s;
    cin >> x >> y;
    i = x;
    j = y;
    s = 0;
    while(i <= j){
        if(i % 2 == 0)
            s += j;
        if(j % 2 == 0)
            s += i;

        i += 1;
        j -= 1;
    }

    cout << s;
}
*/

//d
/*
citeste x, y
(numere naturale x <= y)
i <- x; j <- y; s <- 0
┌daca i <= j atunci
│┌repeta
││┌daca i % 2 = 0 atunci
│││ s <- s + j
││└■
││┌daca j % 2 = 0 atunci
│││ s <- s + i
││└■
││i <- i + 1; j <- j - 1
│└pana vand i > j
└■
scrie s
*/

//2
/*
struct obiectiv{
    int cod;
    struct data{
        int luna, zi;
    }dataInceput, dataFinal;
}ob;
*/

//3
/*
for(i = 0; i < 4; i++)
    for(j = 0; j < 5; j++)
        a[i][j] = 4 * 5 - i - 4 * j;
*/


///SIII
//1
/*
int maxim(int n){
    int x = -1;
    while(n != 0){
        if(n % 2 == 1 && n % 10 > x)
            x = n % 10;
        n /= 10;
    }

    return x;
}

int main(){
    int n;
    cin >> n;
    cout << maxim(n);
}
*/

//2
/*
int main(){
    char s[101], txt[201], *cuv;
    int i, ok;
    cin.getline(s, 101);
    txt[0] = '\0';

    cuv = strtok(s, " ");
    while(cuv != NULL){
        ok = 1;
        for(i = 0; i < strlen(cuv); i++)
            if(strchr("aeiou", cuv[i]) == NULL)
                ok = 0;
        if(ok == 1){
            strcat(txt, cuv);
            strcat(txt, " ");
        }

        strcat(txt, cuv);
        strcat(txt, " ");

        cuv = strtok(NULL, " ");
    }

    cout << txt;
}
*/

//3
/*
int main(){
    int v[1000], x, y, i, n, nr = 0, ok;
    ifstream fin("bac17.txt");
    fin >> n;

    for(i = 0; i < n; i++)
        fin >> v[i];

    while(fin >> x >> y){
        ok = 1;
        for(i = 0; i < n && ok == 1; i++)
            if(v[i] > y || x > v[n - 1])
                i = n;
            else if(v[i] >= x && v[i] <= y)
                    ok = 0;
        if(ok == 1)
            nr++;
    }

    cout << nr;
}
*/

/*
int main(){
    char s[101], *cuv, p[2];
    int i, ok, n = 0;
    cin.getline(s, 101);
    cuv = strtok(s, " ");

    while(cuv != NULL){
        ok = 0;
        p[0] = 'c';
        i = 0;
        while(p[0] == 'c' && i < strlen(cuv)){
            if(cuv[i] == 'a')
                p[0] = 'a';
            else if(cuv[i] == 'e')
                p[0] = 'e';
            else if(cuv[i] == 'i')
                p[0] = 'i';
            else if(cuv[i] == 'o')
                p[0] = 'o';
            else if(cuv[i] == 'u')
                p[0] = 'u';
            i++;
        }

        if(p[0] == 'c')
            ok = 1;
        else{
            if(p[0] == 'a')
                for(i; i < strlen(cuv); i++)
                    if(strchr("eiou", cuv[i]) != NULL){
                        i = strlen(cuv);
                        ok = 1;
                    }
            if(p[0] == 'e')
                for(i; i < strlen(cuv); i++)
                    if(strchr("aiou", cuv[i]) != NULL){
                        i = strlen(cuv);
                        ok = 1;
                    }
            if(p[0] == 'i')
                for(i; i < strlen(cuv); i++)
                    if(strchr("eaou", cuv[i]) != NULL){
                        i = strlen(cuv);
                        ok = 1;
                    }
            if(p[0] == 'o')
                for(i; i < strlen(cuv); i++)
                    if(strchr("eiau", cuv[i]) != NULL){
                        i = strlen(cuv);
                        ok = 1;
                    }
            if(p[0] == 'u')
                for(i; i < strlen(cuv); i++)
                    if(strchr("eioa", cuv[i]) != NULL){
                        i = strlen(cuv);
                        ok = 1;
                    }
        }
        if(ok == 0){
            cout << cuv << endl;
            n = 1;
        }

        cuv = strtok(NULL, " ");
    }

    if(n == 0)
        cout << "nu exista";
}
*/

/*
int main(){
    int n, x, v[10] = {0}, i, j;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        while(x != 0){
            v[x % 10]++;
            x /= 10;
        }
    }
    for(i = 9; i >= 0; i--)
        if(v[i] != 0)
            for(j = 0; j < v[i]; j++)
                cout << i;
}
*/


/*
int main(){
    int n, x, nr = 1, a;
    cin >> n;
    cin >> a;
    for(int i = 0; i < n - 1; i++){
        cin >> x;
        if(a > x)
            nr++;
    }

    cout << nr;
}
*/


/*
int main(){
    int m[2][10] = {{0}}, i, n, mx = 0, x, a;

    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> x;
        a = x % 100 / 10;
        m[0][a]++;
        m[1][a] = i;

        if(m[0][a] > mx)
            mx = m[0][a];
    }

    for(i = 0; i < 10; i++)
        if(mx == m[0][i])
            cout << m[1][i] << " ";
}
*/


int main(){
    ifstream fin("bac18.txt");
    int ante, x, a, b, mxa, mxb;

    fin >> ante;
    mxa = 0;
    mxb = 0;

    while(fin >> x){
        if(ante + 1 == x){
            a = ante;
            while(ante + 1 == x){
                ante = x;
                fin >> x;
            }

            b = ante;

            if(mxb - mxa < b - a){
                mxb = b;
                mxa = a;
            }
        }
        ante = x;
    }


    if(mxb - mxa != 0)
        for(x = mxa; x <= mxb; x++)
            cout << x << " ";
    else
        cout << "nu exista";

}
