// leetcode #2149 (Medium)

#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> res1 = rearrange_array_elems_optimal(arr);

    for( int itr : res1){
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}