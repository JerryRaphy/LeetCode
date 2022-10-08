class Solution {
public:
    
    map<int,int> parent;
    map<int,int> sz;
    
    
    int getparent(int node){
        if(parent[node] == node) return node;
        return parent[node] = getparent(parent[node]);
    }
    
    int findCircleNum(vector<vector<int>>& connected) {
       int n = connected.size();
        
       for(int i=0 ; i<n ; ++i) {
           parent[i] = i;
           sz[i] = 1;
       }
       
       for(int i=0 ; i<n ; ++i){
          for(int j=0 ; j<n ; ++j){
              int a = getparent(i);
              int b = getparent(j);
              
              if(a == b || connected[i][j] == 0) continue;
              if(sz[a] < sz[b]) swap(a,b);
              parent[b] = a;
              sz[a] += sz[b];
          } 
       } 
       
       set<int> st;
       for(auto it = parent.begin() ; it != parent.end() ; it++) st.insert(it->second);
       return st.size(); 
        
    }
};