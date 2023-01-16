#define ll long long int

class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {
        
        int n = charge.size();        
        int robots = 0;
        int l = 0;
        int r = 0;
        
        vector<ll> runcosts(n);
        for(int i=0 ; i<n ; ++i) runcosts[i] = run[i];
        
        for(int i=1 ; i<n ; ++i) runcosts[i] += runcosts[i-1];
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        
       
        while(r < n){
            int k = r - l + 1;
            pq.push({charge[r],r});
            
            ll sumcosts = 0;
            if(l == 0) sumcosts = runcosts[r];
            else sumcosts = runcosts[r] - runcosts[l-1];
            
            ll max_charge = 0;
            while(!pq.empty() && (pq.top().second < l || pq.top().second > r)) pq.pop();
            max_charge = pq.top().first;
            
            ll curr_budget = max_charge + (k * sumcosts);
            
            if(curr_budget > budget){
                l += 1;
                while(l <= r){
                    k = r - l + 1;
                    sumcosts = runcosts[r] - runcosts[l-1];
                    max_charge = 0;
                    while(!pq.empty() && (pq.top().second < l || pq.top().second > r)) pq.pop();
                    max_charge = pq.top().first;
                    
                    curr_budget = max_charge + (k * sumcosts);
                    if(curr_budget <= budget) break;
                    l += 1;
                }
            } 
            else robots = max(robots,k);
            ++r;
        }
        
        robots = max(robots,r-l);
        return robots;
        
    }
};