class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        
        vector<int>  res;
        int temp = n;
        for(int i=0 ; i<n ; ++i){
            res.push_back(nums[i]);
            res.push_back(nums[temp]);
            temp += 1;
        }
        
        return res;
    }
};