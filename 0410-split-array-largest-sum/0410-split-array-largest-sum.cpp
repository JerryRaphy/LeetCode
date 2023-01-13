class Solution {
public:
    
    int solve(int idx, int n, int k, vector<int> &nums, vector<vector<int>> &dp){
                
        int curr = INT_MAX;
        int curr_sum = 0;
        int global_min = INT_MAX;
        
        if(k == 1){
            for(int i=idx ; i<n ; ++i) curr_sum += nums[i];
            return dp[idx][k] = curr_sum;
        }
        
        if(dp[idx][k] != -1) return dp[idx][k];
        
        for(int i=idx ; i<=n-k ; ++i){
            curr_sum += nums[i];
            curr = max(curr_sum,solve(i+1,n,k-1,nums,dp));
            global_min = min(global_min,curr);
        }
        
        return dp[idx][k] = global_min;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,n,k,nums,dp);
    }
};