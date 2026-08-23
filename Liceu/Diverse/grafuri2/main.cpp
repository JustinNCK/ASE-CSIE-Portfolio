#include <iostream>
#include <fstream>
using namespace std;

// T3
// SI
// 1. b.
// 2. c.*54321*543*5*////
// 3. d
// 5. a. 5
//
// SII
// 1.
// a. 8820
// b. 222, 444
// c.
/*int main()
{
	unsigned int n, x, m, c, cn, p;
	cin >> n;
	x = 0;
	m = 0;
	p = 1;
	while (x < 10)
	{
		cn = n;
		while (cn != 0)
		{
			c = cn % 10;
			cn = cn / 10;
			if (c == x)
			{
				m = c * p + m;
				p = p * 10;
			}
		}
		x = x + 2;
	}
	cout << m;
}*/
// d.
/*citește n
(număr natural nenul)
x <- 0; m <- 0; p <- 1;
┌cât timp x < 10 execută
│ cn <- n
│┌daca cn ≠ 0 atunci
││┌execută
│││ c <- cn % 10; cn <- [cn / 10]
│││┌dacă c = x atunci
││││ m <- c * p + m; p <- p * 10
│││└■
││└cât timp cn ≠ 0
│└■
│x <- x + 2
└■
scrie m
*/
//
// 2.
/*
struct muzeu
{
	int numar;
	struct c
	{
		char nume[20], colectie[20];
	}exponat[100];
}m;*/
//
// 3. un
//    zeu
//
// SIII
// 1.
/*void suma(int n);

int main()
{
	int n;
	cin >> n;
	suma(n);
}

void suma(int n)
{
	int d, i, s;
	s = 1;
	for (d = 2; d <= n; d++)
		if (n % d == 0)
			for (i = 2; i <= d / 2; i++)
				if (d % i == 0)
				{
					i = d;
					s = s + d;
				}
	cout << s;
}*/
//
// 2.
/*int main()
{
	int s[20][20], m, n, i, j, cont;
	cin >> m >> n;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> s[i][j];
	cont = 0;
	for(i = 0; i < m; i++)
		if(s[i][0] != 0)
			for(j = 0; j < m; j++)
				if (s[i][0] == s[j][n - 1])
				{
					cout << s[i][0] << " ";
					cont = 1;
				}
	if (cont == 0)
		cout << "nu exista";
}*/
//
// 3.
/*int main()
{
	int v[100], z[10], i, n, maxi;
	ifstream fin("bac.in");
	n = 0;
	while (fin >> v[n])
		n++;
	for (i = 0; i < 10; i++)
		z[i] = 0;
	for (i = 0; i < n; i++)
		z[(v[i] / 10) % 10]++;
	maxi = 0;
	for (i = 0; i < 10; i++)
		if (z[i] >= maxi)
			maxi = z[i];
	for (i = n - 1; i >= 0; i--)
		if (z[(v[i] / 10) % 10] == maxi)
		{
			z[(v[i] / 10) % 10] = 0;
			cout << i + 1 << " ";
		}
}*/


//T4
//
// SII
//1. c
 /*int main()
 {
     unsigned int n;
     int k, p, c;
     cin >> n >> k;
     p = 1;
     while(n > 0)
     {
         c = n % 10;
         if(k > 0)
            if(c % 2 == 1)
            p = p * c;
         n = n / 10;
         k = k - 1;
     }
     cout << p;
 }*/
