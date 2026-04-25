
// Q : Given an array of integers, find the second largest element 

#include <iostream>
#include <climits>
using namespace std;

int main(){

    int max = INT_MIN;
    int secMax = INT_MIN;

    int arr[8]={32,63,29,17,45,24,51,34};

    for(int i=0;i<8;i++){
       if(arr[i]>max){
          secMax = max;
          max = arr[i];
       }else if(arr[i]>secMax && arr[i] != max){
         secMax = arr[i];
       }
    }

    cout << "Second largest element :" << secMax << endl;
    return 0;
}