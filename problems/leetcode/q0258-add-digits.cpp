/*
    PROBLEM: 258. Add Digits

    GIVEN:
    - A non-negative integer num
    - Repeatedly add all digits until only one digit remains

    RETURN:
    - That final single digit

    -----------------------------------------
    KEY IDEA: DIGITAL ROOT (MOD 9 PATTERN)
    -----------------------------------------

    Instead of simulating repeated digit sums,
    we use a mathematical pattern:

        The result cycles every 9 numbers.

    This is because:
        10 ≡ 1 (mod 9)
    so a number and its digit sum are equivalent modulo 9.

    -----------------------------------------
    CORE OBSERVATION
    -----------------------------------------

    The final answer is:

        num % 9

    BUT there are special cases.

    -----------------------------------------
    EDGE CASES
    -----------------------------------------

    1. num == 0
        → answer = 0

    2. num % 9 == 0 (but num != 0)
        → answer = 9

    Example:
        9  → 9
        18 → 9
        27 → 9
        99 → 9

    Why?
        Because modulo gives 0, but digital root is 9 in these cases.

    -----------------------------------------
    FINAL FORMULA
    -----------------------------------------

        if num == 0 → 0
        if num % 9 == 0 → 9
        else → num % 9

    -----------------------------------------
    COMPLEXITY
    -----------------------------------------

    Time:
        O(1)  → constant math formula

    Space:
        O(1)
*/

int addDigits(int num) {

    if (num == 0) return 0;

    if (num % 9 == 0) return 9;

    return num % 9;
}