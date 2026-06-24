#include <string>
#include <vector>

using namespace std;

/*
    PROBLEM: 1047. Remove All Adjacent Duplicates In String

    GIVEN:
    - A string s consisting of lowercase letters.

    RULE:
    - Repeatedly remove adjacent duplicate pairs.
    - Continue until no adjacent duplicates remain.

    RETURN:
    - The final string after all removals.

    -------------------------------------------------
    KEY IDEA: STACK SIMULATION
    -------------------------------------------------

    When we encounter a character, we only need to
    compare it with the most recently kept character.

    If both are equal:

        Remove the previous character
        Ignore the current character

    Otherwise:

        Keep the current character

    This behavior perfectly matches a stack.

    The stack stores characters that have survived
    all removals so far.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Use a vector<char> as a stack.

    Traverse the string from left to right.

    For each character:

        If stack is not empty and
        stack.top() == current character

            Remove the top character

        Otherwise

            Push the current character

    After processing all characters,
    the stack contains the final answer.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        s = "abbaca"

    Processing:

        'a' -> [a]

        'b' -> [a,b]

        'b'
            duplicate found

            [a]

        'a'
            duplicate found

            []

        'c' -> [c]

        'a' -> [c,a]

    Result:

        "ca"

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Whenever two adjacent characters are equal,
    both must disappear.

    The most recently kept character is always the
    only possible adjacent duplicate for the current
    character.

    Therefore checking only the stack's top element
    is sufficient.

    After removing a duplicate pair, new adjacent
    duplicates can form automatically, and the stack
    naturally handles these chain reactions.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Empty result

        s = "aaaa"

        "aa" removed
        "aa" removed

        Result = ""

    2. No duplicates

        s = "abcd"

        Result = "abcd"

    3. Chain reactions

        s = "azxxzy"

        "xx" removed

        becomes:

        "azzy"

        "zz" removed

        becomes:

        "ay"

        Result = "ay"

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:
        Stack Simulation

    Recognition Hint:

        If the problem repeatedly removes the most
        recent element based on the current element,
        a stack is usually a strong candidate.

    Observation:

        After removing a pair, new adjacent pairs
        may form.

        A stack automatically handles these
        cascading removals.

    Similar Problems:

        - 2390. Removing Stars From a String
        - 844. Backspace String Compare
        - 20. Valid Parentheses
        - 1209. Remove All Adjacent Duplicates
          in String II

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
    string removeDuplicates(string s) {
        vector<char> stack;

        for (char c : s) {

            if (!stack.empty() && stack.back() == c) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return string(stack.begin(), stack.end());
    }
};

