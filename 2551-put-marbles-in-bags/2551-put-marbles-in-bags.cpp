class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
          
        long long res = 0;
        vector<int> v;
        
        int n = weights.size();
        for(int i=1 ; i<n ; ++i){
            v.push_back(weights[i] + weights[i-1]);
        }
        
        sort(v.begin(),v.end());
        long long mx = 0;
        long long mn = 0;
        
        for(int i=0 ; i<k-1 ; ++i){
            mn += v[i];
            mx += v[n - i - 2];
        }
        
        res = mx - mn;
        return res;
        
    }
};