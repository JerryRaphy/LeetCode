class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         
        int n = edges.size();
        
        vector<int> dist_from_node_1(n,INT_MAX);
        dist_from_node_1[node1] = 0;
        
        int node = node1;
        
        while(true){
            int child = edges[node];
            if(child == -1) break;
            if(dist_from_node_1[child] < dist_from_node_1[node] + 1) break;
            
            dist_from_node_1[child] = dist_from_node_1[node] + 1;
            node = child;
        }
        
        
        vector<int> dist_from_node_2(n,INT_MAX);
        dist_from_node_2[node2] = 0;
        
        node = node2;
        
        while(true){
            int child = edges[node];
            if(child == -1) break;
            if(dist_from_node_2[child] < dist_from_node_2[node] + 1) break;
        
            
            dist_from_node_2[child] = 1 + dist_from_node_2[node];
            node = child;
        }
        
        /*
        for(int i=0 ; i<n ; ++i) cout<<dist_from_node_1[i]<<" ";
        cout<<endl;
        for(int i=0 ; i<n ; ++i) cout<<dist_from_node_2[i]<<" ";
        cout<<endl;
        */
        
        int dist = INT_MAX;
        int res = -1;
        
        for(int i=0 ; i<n ; ++i){
            
            int d1 = dist_from_node_1[i];
            int d2 = dist_from_node_2[i];
            
            if(d1 != INT_MAX && d2 != INT_MAX){
                if(max(d1,d2) < dist){
                    dist = max(d1,d2);
                    res = i;
                }
            }
            
        }
    
        return res;
        
    }
};