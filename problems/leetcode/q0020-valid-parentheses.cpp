#include <string>
#include <vector>
#include <map>

using namespace std;

/*
    PROBLEM: 20. Valid Parentheses

    GIVEN:
    - A string s containing only

          '('  ')'  '{'  '}'  '['  ']'

    RETURN:
    - true  -> if every opening bracket has a
               matching closing bracket in the
               correct order.
    - false -> otherwise.

    -------------------------------------------------
    KEY IDEA: STACK FOR MATCHING BRACKETS
    -------------------------------------------------

    Parentheses follow a Last-In, First-Out (LIFO)
    order.

    Example:

        ({[]})

    The last opening bracket encountered ('[')
    must be the first one to be closed (']').

    This behavior perfectly matches a stack.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Maintain:

        1. A stack to store opening brackets.

        2. A map that stores the matching opening
           bracket for every closing bracket.

            ')' -> '('
            ']' -> '['
            '}' -> '{'

    Traverse the string.

    If the current character is a closing bracket:

        • Stack must not be empty.
        • Stack top must match the expected
          opening bracket.

        Otherwise, the expression is invalid.

        If matched, pop the opening bracket.

    If the current character is an opening bracket:

        Push it onto the stack.

    After processing all characters:

        If the stack is empty,
        every opening bracket was matched.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        s = "{[()]}"

    Processing:

        '{'
            Stack = [{]

        '['
            Stack = [{,[]

        '('
            Stack = [{,[,(]

        ')'
            Matches '('

            Stack = [{,[]

        ']'
            Matches '['

            Stack = [{]

        '}'
            Matches '{'

            Stack = []

    Result:

        true

    -------------------------------------------------

    Input:

        s = "([)]"

    Processing:

        '('
            Stack = [(]

        '['
            Stack = [(,[]

        ')'

            Expected '('

            Top = '['

            Mismatch

    Result:

        false

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Every closing bracket must match the most
    recently opened bracket that has not yet
    been closed.

    Since the stack always stores the latest
    unmatched opening bracket, checking the
    stack's top is sufficient.

    If the order is incorrect or a closing
    bracket appears without a matching opening
    bracket, the string is immediately invalid.

    Finally, the stack must be empty because
    every opening bracket should have been
    matched.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Empty string

        s = ""

        Result:

            true

    2. Starts with closing bracket

        s = ")"

        Result:

            false

    3. Unmatched opening brackets

        s = "((("

        Result:

            false

    4. Incorrect nesting

        s = "([)]"

        Result:

            false

    5. Correct nesting

        s = "{[]}"

        Result:

            true

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Stack Simulation

    Recognition Hint:

        Whenever elements must be matched in
        reverse order (Last-In, First-Out),
        a stack is usually the correct choice.

    Key Observation:

        The most recently opened bracket must
        always be the first one to close.

    Similar Problems:

        - 1047. Remove All Adjacent Duplicates
          In String
        - 2390. Removing Stars From a String
        - 844. Backspace String Compare
        - 1249. Minimum Remove to Make Valid
          Parentheses

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = s.length()

    Time:

        O(n)

    Space:

        O(n)

    Note:

        In the worst case (e.g. "((((("),
        every opening bracket is stored in
        the stack.
*/

class Solution {
public:
    bool isValid(string s) {

        vector<char> stack;
        map<char, char> matching;

        matching[')'] = '(';
        matching[']'] = '[';
        matching['}'] = '{';

        for (char c : s) {
            if (matching.contains(c)) {
                if (stack.empty() ||
                    stack.back() != matching[c]) {
                    return false;
                }
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }
        return stack.empty();
    }
};
