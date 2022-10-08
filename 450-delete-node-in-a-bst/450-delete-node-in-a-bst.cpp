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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(key < root->val) root->left = deleteNode(root->left,key);
            else if(key > root->val) root->right = deleteNode(root->right,key);
            else{
                //No children for this node now
                if(!root->left && !root->right) return NULL;

                //Only one child
                if(!root->left || !root->right) return root->left ? root->left : root->right;

                //Both Children are present
                TreeNode* temp = root->right;                        
                while(temp->left != NULL) temp = temp->left;    
                root->val = temp->val;                            
                root->right = deleteNode(root->right, temp->val);  
            }
        }
        return root;
    }
};