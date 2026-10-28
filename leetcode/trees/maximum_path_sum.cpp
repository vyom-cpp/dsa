#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* createTree(){
    int x;
    cin >> x;

    if(x == -1) return nullptr;

    TreeNode* root = new TreeNode(x);

    cout << "Enter the left child of " << x << " (-1 for NULL): ";
    root->left = createTree();

    cout << "Enter the right child of " << x << " (-1 for NULL): ";
    root->right = createTree();

    return root;
}

int max_path_down(TreeNode* node, int &maxi){
    if(node == NULL)    return 0;
    int leftSum = max(0, max_path_down(node->left, maxi));
    int rightSum = max(0, max_path_down(node->right, maxi));
    maxi = max(maxi, node->val + leftSum + rightSum);
    return node->val + max(leftSum, rightSum);
}

int max_path_sum(TreeNode* root){
    int maxi = INT_MIN;
    max_path_down(root, maxi);
    return maxi;
}



int main() {
    TreeNode* root = NULL;
    root = createTree();
    cout << "The maximum path sum is " << max_path_sum(root) << endl;
    return 0;
}