#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter the last character (A-Z): ";
    cin >> ch;

    int rows = ch - 'A' + 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < rows - i; j++) {
            cout << " ";
        }
        for (int k = 0; k < 2 * i - 1; k++) {
            int alpha = k;
            if(alpha>i){
                alpha = 2 * i - 2 - k;
            }
            cout << char('A'+alpha);
        }
        cout << endl;
    }

    return 0;
}