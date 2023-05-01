class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        int n = nums.size();
        map<int,int> mp;
        vector<int> res = nums;
        
        for(int i=0 ; i<n ; ++i) mp[nums[i]] = i;
        
        for(auto op : operations){
            int pos = mp[op[0]];
            res[pos] = op[1];
            mp[op[1]] = pos;
            mp.erase(op[0]);
        }
        
        return res;
    }
};