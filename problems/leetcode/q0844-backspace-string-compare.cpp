/*
    PROBLEM: 844. Backspace String Compare

    GIVEN:
    - Two strings s and t
    - Character '#' represents a backspace

    RETURN:
    - true  → if both strings become equal after applying backspaces
    - false → otherwise

    -----------------------------------------
    KEY IDEA: SIMULATE A TEXT EDITOR
    -----------------------------------------

    We process each string from left to right.

    Rules:
        - Normal character:
              add it to the result

        - '#':
              remove the most recently added character
              (if one exists)

    This is exactly how a text editor behaves when
    the backspace key is pressed.

    -----------------------------------------
    PROCESSING A STRING
    -----------------------------------------

    We use a vector<char> as a stack.

    For each character:

        if character != '#'
            push into vector

        else
            pop the last character
            if the vector is not empty

    Example:

        s = "ab#c"

        'a' -> [a]
        'b' -> [a,b]
        '#' -> [a]
        'c' -> [a,c]

        Final string = "ac"

    -----------------------------------------
    COMPARISON
    -----------------------------------------

    Process both strings independently.

        processed(s)
        processed(t)

    If both resulting character sequences are equal,
    return true.

    Otherwise return false.

    -----------------------------------------
    EDGE CASES
    -----------------------------------------

    1. Backspace on empty string

        s = "###"

        Nothing to remove.
        Result remains empty.

    2. Multiple consecutive backspaces

        s = "abc###"

        Result becomes empty.

    3. Different original strings
       producing same final string

        s = "ab#c"
        t = "ad#c"

        Both become "ac"

        Answer = true

    -----------------------------------------
    COMPLEXITY
    -----------------------------------------

    Let:
        n = s.length()
        m = t.length()

    Time:
        O(n + m)

    Space:
        O(n + m)
*/
class Solution {
public:
    vector<char> processString(string s) {
        vector<char> v;

        for (char c : s) {

            if (c != '#') {
                v.push_back(c);
            } else {

                if (!v.empty()) {
                    v.pop_back();
                }
            }
        }

        return v;
    }

    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};
