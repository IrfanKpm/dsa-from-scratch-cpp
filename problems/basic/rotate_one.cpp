
// Q : Given a 1D array, rotate its elements by one position (either left or right)

#include <iostream>
using namespace std;

// fucntion re-usable for n-postional rotation
void rotate(int arr[],int size){
    int temp = arr[size-1];
    for(int i=size-1;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main(){
    int arr[6] = {1,2,3,4,5,6};

    rotate(arr,6);

    for(int x:arr){
        cout << x << " ";
    }
    return 0;
}


// rotate-k > each rotation O(n) , so doing it k times O(n*k)