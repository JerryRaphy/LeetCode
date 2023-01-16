class Solution {
public:
    vector<int> getModifiedArray(int len, vector<vector<int>>& updates) {
        
        vector<int> v(len,0);
        int n = updates.size();
        
        for(int i=0 ; i<n ; ++i){
            v[updates[i][0]] += updates[i][2];
            if(1 + updates[i][1] < len) v[1 + updates[i][1]] -= updates[i][2]; 
        }
        
        for(int i=1 ; i<len ; ++i) v[i] += v[i-1];
        return v;
    }
};