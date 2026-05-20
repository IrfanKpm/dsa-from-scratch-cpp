#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cout << "enter-number : ";
    cin >> n;

    vector<long long> small, large;
    for (long long i = 1; i * i <= n; i++) {
        // NOTE 1:
        // i * i <= n  is same as  i <= sqrt(n)
        // because squaring both sides gives i^2 <= n
        if (n % i == 0) {
            small.push_back(i);
            long long q = n / i;
            if (q != i) {
                large.push_back(q);
            }
            // NOTE 2:
            // For every divisor pair (p, q) such that p * q = n,
            // one of them MUST be <= sqrt(n) and the other >= sqrt(n)
            // so here i acts as p (small side), and q = n/i is the paired divisor
        }
    }
    // print divisors in sorted order
    for (long long x : small) cout << x << " ";
    for (int i = large.size() - 1; i >= 0; i--) cout << large[i] << " ";

    cout << endl;
    return 0;
}