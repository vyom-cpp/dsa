#include <iostream>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right){}
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

// using recursion
int maxDepth(TreeNode* root){
    if(root == NULL)    return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

// using level order traversal
int height_by_level_order_traversal(TreeNode* root){
    queue<TreeNode*>q;
    if(root == NULL)    return 0;
    q.push(root);
    int h = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
        h++;
    }
    return h;
}

int main() {
    TreeNode* root = NULL;
    cout << "Enter root value (-1 for NULL): ";
    root = createTree();
    
    cout << maxDepth(root) << endl;
    cout << height_by_level_order_traversal(root) << endl;
    return 0;
}