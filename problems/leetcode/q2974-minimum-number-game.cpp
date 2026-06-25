#include <vector>
#include <algorithm>

using namespace std;

/*
    PROBLEM: 2974. Minimum Number Game

    GIVEN:
    - An array nums containing an even number of
      positive integers.

    GAME RULES:

    Repeatedly:

        1. Alice removes the minimum element.
        2. Bob removes the next minimum element.
        3. Bob's number is added first.
        4. Alice's number is added second.

    Continue until all numbers are removed.

    RETURN:
    - The resulting array.

    -------------------------------------------------
    KEY OBSERVATION
    -------------------------------------------------

    Since Alice and Bob always remove the two
    smallest remaining numbers:

        First smallest
        Second smallest

    Sorting the array immediately reveals the
    exact order in which numbers will be chosen.

    After sorting:

        [a, b, c, d, e, f]

    Each round uses:

        (a, b)
        (c, d)
        (e, f)

    The game requires:

        [b, a, d, c, f, e]

    Therefore:

        Simply swap every adjacent pair after
        sorting.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Step 1:
        Sort the array.

    Step 2:
        Traverse in steps of 2.

    Step 3:
        Swap each adjacent pair.

    Step 4:
        Return the modified array.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        nums = [5,4,2,3]

    After sorting:

        [2,3,4,5]

    First pair:

        [2,3]

        Swap

        [3,2,4,5]

    Second pair:

        [4,5]

        Swap

        [3,2,5,4]

    Result:

        [3,2,5,4]

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Sorting places numbers in the exact order
    they would be removed from the game.

    For every round:

        Alice gets the smaller number.
        Bob gets the larger number.

    The result requires Bob's number first,
    followed by Alice's number.

    Therefore swapping every adjacent pair
    perfectly simulates the game.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Smallest valid input

        nums = [1,2]

        Sorted:

            [1,2]

        Swap:

            [2,1]

    2. Already sorted

        nums = [1,2,3,4]

        Result:

            [2,1,4,3]

    3. Duplicate values

        nums = [1,1,2,2]

        Result:

            [1,1,2,2]

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:
        Sorting + Simulation

    Recognition Hint:

        If a problem repeatedly asks for the
        smallest or largest remaining elements,
        sorting often simplifies the simulation.

    Key Observation:

        Instead of actually removing elements
        round by round, sorting reveals the
        final removal order immediately.

    Similar Problems:

        - 455. Assign Cookies
        - 561. Array Partition
        - 2418. Sort the People

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = nums.size()

    Sorting:
        O(n log n)

    Swapping:
        O(n)

    Total Time:
        O(n log n)

    Space:
        O(1)

    Note:

        Sorting is performed in-place.
*/

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }

        return nums;
    }
};
