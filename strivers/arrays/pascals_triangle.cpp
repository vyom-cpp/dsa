// focus on code quality too, because that's important, the generateRow function can be merged
#include <iostream>
#include <vector>
using namespace std;

// vector<int> generateRow(int row){
//     vector<int> ansRow;
//     long long ans = 1;
//     ansRow.push_back(1);
//     // this is done for the flexibility in calculating the element;
//     // for row = 6; 1, 5 -> ( 5 / 1), 10 -> ((5 * 4)/(1 * 2)), 10 -> ((5 * 4 * 3)/(1 * 2 * 3)), 5, 1
//     for(int col = 1; col < row; col++){
//         ans = ans * (row - col);
//         ans = ans / col;
//         ansRow.push_back(ans);
//     }
//     return ansRow;
// }

// vector<vector<int>> pascals_triangular_ass(int n){
//     vector<vector<int>> ans;
//     for(int i = 1; i <= n; i++){
//         ans.push_back(generateRow(i));
//     }
//     return ans;
// }

vector<vector<int>> pascal_triangular_asss(int n){
    vector<vector<int>> anSS; // Holds the final 2D triangle
    
    for(int i = 1; i <= n; i++){
        vector<int> ansRow;   // Must be initialized fresh for every row
        long long ans = 1;    // Must reset to 1 for every row
        ansRow.push_back(1);  // Every row starts with 1
        
        // Loop runs up to 'i' (current row size) instead of total rows 'n'
        for(int col = 1; col < i; col++){
            ans = ans * (i - col); // Changed 'n' to 'i' to use current row context
            ans = ans / col;
            ansRow.push_back(ans);
        }
        
        anSS.push_back(ansRow); // Push the row inside the outer loop
    }
    
    return anSS;
}


int main() {
    int row = 6;
    vector<vector<int>> res = pascal_triangular_asss(row);
    for (const auto& row_vec : res) { 
        for (int itr : row_vec) { 
            cout << itr << " "; 
        }
    cout << "\n";
    }
    return 0;
}