#include <iostream>
using namespace std;

int factor(int n){
    if(n == 0 || n == 1) return 1;
    return n * factor(n - 1);
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
 
    cout << "factorial = " << factor(n);
    
    return 0;
}