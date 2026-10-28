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

TreeNode* createTree(){
    int x;
    cin >> x;

    if(x == -1)
        return nullptr;

    TreeNode* root = new TreeNode(x);

    cout << "Enter the left child of " << x << " (-1 for NULL): ";
    root->left = createTree();

    cout << "Enter the right child of " << x << " (-1 for NULL): ";
    root->right = createTree();

    return root;
}

vector<int> double_stack_postorder_traversal(TreeNode* root){
    stack<TreeNode*> st1, st2;
    vector<int> ans;
    if(root == NULL)
        return ans;

    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL)
            st1.push(root->left);
        if(root->right != NULL)
            st1.push(root->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}

vector<int> single_stack_postorder_traversal(TreeNode* root){
    vector<int> postorder;
    if (root == NULL) return postorder;

    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* lastVisited = NULL;

    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* node = st.top();

            if (node->right != NULL && lastVisited != node->right) {
                curr = node->right;
            } else {
                postorder.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }
    }
    return postorder;
}

int main() {
    TreeNode* root = NULL;
    cout << "Enter root value (-1 for NULL): ";
    root = createTree();
    cout << "Postorder traversal using 2 stack" << endl;
    vector<int> ans = double_stack_postorder_traversal(root);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}