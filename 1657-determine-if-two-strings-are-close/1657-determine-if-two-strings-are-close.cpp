class Solution {
public:
    bool closeStrings(string A, string B) {
        
        int n = A.length();
        int m = B.length();
        
        if(n != m) return false;
        set<char> st;
        
        for(int i=0 ; i<m ; ++i) st.insert(B[i]);
        
        for(int i=0 ; i<n ; ++i){
            if(st.find(A[i]) == st.end()) return false;
        }
        
        map<char,int> mpb;
        for(int i=0 ; i<m ; ++i) mpb[B[i]]++;
        
        map<char,int> mpa;
        for(int i=0 ; i<n ; ++i) mpa[A[i]]++;
        
        vector<int> v1,v2;
        
        for(auto it : mpb) v2.push_back(it.second);
        for(auto it : mpa) v1.push_back(it.second);
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        for(int i=0 ; i<v1.size() ; ++i) {
            if(v1[i] != v2[i]) return false;
        }
        
        return true;
    }
};