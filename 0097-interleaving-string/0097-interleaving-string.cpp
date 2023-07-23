class Solution {
public:
    
    
    bool solve(int i, int j, int k, string A, string B, string C, vector<vector<int>> &dp){
        
        if(k < 0) return true;
        
        if(i >= 0 && j >= 0) {
            if(dp[i+1][j+1] != -1) return dp[i+1][j+1];
        }
        
        bool flag = false;
        
        if(i >= 0 && A[i] == C[k] && j >= 0 && B[j] == C[k]) 
            flag = (solve(i-1,j,k-1,A,B,C,dp) | solve(i,j-1,k-1,A,B,C,dp));
        else if(i >= 0 && A[i] == C[k]) flag = solve(i-1,j,k-1,A,B,C,dp);
        else if(j >= 0 && B[j] == C[k]) flag = solve(i,j-1,k-1,A,B,C,dp);
        
        return dp[i+1][j+1] = flag;
    }
    
    bool isInterleave(string A, string B, string C) {
        
        int n = A.length();
        int m = B.length();
        int o = C.length();
        
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        if(n + m != o) return false;
        
        return solve(n-1,m-1,o-1,A,B,C,dp);
    }
};