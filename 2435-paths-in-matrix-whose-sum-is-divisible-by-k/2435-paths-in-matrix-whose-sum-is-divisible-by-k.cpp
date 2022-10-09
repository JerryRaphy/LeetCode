class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int solve(int i, int j, int s, int n, int m, vector<vector<vector<int>>> &dp, int k, vector<vector<int>> &grid){
        if(i == n || j == m) return 0;
        if(i == n-1 && j == m-1) {
            if((s+grid[i][j]) % k == 0) return 1;
            return 0;
        }
        if(dp[i][j][s] != -1) return dp[i][j][s];
        return dp[i][j][s] = (solve(i+1,j,(grid[i][j] + s)%k,n,m,dp,k,grid) + solve(i,j+1,(grid[i][j] + s)%k,n,m,dp,k,grid)) %  mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
       int n = grid.size();
       int m = grid[0].size();
       
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1))); 
       return solve(0,0,0,n,m,dp,k,grid); 
        
    }
};