#include <iostream>
using namespace std;

int main(){
    int col = 5;
    int row = 8;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << "* ";
        }
        cout<<"\n";
    }

    return 0;
}

