#include <bits/stdc++.h>
using namespace std;

/*
<bits/stdc++.h> is a non-standard GCC-specific header.
It includes almost all standard C++ libraries at once, such as:

- <iostream>   → input/output
- <vector>     → dynamic arrays
- <algorithm>  → sort, reverse, min, max, etc.
- <map>        → key-value pairs
- <set>        → unique sorted elements
- <stack>      → LIFO structure
- <queue>      → FIFO structure

⚠️ NOTE:
- It is NOT part of the official C++ standard.
- Works only in GCC/MinGW compilers (commonly used in DSA practice).
- Not recommended for production code.
*/

int main(){

    // pair
    pair<int,int> p = {3, 4};
    cout << "pair.first " << p.first << endl;
    cout << "pair.second " << p.first << endl;
    cout << "\n";

    // stack
    stack<int> st;
    st.push(12);
    st.push(17);
    st.push(24);

    cout << "stack-top : "<< st.top()<<endl;
    st.pop();
    cout << "if-empty : "<< st.empty() << endl;
    cout << "size : " << st.size() << endl;
    cout << "\n";

    // queue
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "front : " << q.front() << endl;
    cout << "back : " << q.back() << endl;
    q.pop();
    cout << "size : " << q.size() << endl;
    cout << "if-empty : "<< q.empty() << endl;
    cout << "\n";

    // set
    set<int> s;

    s.insert(10);
    s.insert(15);
    s.insert(15);
    s.insert(20);

    // iterate
    cout << "set : ";
    for (auto x : s) {
        cout << x << " ";
    }
    cout << "count(7) : " << s.count(7) << endl;
    cout << "\n";

    // unsorted_set
    unordered_set<int> us;
    
    us.insert(10);
    us.insert(5);
    us.insert(20);
    us.insert(10);
    us.insert(3); 

    cout << "unsorted_set : ";
    for (auto x : us) {
        cout << x << " ";
    }
    cout << "\n\n";

    // map
    map<string, int> m;

    m["apple"] = 10;
    m["banana"] = 5;
    m["orange"] = 8;

    cout << "map > m[\"orange\"]" << m["orange"] << endl;


    return 0;
}