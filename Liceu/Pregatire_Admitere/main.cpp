#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

///poli var
//1
/**/

//2
/**/

//3
/**/

//4
/**/

//5
/**/

//6
/**/

//7
/**/

//8
/**/

//9
/**/

//10
/**/

//11
/**/

//12
/**/

//13
/**/

//14
/**/

//15
/**/


///varianta 1 unibuc 2019
//1 b
/*
n = 4

1;1 1;2 1;3 1;4
2;1 2;2 2;3 2;4
3;1 3;2 3;3 3;4
4;1 4;2 4;3 4;4

2 3 4 5
3 4 5 6
4 5 6 7
5 6 7 8

2 3 0 1
3 0 1 2
0 1 2 3
1 2 3 0

suma de pe diagonala secundara este 4 adica n


1;1 1;2 1;3 1;4 1;5
2;1 2;2 2;3 2;4 2;5
3;1 3;2 3;3 3;4 3;5
4;1 4;2 4;3 4;4 4;5
4;1 5;2 5;3 5;4 5;5

2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
6 7 8 9 10

2 3 4 0 1
3 4 0 1 2
4 0 1 2 3
0 1 2 3 4
1 2 3 4 0
*/


//2 c
/*
99 98 96 97 95 94 93 92 91 90
1  2  3  4  5  6  7  8  9  10
cand i este 1 sunt 98 de perechi
cand i este 2 sunt 97 de perechi
cand i este 3 sunt 96 de perechi
...
cand i este 96 sunt 3 de perechi
cand i este 97 sunt 2 de perechi
cand i este 98 este 1 pereche

notez cu a numarul total de perechi

a = (98 + 1 )* 98 / 2 = 99 * 49 = 4851
*/


//3 b


//4 c

//5 d

//6 a
/*
1 1
1 1
1 1


1 1 1
1 1 1
1 1 1
1 1 1


1 1 1 1
1 1 1 1
1 1 1 1


1 1 1
1 1 1
*/


//7 c

//8 c

//9 d

//10 c

/*int main()
{
    int x, p, n, i, nr;
    for(i = 2000; i < 4000; i++){
        x = 0;
        p = 1;
        n = i;
        while(n > 0){
            x += (n % 10 - n % 2) * p;
            p *= 10;
            n /= 10;
        }
        if(x == i){
            nr++;
            cout << x << " ";
        }
    }
    cout << endl << nr;
}*/

/*
0  2  4  6  8
20 22 24 26 28
40 42 44 46 48
60 62 64 66 68
80 82 84 86 88
*/

//11 c
/*
1, 3, 4
*/

//12 b

//13 d

//14 c

/*
{v,c,v,c,v}
{v,c,v,c,c}
{v,c,c,v,c}
{v,c,c,c,v}
{c,v,c,v,c}
{c,v,c,c,v}
{c,c,v,c,v}
A(3,3) * A(3,2) + 6 * A(2,3) * A(3,3) = 6 * 6 + 6 * 6 * 6 = 252
*/


//15 d

/*
c2 = C

c1 = C

p = 9

c2 = C

c1 = T

p = 11

c2 = T

c1 = I

p = NULL
*/


///Problema 4-E4 – Codare semnal imagine

/*int main()
{
    int m, n, **a , v1, v2[255] = {0}, i, j, nr = 0;
    cin >> m >> n;
    v1 = m * n;

    a = (int **)malloc(m * sizeof(int *));
    for(i = 0; i < m; i++)
        *(a + i) = (int *)malloc(n * sizeof(int));

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        cin >> *(j + *(a + i));

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            *(v2 + *(j + *(a + i))) = 1;

    for(i = 0; i < 255; i++)
        if(*(v2 + i) == 1)
            nr += 1;

    nr *= 2;

    cout << v1 - nr;
}*/
/*
3
4

2 2 1 3
4 3 2 4
2 4 4 4
*/

///procesor RISC

/*int main()
{
    int *r, n, val, dst, src, src0;
	char op[10];
    cin >> n;

    r = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++){
		cin >> op;
		if(strcmp(op, "lconst") == 0){
			cin  >> dst >> val;
			r[dst] = val;
		}

		if(strcmp(op, "add") == 0){
			cin >> dst >> src0 >> src;
			r[dst] = r[src0] + r[src];
		}

		if(strcmp(op, "mul") == 0){
			cin >> dst >> src0 >> src;
			r[dst] = r[src0] * r[src];
		}

		if(strcmp(op, "div") == 0){
			cin >> dst >> src0 >> src;
			r[dst] = r[src0] / r[src];
		}

		if(strcmp(op, "print") == 0){
			cin >> dst;
			cout << r[dst] << endl;
		}
	}

}*/

/*
8
lconst 0 10
print 0
lconst 2 1
add 1 0 2
mul 2 0 1
lconst 1 2
div 0 2 1
print 0
*/


///varianta 1 unibuc 2023
//1 c

//2 b

//3 c

//4 b
/*
int main()
{
    int nr = 0, v[100000], i, j;

    for(i = 0; i < 256; i++)
        v[i] = 0;

    for(i = 2; i <= 256 - 1; i++){
        if(v[i] == 0){
            v[i * i] = 2;
            j = i + 1;

            while(i * j < 256){
                v[i * j] = 1;
                j += 1;
            }
        }

        if(v[i] == 2){
            cout << i << " ";
            nr += 1;
        }
    }
    cout << endl << nr;
}
*/

//5 a
/*
1 1
2 1
3 2
4 6
5 24
*/

//6 d

//7 d

//8 a
/*
1
2 4 6 8 12 14 16 18 20 22
3 6 9 12 15 18 21
5 10 15 20
7 14 21
11 22
13
17
19
23
*/

//9 d
/*
strlen(s) = 12
s = re2023admite

k = 12
*/

//10 b
/*
v = [5, -5, 3, -3, 1, -2, 2, -4, 4]
v = [5, 5, 3, 3, -1, 2, 2, 4, 4]
*/

//11 b
/*
4 3 2 1
4 3 1 2
4 2 1 3
4 1 2 3
3 4 2 1
3 4 1 2
3 2 4 1
*/

//12 d
/*
2 3 32 323 32332 ...
4 5 54 545 54554 ...
5 6 65 656 65665 ...
...
9 10 109 10910 10910109
10 21 2110
...
49 90



1 1 2 3 5 8 13 21 34 55 89 144 233 377
2 2 4 6 10 16 26 42 68 110 178 288
*/

//13 ?

//14 c

//15 b


///admitere uniBUC iulie 2017
//1 c

//2 d

//3 c

//4 c

//5 a

//6 a
/*

4 * 4!= 96

51234 - 97
51243 - 98
51324 - 99
51342 - 100
51423 - 101
*/

//7 a

//8 c

//9 a

//10 c
/*
s = calculatoare
j = 12
i = 1

j = 11
i = 2

j = 9
i = 3

j = 6
i = 4

j = 2
i = 5

i = 3
*/

/*int main()
{
    char s[20];
    int i, j;
    strcpy(s,"calculatoare");
    i=0; j=strlen(s);
    while(j>i){
    j=j-i;i++;
    cout << i << " " << j << endl;
    }
    cout << i << " ";
    i=strchr(s,s[i]) - s + 1;
    cout << i;
}*/

//11 b
/*
1 4 9 16 25

9 16 25 1 4
*/


//12 d

//13 d
/*
n = 4
1 2 3 4
1 - 2
1 - 3
1 - 4
2 - 3
2 - 4
3 - 4
*/

//14 c
/*
1 - 1
2 - 2
3 - 4
4 - 8
5 - 16
6 - 32
*/

//15 b


///poli var 4
//1 d

//2 a
/*d1: -a
    --
    b

d2: -a
    --
    b

d1.a/d1.b = d2.a/d2.b
*/


//3 e

//4 a
/*
int a, b;

void f(int a, int &b)
{
    if(a > 0){
        a++;
        b--;
        f(b, a);
    }
    cout << a << " " << b << " ";
}

int main()
{
    a = 0;
    b = 1;

    f(b, a);
    cout << a << "  " << b;
}

a = 0
b = 1
f(1, 0)
a = 1
b = 0

a = 2
b = -1
f(-1, 2)
a = -1
b = 2

cout: -1 2 2 -1 -1 1
*/


//5 e
/*
m = 0
n = 42015

m = 15
n = 420

m = 1520
n = 4

m = 152004
n = 0
*/

//6 d

