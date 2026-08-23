#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <bits/stdc++.h>
#include <cassert>
#include <cstdio>
#include <queue>
using namespace std;

///2017 Problema A
/*int main(){
    int x, n, nr = 0, i, *v;
    cin >> n >> x;
    v = (int *)malloc(n * sizeof(int));
    v[0] = x;
    for(i = 1; i < n; i++){
        cin >> v[i];
        if(x > v[i])
            x = v[i];
    }
    for(i = 0; i < n; i++)
        if(v[i] < x * 3)
            nr++;
    cout << x << " " << nr;

    free(v);
}*/


///2017 Problema B
/*int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char aux[15];
    int i = 0;
    float med = 0, s = 0, n[11] = {0}, nr = 0, e;
    while(fin >> aux){
        i++;
        if(i % 5 == 0){
            nr++;
            med += atoi(aux);
            n[atoi(aux)]++;
        }
    }
    //med /= nr;
    //fout << setprecision(7) << med;

    for(i = 1; i < 11; i++){
        if(n[i] != 0){
            e = i - med;
            s += pow(e, 2);
        }
    }
    cout << s;
    nr = 1/(nr-1);

    fin.close();
    fout.close();
}*/
///suprascrie '<<'
/*class forma_geometrica{
        char *tip = NULL;
        int nr_laturi = 0, *lungimi_laturi = NULL;
public:
    forma_geometrica(){
        //cout << "S-a apelat constructorul implicit" << endl;

        this->tip = NULL;
        this->nr_laturi = 0;
        this->lungimi_laturi = NULL;
    }

    forma_geometrica(const char tip[100], int nr_laturi, int *lungimi_laturi){
        //cout << "S-a apelat constructorul explicit cu 4 parametri" << endl;

        this->tip = (char *)malloc(strlen(tip));
        strcpy(this->tip, tip);

        this->nr_laturi = nr_laturi;

        this->lungimi_laturi = (int *)malloc(this->nr_laturi * sizeof(int));
        for(int i = 0; i < this->nr_laturi; i++)
            this->lungimi_laturi[i] = lungimi_laturi[i];
    }

    forma_geometrica(forma_geometrica &a){
        this->tip = (char *)malloc(strlen(a.tip) * sizeof(char));
        strcpy(this->tip, a.tip);

        this->nr_laturi = a.nr_laturi;

        this->lungimi_laturi = (int *)malloc(a.nr_laturi * sizeof(int));
        for(int i = 0; i < this->nr_laturi; i++)
            this->lungimi_laturi[i] = a.lungimi_laturi[i];
    }


    ~forma_geometrica(){
        if(this->tip != NULL)
            free(this->tip);
        this->tip = NULL;

        if(this->lungimi_laturi != NULL)
            free(this->lungimi_laturi);
        this->lungimi_laturi = NULL;

        nr_laturi = 0;
        //cout << endl << "s-a distrus" << endl;
    }


    char* get_tip(){
        return this->tip;
    }

    int get_nr_laturi(){
        return this->nr_laturi;
    }


    int *get_lungimi_laturi(){
        return this->lungimi_laturi;
    }


    void modif_tip(const char *tip){
        if(this->tip != NULL) {
            free(this->tip);
        }
        this->tip = (char *)malloc(strlen(tip) * sizeof(char));
        strcpy(this->tip, tip);
    }

    void modif_nr_laturi(int nr_laturi){
        this->nr_laturi = nr_laturi;
    }

    void modif_lungimi_laturi(int nr_laturi, int *lungimi_laturi){
        if(this->lungimi_laturi != NULL){
            free(this->lungimi_laturi);
        }
        this->nr_laturi = nr_laturi;
        this->lungimi_laturi = (int *)malloc(this->nr_laturi * sizeof(int));
        for(int i = 0; i < this->nr_laturi; i++)
            this->lungimi_laturi[i] = lungimi_laturi[i];
    }

    void modif_all(const char *tip, int nr_laturi, int *lungimi_laturi){
        if(this->tip != NULL) {
            free(this->tip);
        }
        this->tip = (char *)malloc(strlen(tip) * sizeof(char));
        strcpy(this->tip, tip);

        this->nr_laturi = nr_laturi;

        if(this->lungimi_laturi != NULL){
            free(this->lungimi_laturi);
        }
        this->lungimi_laturi = (int *)malloc(this->nr_laturi * sizeof(int));
        for(int i = 0; i < this->nr_laturi; i++)
            this->lungimi_laturi[i] = lungimi_laturi[i];
    }

    forma_geometrica &operator+(forma_geometrica a){
        if(strcmp(this->tip, a.get_tip()) != 0)
            return *this;

        forma_geometrica b(a);
        int *x = this->lungimi_laturi;
        for(int i = 0; i < this->nr_laturi; i++)
            x[i] += b.lungimi_laturi[i];
        b.modif_lungimi_laturi(b.nr_laturi, x);
        return b;
    }

    forma_geometrica operator=(forma_geometrica a){
        tip = (char *)malloc(strlen(a.get_tip()) * sizeof(char));
        strcpy(this->tip, a.get_tip());
        this->nr_laturi = a.get_nr_laturi();
        this->lungimi_laturi = (int *)malloc(this->nr_laturi * sizeof(int));
        int *x = a.get_lungimi_laturi();
        for(int i = 0; i < this->nr_laturi; i++)
            this->lungimi_laturi[i] = x[i];

        forma_geometrica z(a);
        return z;
    }

    void operator<<(forma_geometrica &a){
        cout << a.get_tip() << endl;
        cout << a.get_nr_laturi() << endl;
        int *x = get_lungimi_laturi();
        for(int i = 0; i < a.get_nr_laturi(); i++)
            cout << x[i] << " ";
        free(x);
    }
};


int main(){
    forma_geometrica p;

    int v[4] = {10, 5, 10, 5}, a[4] = {6, 6, 6, 6}, *x;

    forma_geometrica d("dreptunghi", 4, v);
    cout << d.get_tip() << endl;
    cout << d.get_nr_laturi() << endl;
    x = d.get_lungimi_laturi();
    for(int i = 0; i < 4; i++)
        cout << x[i] << " ";

    cout << endl << endl << endl;


    //forma_geometrica *u = (forma_geometrica *)malloc(1 * sizeof(forma_geometrica));
    forma_geometrica *u = new forma_geometrica;

    u->modif_all("patrat", 4, a);

    cout << u->get_tip() << endl;
    cout << u->get_nr_laturi() << endl;
    x = u->get_lungimi_laturi();
    for(int i = 0; i < 4; i++)
        cout << x[i] << " ";
    cout << endl << endl << endl;

    delete u;


    p.modif_tip("patrat");
    p.modif_nr_laturi(4);
    p.modif_lungimi_laturi(4, a);

    cout << p.get_tip() << endl;
    cout << p.get_nr_laturi() << endl;
    x = p.get_lungimi_laturi();
    for(int i = 0; i < 4; i++)
        cout << x[i] << " ";

    p.modif_all("dreptunghi", 4, v);

    cout << endl << endl << endl;

    cout << p.get_tip() << endl;
    cout << p.get_nr_laturi() << endl;
    x = p.get_lungimi_laturi();
    for(int i = 0; i < 4; i++)
        cout << x[i] << " ";
    cout << endl << endl << endl;


    forma_geometrica z;
    z = p+d;
    cout << z.get_tip() << endl;
    cout << z.get_nr_laturi() << endl;
    x = z.get_lungimi_laturi();
    for(int i = 0; i < 4; i++)
        cout << x[i] << " ";
}*/



