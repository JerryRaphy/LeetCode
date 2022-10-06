/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int curr = 0;
    
    void convert(TreeNode *root){
        if(root->right) convert(root->right);
        root->val = root->val + curr;
        curr = root->val;
        if(root->left) convert(root->left);
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        convert(root);
        return root;
    }
};