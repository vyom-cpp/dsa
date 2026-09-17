#include <iostream>
#include <vector>
using namespace std;

// brute; TC => O(n + n/2) and SC => O(n)
vector<int> rearrange_array_elems_brute(vector<int> arr){
    vector<int> pos, neg;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] >= 0){
            pos.push_back(arr[i]);
        } else {
            neg.push_back(arr[i]);
        }
    }

    for(int i = 0; i < (arr.size() / 2); i++){
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }
    return arr;
}

// optimal;
vector<int> rearrange_array_elems_optimal(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n, 0);
    int posIdx = 0, negIdx = 1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){
            ans[posIdx] = arr[i];
            posIdx += 2;
        } else {
            ans[negIdx] = arr[i];
            negIdx += 2;
        }
    }
    return ans;
}

// general case
vector<int> rearrange_array_elems_general(vector<int> arr) {
    vector<int> pos, neg;
    
    // Step 1: Separate the positive and negative numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        } else {
            neg.push_back(arr[i]);
        }
    }
    
    int i = 0, j = 0, k = 0;
    
    // Step 2: Alternate them as long as both lists have elements
    while (i < pos.size() && j < neg.size()) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    
    // Step 3: Append remaining positive elements if any
    while (i < pos.size()) {
        arr[k++] = pos[i++];
    }
    
    // Step 4: Append remaining negative elements if any
    while (j < neg.size()) {
        arr[k++] = neg[j++];
    }
    
    return arr;
}

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> res1 = rearrange_array_elems_brute(arr);
    vector<int> res2 = rearrange_array_elems_optimal(arr);

    for( int itr : res1){
        cout << itr << " ";
    }
    cout << endl;

    for( int itr : res2){
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}