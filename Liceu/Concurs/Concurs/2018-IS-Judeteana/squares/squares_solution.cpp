#include <iostream>
#include <cmath>

using namespace std;

// This program should print all the perfect squares that are less than or equal
// to n, in descending order. However, the program does not properly stop and
// starts printing very large numbers. What could be the cause?
// 
// Hint: you can make the program work with only one changed line.
int main() {
    int n, root;

    cin >> n;

    // 0 is also a perfect square, so we need to check it
    while (n >= 0) {
        // take the integer part of the square root of n
        root = sqrt(n); 

        // if n is a perfect square, print it
        if (n == root * root) {
            cout << n << " ";
        }

        n--;
    }

    return 0;
}
