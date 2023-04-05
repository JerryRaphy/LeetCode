class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        int n = r1.size();
        vector<pair<int,int>> v;
        
        for(int i=0 ; i<n ; ++i){
            v.push_back({r1[i] - r2[i],i});
        }
        
        sort(v.rbegin(),v.rend());
        
        int i = 0;
        int res = 0;
        while(k--){
            res += r1[v[i++].second];
        }
        
        while(i < n) res += r2[v[i++].second];
        return res;
    }
};