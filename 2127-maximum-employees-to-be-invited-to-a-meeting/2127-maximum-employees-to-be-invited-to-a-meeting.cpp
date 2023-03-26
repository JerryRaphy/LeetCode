class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        
        int n = favorite.size();
        vector<int> indegrees(n,0);
        
        for(int i=0 ; i<n ; ++i){
            indegrees[favorite[i]]++;
        }
        
        vector<int> visited(n,false);
        vector<int> dp(n,0);
        queue<int> q;
        
        for(int i=0 ; i<n ; ++i){
            if(indegrees[i] == 0){
                visited[i] = true;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node  = q.front();
            int child = favorite[node];
            q.pop();
            
            dp[child] = max(dp[child],dp[node] + 1);
            
            if(--indegrees[child] == 0){
                visited[child] = true;
                q.push(child);
            }
        }
        
        
        // whichever is still univisited is still part of cycle;
        int res  = 0;
        int res2 = 0;
        
        for(int i=0 ; i<n ; ++i){
            if(visited[i] == false){
                int len = 0;
                for(int j=i ; visited[j] != true ; j = favorite[j]){
                    visited[j] = true;
                    len += 1;
                }
                
                if(len == 2) res2 += 2 + dp[i] + dp[favorite[i]]; 
                else res = max(res,len);
            }
        }
        
        return max(res,res2);
    }
};