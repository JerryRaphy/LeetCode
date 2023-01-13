// highly intuitive greedy

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first_num  = INT_MAX;
        int second_num = INT_MAX;
        int third_num  = INT_MAX;
        
        for(int i=0 ; i<n ; ++i){
            if(nums[i] <= first_num) first_num = nums[i];
            else if(nums[i] <= second_num) second_num = nums[i];
            else return true;
        }
        
        return false;
    }
};