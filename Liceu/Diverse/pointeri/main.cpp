#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
/*int main()
{
    int a, *p;
    cin >> a;
    p = &a;
    cout <<  a << endl;
    cout <<  &a << endl;
    cout <<  p << endl;
    cout <<  &p << endl;
    cout <<  *p << endl;
    *p *= 2;
    cout << a << endl;
}*/

/*int main()
{
    int v[10], n, i, s = 0;
    // v = pointer care stocheaza adresa primului element din vector
    // v+1 = adresa celui de-al doilea element
    // *v = valoarea primului element
    // *(v+1) = valoarea celui de-al doilea element

    cin >> n;
    for(i = 0; i < n; i++)
        cin >> *(v+i);
    for(i = 0 ; i < n; i++)
        s += *(v+i);
    cout << s;
}*/

/*int main()
{
    int i, j, m, n, mat[100][100];
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            //cin >> mat[i][j];
            cin >> *(*(mat + i) + j);
     for(i = 0; i < m; i++)
     {
        for(j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
     }

}*/


/*
void t(int &x, int y)
{
    x -= 1;
    y = x + 1;
    cout << x << y;
}
int main()
{
    x = 3;
    y = 7;
    t(y, y);
    cout << x << y;
    t(y, x);
}

t(y = 7, y = 7);
t(&x = 7, y = 7);
    x = 6;
    y = 7;
    cout << 6 << 7;
cout << 3 << 6;
t(y = 6, x = 3);
t(&x = 6, y = 3);
    x = 5;
    y = 6;
    cout << 5 << 6;
*/
//673656



//se citesc 2 nr de la tastatura
//sa se afiseze cifrele comune
/*int main()
{
    int a, b, m[10], n[10], i, j, k = 0, c = 0, z;
    cin >> a >> b;
    while(a != 0)
    {
        *(m+c) = a % 10;
        a = a / 10;
        c++;
    }
    while(b != 0)
    {
        *(n+k) = b % 10;
        b = b / 10;
        k++;
    }
    for(i = 0; i < c; i++)
        for(j = 0 ; j < k; j++)
            if(*(m+i) == *(n+j))
            {
                cout << *(m+i);
                for(z = 0; z < k; z++)
                    if(*(m+i) == *(n+z))
                    *(n+z) = -1;
            }
}*/
/*int main()
{
    int a, b, m[10];
    cin >> a >> b;
    while(a != 0)
    {
        *(m+a%10) = 1;
        a = a / 10;
    }
    while(b != 0)
    {
        if(*(m+b%10) == 1)
        {
            cout << b%10;
            *(m+b%10) = 0;
        }
        b = b / 10;
    }
}*/
/*int main()
{
    int mat[20][20], i, j, m, n, k;
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> *(*(mat+i)+j);
    for(i = 0; i < m; i++)
    {
        cout << endl;
        for(j = 0; j < n; j++)
            cout << *(*(mat+i)+j) << " ";
    }
    for(i = 0; i < m; i++)
    {
      k = *(*(mat+i));
        for(j = 1; j < n; j++)
            if(k < *(*(mat+i)+j))
                k = *(*(mat+i)+j);
        cout << k << " ";
    }
}*/

/*int main()
{
    ifstream fin("dex.txt");
    char dex[100][10], *p, s[100];
    int n = 0, i, ok;
    float nr = 0, t = 0;
    cin.getline(s, 100);
    while(fin >> *(dex+n))
        n++;
    p = strtok(s, " ");
    while(p != NULL)
    {
        t++;
        ok = 0;
        for(i = 0; i < n; i += 2)
            if(strcmp(p, *(dex+i)) == 0)
            {
                cout << *(dex+i+1) << " ";
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


/*int main() {
    int n, i;
    int *v;

    cin >> n;
    v = (int *)malloc(n * sizeof(int));


    for(i = 0; i < n; i ++)
        cin >> *(v+i);
    for(i = 0; i < n; i ++)
        cout << *(v+i) << " ";

    free(v);

    return 0;
}*/


