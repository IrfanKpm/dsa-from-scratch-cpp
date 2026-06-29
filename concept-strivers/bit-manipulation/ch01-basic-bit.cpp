#include <iostream>
#include <bitset>
using namespace std;

int main() {

    // ============================================================
    // Chapter 01 : Bit Basics
    // ============================================================

    // A bit can store only two values:
    // 0 or 1

    // 1 Byte = 8 Bits

    // ------------------------------------------------------------
    // Decimal Numbers
    // ------------------------------------------------------------

    int decimal = 26;
    cout << "Decimal Value : " << decimal << endl;

    // ------------------------------------------------------------
    // Binary Literal in C++
    // Prefix : 0b
    // ------------------------------------------------------------

    int binary = 0b11010;
    cout << "Binary Literal Value : " << binary << endl;

    // ------------------------------------------------------------
    // Both numbers are exactly the same
    // ------------------------------------------------------------

    cout << "\nAre they equal? ";
    bool flag = (decimal == binary);
    cout << flag << endl;

    // ------------------------------------------------------------
    // Binary Representation
    // bitset<N> prints N bits
    // ------------------------------------------------------------

    cout << "\nBinary Representation" << endl;
    cout << "26 = " << bitset<8>(decimal) << endl;

    // ------------------------------------------------------------
    // Different Number Systems
    // ------------------------------------------------------------

    int dec = 26;       // Decimal
    int bin = 0b11010;  // Binary
    int oct = 032;      // Octal
    int hex = 0x1A;     // Hexadecimal

    cout << "\nDifferent Number Systems" << endl;

    cout << "Decimal     : " << dec << endl;
    cout << "Binary      : " << bin << endl;
    cout << "Octal       : " << oct << endl;
    cout << "Hexadecimal : " << hex << endl;

    // ------------------------------------------------------------
    // Memory Representation
    // Integers are stored as bits
    // ------------------------------------------------------------

    cout << "\n32-bit Representation of 26" << endl;
    cout << bitset<32>(26) << endl;

    // ------------------------------------------------------------
    // Signed and Unsigned Integer
    // ------------------------------------------------------------

    int signedNum = -26;
    unsigned int unsignedNum = 26;
    cout << "\nSigned Number   : " << signedNum << endl;
    cout << "Unsigned Number : " << unsignedNum << endl;

    // ------------------------------------------------------------
    // Small Practice
    // ------------------------------------------------------------

    cout << "\nPractice" << endl;
    cout << "5  -> " << bitset<8>(5) << endl;
    cout << "10 -> " << bitset<8>(10) << endl;
    cout << "15 -> " << bitset<8>(15) << endl;
    cout << "31 -> " << bitset<8>(31) << endl;

    return 0;
}