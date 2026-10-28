#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode* createTree() {
    int x;
    cin >> x;

    if (x == -1)
        return nullptr;

    TreeNode* root = new TreeNode(x);

    cout << "Enter left child of " << x << " (-1 for NULL): ";
    root->left = createTree();

    cout << "Enter right child of " << x << " (-1 for NULL): ";
    root->right = createTree();

    return root;
}

vector<int> inorder_traversal(TreeNode* root){
    stack<TreeNode*>st;
    TreeNode* node = root;
    vector<int> inorder;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        } else {
            if(st.empty() == true)  break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}

int main() {
    TreeNode* root = NULL;
    cout << "Enter root value (-1 for NULL): ";
    root = createTree();
    cout << "Inorder traversal" << endl;
    vector<int> ans = inorder_traversal(root);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}