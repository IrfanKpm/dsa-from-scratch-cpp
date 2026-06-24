#include <vector>
#include <string>

using namespace std;

/*
    PROBLEM: 1598. Crawler Log Folder

    GIVEN:
    - A list of folder navigation operations logs

    Each operation can be:

        "../"
            Move to parent folder

        "./"
            Stay in the current folder

        "x/"
            Move into a child folder named x

    Initially:
        We start at the main folder.

    RETURN:
    - Minimum number of operations needed to return
      to the main folder after executing all logs.

    -------------------------------------------------
    KEY IDEA: TRACK CURRENT DEPTH
    -------------------------------------------------

    We do not need to know the actual folder names.

    The only thing that matters is:

        How deep are we from the main folder?

    Let:

        depth = current distance from root

    Rules:

        Enter child folder:
            depth++

        Stay in current folder:
            no change

        Move to parent folder:
            depth--

            But depth can never become negative
            because we cannot move above root.

    -------------------------------------------------
    APPROACH
    -------------------------------------------------

    Maintain a counter representing the current
    folder depth.

    Process each log entry:

        "../"
            Move one level up if possible

        "./"
            Ignore

        Any other folder name
            Move one level deeper

    At the end:

        depth = number of folders between
                current location and root

    Therefore:

        Answer = depth

    -------------------------------------------------
    DRY RUN
    -------------------------------------------------

    Input:

        logs = ["d1/","d2/","../","d21/","./"]

    Start:

        depth = 0

    "d1/"
        depth = 1

    "d2/"
        depth = 2

    "../"
        depth = 1

    "d21/"
        depth = 2

    "./"
        depth = 2

    Result:

        2

    -------------------------------------------------
    WHY THIS WORKS
    -------------------------------------------------

    The folder names themselves are irrelevant.

    We only care about how many levels deep we are.

    Every child folder increases depth by one.

    Every valid parent move decreases depth by one.

    The final depth directly represents the number
    of steps required to return to the main folder.

    -------------------------------------------------
    EDGE CASES
    -------------------------------------------------

    1. Already at root

        logs = ["../","../"]

        depth remains 0

        Answer = 0

    2. Only current-folder operations

        logs = ["./","./"]

        depth remains 0

        Answer = 0

    3. Only entering folders

        logs = ["a/","b/","c/"]

        depth = 3

        Answer = 3

    -------------------------------------------------
    PATTERN / LEARNING
    -------------------------------------------------

    Pattern:
        Simulation

    Recognition Hint:

        If the problem asks you to execute a sequence
        of operations and track a changing state,
        simple simulation is often sufficient.

    Observation:

        Folder names are unnecessary.

        Only the current depth matters.

    Similar Problems:

        - 71. Simplify Path
        - 388. Longest Absolute File Path
        - 735. Asteroid Collision

    -------------------------------------------------
    COMPLEXITY
    -------------------------------------------------

    Let n = logs.size()

    Time:
        O(n)

    Space:
        O(1)
*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for (string log : logs) {

            if (log == "../") {

                if (depth > 0) {
                    depth--;
                }

            } else if (log != "./") {

                depth++;
            }
        }

        return depth;
    }
};
