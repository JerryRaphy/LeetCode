class Solution {
    
    /*
        Memoization Approach : 
        Time Complexity : O(n^3)
        Space Complexity : O(n^2)
    */
    
    int n;
    
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MIN;
        for(int idx=i; idx<=j; idx++){
            int coins = nums[i-1]*nums[idx]*nums[j+1]
                + helper(i, idx-1, nums, dp)
                + helper(idx+1, j, nums, dp);
            
            res = max(res, coins);
        }
        
        return dp[i][j] = res;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        nums.push_back(1);
        nums.insert(begin(nums), 1);
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return helper(1, n, nums, dp);
    }
};