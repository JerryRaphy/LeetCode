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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        TreeNode *prev = NULL;
        
        while(root){
            
            if(!root->left){
                res.push_back(root->val);
                root = root->right;
            }
            else{
                prev = root->left;
                while(prev->right && prev->right != root) prev = prev->right;
                
                if(prev->right == NULL){
                    prev->right = root;
                    root = root->left;
                }
                else{
                    prev->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                }
            }
        }
        
        return res;

    }
};