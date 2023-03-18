class Solution {
public:
    
    
    bool static comp(pair<int,int> A, pair<int,int> B){
        
        if(A.first == B.first) return A.second < B.second;
        return A.first < B.first;
    }
    
    long long findScore(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> v;
        
        for(int i=0 ; i<n ; ++i){
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end(),comp);
        set<pair<int,int>> st;
        
        for(int i=0 ; i<n ; ++i) st.insert({nums[i],i});
        
        long long score = 0;
        for(int i=0 ; i<n ; ++i){
            if(st.find(v[i]) != st.end()){
                score += v[i].first;
                int idx = v[i].second;
                
                pair<int,int> pre;
                pair<int,int> aft;    
                    
                if(idx != 0) pre = {nums[idx - 1],idx - 1};
                if(idx != n - 1) aft = {nums[idx + 1],idx + 1};
                
                st.erase(pre);
                st.erase(aft);
                st.erase(v[i]);
            }
        }
        
        return score;
    }
};