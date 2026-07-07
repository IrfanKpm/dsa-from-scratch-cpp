
#include <vector>

using namespace std;

/*
    PROBLEM: 283. Move Zeroes

    GIVEN:
    - An integer array nums.

    RETURN:
    - Move all zeroes to the end of the array.
    - Maintain the relative order of non-zero elements.
    - Modify the array in-place.

    Example:

        Input:

            [0,1,0,3,12]

        Output:

            [1,3,12,0,0]

    -------------------------------------------------
    KEY IDEA: TWO POINTERS
    -------------------------------------------------

    Think of dividing the array into two parts.

        Processed Part
        Unprocessed Part

    We maintain a pointer

        insertPos

    which always points to the position where
    the next non-zero element should be placed.

    As we scan the array:

        • Non-zero element

            Move it to insertPos.

            Advance insertPos.

        • Zero

            Ignore it.

    After all non-zero elements have been placed,
    every remaining position should become zero.

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Suppose

        nums = [0,1,0,3,12]

    Initially

        insertPos = 0

    Traverse the array.

    ---------------------------------

    Current = 0

        Ignore.

        insertPos = 0

    Array:

        [0,1,0,3,12]

    ---------------------------------

    Current = 1

        Place at index 0

        [1,1,0,3,12]

        insertPos = 1

    ---------------------------------

    Current = 0

        Ignore.

    ---------------------------------

    Current = 3

        Place at index 1

        [1,3,0,3,12]

        insertPos = 2

    ---------------------------------

    Current = 12

        Place at index 2

        [1,3,12,3,12]

        insertPos = 3

    Now every non-zero element has been moved.

    Fill remaining positions with zero.

        [1,3,12,0,0]

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Step 1

        Traverse the array.

    Step 2

        Whenever a non-zero element appears,

            copy it to insertPos

            increment insertPos

    Step 3

        Fill remaining indices with zero.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input

        nums = [0,1,0,3,12]

    insertPos = 0

    ---------------------------------

    Read 0

        Ignore

    Read 1

        nums[0] = 1

        insertPos = 1

    Read 0

        Ignore

    Read 3

        nums[1] = 3

        insertPos = 2

    Read 12

        nums[2] = 12

        insertPos = 3

    Fill remaining positions

        nums[3] = 0

        nums[4] = 0

    Final Answer

        [1,3,12,0,0]

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. No zeroes

        [1,2,3]

        Result:

            [1,2,3]

    -------------------------------------------------

    2. All zeroes

        [0,0,0]

        Result:

            [0,0,0]

    -------------------------------------------------

    3. Single element

        [5]

        Result:

            [5]

    -------------------------------------------------

    4. Zero at the end

        [1,2,0]

        Result:

            [1,2,0]

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Two Pointers
        Array Rearrangement

    Recognition Hint:

        Whenever elements satisfying a condition
        must be grouped together while preserving
        their relative order,

        think about maintaining an insertion
        pointer.

    Key Learnings:

        • One pointer scans the array.

        • Another pointer tracks where the next
          valid element should go.

        • After placing all valid elements,
          fill the remaining positions.

    Similar Problems:

        - 27. Remove Element
        - 26. Remove Duplicates from Sorted Array
        - 905. Sort Array By Parity
        - 75. Sort Colors

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
    void moveZeroes(vector<int>& nums) {

        int insertPos = 0;

        for (int num : nums) {

            if (num != 0) {
                nums[insertPos] = num;
                insertPos++;
            }
        }

        while (insertPos < nums.size()) {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};

