class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = nums[0];
        int curr_max = 1;
        int curr_min = 1;
        
        for(int i=0 ; i<nums.size() ; ++i){
            int a = max(nums[i],max(curr_max * nums[i],curr_min * nums[i]));
            int b = min(nums[i],min(curr_max * nums[i],curr_min * nums[i]));
            prod = max(prod,max(a,b));
            curr_max = a;
            curr_min = b;
        }
        return prod;
    }
};