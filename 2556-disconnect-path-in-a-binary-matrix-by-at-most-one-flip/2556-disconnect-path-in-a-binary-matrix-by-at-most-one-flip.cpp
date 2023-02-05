class Solution {
public:
    
    
    vector<vector<int>> dp;
    vector<vector<int>> pp;
    
    bool dfs(int x, int y, vector<vector<int>> &grid, int n, int m){
        
        if(x >= n || y >= m) return false;
        if(grid[x][y] == 0) return false;
        if(x == n-1 && y == m-1) return true;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        if(dfs(x+1,y,grid,n,m)){
            grid[x][y] = 0;
            return dp[x][y] = 1;
        }
        
        if(dfs(x,y+1,grid,n,m)){
            grid[x][y] = 0;
            return dp[x][y] = 1;
        }
        
        return dp[x][y] = 0;
    }
    
    bool helper(int x, int y, vector<vector<int>> &grid, int n, int m){
        if(x >= n || y >= m) return false;
        if(grid[x][y] == 0) return false;
        if(x == n-1 && y == m-1) return true;
        if(pp[x][y] != -1) return pp[x][y];
        
        if(helper(x+1,y,grid,n,m) || helper(x,y+1,grid,n,m)) return pp[x][y] = 1;
        return pp[x][y] = 0;
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        
        dfs(0,0,grid,n,m);
        grid[0][0] = 1;
        
        pp.resize(n+1,vector<int>(m+1,-1));
        if(helper(0,0,grid,n,m)) return false;
        return true;
    }
};