/*int main()
{
    int **a, i, j;
    int m, n;
    cin >> m >> n;

    a = (int **)malloc(m * sizeof(int *));
    for(i = 0; i < m; i++)
    {
        *(a+i) = (int *)malloc(n * sizeof(int));
        for(j = 0; j < n; j++)
            cin >> *(*(a+i)+j);
    }
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cout << *(*(a+i)+j) << " ";

    for(i = 0; i < m; i++)
        free(*(a+i));
    free(a);
}*/



//1
/*int main()
{
    int *v, n, i, j, k;
    cin >> n;
    v =(int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        cin >> *(v+i);
    for(i = 0; i < n; i++)
    {
        k = 0;
        for(j = 0; j < n; j++)
            if(*(v+i) == *(v+j) && i != j)
            {
                k = 1;
                j = n;
            }
        if(k == 0)
            cout << *(v+i) << " ";
    }
    free(v);
    return 0;
}*/

/*int main()
{
    int *v, *nr, i, n, mx;
    cin >> n;
    v = (int *)malloc(n * sizeof(int));
    cin >> *(v);
    mx = *(v);
    for(i = 1; i < n; i++)
    {
        cin >> *(v+i);
        if(*(v+i) > mx)
            mx = *(v+i);
    }
    nr = (int *)malloc(mx * sizeof(int));
    for(i = 0; i < mx; i++)
        *(nr+i) = 0;
    for(i = 0; i < n; i++)
        (*(nr+*(v+i)))++;
    for(i = 1; i <= mx; i++)
        if(*(nr+i) == 1)
            cout << i<< " ";
    free(v);
    free(nr);
    return 0;
}*/


//2
/*int main()
{
    int **mat1, **mat2, **mat3, i, j, m1, n1, m2, n2, m3, n3;
    cout << "Dimensiunile primei matrici: ";
    cin >> m1 >> n1;
    cout << "Dimensiunile cele de a doua matrici: ";
    cin >> m2 >> n2;
    if(m1 > m2)
        m3 = m1;
    else
        m3 = m2;
    if(n1 > n2)
        n3 = n1;
    else
        n3 = n2;

    mat1 = (int **)malloc(m3 * sizeof(int *));
    mat2 = (int **)malloc(m3 * sizeof(int *));
    mat3 = (int **)malloc(m3 * sizeof(int *));
    for(i = 0; i < m3; i++)
    {

        *(mat1+i) = (int *)malloc(n3 * sizeof(int));
        for(j = 0; j < n3; j++)
            *(*(mat1+i)+j) = 0;

        *(mat1+i) = (int *)calloc(n3, sizeof(int));
        *(mat2+i) = (int *)calloc(n3, sizeof(int));
        *(mat3+i) = (int *)calloc(n3, sizeof(int));
    }
    for(i = 0; i < m1; i++)
        for(j = 0; j < n1; j++)
            cin >> *(*(mat1+i)+j);
    for(i = 0; i < m2; i++)
        for(j = 0; j < n2; j++)
            cin >> *(*(mat2+i)+j);
    for(i = 0; i < m3; i++)
        for(j = 0; j < n3; j++)
            *(*(mat3+i)+j) = *(*(mat1+i)+j) + *(*(mat2+i)+j);

    for(i = 0; i < m1; i++)
    {
        cout << endl;
        for(j = 0; j < n1; j++)
            cout << *(*(mat1+i)+j) << " ";
    }
    cout << endl;
    for(i = 0; i < m2; i++)
    {
        cout << endl;
        for(j = 0; j < n2; j++)
            cout << *(*(mat2+i)+j) << " ";
    }
    cout << endl;
    for(i = 0; i < m3; i++)
    {
        cout << endl;
        for(j = 0; j < n3; j++)
            cout << *(*(mat3+i)+j) << " ";
    }

    for(i = 0; i < m3; i++)
    {
        free(*(mat1+i));
        free(*(mat2+i));
        free(*(mat3+i));
    }
    free(mat1);
    free(mat2);
    free(mat3);
return 0;
}*/

