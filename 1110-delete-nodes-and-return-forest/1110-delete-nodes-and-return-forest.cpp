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
    
    bool solve(TreeNode *node, set<int> &st, vector<TreeNode*> &res){
        // if(node == NULL) return true;
        bool a = true;
        bool b = true;
        if(node->left)  a = solve(node->left,st,res);
        if(node->right) b = solve(node->right,st,res);
        
        if(!a && node->left)  node->left = NULL;
        if(!b && node->right) node->right = NULL;
        
        if(st.count(node->val)){
           if(node->left)  res.push_back(node->left);
           if(node->right) res.push_back(node->right); 
           return false; 
        }
    
        return true;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(auto num : to_delete) st.insert(num);
        
        vector<TreeNode*> res;
        if(solve(root,st,res)) res.push_back(root);

        return res;
    }
};