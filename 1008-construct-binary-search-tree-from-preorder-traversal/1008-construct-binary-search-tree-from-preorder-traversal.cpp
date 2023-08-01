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
    
    TreeNode* getbst(int &idx, int bound, vector<int> &preorder){
        
        if(idx == preorder.size() || preorder[idx] > bound) return NULL;
        
        TreeNode *node = new TreeNode(preorder[idx]);
        idx++;
        node->left  = getbst(idx,node->val,preorder);
        node->right = getbst(idx,bound,preorder);
        
        return node;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return getbst(idx,INT_MAX,preorder);
    }
};