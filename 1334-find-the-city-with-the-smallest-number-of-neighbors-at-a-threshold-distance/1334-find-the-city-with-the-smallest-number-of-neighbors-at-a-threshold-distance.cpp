class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        
        vector<vector<pair<int,int>>> graph(n);
        
        for(int i=0 ; i<edges.size() ; ++i){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        int max_cities = n + 1;
        int res = 0;
        
        for(int i=0 ; i<n ; ++i){
            
            vector<int> distances(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            distances[i] = 0;
            pq.push({0,i});
            
        
            while(!pq.empty()){
                int node = pq.top().second;
                int dist = pq.top().first;
                pq.pop();
                
                for(auto child : graph[node]){
                    if(dist + child.second < distances[child.first]){
                        distances[child.first] = dist + child.second;
                        pq.push({distances[child.first],child.first});
                    }
                }
            }    
            
            int temp = 0;
            for(int i=0 ; i<n ; ++i){
                if(distances[i] <= k) temp += 1;
            }
          
            if(temp <= max_cities){
                max_cities = temp;
                res = i;
            }
        }
        
        return res;
    }
};