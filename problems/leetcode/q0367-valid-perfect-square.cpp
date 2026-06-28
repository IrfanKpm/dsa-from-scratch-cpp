#include <cmath>

using namespace std;

/*
    PROBLEM: 367. Valid Perfect Square

    GIVEN:
    - A positive integer num.

    RETURN:
    - true  -> if num is a perfect square.
    - false -> otherwise.

    A perfect square is a number that can be
    written as:

        x * x

    for some integer x.

    Examples:

        1  = 1 × 1
        4  = 2 × 2
        9  = 3 × 3
        16 = 4 × 4

    -------------------------------------------------
    APPROACH 1 : BRUTE FORCE
    -------------------------------------------------

    KEY IDEA

    Try every possible integer starting from 1.

    For each number:

        square = i * i

    If

        square == num

        we found the square root.

    If

        square > num

        no larger value can produce num.

    -------------------------------------------------
    ALGORITHM
    -------------------------------------------------

    Start with

        i = 1

    Continue while

        i * i <= num

    If

        i * i == num

        return true.

    Otherwise continue checking.

    If the loop finishes,

        return false.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        num = 16

    i = 1

        1 * 1 = 1

    i = 2

        2 * 2 = 4

    i = 3

        3 * 3 = 9

    i = 4

        4 * 4 = 16

    Match found.

    Result:

        true

    -------------------------------------------------

    Input:

        num = 14

    Squares checked:

        1
        4
        9

    Next:

        4 * 4 = 16

        Loop stops.

    Result:

        false

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every perfect square has an integer square root.

    By checking every possible integer whose square
    does not exceed num, we eventually find the
    square root if it exists.

    If none matches, num cannot be a perfect square.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Smallest perfect square

        num = 1

        Result:

            true

    2. Non-perfect square

        num = 2

        Result:

            false

    3. Large perfect square

        num = 2147395600

        Result:

            true

    -------------------------------------------------
    NOTE ABOUT long long
    -------------------------------------------------

    We use

        long long

    for variable i because

        i * i

    may overflow an int when num is large.

    Example:

        50000 * 50000

    exceeds the maximum value of a 32-bit integer.

    Using long long prevents integer overflow.

    -------------------------------------------------
    BETTER APPROACH
    -------------------------------------------------

    This brute-force solution is correct, but
    it checks every integer from 1 up to √num.

    Since the search space is sorted, we can use
    Binary Search instead.

    Binary Search:

        Time : O(log n)

        Space: O(1)

    Binary Search is the expected interview
    solution for this problem.

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Mathematical Search

    Recognition Hint:

        If you're searching for an integer answer
        within a sorted numeric range, Binary Search
        is often applicable.

    Key Learning:

        Brute force is simple and correct, but
        recognizing that square values increase
        monotonically allows optimization using
        Binary Search.

    Similar Problems:

        - 69. Sqrt(x)
        - 374. Guess Number Higher or Lower
        - Binary Search on Answer problems

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let

        k = √num

    Time:

        O(√num)

    Space:

        O(1)
*/

class Solution {
public:
    bool isPerfectSquare(int num) {

        for (long long i = 1; i * i <= num; i++) {

            if (i * i == num)
                return true;
        }

        return false;
    }
};
