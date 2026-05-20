#include <iostream>
using namespace std;

int main() {
    int n=4;
    for(int i=1;i<=n;i++){
        // left numbers
        for(int p=1;p<=i;p++){
            cout << p;
        }
        // middle spaces
        for(int q=1;q<=2*(n-i);q++){
            cout << " ";
        }
        // right numbers
        for(int r=i;r>=1;r--){
            cout << r;
        }        
        // end
        cout << endl;
    }
    return 0;
}