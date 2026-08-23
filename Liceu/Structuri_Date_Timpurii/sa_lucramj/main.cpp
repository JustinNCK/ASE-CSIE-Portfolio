#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;

/*struct mat{
    int r, g, b;
};

int main()
{
    ifstream fin("date.txt");
    int m, s, i, j, k;
    int o, f;
    int a, b, mxr, mxg, mxb;
    struct mat **A, **M;
    fin >> m >> s;
    k = m / s;
    A = (struct mat **)malloc(m * sizeof(struct mat *));
    for(i = 0; i < m; i++){
        *(A+i) = (struct mat *)malloc(m * sizeof(struct mat));
    }
    M = (struct mat **)malloc(k * sizeof(struct mat *));
    for(i = 0; i < k; i++){
        *(M+i) = (struct mat *)malloc(k * sizeof(struct mat));
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            fin >> (*(*(A + i)+j)).r >> (*(A + i)+j)->g >> A[i][j].b;
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            cout << (*(*(A + i)+j)).r << " " << (*(A + i)+j)->g << " " << A[i][j].b << " ";
        }
        cout << endl;
    }
    a = 0;
    b = 0;
    int h = 0;
    int d = 0;
    for(o = 0; o < k; o++){
        mxr = 0;
        mxg = 0;
        mxb = 0;
        h = 0;
        for(f = 0; f < k; f++){
            for(i = d; i < s + d; i ++){
                for(j = h; j < s + h; j++){
                    if((*(A+i)+j)->r > mxr)
                        mxr = (*(A+i)+j)->r;

                    if((*(A+i)+j)->g > mxg)
                        mxg = (*(A+i)+j)->g;

                    if((*(A+i)+j)->b > mxb)
                        mxb = (*(A+i)+j)->b;
                }
            }
            h += s;
            (*(M+o)+f)->r = mxr;
            (*(M+o)+f)->g = mxg;
            (*(M+o)+f)->b = mxb;

        }
        d += s;
    }
    for(i = 0; i < k; i++){
        for(j = 0; j < k; j++){
            cout << (*(M + i)+j)->r << " " << (*(M + i)+j)->g << " " << (*(M + i)+j)->b << " ";
        }
        cout << endl;
    }
    for(i = 0; i < m; i++)
        free(*(A+i));
    free(A);
    for(i = 0; i < k; i++)
        free(*(M+i));
    free(M);
    fin.close();
}*/







/*int unu();
void doi();
int main()
{
    int x;
    cin >> x;
    if(x == 1)
        cout << unu();
    if(x == 2)
        doi();
    if(x == 3)
        trei();
    if(x == 4)
        patru();
}

int unu()
{
    int n, i, k;
    cin >> n;
    int v[n+1];
    for(i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(i = 1; i < n; i++){
        if(v[i] == i){
            if(v[i] == v[i+1]){
                k = 2*i-1;
                while(i != k){
                    if(v[i] != v[i+1])
                        return 0;
                    i++;
                }
            }
       }
        else
            return 0;
    }
    return 1;
}
int ver(int n, int v[8])
{
    int i, k;
    for(i = 0; i < n; i++){
        if(v[i] == i){
            if(v[i] == v[i+1]){
                k = 2*i-1;
                while(i != k){
                    if(v[i] != v[i+1])
                        return 0;
                    i++;
                }
            }
       }
        else
            return 0;
    }
    return 1;
}
void combinationUtil(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r){
        //if(ver(r, data) == 1){
            for (int j=0; j<r; j++)
                cout << data[j] << " ";
            cout << endl;
            return;
        //}
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++) {
        data[index] = arr[i];
        combinationUtil(arr, data, 1, end, index+1, r);
    }
}

void printCombination(int arr[], int n, int r) {
    int data[r];

    combinationUtil(arr, data, 0, n-1, 0, r);
}

void doi() {
    int n = 8;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    printCombination(arr, n, n);
}*/





/*int main()
{
    int n, k;
    cin >> n;
    k = ceil(sqrt(n));
    if(pow(k, 2)  - n < k)
        cout << k;
    else
        cout << n - pow(k - 1, 2);
}*/
/*
1  1 2 2  1 2 3 3 3  1  2  3  4  4  4  4   1  2  3  4  5  5  5  5  5
1  2 3 4  5 6 7 8 9  10 11 12 13 14 15 16  17 18 19 20 21 22 23 24 25
*/

/*int s(int n, int a, int b);
int s1(int n);
int s2(int n, int k);
int main()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    cout << s1(n);
    cout << endl;
    cout << s2(n, k);
    cout << endl;
    cout << s(n, a, b);
    return 0;
}

int s1(int n)
{
    if(n == 0)
        return 0;
    return 1 + s1(n / 10);
}

int s2(int n, int k)
{
    int p = 1, cn = 0;
    while(n != 0){
        if(n % 10 == k){
            cn = cn + n % 10 * p;
            p *= 10;
        }
        cn = cn + n % 10 * p;
        n /= 10;
        p *= 10;
    }
    return cn;
}

int s(int n, int a, int b)
{
    int nr = s1(n);
    if(s2(n, a) != n)
        nr = nr - s1(s2(n, a)) + s1(n);
    if(s2(n, b) != n)
        nr = nr - s1(s2(n, b)) + s1(n);
    return nr;
}*/

