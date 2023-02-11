#define ll long long

class Solution {
public:
    
   struct comp{
       bool operator()(const pair<int,int> A, pair<int,int> B){
           if(A.first == B.first) return A.second > B.second;
           return A.first > B.first;
       }
   };
    
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        int n = costs.size();
        ll cost = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        
        int i = 0;
        int j = n - 1;
        
        if(i == j) return costs[0];
        
        while(candidates > 0 && i < j){
            pq.push({costs[i],i});
            pq.push({costs[j],j});
            candidates -= 1;
            i += 1;
            j -= 1;
        }
        
        while(k > 0 && i <= j){
            pair<int,int> p = pq.top();
            pq.pop();
            cost += p.first;
            
            if(p.second < i){
                pq.push({costs[i],i});
                i += 1;
            }
            else{
                pq.push({costs[j],j});
                j -= 1;
            }
            
            k -= 1;
        }
        
        while(k > 0){
            cost += pq.top().first;
            pq.pop();
            k -= 1;
        }
        
        return cost;
    }
};