//7 e
/*
1 2 3
4 5 6
7 8 9

7 4 1
8 5 2
9 6 3

1;1 1;2 1;3
2;1 2;2 2;3
3;1 3;2 3;3

3;1 2;1 1;1
3;2 2;2 1;2
3;3 2;3 1;3

b[i][j] = a[n - j + 1][i]

1;1 = 3;1
1;2 = 2;1
1;3 = 1;1
2;1 = 3;2
2;2 = 2;2
2;3 = 1;2
3;1 = 3;3
3;2 = 2;3
3;3 = 1;3
*/

//8 c

//9 b

//10 f

//11 a

//12 f

//13 b

//14 d

//15 d
/*
5! / 2!*(5 - 2)! + 5! / 3!*(5 - 3)! + 5! / 4!*(5 - 4)! =
= 4 * 5 / 2 + 4 * 5 / 2 + 5 =
= 4 * 5 + 5 =
= 25
*/


///poli var 5
//1 e

//2 b

//3 c
/*
s = admitere

i = 0
s[0] = a
s = dmitere

i = 1
s[1] = m
s = dmitere

i = 2
s[2] = i
s = dmtere

i = 3
s[3] = e
s = dmtre

i = 4
s[4] = e
s = dmtr
*/

//4 d

//5 d

//6 e

//7 b

//8 a

//9 c
/*
s = s + a[i][1] + a[i][4]
*/

//10 b
/*
avion

v, n - consoane
a, i, o - vocale
v---n:
aio
aoi
iao
ioa
oai
oia

n---v:
aio
aoi
iao
ioa
oai
oia
*/

//11 a
/*
void f(int x, int &y)
{
    int aux;
    aux = x;
    x = y;
    y = aux;
}
*/

//12 a

//13 e

//14 e

//15 b


///poli var 6
//1 b

//2 c

//3 a
/*
a = matematica
strstr = em atica
b = atica
*/

//4 b

//5 d

//6 b

//7 b

//8 b

//9 b

//10 a

//11 d

//12 c

//13 a
/*
I: x > 0, y > 0
III: x < 0, y < 0

x, y = (0, +inf);
x, y = (-inf, 0);

x = R \ {0};
y = R \ {0};
*/

//14 b

//15 b


///poli var 7
//1 b

//2 c

//3 d
/*
(46, 17, 10, 4, 3)
*/

//4 e
/*
3 4 7 10 12 17 18 20 46
0 1 2 3  4  5  6  7  8
         1  3  2
*/

//5 f
/*
5, 6, 7 - 3 numere

sqrt 33 = floor 5,.. = 5
sqrt 34 = floor 5,.. = 5
sqrt 35 = floor 5,.. = 5
sqrt 36 = floor 6    = 6
sqrt 37 = floor 6,.. = 6
sqrt 38 = floor 6,.. = 6
sqrt 39 = floor 6,.. = 6
sqrt 40 = floor 6,.. = 6
sqrt 41 = floor 6,.. = 6
sqrt 42 = floor 6,.. = 6
sqrt 43 = floor 6,.. = 6
sqrt 44 = floor 6,.. = 6
sqrt 45 = floor 6,.. = 6
sqrt 46 = floor 6,.. = 6
sqrt 47 = floor 6,.. = 6
sqrt 48 = floor 6,.. = 6
sqrt 49 = floor 7    = 7
*/

//6 d
/*
{a, b, c, d, e, f}
{1, 2, 3, 4, 5, 6}

combinari de 6 luate cate 3 =
= 6! / 3! * 3! = 4 * 5 * 6 / 6 = 4 * 5 = 20
*/

//7 e
/*
ex(c)
    ex(b)
        ex(a)
            cout << a
        cout << a
        ex(a)
            cout << a
    cout << b
    ex(b)
        ex(a)
            cout << a
        cout << a
        ex(a)
            cout << a
*/

//8 f

//9 c

//10 d

//11 d

//12 f

//13 c

//14 f

//15 d


///poli var 8
//1 e
/*
(x < -4 || x > -1) && (x < 1 || x > 4) && x < 10
*/

//2 c

//3 f

//4 e

//5 c

//6 d
/*
5 * 7 * 2 = 70
5 * 6 * 7 * 8 = 1680
*/

//7 e
/*
ex(512)
    a = ex(51) = 5
        a = ex(5) = 9
            ex(0)
                return 9
        return 5
    return 1
return 1
*/

//8 d

//9 b

//10 f
/*
(e.sex == 'F' || e.sex == 'f') && (e.dn.z >= 1 && e.dn.z <= 10) && e.dn.l == 7
*/

//11 c

//12 f

//13 e

//14 c

//15 d


///poli var 9
//1 b
/*
1 3
n = n /1000 * 1000 + n % 1000 / 100 * 10 + n % 100 / 10 * 100 + n % 10
*/

//2 f
/*
x <= 2 || x <= 5 && x > -5
*/

//3 d
/*
acbb
*/

//4 d
/*
a
0 1 0 1
0 0 1 0
1 0 0 0
1 0 1 0
1;2 1;4 2;3 3;1 4;1 4;3

b
0 0 1 0
0 0 0 1
1 0 0 0
0 1 0 0
1;3 2;4 3;1 4;2

c
0 1 1 1
1 0 1 0
1 1 0 0
1 0 0 0
1;2 1;3 1;4 2;1 2;3 3;1 3;2 4;1

d
1;3 2;4 3;1 3;4 4;2 4;3
*/

//5 d
/*
1;1 1;2 1;3 1;4
2;1 2;2 2;3 2;4
3;1 3;2 3;3 3;4

:1 7 18 35
:2 6 11 17
:3 4 5 6
*/

//6 b

//7 e
/*
1 2 3 1
1 5 3 1
5 4 3 5
1 5 4 3 1
5 3 2 1 5
1 2 3 4 5 1
*/

//8 d

//9 e

//10 e
/*
da: x = 3, y = 4, r = 5
nu: x = 5, y = 4, r = 3

x.c.x < x.r && x.c.y < x.r
*/
//11 a
/*
y[x[i]] = x[y[i]]

y[1] = x[1]
y[2] = x[2]
y[4] = x[3]
y[3] = x[4]

x = {1, 2, 4, 3}
y = {1, 2, 3, 4}
*/

//12 a
/*
a, b, d, e, f, g, h, i , j, k, l , m
4jklm
*/

//13 b
/*
x = 1
y = -3

void f(int x)
{
    x = x + 1;
    y = 2 * x + 3;
}
void g(int x)
{
    int a, b;
    a = x + y;
    b = x - y;
    f(a);
    b(b);
    y = y + b;
}

a = -2
b = 4
x = -1
y = 1
x = 5
y = 13
y = 17
*/

//14 d

//15 e
/*
f(a, 2, 5)
a = (0, 1, 1, 3, 4, 4, 5)
a = (0, 5, 3, 4, 2, 0)
a = (0, 2, 2, 3, 4, 5, 5)
a = (0, 4, 3, 4, 2, 2, 1)

x[5] > x[4] > x[3] > x[2]

f(a, 2, 5)
    if(f(a, 2, 3) > 0 && f(a, 3, 5) > 0)
        if(x[4] > x[3])
        f(a, 2, 3)
            if(f(a, 2, 2)[1] > 0 && f(a, 3, 3)[1] > 0)
                if(x[3] > x[2])
                f(a, 2, 2)
                    return 1
                f(a, 3, 3)
                    return 1
        f(a, 3, 5)
            if(f(a, 4, 5) > 0 && f(a, 5, 5)[1] > 0)
                if(x[5] > x[4])
                f(a, 4, 5)
                    if(f(a, 4, 4)[1] > 0 && f(a, 5, 5)[1] > 0)
                        if(x[5] > x[4])
                        f(a, 4, 4)
                            return 1
                        f(a, 5, 5)
                            return 1
                f(a, 5, 5)
                    return 1

*/

///poli var 10
//1 c

//2 d
/*
n = (n - n % 10 + 2) * 10 + n % 10

2
*/

//3 b

/*int main()
{
    int i, j;
    for(i = 1; i <= 100; i++){
        j = i;
        cout << i << "   ";
        while(j != 0){
            cout << j % 2;
            j /= 2;
        }
        cout << endl;
    }
}*/

//4 d
/*
typedef struct{
    float st, dr;
}interval;

interval v[20], m;
*/

//5 a
/*
f(f(772125) + f(97917) = 2 + 7 = 9)
    f(772125)
        return 2

    f(97917)
        return 7

    return -1
*/

//6 f
/*
{1, 2, 3, 4, 5, 6, 7}
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6 7
1 2 3 4 5 7
1 2 3 4 6
1 2 3 4 6 7
1 2 3 4 7
*/

//7 e

//8 b

//9 c

//10 b

