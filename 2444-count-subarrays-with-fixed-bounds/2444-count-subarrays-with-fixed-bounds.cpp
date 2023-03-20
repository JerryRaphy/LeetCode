class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        
        int n = nums.size();
        long long ans = 0;
        int prev_bad = -1;
        int recent_min = -1;
        int recent_max = -1;
        
        for(int i=0 ; i<n ; ++i){
            if(nums[i] < minK || nums[i] > maxK) prev_bad = i;
            if(nums[i] == minK) recent_min = i;
            if(nums[i] == maxK) recent_max = i;
            if(recent_min != -1 && recent_max != -1){
                int smaller = min(recent_min,recent_max);
                if(prev_bad < smaller) ans += smaller - prev_bad;
            }
        }
        
        return ans;
    }
};