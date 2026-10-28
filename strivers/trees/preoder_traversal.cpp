#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
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

vector<int> preorder_traversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;
    if(root == NULL)    return ans;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->val);
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL){
            st.push(root->left);
        }
    }
    return ans;
}

int main() {
    TreeNode* root = NULL;
    cout << "Enter root value (-1 for NULL): ";
    root = createTree();
    cout << "Preorder traversal" << endl;
    vector<int> ans = preorder_traversal(root);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}