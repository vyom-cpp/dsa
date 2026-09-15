#include <iostream>
#include <vector>
using namespace std;

// brute; TC => O(n^2) and SC => O(n)
vector<int> findLeadersBruteForce(vector<int>& arr) {
    vector<int> leaders;
    int n = arr.size();


    for (int i = 0; i < n; i++) {
        bool isLeader = true;


        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isLeader = false; 
                break; 
            }
        }


        if (isLeader) {
            leaders.push_back(arr[i]);
        }
    }

    return leaders;
}

// optimal
vector<int> findLeadersOptimal(vector<int> &arr){
    vector<int> ans;
    int n = arr.size(), maxi = INT_MIN;
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    // TC => O(nlogn) if required to return the sorted version and SC => O(n)
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> res1 = findLeadersBruteForce(arr);
    vector<int> res2 = findLeadersOptimal(arr);

    cout << "Leaders: ";
    for (int itr : res1) {
        cout << itr << " ";
    }
    cout << endl;
    
    cout << "Leaders: ";
    for (int itr : res2) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}
