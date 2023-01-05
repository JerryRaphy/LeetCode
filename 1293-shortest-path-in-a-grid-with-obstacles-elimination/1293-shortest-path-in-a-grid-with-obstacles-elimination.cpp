class Solution {
public:
     int solve(int i,int j,int k,vector<vector<int>>&grid,vector<vector<int>>&vis, 
 vector<vector<vector<int>>>&dp)
    
{
    
    //Base condition
    
    if(i==0 && j==0)
        return dp[i][j][k]=0;
    
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j])
        return 1e6;
    
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    
    if(grid[i][j]==1)
    {
        
        
        if(k==0)
            return 1e6;
        
        else
            k--;
    }
    
    
    vis[i][j] =1;
    
    int top = 1+solve(i-1, j,k,grid,vis, dp);
    int left =1+solve(i, j-1,k,grid,vis, dp);
    int down =1+solve(i+1, j,k,grid,vis, dp);
    int right = 1+solve(i, j+1,k,grid,vis, dp);
    
    
    vis[i][j] =0;

    return dp[i][j][k] = min(top, min(left, min(right, down)));
}
int shortestPath(vector<vector<int>>& grid, int k) {
    
    int n=grid.size(),m=grid[0].size();
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    // 3-D dp becuase the changing parameters are row , col and k.
    
   vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
                                  
    int ans=solve(n-1,m-1,k,grid,vis,dp);
                                  
   return (ans>m*n)?-1:ans;             
                                 
}
};