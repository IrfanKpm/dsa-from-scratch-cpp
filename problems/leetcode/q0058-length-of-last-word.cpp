#include <string>

using namespace std;

/*
    PROBLEM: 58. Length of Last Word

    GIVEN:
    - A string s consisting of words and spaces.

    A word is defined as a maximal substring
    containing only non-space characters.

    RETURN:
    - The length of the last word in the string.

    -------------------------------------------------
    KEY IDEA
    -------------------------------------------------

    Instead of splitting the string into words,
    we can scan the string from the end.

    Why?

    The answer depends only on the last word.

    While scanning backwards:

        1. Ignore all trailing spaces.

        2. Count characters until another
           space (or the beginning of the string)
           is reached.

    This avoids creating extra strings and
    processes only the necessary characters.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Step 1:

        Start from the last character.

    Step 2:

        Skip all trailing spaces.

    Step 3:

        Count consecutive non-space characters.

    Step 4:

        Return the count.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        s = "Hello World"

    Start from the end.

        'd'

        Count = 1

        'l'

        Count = 2

        'r'

        Count = 3

        'o'

        Count = 4

        'W'

        Count = 5

        Space encountered.

    Result:

        5

    -------------------------------------------------

    Input:

        s = "   fly me   to   the moon   "

    Skip trailing spaces.

    Start counting:

        "moon"

    Count:

        4

    Result:

        4

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    The last word is always located just before
    the trailing spaces (if any).

    By scanning backwards:

        • We ignore unnecessary characters.

        • We count only the characters that
          belong to the last word.

    Once another space is encountered,
    the entire last word has been processed.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Single word

        s = "Hello"

        Result:

            5

    2. Trailing spaces

        s = "Hello   "

        Result:

            5

    3. Multiple spaces between words

        s = "a   b"

        Result:

            1

    4. One-letter word

        s = "a"

        Result:

            1

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Reverse Traversal
        String Processing

    Recognition Hint:

        When only the suffix of a string is
        required, consider traversing from
        the end instead of processing the
        entire string.

    Key Learning:

        Reverse traversal often eliminates the
        need for splitting strings or using
        additional memory.

    Similar Problems:

        - 151. Reverse Words in a String
        - 557. Reverse Words in a String III
        - 344. Reverse String

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = s.length()

    Time:

        O(n)

    Space:

        O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int length = 0;

        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