///Automobile - 2023 faza locala
/*ifstream fin("test.in");

int find_index(char results[100][20], char s[], int numberElements);
char *standard_string(char s[]);
void print(char results[100][20], int numberElements);

int main()
{
    char s[20], results[100][20];
    int numberElements = 0;

    while(fin.getline(s, 20)) {
        strcpy(s, standard_string(s));
        if (find_index(results, s, numberElements) == 0) {
            strcpy(results[numberElements++], s);
        }
    }

    print(results, numberElements);
    fin.close();
}

int find_index(char results[100][20], char s[], int numberElements) {
    for (int i = 0; i < numberElements; i++) {
        if (stricmp(s, results[i]) == 0)
            return 1;
    }

    return 0;
}

char *standard_string(char s[]) {
    for (int i = 0; i < strlen(s); ++i) {
        s[i] = tolower(s[i]);
    }

    s[0] = toupper(s[0]);

    return s;
}

void print(char results[100][20], int numberElements) {
    for (int i = 0; i < numberElements; ++i) {
        cout << results[i] << endl;
    }
}*/



///Sum - 2022 faza locala
/*int main()
{
    int n;
    cin >> n;
    cout << "Suma primelor " << n << " numere este " << (n + 1) * n / 2 << " = " << (n + 1) * n / 2;
}*/



