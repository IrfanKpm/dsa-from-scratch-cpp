#include <iostream>
#include <vector>
using namespace std;

int main(){

    // Static 2D array
    int arr1[3][2] = {2,5,4,1,3,5};
    cout << "arr1[2][1] : " << arr1[2][1] << endl;

    int arr2[][3] = {1,2,3};

    // -------------------------------------

    // Create a 2D vector (3 rows, 4 columns, initialized with 0)
    vector<vector<int>> vec(3, vector<int>(4, 0));


    vec[0][0] = 10;
    vec[1][2] = 20;
    vec[2][3] = 30;

    cout << "\n2D Vector:\n";
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> newRow = {1, 2, 3, 4};
    vec.push_back(newRow);


    vec[0].push_back(99);

    vec.pop_back();

    cout << "\nElement at vec[1][2]: " << vec[1][2] << endl;


    cout << "Rows: " << vec.size() << endl;
    cout << "Columns in row 0: " << vec[0].size() << endl;

    cout << "\nUsing range-based loop:\n";
    for(auto row : vec){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}