#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int arr[5]={0};
    cout << arr[0]<<endl;

    vector<int> v1;              // empty vector
    vector<int> v2(5);           // {0,0,0,0,0}
    vector<int> v3(5,3);         // {3,3,3,3,3}
    vector<int> v4 = {3, 7, 2, 9,5}; // direct initialization

    for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<endl;
    }

    v3.push_back(7);

    cout << "Last element in v3 vector : ";
    cout << v3.at(v3.size()-1) << endl;

    // v3.at(...)   → safely accesses element (bounds checked)
    // v3.size()    → gives number of elements
    // v3.size()-1  → last index of vector

    cout << "Last element in v4 vector : " << v4.back() << endl;
    // v4.back() → directly returns last element

    if(v1.empty()){
        cout << "v1 vector is empty\n";
    }else{
        cout << "v1 vector is not empty\n";
    }

    cout << "last element in v4 before pop : " << v4.back() << endl;

    v4.pop_back();

    cout << "last element in v4 after pop : " << v4.back() << endl;

    v1.insert(v1.begin(), 100);   // insert at beginning
    v1.insert(v1.begin()+ 1, 50); // insert at index 1
    v1.insert(v1.begin()+2, 30);  // insert at index 2
    v1.insert(v1.begin()+3, 25);  // insert at index 3
    v1.insert(v1.begin()+4, 23);  // insert at index 4
    v1.insert(v1.begin()+5, 18);  // insert at index 5

    cout << "elements in v1 vector : ";

    for(auto it=v1.begin();it!=v1.end();it++){
        cout << *it << " ";
    }

    cout << "\n\nv1: element at index position 3 > ";
    cout << v1.at(3) << endl;

    cout << "v1: erase element at index position 3\n";

    v1.erase(v1.begin()+3);

    cout << "v1: element at index position 3 > ";
    cout << v1.at(3) << endl;

    cout << "\nelements in v4 vector : ";

    for(auto it=v4.begin();it!=v4.end();it++){
        cout << *it << " ";
    }

    cout << "\nsorting v4.... ";

    sort(v4.begin(), v4.end());  // sorts in O(n log n)

    cout << "\nelements in v4 vector : ";

    for(auto it=v4.begin();it!=v4.end();it++){
        cout << *it << " ";
    }

    cout << "\nreversing v4....\n";

    reverse(v4.begin(), v4.end());  // reverses in O(n)

    for(int x:v4){
        cout << x << " ";
    }

    cout << "\nFront: " << v4.front() << endl;
    cout << "Back: " << v4.back() << endl;
    // front() → first element
    // back()  → last element

    v4.clear(); // removes all elements

    return 0;
}