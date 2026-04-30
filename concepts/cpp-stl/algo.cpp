// algo.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Base data
    vector<int> v = {5, 2, 9, 1, 5, 6};

    cout << "Original vector: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";


    /* SORT */
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << "\n";


    /* REVERSE */
    reverse(v.begin(), v.end());
    cout << "Reversed: ";
    for (int x : v) cout << x << " ";
    cout << "\n";


    /* MAX / MIN */
    cout << "Max element: " << *max_element(v.begin(), v.end()) << "\n";
    cout << "Min element: " << *min_element(v.begin(), v.end()) << "\n";


    /* COUNT */
    int cnt5 = count(v.begin(), v.end(), 5);
    cout << "Count of 5: " << cnt5 << "\n";


    /* FIND */
    auto it = find(v.begin(), v.end(), 9);
    if (it != v.end())
        cout << "Found 9 at index: " << (it - v.begin()) << "\n";
    else
        cout << "9 not found\n";


    /* ACCUMULATE (SUM) */
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << "\n";


    /* UNIQUE (remove duplicates) */
    sort(v.begin(), v.end()); // must sort first
    auto it2 = unique(v.begin(), v.end());
    v.erase(it2, v.end());

    cout << "After removing duplicates: ";
    for (int x : v) cout << x << " ";
    cout << "\n";


    /* BINARY SEARCH */
    // vector must be sorted
    cout << "Binary search for 5: "
         << binary_search(v.begin(), v.end(), 5)
         << "\n";


    /* LOWER & UPPER BOUND */
    vector<int> v2 = {1, 2, 2, 2, 3, 4};

    auto lb = lower_bound(v2.begin(), v2.end(), 2);
    auto ub = upper_bound(v2.begin(), v2.end(), 2);

    cout << "\nLower bound of 2 index: " << (lb - v2.begin()) << "\n";
    cout << "Upper bound of 2 index: " << (ub - v2.begin()) << "\n";


    /* NEXT PERMUTATION */
    vector<int> p = {1, 2, 3};

    next_permutation(p.begin(), p.end());
    cout << "\nNext permutation: ";
    for (int x : p) cout << x << " ";
    cout << "\n";


    /* PREV PERMUTATION */
    prev_permutation(p.begin(), p.end());
    cout << "Prev permutation: ";
    for (int x : p) cout << x << " ";
    cout << "\n";

    return 0;
}