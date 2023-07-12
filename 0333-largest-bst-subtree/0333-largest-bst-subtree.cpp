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
    
    
    class Node{
        public: 
        
        int sz;
        int max_value;
        int min_value;
        
        Node(int sz, int max_value, int min_value){
            this->sz = sz;
            this->max_value = max_value;
            this->min_value = min_value;
        }
    };
    
    Node solve(TreeNode *root){
        
        if(root == NULL) return Node(0,INT_MIN,INT_MAX);
        Node l = solve(root->left);
        Node r = solve(root->right);
        
        if(l.max_value < root->val && root->val < r.min_value){
            return Node(l.sz + r.sz + 1, max(root->val,r.max_value), min(root->val,l.min_value));
        }
        
        return Node(max(l.sz,r.sz),INT_MAX,INT_MIN);
        
    }
    
    int largestBSTSubtree(TreeNode* root) {
        return solve(root).sz;   
    }
};