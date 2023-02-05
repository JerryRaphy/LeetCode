class Solution {
public:
    
    
    
    int helper(int index, vector<int> &prize, int k, int n, vector<int> &dp){
        
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];
        
        int res = helper(index+1,prize,k,n,dp);
        
        int max_range = prize[index] + k;
        int next_index = upper_bound(prize.begin(),prize.end(),max_range) - prize.begin();
        
        res = max(res,next_index - index);
        return dp[index] = res;
    }
    
    int maximizeWin(vector<int>& prize, int k) {
        
        int n = prize.size();
        int res = 0;
        
        vector<int> dp(n+1,-1);
        helper(0,prize,k,n,dp);
        
        for(int i=0 ; i<n ; ++i){
            
            int max_range = prize[i] + k;
            int next_index = upper_bound(prize.begin(),prize.end(),max_range) - prize.begin();
            
            if(next_index == n) res = max(res,next_index - i);
            else res = max(res,next_index - i + dp[next_index]);

        }
        
        return res;
        
    }
};