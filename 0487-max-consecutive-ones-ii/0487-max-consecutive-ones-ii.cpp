class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int prev_flip = -1;
        int len = 0;
        
        int start = 0;
        int i = 0;
        while(i < n){
            if(nums[i] == 0){
                if(prev_flip == -1) prev_flip = i;
                else{
                    len = max(len,i - start);
                    start = prev_flip + 1;
                    prev_flip = i;
                }
            }
            ++i;
        }
        len = max(len,i - start);
        return len;
    }
};