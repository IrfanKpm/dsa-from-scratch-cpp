#include <iostream>
using namespace std;

void printName(int n,string name){
    if(n == 0) return; 
       
    cout << name;
    printName(n-1,name);
    
}

int main(){
    string name = "irfan\n";
    int count = 6;

    printName(count,name);

}