//se citesc de la tastatura 2 vectori de dim diferite
//cu elemente mai mici ca 1000, sa se faca intersectia vectorilor
/*int main()
{
    int *a, *b, *nr, i, m, n, mx;
    cin >> m >> n;
    a = (int *)malloc(m * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for(i = 0; i < m; i++)
        cin >> *(a+i);
    for(i = 0; i < n; i++)
        cin >> *(b+i);

    mx = *(a);
    for(i = 0; i < m; i++)
        if(*(a+i) > mx)
            mx = *(a+i);
    for(i = 0; i < n; i++)
        if(*(b+i) > mx)
            mx = *(b+i);
    nr = (int *)malloc(mx* sizeof(int));

    for(i = 0; i < m; i++)
        *(nr+*(a+i)) = 1;
    for(i = 0; i < n; i++)
        if(*(nr+*(b+i)) == 1)
            *(nr+*(b+i)) = 2;
    for(i = 1; i <= mx; i++)
        if(*(nr+i) == 2)
            cout << i << " ";
    free(nr);
    free(a);
    free(b);
}*/
//TEMA
// reuniunea a doi vectori
// interclasarea a doi vectori

/*int main()
{
    int *a, *b, *c, i, j, k, n, m, q, nr, x, ok;
    cin >> m >> n;
    a = (int *)malloc(m * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    for(i = 0; i < m; i++)
        cin >> *(a+i);
    for(j = 0; j < n; j++)
        cin >> *(b+j);
    q = m + n;
    c = (int *)malloc(q * sizeof(int));
    k = 0;
    q = 0;
    for(i = 0; i < m; i++)
    {
        ok = 0;
        for(x = 0; x < k; x++)
            if(*(c+x) == *(a+i))
            {
                ok = 1;
                break;
            }
        if(ok == 0)
        {
            *(c+k) = *(a+i);
            k++;
            q++;
        }
    }
    for(j = 0; j < n; j++)
    {
        ok = 0;
        for(x = 0; x < k; x++)
            if(*(c+x) == *(b+j))
            {
                ok = 1;
                break;
            }
        if(ok == 0)
        {
            *(c+k) = *(b+j);
            k++;
            q++;
        }
    }
    for(k = 0; k < q; k++)
        cout << *(c+k) << " ";
    free(a);
    free(b);
    free(c);
}*/


/*int main()
{
    int *a, *b, *c, i, j, k = 0, m, n, q;
    cin >> m >> n;
    a = (int *)malloc(m * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    q = m + n;
    c = (int *)malloc(q * sizeof(int));

    for(i = 0; i < m; i++)
        cin >> *(a+i);
    for(j = 0; j < n; j++)
        cin >> *(b+j);
    i = 0;
    j = 0;
    while(i < m && j < n)
        if(*(a+i) < *(b+j))
        {
            *(c+k) = *(a+i);
            i++;
            k++;
        }
        else
        {
            *(c+k) = *(b+j);
            j++;
            k++;
        }
    while(i < m)
    {
        *(c+k) = *(a+i);
        i++;
        k++;
    }
    while(j < n)
    {
        *(c+k) = *(b+j);
        j++;
        k++;
    }
    for(k = 0; k < q; k++)
        cout << *(c+k) << " ";
    free(a);
    free(b);
    free(c);
}*/



