class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        vector<pair<int,int>> v;
        
        for(int i=0 ; i<n ; ++i){
            int diff = costs[i][1] - costs[i][0];
            v.push_back({diff,i});
        }
        
        sort(v.begin(),v.end());
        
        int res = 0;
        for(int i=0 ; i<n/2 ; ++i){
            int idx = v[i].second;
            res += costs[idx][1];
        }
        
        for(int i=n/2 ; i<n ; ++i){
            int idx = v[i].second;
            res += costs[idx][0];
        }
        
        
        return res;
        
    }
};