//11 c
/*
423222
g(4)
    i = 4
        cout 4
        g(2)
            i = 2
                cout << 2
                g(0)
            i = 1
    i = 3
        cout 3
        g(2)
            i = 2
                cout << 2
                g(0)
            i = 1
    i = 2
        cout 2
        g(2)
            i = 2
                cout << 2
                g(0)
            i = 1
*/

//12 d
/*
a 9-a valoare
numarul de valori afisate


1;1 1;2 1;3 1;4 1;5 1;6 1;7 1;8
2;1 2;2 2;3 2;4 2;5 2;6 2;7 2;8
3;1 3;2 3;3 3;4 3;5 3;6 3;7 3;8
4;1 4;2 4;3 4;4 4;5 4;6 4;7 4;8
5;1 5;2 5;3 5;4 5;5 5;6 5;7 5;8
6;1 6;2 6;3 6;4 6;5 6;6 6;7 6;8
7;1 7;2 7;3 7;4 7;5 7;6 7;7 7;8
8;1 8;2 8;3 8;4 8;5 8;6 8;7 8;8

1 9  17 25 33 41 49 57
2 10 18 26 34 42 50 58
3 11 19 27 35 43 51 59
4 12 20 28 36 44 52 60
5 13 21 29 37 45 53 61
6 14 22 30 38 46 54 62
7 15 23 31 39 47 55 62
8 16 24 32 40 48 56 64

i = 3
i <= 6
19 20 21 22

i = 4
i <= 6
30 38 46

i = 5
i >= 3
45 44:al 9-lea numar afisat 43

i = 5
i > 3
36 28

12 numre afisate
*/

//13 f
/*
s = bacaacbc
t = ab
    ac
    bc
s = bacaacbcbc

cout << acbc10bacaacbcbc
*/

//14 d
/*
void p(int k, int v[100])
{
    int w[100];
    v[0] = w[0] = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)
                v[j] = 1;
            else if(i == j)
                    v[j] = 1;
                else
                v[j] = w[j - 1] + v[j];
        }
        for(int j = 0; j <= i; j++)
            w[j] = v[j];
    }
}
*/

//15 e
/*
80
*/


///poli var 11
//1 e

//2 c

//3 f
/*
c) e^(1/2 * ln(n)) = e ^ ln(n) ^ 1/2 = n ^ 1/2
f) e^(1/3 * ln(n)) = e ^ ln(n) ^ 1/3 = n ^ 1/3
*/

//4 d

//5 d

//6 c
/*
n = 16327
1 2 1 2 1
*/
/*int main(){
    int a = 9, n;
    n = 16327;
    while(n != 0){
        switch(n % 10){
            case 0:

            case 2:

            case 4:

            case 6:

            case 8:
                a += n%2;
                break;
       }

       switch(n % 10){
            case 1:

            case 3:

            case 5:

            case 7:

            case 9:
                a -= n%2;
                break;
       }
       n /= 10;
    }
    cout << a;
}*/
//7 a
/*
70 - 39 = 31
*/

//8 f

//9 d

//10 e
/*
s = 123abc4567
nr = 0
n = 10
nr = nr * 10 + s[n - i - 1] - '0'
i = 0
nr = 0 + s[10 - 0 - 1] - '0' = s[9] - '0' = '7' - '0' = 7
i = 1
nr = 70 + s[10 - 1 - 1] - '0' = 70 + s[8] - '0' = 70 + '6' - '0' = 76
i = 2
nr = 760 + s[10 - 2 - 1] - '0' = 760 + s[7] - '0' = 760 + '5' - '0' = 765

765
*/

//11 b
/*
f(1, n)
se vor aduna numerele diviziblile cu de 3 de la 1 pana la 3n
*/

//12 b
/*
{e, r, p, n, f}
{1, 2, 3, 4, 5}
1 2 3
1 2 4
1 2 5
. . .
4 5 3 = {n, f, p}
5 1 2
*/

//13
/**/

//14
/**/

//15
/**/

/*int prim(int x){
    for(int d = 2; d * d <= x; d++)
        if(x % d == 0)
            return 0;
    return 1;
}

int main()
{
    int n, nr = 0, mxnr = 0, x = 0, i, d;
    cin >> n;
    for(i = n; i >= 2; i--){
        nr = 0;
        for(d = 2; d <= i; d++)
            if(i % d == 0 && prim(d) == 1){
                nr++;
            }
        if(mxnr < nr){
            mxnr = nr;
            x = i;
        }
    }
    cout << x;
}*/


/*int main(){
    int n, v[50], i, x = 1;
    cin >> n;
    i = n - 1;
    while(i != -1){
        if(x % 3 != 0 && x % 2 == 1){
            v[i] = x;
            i--;
        }
        x++;
    }
    for(i = 0; i < n; i++)
        cout << v[i] << " ";
}*/


/*int main(){
    ifstream fin("bac.txt");

    int a = 0, b = 0, x, k;
    fin >> k;
    while(k > 9)
        k /= 10;
    while(fin >> x){
        if(k == x % 10){
            a = b;
            b = x;
        }
    }
    if(a == 0 || b == 0)
        cout << "Nu exista";
    else
        cout << a;
}*/


///poli var 12
//1 b

//2 a

//3 d

//4 f

//5 a

//6 e

//7 c
/*
{#, *, &, @, %}
{1, 2, 3, 4, 5}

1 2 3 4
1 2 3 5
1 2 4 3
1 2 4 5
1 2 5 3
1 2 5 4
1 3 2 4
. . .
3 1 5 4 = {&, #, %, @}
3 2 1 4
*/

//8 d

//9 a

//10 d
/*
s = 123abc45678
nr = 0; n = 11; p = 1;
i = 0; s[i] >= '0' && s[i] <= '9'
nr += p * (s[n - i - 1] - '0')

i = 0
nr = 0 + 1 * (s[11 - 0 - 1] - '0') = '8' - '0' = 8
p = 10;

i = 1
nr = 8 + 10 * (s[11 - 1 - 1] - '0') = 8 + 10 *('7' - '0') = 78
p = 100

i = 2
nr = 78 + 100 * (s[11 - 2 - 1] - '0') = 8 + 10 *('6' - '0') = 678


nr = 678
*/

//11 b

//12 e
/*
int n = 4, p = 3, x = 0, s[100];
int f(int k){
    int i, j, ok;
    if(k == p + 1)
        x++;
    else
        for(i = 1; i <= n; i++){
            s[k] = i;
            ok = 1;
            for(j = 1; j < k; j++)
                if(s[k] == s[j])
                    ok = 0;

            if(ok)
                f(k + 1);
        }
}
n = 4, p = 3
k = 1;
s[1] = 1
ok = 1

s[1] = 2
ok = 1

k = 2
s[2] = 1

k = 2
s[2] = 1
*/


//13 c

//14 d
/*
f(1, n, n)
f(1, 12, 12)
    f(a, 6, 12) + f(7, 12, 12)
*/

//15 c



///poli var 16
//1 d

//2 a

//3 a

//4 f

//5 a
/*
5 8 4 0 4 5 3 6 7 8
1 2 3 4 5 6 7 8 9 10
*/

//6 c
/*
n = 5
11 12 13 14 15
21 22 23 24 25
31 32 33 34 35
41 42 43 44 45
51 52 53 54 55

25 34 43 52
*/

//7 a
/*
initaial: x < -10 || !(!( x >= 10) || x >= 100)
final: x < -10 || x >= 10 && x < 100
*/

//8 e
/*
a:
    3 7  3 7
    4 6  4 6
    8 2  7 3
    1 10 9 2

x = 3478
x = 3479
x = 3480
x = 3481
*/

//9 b
/*
n*(n - 1)/2 = 20 => n*(n - 1) = 40 => n^2 - n - 40 = 0
delta = 1 + 160 =  161
n1 = (1 + 12,...)/2 = 6,... => n = 7
*/

//10 f

//11 a

//12 c

//13 c

//14 d

//15 e



///poli var 17
//1 b

//2 d

//3 c
/*
sp(3) = 90
    return sp(2) + 3 * 4 * 5; = 30 + 60 = 60
    sp(2)
        return sp(1) + 2 * 3 * 4; = 6 + 24 = 30
            sp(1)
                return 6;
*/

//4 a
/*
3^2020
e^(2020 * ln 3) = e ^ ln 2 ^ 2020
*/

//5 f
/*
1010 noduri
2020 muchi
100 componente conexe

numarul ciclomatic
m - n + p
m = noduri
n = muchii
p = componente conexe

*/

//6 e
/*
text = oli 2020
*/

//7 d
/*
text = Bucuresti 2020 ADMIS
2 4 0 8 2 0 2 0 1 7  3  1
1 2 3 4 5 6 7 8 9 10 11 12
*/

