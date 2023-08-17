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
    
    bool solve(TreeNode *nodeA, TreeNode *nodeB){
        
        if(!nodeA && !nodeB) return true;
        if(!nodeA || !nodeB) return false; 
        
        if(nodeA->val == nodeB->val) 
          return (solve(nodeA->left,nodeB->right) && solve(nodeA->right,nodeB->left));        
    
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};