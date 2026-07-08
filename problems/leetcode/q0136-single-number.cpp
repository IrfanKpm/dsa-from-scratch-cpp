#include <vector>

using namespace std;

/*
    PROBLEM: 136. Single Number

    GIVEN:
    - An integer array nums.

    CONDITIONS:

        • Every element appears exactly twice.

        • Only one element appears once.

    RETURN:
    - The element that appears only once.

    -------------------------------------------------
    KEY IDEA: XOR CANCELLATION
    -------------------------------------------------

    The XOR operator (^) has two important
    properties.

    1.

        x ^ x = 0

        A number XOR itself becomes zero.

    Example:

        5 ^ 5 = 0

    ---------------------------------------------

    2.

        x ^ 0 = x

        XOR with zero does not change the value.

    Example:

        7 ^ 0 = 7

    ---------------------------------------------

    XOR is also

        • Commutative

            a ^ b = b ^ a

        • Associative

            (a ^ b) ^ c = a ^ (b ^ c)

    Therefore, the order of XOR operations
    does not matter.

    -------------------------------------------------
    KEY OBSERVATION
    -------------------------------------------------

    Since every duplicated number appears twice,

        x ^ x = 0

    every pair cancels itself.

    Only the unique number remains.

    Example:

        4 1 2 1 2

    XOR all numbers:

        4 ^ 1 ^ 2 ^ 1 ^ 2

    Rearranging:

        (1 ^ 1)
        ^
        (2 ^ 2)
        ^
        4

    becomes

        0 ^ 0 ^ 4

    Result:

        4

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Initialize

        answer = 0

    Traverse every number.

    Continuously XOR it with answer.

        answer ^= number

    After processing the entire array,
    answer contains the unique element.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        nums = [2,2,1]

    Initial:

        answer = 0

    answer ^= 2

        0 ^ 2 = 2

    answer ^= 2

        2 ^ 2 = 0

    answer ^= 1

        0 ^ 1 = 1

    Result:

        1

    -------------------------------------------------

    Input:

        nums = [4,1,2,1,2]

    answer = 0

    ^= 4

        4

    ^= 1

        5

    ^= 2

        7

    ^= 1

        6

    ^= 2

        4

    Result:

        4

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every duplicated element appears exactly twice.

    XORing a pair removes it completely.

    Since XOR is associative and commutative,
    all duplicate pairs cancel regardless of
    their positions.

    The only remaining value is the element
    that appeared exactly once.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Single element

        nums = [7]

        Result:

            7

    2. Unique element at beginning

        nums = [5,2,2]

        Result:

            5

    3. Unique element at end

        nums = [8,3,3]

        Result:

            8

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Bit Manipulation
        XOR

    Recognition Hint:

        Whenever every element appears twice
        except one, think of XOR first.

    Key Learnings:

        • x ^ x = 0

        • x ^ 0 = x

        • XOR is associative.

        • XOR is commutative.

    Similar Problems:

        - 191. Number of 1 Bits
        - 268. Missing Number
        - 1486. XOR Operation in an Array
        - 260. Single Number III
        - 137. Single Number II

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = nums.size()

    Time:

        O(n)

    Space:

        O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int unique = 0;

        for (int num : nums) {
            unique ^= num;
        }

        return unique;
    }
};
