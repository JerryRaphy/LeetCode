class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();   
        vector<int> res;
        map<int,int> mp;
        
        vector<vector<int>> freq(n+1);
        for(int i=0 ; i<n ; ++i) mp[nums[i]]++;
        
        for(auto it : mp){
            freq[it.second].push_back(it.first);
        }
        
        for(int i=n ; i>=1 ; --i){
            for(auto element : freq[i]){
                if(k == 0) return res;
                res.push_back(element);
                k -= 1;
            }
        }
        
        return res;
            
    }
};