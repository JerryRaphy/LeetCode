const int mod = 1e9 + 7;

class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int n, int k, int target){
        
        if(n == 0 && target == 0) return 1;
        if(n < 0) return 0;
        
        if(dp[n][target] != -1) return dp[n][target] % mod;
        
        int ways = 0;
        for(int i=1 ; i<=k ; ++i){
            if(target - i >= 0){
                ways = (ways % mod + solve(n-1,k,target - i)%mod) % mod;
            }
        }
        
        return dp[n][target] = ways % mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(n,k,target) % mod;
    }
};