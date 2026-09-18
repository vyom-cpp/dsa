#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute; TC => O(N^3) and SC => O(1)
vector<int> max_subarray_sum_brute(vector<int> arr){
    int maxi = INT16_MIN;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i; j < arr.size(); j++){
            int sum = 0;
            for(int k = i; k < j; k++){
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return {maxi};
}

// better; TC => O(N^2) and SC => O(1)
vector<int> max_subarray_sum_better(vector<int> arr){
    int maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return {maxi};
}

// optimal; Kadane's Algo; TC => O(n) and SC => O(1)
vector<int> max_subarray_sum_optimal(vector<int> arr) {
    long long sum = 0;
    long long maxi = LLONG_MIN; 
    
    int start = 0;   
    int ansSt = -1;  
    int ansEnd = -1;

    for(int i = 0; i < arr.size(); i++) {
        if(sum == 0) {
            start = i; 
        }
        
        sum += arr[i];
        
        if(sum > maxi) {
            maxi = sum;
            ansSt = start; 
            ansEnd = i;
        }
        
        if(sum < 0) {
            sum = 0;
        }
    }
    
    return {(int)maxi, ansSt, ansEnd};
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> res1 = max_subarray_sum_brute(arr);
    vector<int> res2 = max_subarray_sum_better(arr);
    vector<int> res3 = max_subarray_sum_optimal(arr);
    
    for(int itr : res1){
        cout << itr << " ";
    }
    cout << endl;

    for(int itr : res2){
        cout << itr << " ";
    }
    cout << endl;

    for(int itr : res3){
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}