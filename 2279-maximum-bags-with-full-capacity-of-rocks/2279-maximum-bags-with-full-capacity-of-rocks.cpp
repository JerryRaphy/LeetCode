class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        
        int n = capacity.size();
        vector<int> v;
        
        for(int i=0 ; i<n ; ++i){
            v.push_back(capacity[i] - rocks[i]);
        }
        
        sort(v.begin(),v.end());
        int res = 0;
        
        for(int i=0 ; i<n ; ++i){
            
            if(v[i] == 0) res += 1;
            else if(add >= v[i]){
                add -= v[i];
                res += 1;
            }
        }
        
        return res;
    }
};