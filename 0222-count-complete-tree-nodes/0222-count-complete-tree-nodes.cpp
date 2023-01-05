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
    
    int solve(TreeNode *node){
        
        int l = 0;
        TreeNode *temp = node;
        
        while(temp->left){
            temp = temp->left;
            l += 1;
        }
        
        int r = 0;
        temp = node;
        while(temp->right){
            temp = temp->right;
            r += 1;
        }
        if(l == r) return (pow(2,l+1) - 1);
        int cnt = 0;
        if(node->left)  cnt += solve(node->left);
        if(node->right) cnt += solve(node->right);
        return cnt + 1;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return solve(root) ;
    }
};