#include <iostream>

#define MOD 1000000007

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int p = 1;

    for (int i = 1; i <= n; ++i) {
        p *= i;
        p %= MOD;
    }

    cout << p << "\n";

    return 0;
}
