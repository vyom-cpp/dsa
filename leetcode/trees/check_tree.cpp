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

bool checkTree(TreeNode* root) {
    return (root->val == (root->left->val + root->right->val));
}

int main() {
    cout << "Enter the root value (-1 for NULL): ";
    TreeNode* root = createTree();

    if (checkTree(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}