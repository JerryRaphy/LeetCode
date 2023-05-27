class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long ans = 0, mul = 1;
        vector<long long> pre(nums.size(), 0), suf(nums.size(), 0);
        pre[0] = nums[0]; suf[nums.size()-1] = nums.back();
        for( int i = 1; i < nums.size(); ++i) {
            pre[i] = pre[i-1] | nums[i];
            suf[nums.size() - i - 1] = suf[nums.size()-i] | nums[nums.size() - i - 1];
        }
        for(int i = 0; i < k; ++i){ mul *= 2; }
        for(int i = 0; i < nums.size(); ++i){
            long long x = nums[i]*mul;
            if(i-1 >= 0) x = x | pre[i-1];
            if(i+1 < nums.size()) x = x | suf[i+1];
            ans = max(ans, x);
        }
        return ans;
    }
};