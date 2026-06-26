#include <vector>

using namespace std;

/*
    PROBLEM: 3232. Find if Digit Game Can Be Won

    GIVEN:
    - An array nums of positive integers.

    Alice has two possible strategies:

        Strategy 1:
            Choose all single-digit numbers
            (numbers from 0 to 9).

        Strategy 2:
            Choose all double-digit numbers
            (numbers from 10 to 99).

    Bob receives all remaining numbers.

    RETURN:
    - true  -> if Alice can choose one of the two
               strategies and obtain a strictly
               greater total sum than Bob.
    - false -> otherwise.

    -------------------------------------------------
    KEY OBSERVATION
    -------------------------------------------------

    Let:

        singleSum = sum of all single-digit numbers

        doubleSum = sum of all double-digit numbers

    The total array sum is

        total = singleSum + doubleSum

    -------------------------------------------------
    CASE 1

    Alice chooses all single-digit numbers.

    Alice = singleSum

    Bob = doubleSum

    Alice wins if

        singleSum > doubleSum

    -------------------------------------------------
    CASE 2

    Alice chooses all double-digit numbers.

    Alice = doubleSum

    Bob = singleSum

    Alice wins if

        doubleSum > singleSum

    -------------------------------------------------
    Therefore,

    Alice wins whenever

        singleSum != doubleSum

    because one of the two sums must be larger.

    If

        singleSum == doubleSum

    neither strategy gives Alice a strictly
    greater score.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Traverse the array once.

    If a number is single-digit

        add it to singleSum

    Otherwise

        add it to doubleSum

    Finally,

        return singleSum != doubleSum

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        nums = [1,2,12]

    Processing:

        singleSum = 1 + 2 = 3

        doubleSum = 12

    Comparison:

        3 != 12

    Alice chooses double-digit numbers.

    Alice = 12

    Bob = 3

    Result:

        true

    -------------------------------------------------

    Input:

        nums = [5,5,10]

    Processing:

        singleSum = 10

        doubleSum = 10

    Comparison:

        10 == 10

    No strategy gives Alice a strictly
    greater score.

    Result:

        false

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Alice has only two possible choices.

    There is no optimization or searching required.

    We simply compute the total sum for each group
    and compare them.

    If one group has a larger sum, Alice chooses
    that group and wins.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Only single-digit numbers

        nums = [1,2,3]

        singleSum = 6
        doubleSum = 0

        Result = true

    2. Only double-digit numbers

        nums = [10,20]

        singleSum = 0
        doubleSum = 30

        Result = true

    3. Equal sums

        nums = [1,2,3,6]

        singleSum = 12
        doubleSum = 0

        (Not equal)

        Result = true

    4. Balanced sums

        nums = [4,6,10]

        singleSum = 10
        doubleSum = 10

        Result = false

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Mathematical Observation

    Recognition Hint:

        When a problem offers only a small,
        fixed number of choices, compute the
        result for each choice directly instead
        of searching or simulating.

    Key Learning:

        Instead of explicitly checking both
        strategies, observe that

            singleSum > doubleSum

        OR

            doubleSum > singleSum

        is equivalent to

            singleSum != doubleSum

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = nums.size()

    Time:

        O(n)

    Space:

        O(1)
*/

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {

        int singleSum = 0;
        int doubleSum = 0;

        for (int num : nums) {

            if (num <= 9) {
                singleSum += num;
            } else {
                doubleSum += num;
            }
        }

        return singleSum != doubleSum;
    }
};
