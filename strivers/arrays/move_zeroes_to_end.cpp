#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// brute
vector<int> moveZeroes(int n, vector<int> a){
    // step-1
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(a[i] != 0)   temp.push_back(a[i]);
    }

    // step-2
    int nz = temp.size();
    for(int i = 0; i < nz; i++){
        a[i] = temp[i];
    }

    // step-3
    for(int i = nz; i < n; i++){
        a[i] = 0;
    }
    return a;
}

// not better approach, next is direct optimal solution
vector<int> moveZeroesOptimal(int n, vector<int> a){
    // step-1
    int j = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            j = i;
            break;   
        }
    }

    // step-2
    if(j == -1) return a;

    for(int i = j + 1; i < n; i++){
        if(a[i] != 0){
            swap(a[i], a[j]);   // 
            j++;    // because i++ is already happening
        }
    }

    return a;
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    int n = arr.size();

    vector<int> bruteResult = moveZeroes(n, arr);
    cout << "Brute Force: ";
    for (int x : bruteResult) {
        cout << x << " ";
    }
    cout << endl;


    vector<int> optimalResult = moveZeroesOptimal(n, arr);
    cout << "Optimal Way: ";
    for (int x : optimalResult) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}