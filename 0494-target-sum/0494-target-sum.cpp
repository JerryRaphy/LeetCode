class Solution {
public:
    
    
    int getways(int idx, int sum, vector<int> &nums, int target, int total, int n, vector<vector<int>> &dp){
        
        if(idx == n){
            if(sum == target) return 1;
            return 0;
        }
        
        if(dp[idx][sum + total] != -1) return dp[idx][sum + total];
        
        int ways = 0;
        
        ways += getways(idx+1,sum + nums[idx],nums,target,total,n,dp);
        ways += getways(idx+1,sum - nums[idx],nums,target,total,n,dp);
        
        return dp[idx][sum + total] = ways;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int total = 0;
        
        for(auto a : nums) total += a;
        
        vector<vector<int>> dp(n+1,vector<int>(2*total + 1,-1));
        return getways(0,0,nums,target,total,n,dp);
    }
};