class Solution {
public:
    
    map<int,int> parent;
    map<int,int> sz;
    map<string,vector<int>> mp;
    
    
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
            sz[A] += sz[B];
        }
    }
    
    bool issimilar(string A, string B){
        
        int diff = 0;
        int len = A.length();
        
        for(int i=0 ; i<len ; ++i){
            if(A[i] != B[i]) diff += 1;
        }
        
        if(diff == 0 || diff == 2) return true;
        return false;
    }
    
    int numSimilarGroups(vector<string>& str) {
        
        int n = str.size();
        int cnt = n;
        
        for(int i=0 ; i<n ; ++i) {
            mp[str[i]].push_back(i);
            parent[i] = i;
            sz[i] = 1;
        }
        
        for(int i=0 ; i<n ; ++i){
            for(int j=i+1 ; j<n ; ++j){
                if(issimilar(str[i],str[j]) && getparent(i) != getparent(j)){
                    cnt -= 1;
                    Union(i,j);
                }
            }
        }

        return cnt;
    }
};