#include <cstdint>

using namespace std;

/*
    PROBLEM: 342. Power of Four

    GIVEN:
    - An integer n.

    RETURN:
    - true  -> if n is a power of four.
    - false -> otherwise.

    A power of four can be written as:

        4^0 = 1
        4^1 = 4
        4^2 = 16
        4^3 = 64
        4^4 = 256
        ...

    -------------------------------------------------
    KEY IDEA
    -------------------------------------------------

    Every power of four is also a power of two.

    Therefore, we first verify that n contains
    exactly one set bit.

    Then, we verify that this set bit is located
    in the correct position.

    -------------------------------------------------
    STEP 1 : CHECK POWER OF TWO
    -------------------------------------------------

    A power of two contains exactly one set bit.

    Binary examples:

        1   = 00000001
        2   = 00000010
        4   = 00000100
        8   = 00001000
        16  = 00010000

    The expression

        n & (n - 1)

    removes the rightmost set bit.

    Therefore,

        n & (n - 1) == 0

    means n has exactly one set bit.

    -------------------------------------------------
    STEP 2 : CHECK THE BIT POSITION
    -------------------------------------------------

    Powers of four have their only set bit in
    EVEN bit positions (0-indexed).

    Examples:

        Decimal     Binary

        1           00000001   ← bit 0

        4           00000100   ← bit 2

        16          00010000   ← bit 4

        64          01000000   ← bit 6

    Notice the pattern:

        bit positions

        6 5 4 3 2 1 0

        1 0 1 0 1 0 1

    This pattern is represented by the mask

        0x55555555

    Binary:

        01010101010101010101010101010101

    The mask contains 1's only in the valid
    positions for powers of four.

    Therefore,

        n & 0x55555555

    is non-zero only if the set bit lies in one
    of these positions.

    -------------------------------------------------
    WHY BOTH CONDITIONS ARE NEEDED
    -------------------------------------------------

    Example:

        n = 8

        Binary:

            00001000

    It IS a power of two.

    However,

        8 = 2³

    not

        4^k

    because its set bit is at bit position 3,
    which is odd.

    Mask check:

        00001000
    &   01010101
        --------
        00000000

    Therefore

        false

    -------------------------------------------------

    Example:

        n = 16

        Binary:

            00010000

    Power of two?

        Yes

    Mask check:

        00010000
    &   01010101
        --------
        00010000

    Non-zero.

    Therefore

        true

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Return true only if

        1. n > 0

        2. n has exactly one set bit

        3. That set bit is located in an even
           bit position.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        n = 64

    Binary:

        01000000

    Check:

        n > 0

            true

        n & (n - 1)

            0

        n & 0x55555555

            non-zero

    Result:

        true

    -------------------------------------------------

    Input:

        n = 32

    Binary:

        00100000

    Power of two?

        Yes

    Mask check:

        0

    Result:

        false

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every power of four satisfies BOTH properties:

        • Exactly one set bit.

        • That bit appears only in an even
          position.

    Combining both checks uniquely identifies
    powers of four.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. n = 1

        4⁰

        Result:

            true

    2. n = 4

        Result:

            true

    3. n = 8

        Power of two but not power of four.

        Result:

            false

    4. n = 0

        Result:

            false

    5. Negative number

        Result:

            false

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Bit Manipulation

    Recognition Hint:

        When a problem asks whether a number
        belongs to a special power sequence,
        examine the binary representation.

    Key Learnings:

        • Power of two:
              n & (n - 1) == 0

        • Power of four:
              Power of two
              +
              Set bit in an even position

        • 0x55555555 is a bit mask that keeps
          only even bit positions.

    Similar Problems:

        - 231. Power of Two
        - 191. Number of 1 Bits
        - 338. Counting Bits
        - 190. Reverse Bits

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
    bool isPowerOfFour(int n) {

        return n > 0 &&
               (n & (n - 1)) == 0 &&
               (n & 0x55555555) != 0;
    }
};
