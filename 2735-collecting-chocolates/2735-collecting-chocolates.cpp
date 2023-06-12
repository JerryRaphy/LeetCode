#define ll long long

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        
        int n = nums.size();
        long long res = LONG_MAX;
        
        vector<int> check(n,INT_MAX);
        vector<int> helper = nums;
        
        for(auto a : nums) helper.push_back(a);
        
        for(int i=0 ; i<n ; ++i){
            long long sum = 0;
            for(int j=0 ; j<n ; ++j){
                check[j] = min(check[j],helper[i+j]);
                sum += check[j];
            }
            sum += (long long)i * (long long)x;
            res = min(res,sum);
        }
        
        return res;
        
    }
};