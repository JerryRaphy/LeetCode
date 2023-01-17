class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0;
        int r = 0;
        int len = 0;
        
        bool del = false;
        
        while(r < n){
            if(nums[r] == 0){
                if(del == false) del = true;
                else{
                    len = max(len,r-l-1);
                    while(l <= r && nums[l] == 1) ++l;
                    l += 1;
                }
            }
            ++r;
        }
        
        len = max(len,r-l-1);
        return len;
    }
};