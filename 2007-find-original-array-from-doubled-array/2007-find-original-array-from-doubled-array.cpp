class Solution {
public:
    vector<int> findOriginalArray(vector<int>& change) {
        
        int n = change.size();
        if(n % 2 != 0) return {};
        vector<int> v;
        
        map<int,int> mp;
        for(int i=0 ; i<n ; ++i) mp[change[i]]++;
        
        sort(change.begin(),change.end());
        
        for(int i=0 ; i<n ; ++i){
            
            int temp = change[i] * 2;
            
            if(mp.find(change[i]) != mp.end() && mp.find(temp) != mp.end()){
                
                v.push_back(change[i]);
                mp[change[i]]--;
                mp[temp]--;
                
                if(mp[change[i]] == 0) mp.erase(change[i]);
                if(mp[temp] == 0) mp.erase(temp);
            }
        }
        
        if(!mp.empty()) return {};
        return v;
        
    }
};