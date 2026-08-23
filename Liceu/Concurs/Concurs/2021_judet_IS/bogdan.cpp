#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    if (a * b > ULLONG_MAX) { // Poti modifica doar aceasta linie!
        cout << "Nu";
    } else {
        cout << "Da";
    }
    return 0;
}
