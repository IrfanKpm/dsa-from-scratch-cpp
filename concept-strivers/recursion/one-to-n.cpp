#include <iostream>
using namespace std;


void printer(int current, int dest){
    if(current > dest) return;

    cout << current;
    if(current != dest) cout << " ";

    printer(current + 1, dest);
}

int main(){
     int dst;
     cout << "enter number : ";
     cin >> dst;

     int current=1;
     printer(current,dst);
}