#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// brute; TC => O(nlogn) and SC => O(n)
vector<int> sort_brute(vector<int> arr){
    sort(arr.begin(), arr.end());
    return arr;
}

// better; TC => O(n) but multiple iterations and SC => O(1)
vector<int> sort_better(vector<int> arr){
    int c0 = 0, c1 = 0, c2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0)     c0++;
        else if(arr[i] == 1)    c1++;
        else    c2++;
    }

    for(int i = 0; i < c0; i++){
        arr[i] = 0;
    }
    for(int i = c0; i < c0 + c1; i++){
        arr[i] = 1;
    }
    for(int i = c0 + c1; i < arr.size(); i++){
        arr[i] = 2;
    }
    return arr;
}

// optimal; Dutch National Flag Algorithm; TC => O(n) with single iteration and SC => O(1)
vector<int> sort_optimal(vector<int> arr){
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1){
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}

int main() {
    vector<int> arr = {0, 2, 1, 2, 0, 0, 1, 2, 1, 0, 2};
    vector<int> result1 = sort_brute(arr);
    vector<int> result2 = sort_better(arr);
    vector<int> result3 = sort_optimal(arr);

    for(int itr : result1){
        cout << itr << " ";
    }
    cout << endl;

    for(int itr : result2){
        cout << itr << " ";
    }
    cout << endl;

     for(int itr : result3){
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}