///Phone - 2022 faza locala
/*void nr_standard(char nr[15]){
    if(strncmp("07", nr, 2) == 0)
        cout << "(004) " << nr[0] << nr[1] << nr[2] << nr[3] << " " << nr[4] << nr[5] << nr[6] << " " << nr[7] << nr[8] << nr[9] << endl;
    if(strncmp("004", nr, 3) == 0)
        cout << "(004) " << nr[3] << nr[4] << nr[5] << nr[6] << " " << nr[7] << nr[8] << nr[9] << " " << nr[10] << nr[11] << nr[12] << endl;
    if(strncmp("+4", nr, 2) == 0)
        cout << "(004) " << nr[2] << nr[3] << nr[4] << nr[5] << " " << nr[6] << nr[7] << nr[8] << " " << nr[9] << nr[10] << nr[11] << endl;
}

int main(){
    int n;
    char nr[15];

    cin >> n;
    for(int i; i < n; i++){
        cin >> nr;
        nr_standard(nr);
    }
}*/


///Matrix - 2022 faza locala
/*int a[100][100], b[100][100], c[100][100];

int i, j, x, y, m, n, p, k;

int main()
{
    cin >> n >> m >> p;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];


    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> b[i][j];


    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            c[i][j] = 0;


    for (i = 0; i < n; ++i) {
        for (j = 0; j < p; ++j) {
            for (k = 0; k < m; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (i = 0; i < n; ++i) {
        cout << endl;
        for (j = 0; j < m; ++j) {
            cout << c[i][j] << " ";
        }
    }
}*/
/*
3 3 3

1 2 3
4 5 6
7 8 9

1 0 0
0 1 0
0 0 1
*/


///Easy as PI - 2021 faza locala
/*const double PI = 3.14159265;

int main() {
    int n, a, b;

    std::cout << std::fixed;

    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> a >> b;
        std::cout << PI * a * b << std::endl;
    }

    return 0;
}*/
/*
2
2 3
4 5
*/


/*int cutie[101], nr_cutii, nr_colegi, posibilitati = 0;

void gen_sume(int start, int s)
{
  if (start == nr_cutii + 1) {
    return;
  }
    if (s % nr_colegi == 0 && s != 0){
        cout << s << endl;
        posibilitati++;
    }

    gen_sume(start + 1, s + cutie[start]);

}

int main()
{
  int nr = 0, i;
  cin >> nr_cutii >> nr_colegi;
  for (i = 0; i < nr_cutii; i++)
    cin >> cutie[i];
  for (i = 0; i < nr_cutii; i++){
    //for(int j = 1; j < nr_cutii; j++){
        cout << i << endl;
        gen_sume(i,0);
    }
    //}
  cout << "     " << posibilitati << endl;
}*/


///Back to basics - 2021 faza locala
/*int prim_factor(int n);
int main() {
    int n;

    cin >> n;
    cout << n * prim_factor(n);
}


int prim_factor(int n){
    int ok;
    for (int i = n / 2; i >= 2; i--) {
        if(n % i == 0) {
            ok = 0;
            for(int d = 2; d*d <= i; d++)
                if(i % d == 0)
                    ok = 1;
            if(ok == 0)
                return i;
        }
    }
}*/



