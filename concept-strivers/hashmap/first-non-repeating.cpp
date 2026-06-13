#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    bool found = false;
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] == 1) {
            cout << "First non-repeating element: " << arr[i] << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "First non-repeating element: -1" << endl;
    }
    return 0;
}