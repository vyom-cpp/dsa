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

bool isMirror(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr)
        return p == q;

    return (p->val == q->val)
        && isMirror(p->left, q->right)
        && isMirror(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr)
        return true;

    return isMirror(root->left, root->right);
}

int main() {
    cout << "Enter the value for root (-1 for NULL): ";
    TreeNode* root = createTree();

    if (isSymmetric(root))
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}