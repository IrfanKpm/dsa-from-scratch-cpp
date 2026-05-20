#include <iostream>
using namespace std;


int main() {
    int rows = 6;
    for(int i=0;i<rows;i++){
        bool x = !(i%2);
        for(int j=0;j<=i;j++){
            cout<<x;
            if (j != i) cout << " ";
            x = (!x);
        }
        cout << "\n";
    }
    return 0;
}