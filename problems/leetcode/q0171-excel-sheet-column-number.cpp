#include <string>

using namespace std;

/*
    PROBLEM: 171. Excel Sheet Column Number

    GIVEN:
    - A string columnTitle representing an
      Excel column title.

    RETURN:
    - Its corresponding column number.

    Examples:

        A   -> 1
        B   -> 2
        Z   -> 26
        AA  -> 27
        AB  -> 28
        AZ  -> 52
        BA  -> 53
        ZY  -> 701
        ZZ  -> 702

    -------------------------------------------------
    KEY IDEA
    -------------------------------------------------

    This problem is the reverse of

        168. Excel Sheet Column Title

    Think of the column title as a number
    written in Base-26.

    Example:

        "ABC"

    can be interpreted as

        A × 26²
      + B × 26¹
      + C × 26⁰

    Similar to how decimal numbers work:

        123

    is

        1 × 10²
      + 2 × 10¹
      + 3 × 10⁰

    -------------------------------------------------
    EXCEL'S LETTER VALUES
    -------------------------------------------------

        A -> 1

        B -> 2

        ...

        Z -> 26

    Notice that Excel starts from 1 instead
    of 0.

    Therefore,

        value = (c - 'A') + 1

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Maintain a running answer.

        answer = 0

    For every character:

        answer = answer * 26

    This shifts the previous digits one place
    to the left (just like multiplying by 10
    when building a decimal number).

    Then add the current letter's value.

        answer += letterValue

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        columnTitle = "AB"

    Initial:

        answer = 0

    ---------------------------------

    Character:

        'A'

    Value:

        1

    answer

        = 0 * 26 + 1

        = 1

    ---------------------------------

    Character:

        'B'

    Value:

        2

    answer

        = 1 * 26 + 2

        = 28

    Result:

        28

    -------------------------------------------------

    Input:

        columnTitle = "ZY"

    Initial:

        answer = 0

    ---------------------------------

    'Z'

        value = 26

        answer

        = 26

    ---------------------------------

    'Y'

        value = 25

        answer

        = 26 * 26 + 25

        = 701

    Result:

        701

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Each iteration shifts the previously
    processed letters one Base-26 position
    to the left.

    Multiplying by 26 is equivalent to
    shifting left in Base-26.

    Then the current letter contributes
    its value.

    This is exactly how decimal numbers are
    constructed using

        answer = answer * 10 + digit

    except here the base is

        26

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Single letter

        "A"

        Result:

            1

    2. Largest one-letter title

        "Z"

        Result:

            26

    3. First two-letter title

        "AA"

        Result:

            27

    4. Three-letter title

        "AAA"

        Result:

            703

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Number System Conversion
        Base Conversion

    Recognition Hint:

        Whenever characters represent digits,
        build the answer as

            answer = answer * base + digit

    Key Learnings:

        • Decimal uses base 10.

        • Binary uses base 2.

        • Excel columns use base 26.

        • Multiplication shifts previously
          processed digits to the left.

    Similar Problems:

        - 168. Excel Sheet Column Title
        - Number Base Conversion
        - 67. Add Binary

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = columnTitle.length()

    Time:

        O(n)

    Space:

        O(1)
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {

        int answer = 0;

        for (char c : columnTitle) {

            int value = (c - 'A') + 1;

            answer = answer * 26 + value;
        }

        return answer;
    }
};
