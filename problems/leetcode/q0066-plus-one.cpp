#include <vector>
using namespace std;

/*
    PROBLEM: 66. Plus One

    GIVEN:
    - An integer represented as an array of digits.

    Example:

        [1,2,3]

    represents

        123

    RETURN:
    - The array after adding one to the number.

    -------------------------------------------------
    KEY IDEA
    -------------------------------------------------

    Addition always starts from the least
    significant digit (rightmost digit).

    While adding 1:

        • If the digit is less than 9,
          simply increment it.

        • If the digit is 9,
          it becomes 0 and generates a carry
          to the next digit.

    Therefore, we process the array from
    right to left.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Traverse the digits from the last index.

    Case 1:

        Current digit < 9

        Increment it by one.

        No carry remains.

        Return the array immediately.

    -------------------------------------------------

    Case 2:

        Current digit == 9

        It becomes

            0

        Carry continues to the previous digit.

    -------------------------------------------------

    If every digit becomes 0,

    Example:

        999

    becomes

        000

    We still have one carry remaining.

    Insert

        1

    at the beginning.

    Final answer:

        1000

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        digits = [1,2,3]

    Start from the end.

        3 < 9

        Increment:

            4

    Result:

        [1,2,4]

    -------------------------------------------------

    Input:

        digits = [4,3,9]

    Last digit:

        9

        becomes

            0

    Carry moves left.

    Next digit:

        3 < 9

        Increment:

            4

    Result:

        [4,4,0]

    -------------------------------------------------

    Input:

        digits = [9,9,9]

    Processing:

        9 -> 0

        9 -> 0

        9 -> 0

    Carry still exists.

    Insert

        1

    Result:

        [1,0,0,0]

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Decimal addition propagates a carry only
    while digits are equal to 9.

    The first digit smaller than 9 absorbs
    the carry by increasing by one.

    If every digit is 9, the carry creates
    a new most significant digit.

    This exactly matches the behavior of
    normal arithmetic addition.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. No carry

        [2,5,8]

        Result:

            [2,5,9]

    2. Carry affects one digit

        [1,2,9]

        Result:

            [1,3,0]

    3. Carry affects multiple digits

        [4,9,9]

        Result:

            [5,0,0]

    4. All digits are 9

        [9]

        Result:

            [1,0]

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Array Simulation

    Recognition Hint:

        Whenever a problem simulates arithmetic
        on an array of digits, process the digits
        from right to left while handling carry.

    Key Learnings:

        • Addition begins from the least
          significant digit.

        • Carry propagates only through
          consecutive 9s.

        • Early return avoids unnecessary
          iterations once the carry is resolved.

    Similar Problems:

        - 989. Add to Array-Form of Integer
        - 415. Add Strings
        - 67. Add Binary

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = digits.size()

    Time:

        O(n)

    Space:

        O(1)

    Note:

        Inserting 1 at the beginning takes
        O(n), so the overall complexity
        remains O(n).
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        // Process digits from right to left
        for (int i = n; i >= 0; i--) {
            // No carry needed
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // Carry generated
            digits[i] = 0;
        }
        // All digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
