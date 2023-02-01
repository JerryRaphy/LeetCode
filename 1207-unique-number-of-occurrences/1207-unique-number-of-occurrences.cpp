class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        
        int n = v.size();
        map<int,int> mp;
        set<int> st;
        
        for(auto num : v) mp[num]++;
        for(auto m : mp) st.insert(m.second);
        
        if(st.size() == mp.size()) return true;
        return false;
        
        
    }
};