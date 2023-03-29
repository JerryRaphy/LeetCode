class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int r, int c, vector<vector<int>> &grid, int n, int m){
        
        if(c < 0 || c >= m) return -1;
        if(r == n) return c;
        
        if(dp[r][c] != -2) return dp[r][c];
        
        if(grid[r][c] == 1)  {
            if(c + 1 < m && grid[r][c + 1] != grid[r][c]) return -1;
            return dp[r][c] = solve(r + 1,c + 1,grid,n,m);
        }
        
        if(c - 1 >= 0 && grid[r][c - 1] != grid[r][c]) return -1;
        return dp[r][c] = solve(r + 1,c - 1,grid,n,m);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> res;
        dp.resize(n,vector<int>(m,-2));
        
        for(int i=0 ; i<m ; ++i){
            dp[0][i] = solve(0,i,grid,n,m);
            res.push_back(dp[0][i]); 
        }
        
        return res;
    }
};