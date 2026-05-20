#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter the last character (A-Z): ";
    cin >> ch;
    int rows = ch - 'A';
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=i;j++){
            cout << char('A'+i);
        }
        cout << endl;
    } 
    return 0;
}
