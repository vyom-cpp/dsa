#include <iostream>
#include <vector>
#include <map>
using namespace std;

// brute; TC => O(n^3) and SC => O(1)
int brute(vector<int> arr, int kl){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i; j < arr.size(); j++){
            int sum = 0;
            for(int k = i; k <= j; k++){ // the mistake which is made here is I took k < j to terminate the condition which in turn never executes the term for single value which is arr[2] = 3, hence it returned 6 instead of 7.
                sum += arr[k];
            }
            if(sum == kl){
                count++;
            }
        }
    }
    return count;
}

// better; TC => O(n^2) and SC => O(1)
int better(vector<int> arr, int kl){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            if(sum == kl){
                count++;
            }
        }
    }
    return count;
}

int optimal(vector<int> arr, int kl){
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, count = 0;
    for(int i = 0; i < arr.size(); i++){
        preSum += arr[i];
        int remove = preSum - kl;
        count += mpp[remove];
        mpp[preSum]++;
    }
    return count;
}

int main() {
    vector<int> arr = {3, -3, 1, 1, 1};
    int k = 3;
    // cout << brute(arr, k) << endl;
    // cout << better(arr, k) << endl;
    cout << optimal(arr, k) << endl;
    return 0;
}