#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

// brute; TC => O(n^3) and SC => O(1)
int longest_subarray_with_sum_k_brute(int arr[], int n, int k) {
    int max_length = 0;
    
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum == k) {
                max_length = max(max_length, j - i + 1);
            }
        }
    }
    return max_length;
}

// better and this is the most optimized if vector contains all positives, negatives, and zero values
int longest_subarray_with_sum_k_better(vector<int> a, long long k){
    map<long long, int> preMapSum;
    long long sum = 0;
    int maxLen = 0;

    // calculate the sum first
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
        // check if it is equal to k
        if(sum == k)    maxLen = max(maxLen, i + 1);

        // check the remaining sum; if the sum from 0 to 5 is x and sum of 3 to 5 is k, then 0 to 2 sum is x-k
        long long remSum = sum - k;

        // The current sum is already present in the map. (for the if condition)
        if(preMapSum.find(sum) != preMapSum.end()){
            int len = i - preMapSum[remSum];
            maxLen = max(maxLen, len);
        }

        // The current sum is NOT present in the map. (for the if condition)
        if(preMapSum.find(sum) == preMapSum.end()){
            {preMapSum[sum] = i;}
        }
    }
    return maxLen;
}

// optimal (for values including zeroes and positives); TC => O(2n) and SC => O(1)
int longest_subarray_with_sum_k_optimal(vector<int> a, long long k){
    int left = 0, right = 0, maxLen = 0, n = a.size();
    long long sum = a[0];
    while(right < n){
        // reducing the sum if we move to right further then it exceeds the value of k
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }

        // if sum = k
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        
        // now move right and keep adding
        right++;
        if(right < n)   sum += a[right];
    }
    return maxLen;
}


int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> a = {1, 2, 3, 1, 1, 1, 4, 2, 3};

    cout << longest_subarray_with_sum_k_brute(arr, n, k) << endl;
    cout << longest_subarray_with_sum_k_optimal(a, k) << endl;
    return 0;
}