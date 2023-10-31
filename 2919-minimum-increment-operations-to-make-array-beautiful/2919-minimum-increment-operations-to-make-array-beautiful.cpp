class Solution {
public:
    
    
    long long solve(int i, vector<int> &nums, int k, int n, vector<long long> &dp){
        
        // base case
        if(i >= n - 2) return 0;
        if(dp[i] != -1) return dp[i];
        
        long long a = (nums[i] >= k ? 0 : k - nums[i]) + solve(i+1,nums,k,n,dp);
        long long b = (nums[i+1] >= k ? 0 : k - nums[i+1]) + solve(i+2,nums,k,n,dp);
        long long c = (nums[i+2] >= k ? 0 : k - nums[i+2]) + solve(i+3,nums,k,n,dp);
        
        return dp[i] = min(a,min(b,c));
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        int n = nums.size();  
        vector<long long> dp(n+1,-1);
        return solve(0,nums,k,n,dp);
    }
};