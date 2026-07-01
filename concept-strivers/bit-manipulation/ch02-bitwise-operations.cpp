#include <iostream>
#include <bitset>
using namespace std;

int main(){
   
    int x1 = 1;
    int x2 = 13;
    int x3 = 26;

    bitset<8> b1(x1);
    bitset<8> b2(x2);
    bitset<8> b3(x3);

    cout << "x1 --> " << x1 << endl;
    cout << "x2 --> " << x2 << endl;
    cout << "x3 --> " << x3 << endl;
    cout << "b1 = x1-bit --> " << b1 << endl;
    cout << "b2 = x2-bit --> " << b2 << endl;
    cout << "b3 = x3-bit --> " << b3 << endl;

    cout << "\nAND(&) OPERATION" << endl;
    cout << "b2-bit  --> " << b2 << endl;
    cout << "b3-bit  --> " << b3 << endl;
    cout << "b2 & b3 --> " << (b2 & b3) << endl;

    cout << "\nOR(|) OPERATION" << endl;
    cout << "b2-bit  --> " << b2 << endl;
    cout << "b3-bit  --> " << b3 << endl;
    cout << "b2 | b3 --> " << (b2 | b3) << endl;

    cout << "\nXOR(^) OPERATION" << endl;
    cout << "3 in-bit   --> " << bitset<8>(3) << endl;
    cout << "0 in-bit   --> " << bitset<8>(0) << endl;
    cout << "3 ^ 0      --> " << bitset<8>(3 ^ 0) << endl; 
    cout << "3 ^ 1      --> " << bitset<8>(3 ^ 1) << endl; 
    cout << "3 ^ 3      --> " << bitset<8>(3 ^ 3) << endl; 

    cout << "\nNOT(~) OPERATION" << endl;
    int a = 13;
    cout << "a        -->  " << a << " (" << bitset<8>(a) << ")" << endl;
    cout << "~a       --> " << ~a << " (" << bitset<8>(~a) << ")" << endl;


    return 0;
}