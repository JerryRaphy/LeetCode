class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        
        map<long long,int> mp;
    
        
        for(auto c : coordinates){
            long long x = c[0];
            long long y = c[1];
            
            if(c[0]  < m - 1 && c[1] < n-1) mp[ (long long)c[1] * 1000000L +  c[0]]++;          
            if(c[0] - 1 >= 0 && c[1] < n-1) mp[ (long long)c[1] *  1000000L +  (c[0] - 1)]++;
            if(c[1] - 1 >= 0 && c[0] < m-1) mp[ (long long)(c[1] -1) *  1000000L +  c[0]]++;
            if(c[0] - 1 >= 0 && c[1] - 1 >= 0) mp[ (long long)(c[1] -1) *  1000000L +  (c[0] - 1)]++;
        }
        
        
        // for(auto it : mp) cout<<it.first<<" "<<it.second<<endl;
        
        vector<long long> res(5,0);
      
        
        for(auto it : mp) res[it.second] += 1; 
        long long total = (long long)(m-1) * (long long)(n-1);
        res[0] = total - (res[1] + res[2] + res[3] + res[4]);
        
        
        return res;
        
    }
};