//TEMA
//cea mai lunga secventa de numere prime consecutive care adunate dau un numar mai mic decat un numar n introdus de la tastatura
/*int prim(int x)
{
    int d;
    for(d = 2; d <= x / 2; d++)
        if(x % d == 0)
            return 0;
    return 1;
}
int main()
{
    int p[1000], i = 3, n, nr, nrmx = 0, s = 2, x = 1, k = 0, u, s_max;
    cin >> n;
    p[0] = 2;
    while(s < n)
    {
        if(prim(i) == 1)
        {
            s += i;
            *(p+x) = i;
            x++;
            //cout << s << " ";
        }
        i += 2;
    }
    //for(i = 0; i < x; i++)
        //cout << *(p+i) << " ";
    //for(i = 0; i < x; i++)
        //cout << *(p+i) << " ";
    //cout << endl;
    while(k < x) {
        s = *(p+k);
        s_max = s;
        nr = 1;
        for(i = k + 1; s < n; i++) {
            s = s + *(p+i);
            nr++;
            if(prim(s) == 1) {
                u = nr;
                s_max = s;
                //cout << p[i] << " ";
            }
            //else
                //break;
            //cout << endl;
        }
        if(u > nrmx)
            nrmx = u;
        //cout << s_max << " " << nrmx << endl;
        k++;
    }
    cout << nrmx;
}*/



//se citeste de la tastatura un sir de caractere formate din cuv. separate prin spatii
//sa se afiseze pe ecran de cate ori apare fiecare cuv.
/*int main()
{
    char s[100][100], p[200], *c;
    int i = 0, j = 0, n = 0, nr, k, v[100];
    cin.getline(p, 200);
    for(c = strtok(p, " "); c != NULL; c = strtok(NULL, " "))
    {
        k = 1;
        for(j = 0; j < i; j++)
            if(strcmp(s[j], c) == 0) {
                k = 0;
                break;
            }
        if(k == 1) {
            strcpy(s[i], c);
            v[i] = 1;
            i++;
        } else {
            v[j]++;
        }
    }
    for(j = 0; j < i; j++)
        cout << s[j] << " " << v[j] << endl;
}*/




/*int main()
{
    char s[1024];
    int n, i, k = -1;
    cin.getline(s, 1024);
    while(s[n] != NULL)
        n += 2;
    for(i = 0; i < n/2; i++)
        if((s[i] == 'A' && s[n - i - 1] != 'T') || (s[i] == 'T' && s[n - i - 1] != 'A') || (s[i] == 'C' && s[n - i - 1] != 'G') || (s[i] == 'G' && s[n - i - 1] != 'C'))
            {
                k = i;
                break;
            }
    {
        if((s[i] == 'A' && s[n - i - 1] != 'T') || (s[i] == 'T' && s[n - i - 1] != 'A'))
            {
                k = i;
                break;
            }
        if((s[i] == 'C' && s[n - i - 1] != 'G') || (s[i] == 'G' && s[n - i - 1] != 'C'))
            {
                k = i;
                break;
            }
    }
    {
        if(s[i] == 'A')
            if(s[n - i - 1] != 'T')
            {
                k = i;
                break;
            }
        else if(s[i] == 'T')
                if(s[n - i - 1] != 'A')
                {
                    k = i;
                    break;
                }
        if(s[i] == 'C')
            if(s[n - i - 1] != 'G')
            {
                k = i;
                break;
            }
        else if(s[i] == 'G')
                if(s[n - i - 1] != 'C')
                {
                    k = i;
                    break;
                }
    }
    if(k == -1)
        k = 0;
    else
        k++;
    cout << k;
}*/
//ATCATCGTAACGTACGTTACGATGAT - bun
//ATCATCGTAACGTACGTTACGAAGAT - rau




/*int main()
{
    ifstream fin("nr.txt");
    int n, *v, i, k = 0, s, sk = 0, m = 0, a = 0;
    fin >> n;
    v = (int *)malloc(n * sizeof(int));
    for(i = 0;i < n; i++)
        fin >> v[i];
    for(m = 1; m <= n; m++)
    {
        //cout << "a m s sk k" << endl;
        while(m+a <= n)
        {
            s = 0;
            for(i = a; i < m + a; i++)
                s += v[i];
            if(s % 3 == 0 && m > k && s != 0)
            {
                sk = s;
                k = m;
            }
            a++;
            //cout << a << " " << m << " " << s << " " << sk << " " << k << endl;
        }
        a = 0;
        //cout << endl;
    }
    if(k == 0)
        cout << k;
    else
        cout << k << " " << sk;
    free(v);
}*/
//7
//10 6 7 12 4 7 19
//4
//1 4 7 6
//3
//2 5 0



