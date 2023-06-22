class Solution {
public:
    
    int solve(int idx, int walls, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp){      
        
        if(walls <= 0) return 0;
        if(idx < 0) return 1e9;
        
        if(dp[idx][walls] != -1) return dp[idx][walls];
        
        int nottake = solve(idx-1,walls,cost,time,dp);
        
        int take = cost[idx] + solve(idx-1,walls - time[idx] - 1,cost,time,dp);
        
        return dp[idx][walls] = min(nottake,take);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n = cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(n-1,n,cost,time,dp);
        
    }
};