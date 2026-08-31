#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> rotate_image_brute(vector<vector<int>> &matrix){
    int n = matrix.size();
    // FIX 1: Initialize the 2D vector with size n x n
    vector<vector<int>> ans(n, vector<int>(n)); 
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            ans[col][n - 1 - row] = matrix[row][col];
        }
    }
    return ans;
}

void rotat_image_optimal(vector<vector<int>> &matrix){
    int n = matrix.size();

    // 1. Transpose the matrix
     for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){ // Start j from i + 1
            swap(matrix[i][j], matrix[j][i]); // Use swap to correctly exchange values
        }
    }

    // 2. Reverse each row
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // matrix = rotate_image_brute(matrix);

    int n = matrix.size();

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    
    // optimal way
    rotat_image_optimal(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}