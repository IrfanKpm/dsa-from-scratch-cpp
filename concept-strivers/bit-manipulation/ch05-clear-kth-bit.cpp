#include <iostream>
#include <bitset>
using namespace std;

// Topic-3 : Clear the Kth Bit

int main() {

    cout << "\nTopic-3 : Clear the Kth Bit\n" << endl;

    // Number = 13
    // 13 in binary -> (index 3-2-1-0)
    //                 (value 1-1-0-1)

    int n = 13;
    int k = 2;

    cout << "Original Number : " << n << endl;
    cout << "Original Binary : " << bitset<8>(n) << endl;

    cout << "\nMasks\n";
    cout << "1 << 0 --> " << bitset<8>(1 << 0) << endl;
    cout << "1 << 1 --> " << bitset<8>(1 << 1) << endl;
    cout << "1 << 2 --> " << bitset<8>(1 << 2) << endl;
    cout << "1 << 3 --> " << bitset<8>(1 << 3) << endl;

    cout << "\nClear " << k << "th bit\n";

    // Method-1 : Using AND with an inverted mask
    int ans = n & ~(1 << k);

    cout << "Before : " << bitset<8>(n) << endl;
    cout << "Mask   : " << bitset<8>(~(1 << k)) << endl;
    cout << "After  : " << bitset<8>(ans) << endl;

    cout << "\nDecimal Answer : " << ans << endl;

    return 0;
}