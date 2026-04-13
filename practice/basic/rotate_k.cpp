
// Q : Given a 1D array, rotate its elements by 'k' position 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
   vector<int> v={1,2,3,4,5,6,7,8,9};
   int k = 12;

   // solution
   k = k % v.size();

   reverse(v.begin(),v.end());
   reverse(v.begin(),v.begin()+k);
   reverse(v.begin()+k,v.end());

   for(int x:v)
      cout << x << " ";



}