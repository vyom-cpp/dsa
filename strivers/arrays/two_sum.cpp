#include <iostream>
#include <map>
using namespace std;

// brute force
vector<int> brute_two_sum(int arr[], int target, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            if(arr[i] + arr[j] == target){
                return {i, j};
            }
        }
    }
    return {-1};
}

// better
vector<int> better_two_sum(int arr[], int target, int n){
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int firstNum = arr[i];
        int remNum = target - firstNum;

        // check if the needed remainder is already in the map
        if(mpp.find(remNum) != mpp.end()){
            return {mpp[remNum], i};
        }
        mpp[firstNum] = i;
    }
    return {-1, -1}; 
}

// optimal (2 pointer approach); TC => O(n) and SC => O(n)
vector<int> optimal_two_sum(int arr[], int target, int n){
    vector<int> ans;
    int i = 0, j = n - 1;

    while (i < j)
    {
        int pair_sum = arr[i] + arr[j];

        if (pair_sum > target)
        {
            j--;
        }
        else if (pair_sum < target)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }

    return {};
}


int main() {
    int n, target;
    cin >> n >> target;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> result1 = brute_two_sum(arr, target, n);
    vector<int> result2 = better_two_sum(arr, target, n);
    vector<int> result3 = optimal_two_sum(arr, target, n);

    for(int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    for(int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    for(int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}