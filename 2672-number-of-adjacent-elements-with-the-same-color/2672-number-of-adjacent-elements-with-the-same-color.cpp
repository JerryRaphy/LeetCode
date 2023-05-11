class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        
        int m = queries.size();
        vector<int> v(n,0);
        
        map<int,int> mp;
        vector<int> res(m,0);
        int cnt = 0;
        
        for(int i=0 ; i<n ; ++i) mp[i] = 0;
        
        for(int i=0 ; i<m ; ++i){
            
            int idx = queries[i][0];
            int val = queries[i][1];
            int prev = v[idx];
            
            if(prev == val){
                res[i] = cnt;
                continue;
            }
            
            if(idx != 0 && v[idx - 1] != 0){
                if(v[idx - 1] == val){
                   mp[v[idx - 1]] += 1;
                   cnt += 1; 
                }
                
                if(v[idx - 1] == prev){
                    mp[v[idx - 1]] -= 1;
                    cnt -= 1;
                }
            }
            
            
            if(idx != n - 1 && v[idx + 1] != 0){
                if(v[idx + 1] == val){
                    mp[v[idx]] += 1;
                    cnt += 1;
                }
                
                if(v[idx + 1] == prev){
                    mp[v[idx]] -= 1;
                    cnt -= 1;
                }
            }
            
            v[idx] = val;
            res[i] = cnt;
            
        }
        
        return res;
    }
};