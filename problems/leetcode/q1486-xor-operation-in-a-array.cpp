#include <vector>

using namespace std;

/*
    PROBLEM: 1486. XOR Operation in an Array

    GIVEN:
    - Two integers:
          n
          start

    Build an array where:

        nums[i] = start + 2 * i

    for

        0 <= i < n

    RETURN:
    - XOR of all elements in the array.

    =================================================
                APPROACH 1 : SIMULATION
    =================================================

    KEY IDEA

    Directly generate every element of the array and
    continuously XOR it with the answer.

    Since XOR is associative:

        a ^ b ^ c

    can be computed incrementally.

    -------------------------------------------------
    ALGORITHM
    -------------------------------------------------

    Initialize:

        ans = 0

    For every i

        value = start + 2 * i

        ans ^= value

    Return ans.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        n = 5
        start = 0

    Generated numbers:

        0
        2
        4
        6
        8

    Computation:

        ans = 0

        ans ^= 0 -> 0
        ans ^= 2 -> 2
        ans ^= 4 -> 6
        ans ^= 6 -> 0
        ans ^= 8 -> 8

    Result:

        8

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Time:

        O(n)

    Space:

        O(1)

    =================================================
          APPROACH 2 : MATHEMATICAL XOR (O(1))
    =================================================

    OBSERVATION

    Every number is

        start + 2*i

    Rewrite start as

        start = 2*a + b

    where

        a = start / 2
        b = start % 2

    Then

        start + 2*i

    becomes

        2(a+i) + b

    So instead of XORing

        start,
        start+2,
        start+4,
        ...

    we XOR

        a,
        a+1,
        a+2,
        ...

    and finally shift left by one bit.

    The only remaining part is the least
    significant bit.

    It contributes only when BOTH are true:

        start is odd

        AND

        n is odd

    -------------------------------------------------
    IMPORTANT XOR PROPERTY
    -------------------------------------------------

    XOR from

        0 ... x

    follows a repeating pattern every 4 numbers.

        x % 4 == 0

            x

        x % 4 == 1

            1

        x % 4 == 2

            x + 1

        x % 4 == 3

            0

    Therefore,

        XOR(l...r)

    equals

        XOR(0...r)

        ^

        XOR(0...l-1)

    Both values are computed in O(1).

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Multiplying by 2 simply shifts every bit
    one position to the left.

    Therefore,

        XOR of

            2x

    is simply

        (XOR of x) << 1

    The least significant bit behaves separately,
    producing the final adjustment.

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Bit Manipulation

    Key Learnings:

        • XOR is associative.

        • XOR from 0...n has a fixed repeating
          pattern every 4 values.

        • Many XOR problems can be optimized
          mathematically instead of simulation.

    Similar Problems:

        - 268. Missing Number
        - 136. Single Number
        - 1310. XOR Queries of a Subarray
        - 1734. Decode XORed Permutation

    =================================================
                COMPLEXITY COMPARISON
    =================================================

    Simulation

        Time : O(n)
        Space: O(1)

    Mathematical

        Time : O(1)
        Space: O(1)
*/


/*---------------------------------------------------
| Approach 1 : Simulation
---------------------------------------------------*/

class Solution {
public:
    int xorOperation(int n, int start) {

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans ^= (start + 2 * i);
        }

        return ans;
    }
};


/*---------------------------------------------------
| Approach 2 : Mathematical O(1)
---------------------------------------------------*/

class SolutionOptimal {
public:

    // XOR from 0 ... x
    int prefixXor(int x) {

        switch (x & 3) {

            case 0: return x;
            case 1: return 1;
            case 2: return x + 1;
            default: return 0;
        }
    }

    int xorOperation(int n, int start) {

        int a = start >> 1;

        int ans =
            (prefixXor(a - 1) ^
             prefixXor(a + n - 1))
            << 1;

        if ((start & 1) && (n & 1))
            ans |= 1;

        return ans;
    }
};
