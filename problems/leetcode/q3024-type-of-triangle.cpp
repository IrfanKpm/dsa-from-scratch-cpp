#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    PROBLEM: 3024. Type of Triangle

    GIVEN:
    - An array nums of size 3.
    - nums[i] represents the length of a side.

    RETURN:
    - "equilateral" -> all three sides are equal.
    - "isosceles"   -> exactly two sides are equal.
    - "scalene"     -> all sides are different.
    - "none"        -> cannot form a valid triangle.

    -------------------------------------------------
    KEY IDEA
    -------------------------------------------------

    Before determining the triangle type, we must
    first check whether a valid triangle can be
    formed.

    Triangle Inequality Theorem:

        For any triangle,

            a + b > c

    where c is the longest side.

    If this condition fails, the three sides
    cannot form a triangle.

    -------------------------------------------------
    IMPORTANT OBSERVATION
    -------------------------------------------------

    After sorting:

        a <= b <= c

    We only need to check

        a + b > c

    Why?

    Since c is the largest side,

        a + c > b   (always true)
        b + c > a   (always true)

    Therefore, checking the smallest two sides
    against the largest side is sufficient.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Step 1:
        Sort the three sides.

    Step 2:
        Check the triangle inequality.

        If

            a + b <= c

        return "none".

    Step 3:
        Determine the triangle type.

        If all three sides are equal

            "equilateral"

        Else if any two sides are equal

            "isosceles"

        Otherwise

            "scalene"

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        nums = [3,3,3]

    Sorted:

        [3,3,3]

    Check:

        3 + 3 > 3

        Valid triangle

    All sides equal

    Result:

        "equilateral"

    -------------------------------------------------

    Input:

        nums = [3,4,5]

    Sorted:

        [3,4,5]

    Check:

        3 + 4 > 5

        Valid triangle

    All sides different

    Result:

        "scalene"

    -------------------------------------------------

    Input:

        nums = [1,2,3]

    Sorted:

        [1,2,3]

    Check:

        1 + 2 <= 3

        Not a triangle

    Result:

        "none"

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    Sorting guarantees that the largest side is
    placed at the end.

    The triangle inequality theorem tells us that
    only the sum of the two smaller sides needs
    to exceed the largest side.

    Once validity is confirmed, classifying the
    triangle becomes a simple comparison of side
    lengths.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Invalid triangle

        [1,2,3]

        Result:

            "none"

    2. Equilateral

        [5,5,5]

        Result:

            "equilateral"

    3. Isosceles

        [4,4,6]

        Result:

            "isosceles"

    4. Scalene

        [2,3,4]

        Result:

            "scalene"

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Sorting + Mathematical Observation

    Recognition Hint:

        When a problem involves comparing the
        largest or smallest values, sorting often
        simplifies the logic.

    Key Learning:

        After sorting three sides, checking only

            smallest + middle > largest

        is enough to verify a valid triangle.

    Related Concepts:

        - Triangle Inequality Theorem
        - Sorting
        - Conditional Classification

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = nums.size() = 3

    Sorting:

        O(n log n)

    Classification:

        O(1)

    Overall:

        Time  : O(1)

        (Sorting only 3 elements is constant time.)

    Space:

        O(1)
*/

class Solution {
public:
    string triangleType(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        // Check triangle validity
        if (a + b <= c)
            return "none";

        // All sides equal
        if (a == c)
            return "equilateral";

        // Exactly two sides equal
        if (a == b || b == c)
            return "isosceles";

        // All sides different
        return "scalene";
    }
};
