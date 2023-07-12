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
    
    vector<TreeNode*> gettrees(int start, int end){
        if(start > end) return {NULL};
        
        vector<TreeNode*> bsts;
        
        for(int i=start ; i<=end ; ++i){
             vector<TreeNode*> leftsubtrees  = gettrees(start,i-1);
             vector<TreeNode*> rightsubtrees = gettrees(i+1,end);
            
            for(auto l : leftsubtrees){
                for(auto r : rightsubtrees){
                    TreeNode *node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    bsts.push_back(node);
                }
            }
        }
        
        return bsts;
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return gettrees(1,n);
    }
};