class Solution {
public:
    
    int getprofit(int idx, vector<int> &prices, int buy, vector<vector<int>> &dp){
        
        if(idx == prices.size()) return 0;
        
        int curr_max_profit = 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        // if buy is 0, meaning we haven't bought yet
        
        if(!buy){
            curr_max_profit = max(getprofit(idx+1,prices,1,dp) - prices[idx],getprofit(idx+1,prices,0,dp));
        }
        
        // if buy is 1, we will have to sell now
        
        if(buy){
            curr_max_profit = max(getprofit(idx+1,prices,0,dp) + prices[idx],getprofit(idx+1,prices,1,dp));
        }
        
        return dp[idx][buy] = curr_max_profit;
      
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int buy = 0;
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return getprofit(0,prices,buy,dp);
        
    }
};