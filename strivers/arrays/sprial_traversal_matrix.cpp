#include <iostream>
#include <vector>
using namespace std;

// only optimal solution exists; TC => O(n * m) and SC => O(n * m)
vector<int> spiral_traversal(vector<vector<int>> matrix){
    // row size, col size
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, bottom = row - 1, left = 0, right = col - 1;
    vector<int> ans;

    // right -> bottom -> left -> top
    while(left <= right && top <= bottom){
        // move right
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // move bottom
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // move left along with edge case checking
        if(top <= bottom){
            for(int i = right; i >= left; i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }

        // move top along with edge case checking
        if(left <= right){
            for(int i = bottom; i >= top; i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
    }
    return ans;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 28, 9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11}
    };

    int rows = matrix.size(), count = 0, cols = matrix[0].size();
    
    vector<int> ans = spiral_traversal(matrix);

    for(int itr : ans){
        cout << itr << " ";
        count++;
        if(count % cols == 0){
            cout << "\n";
        }
    }
    cout << endl;
    return 0;
}

    