#include <string>
#include <vector>

using namespace std;

/*
    PROBLEM: 2390. Removing Stars From a String

    GIVEN:
    - A string s consisting of lowercase letters
      and '*' characters.

    RULE:
    - Every '*' removes:
          1. Itself
          2. The closest non-star character
             immediately to its left

    RETURN:
    - The resulting string after all removals.

    -------------------------------------------------
    KEY IDEA: STACK SIMULATION
    -------------------------------------------------

    Whenever we see:

        Normal character:
            keep it

        '*':
            remove the most recently kept character

    Since '*' always deletes the nearest valid
    character to its left, the character removed
    is always the last character we stored.

    This behavior perfectly matches a stack:

        push -> store character
        pop  -> remove most recent character

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Use a vector<char> as a stack.

    Traverse the string from left to right.

    For each character:

        If character is not '*'
            push it into the stack

        Otherwise
            remove the last stored character

    After processing the entire string,
    convert the stack back into a string.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        s = "leet**cod*e"

    Processing:

        'l' -> [l]
        'e' -> [l,e]
        'e' -> [l,e,e]
        't' -> [l,e,e,t]

        '*' -> [l,e,e]
        '*' -> [l,e]

        'c' -> [l,e,c]
        'o' -> [l,e,c,o]
        'd' -> [l,e,c,o,d]

        '*' -> [l,e,c,o]

        'e' -> [l,e,c,o,e]

    Result:

        "lecoe"

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every '*' removes the closest valid character
    on its left.

    The closest valid character is always the most
    recently added character that has not already
    been removed.

    A stack naturally maintains this order,
    making push() and pop() the ideal operations.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Single deletion

        s = "a*"

        Result = ""

    2. Entire string removed

        s = "abc***"

        Result = ""

    3. No stars

        s = "abcdef"

        Result = "abcdef"

    4. Multiple alternating deletions

        s = "ab*c*d"

        Result = "ad"

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:
        Stack Simulation

    Recognition Hint:

        If a problem repeatedly removes the most
        recently processed valid element, consider
        using a stack.

    Similar Problems:

        - 844. Backspace String Compare
        - 20. Valid Parentheses
        - 1047. Remove All Adjacent Duplicates
          In String

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = s.length()

    Time:
        O(n)

    Space:
        O(n)
*/

class Solution {
public:
    string removeStars(string s) {
        vector<char> stack;

        for (char c : s) {

            if (c != '*') {
                stack.push_back(c);
            } else if (!stack.empty()) {
                stack.pop_back();
            }
        }

        return string(stack.begin(), stack.end());
    }
};

