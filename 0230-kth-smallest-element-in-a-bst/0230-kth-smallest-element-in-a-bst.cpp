class Solution {
public:
int solve(TreeNode *root,int &k)
{
    if(root==NULL)
        return 0;
    int count=0;int res=0;
    TreeNode *curr=root;
    
    while(curr)
    {
        if(curr->left==NULL)
        {
            count++;
            if(count==k)
                res=curr->val;
            curr=curr->right;
        }
        else
        {
            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                count++;
                if(count==k)
                    res= curr->val;
                curr=curr->right;
            }
        }
    }
    return res;
}
int kthSmallest(TreeNode* root, int k)
{
    return solve(root,k);
}
};