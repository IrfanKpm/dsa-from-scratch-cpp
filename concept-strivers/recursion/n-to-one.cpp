#include <iostream>
using namespace std;

void printer(int n){
    if(n==0) return;

    cout << n << " ";
    printer(n-1);
}

int main(){
     int n;
     cout << "enter number : ";
     cin >> n;
     printer(n);
}