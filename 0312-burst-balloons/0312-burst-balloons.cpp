class Solution {
public:
    
    
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int left=n ; left>=1 ; --left){
            for(int right=1 ; right<=n ; ++right){
                 if(left > right) continue;
                 int curr_mx = 0;
                 for(int i=left ; i<=right ; ++i){
                    int cal = (nums[i] * nums[left-1] * nums[right+1]) + dp[left][i-1] + dp[i+1][right];
                    curr_mx = max(curr_mx,cal);
                 }
                 dp[left][right] = curr_mx;
            }
        }
        
        return dp[1][n];
    }
};