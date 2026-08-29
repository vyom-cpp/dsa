#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

bool linear_search(vector<int> arr, int x){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == x) return true;
    }
    return false;
}

// TC => O(n^2) and SC => O(1)
int lcs_brute(vector<int> arr){
    int longest = 1;
    for(int i = 0; i < arr.size(); i++){
        int x = arr[i], count = 1;
        while(linear_search(arr, x+1) == true){
            x++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}

// TC => O(nlogn) and SC => O(1)
int lcs_better(vector<int> arr){
    if(arr.size() == 0)    return 0;
    sort(arr.begin(), arr.end());
    int n = arr.size(), lastSmaller = INT_MIN, count = 0, longest = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] - 1 == lastSmaller){
            count++;
            lastSmaller = arr[i];
        } else if(arr[i] != lastSmaller){
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

// TC => (for BC and AC it is O(1) and in WC it is O(n)) and SC => O(1) 
int lcs_optimal(vector<int> arr){
    int n = arr.size();
    if(n == 0)  return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }

    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int count = 1;
            int x = it;
            while(st.find(x + 1) != st.end()){
                x++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main() {
    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1};
    cout << lcs_brute(arr) << endl;
    cout << lcs_better(arr) << endl;
    cout << lcs_optimal(arr) << endl;
    return 0;
}