///Most vexing indeed - 2021 faza local
/*class Statistics {
    vector<int> numbers;

    public:
    Statistics() {
        numbers.clear();
        int tmp;

        while (cin >> tmp) {
            numbers.push_back(tmp);
        }
    }

    int sum() {
        int s = 0;

        for (auto n: numbers)
            s += n;

        return s;
    }

    float median() {
        const auto middle_itr = numbers.begin() + numbers.size() / 2;
        nth_element(numbers.begin(), middle_itr, numbers.end());

        if (numbers.size() % 2 == 0) {
            const auto left_mid_itr = max_element(numbers.begin(), middle_itr);
            return (*left_mid_itr + *middle_itr) / 2;
        } else {
            return *middle_itr;
        }
    }

    float mean() {
        return (float)sum() / numbers.size();
    }
};


int main() {
    Statistics stats;

    cout << stats.sum() << " " << stats.median() << " " << stats.mean() << endl;

    return 0;
}*/


///Make it run - 2020 faza local
/*int main (void)
{
    int a,
    b = 0;
    srand(66);
    a = rand();                     // This is
    b = rand();                     // "pure luck"
    if ((a == b) && (a-1 == b-1))
    {
        std::cout << "fail\n";
        return 0;
    }
    std::cout << "success\n";
    return 0;
}*/


///Mouse - 2020 faza local
/*ifstream fin("soarece.in");
ofstream fout;

int b[14][14], a[14][14], is, js, ib, jb, n, m, mx = 0;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

void citire()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            fin>>a[i][j];
    }
    fin >> is >> js >> ib >> jb;
}

void afis()
{
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            if (b[i][j] == 1 || b[i][j] == 0)
                fout << 0 << " ";
            else
                fout << b[i][j] - 1 << " ";
        fout<<endl;
    }
}

void copiere(){
    int i, j;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            b[i][j] = a[i][j];
}

int valid (int x, int y)
{
    if (x>n || x<1 || y>m || y<1)
        return 0;
    return !a[x][y];
}

void bktr(int i, int j, int pas)
{
    for (int dir=0; dir<=3; dir++) {
        int l,c;
        l=i+dy[dir];
        c=j+dx[dir];
        if (valid (l,c)==1) {
            a[l][c]=pas;
            if(l==ib && c==jb) {
                if(mx < pas){
                    mx = pas;
                    copiere();
                }
            }
            else
                bktr(l,c,pas+1);
            a[l][c]=0;
        }
    }
}

int main()
{
    fout.open("soarece.out");
    citire();
    a[is][js]=1;
    bktr(is,js,2);
    afis();
    fout.close();
    return 0;
}*/

///Square - etapa judeteana 2018
// This program should print all the perfect squares that are less than or equal
// to n, in descending order. However, the program does not properly stop and
// starts printing very large numbers. What could be the cause?
//
// Hint: you can make the program work with only one changed line.
/*int main() {
    int n, root;

    cin >> n;

    // 0 is also a perfect square, so we need to check it
    while (n >= 0) {
        // take the integer part of the square root of n
        root = sqrt(n);

        // if n is a perfect square, print it
        if (n == root * root) {
            cout << n << " ";
        }

        n--;
    }

    return 0;
}*/

