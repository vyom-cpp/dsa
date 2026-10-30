#include <iostream>
#include <vector>
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
    if(x == -1) return NULL;
    TreeNode* root = new TreeNode(x);
    cout << "Enter the left child of " << x << " (-1 for NULL): ";
    root->left = createTree();

    cout << "Enter the right child of " << x << " (-1 for NULL): ";
    root->right = createTree();

    return root;
}

vector<int> leftBoundaryTraversal(TreeNode* root){
    vector<int> ans;
    if(root == NULL)    return ans;
    if(root->left == NULL && root->right == NULL)   return ans;
    ans.push_back(root->val);
    vector<int> temp = leftBoundaryTraversal(
        root->left ? root->left : root->right
    );
    ans.insert(ans.end(), temp.begin(), temp.end());
    return ans;
}

vector<int> leafTraversal(TreeNode* root){
    vector<int> ans;
    if(root == NULL)    return ans;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->val);
        return ans;
    }
    vector<int> left = leafTraversal(root->left);
    vector<int> right = leafTraversal(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}

vector<int> rightBoundaryTraversal(TreeNode* root){
    vector<int> ans;
    if(root == NULL)    return ans;
    if(root->left == NULL && root->right == NULL)   return ans;
    vector<int> temp = rightBoundaryTraversal(
        root->right ? root->right : root->left
    );
    ans.insert(ans.end(), temp.begin(), temp.end());
    ans.push_back(root->val);
    return ans;
}

vector<int> boundaryTraversal(TreeNode* root){
    vector<int> ans;
    if(root == NULL)    return ans;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->val);
        return ans;
    }

    ans.push_back(root->val);
    
    vector<int> left = leftBoundaryTraversal(root->left);
    ans.insert(ans.end(), left.begin(), left.end());

    vector<int> leaves = leafTraversal(root);
    ans.insert(ans.end(), leaves.begin(), leaves.end());

    vector<int> right = rightBoundaryTraversal(root->right);
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
}

int main() {
    TreeNode* root = NULL;
    cout << "Enter the root value: ";
    root = createTree();

    vector<int> res = boundaryTraversal(root);
    for(auto itr : res){
        cout << itr << " ";
    }
    cout << endl;
    return 0;
}