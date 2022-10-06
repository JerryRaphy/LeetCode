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
    
    int dfs(TreeNode *root, map<int,int> &mp, int &freq){
        if(root == NULL) return 0;
        int l = dfs(root->left,mp,freq);
        int r = dfs(root->right,mp,freq);
        int curr_sum = l + r + root->val;
        mp[curr_sum]++;
        freq = max(mp[curr_sum],freq);
        return curr_sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        map<int,int> mp;
        int freq = 1;
        dfs(root,mp,freq);
        
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(it->second == freq) ans.push_back(it->first);
        }
        return ans;
    }
};