///Special_macro - etapa judeteana 2018
// Who says C can't have boolean types?
// We implemnt our own!
/*#define true 1
#define false 0

// Why use built in "if" when we can hack it?
#define IIF(cond) IIF_ ## cond
#define IIF_0(t, f) f
#define IIF_1(t, f) t

// Writing "*" for multiplication is too mainstream.
#define MULTIPLY(a, b) ((a) * (b))

// You got the idea...
#define ADD(a, b) ((a) + (b))


int main(void)
{
    printf("Your mission, should you choose to accept it, is to test and make\
            sure these macros work!\n");

    printf("Expected result 1, actual result: %d\n", IIF(0)(0, 1));
    printf("Expected result 0, actual result: %d\n", IIF(1)(0, 1));
    printf("Expected result 0, actual result: %d\n", MULTIPLY(1, 0));
    printf("Expected result 1, actual result: %d\n", MULTIPLY(1, 1));
    printf("Expected result 36, actual result: %d\n", MULTIPLY(6, 6));
    printf("Expected result 3, actual result: %d\n", MULTIPLY(1, 1 + 2));
    printf("Expected result 3, actual result: %d\n", MULTIPLY(1 + 2, 1));
    printf("Expected result 3, actual result: %d\n", MULTIPLY(1 + 2, 1 + 0));
    printf("Expected result 18, actual result: %d\n", MULTIPLY(1 + 2, 6 + 0));
    printf("Expected result 18, actual result: %d\n",
            MULTIPLY(1 + 2, 1 + 2) + MULTIPLY(1 + 2, 1 + 2));

    printf("Expected result 81, actual result: %d\n", \
            MULTIPLY(1 + 2, 1 + 2) * MULTIPLY(1 + 2, 1 + 2));

    printf("Expected result 792, actual result: %d\n", \
            MULTIPLY(6 + 2, 1 + 2) * MULTIPLY(9 + 2, 1 + 2));

    printf("Expected result 57, actual result: %d\n", \
            ADD(MULTIPLY(6 + 2, 1 + 2), MULTIPLY(9 + 2, 1 + 2)));

    printf("Expected result -57, actual result: %d\n", \
           -ADD(MULTIPLY(6 + 2, 1 + 2), MULTIPLY(9 + 2, 1 + 2)));

    assert(1 == IIF(0)(0, 1));
    assert(0 == IIF(1)(0 ,1));
    assert(0 == MULTIPLY(1, 0));
    assert(0 == MULTIPLY(0, 1));
    assert(1 == MULTIPLY(1, 1));
    assert(36 == MULTIPLY(6, 6));
    assert(3 == MULTIPLY(1, 1 + 2));
    assert(3 == MULTIPLY(1 + 2, 1));
    assert(3 == MULTIPLY(1 + 2, 1 + 0));
    assert(18 == MULTIPLY(1 + 2, 6 + 0));
    assert(18 == MULTIPLY(1 + 2, 1 + 2) + MULTIPLY(1 + 2, 1 + 2));
    assert(81 == MULTIPLY(1 + 2, 1 + 2) * MULTIPLY(1 + 2, 1 + 2));
    assert(792 == MULTIPLY(6 + 2, 1 + 2) * MULTIPLY(9 + 2, 1 + 2));
    assert(57 == ADD(MULTIPLY(6 + 2, 1 + 2),MULTIPLY(9 + 2, 1 + 2)));
    assert(-57 == -ADD(MULTIPLY(6 + 2, 1 + 2),MULTIPLY(9 + 2, 1 + 2)));

    return 0;
}
*/


///Ip_converter - etapa judeteana 2018

/*#define EXIT_CONVERTER {cout << "Invalid IPv4 address" << endl; \
                        exit(EXIT_FAILURE);}


int convert_string_to_int(string str) {
    int x;
    stringstream geek(str);
    geek >> x;
    return x;
}


string transform_in_binary(int octet_value) {

    string octet_binary;

    for(int digit = 7; digit >= 0; digit--) {
        octet_binary.push_back(octet_value & (1 << digit) ? '1' : '0');
    }

    reverse(octet_binary.begin(), octet_binary.end());

    return octet_binary;
}

string foo(string ipv4_dec) {

    string ipv4_bin;
    size_t pos;
    unsigned int count = 4;
    unsigned int octet_int;

    pos = ipv4_dec.find('.');
    while (count) {

        octet_int = convert_string_to_int(ipv4_dec.substr(0, pos));

        ipv4_dec = ipv4_dec.substr(pos + 1, ipv4_dec.length());

        ipv4_bin += transform_in_binary(octet_int);

        if (count != 1)
            ipv4_bin.push_back('.');

        pos = ipv4_dec.find('.');

        count--;
    }

    return ipv4_bin;
}

int main() {

    string ipv4_dec, ipv4_bin;

    cin >> ipv4_dec;

    ipv4_bin = foo(ipv4_dec);

    int i;
    for(i = 7; i >= 0; i--)
        cout << ipv4_bin[i];
    cout << ".";
    for(i = 16; i >= 9; i--)
        cout << ipv4_bin[i];
    cout << ".";
    for(i = 25; i >= 18; i--)
        cout << ipv4_bin[i];
    cout << ".";
    for(i = 34; i >= 27; i--)
        cout << ipv4_bin[i];
    return 0;
}*/




