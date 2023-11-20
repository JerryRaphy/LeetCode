/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = getlca(root,p,q);
        if(ans == p){
            if(dfs(p,q)) return p;
            return NULL;
        }
        if(ans == q){
            if(dfs(q,p)) return q;
            return NULL;
        }
        return ans;
    }
    
    TreeNode* getlca(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == NULL || root == p || root == q) return root;
        TreeNode *l = getlca(root->left,p,q);
        TreeNode *r = getlca(root->right,p,q);
        if(!l && !r) return NULL;
        if(l == NULL) return r;
        if(r == NULL) return l;
        return root;
    }
    
    bool dfs(TreeNode *node, TreeNode *target){
        if(node == target) return true;
        if(node == NULL) return false;
        return dfs(node->left,target) || dfs(node->right,target);
    }
};