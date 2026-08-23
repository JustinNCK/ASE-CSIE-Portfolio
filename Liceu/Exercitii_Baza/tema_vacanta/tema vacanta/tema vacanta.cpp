#include <iostream>
using namespace std;

//probleme de pe pbinfo
//#633
/*int main()
{
    int v[50];
    int n, i, nri, nrp;
    cin >> n;
    nri = 0;
    nrp = 0;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
            nrp++;
        else
            nri++;
    }
    if (nri > nrp)
        cout << nri - nrp;
    else
        cout << nrp - nri;
    return 0;
}*/



//#546
/*int main()
{
    int v[50];
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] % v[n - 1] == 0)
            cout << v[i] << " ";
    }
    return 0;
}*/



//#488
/*int main()
{
    int v[50];
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    for (i = 1; i < n; i = i + 2)
    {
        if (i % 2 == 1)
            cout << v[i] << " ";
    }
    cout << endl;
    for (i = n - 1; i >= 0; i--)
    {
        if(i % 2 == 0)
            cout << v[i] << " ";
    }
    return 0;
}*/




//#547
/*int main()
{
    int v[50];
    int n, i, m, M, nr;
    cin >> n;
    nr = 0;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    m = v[0];
    M = v[0];
    for (i = 0; i < n; i++)
    {
        if (v[i] > M)
            M = v[i];
        if (v[i] < m)
            m = v[i];
    }
    for (i = 0; i < n; i = i++)
    {
        if (M - m == v[i])
            nr++;
    }
    cout << nr;
    return 0;
}*/



//#491
/*int main()
{
    int v[50];
    int n, i, nr1, nr2, s;
    cin >> n;
    s = 0;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            nr1 = i;
            i = n;
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (v[i] % 2 == 0)
        {
            nr2 = i;
            i = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i >= nr1 && i <= nr2)
            s = s + v[i];
    }
    cout << s;
    return 0;
}*/



//#487
/*int main()
{
    int v[50];
    int n, i, nr;
    float ma{};
    cin >> n;
    nr = 0;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
        ma = ma + v[i];
    }
    ma =  ma / n;
    for (i = 0; i < n; i++)
    {
        if (ma < v[i])
            nr++;
    }
    cout << nr;
    return 0;
}*/




//#492
/*int main()
{
    int v[50];
    int n, i, j, cont, nr;
    cin >> n;
    nr = 0;
    for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    for (i = 0; i <= n / 2; i++)
    {
        cont = 1;
        for (j = 2; j <= v[i] / 2; j++)
            if (v[i] % j == 0 && v[n - i - 1] % j == 0)
                cont = 0;
        if (cont == 1)
            nr++;
    }
    cout << nr;
    return 0;
}*/