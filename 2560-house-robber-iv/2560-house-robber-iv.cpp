// binary search would have never struck me in this question

class Solution {
public:
    
    
    
    
    
    int minCapability(vector<int>& nums, int k) {
        
        int n = nums.size();
        int res =  -1;
        
        int mn = INT_MAX;
        int mx = 0;
        
        for(int i=0 ; i<n ; ++i){
            mn = min(nums[i],mn);
            mx = max(nums[i],mx);
        }
        
        int l = mn;
        int r = mx;
        
        while(l <= r){
            int mid = l + (r-l) / 2;
            
            int cnt = 0;
            for(int i=0 ; i<n ; ++i){
                if(nums[i] <= mid) {
                    cnt += 1;
                    i += 1;
                }
            }
            
            if(cnt >= k) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
            
        return res;
    
    }
};