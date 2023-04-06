class Solution {
public:
    
    map<int,int> parent;
    map<int,int> sz;
    map<int,int> timestamp;
    
    
    int getparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = getparent(parent[node]);
    }
    
    void Union(int A, int B, long long T){
        
        A = getparent(A);
        B = getparent(B);
        
        if(A != B){
            if(sz[A] < sz[B]) swap(A,B);
            parent[B] = A;
            sz[A] += sz[B];
            timestamp[A] = T;
        }
    }
    
    
    bool static comp(vector<int> A, vector<int> B){
        return A[0] <= B[0];
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        sort(logs.begin(),logs.end(),comp);
        
        for(int i=0 ; i<n ; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
        
        
        for(auto log : logs){
            Union(log[1],log[2],log[0]);
        }
        
        for(int i=0 ; i<n ; ++i){
            if(sz[i] == n) return timestamp[i];
        }
            
        return -1;
        
    }
};