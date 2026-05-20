#include<bits/stdc++.h>
using namespace std;

int countDigit(int n){
    if (n == 0) return 1;
    return floor(log10(abs(n))) + 1;
}

int main(){
    vector<int> v = {514,0,-8341};
    for (int x : v) {
       cout << x << " -> " << countDigit(x);
       cout << endl;
    } 
}
