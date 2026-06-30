#include <cmath>
using namespace std;

/*
    PROBLEM: 507. Perfect Number

    GIVEN:
    - A positive integer num.

    RETURN:
    - true  -> if num is a Perfect Number.
    - false -> otherwise.

    A Perfect Number is a positive integer whose
    sum of all its positive divisors, excluding
    itself, equals the number.

    Examples:

        6

        Divisors:

            1, 2, 3

        Sum:

            1 + 2 + 3 = 6

        Perfect Number ✓

    -------------------------------------------------
                APPROACH 1 : BRUTE FORCE
    -------------------------------------------------

    KEY IDEA

    Check every integer from

        1

    to

        num - 1

    If a number divides num exactly,
    it is a divisor.

    Add every divisor to the sum.

    Finally compare the sum with num.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        num = 28

    Divisors found:

        1
        2
        4
        7
        14

    Sum:

        1+2+4+7+14 = 28

    Result:

        true

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Time:

        O(n)

    Space:

        O(1)

    =================================================
            APPROACH 2 : DIVISOR PAIR OPTIMIZATION
    =================================================

    KEY OBSERVATION

    Divisors always occur in pairs.

    Example:

        num = 36

        1 × 36

        2 × 18

        3 × 12

        4 × 9

        6 × 6

    Instead of checking every integer up to num,
    we only need to search up to

        √num

    Whenever we find one divisor,

        i

    we immediately know another divisor:

        num / i

    Thus one iteration discovers two divisors.

    -------------------------------------------------
    WHY START sum = 1 ?
    -------------------------------------------------

    Every number greater than 1 always has

        1

    as a proper divisor.

    So we initialize

        sum = 1

    before the loop.

    -------------------------------------------------
    WHY START LOOP FROM 2 ?
    -------------------------------------------------

    Since 1 has already been counted,
    we begin checking from

        2

    -------------------------------------------------
    WHY CHECK

        i != num / i

    ?
    -------------------------------------------------

    Perfect squares have one repeated divisor.

    Example:

        36

        Pair:

            6 × 6

    We should add

        6

    only once.

    Therefore

        if (i != num / i)

    prevents double counting.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        num = 28

    Initial:

        sum = 1

    i = 2

        28 % 2 == 0

        Add

            2

        and

            14

        sum = 17

    i = 3

        Not divisible

    i = 4

        Add

            4

        and

            7

        sum = 28

    Loop ends.

    Compare:

        sum == num

    Result:

        true

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every divisor smaller than √num has exactly
    one matching divisor greater than √num.

    By discovering both together, we avoid
    checking unnecessary numbers.

    This reduces the search space from

        n

    to

        √n

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. num = 1

        Not a perfect number.

        Result:

            false

    2. num = 6

        Divisors:

            1,2,3

        Sum:

            6

        Result:

            true

    3. num = 16

        Divisors:

            1,2,4,8

        Sum:

            15

        Result:

            false

    4. Perfect square

        num = 36

        Divisor

            6

        counted only once.

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Mathematics
        Divisor Enumeration

    Recognition Hint:

        Whenever a problem asks to find all
        divisors of a number, remember that
        divisors always come in pairs.

    Key Learnings:

        • Divisors exist as pairs.

        • Only iterate until √n.

        • Handle perfect squares carefully to
          avoid counting the square root twice.

    Similar Problems:

        - 367. Valid Perfect Square
        - 2427. Number of Common Factors
        - 2520. Count the Digits That Divide a Number

    =================================================
              COMPLEXITY COMPARISON
    =================================================

    Approach 1

        Time : O(n)

        Space: O(1)

    -------------------------------------------------

    Approach 2

        Time : O(√n)

        Space: O(1)

    The second approach is the expected interview
    solution because it uses the divisor-pair
    observation.
*/


/*---------------------------------------------------
| Approach 1 : Brute Force
---------------------------------------------------*/

class SolutionBruteForce {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;
        int sum = 0;
        for (int i = 1; i < num; i++) {
            if (num % i == 0)
                sum += i;
        }
        return sum == num;
    }
};


/*---------------------------------------------------
| Approach 2 : Divisor Pair Optimization
---------------------------------------------------*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;
        int sum = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i)
                    sum += num / i;
            }
        }
        return sum == num;
    }
};
