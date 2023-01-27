#define ll long long

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<pair<ll,ll>> dq;
        
        ll sum = 0;
        int res = INT_MAX;
        
        for(int i=0 ; i<n ; ++i){
            
            sum += nums[i];
            if(sum >= k) res = min(res,i+1);
            
            pair<ll,int> curr = {INT_MIN,INT_MIN};
            while(!dq.empty() && (sum - dq.front().first) >= k){
                curr = dq.front();
                dq.pop_front();
            }
            
            if(curr.second != INT_MIN){
                cout<<curr.second<<endl;
                res = min(res,i-curr.second);
            }
            
            while(!dq.empty() && sum <= dq.back().first){
                dq.pop_back();
            }
            
            dq.push_back({sum,i});
        }
        
        return res == INT_MAX ? -1 : res;
    }
};