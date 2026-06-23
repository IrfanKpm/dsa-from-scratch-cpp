#include <iostream>
#include <climits>
using namespace std;

/*
    PROBLEM: Reverse Integer (LeetCode 7)

    TASK:
    Given a signed 32-bit integer x,
    return x with its digits reversed.

    If reversing x causes overflow (outside 32-bit range),
    return 0.

    -----------------------------------------
    32-BIT INTEGER RANGE:
    -----------------------------------------
    INT_MAX =  2147483647
    INT_MIN = -2147483648

    Any result outside this range is invalid.

    -----------------------------------------
    CORE IDEA:
    -----------------------------------------
    We extract digits from the end of the number
    using modulo (%) and build the reversed number step by step.

        digit = x % 10
        x = x / 10
        rev = rev * 10 + digit

    -----------------------------------------
    WHY OVERFLOW CHECK IS NEEDED:
    -----------------------------------------
    If we directly do:
        rev = rev * 10 + digit

    → rev may exceed 32-bit limit silently
    → causing incorrect results or undefined behavior

    So we check BEFORE updating rev.

    -----------------------------------------
    OVERFLOW LOGIC:
    -----------------------------------------

    For POSITIVE overflow:
        if rev > INT_MAX / 10
        OR (rev == INT_MAX / 10 AND digit > 7)

    For NEGATIVE overflow:
        if rev < INT_MIN / 10
        OR (rev == INT_MIN / 10 AND digit < -8)

    WHY 7 AND -8?
    Because:
        INT_MAX ends with 7
        INT_MIN ends with 8

    -----------------------------------------
    TIME COMPLEXITY:
    -----------------------------------------
    O(log10 n)
    (we process each digit once)

    SPACE COMPLEXITY:
    O(1)
*/

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // -------------------------
            // OVERFLOW CHECK (IMPORTANT)
            // -------------------------

            if (rev > INT_MAX / 10 ||
               (rev == INT_MAX / 10 && digit > 7))
                return 0;

            if (rev < INT_MIN / 10 ||
               (rev == INT_MIN / 10 && digit < -8))
                return 0;

            // build reversed number
            rev = rev * 10 + digit;
        }

        return rev;
    }
};

/*
    -----------------------------------------
    DRY RUN EXAMPLE: x = 123
    -----------------------------------------
    Step 1:
        digit = 3, x = 12, rev = 3

    Step 2:
        digit = 2, x = 1,  rev = 32

    Step 3:
        digit = 1, x = 0,  rev = 321

    Final answer: 321
*/