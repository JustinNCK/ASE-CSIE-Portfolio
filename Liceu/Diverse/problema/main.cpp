#include <fstream>
#include <iostream>
using namespace std;

/*int main()
{
    ifstream fin("atestat.in");
    if (!fin)
        cout << "fisierul nu exista";
    int n, p, k, x, i;
    fin >> n >> p >> k;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        if (x % p == k)
            cout << x <<" ";
    }
    fin.close();
    return 0;
}*/


/*int main()
{
    ifstream fin("atestat.in");
    if (!fin)
        cout << "fisierul nu exista";
    int n, x, i, a, nr;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        nr = 0;
        while(x != 0)
        {
            a = x % 10;
            if(a % 2 == 0)
                nr++;
            x = x / 10;
        }
        cout << nr << " ";
    }
    return 0;
}*/



/*int main()
{
    ifstream fin("atestat.in");
    if (!fin)
        cout << "fisierul nu exista";
    int n, x, i;
    fin >> n;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        if(x < 10)
            cout << 0 << " ";
        else
            cout << (x%100)/10 << " ";
    }
    fin.close();
    return 0;
}*/



/*int main()
{
    ifstream fin("atestat.in");
    if (!fin)
        cout << "fisierul nu exista";
    int n, x, i, nr;
    fin >> n;
    fin >> nr;
    for(i = 1; i < n; i++)
    {
        fin >> x;
        if(x < nr)
            nr = x;
    }
    cout << nr;
    fin.close();
    return 0;
}*/



/*int main()
{
    ifstream fin("atestat.in");
    ofstream fout("atestat.out");
    if (!fin)
        cout << "fisierul nu exista";
    int n, x, i, r, a;
    fin >> n;
    a = 2;
    for(i = 0; i < n; i++)
    {
        fin >> x;
        if(100 <= x && x <= 999)
        {
            a = 0;
            for(r = 2; r <= x/2; r++)
            {
                if(x / r == 0)
                {
                    a = 1;
                    break;
                }
            }
        if (a == 0)
            fout << x << " ";
        }
    }
        if(a == 2)
            fout << "NU EXISTA NUMERE PRIME DE TREI CIFRE";
    fin.close();
    fout.close();
    return 0;
}*/
