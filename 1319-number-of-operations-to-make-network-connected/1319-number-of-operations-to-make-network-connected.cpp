class Solution {
public:
    
    map<int,int> parent;
    map<int,int> sz;
    
    int getparent(int A){
        if(A == parent[A]) return A;
        return parent[A] = getparent(parent[A]);
    }
    
    void Union(int A, int B){
        A = getparent(A);
        B = getparent(B);
        
        if(A != B){
            if(sz[B] > sz[A]) swap(A,B);
            parent[B] = A;
            sz[A] += B;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        if(m < n - 1) return -1;
        
        int res = 0;
        for(int i=0 ; i<n ; ++i){
            parent[i] = i;
            sz[i] = 1;
        }
        
        for(auto connection : connections){
            int A = connection[0];
            int B = connection[1];
            Union(A,B);
        }
        
        
        set<int> st;
        for(int i=0 ; i<n ; ++i) st.insert(getparent(i));
        
        return st.size() - 1;
    }
};