#include <vector>
#include <unordered_map>

using namespace std;

/*
    PROBLEM: 219. Contains Duplicate II

    GIVEN:
    - An integer array nums.
    - An integer k.

    RETURN:
    - true  -> if there exist two indices i and j
               such that

                    nums[i] == nums[j]

               and

                    |i - j| <= k

    - false -> otherwise.

    -------------------------------------------------
    KEY IDEA
    -------------------------------------------------

    We need to answer two questions:

        1. Have we seen this number before?

        2. Is its previous occurrence close enough?

    A hash map can answer the first question in
    constant time.

    Store:

        Key   -> number

        Value -> its most recent index

    Whenever the same number appears again,
    simply compare the current index with the
    previously stored index.

    -------------------------------------------------
    WHY STORE THE LATEST INDEX?
    -------------------------------------------------

    Consider

        nums = [1,0,1,1]

        k = 1

    Processing:

        Index 0

            1 -> 0

        Index 2

            Difference

                2 - 0 = 2

            Not valid.

            Update

                1 -> 2

        Index 3

            Difference

                3 - 2 = 1

            Valid.

    If we kept the first occurrence forever,
    we would miss the valid pair.

    Therefore,

        always store the latest index.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Traverse the array.

    For each element:

        If it already exists in the map,

            compute

                currentIndex - previousIndex

            If the difference is at most k,

                return true.

        Update the index of the current number.

    If no valid pair exists,

        return false.

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        nums = [1,2,3,1]

        k = 3

    Initially:

        map = {}

    ---------------------------------

    i = 0

        Store

            1 -> 0

    ---------------------------------

    i = 1

        Store

            2 -> 1

    ---------------------------------

    i = 2

        Store

            3 -> 2

    ---------------------------------

    i = 3

        Found

            1

        Previous index:

            0

        Difference:

            3

        3 <= 3

    Result:

        true

    -------------------------------------------------

    Input:

        nums = [1,2,3,1,2,3]

        k = 2

    Every duplicate is farther than 2 indices.

    Result:

        false

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    The hash map always stores the most recent
    occurrence of every number.

    When a duplicate appears,

        current index - previous index

    gives the smallest possible distance to the
    nearest previous occurrence.

    If even that distance is greater than k,
    no earlier occurrence can produce a smaller
    distance.

    Therefore updating the index after every
    occurrence is always correct.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Adjacent duplicates

        nums = [1,1]

        k = 1

        Result:

            true

    2. Duplicate too far away

        nums = [1,2,3,1]

        k = 2

        Result:

            false

    3. Multiple duplicates

        nums = [1,0,1,1]

        k = 1

        Result:

            true

    4. No duplicates

        nums = [1,2,3,4]

        Result:

            false

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:

        Hash Map
        Last Seen Index

    Recognition Hint:

        Whenever a problem asks

            "Have we seen this value before?"

        or

            "Find the previous occurrence"

        consider storing

            value -> last index

        in a hash map.

    Key Learnings:

        • Hash maps provide O(1) average lookup.

        • Store the latest occurrence rather than
          the first occurrence.

        • Compare indices immediately when a
          duplicate is found.

    Similar Problems:

        - 1. Two Sum
        - 217. Contains Duplicate
        - 220. Contains Duplicate III
        - 3. Longest Substring Without Repeating Characters

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = nums.size()

    Time:

        O(n)

        Each lookup and insertion into the
        unordered_map takes O(1) on average.

    Space:

        O(n)

        In the worst case, every element is
        stored in the hash map.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> lastSeenIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (lastSeenIndex.count(nums[i])) {
                if (i - lastSeenIndex[nums[i]] <= k) {
                    return true;
                }
            }
            lastSeenIndex[nums[i]] = i;
        }
        return false;
    }
};

