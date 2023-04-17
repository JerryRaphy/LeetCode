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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        map<TreeNode*,int> mp;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        int level_sum = 0;
        
        while(!q.empty()){
            int n = q.size();
            int temp_sum = 0;
            
            while(n--){
                TreeNode* node   = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                
                if(parent == NULL){
                    if(node->left){
                        temp_sum += node->left->val;
                        q.push({node->left,node});
                    }
                    if(node->right){
                        temp_sum += node->right->val;
                        q.push({node->right,node});
                    }
                    mp[node] = temp_sum;
                    node->val = 0;
                    continue;
                }
                
                int new_value = level_sum - mp[parent];   
                int f = 0;
                
                if(node->left){
                    f += node->left->val;
                    temp_sum += node->left->val;
                    q.push({node->left,node});
                }
                if(node->right){
                    f += node->right->val;
                    temp_sum += node->right->val;
                    q.push({node->right,node});
                }
                
                mp[node] = f;
                node->val = new_value;
            }
            level_sum = temp_sum;
        }
        return root;
    }
};