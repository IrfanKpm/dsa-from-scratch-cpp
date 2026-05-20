#include <iostream>
using namespace std;

int main() {
    int n = 5;
    // Upper pyramid
    for(int i = 0; i < n; i++) {
        // Spaces
        for(int j = 0; j < n-i-1; j++) {
            cout << " ";
        }
        // Stars
        for(int k = 0; k < 2*i+1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    // Lower inverted pyramid
    for(int i = 0; i < n; i++) {
        // Spaces
        for(int j = 0; j < i+1; j++) {
            cout << " ";
        }
        // Stars
        for(int k = 0; k < 2*(n-i)-3; k++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}