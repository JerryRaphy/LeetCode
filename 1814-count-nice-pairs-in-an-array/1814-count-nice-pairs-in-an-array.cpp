const int mod = 1e9 + 7;

class Solution {
public:
    
    int getreverse(int number){
        string r = to_string(number);
        if(r.length() == 1) return number;
        
        reverse(r.begin(),r.end());
        
        int i = 0;
        while(i < r.length() && r[i] == '0') i += 1;
        
        r = r.substr(i);
        return stoi(r);
    }
    
    
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> revs(n);
        
        for(int i=0 ; i<n ; ++i){
            revs[i] = getreverse(nums[i]);
        }
        
        map<int,int> mp;
        for(int i=0 ; i<n ; ++i) mp[nums[i] - revs[i]] += 1;
        
        int res = 0;
        
        for(auto it : mp){
            long long int cnt = it.second - 1;
            long long int temp = (cnt * (cnt + 1)) / 2;
            
            res = (res%mod + temp%mod) % mod;
        }
        
        return res;
        
    }
};