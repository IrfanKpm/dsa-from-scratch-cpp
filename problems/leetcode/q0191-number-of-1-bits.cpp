#include <cstdint>

using namespace std;

/*
    PROBLEM: 191. Number of 1 Bits

    GIVEN:
    - A positive integer n.

    RETURN:
    - The number of bits set to 1 in the binary
      representation of n.

    This count is also known as the:

        Hamming Weight
        Population Count (Popcount)

    -------------------------------------------------
    APPROACH 1 : DIVISION BY 2
    -------------------------------------------------

    KEY IDEA

    Every integer can be converted into binary by
    repeatedly dividing it by 2.

    At each step:

        n % 2

    gives the least significant bit (LSB).

        0 -> current bit is 0
        1 -> current bit is 1

    If the remainder is 1, increment the count.

    Then remove the processed bit by dividing
    the number by 2.

    -------------------------------------------------
    ALGORITHM
    -------------------------------------------------

    Initialize:

        count = 0

    While n > 0

        If

            n % 2 == 1

            count++

        Divide

            n = n / 2

    Return count.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        n = 11

    Binary:

        1011

    Processing:

        n = 11

        11 % 2 = 1

        count = 1

        n = 5

        ----------------

        5 % 2 = 1

        count = 2

        n = 2

        ----------------

        2 % 2 = 0

        count = 2

        n = 1

        ----------------

        1 % 2 = 1

        count = 3

        n = 0

    Result:

        3

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every division removes the least significant
    binary digit.

    Before removing it,

        n % 2

    tells whether that bit is 0 or 1.

    By examining every bit exactly once,
    we count all set bits.

    -------------------------------------------------
    IMPORTANT NOTE
    -------------------------------------------------

    Your solution works for positive integers.

    However, on LeetCode the parameter is usually

        uint32_t n

    (an unsigned 32-bit integer).

    Using

        while (n >= 1)

    with a signed integer may produce incorrect
    behavior for negative values.

    A more common implementation is

        while (n > 0)

    using an unsigned integer.

    -------------------------------------------------
    BETTER APPROACH
    -------------------------------------------------

    A well-known optimization is
    Brian Kernighan's Algorithm.

    Observation:

        n & (n - 1)

    removes the rightmost set bit.

    Example:

        101100

        n-1

        101011

        AND

        101000

    Each iteration removes exactly one 1-bit.

    Complexity:

        O(number of set bits)

    instead of

        O(number of total bits)

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Bit Manipulation

    Recognition Hint:

        Whenever a problem asks about binary
        representation, think about bitwise
        operators before using arithmetic.

    Key Learning:

        Division and modulus can inspect binary
        bits, but bitwise operators are usually
        faster and cleaner.

    Similar Problems:

        - 338. Counting Bits
        - 461. Hamming Distance
        - 231. Power of Two
        - 190. Reverse Bits

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let b be the number of bits in n.

    Time:

        O(b)

    Space:

        O(1)
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n >= 1) {
            if (n % 2 == 1) {
                count++;
            }
            n = n / 2;
        }
        return count;
    }
};
