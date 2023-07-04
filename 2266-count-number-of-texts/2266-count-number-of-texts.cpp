class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int dfs(int idx, int n, string &s, vector<int> &dp){
        
        if(idx == n) return 1;
        
        int en = idx + 3;
        if(s[idx] == '7' || s[idx] == '9') en += 1;
        
        int ways = 0;
        en = min(n,en);
        
        
        if(dp[idx] != -1) return dp[idx]%mod;
        
        for(int i=idx ; i<en ; ++i){
            if(s[idx] != s[i]) break;
            ways = (ways%mod + dfs(i+1,n,s,dp)%mod) % mod;
        }
        
        return dp[idx] = ways%mod;
    }
  
    int countTexts(string s) {
        
        int n = s.length();
        vector<int> dp(n,-1);
        return dfs(0,n,s,dp);
        
    }
};