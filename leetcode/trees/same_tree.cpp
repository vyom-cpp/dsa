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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr)
        return p == q;

    return (p->val == q->val)
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

int main() {
    cout << "Create the first tree." << endl;
    cout << "Enter the value for root (-1 for NULL): ";
    TreeNode* p = createTree();

    cout << "\nCreate the second tree." << endl;
    cout << "Enter the value for root (-1 for NULL): ";
    TreeNode* q = createTree();

    if (isSameTree(p, q))
        cout << "Both trees are the same." << endl;
    else
        cout << "Both trees are not the same." << endl;

    return 0;
}