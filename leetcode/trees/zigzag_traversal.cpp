#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* createTree(){
    int x;
    cin >> x;

    if(x == -1) return 0;
    TreeNode* root = new TreeNode(x);

    cout << "Enter the left child of " << x << " (-1 for NULL): ";
    root->left = createTree();

    cout << "Enter the right child of " << x << " (-1 for NULL): ";
    root->right = createTree();

    return root;
}

vector<vector<int>> zigzagLevelOrderTraversal(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> row(size); // This will create the vector row of "size" all initialized to zero

        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size - 1 - i);
            row[index] = node->val;

            if(node->left)  q.push(node->left);
            if(node->right)  q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(row);
    }
    return ans;
}

int main() {
    TreeNode* root = NULL;
    cout << "Enter the root value (-1 for NULL): ";
    root = createTree();

    vector<vector<int>> result = zigzagLevelOrderTraversal(root);

    cout << "[" << endl;
    for (const auto& level : result) {
        cout << "  [";
        for (size_t i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    return 0;
}