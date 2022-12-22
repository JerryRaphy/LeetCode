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
class CBTInserter {
public:
    
    queue<TreeNode*> q;
    TreeNode* f,node;
    
    CBTInserter(TreeNode* root) {
        f = root;
    }
    
    int insert(int val) {
        q.push(f);
        int value;
        bool inserted = false;
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node->left)  q.push(node->left);
            if(!node->left && !inserted){
                 inserted = true;
                 value = node->val;
                 node->left = new TreeNode(val);
            }
            
            if(node->right) q.push(node->right);
            if(!node->right && !inserted){
                 inserted = true; 
                 value = node->val;
                 node->right = new TreeNode(val);
            }
        }
        
        return value;
    }
    
    TreeNode* get_root() {
        return f;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */