class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        bool uneven = false;
        bool levelstartingleaf;
        
        int height = 1;
        while(!q.empty()){
            int n = q.size();
            
            if(n == height){
                bool start = true;
                levelstartingleaf = true;
                
                while(n--){
                    TreeNode *node = q.front().first;
                    TreeNode *next = q.front().second;
                    q.pop();
                    
                    //cases where the first node in the level is at the leftmost position
                    if(start && !node->left){
                        levelstartingleaf = false;
                    }
                    
                    if(node->left) q.push({node->left,node->right});
                
                    if(node->right && next) q.push({node->right,next->left});
                    else if(node->right && !next) q.push({node->right,NULL}); 
                    
                    start = false;
                }
            }
            else {
                height = n;
                uneven = true;
                break;
            }
            
            height *= 2;
        }
        
        if(!uneven) return true;
        
        if(!levelstartingleaf) return false;
        
        cout<<"in here"<<" "<<q.size()<<endl;
        
        int temp = 0;
        while(!q.empty()){
            TreeNode *node = q.front().first;
            TreeNode *next = q.front().second;
            q.pop();
            
            //if any of these have children return false as well
            if(node->left || node->right) return false;
            
            ++temp;
            if(!next) break;
        }
        
        return temp == height;
        
    }
};