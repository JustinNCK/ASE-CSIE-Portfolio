#include <iostream>
using namespace std;

/*int main()
{
    int n, a, b, d;
    cin >> n;
    b = n;
    a = 0;
    for (d = 2; d <= n / 2; d++)
    {
        if (n % d == 0)
        {
            if (n / d - d < b && n / d >= d)
            {
                a = n / d;
                b = a - d;
            }
        }
    }
    cout << n / a << " " << a;
    return 0;
}*/




/*int main()
{
    int m, n, d, i, cmmdc;
    cin >> m >> n;
    if (n > m)
    {
        m = n + m;
        n = m - n;
        m = m - n;
    }
    for (i = 2; i <= m / 2; i++)
    {
        if (m % i == 0)
            if (n % i == 0)
                cmmdc = i;
    }
    cout << cmmdc;
    return 0;
}*/




/*int main()
{
    int n, m, cmmmc, i;
    cin >> m >> n;
    for (i = 1; i <= n; i++)
    {
        cmmmc = i * m;
        if (cmmmc % n == 0)
        {
            cout << cmmmc;
            i = n;
        }
    }
}*/




int main()
{
    int n, a, b, c;
    n = 123;
    a = (n % 10) * 100;
    b = (n / 10) % 10;
    c = n / 100;
    cout << a + b + c;
    return 0;
}



