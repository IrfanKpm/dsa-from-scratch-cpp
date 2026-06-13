#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "enter n : ";
    cin >> n;

    int arr[n];
    cout << "enter elments : ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int hash[1000] = {0}; // size depends on constraints

    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for(int i = 0; i < 1000; i++) {
      if(hash[i] > 0) {
        cout << i << " -> " << hash[i] << endl;
      }
    }
}