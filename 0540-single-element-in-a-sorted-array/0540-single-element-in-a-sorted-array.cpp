class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            bool found = true;
            
            if(mid != 0 && nums[mid] == nums[mid-1]){
                found = false;
                if((r - mid) % 2 != 0){
                    l = mid + 1;
                }
                else r = mid - 2;
            }
            else if(mid != n-1 && nums[mid] == nums[mid+1]){
                found = false;
                if((mid - l) % 2 != 0){
                    r = mid - 1;
                }
                else l = mid + 2;
            }
            
            if(found) return nums[mid];
        
             
        }
        return -1;
    }
};