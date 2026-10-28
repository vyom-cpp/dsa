#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

TreeNode* createTree() {
    int x;
    cin >> x;

    if (x == -1)
        return nullptr;

    TreeNode* root = new TreeNode(x);

    cout << "Enter the left child of " << x << " (-1 for NULL): ";
    root->left = createTree();

    cout << "Enter the right child of " << x << " (-1 for NULL): ";
    root->right = createTree();

    return root;
}

bool checkChildrenSum(TreeNode* root) {
    if (root == nullptr) return true;

    if (root->left == nullptr && root->right == nullptr)
        return true;

    int lh = root->left ? root->left->val : 0;
    int rh = root->right ? root->right->val : 0;

    return (root->val == lh + rh) &&
           checkChildrenSum(root->left) &&
           checkChildrenSum(root->right);
}

int main() {
    cout << "Enter the root value (-1 for NULL): ";
    TreeNode* root = createTree();

    if (checkChildrenSum(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}