//8 a
/*
12 camasi
8 pantaloni
9 cravate

96 * 9
810 + 54 = 864

108 * 8
800 + 64 = 864
*/

//9 f
/*
n < 17 - 3 * n / -n
17 - 4*n > 0
4 * n < 17
n < 4,25
*/

//10 f
/*
$$$$$
este un numar impar afisat de "$"
*/

//11 a
/*
n = 6
a[1][1] = (2 * 1 + 1)/2
a[2][2] = (2 * 2 + 2)/2
a[3][3] = (2 * 3 + 3)/2
a[4][4] = (2 * 4 + 4)/2
a[5][5] = (2 * 5 + 5)/2
a[6][6] = (2 * 6 + 6)/2

S = (2 * 1 + 1 + 2 * 2 + 2 + . . . + 2 * 6 + 6) / 2
S = [2 * (1 + 2 + . . . + 6) + 1 + 2 + . . . + 6] / 2
S = [n *(n + 1) + n *(n + 1) / 2] / 2
S =  3 * n * (n + 1) / 4
S = 3/4 * n *(n + 1)


*/

//12 c

//13 f

//14 c

//15 a



///poli var 18
//1 b

//2 d
/*
p = [a / b]
*/

//3 b
/*
sp(5)
    return sp(4) + 1.0 /(5 * 6) = 0.64 + 1/30 = 0.79 + 0.03 = 0.82
    sp(4)
        return sp(3) + 1.0/(4 * 5) = 0.56 + 1/20 = 0.74 + 0.05 = 0.79
        sp(3)
            return sp(2) + 1.0/(3 * 4) = 0.66 + 1/12 = 0.66 + 0.8 = 0.74
            sp(2)
                return sp(1) + 1.0/(2 * 3) = 0.5 + 1/6 = 0.5 + 0.16 = 0.66
                sp(1)
                    retrun 0.5

*/

//4 a
/*
p = 0;
for(k = 0; k <=n; k++)
    p += (n - k) * pow(x, k);
*/

//5 f
/*
32768 = 2^15
2^[(n-1)*n/2] = 2^15 => n = 6
*/

//6 f
/*
text = 0202 iloP '\0'
*/

//7 d
/*
text = Politehnica Bucuresti 2020XXXXXXXXXXXX
4

nou = XXXXXXXXXXXXBucuresti 2020
*/

//8 f
/*
echipa de 5
exact 2 ingineri si restul inginere

24 - ingineri
24 * 3 = 72 - inginere

24 * 23 / 2 = 12 * 23 = 276
72 * 71 * 70 / 6 = 24 * 71 * 35 = 59,640

276 * 59,640 = 16,460,640
*/

//9 c

//10 d

//11 a
/*
(3 * 1 + 2 * n)/2
(3 * 2 + 2 * (n - 1))/2
(3 * 3 + 2 * (n - 2))/2
(3 * 4 + 2 * (n - 3))/2
(3 * 5 + 2 * (n - 4))/2
. . .
(3 * n + 2 * 1)/2
______________________(+)

(3 * (n+1) * n / 2 + 2 * (n+1) * n / 2)/2
(n * (n + 1) * 5)/4
5/4 * (n + 1) * n
*/

//12 c
/*
struct S1 { int a; char b;};
struct S2 { float a; double b;};
struct S3 { struct S1 a;
            struct S2 b;}aa, bb;

bb.b.b = double
*/

//13 e
/*
a = 2020
b = 17
a * b = 34,340
2020 / 17 = 118
118 * 17 = 2006

f(2020, 17)
. . .
    f(14, 17)
        f(14, 3)
            f(11, 3)
                f(8, 3)
                    f(5, 3)
                        f(2, 3)
                            f(2, 1)
                                f(1, 1)
                                    cout << 34,340 << " " << 1;
*/

//14 a

//15 d



///poli var 19
//1 b

//2 e

/*
a = 1
i = 2
i < n && a > 0
*/

//3 f

//4 d
/*
{3, 8, 5, 5, 0, 8, 3, 5, 1, 7,  7,  5,  4,  3,  6}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
3: 1, 7, 14
1: 9
7: 10, 11
14: -
*/

//5 c
/*
void q(int &x, int y)
10 2 10 10
*/

//6 b
/*
24 * 23 / 2 = 12 * 23 = 276
*/

//7 a
/*
u = 4
v = 4
4++*++4
4++*5
cout << 20;
cout << v;
*/

//8 f

//9 e

//10 a

//11 c

//12 b
/*
progresie geometrica
b1 = 1
q = 2

(2^38 - 1) / 2 - 1 = 2^38 - 1
*/

//13 a
/*
f(int &y, int x)
cout << 42 72 152 1518
x = 15
y = 18

f(&y(x = 4), x(y = 2))
    x = 3
    y = 7

f(&y(x = 7), x(x = 7))
    x = 8
    y = 15

f(&y(y = 2), x(x = 15))
    x = 16
    y = 18

*/

//14 b
/*
3(n-1) + n(n-1)
(n-1)(n + 3)
*/

//15 a
/*
 f(3, 1)
    f(2, 1) 1
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)

    f(2, 1) 2
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)

    f(2, 1) 3
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)

    f(2, 1) 4
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)
        f(1, 1)
            f(0, 1)
*/



/*int main(){
    int n, v[100], smx, s, a[100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    smx = v[0];

    for(int i = 0; i < n; i++){
        s = v[i];
        for(int j = i + 1; j < n; j++){
            if(s > smx)
                smx = s;
            s += v[j];
        }
    }

    a[0] = v[0];
    for(int i = 1; i < n; i++){
        if(a[i - 1] + v[i] > v[i])
            a[i] = a[i - 1] + v[i];
        else
            a[i] = v[i];
        if(a[i] > smx)
            smx = a[i];
    }

    cout << smx;
}*/


/*int main(){
    int n, v[100], x[100], nr, nrmx = 0, aux = 0, a = 0, b = -1, i;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    x[0] = 0;
    nr = 1;
    for(i = 1; i < n; i++){
        x[i] = v[i] - v[i - 1];
        if(x[i] >= 0)
            nr++;
        else{
            if(nr > nrmx){
                nrmx = nr;
                a = aux;
                b = i;
            }
            aux = i;
            nr = 1;
        }
    }
    if(nr > nrmx){
        nrmx = nr;
        b = i;
    }

    cout << a << " " << b << endl;

    for(int i = a; i < b; i++)
        cout << v[i] << " ";
    cout << endl << nrmx;
}*/



///poli var 20
//1 b
/*
f(720, 2) = 5
    1 + f(360, 3)
        1 + f(120, 4)
            1 + f(30, 5)
                1 + f(6, 6)
                    1 + f(1, 7)
                        return 0


f(120, 3) = 3
    1 + f(40, 4)
        1 + f(10, 5)
            1 + f(2, 6)
                return 0

f(120, 1) = 5
    1 + f(120, 2)
        1 + f(60, 3)
            1 + f(20, 4)
                1 + f(5, 5)
                    1 + f(1, 6)
                        return 0

f(720, 1) = 6
    1 + f(720, 2)
        1 + f(360, 3)
            1 + f(120, 4)
                1 + f(30, 5)
                    1 + f(6, 6)
                        1 + f(1, 7)
                            return 0
*/

//2 b

//3 c

//4 b
/*
x > -1 && y < 3
a) (y - 3)(x + 1) > 0
xy + y - 3x - 3
__x___|____-1_____3_____
 f(x) |-----0+++++++++++
 f(y) |-----------0+++++
  f   |+++++0-----0+++++
din tabel => (y > 3 && x > -1) || (y < 3 && x < -1)


x + 1 > 0
y - 3 < 0
___________(*)
(x + 1)*(y - 3) < 0

*/

//5 a
/*
n = 231045

0 1 4 5
0 2 3 5
0 2 3 1 4
*/

//6 b
/*
{a, b, c, u, i, e}

{a, b, c, e, i, u}
{1, 2, 3, 4, 5, 6}
1 2 4
1 2 5
1 2 6
1 3 4
1 3 5
1 3 6
1 4 2
1 4 3
1 5 2
*/

//7 c
/*
{2, 3, 5, 7}
2 2 2 2 2 2
2 2 2 3 3
3 3 3 3
2 2 3 5
2 3 7
2 5 5
5 7
*/

//8 a
/*
{info, mate, fizica, chimie, biologie}
{o, te, a, mie, gie}


{a, gie, mie, te, o}
{1, 2, 3, 4, 5}
1 2 3
1 2 4
1 2 5
. . .
2 4 5 = {biologie, mate, info}
3 4 5
*/

//9 c

//10 a

//11 e

