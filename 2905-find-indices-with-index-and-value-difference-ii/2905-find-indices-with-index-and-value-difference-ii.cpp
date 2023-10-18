class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexdiff, int k) {
            
        int n = nums.size();
        vector<int> res;
        
        set<pair<int,int>> st;
        unordered_map<int,int> mp;
        int r = n - 1;
        int l = n - indexdiff - 1;
        
        while(l >= 0){
            
            st.insert({nums[r],r});
        
                
            int f1 = k + nums[l];
            auto it = st.lower_bound({f1,-1});
            if(it != st.end()){
                res = {l,it->second};
                return res;
            }
              
            if(nums[l] >= k){
                int f2 = nums[l] - k;
                it = st.begin();

                if(it->first <= f2){
                    res = {l,it->second};
                    return res;
                }
            }

        
            l -= 1;
            r -= 1;
        }
        
        
        res = {-1,-1};
        return res;
    
    }
};