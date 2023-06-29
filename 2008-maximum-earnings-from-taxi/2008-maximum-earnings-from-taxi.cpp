class Solution {
public:
    
    
   
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        int m = rides.size();
        vector<vector<pair<long long,long long>>> v(n+1);
       
        for(auto ride : rides){
            v[ride[0]].push_back({ride[1],ride[1]-ride[0]+ride[2]});
        }
        
        vector<long long> destination(n+2,0);
        int pos = n;
        
        while(pos >= 1){
            destination[pos] = destination[pos+1];
            for(auto it : v[pos]){
                long long take = it.second + destination[it.first];
                destination[pos] = max(destination[pos],take);
            }
            pos -= 1;
        }
        
        return destination[1];
    }
};