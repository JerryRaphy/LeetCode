/*https://leetcode.com/problems/maximum-performance-of-a-team/discuss/539797/C%2B%2BPython-Priority-Queue*/

#define ll long long int
const int mod = 1e9 + 7;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; ++i){
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
       
        
        ll ans = 0;
        ll sum = 0;
        
        for(int i=0 ; i<k ; ++i){
            sum += v[i].second;
            ans = max(ans,sum * v[i].first);
            pq.push(v[i].second);
        }
        
        for(int i=k ; i<n ; ++i){
            if(v[i].second > pq.top()){
                sum -= pq.top();
                sum += v[i].second;
                pq.pop();
                pq.push(v[i].second);
                ans = max(ans,sum * v[i].first);
            }
        }
        
        return int(ans % mod);
    }
};