#define ll long long

class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        ll n = nums.size();
        vector<vector<ll>> dp(n,vector<ll>(2,0));
        
        //set the initial few values
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        
        if(n == 1) return nums[0];
      
        dp[1][0] = nums[1];
        dp[1][1] = nums[0] - nums[1];
        
        
        // 0 -> positive
        // 1 -> negative
        
       ll mx = nums[0];
       mx = max(mx,max(dp[1][0],dp[1][1])); 
        
        for(int i=2 ; i<n ; ++i){
            ll f = nums[i];
            dp[i][0] = max(f,dp[i-1][1] + nums[i]);
            dp[i][1] = dp[i-1][0] - nums[i];
            mx = max(mx,max(dp[i][0],dp[i][1]));
        }
        
        return mx;
        
    }
};