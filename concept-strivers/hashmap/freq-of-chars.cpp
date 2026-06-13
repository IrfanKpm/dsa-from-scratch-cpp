#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "enter string : ";
    cin >> s;

    int hash[26] = {0}; // for a-z

    for(int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(hash[i] > 0) {
            cout << char(i + 'a') << " -> " << hash[i] << endl;
        }
    }
}