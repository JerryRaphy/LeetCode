class Solution {
public:
    
    bool static comp(pair<pair<int,int>,int> A, pair<pair<int,int>,int> B){
        if(A.first.first == B.first.first) return A.first.second < B.first.second;
        return A.first.first < B.first.first;
    }
    
    vector<int> dp;

    int solve(int idx, vector<pair<pair<int,int>,int>> &v, int n){
        
        if(idx == n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int l = idx + 1;
        int r = n - 1;
        int next_index = n;
        
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(v[mid].first.first >= v[idx].first.second){
                next_index = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
              
        int max_profit = max(v[idx].second + solve(next_index,v,n),solve(idx + 1,v,n));
        
        return dp[idx] = max_profit;
    }
    
    int jobScheduling(vector<int>& starts, vector<int>& ends, vector<int>& profit) {
        
        int n = starts.size();
        vector<pair<pair<int,int>,int>> v;
        
        for(int i=0 ; i<n ; ++i){
            v.push_back({{starts[i],ends[i]},profit[i]});
        }
        
        dp.resize(n,-1);
        sort(v.begin(),v.end(),comp);
      
        return solve(0,v,n);
        
    }
};