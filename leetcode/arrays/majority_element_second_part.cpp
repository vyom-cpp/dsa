#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> optimal_solution(vector<int> arr){
    vector<int> ans;
    int mini = floor((arr.size()) / 3) + 1;
    int el1, el2, ct1 = 0, ct2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(ct1 == 0 && arr[i] != el2){
            ct1 = 1;
            el1 = arr[i];
        } else if(ct2 == 0 && arr[i] != el1){
            ct2 = 1;
            el2 = arr[i];
        } else if(el1 == arr[i])    ct1++;
          else if(el2 == arr[i])    ct2++;
        else {
            ct1--;
            ct2--;
        }
    }
    ct1 = 0, ct2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(el1 == arr[i])   ct1++;
        if(el2 == arr[i])   ct2++;
    }
    if(ct1 >= mini) ans.push_back(el1);
    if(ct2 >= mini) ans.push_back(el2);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr = {3, 2, 3};
    vector<int> res = optimal_solution(arr);
    for(int itr : res){
        cout << itr << " ";
    }
    return 0;
}