class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        set<int> prefix;
        vector<int> res(n,0);
        
        for(int i=0 ; i<n ; ++i){
            set<int> suffix;
            prefix.insert(nums[i]);
            for(int j=i+1 ; j<n ; ++j) suffix.insert(nums[j]);
            res[i] = prefix.size() - suffix.size();
        }
        
        return res;
    }
};