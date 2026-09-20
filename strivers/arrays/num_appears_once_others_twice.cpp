#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// brute force
int num_appears_once_others_twice_brute(int arr[], int n){
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == num)   count++;
        }
        if(num == 1)    return num;
    }
    return 0;
}

// better
int num_appears_once_others_twice_better(int arr[], int n) { 
    int maxi = arr[0]; 
    for(int i = 1; i < n; i++) { 
        maxi = max(maxi, arr[i]); 
    } 
    
    int hash[maxi + 1]; 
    
    for(int i = 0; i <= maxi; i++) {
        hash[i] = 0;
    }
    
    for(int i = 0; i < n; i++) { 
        hash[arr[i]]++; 
    } 
    
    for(int i = 0; i < n; i++) { 
        if(hash[arr[i]] == 1) return arr[i]; 
    } 
    
    return -1; 
}


// optimal
int num_appears_once_others_twice_optimal(int arr[], int n){
    int xor1 = 0;
    for(int i = 0; i < n; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // cout << num_appears_once_others_twice_brute(arr, n) << endl;
    // cout << num_appears_once_others_twice_better(arr, n) << endl;
    cout << num_appears_once_others_twice_optimal(arr, n) << endl;
    return 0;
}