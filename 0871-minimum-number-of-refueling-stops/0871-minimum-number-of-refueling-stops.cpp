class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        priority_queue<int,vector<int>> pq;
        
        int i = 0;
        int maxdist = startFuel;
        int stops = 0;
        
        while(maxdist < target){
            while(i < n && stations[i][0] <= maxdist){
                pq.push(stations[i][1]);
                i += 1;
            }
            
            if(pq.empty()) return -1;
            maxdist += pq.top();
            pq.pop();
            stops += 1;
        }
        return stops;
    }
};