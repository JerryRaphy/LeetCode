class Solution {
public:
    int minJumps(vector<int>& v) {
        
        int n = v.size();
        map<int,vector<int>> mp;
        
        for(int i=0 ; i<n ; ++i){
            mp[v[i]].push_back(i);
        }
        
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> pq;
        
        pq.push({0,0});
        dist[0] = 0;
        
        while(!pq.empty()){
            
            int pos  = pq.front().first;
            int step = pq.front().second;
        
            pq.pop();
            
            if(pos == n - 1) return step;
            
            int new_pos = pos;
            
            // one step forward
            if(pos + 1 < n){
                new_pos = pos + 1;
                if(dist[new_pos] > (step + 1)){
                    dist[new_pos] = step + 1;
                    pq.push({new_pos,dist[new_pos]});
                }
            }
            
            // one step backward
            if(pos - 1 >= 0){
                new_pos = pos - 1;
                if(dist[new_pos] > (step + 1)){
                    dist[new_pos] = step + 1;
                    pq.push({new_pos,dist[new_pos]});
                }
            }
            
            // try all of the equal values in front of it
            if(mp.find(v[pos]) != mp.end()){
                for(auto it : mp[v[pos]]){
                    if(it != pos){
                        new_pos = it;
                        if(dist[new_pos] > (step + 1)){
                            dist[new_pos] = step + 1;
                            pq.push({new_pos,dist[new_pos]});
                        }
                    }
                }
                
                mp.erase(v[pos]);
            }
        }
        
        return dist[n - 1];
    }
};