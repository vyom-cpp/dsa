#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

vector<int> brute(vector<int> arr){
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++){
        // It prevents from adding the same number multiple times, ensuring output contains only unique majority elements.
        if(find(ans.begin(), ans.end(), arr[i]) == ans.end()){
            
            int count = 0;
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] == arr[i]){
                    count++;
                }
            }
            
            if(count > (arr.size() / 3)) {
                ans.push_back(arr[i]);
            }
        }
    }
    return ans;
}

vector<int> better(vector<int> arr){
    map<int, int> mpp;
    vector<int> ls;
    int mini = floor((arr.size() / 3)) + 1;
    for(int i = 0; i < arr.size(); i++){
        // this will update the count of the unique key
        mpp[arr[i]]++;
        if(mpp[arr[i]] == mini) ls.push_back(arr[i]);
    }
    return ls;
}

vector<int> optimal(vector<int> arr){
    int el1, el2, ct1 = 0, ct2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(ct1 == 0 && arr[i] != el2){
            ct1 = 1;
            el1 = arr[i];
        } else if( ct2 == 0 && arr[i] != el1){
            ct2 = 1;
            el2 = arr[i];
        } else if(el1 == arr[i])    ct1++;
          else if(el2 == arr[i])    ct2++;
        else {
            ct1--;
            ct2--;
        }
    }
    vector<int> ans;
    ct1 = 0, ct2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(el1 == arr[i])   ct1++;
        if(el2 == arr[i])   ct2++;
    }
    int mini = floor((arr.size() / 3)) + 1;
    if(ct1 >= mini)  ans.push_back(el1);
    if(ct2 >= mini)  ans.push_back(el2);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> res1 = brute(arr);
    vector<int> res2 = better(arr);
    vector<int> res3 = better(arr);

    for(int i : res1){
        cout << i << " ";
    }

    cout << endl;

    for(int i : res2){
        cout << i << " ";
    }

    cout << endl;

    for(int i : res2){
        cout << i << " ";
    }
    return 0;
}