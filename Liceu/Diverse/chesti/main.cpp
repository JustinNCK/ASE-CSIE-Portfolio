#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int v[100] = { 0 }, b[2] = { 0 }, i, n, j, a, aux, cont, ok;
    ifstream fin("bac.txt");
    cont = 0;
    while (fin >> a)
        if(a <= 99)
            v[a] = 1;
    for (i = 98; i >= 10 && cont != 2; i--)
        if (v[i] == 0 && (i % 10 != i / 10))
        {
            b[cont] = i;
            cont++;
        }
    if(cont < 2)
        cout << "nu exista";
    else
        cout << b[0] << " " << b[1];
}
