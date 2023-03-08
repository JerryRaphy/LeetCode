#define ll long long int

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        vector<vector<int>> graph(n);
        
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<n ; ++j){
        
                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r  = bombs[i][2];
                
                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                
                ll dist_x = (x2 - x1) * (x2 - x1);
                ll dist_y = (y2 - y1) * (y2 - y1);
                if(dist_x + dist_y <= r * r) graph[i].push_back(j);
                
            }
        }
        
        int max_bomb_blasts = 1;
        for(int i=0 ; i<n ; ++i){
            
            queue<int> q;
            q.push(i);
            vector<bool> visited(n,false);
            visited[i] = true;
            int cnt = 0;
            
            while(!q.empty()){
                
                int curr_bomb = q.front();
                q.pop();
                cnt += 1;
                
                for(auto child : graph[curr_bomb]) {
                    if(!visited[child]){
                        visited[child] = true;
                        q.push(child);
                    }
                } 
            }
            
            max_bomb_blasts = max(max_bomb_blasts,cnt);
        }
        
        return max_bomb_blasts;
    }
};