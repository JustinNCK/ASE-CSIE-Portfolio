#include <iostream>
#define maxN 0xb055

using namespace std;

int main() {
    int n, q, x, logN, v[maxN];
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (logN = 1; logN<=n; logN<<=1);
    while (q--) {
        cin >> x;
        int pos = 0;
        for (int step = logN; step; step>>=1) {
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
}

