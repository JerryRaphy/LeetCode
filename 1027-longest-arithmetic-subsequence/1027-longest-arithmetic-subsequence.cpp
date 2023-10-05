class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
            
        int n = nums.size();
        int len = 2;
        
        vector<vector<int>> dp(n+1,vector<int>(2000,1));
        
        for(int i=1 ; i<n ; ++i){
            for(int j=0 ; j<i ; ++j){
                int diff = nums[i] - nums[j] + 600;
                dp[i][diff] = max(dp[i][diff],1 + dp[j][diff]);
                len = max(len,dp[i][diff]);
            }
        }
        
        return len;
    }
};