/*int main()
{
    int n, v[32] = {0}, i, k = 0, cn, s, a;
    cin >> n;
    cn = n;
    while(n != 0)
    {
        v[k] = n % 2;
        n /= 2;
    }
    a = k;
    while(a > 0)
    {
        for(i = 0; i , k; i++)
            cout << v[i];
        s = 0;
        v[0] = v[k - 1] + v[0];
        v[k - 1] = v[0] - v[k - 1];
        v[0] = v[0] - v[k - 1];
        for(i = k - 1; i > 0; i--)
            v[i] = v[i - 1];
        for(i = 1; i <= k; i++)
            s += pow(2, v[i - 1]);
        if(s > cn)
            cn = s;
        cout << " " << s << " " << cn << endl;
        a--;
    }
    cout << cn;
}*/


/*int main()
{
    char prop[200], s[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", cod[400];
    int i = 0, j = 0;
    cin >> cod;
    while(j < strlen(cod)) {
        if(cod[j] != '0' || cod[j + 1] != '0') {
            if((cod[j] - 48) * 10 + (cod[j + 1] - 48) - 1 > 26){
                 if(cod[j + 1] <= '2'){
                    prop[i] = s[cod[j] - 48 - 1];
                    i++;
                    j++;
                 }
                 else{
                    prop[i] = s[cod[j] - 48 - 1];
                    prop[i + 1] = s[cod[j + 1] - 48 -1];
                    i += 2;
                    j += 2;
                 }
            }
            else {
                prop[i] = s[(cod[j] - 48) * 10 + (cod[j + 1] - 48) - 1];
                i++;
                j += 2;
            }
        }
        else {
            prop[i] = ' ';
            j += 2;
            i++;
        }
    }
    prop[i] = '\0';
    cout << prop;
}*/
//195318520   SECTRET
//2671513152000011202     ZGOMOT ALB
//A B C D E F G H I J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26





//3 6 10 15 21 27 35 44


/*int main()
{
    int t = 0, h, k, u = 1, ok = 0, l = 0, s = 0, c;
    cin >> k;
    while(ok == 0){
        t++;
        h = (t+1)*(t+2)/2;
        if(k >= u && k < u + h){
            ok = 1;
        }
        u += h;
    }
    u -= h;
    ok = 0;
    h = 0;
    while(ok == 0){
        if(k >= u && k <= u + h){
            ok = 1;
        }
        l++;
        h++;
        u = u + h;

    }
    c = h - (u - k) + 1;
    cout << t << " " << l << " " << c;
}*/




/*int main()
{
    char voc[] = "aeiou", s[100];
    int i;
    strcpy(s, "*galbbbleinn*asaa*appaarei*astfel*creuzet*");
    for(i = 0; i < strlen(s) - 1; i++){
        if(s[i] != '*' && s[i + 1] != '*')
            if((strchr(voc, s[i]) != 0 && strchr(voc, s[i + 1]) != 0) || (strchr(voc, s[i]) == 0 && strchr(voc, s[i + 1]) == 0)){
                strcpy(s + i + 1, s + i + 2);
                i--;
            }
    }
    cout << s;
}*/


