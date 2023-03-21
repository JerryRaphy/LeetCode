#define ll long long int

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        map<ll,vector<pair<int,int>>> mp;
        
        for(int i=0 ; i<n ; ++i){
            for(int j=i+1 ; j<n ; ++j){
                ll sum = nums[i] + nums[j];
                mp[sum].push_back({i,j});
            }
        }
        
        for(int i=0 ; i<=n-4 ; ++i){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1 ; j<=n-3 ; ++j){
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                ll k = target;
                k -= nums[i];
                k -= nums[j];
                
                for(auto it : mp[k]){
                    int l = it.first;
                    int r = it.second;
                    
                    if(l <= j) continue;
                    if(!res.empty() && nums[i] == res.back()[0] && nums[j] == res.back()[1] && nums[l] == res.back()[2] && nums[r] == res.back()[3])                                  continue;    
                    
                    vector<int> curr = {nums[i],nums[j],nums[l],nums[r]};
                    res.push_back(curr);   
                }
            }
        }
        
        return res;
    }
};