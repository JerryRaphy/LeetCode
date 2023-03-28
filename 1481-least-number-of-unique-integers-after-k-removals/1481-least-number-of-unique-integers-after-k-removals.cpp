class Solution {
public:
    
    
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int,int> mp;
        
        for(int i=0 ; i<n ; ++i){
            mp[nums[i]] += 1;
        }
        
        vector<int> v;
        for(auto it : mp) v.push_back(it.second);
        sort(v.begin(),v.end());
        
        int i = 0;
        int sz = v.size();
        
        while(i < sz){
            if(k > v[i]){
                k -= v[i];
                i += 1;
            }
            else if(k == v[i]){
                i += 1;
                break;
            }
            else break;
        }
        
        return sz - i;
    }
    
};