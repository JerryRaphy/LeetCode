#define ll long long int

class Graph {
public:
    
    vector<vector<pair<ll,ll>>> graph;
    int n;
    
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        this->n = n;
        for(auto edge : edges) graph[edge[0]].push_back({edge[1],edge[2]});
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,node1});
        vector<ll> distances(n,INT_MAX);
        distances[node1] = 0;
        
        while(!pq.empty()){
            ll dist = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            
            for(auto child : graph[node]){
                if(distances[child.first] > dist + child.second){
                    distances[child.first] = dist + child.second;
                    pq.push({distances[child.first],child.first});
                }
            }
        }
        
        return distances[node2] == INT_MAX ? -1 : distances[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */