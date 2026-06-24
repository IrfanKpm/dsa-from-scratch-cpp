#include <string>
#include <vector>

using namespace std;

/*
    PROBLEM: 709. To Lower Case

    GIVEN:
    - A string s containing English letters and
      possibly other characters.

    RETURN:
    - A new string where every uppercase English
      letter is converted to lowercase.

    -------------------------------------------------
    KEY IDEA: ASCII CHARACTER CONVERSION
    -------------------------------------------------

    In ASCII:

        'A' = 65
        'B' = 66
        ...
        'Z' = 90

        'a' = 97
        'b' = 98
        ...
        'z' = 122

    Observation:

        Lowercase letter = Uppercase letter + 32

    Example:

        'A' + 32 = 'a'
        'B' + 32 = 'b'
        'Z' + 32 = 'z'

    Therefore, whenever we find an uppercase
    character, we can convert it by adding 32.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Traverse the string character by character.

    For each character:

        If it lies between 'A' and 'Z'

            Convert it to lowercase by adding 32

        Otherwise

            Keep it unchanged

    Build the result string and return it.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        s = "Hello"

    Processing:

        'H'
            uppercase

            'H' + 32 = 'h'

        'e'
            keep

        'l'
            keep

        'l'
            keep

        'o'
            keep

    Result:

        "hello"

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    ASCII stores uppercase and lowercase English
    letters at fixed positions.

    Every lowercase letter is exactly 32 positions
    after its uppercase counterpart.

    By checking whether a character belongs to the
    uppercase range, we can safely convert it using
    a simple arithmetic operation.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. All lowercase

        s = "leetcode"

        Result = "leetcode"

    2. All uppercase

        s = "HELLO"

        Result = "hello"

    3. Mixed characters

        s = "LOVELY123"

        Result = "lovely123"

    4. Empty string

        s = ""

        Result = ""

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:
        Character Manipulation

    Recognition Hint:

        When working with English letters, knowing
        ASCII relationships can simplify solutions.

    Key Observation:

        Lowercase = Uppercase + 32

    Similar Problems:

        - 520. Detect Capital
        - 125. Valid Palindrome
        - 344. Reverse String

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = s.length()

    Time:
        O(n)

    Space:
        O(n)

    Note:

        If the string were modified in-place,
        space complexity could be O(1).
*/

class Solution {
public:
    string toLowerCase(string s) {
        vector<char> result;
        for (char c : s) {
            if ('A' <= c && c <= 'Z') {
                result.push_back(char(c + 32));
            } else {
                result.push_back(c);
            }
        }
        return string(result.begin(), result.end());
    }
};
