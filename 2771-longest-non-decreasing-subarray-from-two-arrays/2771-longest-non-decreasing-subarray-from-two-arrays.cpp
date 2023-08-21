class Solution {
public:
    
        
   
        
        
        
        
        
    
    
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>(2,1));
        
        for(int idx=n-2 ; idx>=0 ; --idx){
            
            if(nums1[idx] <= nums1[idx+1] && nums1[idx] <= nums2[idx+1]) {
            dp[idx][0] += max(dp[idx+1][0],dp[idx+1][1]);
            }
            else if(nums1[idx] <= nums1[idx+1]) dp[idx][0] += dp[idx+1][0];
            else if(nums1[idx] <= nums2[idx+1]) dp[idx][0] += dp[idx+1][1];

            if(nums2[idx] <= nums1[idx+1] && nums2[idx] <= nums2[idx+1]) {
                dp[idx][1] += max(dp[idx+1][0],dp[idx+1][1]);
            }
            else if(nums2[idx] <= nums1[idx+1]) dp[idx][1] += dp[idx+1][0];
            else if(nums2[idx] <= nums2[idx+1]) dp[idx][1] += dp[idx+1][1];
        }
        
        int ans = 1;
        for(int i=0 ; i<n ; ++i) ans = max(ans,max(dp[i][0],dp[i][1]));
        
        return ans;
    }
};