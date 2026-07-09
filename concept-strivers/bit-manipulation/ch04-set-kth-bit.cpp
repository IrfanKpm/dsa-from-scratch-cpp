#include <iostream>
#include <bitset>
using namespace std;

// Topics-2 : Set the Kth Bit

int main(){

    cout << "\nTopics-2 : Set the Kth Bit\n" << endl;

    // Number = 9
    // 9 in binary  -> ( index 3-2-1-0 )
    //                 ( value 1-0-0-1 )

    int n = 9;
    int k = 1;

    cout << "Original Number : " << n << endl;
    cout << "Original Binary : " << bitset<8>(n) << endl;

    cout << "\nMasks\n";
    cout << "1<<0 --> " << bitset<8>(1 << 0) << endl;
    cout << "1<<1 --> " << bitset<8>(1 << 1) << endl;
    cout << "1<<2 --> " << bitset<8>(1 << 2) << endl;
    cout << "1<<3 --> " << bitset<8>(1 << 3) << endl;

    cout << "\nSet " << k << "th bit\n";

    // Method-1 : Using OR
    int ans = n | (1 << k);

    cout << "Before : " << bitset<8>(n) << endl;
    cout << "Mask   : " << bitset<8>(1 << k) << endl;
    cout << "After  : " << bitset<8>(ans) << endl;

    cout << "\nDecimal Answer : " << ans << endl;

    return 0;
}