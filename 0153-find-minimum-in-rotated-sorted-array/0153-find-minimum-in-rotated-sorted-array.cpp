class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] <= nums[n-1]) return nums[0];
        
        int l = 1;
        int r = n - 1;
        int nas = -1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
           
            if(nums[mid] < nums[mid-1]){
                nas = nums[mid];
                break;
            }
                
            if(nums[mid] > nums[0]) l = mid + 1;
            else r = mid - 1;
        }
        
        return nas;
    }
};