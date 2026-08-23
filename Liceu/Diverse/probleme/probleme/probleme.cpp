#include <fstream>
#include <iostream>
using namespace std;

int main()
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
}
