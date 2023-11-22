class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> v;
        
        for(int i=0 ; i<2*n ; ++i) v.push_back(nums[i % n]);
        
        int cnt = 0;
        for(int i=0 ; i<n ; ++i) {
            if(nums[i] == 1) cnt += 1;
        }
        
        int l = 0;
        int r = 0;
        int current_cnt = 0;
        
        while(r < cnt){
            if(v[r] == 1) current_cnt += 1;
            r += 1;
        }
        
        int res = cnt - current_cnt;
        
        while(r < 2*n){
            
            if(v[l] == 1) current_cnt -= 1;
            if(v[r] == 1) current_cnt += 1;
            
            res = min(res,cnt - current_cnt);
            
            l += 1;
            r += 1;
        }
            
        return res;
    }
};