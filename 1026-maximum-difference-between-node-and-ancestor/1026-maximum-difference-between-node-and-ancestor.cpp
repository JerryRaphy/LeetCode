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
    
    pair<int,int> solve(TreeNode *root, int &val){
        
        // base case is when we encounter a leaf node
        if(!root->left && !root->right){
            return {root->val,root->val};
        }
        
        pair<int,int> l,r;
        if(root->left)  l = solve(root->left,val);
        else l = {INT_MAX,INT_MIN};
        
        if(root->right) r = solve(root->right,val);
        else r = {INT_MAX,INT_MIN};
        
        int mn = min(l.first,r.first);
        int mx = max(l.second,r.second);
       
        val = max(val,max(abs(root->val - mn),abs(root->val - mx)));
        return {min(mn,root->val),max(mx,root->val)};
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int val = 0;
        solve(root,val);
        return val;
    }
};