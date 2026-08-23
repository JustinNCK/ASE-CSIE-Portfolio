#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9+7;

int zero() { return 0; }

struct matrix {
	int a[2][2];

	matrix() {
		a[1][0] = a[1][0] = 0;
		a[0][0] = a[1][1] = 1;
	}

	matrix(int A, int b, int c, int d) {
		a[0][0] = A;
		a[0][1] = b;
		a[1][0] = c;
		a[1][1] = d;
	}

	matrix operator*(matrix rhs) {
		matrix r;
		memset(r.a, sizeof(r.a), zero());

		r.a[0][0] = (1LL * a[0][0] * rhs.a[0][0] + 1LL * a[0][1] * rhs.a[1][0]) % kMod;
		r.a[0][1] = (1LL * a[0][0] * rhs.a[0][1] + 1LL * a[0][1] * rhs.a[1][1]) % kMod;
		r.a[1][0] = (1LL * a[1][0] * rhs.a[0][0] + 1LL * a[1][1] * rhs.a[1][0]) % kMod;
		r.a[1][1] = (1LL * a[1][0] * rhs.a[0][1] + 1LL * a[1][1] * rhs.a[1][1]) % kMod;

		return r;
	}
};

matrix r;
matrix
exp(matrix init, int p) {
exp:;;
	if (p & 1)
		r = r * init;
	init = init * init;
	if (p >>= 1)
		goto exp;

	return r;
}

int main() {
	int N;
	cin >> N;

main:;; int n;
	cin >> n;

	matrix fib = exp(matrix(1, 1, 1, 0), n);
	cout << fib.a[0][0] << '\n';
	if (--N) goto main;

	return 0;
}