//12 e
/*
i = 4 8 12 14 16 18 20 22 24 26
cout: 4 8 3 5 7 9 2 4 6 8
*/

//13 b
/*
4 3 4 = 311
s = 3; p = 4
s(4)
    return 3 * s(3) - 4 * s(2) = 3 * 112 + 4 * 35 = 226 + 85 = 311
        s(3)
            return 3 * s(2) + 4 * s(1) = 3 * 35 + 4 * 3 = 105 + 12 = 117
                s(2)
                    return 3 * s(1) + 4 * s(0) = 3 * 3 + 4 * 2 = 27 + 8 = 35
                        s(1)
                            return 3
                        s(0)
                            return 2
                s(1)
                    return 3


4 2 3
s = 2
p = 3
s(4)
    return 2 * s(3) - 3 * s(2) = 2 * 26 + 3 * 10 = 82
        s(3)
            return 2 * s(2) + 3 * s(1) = 2 * 10 + 3 * 2 = 26
                s(2)
                    return 2 * s(1) + 3 * s(0) = 2 * 2 + 2 * 3 = 4 + 6 = 10
                        s(1)
                            return 2
                        s(0)
                            return 2
                s(1)
                    return 2
        s(2)
            return 2 * s(1) + 3 * s(0) = 2 * 2 + 2 * 3 = 4 + 6 = 10
                s(1)
                    return 2
                s(0)
                    return 2
*/

//14 b
/*
n, k
max n = 7, max k = 3
matrice pt t:
0 1 2 3 4 5 6
1 0 1 2 3 4 5
2 1 0 1 2 3 4
3 2 1 0 1 2 3
4 3 2 1 0 1 2
5 4 3 2 1 0 1
6 5 4 3 2 1 0

2 3 4  5  6  7  8
3 4 5  6  7  8  9
4 5 6  7  8  9  10
5 6 7  8  9  10 11
6 7 8  9  10 11 12
7 8 9  10 11 12 13
8 9 10 11 12 13 14

n = 6, k = 2
n - k + 1 = 5
n + k + 1 = 9
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1


n = 6, k = 1
n - k + 1 = 6
n + k + 1 = 8
1 1 2 2 1 1
1 1 1 1 1 1
2 1 1 1 1 2
2 1 1 1 1 2
1 1 1 1 1 1
1 1 2 2 1 1
*/

//15 c
/*
1;1 1;2 1;3
2;1 2;2 2;3
3;1 3;2 3;3

a[i][j] = j + 3*(i - 1)
1 2 3
4 5 6
7 8 9

 3   5   7   2   4   1
1;3 2;2 3;1 1;2 2;1 1;1
alpha = j
beta = 4 - j + k
*/



///poli var 21
//1 d

//2 d
/*
A(-2;-2)
B(-2;2)
C(2;-2)
D(2;2)
X(x, y)

bob.x >= -2 && bob.x <= 2 && bob.y >= -2 && bob.y <= 2
*/

//3 c

//4 d

//5 c

//6 c
/*
a b c d e
f g h i j
k l m n
*/

//7 d

//8 c

//9 d
/*
m = 4

a b k d e
f g r i j
n o c l m
p q h s t

aux = k

*/

//10 b
/*
a = 5
b = 10
c = 15

f(a, b, c)

a = 5
b = 20
c = 30

f(a, a, b)

a = 15
b = 35
c = 30
*/

//11 d
/*
capitan 1 - Andrei
capitan 2 - Mariana
cercetatori - Alina, Dana, Marius
Andrei, Mariana, Alina, Dana, Marius
{1, 2, 3, 4, 5}
1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 3 4 2 5
1 3 4 5 2
Andrei, Alina, Dana, Marius, Mariana
*/

//12 d

//13 d

//14 a
/*
i = 1 2 3 4
j = 1 1 2 1 2 3 1 2 3 4
k = 1 1 1 2 1 1 2 1 2 3 1 1 2 1 2 3 1 2 3 4
cout 1 + 3 + 6 + 10 + 15 + 21 + 28 + 36 + 45 + 55
220
*/

//15 d


///poli var 22
//1 c

//2 b

//3 c

//4 d

//5 b
// x^3 3*x^2 - 2*x + 1

//6 a
/*
i = 3
cout << 3 + f(g(3)) = 3 + f(6) = 3 + 15 = 18
    g(3)
        return 6
    f(6)
        return 6 + g(6) = 6 + 9 = 15
            g(6)
                return 9
*/

//7 d

//8 d

//9 b
/*
cout << 1 1 1 1 6
*/

//10 d
/*
a = caiet
n = 5
i = 0
i = 1
a = caiiet
n = 6
a = caiiiet
n = 7
a = capaiet
i = 4
a = capaieet
n = 8
a = capaieeet
n = 9
a = capaipiet
i = 7
a = capaipiett
n = 10
a = capaipiettt
n = 11
a = capaipiepet
i = 10
i = 11

a = capaipiepet
*/

//11 a
/*
f(30)
    return f(f(37)) = f(46) = 47
        f(37)
            return f(f(44)) = f(47) = 46
                f(44)
                    return f(f(51)) = f(46) = 47
                        f(51)
                            return 46
                        f(46)
                            return f(f(53)) = f(48) = 47
                                f(53)
                                    return 48
                                f(48)
                                    return f(f(55)) = f(52) = 47
                                        f(55)
                                            return f(f(62)) = f(57) = 52
                                                f(62)
                                                    return 57
                                                f(57)
                                                    return 52
                                        f(52)
                                            return 47
                f(47)
                    return f(f(54)) = f(49) = 46
                        f(54)
                            return 49
                        f(49)
                            return f(f(56)) = f(51) = 46
                                f(56)
                                    return 51
                                f(51)
                                    return 46
        f(46)
            return f(f(53)) = f(48) = 47
                f(53)
                    return 48
                f(48)
                    return f(f(55)) = f(52) = 47
                        f(55)
                            return f(f(62)) = f(57) = 52
                                f(62)
                                    return 57
                                f(57)
                                    return 52
                        f(52)
                            return 47
*/

//12 d
/*
1 2 3
1 2 4
1 2 5
1 3 2
1 3 4
1 3 5
1 4 2
1 4 3
1 4 5
1 5 2
*/

//13 b

//14 d
/*
cout << 5 4 3 1
*/

//15 d



///poli var 23
//1 c

//2 f

//3 c
/*
i = 1
i = 2
i = 4
i = 8
i = 16
i = 32
i = 64
*/

//4 e
/*
s = 2020+2020=4040
s = 00+00=00
*/

//5 b

//6 c
/*
x = 15
x = 14

x = 7
x = 2
x = 1
x = -4
*/

//7 d
/*
abcd
a + b + c + d = 4
1003
1012
1021
1030
1102
1111
1120
1201
1210
1300
2002
2011
2020
*/

//8 a

//9 e
/*
struct a{
    int b;
    char c[10];
};

struct d{
    char e[10];
    float f;
    a g;
}h;
*/

//10 e

//11 f
/*
{1, 2, 3, 4, 5, 6}
{6, 3, 1, 3, 2, 1}
a[a[6]] = a[1] = 2 * 6 % 7 = 5
a[a[5]] = a[2] = 2 * 5 % 7 = 3
a[a[4]] = a[3] = 2 * 4 % 7 = 1
a[a[3]] = a[6] = 2 * 3 % 7 = 6
*/

//12 c
/*
f(2020, 2) = 4
    return 1 + f(1010, 2) = 4
        f(1010, 2)
            return 1 + f(505, 2) = 3
                f(505, 2)
                    return f(505, 3) = 2
                        f(505, 3)
                            return f(505, 4) = 2
                                f(505, 4)
                                    return f(505, 5) = 2
                                        f(505, 5)
                                            1 + return f(101, 5) = 2
                                                . . .
                                                    f(101, 101)
                                                        1 + return f(1, 101) = 1
                                                            f(1, 101)
                                                                return 0
*/

//13 d
/*
28 * 64
*/

//14 f

//15 f
/*
{3, 4, 2, 5, 1, 7, 6}
{3, 2, 4, 5, 1, 7, 6} 1
{3, 2, 4, 1, 5, 7, 6} 2
{3, 2, 4, 1, 5, 6, 7} 3
{2, 3, 4, 1, 5, 7, 6} 4
{2, 3, 1, 4, 5, 7, 6} 5
{2, 1, 3, 4, 5, 7, 6} 6
{1, 2, 3, 4, 5, 7, 6} 7
*/


///poli var 24
//1 d
/*
n = {1, 3, 5, 7, 9}
*/

//2 f

//3 d

//4 c
/*
d = ratie
*/