/*
121532 2 2 3
*/


/*int main()
{
    int n, i, j, a[100][100];
    cin >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(i - 1 <= n - j)
                a[i][j] = n - j;
            else
                a[i][j] = a[i][j - 1];
    for(i = 1; i <= n; i++){
        cout << endl;
        for(j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
    }
}*/



///simulare BAC 2023
///SIII
///1
/*void NrImp(int &nr, int x, int y);

int main()
{
    int x, y, nr;
    cin >> x >> y;
    NrImp(nr, x, y);
    cout << nr;
}

void NrImp(int &nr, int x, int y)
{
    int nrd;
    for(int i = x; i <= y; i++){
        nrd = 0;
        for(int d = 1; d <= i; d += 2){
            if(i % d == 0)
                nrd++;
            if(nrd > 3){
                d = i+1;
            }
        }
        if(nrd == 3){
            nr++;
        }
    }
}*/



///2
/*int main()
{
    char t[101], *c, f[] = "fam. ", g[] = "gen. ", s[] = "spe. ", n[101];
    cin.getline(t, 101);
    c = strtok(t, " ");
    c = strtok(NULL, " ");
    strcpy(n, f);
    strcat(n, c);
    strcat(n, " ");
    c = strtok(NULL, " ");
    c = strtok(NULL, " ");
    strcat(n, g);
    strcat(n, c);
    strcat(n, " ");
    c = strtok(NULL, " ");
    c = strtok(NULL, " ");
    strcat(n, s);
    strcat(n, c);
    cout << n;
}*/
/*
FAMIL. PHASIANIDAE GEN. MELEAGRIS SP. GALLOPAVO
FAM. PHASIANIDAE G. MELEAGRIS SPECI. GALLOPAVO
*/



///3
/*int main()
{
    ifstream fin("bac.txt");
    int x, mx, i, nr = 2;
    cout << "1 ";
    fin >> x;
    mx = x;
    i = x;
    while(fin >> x){
        if(x >= mx)
            if(x != i){
                cout << nr << " ";
            }
        if(x > mx)
            mx = x;
        i = x;
        nr++;
    }
}*/


/*void unu(char a[100]);
void doi(char a[100], char r[100]);

int main()
{
    char a[100], r[100];
    int i;
    cin >> i >> a >> r;
    if(i == 1)
        unu(a);
    else
        doi(a, r);
}

void unu(char a[100])
{
    int i, j, t = 0, nr;
    if(abs(65 - int(a[0])) < abs(26 - abs(65 - int(a[i])))){
            t += abs(65 - int(a[0]));
        }
        else{
            t += abs(26 - abs(65 - int(a[i])));
        }
    for(i = 0; i < strlen(a) - 1; i++){
        nr = abs(int(a[i] - a[i + 1]));
        if(nr < abs(26 - nr)){
            t += nr;
        }
        else{
            t += abs(26 - nr);
        }
    }
    cout << t;
}

void doi(char a[100], char r[100])
{
    char s[200], l[2];
    int i, j, t, mx, mx1, nr, q = 0, ok, nr_min, nr_total = 1;
    cout << strlen(a) << endl;
    for(i = 0; i < strlen(a) - 1; i++){
        mx = 14;
        mx1 = 14;
        ok = 27;
        nr_min = 1;
        for(j = 0; j < strlen(r); j++){
            mx = 14;
            mx1 = 14;
            nr = abs(int(a[i] - r[j]));
            if(mx > 26 - nr){
                mx = 26 - nr;
            }
            if(mx > nr){
                mx = nr;
            }
            nr = abs(int(a[i + 1] - r[j]));
            if(mx1 > 26 - nr){
                mx1 = 26 - nr;
            }
            if(mx1 > nr){
                mx1 = nr;
            }
            if(mx1 + mx < ok) {
                ok = mx1 + mx;
                l[0] = r[j];
                nr_min = 1;
            }
            else if (mx1 + mx == ok) {
                nr_min++;
            }
        }
        s[i + q] = a[i];
        s[i + q + 1] = l[0];
        q++;
        nr_total *= nr_min;
    }
    nr_total %= 666013;
    s[i + q + 1] = '\0';
    s[strlen(s)] = a[strlen(a) - 1];
    s[strlen(s)] = '\0';
    unu(s);
    cout << endl << s << endl << nr_total;
}*/

/**

2
AMYMAMAMY
BCDEFGHIJKLNOPQRSTUVWX

2
BBTH
AEIOU


1
BBTH
AEIOU


            for(o = 0; o < strlen(r); o++)
                if(int(r[o]) == int(l[0]) - mx)
                    ok = 1;
            if(ok = 1){
                nr = abs(int(a[i] - r[j]));
                if(mx > 26 - nr){
                    mx = 26 - nr;
                    l[0] = r[j];
                }
                if(mx > nr){
                    mx = nr;
                    l[0] = r[j];
                }
                nr = abs(int(a[i + 1] - r[j]));
                if(mx > 26 - nr){
                    mx = 26 - nr;
                    l[0] = r[j];
                }
                if(mx > nr){
                    mx = nr;
                    l[0] = r[j];
                }
            }
*/
