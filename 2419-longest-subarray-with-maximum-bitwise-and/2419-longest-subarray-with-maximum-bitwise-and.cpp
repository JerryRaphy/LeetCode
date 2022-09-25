class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0 ; i<n ; ++i){
            mx = max(mx,nums[i]);
        }
        int i = 0;
        int j = 0;
        int len = 0;
        while(j < n){
            if(nums[j] == mx){
                i = j;
                while(j<n && nums[j] == mx) ++j;
                len = max(len,j-i);
            }
            ++j;
        }
        return len;
    }
};