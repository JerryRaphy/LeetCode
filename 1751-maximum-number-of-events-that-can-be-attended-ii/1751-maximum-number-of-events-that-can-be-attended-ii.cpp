class Solution {
public:
    
    bool static comp(vector<int> &A, vector<int> &B){
        if(A[0] == B[0]) return A[1] < B[1];
        return A[0] < B[0];
    }
    
    
    int solve(int idx, vector<vector<int>> &events, int k, int n, vector<vector<int>> &dp){
        
        // base case
        if(idx == n || k == 0) return 0;
        
        int take = 0;
        int nottake = 0;
        
        if(dp[idx][k] != -1) return dp[idx][k];
        
        // using this event
        take = events[idx][2];
        
        // binary search to the next possible event
        int en = events[idx][1];
        int l = idx + 1;
        int r = n - 1;
        int next_pos = -1;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(events[mid][0] > en){
                next_pos = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        if(next_pos != -1) take += solve(next_pos,events,k-1,n,dp); 
        
        
        // skipping this event
        nottake = solve(idx+1,events,k,n,dp);
        
        return dp[idx][k] = max(take,nottake);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        sort(events.begin(),events.end(),comp);
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,events,k,n,dp);
        
    }
};