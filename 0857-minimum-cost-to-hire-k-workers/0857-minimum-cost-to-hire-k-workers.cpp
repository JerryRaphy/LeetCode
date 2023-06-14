class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        double mincost = LONG_MAX;
        
        vector<pair<double,int>> v;
        for(int i=0 ; i<n ; ++i){
            double ratio = double(wage[i]) / quality[i];
            v.push_back({ratio,i});
        }
        sort(v.begin(),v.end());
        
        // pushing in only the qualities
        priority_queue<int,vector<int>> pq;
        double current_cost = 0;
        
        for(int i=0 ; i<k ; ++i){
            pq.push(quality[v[i].second]);
            current_cost += quality[v[i].second];
        }
        
        double captain_cost = v[k-1].first;
        mincost = double(current_cost) * captain_cost;
        
        for(int i=k ; i<n ; ++i){
            if(!pq.empty() && quality[v[i].second] < pq.top()){
                current_cost -= pq.top();
                pq.pop();
                
                pq.push(quality[v[i].second]);
                current_cost += quality[v[i].second];
                
                double captain_cost = v[i].first;
                mincost = min(mincost,captain_cost * double(current_cost));
            }
        }
    
        
        return mincost;
    }
};