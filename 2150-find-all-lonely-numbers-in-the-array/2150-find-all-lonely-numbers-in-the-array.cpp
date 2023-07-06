class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
         int n = nums.size();
         vector<int> res;
            
         map<int,int> mp;
         for(auto it : nums) mp[it] += 1;
 
         for(int i=0 ; i<n ; ++i){
             if(mp[nums[i]] == 1 && !mp.count(nums[i] - 1) && !mp.count(nums[i] + 1))
                 res.push_back(nums[i]);
         }
        
         return res;
    }
};