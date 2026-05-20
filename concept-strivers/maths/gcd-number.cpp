#include <bits/stdc++.h>
using namespace std;

// non recursive
long long gcd_iter(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    // when b becomes 0, a is the GCD
    return a;
}

// recursive GCD
long long gcd_rec(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd_rec(b, a % b);
}

int main() {
    long long a, b;
    cin >> a >> b;

    cout << "Iterative GCD: " << gcd_iter(a, b) << endl;
    cout << "Recursive GCD: " << gcd_rec(a, b) << endl;
    return 0;
}