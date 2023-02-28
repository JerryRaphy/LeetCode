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
    
    vector<TreeNode*> res;
    map<string,int> mp;
    
    string solve(TreeNode *root){
        string a,b;
        if(root->left)  a = solve(root->left);
        if(root->right) b = solve(root->right);
        
        string curr = to_string(root->val) + '$' + a + '$' + b;
        
        if(mp[curr] == 1){
            res.push_back(root);
        }
        
        mp[curr] += 1;
        return curr;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       if(root == NULL)  return res;
       solve(root);
       return res; 
    }
};