class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        vector<int> res;
        map<int,int> mp;
        
        for(int i=0 ; i<k ; ++i){
            if(nums[i] < 0) mp[nums[i]]++;
        }
        
        int curr = x;
        int val = 0;
        
        for(auto it : mp){
            if(it.second < curr) curr -= it.second;
            else{
                val = it.first;
                break;
            }
        }
        
        res.push_back(val);
        
        int l = 1;
        int r = k;
        
        while(r < n){
            
            curr = x;
            val = 0;
            
            // eliminate the previous value if it was a pos value
            if(nums[l - 1] < 0){
                mp[nums[l-1]]--;
                if(mp[nums[l-1]] == 0) mp.erase(nums[l-1]);
            }
                
            // add the current index if it a neg value
            if(nums[r] < 0) mp[nums[r]]++;
           
            for(auto it : mp){
                if(it.second < curr) curr -= it.second;
                else{
                    val = it.first;
                    break;
                }
            }
            
            res.push_back(val);
            
            l += 1;
            r += 1;
        }
        
        return res;
    }
};