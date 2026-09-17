#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> next_big_permuation(vector<int> arr){
    int idx = -1, n = arr.size();
    // longest prefix finding
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            idx = i;
            break;
        }
    }

    // if there is no dip, then just reverse the array and you get the next permutation
    if(idx == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i = n - 1; i > idx; i--){
        if(arr[i] > arr[idx]){
            swap(arr[i], arr[idx]);
            break;
        }
    }

    reverse(arr.begin() + idx + 1, arr.end());
    return arr;
}

int main() {
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    vector<int> res = next_big_permuation(arr);

    for(int itr : res){
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}