#include <string>

using namespace std;

/*
    PROBLEM: 389. Find the Difference

    GIVEN:
    - Two strings:

        s
        t

    String t is formed by shuffling s and adding
    exactly one extra character.

    RETURN:
    - The extra character present in t.

    -------------------------------------------------
    KEY IDEA: XOR CANCELLATION
    -------------------------------------------------

    XOR has the following important properties.

    1.

        x ^ x = 0

        A character XOR itself becomes zero.

    Example:

        'a' ^ 'a' = 0

    ---------------------------------------------

    2.

        x ^ 0 = x

    ---------------------------------------------

    3.

        XOR is commutative.

            a ^ b = b ^ a

    ---------------------------------------------

    4.

        XOR is associative.

            (a ^ b) ^ c

        =
            a ^ (b ^ c)

    Therefore, the order of characters does not
    matter.

    -------------------------------------------------
    KEY OBSERVATION
    -------------------------------------------------

    Every character in s also exists in t.

    Therefore,

        every matching character appears twice.

    XORing all characters from both strings
    causes identical characters to cancel out.

    The only remaining value is the extra
    character.

    Example:

        s = "abc"

        t = "cbad"

    XOR:

        a ^ b ^ c ^
        c ^ b ^ a ^ d

    Rearranging:

        (a ^ a)
        ^
        (b ^ b)
        ^
        (c ^ c)
        ^
        d

    becomes

        0 ^ 0 ^ 0 ^ d

    Result:

        d

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Initialize

        answer = 0

    Traverse string s.

        answer ^= current character

    Traverse string t.

        answer ^= current character

    Return answer.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        s = "abcd"

        t = "abcde"

    Initial:

        answer = 0

    XOR all characters from s

        answer =

        a ^ b ^ c ^ d

    XOR all characters from t

        answer =

        a ^ b ^ c ^ d
        ^
        a ^ b ^ c ^ d ^ e

    Matching characters cancel.

    Remaining:

        e

    Result:

        'e'

    -------------------------------------------------

    Input:

        s = ""

        t = "y"

    answer = 0

    XOR:

        0 ^ 'y'

    Result:

        'y'

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every character that appears in both strings
    is XORed exactly twice.

    Since

        x ^ x = 0

    all common characters disappear.

    Only the additional character remains.

    Because XOR is associative and commutative,
    the shuffle order has no effect on the result.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Empty original string

        s = ""

        t = "a"

        Result:

            'a'

    2. Extra character at beginning

        s = "xyz"

        t = "axyz"

        Result:

            'a'

    3. Extra character at end

        s = "abc"

        t = "abcd"

        Result:

            'd'

    4. Shuffled string

        s = "abcd"

        t = "dcbae"

        Result:

            'e'

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Bit Manipulation
        XOR Cancellation

    Recognition Hint:

        Whenever every element appears twice
        except one extra or unique element,
        XOR often provides the simplest solution.

    Key Learnings:

        • x ^ x = 0

        • x ^ 0 = x

        • XOR is associative.

        • XOR is commutative.

        • Matching values cancel automatically.

    Similar Problems:

        - 136. Single Number
        - 268. Missing Number
        - 1486. XOR Operation in an Array
        - 191. Number of 1 Bits

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let

        n = s.length()

    Since

        t.length() = n + 1

    Time:

        O(n)

    Space:

        O(1)
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        char answer = 0;
        // XOR all characters of the first string
        for (char c : s) {
            answer ^= c;
        }
        // XOR all characters of the second string
        for (char c : t) {
            answer ^= c;
        }
        return answer;
    }
};