//5 b
/*
1 - 3
2 - 2
3 - 3
5 - 4
7 - 3
8 - 3
*/

//6 a
/*
n = 0
a = 11357
b = 1426
p = 1

x = 7
y = 6
n = 6
p = 10
a = 1135
b = 142

x = 5
y = 2
n = 26
p = 100
a = 113
b = 14

x = 3
y = 4
n = 326
p = 1000
a = 11
b = 1

x = 1
y = 1
n = 1326
p = 10000
a = 1
b = 0

x = 1
y = 0
n = 1326
p = 100000
a = 0
b = 0
*/

//7 c

//8 c

//9 e
/*
{r, o, m, a, n}
{a, m, n, o, r}
{1, 2, 3, 4, 5}
norma
34521

inainte: 34512 - noram
dupa: 35124 -nramo
*/

//10 c
/*
orama maro
k = 1
oramamaro
k = 0

orama alba
k = 0

oramaalba
*/

//11 d
/*
f(f(3)) = f(5)
    f(3)
        return f(2) + 2 * f(0) = 5
            f(2)
                return f(1) + 2 * f(-1) = 3
                    f(1)
                        return 1
                    f(-1)
                        return 1
            f(0)
                return 1
    f(5)
        return f(4) + 2 * f(2)
            f(4)
                return f(3) + 2 * f(1)
                    f(3)
                        return f(2) + 2 * f(0)
                            f(2)
                                return f(1) + 2 * f(-1) = 3
                                    f(1)
                                        return 1
                                    f(-1)
                                        return 1
                    f(1)
                        return 1
            f(2)
                return f(1) + 2 * f(-1) = 3
                    f(1)
                        return 1
                    f(-1)
                        return 1

*/

//12 c
/*
1 2 3 10
5 6 9 8
8 7 6 5
4 3 2 1
*/

//13 f
/*
int f(int x){
    if(x >= 100)
        return x + 2;
    else
        return f(f(x + 2) + 1)
}
f(95)
    return f(f(97) + 1) = f(110) = 112
        f(97)
            return f(f(99) + 1) = f(107) = 109
                f(99)
                    return f(f(101) + 1) = f(104) = 106
                        f(101)
                            return 103
                        f(104)
                            return 106
                f(107)
                    return f(109)
        f(110)
            return 112

+40 = 2 * 20
f(59)
    return f(f(61) + 1)
        f(61)
            return f(f(63) + 1)
                f(63)
                    return f(f(65) + 1)
                        . . .
                            f(99)
                                return f(f(101) + 1) = f(104) = 106
                                    f(101)
                                        return 103
                                    f(104)
                                        return 106
*/

//14 e
/*
v = (3, 8, 2, 7) = 25
     2  4  1  3
     1  3  2  4

x = (4, 5, 1, 7) = 33
     2  3  1  4
     1  3  2  4

y = (4, 7, 9, 6) =
     1  3  4  2

z = (6, 3, 2, 9) =
     3  2  1  4
*/

//15 f




///poli var 25 (77 min)
//1 b

//2 a
/*
cout: 167238945
i = 4
j = 0
i = 3
j = 1
i = 2
j = 2
i = 1
j = 3
i = 0
j = 4
*/

//3 a

//4 e

//5 f

//6 e
/*
114
123
132
141
213
222
231
312
321
411
*/

//7 a
/*
a = examen
a = xxmmnn
*/

//8 b
/*
void numar(int n){
    if(n <= 100)
        cout <<'\n';
    else{
        if(n % 10 < 5)
                cout << n % 10;
        numar(n/10);
        if(n % 10 > 5)
            cout << n % 10;
    }
}
nr(824972345)
cout: 4324
      79
*/

//9 b
/*
a = 360
b = 0
c = 2

a = 180
a = 90
a = 45
b = 1
c = 3
a = 15
a = 5
b = 2
c = 4
c = 5
a = 1
b = 3
c = 6
*/

//10 c
/*
i = 0
while(i <= 3){
    if(v[i] < 5)
        v[i] = 2*v[i];
    if(v[7 - i] > v[i])
        v[7 - i] = v[7 - i] - v[i];
    i += 1;
}

v = {5, 8, 1, 3, 6, 7, 4, 9}
v = {5, 8, 2, 6, 6, 5, 4, 4}
i = 3
*/

//11 d

//12 a
/*
a = (1, 2, 3, 4, 5, 6, 7)
*/

//13 d
/*
int c, i, nr = 0;
for(i = 200; i <= 300; i++){
    c = i;
    while(c != 0){
        if(c % 2 == 1)
            nr++;
        c /= 10
    }
}
cout << nr;

abc
nr += 1:
b = 0, 2, 4, 6, 8
c = 1, 3, 5, 7, 9

b = 1, 3, 5, 7, 9
c = 0, 2, 4, 6, 8

nr += 2:
b = 1, 3, 5, 7, 9
c = 1, 3, 5, 7, 9

300
*/

//14 c

//15 b
/*
cout: 541703296325840
n = 4
k = 8
i = 1, 2, 3, 4
cout: 5
k = 7
i = 4, 3
cout: 41
k = 6
i = 1, 2, 3, 4
cout: 703
k = 5
i = 4, 3, 2, 1
cout: 2963
k = 4
i = 1, 2, 3, 4
cout: 258
k = 3
i = 4, 3, 2, 1
cout: 4
k = 2
i = 1, 2, 3, 4
cout: 0
k = 1
*/



///poli var 26 (30 min)
//1 e

//2 b
/*
v = (3, 5, 8, 4, 2, 6, 9, 1)
v = (5, 3, 4, 8, 6, 2, 1, 9)
*/

//3 f
/*
a = poLItEHnica
a b c d e f g h i j k l m
*/

//4 d
/*
0;0 0;1 0;2 0;3
1;0 1;1 1;2 1;3
2;0 2;1 2;2 2;3
3;0 3;1 3;2 3;3

0 1 2 3
1 2 2 4
2 2 4 3
3 4 3 6
*/

//5 d

//6 d
/*
a = {1, 4, 5, 8, 9}
1458
1498
1854
1894
4185
4189
4581
4589
4981
4985
5418
5498
5814
5819
8145
8149
8541
8549
8941
8945
9418
9458
9814
9854
*/

//7 f

//8 d

//9 b

//10 d
/*
cout: 53078520
n = 4
k = 8
i = 4, 3, 2, 1
cout: 5
k = 6
i = 4, 3, 2, 1
cout: 307
k = 4
i = 4, 3, 2, 1
cout: 852
k = 2
i = 4, 3, 2, 1
cout: 0
k = 0
*/

//11 f
/*
c = 3
abc(t, 3)
    return abc(3*t-1, 2)
        abc(3*t-1, 3)
            return abc(3*(3*t-1)-1, 1)
                abc(3*(3*t-1)-1, 1)
                    return abc(3*(3*(3*t-1)-1)-1, 0)
                        abc(3*(3*(3*t-1)-1)-1, 0)
                            return 3*(3*(3*t-1)-1)-1
*/

//12 d
/*
a:
bacalaureat
liceu
examene
politehnica
cout << a[1][2] << a[2][4] << a[3][6] << a[4][8];
cout: cuei
*/

//13 a
/*
int f1(int x, int &y){
    x += 2;
    y -= 1;
    return x + y;
    x += 1;
}

int main(){
    int n = 3, m = 6;
    cout << f1(f1(m, n), m)
    cout << " " << m;
}
m = 5
n = 2
f1(f1(6, 3), 6) = f1(10, 6) = 17
    f1(6, 3)
        x = 8
        y = 2
        return 10
    f1(10, 6)
        x = 12
        y = 5
        return 17
*/

//14 e
/*
n = 3
q = 2
b[1][1] += a[1][1] * a[1][1]
b[1][1] += a[1][2] * a[2][1]
b[1][1] += a[1][3] * a[3][1]

b[1][2] += a[1][1] * a[1][2]
b[1][2] += a[1][2] * a[2][2]
b[1][2] += a[1][3] * a[3][2]

b[1][3] += a[1][1] * a[1][3]
b[1][3] += a[1][2] * a[2][3]
b[1][3] += a[1][3] * a[3][3]
*/

//15 f




///poli var 27
//1 b

//2 b

//3 f

//4 a

//5 c

//6 e
/*
10*9/2 = 5*9 = 45
*/

//7 e
/*
0;0 0;1 0;2 0;3 0;4
1;0 1;1 1;2 1;3 1;4
2;0 2;1 2;2 2;3 2;4
3;0 3;1 3;2 3;3 3;4
4;0 4;1 4;2 4;3 4;4

25 24 23 22 21
20 19 18 17 16
15 14 13 12 11
10 9  8  7  6
5  4  3  2  1

25 + 19 + 13 + 7 + 1 = 65
*/

