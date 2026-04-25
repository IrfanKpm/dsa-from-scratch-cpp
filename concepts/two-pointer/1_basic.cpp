#include <iostream>
#include <vector>
using namespace std;

// Move function outside main (C++ rule)
bool valid(int a, int b) {
    // Example rule: keep only if values are different
    return a != b;
}

int main() {
    // Pattern 1: Opposite ends
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();

    bool condition_met = true;
    bool need_bigger = true;

    int left = 0, right = n - 1;

    while (left < right) {
        if (condition_met) {
            // do something with both ends
            cout << "Pair: " << arr[left] << " " << arr[right] << endl;
            left++;
            right--;
        } 
        else if (need_bigger) {
            left++;
        } 
        else {
            right--;
        }
    }

    // Pattern 2: Fast/Slow (Floyd-style / filtering pattern)
    int slow = 0;

    for (int fast = 0; fast < n; fast++) {
        if (slow == 0 || valid(arr[slow - 1], arr[fast])) {
            arr[slow] = arr[fast];  // safe overwrite
            slow++;
        }
    }

    // Optional: show result after "filtering"
    cout << "After slow-fast processing: ";
    for (int i = 0; i < slow; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}