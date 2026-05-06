#include <iostream>
using namespace std;

/*
    PROBLEM: Check if a number is a palindrome (LeetCode 9)

    IDEA:
    Instead of reversing full number (risk overflow),
    we reverse ONLY half of the number.

    WHY HALF REVERSAL WORKS:
    - We split number into two parts:
        left half (x)
        right half (rev)
    - For even digits: both halves match directly
    - For odd digits: middle digit is ignored (rev / 10)

    -----------------------------------------
    WHY "x > rev" CONDITION?
    -----------------------------------------
    We stop reversing when:
        x <= rev

    Meaning:
    - We have processed at least half digits
    - Prevents full reversal
    - Avoids unnecessary computation

    Example (1221):
        x = 12, rev = 12 → stop

    Example (12321):
        x = 12, rev = 123 → stop (middle digit included)

    -----------------------------------------
    WHY NOT "while(x != 0)"?
    -----------------------------------------
    That would:
    - reverse FULL number
    - use extra space/time
    - risk overflow
    - unnecessary work (O(n) full reversal)

    We only need HALF → O(log10 n)

    -----------------------------------------
    EVEN vs ODD CASE
    -----------------------------------------

    EVEN digits example: 1221
        x = 12, rev = 12
        → x == rev

    ODD digits example: 12321
        x = 12, rev = 123
        remove middle digit → rev/10 = 12
        → x == rev/10

    -----------------------------------------
    COMPLEXITY
    -----------------------------------------
    Time Complexity  : O(log10 n)
    Space Complexity : O(1)

    Reason:
    - We process digits one by one
    - Number of digits = log10(n)
*/

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int rev = 0;

    while (x > rev) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }

    return (x == rev || x == rev / 10);
}

int main() {
    int x;
    cin >> x;

    cout << (isPalindrome(x) ? "true" : "false");
    return 0;
}