//8 c

//9 c
/*
p o l i
1 2 3 4

i l o p
1 2 3 4

pilo
4123
poli
4321
*/

//10 a

//11 b
/*
f(a, b)
f(24, 34) = 31
    return r = 2 + f(25, 34) = 31
        f(25, 34)
            return r = 1 + f(26, 33) = 29
                f(26, 33)
                    return r = f(26, 31) = 28
                        f(26, 31)
                            return r = f(26, 29) = 28
                                f(26, 29)
                                    return r = 1 + f(27, 28) = 28
                                        f(27, 28)
                                            return r = f(27, 26) = 27
                                                f(27, 26)
                                                    return r = 27

*/

//12 f

//13 d

//14 b

//15 d




///poli var 28
//1 d

//2 c

//3 f

//4 e
/*
1 4 6 7 10 13 16 19 21 22
0 1 2 3 4  5  7  8  9  10
15
*/

//5 b
/*
0;0 0;1 0;2 0;3 0;4
1;0 1;1 1;2 1;3 1;4
2;0 2;1 2;2 2;3 2;4
3;0 3;1 3;2 3;3 3;4
4;0 4;1 4;2 4;3 4;4

0 -1 -2 -3 -4
1 0  -1 -2 -3
2 1  0  -1 -2
3 2  1  0  -1
4 3  2  1  0

5 4 3 2 1
6 5 4 3 2
7 6 5 4 3
8 7 6 5 4
9 8 7 6 5
2 * 2 + 4 * 4 + 6 * 4 + 8 * 2 = 4 + 16 + 24 + 16 = 60
*/

//6 b
/*
int f(int n){
    int r = 0;
    while(r * r < n){
        r++;
    }
    return r * r - n;
}
*/

//7 d

//8 c

//9 a

//10 f
/*
cout: 012013
s(3)
    cout: 012
        f(-1)
        f(0)
        f(1)
            f(1)
                cout:0
                f(-1)
                cout: 1
    cout: 3

*/

//11 b

//12 d

//13 e

//14 a

//15 c




///poli var 29
//1 c
/*
(n - 1) / 2
*/

//2 b
/*
(18, 91, 1, 15, 102)
(1, 15, 102, 18, 91)
*/

//3 c

//4 b
/*
(10, 24, 9, 11, 33, 7, 15)


(10, 9, 24, 11, 33, 7, 15)
(10, 9, 11, 24, 33, 7, 15)
(10, 9, 11, 24, 7, 33, 15)
(10, 9, 11, 24, 7, 15, 33)
(9, 10, 11, 24, 7, 15, 33)
(9, 10, 11, 7, 24, 15, 33)
(9, 10, 11, 7, 15, 24, 33)
(9, 10, 7, 11, 15, 24, 33)
(9, 7, 10, 11, 15, 24, 33)
(7, 9, 10, 11, 15, 24, 33)
*/

//5 f

//6 c
/*
f(a, b)
f(2019, 2347) = 2349
    return f(201, 234) * 10 + 9 = 234 * 10 + 9 = 2349
        f(201, 234)
            return f(20, 23) * 10 + 4 = 23 * 10 + 4 = 234
                f(20, 23)
                    return f(2, 2) * 10 + 3 = 2 * 10 + 3 = 23
                        f(2, 2)
                            return f(0, 0) * 10 + 2 = 2
                                f(0, 0)
                                    return 0

*/

//7 d
/*
(4, 6, 14, 25, 61, 73, 82, 87, 95, 96, 98)
*/

//8 e

//9 b
/*
(20 * 20 - 20) / 2 = 380 / 2 = 190
*/

//10 d

//11 c

//12 f

//13 f

//14 c
/*
caracter
ABCDEFGH
87654321
*/

//15 b




///poli var 30
//1 c

//2 d

//3 f

//4 b

//5 e
/*
algoritmul lui eucild pentru cmmdec si cmmmc
*/

//6 b

//7 e

//8 d

//9 e
/*
z = s(f(1), f(1)) = s(2, 2) = 4

f(1)
    return 2

s(2)
    return 4
*/

//10 d
/*
101
103
107
109
113
119
121
127
129
131

133
137
139
143
149
151
157
161
163
167

169
173
181
187
191
193
197
199
*/


//11 a

//12 d
/*
ADV: 1, 3, 4

23456
23457
23458
23459
23467
23469
23478
23479
23489
23567

23568
23569
23678
23679
23689
24567
24568
24569
24578
24579

24589
24789
25678
25679
25689
25789
26789
*/

//13 d

//14 b
/*
n * (n - 1) = 20 => n = 5
*/

//15 c
/*
E1, E2
*/



///poli var 31
//1 d
/*
n = 8080
*/

//2 a
/*
cout: 234
x = 0
y = 3, 2, 1, 0
cout: 2
x = 1
y = 3, 2, 1
cout: 3
x = 2
y = 3, 2
cout: 4
x = 3
y = 3
*/

//3 f
/*
1;1 1;2 1;3 1;4 1;5 1;6
2;1 2;2 2;3 2;4 2;5 2;6
3;1 3;2 3;3 3;4 3;5 3;6
4;1 4;2 4;3 4;4 4;5 4;6
5;1 5;2 5;3 5;4 5;5 5;6
6;1 6;2 6;3 6;4 6;5 6;6

0 0 0 0 0 0
1 1 1 1 1 1
2 0 2 0 2 0
3 3 3 3 3 3
4 0 4 0 4 0
0 0 0 0 0 0
6 * 1 + 6 * 3 + 12 + 6 = 6 + 18 + 18 = 42


*/

//4 a
/*
s = AUTONATICA
*/

//5 d
/*
(I.a < J.b) || (I.b < J.a)
*/

//6 b
/*
100
102
110
112
120
122
200
202
210
212
220
222
*/

//7 c
/*
f(20)
    return 20 * 21 + f(19)
        f(19)
            return 19 * 20 + f(18)
                f(18)
                    return 18 * 19 + f(17)
                        . . .
                            f(3)
                                return 3 * 4 + f(2)
                                    f(2)
                                        return 2 * 3 + f(1) = 6 + 2 = 8
                                            f(1)
                                                return 2


2 + 6 + 12 + 20 + 30 + 42 + 56 + 72 + 90 + 110 + 132 + 156 + 182 + 210 +
+ 240 + 272 + 306 + 342 + 380 + 420 = 3080
*/

//8 b
/*
A = {0, 1, 4, 9, 16}
B = {2, 3, 5, 7}
C = {16, 9, 7, 5, 4, 3, 2, 1, 0}
*/

//9 a
/*
a = 19
b = 20
c = 21

f(a, b, c)
a = 20
b = 21
c = 20

a = 19
b = 20
c = 20
*/

//10 a

//11 d

//12 c

//13 e

//14 b

//15 f
/*
v = {0, 1, 4, 9, 61, 52, 63, 94, 46, 18, 1, . . .}
*/




///poli var 32
//1 c

//2 a

//3 a

//4 d

//5 c

//6 a

//7 d

//8 c

//9 b
/*
1 + 3 + 3 + 1 = 8
*/

//10 c

//11 c

//12 e
/*
f(x, &y)
f(a, a)
f(2, 2)
    y = 4
    x = 6
*/

//13 f

//14 a
/*
mic - cel mai mic nr
mare - cel mai mare nr
p - x ^ y
cmmdc si cmmmc la 6^x si 6^y

u = p(2, f1(x, y)) * p(3, f2(x, y))
v = p(2, f3(x, y)) * p(3, f4(x, y))

f1 - mic
f2 - mic
f3 - mare
f4 - mare
*/

//15 b



///poli var 33
//1 a

//2 f

//3 d

//4 d

//5 c

//6 b
/*
0, 5, 0, 5, 0, 5, 0, 5, 0, 5
0, 1, 2, 3, 4, 5, 6, 7, 8, 9
*/

//7 b

//8 e
/*
2 4 6 8
*/

//9 c

//10 c
/*
3 + 4 + 5
3 + 9
*/

//11 a

//12 b

//13 c
/*
3, 0, 6, 2, 11, 6, 18, 12, 27, 20, 38, 30, 51, 42, 66, 56, 83, 72
+3 , -3, +6, -4, +9, -5, +12, -6, +15, -7, +18, -8, +21, -9, +24, -10, + 27, -11
i = 1, 2, 3, 4, 5, 6, 7, 8, 9
*/

//14 a

//15 f
/*
49 - 12
n^2 - 2n + 2
*/



///poli var 34
//1 a

//2 c

