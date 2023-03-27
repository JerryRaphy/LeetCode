#define ll long long int
const int mod = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> graph(n);
        
        for(int i=0 ; i<roads.size() ; ++i){
            graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
    
        
        ll INF = 1e15;
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> distances(n,INF);
        vector<ll> dp(n,INF);
            
        distances[0] = 0; 
        dp[0] = 1; 
        
        pq.push({0,0});
    
        while(!pq.empty()){
            
            ll dist = pq.top().first;
            ll city = pq.top().second;
            pq.pop();
            
            if(dist > distances[city]) continue;
            
            for(auto child : graph[city]){
                
                if(child.second + dist == distances[child.first]){
                    dp[child.first] = (dp[child.first] % mod + dp[city] % mod) % mod;
                }
                else if(child.second + dist < distances[child.first]){
                    dp[child.first] = dp[city] % mod;
                    distances[child.first] = child.second + dist;
                    pq.push({distances[child.first],child.first});
                }
                
            }
        }
            
        return int(dp[n - 1] % mod);
    }
};