///Asamblica - etapa judeteana 2019
/*int main()
{
	unsigned int i;
	i = (freopen("asamblica.in", "rb", stdin), 0);

	// IMPORTANT: De aici in jos aveti voie sa modificati.
	char c;

	while (1) {
		c = getchar();
		if (i > 0)
			putchar(" \n"[(i & 0x0F) == 0 || c == EOF]);
		if (c == EOF) {
			break;
		}
		printf("%02hhX", c);
		i++;
	}
	return 0;
}*/




///Minmax - etapa judeteana 2019
// IMPORTANT: Singurele linii care pot fi schimbate sunt cele care incep
// cu #define.
/*#define SIGNBITONLY(x)	((x) >> (sizeof((x)) * 8 - 1))
#define ABS(x)		(((x) + SIGNBITONLY(x)) ^ SIGNBITONLY(x))
#define MINMAXOP(x, y, OP) (((x + y) OP ABS(x - y)) / 2)
#define MIN(x, y)	MINMAXOP(x, y, -)
#define MAX(x, y)	MINMAXOP(x, y, +)
// 3 5
// max = (5+3)/2 + (5-3)/2 = 4 + 1 = 5
// min = (5+3)/2 - (5-3)/2 = 4 - 1 = 3
// 4 5 => max = 4.5 + 0. 5 = 5        => max = 0

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << MIN(a, MIN(b, c)) << ' ' << MAX(MAX(a, b), c) << '\n';
	return 0;
}*/



///Easy_peasy - etapa interjudeteana 2019
/*class A {
public:
   int s = 5;

   static void print1() {
       cout << "1 ";
   }

   void print2() {
       std::cout << "5";
   }
};

A * a;
int main() {
   int i, s[] = {2, 3, 4};
   a->print1();
   for(i = 0; i < 3; i++)
        cout << i[s] << " ";
   a->print2();
   return 0;
}*/



///Elevator - etapa interjudeteana 2019 ????
/*#define maxN 0xb055

// 00010100 = 20
// 00001010 = 10
// 00000101 = 5


int main() {
    int n, q, x, logN, v[maxN];
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (logN = 1; logN<=n; logN<<=1);
    //cout << logN << endl;
    while (q--) {
        cin >> x;
        int pos = 0;
        for (int step = logN; step; step>>=1) {
            //cout << pos << ", " << step << " ";
            if (pos + step < n && v[pos + step] <= x) {
                pos += step;
            }
        }
        if (v[pos] == x) {
            cout << "fair enough\n";
        } else {
            cout << "bad luck\n";
        }
    }
    return 0;
}*/




///Gigelina - etapa interjudeteana 2019
/*int main() {
	int n;
	int *vector;

	cin >> n;

	// Allocate memory
	vector = new int[n];

	// Read input
	for (int i = 0; i < n; i++)
		cin >> vector[i];

	// Math operations on the vector
	for (int i = 0; i < n; i++) {
		if (vector[i] % 2 == 0) {
			vector[i] *= 2;
			vector[i] += 1;
		} else
			vector[i] *= 3;
			vector[i] -= 1;
	}


	// Sum all the elements
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += vector[i];

	// Print the sum
	cout << sum << "\n";

	// Print the elements
	for (int i = 0; i < n; i++)
		cout << vector[i] << " ";
	cout << "\n";

	// Free the allocated memory
	delete[] vector;

	return 0;
}*/





///Inheritance - etapa judeteana 2020
/*#define check_eq(x, y) ((x) == (y))

class A
{
public:
    int x;
    int y;

    A();
    ~A();
};

A::A()
{
    x = 42;
    y = 41;
    if (!check_eq(x, 24))
    {
        cout << "A.ctor()\n";
    }
}

A::~A()
{
    cout << "~A.dtor()\n";
}

class B : public A
{
public:
    B();
    ~B();
};

B::B() : A()
{
    cout << "B.ctor()\n";
    // Make sure 42 is the universal answer
    cout << "is 42 the answer to the Ultimate Question of Life, the Universe and Everything? " << (x == 42 ? "yes" : "no") << "\n";
}

B::~B()
{
    cout << "~B.dtor()\n";
}

int main()
{
    A* a = new B();
    delete (B*)a;

    return 0;
}*/