//
//2.
/*struct ciocolata
{
    int gramaj;
    struct data
    {
        int zi, luna, an;
    }datae;
}c;*/
//
//
//
//
// SIII
// 1.
/*void joc(int n)
{
	int k, nr;
	nr = 1;
	for (k = 2; k <= n / 2; k++)
		if (n % k == 0)
			nr++;
	cout << nr;
}

int main()
{
	int n;
	cout << "Dati numarul de jetoane: ";
	cin >> n;
	joc(n);
}*/
//
// 2.
/*int main()
{
	int mat[10][10], m, n, i, j, max;
	cin >> m >> n;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> mat[i][j];
	for (i = 0; i < m; i++)
	{
		max = 0;
		for(j = 0; j < n; j++)
			if (mat[i][j] < 21)
			{
				max = mat[i][j];
				j = n;
			}
		if (j == n)
			cout << "nu exista" << endl;
		else
		{
			for (j = 0; j < n; j++)
				if (mat[i][j] > max && mat[i][j] < 21)
					max = mat[i][j];
			cout << max << endl;
		}
	}
}*/
//
// 3.
/*int main()
{
	int n1, n2, i, i1, i2, ok, cont, x, y;
	ifstream fin1("bac1.in");
	ifstream fin2("bac2.in");
	fin1 >> n1;
	fin2 >> n2;
	i1 = 0;
	i2 = 0;
	fin1 >> x;
	fin2 >> y;
	while (i1 < n1 && i2 < n2)
	{
	    if(x < y)
        {
            if (x % 5 == 0)
            {
                cout << x << " ";
            }
        fin1 >> x;
        i1++;
        }else if(x > y){
            if(y % 5 == 0)
            {
                cout << y << " ";
            }
        fin2 >> y;
        i2++;
        }else
        {
            fin1 >> x;
            fin2 >> y;
            i1++;
            i2++;
        }
	}
	while(i1 < n1)
    {
        if(x % 5 == 0)
            cout << x;
        fin1 >> x;
        i1++;
    }
    while(i2 < n2)
    {
        if(y % 5 == 0)
            cout << y;
        fin2 >> y;
        i2++;
    }
*/





///TEST 5
///SI
//1. d
//2. a
//7552021
//7654321
//3. b
//5. b
///SII
//1. a. 17396

//x = 12
//y = 0
//x = 1
//y = 1
//x = 7
//y = 17
//x = 354
//x = 35
//x = 3
//y = 173
//x = 9
//x = 0
//y = 1730
//x = 630
//x = 63
//x = 6
//y = 17306
//x = 0
//   b. 321, 231, 123, 0
//   c.
/*int main()
{
    unsigned int x, y;
    cin >> x;
    y = 0;
    do
    {
        if(x > 9)
            do
                x = x / 10;
            while(x > 9);
        y = y * 10 + x;
        cin >> x;
    }while(x != 0);
    cout << y;
}*/
//   d.
/*citeşte x
(număr natural nenul)
y <- 0
┌repetă
│┌dacă x > 9 atunci
││┌cât timp x > 9 execută
│││ x <- [x / 10]
││└■
│└■
│ y <- y * 10 + x
│ citeşte x (număr natural)
└până când x = 0
scrie y*/

//2.
/*struct carte
{
  char titlu[50], autor[10][50];
  int nrExemplare;
}c;*/
//3.
//scrie: 11*nf*rm*t*c*
//s = informatica
//s = *nf*rm*t*c*
///SIII
//1.
/*int indice(int n)
{
    int k;
    k = n % 10;
    while(n != 0)
    {
        if(n % 10 != k)
            return 0;
        n = n / 10;
    }
    return 1;
}

int main()
{
   int n;
   cin >> n;
   cout << indice(n);
}*/
//2.
/*int main()
{
    int mat[101][101], m, n, i, j;
    cin >> m >> n;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            mat[i][j] = (i * j) % 10;
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}*/
//3.
/*int main()
{
    int n, nmax, x;
    ifstream fin("bac.txt");
    fin >> n;
    fin >> nmax;
    cout << nmax << " ";
    while(fin >> x)
    {
        if(x > nmax)
            nmax = x;
        cout << nmax << " ";
    }
}*/