/*void mut(int mat[20][20], int a, int b, int m, int n)
{
    if(mat[a][b] == 2)
        return;

    mat[a][b] = 2;
    if(a > 0 && mat[a - 1][b] == 0){
        cout << "1 " << a << " " << b << "  " << endl;
        mut(mat, a - 1, b, m ,n);
        cout << "ter1 "<< mat[a][b] << endl;
    }
    if(b > 0 && mat[a][b - 1] == 0){
        cout << "2 " << a << " " << b << "  " << endl;
        mut(mat, a, b - 1, m ,n);
        cout << "ter2 " << mat[a][b] << endl;
    }
    if(b + 1 < n && mat[a][b + 1] == 0){
        cout << "3 " << a << " " << b << "  " << endl;
        mut(mat, a, b + 1, m ,n);
        cout << "ter3 " << mat[a][b] << endl;
    }
    if(a + 1 < m && mat[a + 1][b] == 0){
        cout << "4 " << a << " " << b << "  " << endl;
        mut(mat, a + 1, b, m ,n);
        cout << "ter4 " << mat[a][b] << endl;
    }
}


int main()
{
    int mat[20][20], i, j, m, n, a, b;
    cout << "numarul de lini si coloane: ";
    cin >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cin >> mat[i][j];
    cout << "coodonatele de start: ";
    cin >> a >> b;
    mut(mat, a, b, m ,n);
    for(i = 0; i < m; i++){
        cout << endl;
        for(j = 0; j < n; j++)
            cout << mat[i][j] << " ";
    }
}*/

/*
6 7

1 0 0 1 1 0 0
1 1 0 1 0 1 0
1 0 0 0 0 0 0
1 1 1 0 1 1 1
1 0 0 1 1 0 1
1 0 0 1 1 0 0

3 3
*/

/*


*/


// Q - statistici
// Q in pariaada zi (ziua inceput) si zf (ziua finala)
// Q de la compina cl pana la compania cr
// N - Numarul de companii
// M - numarule de zile in care investteste in fiecare companie
/*ifstream fin("inv.in");
ofstream fout("inv.out");
int main ()
{
    int **s, *a;
    int i, j, N, M, k, t;
    int Q, zi, zf, cl, cr;
    fin >> N >> M;
    a = (int *)malloc(N * sizeof(int));
    for(i = 0; i < N; i++)
        fin >> *(a+i);
    s = (int **)malloc(M * sizeof(int *));
    for(i = 0; i < M; i++){
        *(s+i) = (int *)malloc(N * sizeof(int));
    }
    for(i = 0; i < N; i++)
        s[0][i] = a[i];
    for (i = 1; i < M; i++){
        for (j = 0; j < N; j++)
            *(*(s+i)+j) = *(*(s+i-1)+*(a+j)-1);
    }
    fin >> Q;
    for(k = 0; k < Q; k++){
        fin >> zi >> zf >> cl >> cr;
        t = 0;
        for(i = zi - 1; i < zf; i++)
            for(j = cl - 1; j < cr; j++)
                t += *(*(s+i)+j);
        fout << t << endl;
    }

    free(a);
    for(i = 0; i < M; i++){
        free(s[i]);
    }
    free(s);
    fin.close();
    fout.close();
}*/
/*
8 3
3 1 7 2 6 4 5 8
5
1 1 3 7
1 2 1 4
1 3 2 8
2 3 3 6
3 3 3 3
*/





