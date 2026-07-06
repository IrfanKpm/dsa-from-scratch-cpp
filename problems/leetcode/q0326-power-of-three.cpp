#include <cmath>

using namespace std;

/*
    PROBLEM: 326. Power of Three

    GIVEN:
    - An integer n.

    RETURN:
    - true  -> if n is a power of three.
    - false -> otherwise.

    A power of three can be written as:

        3^0 = 1
        3^1 = 3
        3^2 = 9
        3^3 = 27
        3^4 = 81
        ...

    -------------------------------------------------
                APPROACH 1 : ITERATIVE DIVISION
    -------------------------------------------------

    KEY IDEA

    Every power of three can be repeatedly
    divided by 3 until it becomes 1.

    Example:

        81

        81 / 3 = 27

        27 / 3 = 9

         9 / 3 = 3

         3 / 3 = 1

    Since we reached 1,

        81

    is a power of three.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    1. Negative numbers and zero can never be
       powers of three.

    2. While n is divisible by 3,

            n /= 3

    3. If the final value is 1,

            return true.

       Otherwise,

            return false.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        n = 27

    27 % 3 == 0

        n = 9

    9 % 3 == 0

        n = 3

    3 % 3 == 0

        n = 1

    Result:

        true

    -------------------------------------------------

    Input:

        n = 45

    45 % 3 == 0

        n = 15

    15 % 3 == 0

        n = 5

    5 % 3 != 0

    Result:

        false

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    A power of three contains only factors of 3.

    Repeatedly removing the factor 3 should
    eventually leave exactly

        1

    If any other prime factor exists,
    the process stops before reaching 1.

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Time:

        O(log₃ n)

    Space:

        O(1)

    =================================================
             APPROACH 2 : MATHEMATICAL TRICK
    =================================================

    KEY OBSERVATION

    The largest power of three that fits inside
    a signed 32-bit integer is

        3^19 = 1162261467

    Since

        1162261467

    contains only factors of 3,

    every smaller power of three divides it
    exactly.

    Therefore,

        if

            1162261467 % n == 0

        then

            n

        must also be a power of three.

    -------------------------------------------------
    WHY DOES THIS WORK?
    -------------------------------------------------

    Prime factorization:

        1162261467

        = 3^19

    Any divisor of

        3^19

    must be

        3^0
        3^1
        3^2
        ...
        3^19

    No other number divides it evenly.

    Example:

        n = 27

        1162261467 % 27 == 0

        true

    Example:

        n = 45

        1162261467 % 45 != 0

        false

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    If

        n > 0

    and

        1162261467 % n == 0

    return true.

    Otherwise,

    return false.

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Mathematics
        Repeated Division

    Recognition Hint:

        Whenever asked whether a number is a
        power of some base,

            repeatedly divide

        or

            use mathematical properties of the
            largest possible power.

    Key Learnings:

        • Repeated division removes one factor
          at a time.

        • The largest power trick works only
          because 3 is prime.

        • This trick is valid only when the
          integer size (32-bit) is fixed.

    Similar Problems:

        - 231. Power of Two
        - 342. Power of Four
        - 326. Power of Three

    =================================================
            COMPLEXITY COMPARISON
    =================================================

    Approach 1

        Time : O(log₃ n)

        Space: O(1)

    -------------------------------------------------

    Approach 2

        Time : O(1)

        Space: O(1)
*/


/*---------------------------------------------------
| Approach 1 : Repeated Division
---------------------------------------------------*/

class SolutionDivision {
public:
    bool isPowerOfThree(int n) {

        if (n <= 0)
            return false;

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};


/*---------------------------------------------------
| Approach 2 : Largest Power Trick (O(1))
---------------------------------------------------*/

class Solution {
public:
    bool isPowerOfThree(int n) {

        return n > 0 &&
               1162261467 % n == 0;
    }
};
