class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int,vector<int>> mp;
        int res = 1;
        
        for(int i=0 ; i<n ; ++i) mp[nums[i]].push_back(i);
        
        for(auto it : mp){
            
            int m = it.second.size();
            int l = 0;
            int r = 0;
            
            while(r < m){
                
                int inbetween = it.second[r] - it.second[l] - 1;
                
                if(inbetween <= 0){
                    res = max(res,r - l + 1);
                    r += 1;
                    continue;
                }
                
                int curr = r - l - 1;
                int remaining = inbetween - curr;
                     
                if(remaining <= k) {
                    res = max(res,curr + 2);
                    r += 1;
                }
                else {
                    l += 1;
                }
            }
            
        }
        
        return res;
    }
};