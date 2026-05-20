#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter the last character (A-Z): ";
    cin >> ch;
    int rows = ch - 'A' + 1;
    for (int i = rows; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << char('A' + j);
        }
        cout << endl;
    }

    return 0;
}