ifstream fin("seif.in");
ofstream fout("seif.out");
int main()
{
    int **A, i, j, N, T;
    int *v, *k;
    int c, p, *nr, a, q;
    int x;
    char s;
    fin >> N;
    A = (int **)malloc((N+1) * sizeof(int *));
    for(i = 1; i <= N; i++){
        *(A+i) =(int *)malloc((N+1) * sizeof(int));
        for(j = 1; j <= N; j++)
            fin >> *(*(A+i)+j);
    }
    /*for(i = 1; i <= N; i++){
        cout << endl;
        for(j = 1; j <= N; j++)
            cout << *(*(A+i)+j) << " ";
    }*/
    fin >> T;
    nr = (int *)calloc(N/2+1 , sizeof(int));
    for(i = 1; i <= T; i++){
        fin >> c >> p >> s;
        if(s == 'S')
            *(nr+c) -= p;
        else
            *(nr+c) += p;
    }
    v = (int *)malloc(sizeof(int));
    k = (int *)malloc(2*sizeof(int));

    x = N;
    for(c = 1; c <= N/2; c++){
        if(*(nr+c) == 0)
            continue;
        a = 1;
        q = 4*x-4;
        x -= 2;
        v = (int *)realloc(v, q * sizeof(int));
        for(i = c; i <= N - c + 1; i++){
            *(v+a) = *(*(A+c)+i);
            a++;
        }
        for(i = c + 1; i <= N - c + 1; i++){
            *(v+a) = *(*(A+i)+N-c+1);
            a++;
        }
        for(i = N - c; i >= c; i--){
            *(v+a) = *(*(A+N-c+1)+i);
            a++;
        }
        for(i = N - c; i >= c + 1; i--){
            *(v+a) = *(*(A+i)+c);
            a++;
        }
        /*cout << endl;
        for(i = 1; i <= q; i++)
            cout << *(v+i) << " ";
        cout << endl;*/

        if(*(nr+c) < 0)
            p = (*(nr+c)*(-1))%q;
        else
            p = *(nr+c)%q;
        k = (int *)realloc(k, 1 * sizeof(int));
        a = 1;
        if(*(nr+c) > 0){
            for(i = q-p+1; i <= q; i++){
                *(k+a) = *(v+i);
                a++;
            }
            for(i = q-p; i >=1; i--){
                *(v+i+p) = *(v+i);
            }
            for(i = 1; i <=p; i++){
                *(v+i) = *(k+i);
            }
        }
        else{
            for(i = 1; i <= q; i++){
                *(k+i) = *(v+i);
            }
            for(i = p+1; i <= q; i++){
                *(v+i-p) = *(v+i);
            }
            for(i = q-p+1; i <= q; i++){
                *(v+i) = *(k+a);
                a++;
            }
        }
        /*for(i = 1; i <= q; i++)
            cout << *(v+i) << " ";
        cout << endl;*/
        a = 1;
        for(i = c; i <= N - c + 1; i++){
            *(*(A+c)+i) = *(v+a);
            a++;
        }
        for(i = c + 1; i <= N - c + 1; i++){
            *(*(A+i)+N-c+1) = *(v+a);
            a++;
        }
        for(i = N - c; i >= c; i--){
            *(*(A+N-c+1)+i) = *(v+a);
            a++;
        }
        for(i = N - c; i >= c + 1; i--){
            *(*(A+i)+c) = *(v+a);
            a++;
        }
        /*for(i = 1; i <= N; i++){
            cout << endl;
            for(j = 1; j <= N; j++)
                cout << *(*(A+i)+j) << " ";
        }*/
    }
    for(i = 1; i <= N; i++){
        cout << endl;
        for(j = 1; j <= N; j++)
            cout << *(*(A+i)+j) << " ";
    }


    for(i = 0; i < N; i++){
        free(*(A+i));
    }
    free(A);
    free(v);
    free(nr);
    free(k);
    fin.close();
    fout.close();
    return 0;
}
/*
v = (int *)realloc((N-c+1)*(N-c+1) * sizeof(int));
        if(s =='S'){
            for(j = 0; j < p; j++)
                shift_s(c, p, A, N);
        }
        else{
            for(j = 0; j < p; j++)
                shift_d(c, p, A, N);
        }
*/
    /*
    sus - *(*(A+c)+i);
    dreapta - *(*(A+i)+N-c+1);
    jos - *(*(A+N-c+1)+i);
    stanga - *(*(A+i)+c);
    */
    /*
10 20 30 40 50 60 70 80 90

40 20 30 10 50 60 70 80 90
40 50 30 10 20 60 70 80 90
40 50 60 10 20 30 70 80 90
40 50 60 70 20 30 10 80 90
40 50 60 70 80 30 10 20 90
40 50 60 70 80 90 10 20 30



*(nr+c) = 3
q = 9
D
70 80 90 10 20 30 40 50 60


sus - *(*(A+c)+i);
dreapta - *(*(A+i)+N-c+1);
jos - *(*(A+N-c+1)+i);
stanga - *(*(A+i)+c);

*/
