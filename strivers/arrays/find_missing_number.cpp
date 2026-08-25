#include <iostream>
#include <cstring>
using namespace std;

// brute force approach -> TC => O(n^2) and SC => O(1)
int find_missing_number_brute(int arr[], int n, int arr_sz){
    for(int i = 1; i <= n; i++){
        int flag = 0;
        for(int j = 0; j < arr_sz; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0)   return i;
    }
    return 0;
}

// better approach - using Hash; TC => O(n) and SC => O(n)
int find_missing_number_better(int arr[], int n, int arr_sz){
    int hash[arr_sz+1];
    std::memset(hash, 0, sizeof(hash));
    // updating the only values which are in the input
    for(int i = 0; i < n - 1; i++){
        hash[arr[i]] = 1;
    }

    for(int i = 1; i < n; i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return 0;
}

// optimal appraoch (2 ways) TC => O(n) and SC => O(1)
int find_missing_number_optimal_sum(int arr[], int n, int arr_sz){
    int sum = (n * (n + 1)) / 2, s2 = 0;
    for(int i = 0; i < arr_sz; i++){
        s2 += arr[i];
    }
    return (sum - s2);
}

int find_missing_number_optimal_xor(int arr[], int n, int arr_sz){
    int xor1 = 0, xor2 = 0;
    for(int i = 1; i <= n; i++){
        xor1 = xor1 ^ i;
    }

    for(int j = 0; j < arr_sz; j++){
        xor2 = xor2 ^ arr[j];
    }

    return xor1 ^ xor2;
}

int main() {
    int n, arr_sz;
    cin >> n >> arr_sz;
    int arr[arr_sz];
    for(int i = 0; i < arr_sz; i++){
        cin >> arr[i];
    }

    // cout << find_missing_number_brute(arr, n, arr_sz) << endl;
    // cout << find_missing_number_better(arr, n, arr_sz) << endl;
    // cout << find_missing_number_optimal_sum(arr, n, arr_sz) << endl;
    cout << find_missing_number_optimal_xor(arr, n, arr_sz) << endl;
    return 0;
}