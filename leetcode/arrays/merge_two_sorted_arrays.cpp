#include <iostream>
#include <vector>
using namespace std;

void merge_two_sorted_array(vector <int>&A, vector <int>&B, int m, int n){
    int i = m - 1, j = n - 1, index = m + n - 1;

    while(i >= 0 && j >= 0){
        if(A[i] >= B[j]){
            A[index--] = A[i--];
        } else {
            A[index--] = B[j--];
        }
    }

    while(j >= 0){
        A[index--] = B[j--];
    }
}

int main() {
    vector <int> A = {1, 2, 3, 0, 0, 0};
    vector <int> B = {2, 5, 6};
    int m = 3, n = 3;

    merge_two_sorted_array(A, B, m, n);

    for(int num : A){
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}

// Leetcode #88
// A = [1, 2, 3, 0, 0, 0], m = 3, sizeof(m) = m + n; B = [2, 5, 6], n = sizeof(B) = 3; only valid elements are counted
// Merge these both arrays into one and store it in A, A = [1, 2, 2, 3, 5, 6]
// TC = O(m + n) and SC = O(1)