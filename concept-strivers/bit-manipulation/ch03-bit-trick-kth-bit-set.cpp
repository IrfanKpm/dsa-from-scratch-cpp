#include <iostream>
#include <bitset>
using namespace std;

// Topics-1 : Check if the Kth Bit is Set

int main(){
   
    // Topics-1 : Check if the Kth Bit is Set
    cout << "\nTopics-1 : Check if the Kth Bit is Set\n" << endl; 

    // 13        -> ( index 3-2-1-0)
    // 13 in bit -> ( value 1-1-0-1)

    bitset<8> x1(1);
    cout << "1     --> " << x1 << endl;
    bitset<8> x2(1<<0);
    cout << "1<<0  --> " << x2 << endl;
    bitset<8> x3(1<<1);
    cout << "1<<1  --> " << x3 << endl;
    bitset<8> x4(1<<2);
    cout << "1<<2  --> " << x4 << endl;
    bitset<8> x5(1<<3);
    cout << "1<<3  --> " << x5 << endl;

    cout << "\ncheck 3th bit is set or not!"<<endl;
    cout << "3-in-bit  --> 00001101" << endl;

    // method-1
    if ((13 & (1 << 3)) != 0) {
       cout << "3th bit is set\n";
    } else {
       cout << "3th bit is not set\n";
    }

    //method-2
    if (((13 >> 3) & 1) != 0){
       cout << "3th bit is set\n";
    } else {
       cout << "3th bit is not set\n";
    }

    return 0;
}