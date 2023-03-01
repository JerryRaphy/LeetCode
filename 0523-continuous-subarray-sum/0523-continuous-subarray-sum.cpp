class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int,int> mp;
        
        mp[0] = -1;
        int total = 0;
        
        for(int i=0 ; i<n ; ++i){
            
            total += nums[i];
            int r = total % k;
            if(mp.find(r) != mp.end()){
                if(i - mp[r] > 1) return true;
            }
            else mp[r] = i;
            
        }
        
        return false;
    }
};