#include <iostream>
#include <vector>
using namespace std;

// brute; TC => (n^3)
void markRow(vector<vector<int>> &matrix, int row, int col){
    for(int j = 0; j < col; j++){
        if(matrix[row][j] != 0){
            matrix[row][j] = -1;
        }
    }
}

void markCols(vector<vector<int>> &matrix, int col, int row){
    for(int i = 0; i < row; i++){
        if(matrix[i][col] != 0){
            matrix[i][col] = -1;
        }
    }
}

void set_matrix_zeroes_brute(vector<vector<int>> &matrix){
    int rows = matrix.size();
    if(rows == 0)   return;
    int cols = matrix[0].size();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){
                markRow(matrix, i, cols);
                markCols(matrix, j,rows);
            }
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}

// better; TC => O(2 * n * m) and SC => O(n + m)
vector<vector<int>> set_matrix_zeroes_better(vector<vector<int>> &matrix, int n, int m){
    vector<int> col = {m, 0};
    vector<int> row = {n, 0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

// optimal; TC => O(2 * n * m) and SC => Ö(1)
vector<vector<int>> set_matrix_zeroes_optimal(vector<vector<int>> &matrix, int n, int m) {
    int col0 = 1; 


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark row
                
                if (j != 0) {
                    matrix[0][j] = 0; // Mark col
                } else {
                    col0 = 0; 
                }
            }
        }
    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }


    if (matrix[0][0] == 0) { 
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }


    if (col0 == 0) { 
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    // set_matrix_zeroes_brute(matrix);


    // for(const auto& row : matrix){
    //     for(int val : row){
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    int n = matrix.size();
    int m = matrix[0].size();

    // Call the function
    set_matrix_zeroes_optimal(matrix, n, m);

    // Print output directly
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}