const int mod = 1e9 + 7;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        
        int n = nums.size();
        vector<long long int> v;
        
        for(int i=0 ; i<n ; ++i) {
            if(s[i] == 'L') v.push_back(nums[i] - d);
            else v.push_back(nums[i] + d);
        }
        
        sort(v.begin(),v.end());
        
        
        vector<long long int> prefix(n,0);
        prefix[0] = v[0];
        
        for(int i=1 ; i<n ; ++i){
            prefix[i] = prefix[i-1] + v[i];
        }
        
        
        
        int res = 0;
        for(int i=1 ; i<n ; ++i){
            long long int a = i * v[i];
            long long int b = prefix[i-1];
            long long int c = abs(a - b);
            res = (res%mod + c%mod) % mod;
            cout<<res<<endl;
        }
        return res;
    }
};