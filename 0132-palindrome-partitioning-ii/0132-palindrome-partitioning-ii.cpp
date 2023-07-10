class Solution {
public:
    
    int solve(int idx, int n, string &s, vector<int> &dp, vector<vector<bool>> &ispalin){
        
        if(idx == n) return 0;
        int cuts = 3000;
        
        if(dp[idx] != -1) return dp[idx]; 
        
        string curr;
        for(int i=idx ; i<n ; ++i){
            curr.push_back(s[i]);
            if(s[idx] == s[i] && (i - idx <= 2 || ispalin[idx+1][i-1])){
                ispalin[idx][i] = true;
                cuts = min(cuts,1 + solve(i+1,n,s,dp,ispalin));
            }
        }
        
        return dp[idx] = cuts;
    }
    
    int minCut(string s) {
        
        int n = s.length();
        vector<int> dp(n,-1);
        vector<vector<bool>> ispalin(n+1,vector<bool>(n+1,false));
        return solve(0,n,s,dp,ispalin) - 1;
    }
};