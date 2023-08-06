class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        map<int,vector<int>> mp;
        int m = nums.size();
        
        for(int i=0 ; i<m ; ++i) mp[nums[i]].push_back(i);
        int res = m;
        
        for(auto it : mp){
            
            vector<int> v = it.second;
            int n = v.size();
            int curr_max = 0;
            
            for(int i=0 ; i<n ; ++i){
                int diff = 0;
                if(i == n-1)  diff = (m - v[i] - 1) + v[0]; 
                else diff = v[i+1] - v[i] - 1;
                
                if(diff % 2 == 0) curr_max = max(curr_max,diff / 2);
                else curr_max = max(curr_max, (diff / 2) + 1);
            }
            
            res = min(curr_max,res);
        }
        
        return res;
    }
};