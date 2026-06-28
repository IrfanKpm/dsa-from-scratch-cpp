#include <cstdint>

using namespace std;

/*
    PROBLEM: 231. Power of Two

    GIVEN:
    - An integer n.

    RETURN:
    - true  -> if n is a power of two.
    - false -> otherwise.

    A number is a power of two if it can be written
    as:

        2^0 = 1
        2^1 = 2
        2^2 = 4
        2^3 = 8
        2^4 = 16
        ...

    -------------------------------------------------
    KEY IDEA: BIT MANIPULATION
    -------------------------------------------------

    Binary representation of powers of two:

        1   = 0001
        2   = 0010
        4   = 0100
        8   = 1000
        16  = 10000

    Observation:

        Every power of two contains exactly ONE
        set bit (1-bit).

    -------------------------------------------------
    IMPORTANT BIT PROPERTY
    -------------------------------------------------

    For any positive power of two:

        n & (n - 1)

    always equals

        0

    Why?

    Example:

        n = 8

        Binary:

            1000

        n - 1

            0111

        AND

            1000
          & 0111
          --------
            0000

    -------------------------------------------------

    Another example:

        n = 16

            10000

        n - 1

            01111

        AND

            00000

    -------------------------------------------------

    Non-power of two:

        n = 12

            1100

        n - 1

            1011

        AND

            1000

        Not zero

    Therefore,

        (n & (n - 1)) == 0

    is true only when n contains exactly one
    set bit.

    -------------------------------------------------
    WHY CHECK n > 0 ?
    -------------------------------------------------

    Zero is NOT a power of two.

        0 & (-1)

    also equals

        0

    which would incorrectly return true.

    Therefore we first ensure

        n > 0

    before applying the bit trick.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Step 1:

        If n <= 0

            return false.

    Step 2:

        Compute

            n & (n - 1)

    Step 3:

        If the result is zero

            return true

        otherwise

            return false.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        n = 32

    Binary:

        100000

    n - 1

        011111

    AND

        000000

    Result:

        true

    -------------------------------------------------

    Input:

        n = 18

    Binary:

        10010

    n - 1

        10001

    AND

        10000

    Not zero.

    Result:

        false

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    A power of two has exactly one bit set.

    Subtracting one flips:

        • the only set bit to 0
        • every lower bit to 1

    Performing AND removes every bit, producing 0.

    Numbers containing two or more set bits always
    leave at least one bit after the AND operation.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. n = 1

        2^0

        Result:

            true

    2. n = 0

        Result:

            false

    3. Negative number

        n = -8

        Result:

            false

    4. Large power of two

        n = 1073741824

        Result:

            true

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Bit Manipulation

    Recognition Hint:

        Whenever a problem asks whether a number
        contains exactly one set bit, remember

            n & (n - 1)

    Key Learning:

        The expression

            n & (n - 1)

        removes the rightmost set bit.

        If nothing remains, there was only one
        set bit to begin with.

    Similar Problems:

        - 191. Number of 1 Bits
        - 338. Counting Bits
        - 342. Power of Four
        - 461. Hamming Distance

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Time:

        O(1)

    Space:

        O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {

        return n > 0 && (n & (n - 1)) == 0;
    }
};
