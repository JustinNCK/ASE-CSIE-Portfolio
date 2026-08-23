#include <bits/stdc++.h>

void check_if_stop(int n, int limit, int s) {       // You can edit this line!
    if (n == limit) {                               // You can edit this line!
        s = 0;                                      // You can edit this line!
    }                                               // You can edit this line!
}                                                   // You can edit this line!

int main() {                                        // You can NOT edit this
    int n, s, limit;                                // You can NOT edit this
    n = 0;                                          // You can NOT edit this
    s = 1;                                          // You can NOT edit this
    std::cin >> limit;                              // You can NOT edit this
    while (s)                                       // You can NOT edit this
    {                                               // You can NOT edit this
		std::cout << n << "\n";	                    // You can NOT edit this
        n += 2;                                     // You can NOT edit this
        check_if_stop(n, limit, s);                 // You can NOT edit this
    }                                               // You can NOT edit this
    return 0;                                       // You can NOT edit this
}                                                   // You can NOT edit this
