#include <iostream>
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

int checkHeight(TreeNode* root){
    if(root == NULL)    return 0;

    int lh = checkHeight(root->left);
    if(lh == -1)    return -1;
    int rh = checkHeight(root->right);
    if(rh == -1)    return -1;
    if(abs(lh-rh) > 1)  return -1;
    return max(lh, rh) + 1;
}

bool balancedTree(TreeNode* root){
    return checkHeight(root) != -1;
}

int main() {
    TreeNode* root = NULL;

    cout << "Enter the root of the tree (-1 for NULL): ";
    root = createTree();

    if (balancedTree(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    return 0;
}