class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        
        mp[0] = 1;
        int cnt = 0;
        int sum = 0;
        
        for(int i=0 ; i<n ; ++i){
            sum = (sum + nums[i] % k + k) % k;
            if(mp.find(sum) != mp.end()){
                cnt += mp[sum];
            }
            mp[sum] += 1;
        }
        
        return cnt;
    }
};