///Gigel_si_covid - etapa judeteana 2020
/*#define POLI_FORBIDDEN_DREAM 6969696969

using zacusca_t = vector<vector<int>>;
using strangers_t = vector<long long int>;


int main() {
    int n;
    cin >> n;

    zacusca_t zacusca(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> zacusca[i][j];
        }
    }

    strangers_t strangers(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> strangers[i];
    }

    vector<int> dp(n + 1);
    // Caz de baza
    dp[0] = 0;

    // Caz general
    for (int i = 1; i <= n; ++i) {
        // Adaugam interactiunile cu strainii.
        dp[i] = strangers[i];

        // Adaugam interactiunile de tip zacusca.
        for (int j = 1; j < i; ++j) {
            if (zacusca[j][i]) {
                dp[i] += dp[j];
            }
        }
    }

    // Solutie: X = sum(dp[i])
    long long int X = 0;
    for (int i = 1; i <= n; ++i) {
        X += dp[i];
    }

    cout << X % POLI_FORBIDDEN_DREAM << endl;

    return 0;
}*/



///Empty_main - etapa judeteana 2020

/*class apel{
private:
    int x;
public:
    apel() {
        cin >> x;
        for(int i = 2; i <= x; i++)
            if(is_prime(i) == true)
                cout << i << endl;
    }

    bool is_prime(int x){
        for (int i = 2; i*i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
};

apel a;


int main() { return 0; }*/


///Bogdan - etapa judeteana 2021
//4294967297 4294967295
/*int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    if ((double)a * b > ULLONG_MAX) { // Poti modifica doar aceasta linie!
        cout << "Nu";
    } else {
         cout << "Da" << endl << a * b;
    }
    //cout << endl << a*b;
    return 0;
}*/



///Decebal la internship - etapa judeteana 2021
/*double find_best_phone(vector<int> &phones, int n) {
    int number_phones = n;
    sort(phones.begin(), phones.begin() + number_phones);
    if (number_phones % 2 == 1)
        return phones[number_phones / 2];
    else
        return (phones[(number_phones - 1) / 2] + phones[number_phones / 2]) / 2;
}


int main() {
    int n;
    ifstream fin("input.txt");
    fin >> n;
    vector<int> phones{n, 0};
    for (int i = 0; i < n; ++i) {
        fin >> phones[i];
    }

    ofstream fout("output.txt");
    fout << find_best_phone(phones, n);
    fin.close();
    fout.close();
    return 0;
}*/

///Matematică POO - etapa judeteana 2021
// Clasa memoreaza un nr complex
/*class complex
{
private:
    int r, i;   // r - partea reala, i - partea imaginara
public:
    complex(){
        r = 0;
        i = 0;
    }  // creeaza numarul imaginar nul
    complex(int pr, int pi){
        r = pr;
        i = pi;
    } // pr - valoarea termenului real, pi - val. term. imaginar
    char* afisare(){
        char s[10], re[3], im[3];
        re[0] = char((this->r < 0 ? (this->r * -1) : this->r) + 48);
        strcat(re, " ");
        im[0] = char((this->i < 0 ? (this->i * -1) : this->i) + 48);
        strcat(im, " ");
        s[0] = '\0';
        strcat(s, re);
        if(this->i != 0 && this->i < 0){
            strcat(s, "-");
            strcat(s, im);
            strcat(s, "i");
        }
        else{
            strcat(s, "+");
            strcat(s, im);
            strcat(s, "i");
        }

        return s;
    } // pregateste un sir pentru a fi afisat
    int real(){
        return r;
    }// returneaza partea reala
    int imaginar(){
        return i;
    } // returneaza partea imaginara
    void set(int pr, int pi){
        r = pr;
        i = pi;
    }// stabileste valoarea partii reale si a celei imaginare

    complex operator +(complex a){
        return complex(this->r + a.r, this->i + a.i);
    }
    complex operator -(complex a){
        return complex(this->r - a.r, this->i - a.i);
    }
    complex operator *(complex a){
        int re, im;
        re = this->r * a.r - this->i * a.i;
        im = this->r * a.i + this->i * a.r;
        return complex(re, im);
    }
    complex operator =(complex a){
        this->r = a.r;
        this->i = a.i;
    }
};
// aici va fi scris codul tau

int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    int a, b, c, d;
    while(fin >> a >> b >> c >> d)
    {
        class complex m(a,b), n(c,d), o;
        o = m + n;
        fout << o.afisare() <<"\n";
        o = m - n;
        fout << o.afisare() <<"\n";
        o = m * n;
        fout << o.afisare() <<"\n";
    }
    return 0;
}*/



