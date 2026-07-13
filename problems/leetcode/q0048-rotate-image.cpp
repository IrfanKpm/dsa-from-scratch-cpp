#include <vector>
#include <algorithm>

using namespace std;

/*
    PROBLEM: 48. Rotate Image

    GIVEN:
    - An n × n matrix representing an image.

    RETURN:
    - Rotate the image by 90 degrees clockwise.
    - The rotation must be performed in-place.

    Example:

        Input

        1 2 3
        4 5 6
        7 8 9

        Output

        7 4 1
        8 5 2
        9 6 3

    -------------------------------------------------
    KEY IDEA
    -------------------------------------------------

    Rotating a matrix directly is difficult.

    Instead, observe an important fact.

    A 90° clockwise rotation can be achieved
    using two simple operations:

        1. Transpose the matrix.

        2. Reverse every row.

    This is much easier than moving every
    element individually.

    -------------------------------------------------
    STEP 1 : TRANSPOSE
    -------------------------------------------------

    Transpose means

        rows become columns.

    Swap

        matrix[i][j]

    with

        matrix[j][i]

    Example:

        Before

        1 2 3
        4 5 6
        7 8 9

        After transpose

        1 4 7
        2 5 8
        3 6 9

    -------------------------------------------------
    WHY j = i + 1 ?
    -------------------------------------------------

    Consider

        matrix[0][1]

    and

        matrix[1][0]

    They should be swapped only once.

    If we loop over the entire matrix,

    they would be swapped twice,
    undoing the operation.

    Therefore we only process the upper
    triangular part.

        j = i + 1

    avoids duplicate swaps.

    -------------------------------------------------
    STEP 2 : REVERSE EACH ROW
    -------------------------------------------------

    Reverse every row.

    Example:

        Before

        1 4 7
        2 5 8
        3 6 9

        After reversing rows

        7 4 1
        8 5 2
        9 6 3

    This is exactly the required
    clockwise rotation.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input

        1 2 3
        4 5 6
        7 8 9

    ---------------------------------

    After transpose

        1 4 7
        2 5 8
        3 6 9

    ---------------------------------

    Reverse Row 1

        7 4 1

    Reverse Row 2

        8 5 2

    Reverse Row 3

        9 6 3

    Final Answer

        7 4 1
        8 5 2
        9 6 3

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    During transpose,

        element

            (i, j)

    moves to

            (j, i)

    Reversing each row then places every
    element into its final rotated position.

    Combining these two operations produces
    exactly a 90° clockwise rotation without
    using any extra matrix.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. 1 × 1 Matrix

        5

        Result

            5

    -------------------------------------------------

    2. 2 × 2 Matrix

        1 2
        3 4

        After rotation

        3 1
        4 2

    -------------------------------------------------

    3. 4 × 4 Matrix

        Works exactly the same because both
        transpose and reverse operate on
        any square matrix.

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Matrix Transformation

    Recognition Hint:

        Whenever a problem asks for

            90° clockwise rotation

        think

            Transpose
            +
            Reverse every row

        Whenever a problem asks for

            90° counter-clockwise rotation

        think

            Transpose
            +
            Reverse every column

    Key Learnings:

        • Transpose converts rows into columns.

        • Only traverse the upper triangle
          while transposing.

        • Reversing rows completes a clockwise
          rotation.

    Similar Problems:

        - 867. Transpose Matrix
        - 54. Spiral Matrix
        - 59. Spiral Matrix II

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n be the number of rows.

    Time:

        O(n²)

        Every element is visited at most once.

    Space:

        O(1)

        The matrix is modified in-place.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse every row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

