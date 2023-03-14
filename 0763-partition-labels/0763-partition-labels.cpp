class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        vector<int> res;
        
        map<char,int> mp;
        for(int i=0 ; i<n ; ++i) mp[s[i]] = i;
        
        int sz = 0;
        int curr_mx = 0;
        
        for(int i=0 ; i<n ; ++i){
            curr_mx = max(curr_mx,mp[s[i]]);
            if(curr_mx == i){
                sz += 1;
                res.push_back(sz);
                sz = 0;
            }
            else sz += 1;
        }
        
        return res;
    }
};