///Ciur - etapa judeteana 2022
/*
//-------------------------- Defining a set --------------------------------

#define MAX_NR 10000000
#define SET_SIZE ((MAX_NR + 1) / 8)
typedef unsigned char SET[SET_SIZE];

SET my_set = {0};

//------------------------- Helper functions! ------------------------------

static inline void insert_in_set(SET s, unsigned int n){
    // Find the corresponding cell and set one of its bits
    s[n / 8] |= 1 << n % 8;
}

static inline int is_in_set(SET s, unsigned int n){
    // Find the corresponding cell and test one of its bits
    return (s[n / 8] & (1 << n % 8) > 0);
}

//------------------------ Sieve functions! --------------------------------

unsigned int find_next_prime(SET sieve, unsigned int x){
    while (is_in_set(sieve, ++x));

    return x;
}

void init_seive(SET sieve){
    unsigned int i, d;

    insert_in_set(sieve, 0);


    for (d = 2; d <= MAX_NR; d++){
        if (!is_in_set(sieve, d)){                // if d is prime
            for (i = d * d; i <= MAX_NR; i += d){   // we'll jump d steps and mark
                insert_in_set(sieve, i);
            }
        }
    }
}


int main()
{
    unsigned int n, x;

    init_seive(my_set);

    cin >> n;
    while (n--){
        cin >> x;
        cout << find_next_prime(my_set, x) << endl << endl;
    }


             return 0;
}*/


#define MAX_N 1000

using namespace std;

struct point {
  int l, c;
};

// there is a path available on that square
bool path[MAX_N][MAX_N];
// we have seen that squre
bool seen[MAX_N][MAX_N];
// we can reach that wall
bool reachable_wall[MAX_N][MAX_N];


point dir[] = {
  {-1,  0},
  { 0,  1},
  { 1,  1},
  { 1,  0},
  { 0, -1},
  {-1, -1}
};

// Perform a BFS from coordinates (startx, starty)
bool bfs(int startx, int starty, bool touch_wall) {
  int i;
  queue<point> q;

  seen[startx][starty] = true;
  q.push({startx, starty});
  while (!q.empty()) {
    q.pop();
    point p = q.front();

    for (i = 0; i < (int) (sizeof(dir) / sizeof(point)); i+=1) {
      point new_p = {p.l + dir[i].l, p.l + dir[i].c};

      if (!path[new_p.l][new_p.c] && touch_wall) {
        reachable_wall[new_p.l][new_p.c] = true;
      } else if (reachable_wall[new_p.l][new_p.c] && !touch_wall) {
            return true;
      } else if (!seen[new_p.l][new_p.c] && path[new_p.l][new_p.c]) {
        seen[new_p.l][new_p.c] = true;

        q.push(new_p);
      }
    }
  }

  return false;
}

/**
6 8
0 0 0 0 0 0 0 0
0 1 0 1 1 0 0 0
0 1 0 1 1 1 0 0
0 1 1 1 1 0 0 0
0 0 1 0 1 1 0 0
0 0 0 0 0 0 0 0
3 3 6 8
*/
int main(void) {
  int L1, C1, L2, C2;
  int N, M;
  int i, j;

  // read the input
  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; ++i) {
    for (j = 1; j <= M; ++j) {
      int cell;

      scanf("%d", &cell);
      // set the path availability
      path[i][j] = (cell == 1 ? true : false);
    }
  }

  scanf("%d %d %d %d", &L1, &C1, &L2, &C2);

  bfs(L1, C1, true);

  // if the first player can reach the second one
  if (bfs(L1, C1, true)) {
    printf("OK.\n");
    return 0;
  }

  if (bfs(L2, C2, false))
    printf("BOOM.\n");
  else
    printf("!OK.\n");

  return 0;
}
