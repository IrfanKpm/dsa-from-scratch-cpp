
// Q : Remove duplicates from an unsorted array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 5, 1, 4, 9, 1, 6, 0};

    sort(v.begin(), v.end());
    vector<int> uniq;
    uniq.push_back(v[0]);

    //  compare with previous element
    for(int i = 1; i < v.size(); i++) {
        if(v[i] != v[i - 1]) {
            uniq.push_back(v[i]);
        }
    }
    for(int x : uniq) {
        cout << x << " ";
    }

    return 0;
}