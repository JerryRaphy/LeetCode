class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> graph(n+1);
        int m = flights.size();
    
        k += 1;
        
        for(int i=0 ; i<m ; ++i){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> cost(n+1,vector<int>(k+1,INT_MAX));

        pq.push({0,src,0});
        
        for(int i=0 ; i<=k ; ++i) cost[src][i] = 0;
        
          
        while(!pq.empty()){
            
            int cost_to_reach = pq.top()[0];
            int current_city  = pq.top()[1];
            int stops = pq.top()[2];
            pq.pop();
            
            if(current_city == dst) return cost_to_reach;
            if(stops == k) continue;
            
            stops += 1;
            
            for(auto child : graph[current_city]){
                int go_to = child.first;
                int cost_to_go = child.second;
                
                if(cost[go_to][stops] > cost_to_reach + cost_to_go){
                    cost[go_to][stops] = cost_to_reach + cost_to_go;
                    pq.push({cost[go_to][stops],go_to,stops});
                }
                
            }
        
        }
        
        /*
        int res = INT_MAX;
        for(int i=0 ; i<=k ; ++i) res = min(res,cost[dst][i]);
        
        return res == INT_MAX ? -1 : res;
        */
        return -1;
        
    }
};