///TEST 6
///SIII
//1.
/*int numar(int n, int c)
{
    int m, k, cn, ok;
    k = 1;
    cn = n;
    m = -1;
    while(cn != 0)
    {
        if(cn % 10 != c)
        {
            m = (cn % 10) * k + m;
            k = k * 10;
        }
        cn = cn / 10;
    }
    if(m == -1)
        return m;
    else
        return m + 1;
}

int main()
{
    int n, c;
    cin >> n >> c;
    cout << numar(n, c);
}*/
//2.
/*int main()
{
    int mat[20][20] = {{0}}, i, j, n, cn, k;
    cin >> n;
    k = 0;
    for(i = 0; i < n; i++)
        mat[i][n - i - 1] = k;
    cn = n - 1;
    while(k != n - 1)
    {
        k++;
        for(i = 0; i < cn; i++)
        {
            mat[i][cn - i - 1] = k;
            mat[n - cn][cn + i] = k;
        }
        cn--;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}*/








///SUBIECT BAC 2022
///SI
//1. c
//2. d
//3. a
//4. b
///SIII
//1.
/*void secventa(int n)
{
    int cn, a;
    cn = 0;
    a = 1;
    while(n != 0) {
        if(n % 100 == 22) {
            //cout << "m" << endl;
            cn = 20 * a + cn;
            //n = n / 10;
            //a = a * 10;
        }
        else {
            cn = (n % 10) * a + cn;
        }
        a = a * 10;
        n = n / 10;
    }
    cout << cn;
}
int main()
{
    int n;
    cin >> n;
    secventa(n);
}*/
///varianta iustin
/*void secventa(int n)
{
    int p, x, cn, a;
    cn = 0;
    a = 1;
    while(n != 0)
    {
        x = 20;
        if(n % 10 == 2 && (n % 100 / 10) == 2)
            {
                n = n / 100;
                while(n % 10 == 2)
                {
                    x = x * 10;
                    a = a * 10;
                    n = n / 10;
                }
                cn = cn + x * a;
            }
        else
            {
                cn = cn + (n % 10) * a;
                a = a * 10;
            }
        a = a * 10;
        n = n / 10;
    }
    cout << cn;
}
int main()
{
    int n;
    cin >> n;
    secventa(n);
}*/
///2
/*int main()
{
    int mat[100][100], i, j, m, n, nr, s;
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    s = 0;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            nr = 11;
            if(i > 0 && nr > mat[i - 1][j])
                nr = mat[i - 1][j];
            if(j < n - 1 && nr > mat[i][j + 1])
                nr = mat[i][j + 1];
            if(i < m - 1 && nr > mat[i + 1][j])
                nr = mat[i + 1][j];
            if(j > 0 && nr > mat[i][j - 1])
                nr = mat[i][j - 1];
            if(mat[i][j] < nr)
            {
                s = s + (nr - mat[i][j]);
            }
        }
    cout << s;
}*/
///3
/*int main()
{
    int a, b, m, n, nr;
    ifstream fin("bac.txt");
    fin >> m >> n;
    nr = 0;
    b = 0;
    while(fin >> a)
    {
       if(a != b && a >= m && a <= n)
            nr++;
       b = a;
    }
    cout << nr;
}*/




///subiect SN
///SIII
//2.
/*int main()
{
    int v[100], n, i, s, nr;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> v[i];
    s = 0;
    for(i = 0; i < n; i++)
    {
        nr = 11;
        if(i > 0 && nr > v[i - 1])
            nr = v[i - 1];
        if(i < n && nr > v[i + 1])
            nr = v[i + 1];
        if(nr > v[i])
            s = s + (nr - v[i]);
    }
    cout << s;
}*/
//3.
/*int main()
{
    int x, a, b, nr;
    ifstream fin("bac.txt");
    fin >> x;
    nr = 0;
    b = 0;
    while(fin >> a)
    {
        if(b != a && a >= 1 && a <= x)
            nr++;
        b = a;
    }
    cout << nr;
}*/


int main()
{
    int a, b, c, d;
    a = 15;
    b = 5;
    c = 6;
    d = 3;
    cout << a/b*c/d;
}
