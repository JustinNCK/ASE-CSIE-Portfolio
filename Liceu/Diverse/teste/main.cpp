#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/*int main()
{
    /*
    int a = 5;
    int *b;
    b = &a;
    cout << *b << endl;
    *b = 10;
    cout << a;
    */

    /*
    int nr, d, i;
    cin >> nr;
    i = 1;
    for (d = 2; d < nr / 2; d++)
    {
        if (nr % d == 0)
        {
            i = 0;
            d = nr/2;
        }
    }
    if (i == 1)
        cout << "numarul este prim";
    else
        cout << "numarul nu este prim";
    */

    /*int a[10][10];
    int m, n, i, j;

    cout << "Dati nr de linii si de coloane: ";
    cin >> n >> m;

    // Citire elemente matrice
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << "a[" << i << "]["  << j << "]=";
            cin >> a[i][j];
        }
    }

    // Afisare elemente matrice
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/



//65 - 90 sunt litere mari
//97 - 122 sunt litere mici
//32 este diferenta
/*int main()
{
    char sir[50], sir2[50];
    char* cuv;
    int n, i;
    cout << "introduceti sirul: ";
    cin.getline(sir, 50);
    cuv = strtok(sir, " ");
    while (cuv != NULL)
    {
        for (i = 0; i < strlen(cuv); i++)
        {
            if (i == 0)
            {
                n = cuv[i];
                n = n - 32;
                cuv[i] = n;
            }
        }
    }
    cout << cuv;
    return 0;
}*/


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




int main()
{
    int v[30], i, n, j, a, aux;
    ifstream fin("bac.txt");
    n = 0;
    while (cin >> v[n])
        n++;
    for(i = 0; i < n; i++)
        if (v[i] < 10 && v[i] >99)
        {
            for (j = i; j < n - 1; j++)
                v[j] = v[j + 1];
            n--;
        }
    a = 0;
    while (a == 0)
    {
        a = 1;
        for (i = 0; i < n - 1; i++)
        {
            aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
            a = 0;
        }
    }
    for (i = 0; i < n; i++)
        cout << v[i] << " ";
}
