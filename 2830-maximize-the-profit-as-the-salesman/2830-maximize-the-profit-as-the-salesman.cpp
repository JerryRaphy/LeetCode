class Solution {
public:
    
    int getmaxprofit(int idx, vector<vector<int>> &offers, int m, vector<int> &dp){
        
        if(idx >= m) return 0;
        
        int curr_max_profit = 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        // take
        int nexthouse = offers[idx][1] + 1;
        int l = idx + 1;
        int r = m - 1;
        
        int next_idx = m;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(offers[mid][0] >= nexthouse){
                next_idx = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        curr_max_profit = offers[idx][2] + getmaxprofit(next_idx,offers,m,dp);
        
        
        // nottake
        curr_max_profit = max(curr_max_profit,getmaxprofit(idx+1,offers,m,dp));
        
        return dp[idx] = curr_max_profit;
        
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        int m = offers.size();
        sort(offers.begin(),offers.end());
        
        vector<int> dp(m+1,-1);
        return getmaxprofit(0,offers,m,dp);
    }
};