#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "enter-number : ";
    cin >> n;

    int original = n;

    int digits = 0;
    int temp = n;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    int sum = 0;

    while (temp > 0) {
        int d = temp % 10;

        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= d;
        }

        sum += power;
        temp /= 10;
    }

    if (sum == original)
        cout << "Armstrong Number";
    else
        cout << "Not Armstrong Number";

    return 0;
}