//3 c
/*
a = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
b = 1, 2, 4, 7, 8, 9, 15, 22, 23, 24
*/

//4 a
/*
u este !v si viceversa
*/

//5 c

//6 a
/*
f(v, i, j); f(v, i + 1, j - i);
6 1 7 8 4 5 9
    |     |
6 1 5 4 8 7 9
6 1 5 8 4 7 9
*/

//7 c

//8 d
/*
cel mai mare numar divizibil cu a mai mic decat b
*/

//9 d

//10 c

//11 a
/*
a = a
b = b

x = a
a = b
b = a

a = a
b = a
*/

//12 b

//13 c

//14 f

//15 c




///poli var 35
//1 b
/*
n = (n / 10 * 10 + c) * 10 + n % 10;
*/

//2 d

//3 b

//4 c

//5 c

//6 d
/*
if(x > y)
    if(y > z)
        if(z > x)
            s = x + y + z;
        else
            p = x * y * z;

x > y > z
*/

//7 e
/*
0 1 2 3 4 5 6 7 8 9 10
1 0 2 3 4 5 6 7 8 9 10
. . .
1 2 3 4 5 6 7 8 9 10 0

(10 * 11) / 2 = 45
*/

//8 b

//9 f
/*
1 2 3 4
1 4 3 2
3 2 1 4
3 4 1 2
*/

//10 c

//11 e
/*
a = 20
b = 43

f(a, b)
f(x, &y)
b = 20
y = 43
x = 43
*/

//12 b

//13 a

//14 d

//15 b




///poli var 36
//1 f
/*
x = 288
y = 1
*/

//2 c

//3 e

//4 c

//5 d

//6 d

//7 a

//8 b

//9 d

//10 f

//11 e

//12 b

//13 f

//14 c

//15 d



///poli var 37
//1 b

//2 c

//3 f

//4 c
/*
147 - graf complet
*/

//5 f
/*
10
1 2 3 4 5 6 7 8 9 10
*/

//6 b

//7 c
/*
n = 4
2 3 4 5
3 4 5 4
4 5 4 3
5 4 3 2
*/

//8 c

//9 d

//10 c

//11 c

//12 a

//13 e
/*
s = Sebby
p = bytes to mb
*/

//14 b
/*
n = 3
k = 1

1 2 3
4 5 6
7 8 9

1 2 3 6 9 8 7 4 5
*/

//15 e


///VAR1 UniBuc 2022
//1 A
/*
4 * (n - 2 * k) + 2
n = 22
val = 0
k <- 1, 11

k = 1 -> 82;  1, 21  22, 1
k = 2 -> 74;  2, 20  21, 2
k = 3 -> 66;  3, 19  20, 3
k = 4 -> 58;  4, 18  19, 4
k = 5 -> 50;  5, 17  18, 5
*/

//2 C
/*
v = [4, 3, -10, 3, -1, 2, 0, -3, 5, 7,
-4, -8, -10, 4, 7, -30, -2, -6, 4, 7]
*/

//3 C
/*
v = [10, 20, 30, 40, 50, 60, . . .]
*/

//4 B
/*
1 - 0
2 - 2
3 - 4
4 - 7
5 - 12

0 0 0 0 0
1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
1 0 1 0 0
1 0 0 1 0
1 0 0 0 1
1 0 1 0 1
0 1 0 1 0
0 1 0 0 1
0 0 1 0 1
*/

//5 A
/*
201057

20.10.5.7
20.1.0.57
201.0.5.7
2.0.10.57
2.0.105.7
*/

//6 C
/*
1)
n = 3
i = 0

i = 1
i = 2
i = 3
i = 4


2)
n = 3
i = 1

i = 2
i = 3

3)
n = 3
i = 0

i = 1
i = 2
i = 3
*/

//7 A
/*
214354322
2 - 2 = 0
2 - 2 = 0
3 - 2 = 1
4 - 2 = 2
5 - 2 = 3
5 - 2 = 3
5 - 2 = 3
5 - 1 = 4
5 - 1 = 4
*/

//8 B

//9 C

//10 C

//11 D
/*
511
0
1

10
11

100
101
110
111

1000
1001
1010
1011
1100
1101
1110
1111

0 = 0
1 = 1
2 = 10
3 = 11
4 = 100
5 = 101
6 = 110
7 = 111
8 = 1000

10000
10001
10010
10011
10100
10101
10110
10111
11000
11001
11010
11011
11100
11101
11110
11111

2 2 4 8 16 32 64 128 256 512 1024 2048 4096
1 2 3 4 5  6  7  8   9   10  11   12   13
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/

//12 A
/*
1 - 12
2 - 7
3 - 5
4 - 5
5 - 3
6 - 5
7 - 2
8 - 4
9 - 3
10 - 4
11 - 2
12 - 6
*/

//13 D
/*
ipip - 1 * 1 * 5 * 5 = 25
iipp - 1 * 1 * 5 * 5 = 25
ippi - 25
ip - 25
pi - 20
ippi - 3
*/

//14 B

//15 A


///VAR1 UniBuc 2023
//1 C

//2 B
/*
n = 4
2 - 4
2 4
2 4

n = 13
6 - 13
2 4 8
2 4 8
2 4 8
2 4 8
. . .
*/

//3 C
/*
10, 15, 23, 35 44
A - 1, 1, 1
B - 4, 8
*/

//4 B
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
0 0 0 2 0 1 0 1 2 1  0  1  0  1  1  1

6, 8, 10 . . .
12, 15, 18 . . .
30, 35, 40 . . .
56, 63, 70 . . .
132, 143, 154 . . .

4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256
*/

//5 A
/*
1, 2, 6, 24
t(k, 1, 1)
    t(k, 2, 1)
        t(k, 3, 2)
            t(k, 4, 6)
                t(k, 5, 24)
*/

//6 D
/*
83 * 3 + 98 * 4 + (n − 83 − 9) * 5 = 2 * 2023
249 + 392 + 5n − 905 = 4046 <=> 5n = 4310 <=> n = 862
*/

//7 D
/*
6, 9
k <- 1, 15
c = 18
*/

//8 A
/*
2-4-6-8-10-12-14-16-18-20-22
13
17
19
23
*/

//9 D
/*
n = 12
s = admitere2023
p = admitere2023
p = a
s = dmitere2023a, k = 1
s = itere2023adm, k = 2
s = re2023admite, k = 3
s = 23admitere20, k = 4
s = itere2023adm, k = 5
s = 023admitere2, k = 6
s = tere2023admi, k = 7
s = admitere2023, k = 8
s = 023admitere2, k = 9
s = e2023admiter, k = 10
s = re2023admite, k = 11
*/

//10 B
/*
v = [5, -5, 3, -3, 1, -2, 2, -4, 4]
11
*/

//11 B
/*
4 3 2 1
4 3 1 2
4 2 3 1
4 2 1 3
4 1 3 2
4 1 2 3
3 4 2 1
3 4 1 2
3 2 4 1

3 2 4 1
*/

//12 D
/*
2 - 232
3 - 343
4 - 454
. . .


s1 = 49
s2 = 90

*/
/*
int main(){
    int i, x;
    for(i = 1; i <= 49; i++){
        x = 2 * i - (i % 10) + 1;
        cout << i << "  " << x << "     " << x << i <<endl;
    }
}
*/

//13 A
/*
65, 70, 75, 80, 85, 90

30 de combinatii posibile
29 pana gaseste parola corecta
*/

//14 C
/*
(5, 11, 9, 5, 2, 3, 2, 1, 2, 7,  0)
(1, 2,  3, 4, 5, 6, 7, 8, 9, 10, 11)
*/

//15 B

///ADMITERE POLI 2023
//1 c

//2 b
/*
(0, 1, 2, 2, 1, 5, 1, 7, 7, 4,  4)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)
*/

//3 f

//4 a
/*
k = 3
n = 7

i = 1: 1 2 3
i = 2: 2 3 4
i = 3: 3 4 5
i = 4: 4 5 6
i = 5: 5 6 7
i = 6: 6 7 8
i = 7: 7 8 9

4 5 6 7 8 9 10 10 10
*/

//5 a

//6 e

//7 a

//8 a

//9 c

//10 a


///ADMITERE POLI 2022
//1 a
/*
input = Ana are 4 mere
*/

//2 e
/*
7 note
n = 7 * 7 * 7 = 343
m = 343 - 7 * 6 * 5 = 343 - 210 = 133
*/

//3 d
/*
55 * a + 10 * b = 2045
15 * a + 5 * b = 560

55 * a + 10 * b = 2045
30 * a + 10 * b = 1120

25 * a = 925 => a = 37 => b = 1
*/

//4 d

//5 a

//6 d
