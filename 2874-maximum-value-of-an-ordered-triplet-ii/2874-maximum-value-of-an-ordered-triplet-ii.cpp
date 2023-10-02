class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n = nums.size();
        long long res = 0;
        
        vector<long long> max_diff(n,0);
        int mx = nums[0];
        
        for(int i=1 ; i<n ; ++i){
            if(nums[i] <= mx){
                max_diff[i] = mx - nums[i];
            }
            else mx = nums[i];
        }
        
        
        mx = nums[n - 1];
        for(int i=n-2 ; i>=0 ; --i){
            res = max(res,max_diff[i] * mx);
            mx = max(mx,nums[i]);
        }
        
        return res;
    }
};