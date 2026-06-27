#include <string>
#include <vector>

using namespace std;

/*
    PROBLEM: 387. First Unique Character in a String

    GIVEN:
    - A string s consisting of lowercase English letters.

    RETURN:
    - The index of the first non-repeating character.
    - If no such character exists, return -1.

    -------------------------------------------------
    KEY IDEA: TWO-PASS FREQUENCY COUNTING
    -------------------------------------------------

    To determine whether a character is unique,
    we first need to know how many times every
    character appears.

    Since the string contains only lowercase
    English letters ('a' to 'z'), we can store
    the frequency of each character in an array
    of size 26.

    The solution is divided into two passes:

        Pass 1:
            Count the frequency of every character.

        Pass 2:
            Traverse the string again and return
            the first character whose frequency
            is exactly one.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Step 1:

        Create a frequency array of size 26,
        initialized to zero.

    Step 2:

        Traverse the string and increment the
        frequency of each character.

    Step 3:

        Traverse the string again.

        If the current character has frequency 1,
        return its index immediately.

    Step 4:

        If no unique character exists,
        return -1.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        s = "leetcode"

    Pass 1 (Frequency Count):

        l -> 1
        e -> 3
        t -> 1
        c -> 1
        o -> 1
        d -> 1

    Pass 2:

        index 0 -> 'l'

        frequency = 1

        Return 0

    -------------------------------------------------

    Input:

        s = "loveleetcode"

    Frequencies:

        l -> 2
        o -> 2
        v -> 1
        e -> 4
        t -> 1
        c -> 1
        d -> 1

    Second Pass:

        l -> repeated
        o -> repeated
        v -> unique

    Return:

        2

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    The first traversal gathers complete
    frequency information.

    The second traversal preserves the original
    order of characters.

    Therefore, the first character encountered
    with frequency one is exactly the first
    unique character.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. First character is unique

        s = "leetcode"

        Result:

            0

    2. Last character is unique

        s = "aabbccd"

        Result:

            6

    3. No unique character

        s = "aabbcc"

        Result:

            -1

    4. Single character

        s = "z"

        Result:

            0

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Frequency Counting

    Recognition Hint:

        Whenever a problem asks about
        occurrences, duplicates, or unique
        elements, consider using a frequency
        array or hash map.

    Key Observation:

        Since there are only 26 lowercase
        English letters, a fixed-size array
        is more efficient than an unordered_map.

    Similar Problems:

        - 242. Valid Anagram
        - 383. Ransom Note
        - 771. Jewels and Stones
        - 1207. Unique Number of Occurrences

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = s.length()

    Time:

        O(n)

        - First pass : O(n)
        - Second pass: O(n)

    Overall:

        O(n)

    Space:

        O(1)

    Note:

        The frequency array always contains
        exactly 26 elements, regardless of
        the input size.
*/

class Solution {
public:
    int firstUniqChar(string s) {

        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find the first unique character
        for (int i = 0; i < s.size(); i++) {

            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
