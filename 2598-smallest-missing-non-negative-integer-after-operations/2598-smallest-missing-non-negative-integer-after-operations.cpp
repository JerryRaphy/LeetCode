class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        int n = nums.size();
        int res = 0;
       
        map<int,int> mp;
        for(int i=0 ; i<n ; ++i){
            int mod = (nums[i] % value + value) % value;
            mp[mod] += 1;
        }
       
        for(int i=0 ; i<=1000001 ; ++i){
            int mod = i % value;
            if(mp.find(mod) == mp.end()) return i;
            else{
                mp[mod] -= 1;
                if(mp[mod] == 0) mp.erase(mod);
            }
        }
        
        return 0;
    }   
};