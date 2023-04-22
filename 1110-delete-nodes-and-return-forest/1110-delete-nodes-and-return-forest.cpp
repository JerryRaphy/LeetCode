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
        
    TreeNode* solve(TreeNode *node, unordered_set<int> &st){
        if(node == NULL) return NULL;
        
        node->left  = solve(node->left,st);
        node->right = solve(node->right,st);
        
        if(st.find(node->val) != st.end()){
            if(node->left)  res.push_back(node->left);
            if(node->right) res.push_back(node->right);
            return NULL;
        }
        
        return node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> st;
        for(auto num : to_delete) st.insert(num);
            
        TreeNode* f = solve(root,st);
        if(f) res.push_back(root);
        
        return res;
    }
};